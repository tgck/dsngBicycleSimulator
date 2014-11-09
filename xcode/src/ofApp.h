#pragma once

#include "ofMain.h"
#include "appConst.h"
#include "Bike.h"
#include "FinderItem.h"

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

    
        // - - - - app - - - - //

        // bike and fields
        Bike bike;
    
        // target display size
        ofVec2f dispSize;
    
        // Finder Items
        vector<FinderItem> items;
    
        bool bAnimate;
        bool bFade;

        void showDebug();
        void showGuide();
        void setupSpaces();
    
private:
        ofBuffer tBuf;
        void setupFinderItems();
        void tBuf2Items();
};


namespace Util{
    void crop(ofVec2f* src, ofVec2f corner1, ofVec2f corner2);
};