#ifndef WALL_H
#define WALL_H

#include <Godot.hpp>
#include <MeshInstance.hpp>
#include <stdlib.h>
#include <stdio.h>

namespace godot {

class wall : public MeshInstance {
    GODOT_CLASS(wall, MeshInstance)

private:
    Vector3 normal;

public:
    static void _register_methods();

    wall();
    ~wall();

    void _init();

};

}

#endif