#ifndef _AssetManager_HPP
#define _AssetManager_HPP

#include "Graphics.hpp"
#include <SDL_mixer.h>
#include <unordered_map>

class AssetManager {

public:

  static AssetManager* Instance();
  static void Release();

  SDL_Texture* GetTexture(std::string filename);
  SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color);

  Mix_Music* GetMusic(std::string filename);
  Mix_Chunk* GetSFX(std::string filename);

private:

  static AssetManager *sInstance;
  std::unordered_map<std::string, SDL_Texture*> mTextures;
  std::unordered_map<std::string, SDL_Texture*> mText;
  std::unordered_map<std::string, TTF_Font*> mFonts;
  std::unordered_map<std::string, Mix_Music*> mMusic;
  std::unordered_map<std::string, Mix_Chunk*> mSFX;

  AssetManager();
  ~AssetManager();

  TTF_Font* GetFont(std::string filename, int size);
};

#endif