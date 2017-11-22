#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#define GRABBER_WIDTH 320
#define GRABBER_HEIGHT 240
#define HUE_MARGIN 2
#define MIN_SIZE 50

class ofApp : public ofBaseApp {

public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void mousePressed(int x, int y, int button);

	ofVideoGrabber grabber;
	ofxCvColorImage rgbImage, hsvImage;  //HSV: hue, saturation, value. 
	ofxCvGrayscaleImage hue, saturation, value, filtered;  //value == brightness
	ofxCvContourFinder contours;

	bool showHSVcomponents = false;
	bool showVideo = true;
	bool showFiltered = true;
	bool showContours = true;
	int findHue1;
	int findHue2;

	bool testBool = false;
	bool ikDRUKTOCH = false;

};
