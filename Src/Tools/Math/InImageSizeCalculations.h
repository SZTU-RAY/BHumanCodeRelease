/**
 * @file InImageSizeCalculations.h
 *
 * A namespace with methods to calculate sizes in image.
 *
 * @author <a href="mailto:jesse@tzi.de">Jesse Richter-Klug</a>
 */

#pragma once

#include "Representations/Configuration/BallSpecification.h"
#include "Representations/Configuration/FieldDimensions.h"
#include "Representations/Infrastructure/CameraInfo.h"
#include "Representations/Perception/ImagePreprocessing/CameraMatrix.h"
#include "Math/Eigen.h"

namespace IISC
{
  /**
   * Calculates where a ball in-image would be, assuming the given start point is the lowest middle point of the ball that could be seen.
   *
   * @param start, point in image
   * @param circle, result of the calculation (in-image/pixel)
   * @param theCameraInfo
   * @param theCameraMatrix
   * @param theBallSpecification
   * @param greenEdge (optional) The greenEdge of the ball (a line at the ball given by an angle offset to the point of ball-ground-intersection: we assume that the part of the ball under this line is not well visible in the image, because of low light conditions and reflecting ground/green)
   * @return false if the calculation failed
   */
  [[nodiscard]] bool calcPossibleVisibleBallByLowestPoint(const Vector2f& start, Geometry::Circle& circle,
      const CameraInfo& theCameraInfo, const CameraMatrix& theCameraMatrix, const BallSpecification& theBallSpecification,
      const Angle greenEdge = 60_deg);

  /**
   * Calculates the in-image-vertical size of an in-image-horizontal line with the given
   * image point that is used as the lowest visible point.
   *
   * @param start, point in image (lowest visible line point)
   * @param theCameraInfo
   * @param theCameraMatrix
   * @param theFieldDimensions
   * @return the in-image-size in pixel
   *     error case: -1
   */
  float getImageLineDiameterByLowestPoint(const Vector2f& start,
                                          const CameraInfo& theCameraInfo, const CameraMatrix& theCameraMatrix, const FieldDimensions& theFieldDimensions);

  /**
   * Calculates the in-image-sizes of the penalty mark according to the given
   * image point that is used as the lowest middle point that is seen.
   *
   * @param center, the in image lowest center point of the PM that is seen
   * @param length, the calculated in-image-horizontal-size (in pixel) of the PM in case of true
   * @param height, the calculated in-image-vertical-size (in pixel) of the PM in case of true
   * @param theCameraInfo
   * @param theCameraMatrix
   * @param theFieldDimensions
   * @return false if the calculation failed
   */
  [[nodiscard]] bool calculateImagePenaltyMeasurementsByCenter(const Vector2f& center, float& length, float& height,
      const CameraInfo& theCameraInfo, const CameraMatrix& theCameraMatrix, const FieldDimensions& theFieldDimensions);

  /**
   * Calculates the in-image-vertical in-image-size of the given on-field-diameter according to the given
   * image point that is used as the start / lowest point.
   *
   * @param fieldDiameter, diameter on field
   * @param start, point in image
   * @param theCameraInfo
   * @param theCameraMatrix
   * @return the in-image-size in pixel
   *     error case: -1
   */
  float getImageDiameterByLowestPointAndFieldDiameter(const float fieldDiameter, const Vector2f& start,
      const CameraInfo& theCameraInfo, const CameraMatrix& theCameraMatrix);

  /**
   * Calculates the in-image-horizontal in-image-size of the given on-field-diameter according to the given
   * image point that is used as the middle point
   *
   * @param fieldDiameter, diameter on field
   * @param middle, point in image
   * @param theCameraInfo
   * @param theCameraMatrix
   * @return the in-image-size in pixel
   *     error case: -1
   */
  float getHorizontalImageDiameterByMiddlePointAndFieldDiameter(const float fieldDiameter, const Vector2f& middle,
      const CameraInfo& theCameraInfo, const CameraMatrix& theCameraMatrix);
};
