//
//  Desktop.h
//  mySketch
//
//  Created by tani on 11/9/14.
//
//
#pragma once
#include <iostream>
#include "ofMain.h"
#include "appConst.h"

class Desktop {
    
public:
    ofVec2f _size;
    ofVec2f _p;
    
    //Desktop(const ofVec2f _size); // no use
    void setup(const ofVec2f _size);
    void update();
    void draw();
    
    ofVec2f getCornerBegin();
    ofVec2f getCornerEnd();
    
private:
    
};
