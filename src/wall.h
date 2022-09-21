#ifndef WALL_H
#define WALL_H

#include <Godot.hpp>
#include <Spatial.hpp>
#include <Area.hpp>
#include <KinematicBody.hpp>

namespace godot {

class Wall : public Area {
    GODOT_CLASS(Wall, Spatial)

private:
    Vector3 normal;

public:
	static void _register_methods();

	Wall();
	~Wall();

	void _init(); // our initializer called by Godot
    void _ready();

    Vector3 get_normal();

	void _process(float delta);
};


}
#endif
