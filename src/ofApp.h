#pragma once

#include "ofMain.h"
#include "ncQuickDrawLoaderThreaded.h"
#include "ncQuickDrawImageSave.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		ncQuickDrawLoaderThreaded quickdraw;
		ncQuickDrawImageSave imagesaver;

		vector<ofPolyline> strokes;

		int counter;
		ofFile filetoparse;
};
