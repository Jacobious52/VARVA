#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackgroundHex(0x212121);
    ofSetFrameRate(30);
    ofSetEscapeQuitsApp(false);
    ofSetWindowTitle("VARVA");

    ofTrueTypeFont::setGlobalDpi(72);

    ofSetCircleResolution(72);

    uiFont.loadFont("Roboto-Regular.ttf", 18);

    Button *quitButton = new Button(20, 20, 100, 25);
    quitButton->name = "Quit";
    quitButton->setFont(uiFont);
    quitButton->depth = 2;
    quitButton->setDelegate(this);
    views.push_back(quitButton);

    Button *testButton = new Button(200, 20, 300, 500);
    testButton->name = "Test";
    testButton->setFont(uiFont);
    testButton->depth = 6;
    testButton->setDelegate(this);
    views.push_back(testButton);

    VarManager::shared_manager().load_varibles("/Users/Jacob/Developer/of_v0.8.4_osx_release/apps/myApps/VARVA/debuggers/");
}

void ofApp::exit()
{
    for (auto view : views)
    {
        if (view != 0)
        {
            delete view;
            view--;
        }
    }
}

void ofApp::viewClicked(string name, View *sender)
{
    ofLog(OF_LOG_NOTICE, name);

    if (name == "Quit")
    {
        ofExit();
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (auto view : views)
    {
        view->update();
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (auto view : views)
    {
        view->draw();
    }

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
    for (auto view : views)
    {
        if (view->getBounds().inside(x, y))
        {
            view->mouseMoved(x, y);
        }
        else
        {
            view->mouseLeft();
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    for (auto view : views)
    {
        if (view->getBounds().inside(x, y))
        {
            view->mouseDragged(x, y, button);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    for (auto view : views)
    {
        if (view->getBounds().inside(x, y))
        {
            view->mousePressed(x, y, button);
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    for (auto view : views)
    {
        if (view->getBounds().inside(x, y))
        {
            view->mouseReleased(x, y, button);
        }
    }
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
