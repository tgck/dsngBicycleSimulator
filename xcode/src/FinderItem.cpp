//
//  FinderItems.cpp
//  mySketch
//
//  Created by tani on 11/9/14.
//
//

#include "FinderItem.h"

//--------------------------------------------------------------
//
//
FinderItem::FinderItem(const ofVec2f point){
    _p = point;
}

//--------------------------------------------------------------
//
//
void FinderItem::setup() {
    
}

//--------------------------------------------------------------
// update
//[design] No any update.
//
void FinderItem::update() {

}
//--------------------------------------------------------------
// draw
//[design] No any update.
//
void FinderItem::draw() {
    
    ofCircle(_p.x, _p.y, ITEM_SIZE_R);
    
}