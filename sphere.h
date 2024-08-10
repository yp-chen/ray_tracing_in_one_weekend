#ifndef SPHERE_H
#define SPHERE_H
#include "object.h"
class Sphere: public Object {
    public:
        Sphere() {}
        Sphere(Point3 center, double radius) : center_(center), radius_(radius) {}
        virtual bool hit(const Ray& r, hit_record& rec) const override;
    private:
        Point3 center_;
        double radius_;
};
#endif