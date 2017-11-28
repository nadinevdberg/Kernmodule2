#include "ColourTracker.h"

ColourTracker::ColourTracker() {}

void ColourTracker::setup() {
	grabber.setup(GRABBER_WIDTH, GRABBER_HEIGHT);
	rgbImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hsvImage.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	saturation.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	value.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	hue.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
	filtered.allocate(GRABBER_WIDTH, GRABBER_HEIGHT);
}

void ColourTracker::update() {
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
		for (int i = 0; i < GRABBER_WIDTH*GRABBER_HEIGHT; i++) {

			if (ofInRange(hue.getPixels()[i],
				findHue - HUE_MARGIN,//marge zodat de kleur heel iets af kan wijken
				findHue + HUE_MARGIN)) {
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
		GRABBER_WIDTH * GRABBER_HEIGHT / 2, 1, false); //grenzen voor de blobs
}


void ColourTracker::draw() {
	ofSetColor(ofColor::white);
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



//void ColourTracker::mousePressed(int x, int y, int button)
//{
//	findHue = hue.getPixels()[y*GRABBER_WIDTH + x];
//	ofLog() << "bool is true, hue1 = " << findHue;
//}

void ColourTracker::selectColor(int x, int y)
{
	findHue = hue.getPixels()[y*GRABBER_WIDTH + x];
	ofLog() << "bool is true, hue1 = " << findHue;
}

bool ColourTracker::haveBlobs()
{
	cout << "hoi "<< findHue << endl;
	return findHue != -1 && contours.blobs.size() > 0;
}

ofPoint ColourTracker::getCentroid()
{
	if (haveBlobs()) {
		return contours.blobs[0].centroid;
	}
}

