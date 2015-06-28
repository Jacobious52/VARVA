//
//  Graph.h
//  VARVA
//
//  Created by Jacob Gonzalez on 28/06/2015.
//
//

#pragma once

#include "View.h"
#include "Variable.h"

class Graph : public View
{
public:
    Graph(vector<Variable> &points, int x, int y, int w, int h)
    : View(x, y, w, h), _points(points)
    {}

    ~Graph()
    {}

    void update();
    void draw();

    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseDragged(int x, int y, int button);
    void mouseMoved(int x, int y );
    void mouseLeft();

    void setFont(ofTrueTypeFont &font);

private:
    ofTrueTypeFont _font;

    vector<Variable> _points;
};
