#include "Tank.h"

Tank::Tank() {
	string color[2] = { "red", "blue" };
	_tank.load("img/" + ofToString(color[0]) + "_tank.png");
	_barrel.load("img/" + ofToString(color[0]) + "_barrel.png");
	
	_position = ofVec2f(0, 0);
	_direction = ofVec2f(0, 0);

	_angle = 0;
	_speed = 1;
}

void Tank::Update() {
	cout << _position << endl << _angle << endl;
}

void Tank::Draw(Matrix3f &world) {
	_tank.setAnchorPercent(0.5, 0.5);

	ofPushMatrix();
	world = world.translate(_position.x, _position.y);
	world = world.rotate(_angle);
	//world = world.scale(0.5f, 0.5f);
	ofVec2f position = world.transform(_position, 1);
	_tank.draw(position.x - _position.x, position.y - _position.y);
	_barrel.draw(position.x - _position.x, position.y - _position.y);
	ofPopMatrix();
}
