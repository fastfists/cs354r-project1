# cs354r-project1
## Compiling 

Compiling using 
```
scons platfor=linux
```

## Project Report

I used an Area as the holder of the script that had a
mesh and a Collision Shape object. The circle class used
the area_entered signal to notify the circle when it
collides with either the wall or another ball. When this
happens it then gets the walls normal and uses Vector3:Bounce
to calculate the reflected vector.

## Video Demo

Link here [here](https://youtu.be/0Q_aePeqzzI)
