#ifndef SCENE_H
#define SCENE_H
#include "camera.h"
#include <vector>
class Scene {
    public:
        Scene(Camera& camera) : camera_(camera) {
            sphere_ = {};
        }
        const Camera& get_camera() const { return camera_; }
        std::vector<Object*> get_sphere_list() const { return sphere_; }
        void set_camera(Camera camera) { camera_ = camera; }
        void add_sphere_list(Object* sphere) { sphere_.push_back(sphere); }
        void render() { camera_.rander(sphere_); };
    private:
        Camera camera_;
        std::vector<Object*> sphere_;
};
#endif