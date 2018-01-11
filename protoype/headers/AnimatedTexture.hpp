/**
  * \class AnimatedTexture
  *
  * This class is for animated textures for example a spitesheet.
  *
  * \author $Author: gluaxspeed
  *
  * \date $Date: 2018/01/11
  *
  */

#ifndef _AnimatedTexture_HPP
#define _AnimatedTexture_HPP

#include "Timer.hpp"
#include "Texture.hpp"

class AnimatedTexture : public Texture {

public:

  /// Enum for the type of wrap mode, wraps once or infinitely.
  enum WRAP_MODE { once = 0, loop = 1 };
  /// Enum for the direction of animation, horizontally or vertically.
  enum ANIM_DIR { horizontal = 0, vertical = 1 };

  /** Class constructor takes the filename, starting (x,y), size, 
    * number of frames, how fast the animation is in seconds (1.0f is one second), 
    * and the direction of the animation.
    */
  AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed, ANIM_DIR animationDir);
  /// Class decontstructor
  ~AnimatedTexture();

  /// Setter for the wrap mode.
  void WrapMode(WRAP_MODE mode);

  /// Function that handles all updates of the animated texture.
  void Update();

private:

  /// Timer pointer.
  Timer *mTimer;

  /// Starting x pos.
  int mStartX;
  /// Starting y pos.
  int mStartY;

  /// The animation timer in seconds.
  float mAnimationTimer;
  /// The speed of the animation in seconds.
  float mAnimationSpeed;
  /// Time per frame in seconds.
  float mTimePerFrame;


  /// The number of frames for animation, i.e. if a sprite has 3 animations.
  int mFrameCount;

  /// The wrap mode of the AnimatedTexture.
  WRAP_MODE mWrapMode;
  /// The direction of the Animated Texture
  ANIM_DIR mAnimationDirection;

  /// Is the animation done?
  bool mAnimationDone;
};

#endif