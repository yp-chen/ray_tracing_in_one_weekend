#ifndef GLOBAL_H
#define GLOBAL_H
#include <random>
#define M_PI 3.14159265358979323846
//无穷大
#define MY_INFINITY 1e8
//返回一个[0,1)的随机数
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}
//返回一个像素点[0,1)*[0,1)内的随机点
inline Point3 random_point() {
    return Point3(random_double(), random_double(), 0);
}
#endif