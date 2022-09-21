#include "ball.h"
#include "wall.h"

using namespace godot;


void Ball::_register_methods() {
    register_property<Ball, float>("speed", &Ball::speed, 0.5);
    register_property<Ball, int>("id", &Ball::id, 1);

    register_method("_process", &Ball::_process);
    register_method("_ready", &Ball::_ready);
    register_method("_on_hit", &Ball::_on_hit);
}

Ball::Ball() {

}

Ball::~Ball() {

}

void Ball::_on_hit(Area* area) {
    direction = -direction;
    Wall* n = Object::cast_to<Wall>(area);
    Vector3 N = n->get_normal();
    Vector3 I = direction;
    Godot::print("--- hit ---");
    Godot::print(N);
    direction = I - 2*N*(N-I);
    Godot::print(direction);
    this->connect("area_entered", this, "_on_hit");
}

void Ball::_init() {
	speed = 0.5;
    id = 1;
    direction = Vector3(speed, speed, speed);
    Godot::print("Hello bruvvvv");
}

void Ball::_ready() {
    this->connect("area_entered", this, "_on_hit");
}

void Ball::_process(float delta) {
    translate(direction);
    // Check intersections
}
