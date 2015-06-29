#pragma once

#include "ofMain.h"
#include "VarManager.h"
#include "Button.h"
#include "Graph.h"

class ofApp : public ofBaseApp, IViewDelegate
{
public:
    void setup();
    void exit();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    // IViewDelegate
    void viewClicked(string name, View *sender);

    map<string, View *> views;
    void addView(View *view);

    ofTrueTypeFont uiFont;
    ofTrueTypeFont uiFontLarge;

    bool loaded;
    float dragRadius;

    float toolbarOffset;

    float graphsOffset;
};
