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
    _locHistory.resize(20);
    _locHistory.push_back(_location);
}

void Bike::update(){
    // update direction
    updateDirection();

	// update position
    _location.x += _speed * cos(_direction);
	_location.y += _speed * sin(_direction);

    cout << _direction << endl;
    
    Util::crop(_location, _fieldSize);

    // update history
    _locHistory.push_back(_location);
    
}

void Util::crop(ofVec2f src, ofVec2f dest){
    if (src.x > dest.x) src.x = 0;
    if (src.x < 0)      src.x = dest.x;
    if (src.y > dest.y) src.y = 0;
    if (src.y < 0)      src.y = dest.y;
};

void Bike::updateDirection(){
	_direction += ofMap(_steer, -1.0, 1.0, -PI/2 *0.1, PI/2 * 0.1);
}

void Bike::draw(){
    ofPushStyle();

	ofSetColor(0);
    ofNoFill();
	ofCircle(_location.x, _location.y, 10);
    
    ofPopStyle();
    
    drawHistory();
}

void Bike::drawHistory(){
    ofPushStyle();
    ofSetColor(255, 0, 0);
    ofNoFill();
    
	list<ofVec2f>::iterator it = _locHistory.begin();
	while(it != _locHistory.end())
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


