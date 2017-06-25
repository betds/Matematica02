#include "ofApp.h"

void next() {
	system("pause");
	system("cls");
	std::cout << "[ Matematica para Jogos II - TDE ]" << std::endl << std::endl;
}

//--------------------------------------------------------------
void ofApp::setup() {
	if (tde) {
		std::cout << "[ Matematica para Jogos II - TDE ]" << std::endl << std::endl;

		// Construtor padrão (deve criar uma matriz identidade)
		std::cout << "- Construtor Padrao" << std::endl << std::endl;
		
		std::cout << "  I" << std::endl; 
		Matrix3f identidade = Matrix3f();
		identidade.print();
		
		next();

		// Construtor com os 9 floats iniciais
		std::cout << "- Construtor com os 9 floats iniciais" << std::endl << std::endl;
		
		std::cout << "  F" << std::endl; 
		Matrix3f floats = Matrix3f(ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9));
		floats.print();
		
		next();

		// Construtor de cópia
		std::cout << "- Construtor de Copia" << std::endl << std::endl;
		
		std::cout << "  F" << std::endl;
		floats.print();
		
		Matrix3f copiaDeFloats = Matrix3f(floats);
		std::cout << "  CF" << std::endl; 
		copiaDeFloats.print();
		
		next();

		// Cópia de matriz: operador =
		std::cout << "- Copia de Matriz com operador =" << std::endl << std::endl;
		
		std::cout << "  F" << std::endl;
		floats.print();
		
		Matrix3f igual = floats;
		std::cout << "  OI = F" << std::endl;
		igual.print();
		
		next();

		// Operadores
		Matrix3f matA = Matrix3f(ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9));
		Matrix3f matB = Matrix3f(ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9), ofRandom(9));

		// [OPCIONAL] Soma de matrizes: operador +
		std::cout << "- Operadores: Soma de Matrizes com operador +" << std::endl << std::endl;
		
		std::cout << "  A" << std::endl;
		matA.print();
		
		std::cout << "  B" << std::endl;
		matB.print();
		
		Matrix3f soma = matA + matB;
		std::cout << "  A + B" << std::endl;
		soma.print();
		
		next();

		// [OPCIONAL] Soma de matrizes: operador +=
		std::cout << "- Operadores: Soma de Matrizes com operador +=" << std::endl << std::endl;
		
		std::cout << "  A" << std::endl;
		matA.print();

		std::cout << "  B" << std::endl;
		matB.print();

		matB += matA;
		std::cout << "  B += A" << std::endl;
		matB.print();

		next();

		// [OPCIONAL] Subtração de matrizes: operador -
		std::cout << "- Operadores: Subtracao de Matrizes com operador -" << std::endl << std::endl;
		
		std::cout << "  A" << std::endl;
		matA.print();

		std::cout << "  B" << std::endl;
		matB.print();

		Matrix3f subtracao = matB - matA;
		std::cout << "  B - A" << std::endl; 
		subtracao.print();

		next();

		// [OPCIONAL] Subtração de matrizes: operador -=
		std::cout << "- Operadores: Subtracao de Matrizes com operador -=" << std::endl << std::endl;
		
		std::cout << "  A" << std::endl;
		matA.print();

		std::cout << "  B" << std::endl;
		matB.print();

		matB -= matA;
		std::cout << "  B -= A" << std::endl;
		matB.print();

		next();

		// Multiplicação de matrizes: operador *
		std::cout << "- Operadores: Multiplicacao de Matrizes com operador *" << std::endl << std::endl;

		std::cout << "  A" << std::endl;
		matA.print();

		std::cout << "  B" << std::endl;
		matB.print();

		Matrix3f multiplicacao = matA * matB;
		std::cout << "  A * B" << std::endl; 
		multiplicacao.print();
		next();

		// Cálculo do Determinante
		std::cout << "- Calculo do Determinante" << std::endl << std::endl;
		
		std::cout << "  A" << std::endl;
		matA.print(); 
		
		std::cout << "  det(A) = " << matA.determinant() << std::endl << std::endl;

		next();

		// Cálculo da Inversa
		std::cout << "- Calculo da Matriz Inversa" << std::endl << std::endl;
		
		std::cout << "  A" << std::endl;
		matA.print();

		Matrix3f inversa = matA.inverse();
		std::cout << "  A(-1)" << std::endl;
		inversa.print();

		next();

		// Cálculo da Transposta
		std::cout << "- Calculo da Matriz Transposta" << std::endl << std::endl;

		std::cout << "  A" << std::endl;
		matA.print();

		Matrix3f transposta = matA.transpose();
		std::cout << "  At" << std::endl;
		transposta.print();

		next();

		// [OPCIONAL] Acesso aos elementos da matriz pelo operador ()
		string opa, opb, opc, opd, ope, opf, opg, oph, opk;
		opa = floats.round(floats(0, 0), 4);
		opb = floats.round(floats(0, 1), 4);
		opc = floats.round(floats(0, 2), 4);
		opd = floats.round(floats(1, 0), 4);
		ope = floats.round(floats(1, 1), 4);
		opf = floats.round(floats(1, 2), 4);
		opg = floats.round(floats(2, 0), 4);
		oph = floats.round(floats(2, 1), 4);
		opk = floats.round(floats(2, 2), 4);

		std::cout << "- Acesso aos elementos da matriz pelo operador (): " << std::endl << std::endl;

		std::cout << "  F" << std::endl;
		std::cout << "  [ " << opa << " " << opb << " " << opc << " ]" << std::endl;
		std::cout << "  [ " << opd << " " << ope << " " << opf << " ]" << std::endl;
		std::cout << "  [ " << opg << " " << oph << " " << opk << " ]" << std::endl;
		std::cout << std::endl;

		next();

		// [OPCIONAL]
		// Acesso aos elementos pelos métodos a(), b(), c(), d(), e(), f(), g(), h() e k() no formato:
		// [a b c]
		// [d e f]
		// [g h k]
		string mta, mtb, mtc, mtd, mte, mtf, mtg, mth, mtk;
		mta = floats.round(floats(0, 0), 4);
		mtb = floats.round(floats(0, 1), 4);
		mtc = floats.round(floats(0, 2), 4);
		mtd = floats.round(floats(1, 0), 4);
		mte = floats.round(floats(1, 1), 4);
		mtf = floats.round(floats(1, 2), 4);
		mtg = floats.round(floats(2, 0), 4);
		mth = floats.round(floats(2, 1), 4);
		mtk = floats.round(floats(2, 2), 4);

		std::cout << "- Acesso aos elementos pelos metodos a(), b(), c(), d(), e(), f(), g(), h() e k(): " << std::endl << std::endl;

		std::cout << "  F" << std::endl;
		std::cout << "  [ " << mta << " " << mtb << " " << mtc << " ]" << std::endl;
		std::cout << "  [ " << mtd << " " << mte << " " << mtf << " ]" << std::endl;
		std::cout << "  [ " << mtg << " " << mth << " " << mtk << " ]" << std::endl;
		std::cout << std::endl;

		next();

		// Transformação de um ofVec2f pela matriz (multiplicação de vetor pela matriz)
		std::cout << "- Transformaca de um ofVec2f pela Matriz" << std::endl << std::endl;
		
		ofVec2f vetor = ofVec2f(ofRandom(2), ofRandom(2));
		std::cout << "  vetor(" << vetor.x << ", " << vetor.y << ")" << std::endl  << std::endl;

		ofVec2f transformacao = Matrix3f(1, 0, 0, 0, 1, 0, 0, 0, 0).transform(vetor, 1);
		std::cout << "  transformacao(" << vetor.x << ", " << vetor.y << ")" << std::endl << std::endl;

		next();

		// Métodos Fábrica Estáticos (Rotação, Translação e Escala)
		std::cout << "- Metodos Fabrica Estaticos" << std::endl << std::endl;
		
		Matrix3f modelo = Matrix3f(); 
		std::cout << "- Modelo" << std::endl;
		modelo.print();

		std::cout << "- Rotacao (45)" << std::endl;
		modelo.rotate(45).print();

		std::cout << "- Translacao (10, 10)" << std::endl;
		modelo.translate(10, 10).print();

		std::cout << "- Escala (2x, 2x)" << std::endl;
		modelo.scale(2, 2).print();

		next();
	}

	world = Matrix3f();
	tank._position = ofVec2f(ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);

	/*
	tank[1]._position = ofVec2f(ofGetWindowWidth() - 25, ofRandom(25, ofGetWindowHeight() - 25));
	tank[1]._color = ofColor(0, 0, 200);
	*/
}

//--------------------------------------------------------------
void ofApp::update() {
	
}

//--------------------------------------------------------------
void ofApp::draw() {
	tank.Draw(world);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == OF_KEY_LEFT) {
		tank._angle--;
	}

	if (key == OF_KEY_RIGHT) {
		tank._angle++;
	}
	
	// Pegar o input do Player para ver a velocidade que o tank vai andar
	int velocityType;
	if(key == '1'){
		velocityType = 1;
	}
	if(key == '2'){
		velocityType = 2;
	}
	if(key == '3'){
		velocityType = 3;
	}
	tank.PlayerInput(velocityType);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
