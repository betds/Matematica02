#pragma once

#include "ofMain.h"

using namespace std;

class Matrix3f {

private:
	float _entry[3][3];

public:
	// Construtores
	Matrix3f();
	Matrix3f(float v);
	Matrix3f(float a, float b, float c, float d, float e, float f, float g, float h, float k);
	Matrix3f(Matrix3f &other);
	
	// Print da Matriz
	string round(float value, int precision);
	void print();
	
	// Acessos
	float a();
	float b();
	float c();
	float d();
	float e();
	float f();
	float g();
	float h();
	float k();
	
	// Operadores
	float operator()(int i, int j); 
	Matrix3f operator=(Matrix3f &other);
	Matrix3f operator+(Matrix3f &other);
	Matrix3f operator+=(Matrix3f &other);
	Matrix3f operator-(Matrix3f &other);
	Matrix3f operator-=(Matrix3f &other);
	Matrix3f operator*(Matrix3f &other);

	// Funções Matriciais
	float determinant();
	Matrix3f cofactor();
	Matrix3f transpose();
	Matrix3f adjunct();
	Matrix3f inverse();

	// Transformação (ofVec2f)
	//ofVec2f Matrix3f::transform(const ofVec2f& vector, float z = 1.0f) const;
	ofVec2f Matrix3f::transform(const ofVec2f& vector, float z) const;

	// Métodos Estáticos
	static Matrix3f rotate(float angle);
	static Matrix3f translate(float dx, float dy);
	static Matrix3f scale(float sx, float sy);

	// ofMatrix4x4
	ofMatrix4x4 to4x4();
};