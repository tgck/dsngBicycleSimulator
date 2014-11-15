#pragma once

#include "ofMain.h"
#include "appConst.h"
#include "Bike.h"
#include "Desktop.h"
#include "FinderItem.h"

#include "ofxOsc.h"

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
        Desktop desktop;

        // Finder Items
        vector<FinderItem> items;
    
        bool bAnimate;
        bool bFade;
        bool bSendMode;
        bool bNeedSending;  // 送信メッセージあり
    
        void showDebug();
        void showGuide();
        void setupSpaces();
    
        // - - - - osc - - - - //
        ofxOscSender senders[3];
        void setupSender(bool); // bool で起動要否を切替
        void updateSender();
        void send(); // メッセージ送信
    
private:
        ofBuffer tBuf;
        void setupFinderItems();
        void tBuf2Items();

        // メッセージ送信
        float _prevSendTime;    // 前回メッセージ送信時刻(ミリ秒);
};


namespace Util{
    void crop(ofVec2f* src, const ofVec2f corner1, const ofVec2f corner2);
};