#pragma once

#include "ofMain.h"
#include "Matrix3f.h"

class Tank {

public:
	ofImage _tank, _barrel;
	ofVec2f _position, _direction;
	float _angle;
	int _speed;

	Tank();
	void Update();
	void Draw(Matrix3f &world);
	void PlayerInput(int velocityType); // Para a escolha da velocidade do tanque
};
