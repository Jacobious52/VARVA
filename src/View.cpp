//
//  View.cpp
//  VARVA
//
//  Created by Jacob Gonzalez on 25/06/2015.
//
//

#include "View.h"

void View::setDelegate(IViewDelegate *delegate)
{
    _delegate = delegate;
}

ofRectangle View::getBounds() const
{
    return ofRectangle(_pos, _size.x, _size.y);
}

ofPoint View::getPos() const
{
    return _pos;
}

void View::setPos(ofPoint pos)
{
    _pos = pos;
}

ofPoint View::getSize() const
{
    return _size;
}

void View::setSize(ofPoint size)
{
    _size = size;
}

void View::setFont(ofTrueTypeFont &font)
{
    _font = font;
}