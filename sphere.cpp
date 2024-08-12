#include "sphere.h"
bool Sphere::hit(const Ray& r, hit_record& rec) const {
    Vec3 oc = r.origin() - center_;
    double a = r.direction().dot(r.direction());
    double halfb = oc.dot(r.direction());
    double c = oc.dot(oc) - radius_ * radius_;
    double discriminant = halfb * halfb - a * c;
    if (discriminant < 0) {
        return false;
    }
    double t = (-halfb - std::sqrt(discriminant)) / a;
    if (t < 0) {
        t = (-halfb + std::sqrt(discriminant)) / a;
        if (t < 0) {
            return false;
        }
    }
    rec.hit = true;
    rec.t = t;
    rec.p = r.at(t);
    rec.normal = (rec.p - center_) / radius_;
    return true;
}
