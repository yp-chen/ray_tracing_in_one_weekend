#ifndef SPHERE_H
#define SPHERE_H
#include "object.h"
#include "material.h"
#include <memory>
class Sphere: public Object {
    public:
        Sphere() {}
        Sphere(Point3 center, double radius, Material* mat_ptr) : center_(center), radius_(radius), mat_ptr_(mat_ptr) {}
        virtual bool hit(const Ray& r,Interval inter,hit_record& rec) const override;
        // virtual void transform(Vec3 w, Vec3 u, Vec3 v, Vec3 center_point) override;
    private:
        Point3 center_;
        double radius_;
        std::shared_ptr<Material> mat_ptr_; //材质
};
#endif