#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // trigger ratio !
    windowResized(ofGetWidth(), ofGetHeight());
    
    ofSetFrameRate( 64 );
    //ofSetVerticalSync(true);
    
    ofBackground(0);
    cam.setDistance(100);
    
    total_Points = 30000;
    shouldSaveScreen = false;
    
    particles.resize(total_Points);
    for (int i = 0; i < total_Points; ++i) {
        particles[i].position = ofPoint(0, 1. / (float)i, 0);
        mesh.addVertex(particles[i].position);
        mesh.addColor(particles[i].color);
    }
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    mouse = ofVec3f(ofGetMouseX(), height-ofGetMouseY(), 0);
    mouse = toCoordRelative(mouse);
    
    for(int i=0; i<particles.size(); ++i){
        particles[i].update(mouse, size);
        
        mesh.setVertex(i, particles[i].position);
        mesh.setColor(i, particles[i].color);
    }
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()) + ofToString(total_Points));
    
    if (shouldSaveScreen) {
        ofSaveFrame(true);
    }
     
}

//--------------------------------------------------------------
void ofApp::draw(){
   
    ofPushMatrix();
    cam.begin();
    mesh.draw();
    cam.end();
    ofPopMatrix();
     
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'c') {
        shouldSaveScreen = !shouldSaveScreen;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
    screenRatio = (float)ofGetWidth()/ofGetHeight();
     
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

ofVec3f ofApp::toCoordRelative(ofVec3f position){
    
    position.x = ((position.x / width) * 2.) - 1; // range (-1/1)
    position.y = ((position.y / height) * 2.) - 1; // idem
    position.x *= screenRatio;
    return position;
    
}
 
