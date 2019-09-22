#ifndef GDEXAMPLE_H
#define GDEXAMPLE_H

#include <Godot.hpp>
#include <MeshInstance.hpp>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <area.hpp>
#include <wall.h>

namespace godot {

class GDExample : public MeshInstance {
    GODOT_CLASS(GDExample, MeshInstance)

private:
    float time_passed;
    Vector3 direction;
    float speed;

public:
    static void _register_methods();

    GDExample();
    ~GDExample();

    void _ready();

    void _init(); // our initializer called by Godot

    void _on_area_entered(Area * a);

    void _process(float delta);
};

}

#endif