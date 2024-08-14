#ifndef OBJECT_H
#define OBJECT_H
#include "ray.h"
#include "global.h"
#include "interval.h"
#include <memory>
class Material;
class hit_record {
public:
    bool hit = false;
    Point3 p;
    Vec3 normal;
    double t = MY_INFINITY;
    std::shared_ptr<Material> mat_ptr;
    bool front_face; //判断是否是正面
};
class Object {
    public:
        virtual bool hit(const Ray& r,Interval inter,hit_record& rec) const = 0;
        virtual ~Object() = default;
        // virtual void transform(Vec3 w, Vec3 u, Vec3 v, Vec3 center_point) = 0;
};
#endif