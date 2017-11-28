#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	grabber.setup(640, 480);
	haarFinder.setup("haarcascade_eyes.xml");
	haarFinder2.setup("haarcascade_mouth.xml");
	image.load("eyes2.png");
	mouth.load("baard.png");
}

//--------------------------------------------------------------
void ofApp::update() {
	grabber.update();

	if (grabber.isFrameNew()) {
		haarFinder.findHaarObjects(grabber.getPixels(), 100, 100); //pakt de pixels uit het plaatje
		haarFinder2.findHaarObjects(grabber.getPixels(), 100, 100);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	grabber.draw(0, 0);

	ofSetColor(ofColor::white);
	for (int i = 0; i < haarFinder.blobs.size(); i++) {
		if (drawBox) {
			ofRectangle boundingBox = haarFinder.blobs[i].boundingRect;
			ofDrawRectangle(boundingBox);
		}


		if (drawImage) {
			ofRectangle boundingBox = haarFinder.blobs[i].boundingRect;
			image.draw(boundingBox);
		}
	}
	for (int i = 0; i < haarFinder2.blobs.size(); i++) {
		if (drawBaard) {
			ofRectangle boundingBox = haarFinder2.blobs[i].boundingRect;
			mouth.draw(boundingBox);
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'a') {
		drawBox = !drawBox;
	}
	if (key == 'i') {
		drawImage = !drawImage;
	}

	if (key == 'b') {
		drawBaard = !drawBaard;
	}
}

