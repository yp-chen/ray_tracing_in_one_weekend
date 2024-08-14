#ifndef VEC3_H
#define VEC3_H
#include <cmath>
#include <iostream>
#include <graphics.h>
class Vec3 {
    public:
        Vec3() : x_(0), y_(0), z_(0) {}
        Vec3(float x) : x_(x), y_(x), z_(x) {}
        Vec3(float x, float y, float z) : x_(x), y_(y), z_(z) {}
        float x() const { return x_; }
        float y() const { return y_; }
        float z() const { return z_; }
        Vec3 operator-() const { return Vec3(-x_, -y_, -z_); }

        Vec3 operator+(const Vec3& v) const { return Vec3(x_ + v.x_, y_ + v.y_, z_ + v.z_); }
        Vec3 operator-(const Vec3& v) const { return Vec3(x_ - v.x_, y_ - v.y_, z_ - v.z_); }
        Vec3 operator*(const Vec3& v) const { return Vec3(x_ * v.x_, y_ * v.y_, z_ * v.z_); }

        Vec3 operator+(float t) const { return Vec3(x_ + t, y_ + t, z_ + t); }
        Vec3 operator-(float t) const { return Vec3(x_ - t, y_ - t, z_ - t); }
        Vec3 operator*(float t) const { return Vec3(x_ * t, y_ * t, z_ * t); }
        // Vec3& operator=(const Vec3& v) const { return *this = v; }
        friend Vec3 operator*(float t, const Vec3& v) { return v * t; }
        Vec3 operator/(float t) const {
            if (t == 0) {
                return Vec3(0, 0, 0);
            }
            return *this * (1 / t); 
        }

        Vec3& operator+=(const Vec3& v) {
            x_ += v.x_;
            y_ += v.y_;
            z_ += v.z_;
            return *this;
        }
        Vec3& operator-=(const Vec3& v) {
            x_ -= v.x_;
            y_ -= v.y_;
            z_ -= v.z_;
            return *this;
        }

        float operator[](int i) const {
            if (i == 0) return x_;
            if (i == 1) return y_;
            return z_;
        }
        float& operator[](int i) {
            if (i == 0) return x_;
            if (i == 1) return y_;
            return z_;
        }
        float norm() const { return std::sqrt(x_ * x_ + y_ * y_ + z_ * z_); }
        float norm2() const { return x_ * x_ + y_ * y_ + z_ * z_; }
        Vec3 normalize() const { return *this / norm(); }
        friend std::ostream& operator<<(std::ostream& out, const Vec3& v) {
            return out << v.x_ << ' ' << v.y_ << ' ' << v.z_;
        }
        float dot(const Vec3& v) const { return x_ * v.x_ + y_ * v.y_ + z_ * v.z_; }
        Vec3 cross(const Vec3& v) const {
            return Vec3(y_ * v.z_ - z_ * v.y_, z_ * v.x_ - x_ * v.z_, x_ * v.y_ - y_ * v.x_);
        }
        bool near_zero() const {
            auto s = 1e-8;
            return (std::fabs(x_) < s) && (std::fabs(y_) < s) && (std::fabs(z_) < s);
        }

    private:
        float x_, y_, z_; // 3D vector
};

using Point3 = Vec3;
using Color = Vec3;

inline float dot(const Vec3& u, const Vec3& v) { return u.dot(v); }
inline Vec3 cross(const Vec3& u, const Vec3& v) { return u.cross(v); }

inline DWORD colorToDWORD(const Color& c) {
    return BGR(RGB(c.x(), c.y(), c.z()));
}
#endif
