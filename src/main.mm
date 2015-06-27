#include "ofMain.h"
#include "ofApp.h"

#ifdef __APPLE__
#include <Cocoa/Cocoa.h>
#endif

//========================================================================
int main()
{
	ofSetupOpenGL(1024,768,OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:

    // If on OSX make window frame dark.
#ifdef TARGET_OSX
    NSWindow *window = (NSWindow *)ofGetCocoaWindow();
    [window setAppearance:[NSAppearance appearanceNamed:NSAppearanceNameVibrantDark]];
    [window setTitlebarAppearsTransparent:YES];
    [window invalidateShadow];
#endif

	ofRunApp(new ofApp());

    return 0;
}
