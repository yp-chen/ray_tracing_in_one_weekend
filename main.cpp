#define UNICODE
#define _UNICODE
#include <conio.h>
#include "ray.h"
#include "global.h"
#include "camera.h"
#include "sphere.h"
#include "scene.h"
int main() {
    constexpr int ScreenWidth = 640;
    constexpr double AspectRatio = 16.0 / 9.0;
    Sphere sphere(Point3(0, 0, -1), 0.5);
    Sphere ground(Point3(0, -100.5, -1), 100);
    Camera camera(Point3(0, 0, 0), Vec3(0, 1, 0), Vec3(0, 0, -1), 90, AspectRatio, ScreenWidth, 1);
    Scene scene(camera);
    scene.add_sphere_list(&sphere);
    scene.add_sphere_list(&ground);
    scene.render();
    _getch();
    return 0;
}