#ifndef INCLUDE_LIB_MATH_VEC2_H_
#define INCLUDE_LIB_MATH_VEC2_H_

#include <cmath>
#include <tuple>
#include <utility>

class Vec2 {
 public:
  float x;
  float y;

  constexpr Vec2() noexcept : x(0.0f), y(0.0f) {}
  constexpr Vec2(float x, float y) noexcept : x(x), y(y) {}
  constexpr Vec2(int x, int y) noexcept : x(static_cast<float>(x)), y(static_cast<float>(y)) {}

  bool operator==(const Vec2 &rhs) const {
    return std::tie(x, y) == std::tie(rhs.x, rhs.y);
  }
  bool operator!=(const Vec2 &rhs) const {
    return !(rhs == *this);
  }

  Vec2 operator+(const Vec2 &rhs) const {
    return {x + rhs.x, y + rhs.y};
  }

  Vec2 operator+=(const Vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
  }

  Vec2 operator-(const Vec2 &rhs) const {
    return {x - rhs.x, y - rhs.y};
  }

  Vec2 operator*(float c) const {
    return {x * c, y * c};
  }

  Vec2 operator*=(float c) {
    x *= c;
    y *= c;
    return *this;
  }

  Vec2 operator*(const Vec2 &rhs) const {
    return {x * rhs.x, y * rhs.y};
  }

  Vec2 operator*=(const Vec2 &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
  }

  double DotProd(const Vec2 &rhs) const {
    return x * rhs.x + y * rhs.y;
  }

  double CrossProd(const Vec2 &rhs) const {
    return x * rhs.y - y * rhs.x;
  }

  Vec2 Abs() const {
    return Vec2(std::abs(x), std::abs(y));
  }

  /**
   * Euclidean L2 norm, Length of the vector.
   */
  double Magnitude() const {
    return std::sqrt(x * x + y * y);
  }

  Vec2 Normalize() {
    auto m = Magnitude();
    if (m <= 0.000000001) {
      x = 0;
      y = 0;
    } else {
      x /= m;
      y /= m;
    }

    return *this;
  }
};

const Vec2 ZeroVec2(0, 0);
const Vec2 UpVec2(0, -1);
const Vec2 DownVec2(0, 1);
const Vec2 RightVec2(1, 0);
const Vec2 LeftVec2(-1, 0);
const Vec2 OnesVec2(1, 1);

#endif  // INCLUDE_LIB_MATH_VEC2_H_
