#ifndef OBJECT_H
#define OBJECT_H
#include "ray.h"
struct hit_record {
    Point3 p;
    Vec3 normal;
    double t;
};
class Object {
    public:
        virtual bool hit(const Ray& r, hit_record& rec) const = 0;
};
#endif