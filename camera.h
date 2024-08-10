#ifndef CAMERA_H
#define CAMERA_H
#include "vec3.h"
#include "ray.h"
#include "device.h"
#include "sphere.h"
class Camera {
    public:
        Camera(Point3 center_point, Vec3 up, Vec3 look_at, double vfov, double aspect_ratio, double screen_height, double near);
        Ray get_ray(double u, double v) const; // u,v are in [0,1]
        Color ray_color(const Ray& r, Sphere world) const; //返回颜色
        void rander(Sphere world); //渲染屏幕
        void printval() const;
    private:
        Point3 center_point_;
        Vec3 up_;
        Vec3 look_at_;
        double aspect_ratio_;//宽高比
        double fov_;//视场角
        double viewport_height_;//视口高度
        double viewport_width_;//视口宽度
        double near_;//近平面
        double far_ = 0;//远平面
        double near_width_;//近平面的宽度和高度
        double near_height_;
        double half_near_width_;//近平面的一半宽度和高度
        double half_near_height_;
        Device Graphics;
};
#endif