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
};
class Object {
    public:
        virtual bool hit(const Ray& r,Interval inter,hit_record& rec) const = 0;
};
#endif