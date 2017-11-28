#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

#define GRABBER_HEIGHT 240
#define GRABBER_WIDTH 320
#define HUE_MARGIN 5
#define MIN_SIZE 50

class ColourTracker {
public:
	ColourTracker();
	void setup();
	void update();
	void draw();
	//void mousePressed(int x, int y, int button);
	void selectColor(int x, int y);
	ofVideoGrabber grabber;
	ofxCvColorImage rgbImage, hsvImage;  //HSV: hue, saturation, value. 
	ofxCvGrayscaleImage hue, saturation, value, filtered;  //value == brightness
	ofxCvContourFinder contours;
	bool haveBlobs();
	
	ofPoint getCentroid();

	bool showVideo = true;
	bool showFiltered = true;
	bool showContours = true;
	bool showHSVcomponents = false;
	int findHue;


};
