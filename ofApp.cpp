#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);

	ofNoFill();
	ofSetCircleResolution(120);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);

	this->mesh.clear();
	int max_radius = 300;

	for (float deg = 0; deg < 360; deg += 0.2) {

		auto radius = max_radius - (int)(ofRandom(max_radius) + ofGetFrameNum() * ofRandom(2, 10)) % max_radius;
		this->mesh.addVertex(glm::vec3(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD), 0));
		this->mesh.addColor(ofColor(255, radius > max_radius - 50 ? 255 : radius < 100 ? 0 : ofMap(radius, 100, max_radius - 50, 0, 255)));
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	ofFill();
	for (int i = 0; i < this->mesh.getNumVertices(); i++) {

		ofSetColor(this->mesh.getColor(i));
		ofDrawCircle(this->mesh.getVertex(i), 1.5);
	}


	ofNoFill();
	ofSetColor(255);
	ofDrawCircle(glm::vec2(), 300);
}


//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}