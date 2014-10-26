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

        // bike and fields
        void setupSpaces();
        Bike bike;

        // app
        bool bAnimate;
        bool bFade;
    
        ofVec2f dispSize; // target display size
        void showDebug();
        void showGuide();

    
};

