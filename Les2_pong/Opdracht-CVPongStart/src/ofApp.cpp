#include "ofApp.h"

void ofApp::setup() {
	ofSetBackgroundColor(ofColor::black);
	ofSetCircleResolution(30);
	colourTracker.setup();
}

void ofApp::update() {
	colourTracker.update();
	if (colourTracker.haveBlobs()) {
		ofPoint blobPos = colourTracker.getCentroid();
		int scaledY = blobPos.y * ofGetHeight() / GRABBER_HEIGHT;
		paddleY = scaledY;
	}


	bool wasReset = ball.update(paddleY);
	if (wasReset) {
		missedCount++;
	}



}

void ofApp::draw() {
	colourTracker.draw();
	ball.draw();

	ofDrawRectangle(ofGetWidth() - PADDLE_WIDTH,
		paddleY,
		PADDLE_WIDTH, PADDLE_HEIGHT);



	ofDrawBitmapString("Missed: " + ofToString(missedCount), 10, 10);
}

void ofApp::keyPressed(int key) {
	if (key == ' ') {
		ball.reset();
	}
	if (key == 'h') {
		colourTracker.showHSVcomponents = !colourTracker.showHSVcomponents;
	}
	else if (key == 'v') {
		colourTracker.showVideo = !colourTracker.showVideo;
	}
	else if (key == 'c') {
		colourTracker.showContours = !colourTracker.showContours;
	}
	else if (key == 'f') {
		colourTracker.showFiltered = !colourTracker.showFiltered;
	}
}

void ofApp::mousePressed(int x, int y, int button)
{
	if (colourTracker.haveBlobs()) {

		colourTracker.selectColor(x, y);
	}
}

