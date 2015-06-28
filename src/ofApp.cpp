#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackgroundHex(0x111111);
    ofSetFrameRate(30);
    ofSetEscapeQuitsApp(false);
    ofSetWindowTitle("VARVA");

    ofTrueTypeFont::setGlobalDpi(72);

    ofSetCircleResolution(72);
    ofEnableAntiAliasing();

    uiFont.loadFont("Roboto-Regular.ttf", 18);
    uiFontLarge.loadFont("Roboto-Bold.ttf", 24);

    Button *quitButton = new Button(20, 20, 200, 50);
    quitButton->name = "Quit";
    quitButton->setFont(uiFont);
    quitButton->setDelegate(this);
    addView(quitButton);

    Button *unloadButton = new Button(240, 20, 200, 50);
    unloadButton->name = "Unload";
    unloadButton->setFont(uiFont);
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
    if (!loaded)
    {
        // draw drag n drop circle

        ofSetHexColor(0x2F2FCF);
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, dragRadius+50*sin(dragRadius/100*M_PI) + 60);
        ofSetHexColor(0x212121);
        ofCircle(ofGetWidth()/2, ofGetHeight()/2, dragRadius);
        string dragMsg = "Drag Debug Folder";
        float sx = uiFontLarge.stringWidth(dragMsg);
        ofSetColor(255);
        uiFontLarge.drawString(dragMsg, ofGetWidth()/2 - sx/2, ofGetHeight()/2);
    }

    ofSetColor(255);
    uiFontLarge.drawString(VarManager::shared_manager().current_dir(), 20, 40);

    ofSetHexColor(0x212121);
    ofRect(0, toolbarOffset, ofGetWidth(), 90);

    for (auto view : views)
    {
        if (!view.second->hidden)
        {
            if (view.second->name.substr(0, 5) == "graph")
            {
                if (loaded)
                {
                    view.second->draw();
                }
            }
            else
            {
                view.second->draw();
            }
        }
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

    toolbarOffset = -powf(2.0, 0.025*(y - 100));
    views.find("Quit")->second->setPos(ofPoint(20, -powf(2.0, 0.035*(y-100)) + 20));
    views.find("Unload")->second->setPos(ofPoint(240, -powf(2.0, 0.040*(y-100)) + 20));
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
    for (auto var : views)
    {
        if (var.second->name.substr(0, 5) == "graph")
        {
            ofLog(OF_LOG_NOTICE, "resize");
            Graph *graph = (Graph *)var.second;
            graph->setSize(ofPoint(w - 40, 300));
        }
    }
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
    // TODO: check if folder of file
    //VarManager::shared_manager().load_varibles("/Users/Jacob/Developer/of_v0.8.4_osx_release/apps/myApps/VARVA/debuggers/");

    VarManager::shared_manager().load_varibles(dragInfo.files[0]);
    loaded = true;
    views.find("Unload")->second->hidden = false;

    int y = 0;
    for (auto var : VarManager::shared_manager().var_map)
    {
        Graph *graph = new Graph(var.second, 20, 100 + (300+10*y)*y, ofGetWidth()-40, 300);
        graph->setFont(uiFont);
        graph->name = "graph_" + var.first;
        addView(graph);
        y++;
    }
}
