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
        Material(MetalType type, const Color& albedo, float fuzziness = 0.0f, float ior = 1.5f) : type_(type), albedo_(albedo), fuzz_(fuzziness), ior_(ior) {}
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
                reflected = reflected.normalize() + fuzz_ * random_unit_vector();
                scattered = Ray(rec.p, reflected);
                attenuation = albedo_;
                return (dot(scattered.direction(), rec.normal) > 0);
            } else  if (type_ == kDielectric) {
                attenuation = Color(1.0, 1.0, 1.0);
                double ri = rec.front_face ? (1.0/ior_) : ior_;
                Vec3 unit_direction = r_in.direction().normalize();
                double cos_theta = std::fmin(dot(-unit_direction, rec.normal), 1.0);
                double sin_theta = std::sqrt(1.0 - cos_theta*cos_theta);
                bool cannot_refract = ri * sin_theta > 1.0;
                Vec3 direction;
                if (cannot_refract || reflectance(cos_theta, ri) > random_double())
                    direction = reflect(unit_direction, rec.normal);
                else
                    direction = refract(unit_direction, rec.normal, ri);
                scattered = Ray(rec.p, direction);
                return true;
            } else {
                return false;
            }
        }
        //反射
        Vec3 reflect(Vec3 v, Vec3 n) const {
            return v - 2 * dot(v, n) * n;
        }
        //折射
        Vec3 refract(Vec3 v, Vec3 n, float ior) const {
            double cos_theta = std::fmin(dot(-v, n), 1.0);
            Vec3 r_out_perp = ior * (v + cos_theta * n);
            Vec3 r_out_parallel = -std::sqrt(fabs(1.0 - r_out_perp.norm2())) * n;
            return r_out_perp + r_out_parallel;
        }

        static double reflectance(double cosine, double refraction_index) {
            auto r0 = (1 - refraction_index) / (1 + refraction_index);
            r0 = r0*r0;
            return r0 + (1-r0)*std::pow((1 - cosine),5);
        }
    private:
        MetalType type_;
        Color albedo_; //漫反射颜色
        double fuzz_; //模糊度
        float ior_; //折射率
};

#endif