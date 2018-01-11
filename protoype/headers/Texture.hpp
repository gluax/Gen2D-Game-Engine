#ifndef _Texture_HPP
#define _Texture_HPP

#include "GameEntity.hpp"
#include "AssetManager.hpp"

class Texture : public GameEntity {

public:
  Texture(std::string filename);
  Texture(std::string filename, int x, int y, int w, int h);
  Texture(std::string text, std::string fontPath, int size, SDL_Color color);
  ~Texture();
 

 virtual void Render();

protected:

  SDL_Texture *mTex;

  Graphics *mGraphics;

  int mWidth;
  int mHeight;

  bool mClipped;
  SDL_Rect mRenderRect;
  SDL_Rect mClipRect;

};


#endif