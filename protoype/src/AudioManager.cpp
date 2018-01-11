#include "AudioManager.hpp"

AudioManager *AudioManager::sInstance = NULL;

AudioManager* AudioManager::Instance() {

  if(!sInstance) {

    sInstance = new AudioManager();
  }

  return sInstance;
}

void AudioManager::Release() {

  delete sInstance;
  sInstance = NULL;
}

AudioManager::AudioManager() {

  mAssetMgr = AssetManager::Instance();

  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096) < 0) {

    printf("Mixer Init Error: %s\n", Mix_GetError());
  }
}

AudioManager::~AudioManager() {

  mAssetMgr = NULL;
  Mix_Quit();
}

void AudioManager::PlayMusic(std::string filename, int loops) {

  Mix_PlayMusic(mAssetMgr->GetMusic(filename), loops);
}

void AudioManager::PauseMusic() {

  if(Mix_PlayingMusic) {

    Mix_PauseMusic();
  }
}

void AudioManager::ResumeMusic() {

  if(Mix_PausedMusic) {

    Mix_ResumeMusic();
  }
}

void AudioManager::PlaySFX(std::string filename, int loops, int channel) {

  Mix_PlayChannel(channel, mAssetMgr->GetSFX(filename), loops);
}