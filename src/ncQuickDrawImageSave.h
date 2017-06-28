#pragma once

#include "ofMain.h"

class ncQuickDrawImageSave {

	public:
		void start(string _foldername);
		
		void addImage(vector<ofPolyline> & strokes, int _counter);

		void addImage(ofPolyline & stroke, int _counter);

		void draw();

		ofFbo image;

		string foldername;
		
};
