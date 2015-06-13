#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    VarManager::shared_manager().load_varibles("/Users/Jacob/Developer/of_v0.8.4_osx_release/apps/myApps/VARVA/debuggers/");
}

//--------------------------------------------------------------
void ofApp::update()
{

}

//--------------------------------------------------------------
void ofApp::draw()
{
    vector<Variable> vars = VarManager::shared_manager()["i"];

    ofPolyline line;

    for (int i = 0; i < vars.size(); i++)
    {
        Variable v = vars[i];
        ofSetColor(ofColor::red);
        ofCircle(i*30 + 100, ofGetHeight() - v.var_value*30 - 100, 3);
        line.curveTo(i*30 + 100, ofGetHeight() - v.var_value*30 - 100, 3);
    }

    line.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{

}
