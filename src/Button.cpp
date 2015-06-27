//
//  Button.cpp
//  VARVA
//
//  Created by Jacob Gonzalez on 25/06/2015.
//
//

#include "Button.h"

void Button::update()
{
    if (_growRadius)
    {
        _circleRadius = ofLerp(_circleRadius, MAX(_size.x, _size.y), 0.25);
    }
    else
    {
        _circleRadius = ofLerp(_circleRadius, 0, 0.5);
    }
}

void Button::draw()
{
    ofSetColor(_color);
    ofRect(_pos, _size.x, _size.y);

    // Material Design
    if (_circleRadius > 0)
    {
        glScissor(_pos.x, ofGetHeight() - _pos.y - _size.y, _size.x, _size.y);
        glEnable(GL_SCISSOR_TEST);

        ofSetColor(ofColor(0x525252));
        ofCircle(_clickPos, _circleRadius);

        glDisable(GL_SCISSOR_TEST);
    }

    ofSetColor(255);
    int sizeX = _font.stringWidth(name);
    int sizeY = _font.stringHeight(name);
    _font.drawString(name, _pos.x + _size.x/2 - sizeX/2, _pos.y + _size.y/2 + sizeY/2 - 2);
}

void Button::setFont(ofTrueTypeFont &font)
{
    _font = font;
}

void Button::mousePressed(int x, int y, int button)
{
    _growRadius = true;
    _clickPos = ofPoint(x, y);
}

void Button::mouseReleased(int x, int y, int button)
{
    _growRadius = false;

    if (_delegate != 0)
    {
        _delegate->viewClicked(name, this);
    }
}

void Button::mouseDragged(int x, int y, int button)
{
    _clickPos = ofPoint(x, y);
}

void Button::mouseMoved(int x, int y )
{
    _color = _color.lerp(ofColor(0x323232), 0.25);
}

void Button::mouseLeft()
{
    if (_growRadius)
    {
        _growRadius = false;
    }

    _color = ofColor(0x424242);
}

ofColor Button::getColor() const
{
    return _color;
}

void Button::setColor(ofColor color)
{
    _color = color;
}