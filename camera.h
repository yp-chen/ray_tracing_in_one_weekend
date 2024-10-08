#ifndef CAMERA_H
#define CAMERA_H
#include "vec3.h"
#include "ray.h"
#include "device.h"
#include "sphere.h"
#include <vector>
class Camera {
    public:
        Camera(Point3 center_point, Vec3 up, Vec3 look_at, double vfov, double aspect_ratio, double screen_height);
        // Ray get_ray(double u, double v) const; // u,v are in [0,1]
        Color ray_color(const Ray& r, std::vector<Object*> world, int maxdepth) const; //返回颜色
        void rander(std::vector<Object*> world); //渲染屏幕
        void printval() const;
    private:
        Point3 center_point_;
        Vec3 up_;
        Vec3 look_at_;
        double aspect_ratio_;//宽高比
        double fov_;//视场角
        double viewport_height_;//视口高度
        double viewport_width_;//视口宽度
        Device Graphics;
        int sample_num_ = 50; //采样次数
        int maxdepth_ = 10; //最大递归深度
        Vec3 w, u, v;
        Vec3 pixel_delta_u, pixel_delta_v;
        Point3 lower_left_corner_;
};
#endif