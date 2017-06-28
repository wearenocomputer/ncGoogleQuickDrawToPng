#include "ncQuickDrawImageSave.h"

//--------------------------------------------------------------
void ncQuickDrawImageSave::start(string _foldername){
	foldername = _foldername;
	image.allocate(300, 280);
}

void ncQuickDrawImageSave::addImage(vector<ofPolyline> & strokes, int _counter) {

	
	image.begin();
	ofClear(255, 255, 255, 255);
	for (const auto &stroke : strokes) {
		ofSetColor(0, 0, 0, 255);
		stroke.draw();
		ofSetColor(255);
	}
	image.end();
	
	ofPixels pix;
	image.readToPixels(pix);
	ofSaveImage(pix, ofToDataPath("output/"+foldername+"/"+ofToString(_counter) + ".png"));
}

void ncQuickDrawImageSave::addImage(ofPolyline & stroke, int _counter)
{

	image.begin();
	ofClear(0, 0, 0, 255);
	stroke.draw();
	image.end();

	ofPixels pix;
	image.readToPixels(pix);
	ofSaveImage(pix, ofToDataPath("output/" + foldername + "/" + ofToString(_counter) + ".png"));
}

void ncQuickDrawImageSave::draw() {
	image.draw(0, 0);
}