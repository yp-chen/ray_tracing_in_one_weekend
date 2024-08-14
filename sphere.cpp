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

// //w,u,v是相机坐标系下的坐标轴，center_point是相机在世界坐标轴下的原点
// void Sphere::transform(Vec3 w, Vec3 u, Vec3 v, Vec3 center_point) {
//     Vec3 new_center = center_ - center_point;
//     // Vec3 new_w = Vec3(w[0], u[0], v[0]);
//     // Vec3 new_u = Vec3(w[1], u[1], v[1]);
//     // Vec3 new_v = Vec3(w[2], u[2], v[2]);
//     // center_ = Point3(new_center.dot(new_w), new_center.dot(new_u), new_center.dot(new_v));
//     center_ = Point3(new_center.dot(w), new_center.dot(u), new_center.dot(v));
//     std::cout << "transformed center:" << center_ << std::endl;
// }
