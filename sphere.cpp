#include "sphere.h"
bool Sphere::hit(const Ray& r,Interval inter,hit_record& rec) const {
    Vec3 oc = r.origin() - center_;
    double a = r.direction().dot(r.direction());
    double halfb = oc.dot(r.direction());
    double c = oc.dot(oc) - radius_ * radius_;
    double discriminant = halfb * halfb - a * c;
    if (discriminant < 0) {
        return false;
    }
    double t = (-halfb - std::sqrt(discriminant)) / a;
    if (!inter.surrounds(t)) {
        t = (-halfb + std::sqrt(discriminant)) / a;
        if (!inter.surrounds(t)) {
            return false;
        }
    }
    rec.hit = true;
    rec.t = t;
    rec.p = r.at(t);
    rec.normal = (rec.p - center_) / radius_;
    rec.mat_ptr = mat_ptr_;
    rec.front_face = r.direction().dot(rec.normal) < 0;
    rec.normal = rec.front_face ? rec.normal : -rec.normal;
    return true;
}
