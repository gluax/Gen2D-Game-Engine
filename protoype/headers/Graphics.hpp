#ifndef _Graphics_HPP
#define _Graphics_HPP

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>

class Graphics {
  
public:
  
  static const int SCREEN_WIDTH = 800;
  static const int SCREEN_HEIGHT = 600;

  static Graphics* Instance();
  static void Release();
  static bool Initialized();

  SDL_Texture* LoadTexture(std::string path);
  SDL_Texture* CreateTextTexture(TTF_Font *font, std::string text, SDL_Color color);

  void ClearBackBuffer();

  void DrawTexture(SDL_Texture *tex, SDL_Rect *clip = NULL, SDL_Rect *rend = NULL, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);

  void Render();

private:
  
  static Graphics *sInstance;
  static bool sInitialized;

  SDL_Window *mWindow;
  SDL_Surface *mBackBuffer;

  SDL_Renderer *mRenderer;

  Graphics();
  ~Graphics();

  bool Init();
};

#endif