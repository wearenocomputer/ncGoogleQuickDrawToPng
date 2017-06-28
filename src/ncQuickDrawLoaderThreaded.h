#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

class ncQuickDrawLoaderThreaded : public ofThread{

	public:
	

		void start(string file);

		void threadedFunction();

		vector< vector<ofPolyline> > allstrokes;
		Json::Reader reader;
		ifstream input;

		ofMutex clientmutex;
		
};
