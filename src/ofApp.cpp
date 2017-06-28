#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);

	ofBackground(255);
	counter = 0;
	
}

//--------------------------------------------------------------
void ofApp::update() {

	if (counter == quickdraw.allstrokes.size()) {
		return;
	}
	quickdraw.clientmutex.lock();
	if (quickdraw.allstrokes.size() > 0) {
		imagesaver.addImage(quickdraw.allstrokes[counter], counter);
	}
	quickdraw.clientmutex.unlock();
	counter++;
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofDrawBitmapStringHighlight("fps: "+ofToString(ofGetFrameRate()), 10, 20);
	ofDrawBitmapStringHighlight("parsed drawings "+ofToString(quickdraw.allstrokes.size())+ " -> saved drawings " + ofToString(counter), 10, 40);
	
	ofDrawBitmapStringHighlight("press 'o' to open file ",10,60);
	ofDrawBitmapStringHighlight("press 's' to start conversion", 10, 80);

	ofDrawBitmapStringHighlight("selected file is: "+filetoparse.getBaseName(), 10, 100);


	ofPushMatrix();
	ofTranslate((ofGetWidth() / 2)-250, (ofGetHeight() / 2)-200);
	ofScale(2, 2);
	quickdraw.clientmutex.lock();
	ofSetColor(0, 0, 0, 255);
	if (quickdraw.allstrokes.size() > 0) {
		for (const auto &stroke : quickdraw.allstrokes[counter]) {
			stroke.draw();
		}
	}
	ofSetColor(255);
	
	quickdraw.clientmutex.unlock();
	ofPopMatrix();
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'o') {
		ofFileDialogResult  result = ofSystemLoadDialog("select file", false, ofToDataPath("input"));
		
		ofFile file = ofFile(result.filePath);

		if (file.getExtension() != "ndjson") {
			return;
		}
		else {
			filetoparse = file;
		}
		
	}

	if (key == 's') {

		if (filetoparse.getExtension() != "ndjson") {
			return;
		}
		else {
			quickdraw.start(filetoparse.getAbsolutePath());
			imagesaver.start(filetoparse.getBaseName());
		}

		
	}
}
