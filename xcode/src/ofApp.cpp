
#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    
    // Window Title for help
    ofSetWindowTitle(ofToString(winSize[0]) +  " " +  ofToString(winSize[1]));
    
    bAnimate = true;
    bFade = true;

    desktop.setup(ofVec2f(1400, 900)); // デスクトップの解像度を入れる
    
    bike.setup();
    bike.setupCropSettings(desktop.getCornerBegin(), desktop.getCornerEnd());
    
    setupFinderItems();
    
//    setupSender(false);
    setupSender(true);
}

//--------------------------------------------------------------
void ofApp::update(){

    // モデルの更新
    if (bAnimate) bike.update();
    
    // 通信
    updateSender(); // フラグの考慮は先方でやってくれる
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofPushMatrix();

    setupSpaces(); // 座標系
    showGuide(); // ガイド

    // Field
    desktop.draw();
    
    // FinderItems
    ofPushStyle();
    ofSetColor(188);
    for (int i=0; i<items.size(); i++){
        items[i].draw();
        items[i].drawInfo();
    }
    ofPopStyle();
    
    // Bike
	bike.report();
	bike.draw();

    ofPopMatrix();
    
    showDebug();

    // debug
    ofSetWindowTitle(ofToString(ofGetElapsedTimeMillis()));
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
        case 'a': // 原点から再開
            bike.setLocation(ofVec2f(0, 0));
            bike.resetHandle();
            break;
        case '1': // ハンドル角のみ初期化
            bike.resetHandle();
            break;
        case '/': // テスト送信実行
            bNeedSending = true;
            cout << "OSC Sending Toggled to [" << bNeedSending << "]" << endl;
            break;
        default:
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
