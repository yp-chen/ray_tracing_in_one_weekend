#include "camera.h"
#include "vec3.h"
#include "ray.h"
#include "global.h"
#include "interval.h"
#include "material.h"
Camera::Camera(Point3 center_point, Vec3 up, Vec3 look_at, double vfov, double aspect_ratio, double screen_height): Graphics(aspect_ratio * screen_height, screen_height) {
    center_point_ = center_point;
    up_ = up;
    look_at_ = look_at;
    aspect_ratio_ = aspect_ratio;
    fov_ = vfov;
    viewport_height_ = screen_height;
    viewport_width_ = aspect_ratio_ * viewport_height_;    
    double theta = vfov * M_PI / 180;
    double h = tan(theta / 2);
    double viewport_height = 2.0 * h;
    double viewport_width = aspect_ratio * viewport_height;
    w = (center_point_ - look_at_).normalize();
    u = up_.cross(w).normalize();
    v = w.cross(u).normalize();
    Vec3 horizontal = viewport_width * u;
    Vec3 vertical = viewport_height * -v;
    pixel_delta_u = horizontal / viewport_width_;
    pixel_delta_v = vertical / viewport_height_;
    lower_left_corner_ = center_point_ - horizontal / 2 - vertical / 2 - w;
}

// Ray Camera::get_ray(double u, double v) const {
//     Vec3 horizontal = Vec3(half_near_width_, 0, 0);
//     Vec3 vertical = Vec3(0, half_near_height_, 0);
//     Vec3 lower_left_corner = center_point_ - horizontal - vertical - Vec3(0, 0, near_);
//     Vec3 origin = center_point_;
//     Vec3 direction = lower_left_corner + u * horizontal + v * vertical - origin;
//     return Ray(origin, direction);
// }

Color Camera::ray_color(const Ray& r, std::vector<Object*> world, int maxdepth) const {
    if (maxdepth <= 0) {
        return Color(0, 0, 0);
    }
    hit_record rec;
    for (auto& obj : world) {
        hit_record temp_rec;
        if (obj->hit(r, Interval(0.001, MY_INFINITY), temp_rec)) {
            if (temp_rec.t < rec.t) {
                rec = temp_rec;
            }
        }
    }
    if (rec.hit) {
        Ray scattered;
        Color attenuation;
        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered))
            return attenuation * ray_color(scattered, world, maxdepth-1);
        return Color(0,0,0);
    }
    Vec3 Direction = r.direction().normalize();
    const auto a = 0.5 * (Direction[1] + 1.0);
    auto Result = (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color (0.5, 0.7, 1.0);
    Result = Result * 255.0;
    return Result;
}

void Camera::rander(std::vector<Object*> world) {
    // printval();
    for (int i = 0; i < viewport_height_; ++i) {
        std::clog << "\rThere are still left:" << ( viewport_height_ - i) << "scanlines to be rendered" << std::flush;
        for (int j = 0; j < viewport_width_; ++j) {
            //当前中心点坐标
            Color writecolor(0, 0, 0);
            for (int k = 0; k < sample_num_; ++k) {
                Point3 sample_point = random_point();
                Point3 center = lower_left_corner_ + (j + sample_point[0]) * pixel_delta_u + (i + sample_point[1]) * pixel_delta_v;
                Ray r(center_point_, center - center_point_);
                writecolor += ray_color(r, world, maxdepth_) / sample_num_;
            }
            Graphics.At(j, i) = colorToDWORD(writecolor);
        }
    }
    std::clog << "\rrendered finish" << std::endl;
    Device::Flush();
}

void Camera::printval() const {
    std::clog << "center_point:" << center_point_ << std::endl;
    std::clog << "up:" << up_ << std::endl;
    std::clog << "look_at:" << look_at_ << std::endl;
    std::clog << "aspect_ratio:" << aspect_ratio_ << std::endl;
    std::clog << "fov:" << fov_ << std::endl;
    std::clog << "viewport_height:" << viewport_height_ << std::endl;
    std::clog << "viewport_width:" << viewport_width_ << std::endl;
    std::clog << "w:" << w << std::endl;
    std::clog << "u:" << u << std::endl;
    std::clog << "v:" << v << std::endl;
    std::clog << "pixel_delta_u:" << pixel_delta_u << std::endl;
    std::clog << "pixel_delta_v:" << pixel_delta_v << std::endl;
    std::clog << "lower_left_corner:" << lower_left_corner_ << std::endl;
}