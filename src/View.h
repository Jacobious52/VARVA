//
//  View.h
//  VARVA
//
//  Created by Jacob Gonzalez on 25/06/2015.
//
//

#pragma once

#include "ofMain.h"

class View
{
public:
    View(ofVec2f pos, ofVec2f size)
        : _pos(pos), _size(size)
    {}
    virtual ~View()
    {}

    virtual void update() = 0;
    virtual void draw() = 0;

    void (*mousePressed)(int x, int y, int button);

    ofVec2f getPos() const;
    void setPos(ofVec2f pos);

    ofVec2f getSize() const;
    void setSize(ofVec2f size);

private:
    ofVec2f _pos;
    ofVec2f _size;
};