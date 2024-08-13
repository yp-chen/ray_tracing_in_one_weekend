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
    private:
        Point3 center_;
        double radius_;
        std::shared_ptr<Material> mat_ptr_; //材质
};
#endif