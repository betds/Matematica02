#pragma once

#include "ofMain.h"
#include "Matrix3f.h"

class Tank {

public:
	ofImage _tank;
	ofVec2f _position, _direction;
	float _angle;
	int _speed;
	int _keyPress;

	Tank();
	void Update();
	void Draw(Matrix3f &world);
	void CannonRotation();
	void TankRotation();
	void TankMoviment();
	void Threshold();
	void PlayerInput(int velocityType); // Para a escolha da velocidade do tanque
};
