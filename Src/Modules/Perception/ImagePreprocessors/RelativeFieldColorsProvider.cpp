/**
* @file RelativeFieldColorsProvider.cpp
*
* This file implements a module that approximates the current image's average
* luminance and saturation for discerning field and white.
*
* @author Lukas Malte Monnerjahn
*/

#include "RelativeFieldColorsProvider.h"

#include <list>

MAKE_MODULE(RelativeFieldColorsProvider);

void RelativeFieldColorsProvider::update(RelativeFieldColors& theRelativeFieldColors)
{
  theRelativeFieldColors.rfcParameters = theRelativeFieldColorsParameters;
  theRelativeFieldColors.averageLuminanceF = approximateAverage(theECImage.grayscaled);
  theRelativeFieldColors.averageSaturationF = approximateAverage(theECImage.saturated);
  theRelativeFieldColors.averageLuminance = static_cast<PixelTypes::GrayscaledPixel>(theRelativeFieldColors.averageLuminanceF);
  theRelativeFieldColors.averageSaturation = static_cast<PixelTypes::GrayscaledPixel>(theRelativeFieldColors.averageSaturationF);
}

float RelativeFieldColorsProvider::approximateAverage(const Image<PixelTypes::GrayscaledPixel>& image) const
{
  std::list<unsigned int> yList;
  if(theScanGrid.lowResHorizontalLines.empty())
  {
    yList.emplace_back(image.height * 3 / 8);
    yList.emplace_back(image.height / 4);
    yList.emplace_back(image.height / 8);
  }
  else
  {
    yList.emplace_back(theScanGrid.lowResHorizontalLines[theScanGrid.lowResHorizontalLines.size() / 4 * 3].y);
    yList.emplace_back(theScanGrid.lowResHorizontalLines[theScanGrid.lowResHorizontalLines.size() / 2].y);
    yList.emplace_back(theScanGrid.lowResHorizontalLines[theScanGrid.lowResHorizontalLines.size() / 4].y);
  }

  int sum = 0;
  int step = 8;
  unsigned int samples = image.width / step;
  for(const auto y : yList)
    for(unsigned int x = 0; x < samples; ++x)
      sum += image[y][step * x + 2];
  return static_cast<float>(sum) / (static_cast<float>(yList.size()) * static_cast<float>(samples));
}
