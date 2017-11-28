#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		ofVideoGrabber grabber;
		ofxCvHaarFinder haarFinder;

		ofxCvHaarFinder haarFinder2;

		bool drawBox = false;
		bool drawImage = true;
		bool drawBaard = true;
		ofImage image;
		ofImage mouth;
};
