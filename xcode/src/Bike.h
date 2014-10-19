/*
 *  Bike.h
 *  emptyExample
 *
 *  Created by tani on 14/10/13.
 *  Copyright 2014 __MyCompanyName__. All rights reserved.
 *
 */
#pragma once
#include <iostream>
#include "ofMain.h"
#include "appConst.h"

class Bike {
private:
	
public:
	float _speed;
	float _steer;
	float _direction; //  as radian
	ofVec2f _location; // is this here or other Class?
	ofVec2f _fieldSize; // is this here or other Class?
	list<ofVec2f> _locHistory;
    
    Bike();
	
	void setup();
	void update();
	void updateDirection();
	void draw(); // for self drawing on oF App
    void drawHistory(); // for self drawing on oF App
	void report(); // report position in stdout
	
	void pedal();
	void stop();
	void handle(float normed);
    
    // debug
    void setLocation(ofVec2f loc);
    void setHandle(float st);
};

namespace Util{
    void crop(ofVec2f src, ofVec2f dest);
};