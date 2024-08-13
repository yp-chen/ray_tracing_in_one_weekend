#ifndef MATERIAL_H
#define MATERIAL_H
#include "ray.h"
#include "vec3.h"
#include "global.h"
#include "object.h"
enum MetalType {
    kDiffuse,
    kMetal,
    kDielectric
};
class hit_record;
//材质类
class Material {
    public:
        Material(MetalType type, const Color& albedo) : type_(type), albedo_(albedo) {}
        virtual ~Material() = default;

        //返回散射后的光线
        bool scatter(const Ray& r_in, const hit_record& rec, Color& attenuation, Ray& scattered) const {
            if (type_ == kDiffuse) {
                Vec3 scatter_direction = rec.normal + random_unit_vector();
                if (scatter_direction.near_zero())
                    scatter_direction = rec.normal;
                scattered = Ray(rec.p, scatter_direction);
                attenuation = albedo_;
                return true;
            } else if (type_ == kMetal) {
                Vec3 reflected = reflect(r_in.direction().normalize(), rec.normal);
                scattered = Ray(rec.p, reflected);
                attenuation = albedo_;
                return (dot(scattered.direction(), rec.normal) > 0);
            } else {
                return false;
            }
        }
        Vec3 reflect(Vec3 v, Vec3 n) const {
            return v - 2 * dot(v, n) * n;
        }
    private:
        MetalType type_;
        Color albedo_; //漫反射颜色
};

#endif