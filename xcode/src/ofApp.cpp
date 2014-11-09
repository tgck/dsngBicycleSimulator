
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    
    // Window Title for help
    ofSetWindowTitle(ofToString(winSize[0]) +  " " +  ofToString(winSize[1]));
    
    bAnimate = true;
    bFade = true;
    
    bike.setup();
    setupFinderItems();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (bAnimate) bike.update();
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();
    
    setupSpaces(); // 座標系
    showGuide(); // ガイド

	bike.report();
	bike.draw();

    ofPopMatrix();
    
    showDebug();
}


//--------------------------------------------------------------
//
void ofApp::keyPressed(int key){
	fprintf(stdout, "key pressed [%d]\n", key);
    switch (key) {
        case OF_KEY_UP:
            bike.pedal();
            break;
        case OF_KEY_DOWN:
            bike.stop();
            break;
        case OF_KEY_LEFT:
            bike.handle(-0.1);
            break;
        case OF_KEY_RIGHT:
            bike.handle(+0.1);
            break;
        case ' ':
            bAnimate = !bAnimate;
            break;
        case 'a':
            bike.setLocation(ofVec2f(0, 0));
            bike.setHandle(0);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
