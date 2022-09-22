#include "ball.h"
#include <ctime>
#include "wall.h"

using namespace godot;


void Ball::_register_methods() {
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
    Wall* w = Object::cast_to<Wall>(area);
    if (w != NULL) {
        Vector3 N = w->get_normal().normalized();
        Vector3 I = direction;
        direction = I.bounce(N);
    } else {
        Ball* b = Object::cast_to<Ball>(area);

        Vector3 N = b->get_direction().normalized();
        Vector3 I = direction.normalized();
        direction = I.bounce(N);
    }
}

Vector3 Ball::get_direction() {
    return direction;
}

void Ball::_init() {
    id = 1;
    std::srand(std::time(NULL));
}

void Ball::_ready() {
    this->connect("area_entered", this, "_on_hit");
    float x = ((float)std::rand() / RAND_MAX);
    float y = ((float)std::rand() / RAND_MAX);
    float z = ((float)std::rand() / RAND_MAX);
    direction = Vector3(x, y, z);
    Godot::print(direction);
}

void Ball::_process(float delta) {
    translate(direction);
    // Check intersections
}
