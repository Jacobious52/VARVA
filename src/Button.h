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

    Button(ofVec2f pos, ofVec2f size)
        : View(pos, size)
    {}

    ~Button()
    {}

    void update();
    void draw();
};