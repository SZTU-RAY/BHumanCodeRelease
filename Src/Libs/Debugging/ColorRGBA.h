#pragma once

#include "Streaming/InOut.h"

class ColorRGBA
{
public:
  unsigned char r = 0;
  unsigned char g = 0;
  unsigned char b = 0;
  unsigned char a = 255;

  static const ColorRGBA white;
  static const ColorRGBA black;
  static const ColorRGBA red;
  static const ColorRGBA green;
  static const ColorRGBA blue;
  static const ColorRGBA yellow;
  static const ColorRGBA cyan;
  static const ColorRGBA magenta;
  static const ColorRGBA orange;
  static const ColorRGBA violet;
  static const ColorRGBA gray;
  static const ColorRGBA brown;

  ColorRGBA() = default;

  ColorRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a = 255) :
    r(r), g(g), b(b), a(a)
  {}

  static ColorRGBA fromTeamColor(int teamColor);

  ColorRGBA operator*(float scale) const;
  bool operator==(const ColorRGBA& other) const;
  bool operator!=(const ColorRGBA& other) const {return !(*this == other);}
  ColorRGBA blend(const ColorRGBA& other) const;
  ColorRGBA interpolate(const float factor, const ColorRGBA& other) const;

private:
  static void reg();
};

In& operator>>(In& stream, ColorRGBA&);
Out& operator<<(Out& stream, const ColorRGBA&);
