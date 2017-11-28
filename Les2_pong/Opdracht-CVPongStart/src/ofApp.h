#pragma once

#include "ofMain.h"
#include "Ball.h"
#include "ofxOpenCv.h"
#include "ColourTracker.h"

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


        static const int PADDLE_WIDTH = 20;
        static const int PADDLE_HEIGHT = 250;

		bool showVideo;



    private:
        Ball ball;
        int missedCount;
        int paddleY;
		ColourTracker colourTracker;
};
