#include "wall.h"
#include "ball.h"
#include <cstdlib>

using namespace godot;


void Wall::_register_methods() {
    register_method("_process", &Wall::_process);
    register_method("_init", &Wall::_init);
    register_method("_ready", &Wall::_ready);
    register_property("normal", &Wall::normal, Vector3(0, 1, 0));
    register_signal<Wall>((char*)"area_entered");
}

Wall::Wall() {

}

Wall::~Wall() {

}

void Wall::_ready() {
    auto n = this->get_parent()->get_parent()->get_node("Circle");


}

Vector3 Wall::get_normal() {
    return normal;
}

void Wall::_init() {
    Godot::print("I'm a wall hoe");
}

void Wall::_process(float delta) {
    // Check intersections

}
