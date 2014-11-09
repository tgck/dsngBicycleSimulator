//
//  Desktop.cpp
//  mySketch
//
//  Created by tani on 11/9/14.
//
//

#include "Desktop.h"

//--------------------------------------------------------------
//
//
//Desktop::Desktop(const ofVec2f size){
//    _size = size;
//    
//    // 描画開始座標の設定
//    _p.x = -1 * _size.x / 2;
//    _p.y = -1 * _size.y / 2;
//}

//--------------------------------------------------------------
//
//
void Desktop::setup(const ofVec2f size) {
    _size = size;
    
    // 描画開始座標の設定
    _p.x = -1 * _size.x / 2;
    _p.y = -1 * _size.y / 2;
}

//--------------------------------------------------------------
// update
//[design] No any update.
//
void Desktop::update() {
    
}
//--------------------------------------------------------------
// draw
//
//
void Desktop::draw() {
    ofPushStyle();
    
    ofNoFill();
//    glLineWidth(1);
    ofSetColor(0, 188, 0);
    ofRect(_p.x, _p.y, _size.x, _size.y);
    
    ofPopStyle();
}

//--------------------------------------------------------------
// getCornerBegin
//
//
ofVec2f Desktop::getCornerBegin(){
    return ofVec2f(_p.x, _p.y);
}

//--------------------------------------------------------------
// getCornerEnd
//
//
ofVec2f Desktop::getCornerEnd(){
    return ofVec2f(_p.x + _size.x, _p.y + _size.y);
}


