#ifndef OBJECT_H
#define OBJECT_H
#include "ray.h"
#include "global.h"
#include "interval.h"
struct hit_record {
    bool hit = false;
    Point3 p;
    Vec3 normal;
    double t = MY_INFINITY;
};
class Object {
    public:
        virtual bool hit(const Ray& r,Interval inter,hit_record& rec) const = 0;
};
#endif