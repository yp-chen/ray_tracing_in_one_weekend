#ifndef GLOBAL_H
#define GLOBAL_H
#include <random>
//PI
#define M_PI 3.14159265358979323846
//无穷大
#define MY_INFINITY 1e8
//返回一个[0,1)的随机数
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}
//返回一个[min,max)的随机数
inline double random_double(double min, double max) {
    return min + (max - min) * random_double();
}
//返回一个像素点[0,1)*[0,1)内的随机点
inline Point3 random_point() {
    return Point3(random_double(), random_double(), 0);
}
//返回一个随机单位向量
inline Vec3 random_unit_vector() {
    double alpha = random_double(0, 2 * M_PI);
    double beta = random_double(0, M_PI);
    return Vec3(cos(alpha) * sin(beta), sin(alpha) * sin(beta), cos(beta));
}
//返回上半球面的随机点
inline Vec3 random_in_hemisphere(const Vec3& normal) {
    Vec3 in_unit_sphere = random_unit_vector();
    if (dot(in_unit_sphere, normal) > 0.0) {
        return in_unit_sphere;
    } else {
        return -in_unit_sphere;
    }
}
#endif