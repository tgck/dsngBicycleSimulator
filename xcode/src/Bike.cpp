/*
 *  Bike.cpp
 *  emptyExample
 *
 *  Created by tani on 14/10/13.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */
#include "Bike.h"

Bike::Bike(){
}

void Bike::setup(){
	_speed = 1.0;
	_steer = 0.0;
	_direction = 0.0;
	_location = ofVec2f(ofGetWidth()/2, ofGetHeight()/2);
	_fieldSize = ofVec2f(winSize[0], winSize[1]);
    
    // history
    _locHist.resize(20);
    _locHist.clear();
    _locHist.push_back(_location);
}

void Bike::update(){
    // update direction
    updateDirection();

	// update position
    _location.x += _speed * cos(_direction);
	_location.y += _speed * sin(_direction);

    cout << _direction << endl;
    
    Util::crop(&_location, ofVec2f(-200, -100), ofVec2f(200, 100));
    cout << _fieldSize/2.0 << endl;
    
    // update history
    if (_locHist.size() > 20) {
        _locHist.pop_front();
        _locHist.push_back(_location);
    } else {
        _locHist.push_back(_location);
    }
}

//--------------------------------------------------------------
// crop
// 座標sを、端点p1, 端点p2から作られる領域でクロッピングします。
// 参照渡しによる、座標の更新を行います
//
void Util::crop(ofVec2f *s, ofVec2f p1, ofVec2f p2){
    if (s->x > p2.x) {s->x = p1.x; cout<<"croped! 1" << endl;}
    if (s->x < p1.x) {s->x = p2.x; cout<<"croped! 2" << endl;}
    if (s->y > p2.y) {s->y = p1.y; cout<<"croped! 3" << endl;}
    if (s->y < p1.y) {s->y = p2.y; cout<<"croped! 4" << endl;}
};
//--------------------------------------------------------------
// updateDirection
// 局所系であるハンドル角をもとに、directionの更新をおこないます
void Bike::updateDirection(){
	_direction += ofMap(_steer, -1.0, 1.0, -PI/2 *0.1, PI/2 * 0.1);
}
//--------------------------------------------------------------
//  描画系
//--------------------------------------------------------------

//
// draw()
// 自転車の描画を行います
//
void Bike::draw(){
    cout << "SIZE: "  << _locHist.size() << endl;
    
    ofPushStyle();

	ofSetColor(0);
    ofNoFill();
	ofCircle(_location.x, _location.y, 10);
    
    ofPopStyle();
    
    drawTrack();
}

//
// drawTrack()
// 自転車の軌跡の描画
//
void Bike::drawTrack(){
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofNoFill();
    
	list<ofVec2f>::iterator it = _locHist.begin();
	while(it != _locHist.end())
	{
        ofCircle((int)it->x, (int)it->y, 8);
		++it;  // イテレータを１つ進める
	}
	ofSetColor(0);
    ofNoFill();
	ofCircle(_location.x, _location.y, 10);
    
    ofPopStyle();
}

// setLocation
// 自転車の位置を変更します
void Bike::setLocation(ofVec2f loc){
    _location = loc;
}

// setHandle
// 自転車のハンドル向きを変更します
void Bike::setHandle(float st){
    _steer = st;
}

void Bike::report(){
    stringstream s;
    s   << " sp :" << ofToString(_speed)
        << " st :" << ofToString(_steer)
        << " dir:" << ofToString(_direction)
        << " px :" << ofToString(_location.x)
        << " py :" << ofToString(_location.y);
    cout << s.str() << endl;
}

void Bike::pedal(){
	_speed += 0.1;
}

void Bike::stop(){
	_speed = 0;
}

void Bike::handle(float normed){
	_steer += normed;
    
    // clipping
    _steer = ofClamp(_steer, -1.0, 1.0);
}


