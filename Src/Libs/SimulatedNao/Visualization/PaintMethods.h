/**
 * @file Visualization/PaintMethods.h
 * Declaration of class PaintMethods.
 *
 * @author <A href="mailto:juengel@informatik.hu-berlin.de">Matthias Jüngel</A>
 * @author Colin Graf
 */

#pragma once

#include "SimulatedNao/Visualization/DebugDrawing.h"
#include <QBrush>
#include <QImage>
#include <QPen>

class DebugDrawing;
class QPainter;
class QTransform;

/**
 * @class PaintMethods
 *
 * Defines static methods to paint debug drawings to QPainters.
 */
class PaintMethods
{
private:
  static QBrush brush;
  static QBrush noBrush;
  static QPen pen;
  static QPen noPen;
  static QImage robot;

public:
  /**
   * Paints a DebugDrawings to a QPainter.
   * @param painter The graphics context the DebugDrawing is painted to.
   * @param debugDrawing The DebugDrawing to paint.
   * @param baseTrans A basic transformation.
   */
  static void paintDebugDrawing(QPainter& painter, const DebugDrawing& debugDrawing, const QTransform& baseTrans);

  static void paintLine(const DebugDrawing::Line& element, QPainter& painter);
  static void paintPolygon(const DebugDrawing::Polygon& element, QPainter& painter);
  static void paintEllipse(const DebugDrawing::Ellipse& element, QPainter& painter);
  static void paintArc(const DebugDrawing::Arc& element, QPainter& painter);
  static void paintOrigin(const DebugDrawing::Origin& element, QPainter& painter, const QTransform& baseTrans);
  static void paintText(const DebugDrawing::Text& element, QPainter& painter, const QTransform& baseTrans);
  static void paintRectangle(const DebugDrawing::Rectangle& element, QPainter& painter);
  static void paintRobot(const DebugDrawing::Robot& element, QPainter& painter);
  static void paintGridMono(const DebugDrawing::GridMono& element, QPainter& painter);
  static void paintGridRGBA(const DebugDrawing::GridRGBA& element, QPainter& painter);
  static void paintGridRectangleRGBA(const DebugDrawing::GridRectangleRGBA& element, QPainter& painter);

  static void setPen(const DebugDrawing::Element& element, QPainter& painter);
  static void setBrush(const Drawings::BrushStyle brushStyle, const ColorRGBA& brushColor, QPainter& painter);
};
