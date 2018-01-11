#ifndef _AudioManager_HPP
#define _AudioManager_HPP

#include "AssetManager.hpp"

class AudioManager {

public:

  static AudioManager *Instance();
  static void Release();

  void PlayMusic(std::string filename, int loops = -1);
  void PauseMusic();
  void ResumeMusic();

  void PlaySFX(std::string filename, int loops = 0, int channel = 0);

private:

  static AudioManager *sInstance;

  AssetManager *mAssetMgr;

  AudioManager();
  ~AudioManager();
};

#endif