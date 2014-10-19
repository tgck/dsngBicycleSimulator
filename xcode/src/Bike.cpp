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
	_dispSize = ofVec2f(200, 200);
}

void Bike::update(){
    updateDirection();
	_location.x += _speed * cos(_direction);
	_location.y += _speed * sin(_direction);
	
	// wrap
	if ( _location.x > _dispSize.x )
		_location.x = 0;
	if ( _location.x < 0 )
		_location.x = _dispSize.x;
	if ( _location.y > _dispSize.y )
		_location.y = 0;
	if ( _location.y < 0 )
		_location.y = _dispSize.y;
}

void Bike::updateDirection(){
	_direction += ofMap(_steer, -1.0, 1.0, -PI/2 *0.1, PI/2 * 0.1);
}

void Bike::draw(){
    ofPushStyle();

	ofSetColor(0);
    ofNoFill();
	ofCircle(_location.x, _location.y, 10);
    
    ofPopStyle();
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


