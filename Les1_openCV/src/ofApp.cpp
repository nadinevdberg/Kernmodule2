#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT);
	//alle images moeten een width en height mee krijgen. hebben ze niet van zichzelf.

	rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hsvImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);

	hue.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	saturation.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	value.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	filtered.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	
}

//--------------------------------------------------------------
void ofApp::update() {
	grabber.update();
	// alleen werk doen als je een new frame binnen hebt gekregen
	// pixels stoppen we in een image en hier kunnen we oF dingen mee doen
	if (grabber.isFrameNew()) {
		rgbImage.setFromPixels(grabber.getPixels().getData(),
			GRABBER_WIDTH,
			GRABBER_HEIGHT);
		rgbImage.mirror(false, true);  // verticaal je beeld spiegelen 

		hsvImage = rgbImage; //met hsv is makkelijk rekenen want je krijg 1 getal
		hsvImage.convertRgbToHsv();

		hsvImage.convertToGrayscalePlanarImages(hue, saturation, value); 
		//als ieder pixeltje matcht met wat we aangeklikt hebben (marge), dan wit pixel, anders zwart
		if (testBool == true) {
			for (int i = 0; i < GRABBER_WIDTH*GRABBER_HEIGHT; i++) {
				{
					if (ofInRange(hue.getPixels()[i],
						findHue1 - HUE_MARGIN,//marge zodat de kleur heel iets af kan wijken
						findHue1 + HUE_MARGIN)) {
						//filtered is een masker
						filtered.getPixels()[i] = 255;



					}
					else {
						filtered.getPixels()[i] = 0;
					}
				}
			}
		}
		if (testBool == false){
		for (int i = 0; i < GRABBER_WIDTH*GRABBER_HEIGHT; i++){
			
				if (ofInRange(hue.getPixels()[i],
					findHue2 - HUE_MARGIN,//marge zodat de kleur heel iets af kan wijken
					findHue2 + HUE_MARGIN)) {
					//filtered is een masker
					filtered.getPixels()[i] = 255;
					
					
					
				}
				else {
					filtered.getPixels()[i] = 0;
				}
			}
			
		}
		filtered.flagImageChanged(); //masker nog op scherm zien
		contours.findContours(filtered, MIN_SIZE, 
			GRABBER_WIDTH * GRABBER_HEIGHT/2,1,false); //grenzen voor de blobs
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	if (showVideo) {
		rgbImage.draw(0, 0, ofGetWidth(), ofGetHeight());


	}

	if (showHSVcomponents) {
		hsvImage.draw(880, 0);
		hue.draw(0, 0);
		saturation.draw(320, 0);
		value.draw(640, 0);
	}

	if (showFiltered) {
		filtered.draw(0, 480);
	
		if (showContours) {
			contours.draw(0, 480);
		}
	}
}

void ofApp::keyPressed(int key)
{
	if (key == 'h') {
		showHSVcomponents = !showHSVcomponents;
	}
	else if (key == 'v') {
		showVideo = !showVideo;
	}
	else if (key == 'c') {
		showContours = !showContours;
	}
	else if (key == 'f') {
		showFiltered = !showFiltered;
	}

	if (key == 'i') {
		ikDRUKTOCH = !ikDRUKTOCH;
		ofLog() << "ik druk toch" << ikDRUKTOCH;
	}

	if (key == 'j') {
		testBool = !testBool;
		ofLog() << testBool;
	}
}

void ofApp::mousePressed(int x, int y, int button)
{
	//pak de hue van waar je op klikt. y as maal aantal pixels die in de breedte zitten, +x
	
	if (testBool == true) {
		findHue1 = hue.getPixels()[y*GRABBER_WIDTH + x];
		ofLog() << "bool is true, hue1 = " << findHue1;
	}

	if (testBool == false) {

		findHue2 = hue.getPixels()[y*GRABBER_WIDTH + x];
		ofLog() << "bool is false, hue 2 = " << findHue2;
	}
	
}

	