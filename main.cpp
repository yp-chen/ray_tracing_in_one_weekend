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
    constexpr int ScreenWidth = 540;
    constexpr double AspectRatio = 16.0 / 9.0;
    Material* ground_material = new Material(MetalType::kDiffuse ,Vec3(0.5, 0.5, 0.5));
    Sphere ground(Point3(0, -1000, 0), 1000, ground_material);

    Camera camera(Point3(13, 2, 3), Vec3(0, 1, 0), Vec3(0, 0, 0), 20, AspectRatio, ScreenWidth);
    Scene scene(camera);
    scene.add_sphere_list(&ground);
    for (int a = -11; a < 11; a++) {
        for (int b = -11; b < 11; b++) {
            double choose_mat = random_double();
            Point3 center(a + 0.9 * random_double(), 0.2, b + 0.9 * random_double());
            if ((center - Point3(4, 0.2, 0)).norm() > 0.9) {
                if (choose_mat < 0.8) {
                    Material* sphere_material = new Material(MetalType::kDiffuse ,Vec3(random_double() * random_double(), random_double() * random_double(), random_double() * random_double()));
                    scene.add_sphere_list(new Sphere(center, 0.2, sphere_material));
                }
                else if (choose_mat < 0.95) {
                    Material* sphere_material = new Material(MetalType::kMetal ,Vec3(0.5 * (1 + random_double()), 0.5 * (1 + random_double()), 0.5 * (1 + random_double())), 0.5 * random_double());
                    scene.add_sphere_list(new Sphere(center, 0.2, sphere_material));
                }
                else {
                    Material* sphere_material = new Material(MetalType::kDielectric ,Vec3(1, 1, 1), 0.0, 1.5);
                    scene.add_sphere_list(new Sphere(center, 0.2, sphere_material));
                }
            }
        }
    }
    Material* material1 = new Material(MetalType::kDielectric ,Vec3(1, 1, 1), 0.0, 1.5);
    scene.add_sphere_list(new Sphere(Point3(0, 1, 0), 1.0, material1));
    Material* material2 = new Material(MetalType::kDiffuse ,Vec3(0.4, 0.2, 0.1));
    scene.add_sphere_list(new Sphere(Point3(-4, 1, 0), 1.0, material2));
    Material* material3 = new Material(MetalType::kMetal ,Vec3(0.7, 0.6, 0.5), 0.0);
    scene.add_sphere_list(new Sphere(Point3(4, 1, 0), 1.0, material3));
    scene.render();
    _getch();
    return 0;
}