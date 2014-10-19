//
// ofApps.cpp から分岐
//

#include "ofApp.h"

//--------------------------------------------------------------
// setupSpaces
// 描画時に必要な、座標系の変換をおこないます
void ofApp::setupSpaces(){
    ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0, 0);
    ofRotate(-90);
    ofScale(1, 1);
}

//--------------------------------------------------------------
// showDebug
// デバッグ情報の表示

void ofApp::showDebug(){
    
    // メソッド内のローカルな計算
    Bike *b = &bike;
    float sp = b->_speed;
    float st = b->_steer;
    
    //
    // speed 0.  and steer -1.0 .. 1.0
    //
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
    
    
    ofPushStyle();
    
    ofSetColor(COLOR_DEBUGINFO);
    ofDrawBitmapString(s1.str(), 20, 20);
    ofDrawBitmapString(s2.str(), 20, 40);
    
    ofPopStyle();
}

//--------------------------------------------------------------
// 座標系を表現するガイドの表示
// X, Y軸の正方向を太線とする

void ofApp::showGuide(){
    
    float scale = 1000;
    
    ofPushStyle();
    
    ofSetColor(COLOR_GUIDE_X);
    ofSetLineWidth(1.0);   ofLine(-scale, 0, scale, 0);
    ofSetLineWidth(3.0);   ofLine(0, 0, scale, 0);
    
    ofSetColor(COLOR_GUIDE_Y);
    ofSetLineWidth(1.0);   ofLine(0, -scale, 0, scale);
    ofSetLineWidth(3.0);   ofLine(0, 0, 0, scale);
    
    ofPopStyle();
}
