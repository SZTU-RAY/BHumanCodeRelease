/**
 * @file SkillRequest.h
 *
 * This file declares the representation of the request from the strategy layer to the skill layer.
 *
 * @author Arne Hasselbring
 */

#pragma once

#include "Math/Pose2f.h"
#include "Streaming/AutoStreamable.h"
#include "Streaming/Enum.h"

STREAMABLE(SkillRequest,
{
  ENUM(Type,
  {,
    none,
    stand,
    walk,
    shoot,
    pass,
    dribble,
    block,
    mark,
    observe,
  });

  struct Builder
  {
    // All coordinates/angles/directions are in field coordinates.
    //所有坐标/角度/方向均为场坐标
    static SkillRequest empty();
    static SkillRequest stand();
    static SkillRequest walkTo(const Pose2f& target);
    static SkillRequest shoot();
    static SkillRequest passTo(int target);
    static SkillRequest dribbleTo(Angle target);
    static SkillRequest block(const Vector2f& player);
    static SkillRequest mark(const Vector2f& player);
    static SkillRequest observe(const Vector2f& point);
  },

  (Type)(none) skill, /**< 应该运行的技能 */
  (Pose2f) target, /**< 所需的位置、物体或方向，均以场地坐标为基准 */
  (int)(-1) passTarget, /**< 要传的球员号码 */
});
