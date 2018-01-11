#include "GameManager.hpp"

GameManager *GameManager::sInstance = NULL;

GameManager* GameManager::Instance() {

  if(!sInstance) {
    sInstance = new GameManager();
  }

  return sInstance;
}

void GameManager::Release() {

  delete sInstance;
  sInstance = NULL;
}

GameManager::GameManager() : mQuit(false), mGraphics(Graphics::Instance()) {

  if(!Graphics::Initialized()) {

    mQuit = true;
  }

  mAssetMgr = AssetManager::Instance();

  mInputMgr = InputManager::Instance();

  mAudioMgr = AudioManager::Instance();

  mTimer = Timer::Instance();

  mTex = new Texture("Hello World!", "ARCADE.TTF", 72, {255, 0, 0});
  mTex->Pos(Vector2(300, 300));
  mTex->Scale(Vector2(1.0f, 0.5f));

  mTex2 = new Texture("Hello World!", "ARCADE.TTF", 72, {0, 255, 0});
  mTex2->Pos(Vector2(450, 120));

  //mTex2->Scale(Vector2(20.0f, 20.0f));
}

GameManager::~GameManager() {

  AudioManager::Release();
  mAudioMgr = NULL;

  AssetManager::Release();
  mAssetMgr = NULL;

  Graphics::Release();
  mGraphics = NULL;

  InputManager::Release();
  mInputMgr = NULL;

  Timer::Release();
  mTimer = NULL;

  delete mTex;
  mTex = NULL;

  delete mTex2;
  mTex2 = NULL;
}

void GameManager::EarlyUpdate() {

  mInputMgr->Update();
}

void GameManager::Update() {

  if(mInputMgr->KeyPressed(SDL_SCANCODE_1)) {

    mAudioMgr->PlayMusic("ChillingMusic.wav");
  }
  if(mInputMgr->KeyPressed(SDL_SCANCODE_2)) {

    mAudioMgr->PauseMusic();
  }
  if(mInputMgr->KeyPressed(SDL_SCANCODE_3)) {

    mAudioMgr->ResumeMusic();
  }
  if(mInputMgr->KeyReleased(SDL_SCANCODE_W)) {

    printf("W Key Released\n");
  }
  if(mInputMgr->KeyPressed(SDL_SCANCODE_W)) {

    printf("W Key Pressed\n");
  }
  if(mInputMgr->KeyDown(SDL_SCANCODE_W)) {

    printf("W Key Down\n");
  }
  if(mInputMgr->MouseButtonReleased(InputManager::middle)) {

    printf("mouse middle Released\n");
  }
  if(mInputMgr->MouseButtonPressed(InputManager::middle)) {

    printf("mouse middle Pressed\n");
  }
  if(mInputMgr->MouseButtonDown(InputManager::middle)) {

    printf("mouse middle Down\n");
  }

  mTex->Rotate(10 * mTimer->DeltaTime());

  if(mInputMgr->KeyPressed(SDL_SCANCODE_A)) {

    mTex2->Parent(mTex);
  }
  if(mInputMgr->KeyPressed(SDL_SCANCODE_S)) {

   mTex2->Parent(NULL);
  }
}

void GameManager::LateUpdate() {

  mInputMgr->UpdatePrevInput();
  mTimer->Reset();
}

void GameManager::Render() {

  mGraphics->ClearBackBuffer();

  mTex->Render();
  mTex2->Render();

  mGraphics->Render();
}

void GameManager::Run() {

  while(!mQuit) {

   mTimer->Update();

    while(SDL_PollEvent(&mEvents) != 0) {

      if(mEvents.type == SDL_QUIT) {
        mQuit = true;
      }
    }

    if(mTimer->DeltaTime() >= 1.0f / FRAME_RATE) {

      EarlyUpdate();
      Update();
      LateUpdate();
      Render();
    }

  }
}