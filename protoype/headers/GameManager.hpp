#ifndef _GameManager_HPP
#define _GameManager_HPP

#include "InputManager.hpp"
#include "AnimatedTexture.hpp"
#include "AudioManager.hpp"

class GameManager {

public:
  static GameManager* Instance();
  static void Release();

  void Run();

private:
  
  static GameManager *sInstance;

  const int FRAME_RATE = 60;

  bool mQuit;
  Graphics *mGraphics;
  AssetManager *mAssetMgr;
  InputManager *mInputMgr;
  AudioManager *mAudioMgr;

  Timer *mTimer;

  SDL_Event mEvents;

  GameManager();
  ~GameManager();

  void EarlyUpdate();
  void Update();
  void LateUpdate();

  void Render();

  Texture *mTex;
  Texture *mTex2;

};

#endif