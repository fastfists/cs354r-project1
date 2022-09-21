#ifndef BALL_H
#define BALL_H

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Area.hpp>

namespace godot {

class Ball : public Area {
    GODOT_CLASS(Ball, Spatial)

private:
    Vector3 direction;
    int id;

public:
	static void _register_methods();

	Ball();
	~Ball();

	void _init(); // our initializer called by Godot
	void _process(float delta);
    void _ready();
    Vector3 get_direction();

    // Signals
    void _on_hit(Area* area);

};


}
#endif
