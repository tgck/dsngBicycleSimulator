#pragma once

#include "ofMain.h"
#include "appConst.h"
#include "Bike.h"

class ofApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

    
        void setupSpaces();
        void showDebug();
        void showGuide();
    
        bool bAnimate;
        bool bFade;
    
        Bike bike;
        ofVec2f dispSize; // target display size
    
};

