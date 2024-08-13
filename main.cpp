#define UNICODE
#define _UNICODE
#include <conio.h>
#include "ray.h"
#include "global.h"
#include "camera.h"
#include "sphere.h"
#include "scene.h"
#include "material.h"
int main() {
    constexpr int ScreenWidth = 640;
    constexpr double AspectRatio = 16.0 / 9.0;
    Material* ground_material = new Material(MetalType::kDiffuse ,Vec3(0.8, 0.8, 0.0));
    Material* sphere_material = new Material(MetalType::kDiffuse ,Vec3(0.1, 0.2, 0.5));
    Material* left_material = new Material(MetalType::kDielectric ,Vec3(0.8, 0.8, 0.8), 0.3, 1.50);
    Material* left_material2 = new Material(MetalType::kDielectric ,Vec3(0.8, 0.8, 0.8), 0.3, 1.00 / 1.50);
    Material* right_material = new Material(MetalType::kMetal ,Vec3(0.8, 0.6, 0.2), 1.0);
    Sphere sphere(Point3(0, 0, -1.2), 0.5, sphere_material);
    Sphere left(Point3(-1, 0, -1), 0.5, left_material);
    Sphere left2(Point3(-1, 0, -1), 0.4, left_material2);
    Sphere right(Point3(1, 0, -1), 0.5, right_material);
    Sphere ground(Point3(0, -100.5, -1.0), 100, ground_material);
    Camera camera(Point3(0, 0, 0), Vec3(0, 1, 0), Vec3(0, 0, -1), 90, AspectRatio, ScreenWidth, 1);
    Scene scene(camera);
    scene.add_sphere_list(&sphere);
    scene.add_sphere_list(&ground);
    scene.add_sphere_list(&left);
    scene.add_sphere_list(&left2);
    scene.add_sphere_list(&right);
    scene.render();
    _getch();
    return 0;
}