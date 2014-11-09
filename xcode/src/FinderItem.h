//
//  FinderItem.h
//  mySketch
//
//  Created by tani on 11/9/14.
//
//
#pragma once
#include <iostream>
#include "ofMain.h"
#include "appConst.h"

#define ITEM_SIZE_R 10 // drawing size

class FinderItem {
    
public:
    ofVec2f _p;
    
    FinderItem(const ofVec2f);
    void setup();
    void update();
    void draw();
    
private:

};
