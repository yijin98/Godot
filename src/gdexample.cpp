#include "gdexample.h"

using namespace godot;

void GDExample::_register_methods() {
	register_method("_ready", &GDExample::_ready);
    register_method("_process", &GDExample::_process);
    register_method("_on_area_entered", &GDExample::_on_area_entered);
}

GDExample::GDExample() {
}

GDExample::~GDExample() {
    // add your cleanup here
}

void GDExample::_init() {
	//srand(time(0));
	float v1 = rand()%17-8;
	float v2 = rand()%17-8;
	float v3 = rand()%17-8;

	translate(Vector3(v1,v2,v3));

	float d1 = rand()/(float)(RAND_MAX+5);
	float d2 = rand()/(float)(RAND_MAX+5);
	float d3 = rand()/(float)(RAND_MAX+5);
	
	speed = rand()%2+1;
	direction = Vector3(d1,d2,d3);

    // initialize any variables here
    time_passed = 0.0;
}

void GDExample::_ready(){
	find_node("area", true, false)->connect("area_entered", this, "_on_area_entered");
}

void GDExample::_on_area_entered(Area * a){
	Node *wall = a->get_parent();
	if (wall->get_name().find("wall") >= 0){
		Vector3 norm = wall->get("normal");
		float dp = norm[0]*direction[0]+norm[1]*direction[1]+norm[2]*direction[2];
		norm = 2 * norm * dp;
		direction = direction - norm;
	} 

}

void GDExample::_process(float delta) {
    time_passed += delta;

    //Vector3 new_position = Vector3(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)), 0);

    translate(Vector3(direction*speed));
}
