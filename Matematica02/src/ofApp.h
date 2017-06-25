#pragma once

#include "ofMain.h"
#include "conio.h"
#include "Matrix3f.h"
#include "Tank.h"

class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		bool tde = false;
		
		Tank tank;
		Matrix3f world;

		// Turnos:
		// 0 - P1 Giro do Canhão
		// 1 - P1 Giro do Tanque
		// 2 - P1 Movimento do Tanque
};
