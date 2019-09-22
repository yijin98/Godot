#include "wall.h"

using namespace godot;

void wall::_register_methods() {
	register_property<wall, Vector3>("normal", &wall::normal, Vector3(0,0,0));
}

wall::wall() {
}

wall::~wall() {
    // add your cleanup here
}

void wall::_init() {
    Vector3 trans = get_translation();
    Vector3 rotate = get_rotation();

    if(rotate[2] > 0){
    	if(trans[1] == 0){
    		normal = Vector3(0,1,0);
    	} else {
    		normal = Vector3(0,-1,0);
    	}
    } else if (rotate[1] > 0){
    	if(trans[2] < 0){
    		normal = Vector3(0,0,1);
    	} else {
    		normal = Vector3(0,0,-1);
    	}
    } else {
    	if(trans[0] < 0){
    		normal = Vector3(1,0,0);
    	} else {
    		normal = Vector3(-1,0,0);
    	}
    }
}