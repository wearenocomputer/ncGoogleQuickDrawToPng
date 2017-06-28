#include "ncQuickDrawLoaderThreaded.h"

void ncQuickDrawLoaderThreaded::start(string file){
	input = ifstream(file, ifstream::in);
	startThread();
}

//--------------------------------------------------------------
void ncQuickDrawLoaderThreaded::threadedFunction() {

	while (isThreadRunning()) {
		ofxJSONElement jsonElement;
		string currentLine;
		while (getline(input, currentLine)) {
			clientmutex.lock();
			reader.parse(currentLine, jsonElement);
			ofxJSONElement root = ofxJSONElement(jsonElement["drawing"]);
			vector<ofPolyline> strokes;

			for (auto& stroke_data : root) {
				assert(stroke_data.size() == 2);
				const auto  &x__ = stroke_data[0];
				const auto &y__ = stroke_data[1];
				ofPolyline stroke;
				for (int i = 0; i < x__.size(); i++) {
					stroke.addVertex(x__[i].asFloat(), y__[i].asFloat());
				}
				strokes.push_back(stroke);
			}

			allstrokes.push_back(strokes);
			clientmutex.unlock();
			sleep(1);
		}
		stopThread();
	}
}

