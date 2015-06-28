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
    uiFontLarge.loadFont("Roboto-Bold.ttf", 24);

    Button *quitButton = new Button(20, 20, 100, 25);
    quitButton->name = "Quit";
    quitButton->setFont(uiFont);
    quitButton->depth = 2;
    quitButton->setDelegate(this);
    addView(quitButton);

    Button *unloadButton = new Button(140, 20, 100, 25);
    unloadButton->name = "Unload";
    unloadButton->setFont(uiFont);
    unloadButton->depth = 6;
    unloadButton->hidden = true;
    unloadButton->setDelegate(this);
    addView(unloadButton);

    loaded = false;
    dragRadius = 200;
}

void ofApp::exit()
{
    for (auto view : views)
    {
        if (view.second != 0)
        {
            delete view.second;
        }
    }

    views.clear();
}

void ofApp::addView(View *view)
{
    views[view->name] = view;
}

void ofApp::viewClicked(string name, View *sender)
{
    ofLog(OF_LOG_NOTICE, name);

    if (name == "Quit")
    {
        ofExit();
    }
    else if (name == "Unload")
    {
        VarManager::shared_manager().unload();
        loaded = false;
        sender->hidden = true;
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
    for (auto view : views)
    {
        view.second->update();
    }

    if (!loaded)
    {
        dragRadius = 50*sin(ofGetElapsedTimef()/2*M_PI) + 200;
    }
}

//--------------------------------------------------------------
void ofApp::draw()
{
    for (auto view : views)
    {
        if (!view.second->hidden)
        {
            view.second->draw();
        }
    }

    if (loaded)
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
    else
    {
        // draw drag n drop circle

        ofSetHexColor(0x121212);
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, dragRadius);
        string dragMsg = "Drag Debug Folder";
        float sx = uiFontLarge.stringWidth(dragMsg);
        ofSetColor(255);
        uiFontLarge.drawString(dragMsg, ofGetWidth()/2 - sx/2, ofGetHeight()/2);
    }
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
        if (!view.second->hidden)
        {
            if (view.second->getBounds().inside(x, y))
            {
                view.second->mouseMoved(x, y);
            }
            else
            {
                view.second->mouseLeft();
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
    for (auto view : views)
    {
        if (!view.second->hidden)
        {
            if (view.second->getBounds().inside(x, y))
            {
                view.second->mouseDragged(x, y, button);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
    for (auto view : views)
    {
        if (!view.second->hidden)
        {
            if (view.second->getBounds().inside(x, y))
            {
                view.second->mousePressed(x, y, button);
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
    for (auto view : views)
    {
        if (!view.second->hidden)
        {
            if (view.second->getBounds().inside(x, y))
            {
                view.second->mouseReleased(x, y, button);
            }
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
    // TODO: check if folder of file
    VarManager::shared_manager().load_varibles("/Users/Jacob/Developer/of_v0.8.4_osx_release/apps/myApps/VARVA/debuggers/");
    loaded = true;
    views.find("Unload")->second->hidden = false;
}
