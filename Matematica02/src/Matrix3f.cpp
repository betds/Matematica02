#include "Matrix3f.h"

// Construtores
Matrix3f::Matrix3f() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_entry[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
}

Matrix3f::Matrix3f(float v) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_entry[i][j] = v;
		}
	}
}

Matrix3f::Matrix3f(float a, float b, float c, float d, float e, float f, float g, float h, float k) {
	float temp[9] = { a, b, c, d, e, f, g, h, k };

	int aux = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_entry[i][j] = temp[aux];
			aux++;
		}
	}
}

Matrix3f::Matrix3f(Matrix3f &other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_entry[i][j] = other(i, j);
		}
	}
}

// Print da Matriz
string Matrix3f::round(float value, int precision) {
	string out;
	precision += 2;

	float roundedValue = ceil(pow(10.0f, precision) * value);
	roundedValue *= pow(10.0f, -precision);

	out = ofToString(roundedValue);
	do {
		if (out.size() < precision) out.push_back(' ');
		if (out.size() > precision) out.pop_back();
	} while (out.size() != precision);

	return out;
}

void Matrix3f::print() {
	for (int i = 0; i < 3; i++) {
		std::cout << " | ";
		for (int j = 0; j < 3; j++) {
			std::cout << round(_entry[i][j], 4) << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << std::endl;
}

// Acessos
float Matrix3f::a() { return _entry[0][0]; }
float Matrix3f::b() { return _entry[0][1]; }
float Matrix3f::c() { return _entry[0][2]; }
float Matrix3f::d() { return _entry[1][0]; }
float Matrix3f::e() { return _entry[1][1]; }
float Matrix3f::f() { return _entry[1][2]; }
float Matrix3f::g() { return _entry[2][0]; }
float Matrix3f::h() { return _entry[2][1]; }
float Matrix3f::k() { return _entry[2][2]; }

// Operadores
float Matrix3f::operator()(int i, int j) { return _entry[i][j]; }

Matrix3f Matrix3f::operator=(Matrix3f &other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_entry[i][j] = other(i, j);
		}
	}

	return *this;
}

Matrix3f Matrix3f::operator+(Matrix3f &other) {
	Matrix3f aux;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			aux._entry[i][j] = _entry[i][j] + other(i, j);
		}
	}

	return aux;
}

Matrix3f Matrix3f::operator+=(Matrix3f &other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_entry[i][j] += other(i, j);
		}
	}

	return *this;
}

Matrix3f Matrix3f::operator-(Matrix3f &other) {
	Matrix3f aux;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			aux._entry[i][j] = _entry[i][j] - other(i, j);
		}
	}

	return aux;
}

Matrix3f Matrix3f::operator-=(Matrix3f &other) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			_entry[i][j] -= other(i, j);
		}
	}

	return *this;
}

Matrix3f Matrix3f::operator*(Matrix3f &other) {
	Matrix3f aux;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			float auxf = 0;
			for (int k = 0; k < 3; k++) {
				auxf += _entry[i][k] * other(k, j);
			}
			aux._entry[i][j] = auxf;
		}
	}

	return aux;
}

// Funções Matriciais
float Matrix3f::determinant() {
	float minor1 = _entry[2][0] * _entry[1][1] * _entry[0][2];
	float minor2 = _entry[0][0] * _entry[2][1] * _entry[1][2];
	float minor3 = _entry[1][0] * _entry[0][1] * _entry[2][2];

	float minor4 = _entry[0][0] * _entry[1][1] * _entry[2][2];
	float minor5 = _entry[1][0] * _entry[2][1] * _entry[0][2];
	float minor6 = _entry[2][0] * _entry[0][1] * _entry[1][2];

	float det = minor1 + minor2 + minor3 - minor4 - minor5 - minor6;

	return det;
}

Matrix3f Matrix3f::cofactor() {
	Matrix3f aux(1, -1, 1, -1, 1, -1, 1, -1, 1);
	
	aux = *this * aux;

	return aux;
}

Matrix3f Matrix3f::transpose() {
	Matrix3f aux;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			aux._entry[i][j] = _entry[j][i];
		}
	}

	return aux;
}

Matrix3f Matrix3f::adjunct() {
	Matrix3f original = *this;
	Matrix3f cofactor = original.cofactor();
	Matrix3f transpose = cofactor.transpose();
	Matrix3f aux = transpose;

	return aux;
}	

Matrix3f Matrix3f::inverse() {
	Matrix3f aux;
	float det = determinant();

	if (det != 0) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				aux._entry[i][j] = adjunct()(i, j) / det;
			}
		}
	}

	return aux;
}

// Transformação (ofVec2f)
ofVec2f Matrix3f::transform(const ofVec2f &vector, float z) const {
	ofVec2f aux; 
	float vec[3] = { vector.x, vector.y, z };

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			aux[i] += _entry[i][j] * vec[j];
		}
	}

	return ofVec2f(aux.x, aux.y);
}

// Métodos Estáticos
Matrix3f Matrix3f::rotation(float angle) {
	Matrix3f aux = Matrix3f(
		cos(ofDegToRad(angle)), sin(ofDegToRad(angle)), 0,
		-sin(ofDegToRad(angle)), cos(ofDegToRad(angle)), 0,
		0, 0, 1
	);
	
	return aux;
}

Matrix3f Matrix3f::translation(float dx, float dy) {
	Matrix3f aux = Matrix3f(
		1, 0, 0,
		0, 1, 0,
		dx, dy, 1
	);

	return aux;
}

Matrix3f Matrix3f::scale(float sx, float sy) {
	Matrix3f aux = Matrix3f(
		sx, 0, 0,
		0, sy, 0,
		0, 0, 1
	);

	return aux;
}