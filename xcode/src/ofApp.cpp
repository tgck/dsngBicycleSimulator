
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	cerr << "dsngKevOfx: controls Finder pointer with key event." << endl;
    ofSetFrameRate(30);
    ofSetBackgroundAuto(false); // haikei clear wo OFF
    
    bAnimate = true;
    bFade = true;
    
    bike.setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    if (bAnimate) bike.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    if (bFade) {
        ofSetColor(128, 60);  // clear with alpha
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
    } else {
        ofSetColor(128);
        ofRect(0, 0, ofGetWidth(), ofGetHeight());
    }

    // 座標系の変換
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0, 0);
    ofScale(1, -1);
    ofRotate(90);
    
	bike.report();
	bike.draw();

    ofPopMatrix();
    
    showDebug();
}

void ofApp::showDebug(){
    // 表示用の計算
    
    Bike *b = &bike;
    float sp = b->_speed;
    float st = b->_steer;
    
    // speed 0.
    // and steer -1.0 .. 1.0
    stringstream s1, s2;
    for (int i = 0 ; i < 10; i++){
        s1 << (sp * 10 > i ? '*' : '-') ;
    }
    s1 << " .. "  << ofToString(sp, 2) << endl;
    
    int stRounded = round( ofMap(st, -1, 1, 0, 10) );
    for (int i = 0 ; i < 10; i++){
        s2 << (stRounded == i ? '|' : '-') ;
    }
    s2 << " .. "  << ofToString(st, 2) << endl;
    
    
    // 表示
    ofPushStyle();
    ofSetColor(0);
    ofDrawBitmapString(s1.str(), 20, 20);
    ofDrawBitmapString(s2.str(), 20, 40);
    ofPopStyle();
}

//--------------------------------------------------------------
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
	fprintf(stdout, "---- key released [%d]\n", key);
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
