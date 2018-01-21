#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_NOTICE); // only message above a certain priority will show

	for (int i = 0; i < SOUNDS; i++) {
		ofLogNotice() << "Loading voice " << i << endl; //logt welk geluidsbestand hij inlaad
		soundPlayer[i].load(ofToDataPath("camel" + ofToString(i + 1) + ".mp3"));  // hierbij laad hij al mijn geluidsbestanden. doordat ze allemaal dezelfde naam hebben (camel) en alleen het nummer anders is, laad ik ze op deze manier makkelijk in
		soundPlayer[i].setLoop(true);  // zorgt ervoor dat de geluidsbestanden loopen

		soundPlayer[i].play(); // start de soundplayer
		//soundPlayer[i].setPaused(true); // ze de soundplayer op pauze zodat hij niet direct begint te spelen
	}
	ofSoundSetVolume(0.5);  // volume geluid: 50% van het maximum
}

//--------------------------------------------------------------
void ofApp::update(){
	
	ofSoundUpdate(); //updates sound engine
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofLogVerbose() << "Key:" << key << endl;
	//afhankelijk van welke toets ik indruk ; speel geluid af

	if (key == '1') {
		cout << "isPlaying? " << soundPlayer[0].isPlaying() << endl;
		soundPlayer[0].setPaused(soundPlayer[0].isPlaying());
	}
	else if (key == '2') {

		soundPlayer[1].setPaused(soundPlayer[1].isPlaying());
	}
	else if (key == '3') {

		soundPlayer[2].setPaused(soundPlayer[2].isPlaying());
	}
	else if (key == '4') {
	
		soundPlayer[3].setPaused(soundPlayer[3].isPlaying());
	}
}


