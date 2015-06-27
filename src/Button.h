//
//  Button.h
//  VARVA
//
//  Created by Jacob Gonzalez on 25/06/2015.
//
//

#pragma once

#include "View.h"

class Button : public View
{
public:

    Button(ofPoint pos, ofPoint size)
        : View(pos, size), _circleRadius(0), _growRadius(false)
    {
        _color = ofColor(0x424242);
    }

    Button(int x, int y, int w, int h)
    : View(x, y, w, h), _growRadius(false)
    {
        _color = ofColor(0x424242);
    }

    ~Button()
    {}

    void update();
    void draw();

    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseMoved(int x, int y );
    void mouseLeft();

    ofColor getColor() const;
    void setColor(ofColor color);

    void setFont(ofTrueTypeFont &font);

private:
    ofColor _color;
    ofTrueTypeFont _font;

    // Material Design click
    ofPoint _clickPos;
    float _circleRadius;
    bool _growRadius;
};