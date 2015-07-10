//
//  Graph.cpp
//  VARVA
//
//  Created by Jacob Gonzalez on 28/06/2015.
//
//

#include "Graph.h"

void Graph::update()
{

}

float varMax(vector<Variable> points)
{
    float max = points[0].var_value;
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i].var_value > max)
        {
            max = points[i].var_value;
        }
    }
    ofLog(OF_LOG_NOTICE, "max = " + ofToString(max));
    return max;
}

float varMin(vector<Variable> points)
{
    float min = points[0].var_value;
    for (int i = 1; i < points.size(); i++)
    {
        if (points[i].var_value < min)
        {
            min = points[i].var_value;
        }
    }
    ofLog(OF_LOG_NOTICE, "min = " + ofToString(min));
    return min;
}

void Graph::draw()
{
    ofSetColor(100);
    ofRect(_pos, _size.x, _size.y);

    float spacingX = _size.x/_points.size();
    float spacingY = abs(_size.y / ( varMax(_points) - varMin(_points) )) * 0.8;
    float offsetY = spacingY + 20;

    // X axis
    ofSetColor(ofColor::blue);
    ofLine(_pos.x, _pos.y + _size.y - 20, _pos.x + _size.x, _pos.y + _size.y - 20);
    // Y axis
    ofLine(_pos.x + 10, _pos.y, _pos.x + 10, _pos.y + _size.y);

    ofPolyline line;
    line.addVertex(_pos.x + 20, _pos.y + _size.y - _points[0].var_value*spacingY - offsetY);
    for (int i = 0; i < _points.size(); i++)
    {
        Variable v = _points[i];
        ofPoint ppos(_pos.x + i*spacingX + 20, _pos.y + _size.y - v.var_value*spacingY - offsetY);

        float radius = MAX(5, spacingX*0.25);

        ofSetColor(ofColor::red);
        ofCircle(ppos.x, ppos.y, radius);
        line.curveTo(_pos.x + i*spacingX + 20, _pos.y + _size.y - v.var_value*spacingY - offsetY);

    }

    ofSetColor(ofColor::lightGray);
    line.draw();

    ofSetColor(255);
    _font.drawString(name.substr(6, name.size()), _pos.x + 20, _pos.y + 20);

    for (int i = 0; i < _points.size(); i++)
    {
        Variable v = _points[i];
        ofPoint ppos(_pos.x + i*spacingX + 20, _pos.y + _size.y - v.var_value*spacingY - offsetY);

        float radius = MAX(5, spacingX*0.25);


        if (ofRectangle(ppos.x - radius, ppos.y - radius, radius*2,
                        radius*2).inside(ofGetMouseX(), ofGetMouseY()))
        {
            ofSetHexColor(0x424242);
            ofRect(ofGetMouseX(), ofGetMouseY(), 300, 110);
            ofSetColor(255);
            _font.drawString(v.note, ofGetMouseX() + 10, ofGetMouseY() + 20);
            _font.drawString("Value: " + ofToString(v.var_value), ofGetMouseX() + 10, ofGetMouseY() + 40);
            _font.drawString("Class: " + v.class_name, ofGetMouseX() + 10, ofGetMouseY() + 60);
            _font.drawString("Func: " + v.func_name, ofGetMouseX() + 10, ofGetMouseY() + 80);
            _font.drawString("Line: " + v.line, ofGetMouseX() + 10, ofGetMouseY() + 100);
        }
    }
}

void Graph::setFont(ofTrueTypeFont &font)
{
    _font = font;
}

void Graph::mousePressed(int x, int y, int button)
{

}

void Graph::mouseReleased(int x, int y, int button)
{

}

void Graph::mouseDragged(int x, int y, int button)
{

}

void Graph::mouseMoved(int x, int y )
{

}

void Graph::mouseLeft()
{
}