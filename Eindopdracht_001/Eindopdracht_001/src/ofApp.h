#pragma once

#include "ofMain.h"
#define SOUNDS 4  //grootte van de library 

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();

		void keyPressed(int key);

		ofSoundPlayer soundPlayer[SOUNDS];  //mnaakt een soundplayer aan
		
};
