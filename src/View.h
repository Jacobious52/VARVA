//
//  View.h
//  VARVA
//
//  Created by Jacob Gonzalez on 25/06/2015.
//
//

#pragma once

#include "ofMain.h"

class View;

class IViewDelegate
{
public:
    virtual void viewClicked(string name, View *sender) = 0;
};

class View
{
public:
    View(ofPoint pos, ofPoint size)
        : _pos(pos), _size(size), name(""), hidden(false)
    {
        _delegate = 0;
    }

    View(int x, int y, int w, int h)
    : _pos(x, y), _size(w, h), name(""), hidden(false)
    {
        _delegate = 0;
    }

    virtual ~View()
    {
        _delegate = 0;
    }

    virtual void update() = 0;
    virtual void draw() = 0;

    virtual void mousePressed(int x, int y, int button) = 0;
    virtual void mouseReleased(int x, int y, int button) = 0;
    virtual void mouseDragged(int x, int y, int button) = 0;
    virtual void mouseMoved(int x, int y ) = 0;
    virtual void mouseLeft() = 0;

    ofPoint getPos() const;
    void setPos(ofPoint pos);

    ofPoint getSize() const;
    void setSize(ofPoint size);

    ofRectangle getBounds() const;

    void setDelegate(IViewDelegate *delegate);

    void setFont(ofTrueTypeFont &font);

    string name;

    bool hidden;

protected:
    ofPoint _pos;
    ofPoint _size;

    ofTrueTypeFont _font;

    IViewDelegate *_delegate;
};