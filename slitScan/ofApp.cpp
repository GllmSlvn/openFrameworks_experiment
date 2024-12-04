#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    camWidth = 1280; camHeight = 720;
    float aspectRatio = camWidth / camHeight;
    
    w = camWidth;
    h = camHeight;
    
    cam.initGrabber(camWidth, camHeight);
    pixels.allocate(w, h, OF_PIXELS_RGB);
    pix.allocate(w, h, OF_PIXELS_RGB);
    tex.allocate(pix);
    camDisplay.allocate(pix);
    
    speed = 2;
    record = false;
    stop = false;
    mode = 1; // 1 vertical 2 horizontal
    pNum = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
    cam.update();
    cam.getPixels().mirror(false, true);
    pixels = cam.getPixels();
    ofColor color;
    
    if(record){
        if(cam.isFrameNew()){
            
            // vertical scan
            if(mode == 1){
                for(int x = 0; x < camWidth; x++){
                    color = pixels.getColor(camWidth-x, yStep);
                    pix.setColor(x, yStep, color);
                }
                tex.loadData(pix);
               
                if(yStep >= camHeight){
                    yStep = 0;
                    record = false;
                }
                if(!stop){
                    yStep += speed;
                }
            }
            
            // horizontal scan
            if(mode == 2){
                for(int y = 0; y < camHeight; y++){
                    color = pixels.getColor(xStep, y);
                    pix.setColor(xStep, y, color);
                }
                tex.loadData(pix);
                
                if(xStep >= camWidth){
                    xStep = 0;
                    record = false;
                }
                xStep += speed;
            }
            
        }
    }
    
    if(mode == 1){
        
        if(cam.isFrameNew()){
            for(int y = yStep; y <= h; y++){
                for(int x = 0; x < camWidth; x++){
                    color = pixels.getColor(x, y);
                    pix.setColor(camWidth-x, y, color);
                }
            }
            camDisplay.loadData(pix);
        }
    }
    
    if(mode == 2){
        if(cam.isFrameNew()){
            for(int x = xStep; x < w; x++){
                for(int y = 0; y < camHeight; y++){
                    color = pixels.getColor(x, y);
                    pix.setColor(x, y, color);
                }
            }
            camDisplay.loadData(pix);
        }
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
   
    ofSetColor(255);
    
    if(mode == 1){
        camDisplay.draw(w,0,-w,h);
        tex.draw(w,0,-w,h);
            
        // draw recorder line
        ofSetColor(0, 255, 0);
        ofSetLineWidth(3);
        ofDrawLine(0, yStep, w, yStep);
    }
    
    if(mode == 2){
        camDisplay.draw(0,0,w,h);
        tex.draw(0,0,w,h);
        
        ofSetColor(0, 255, 0);
        ofSetLineWidth(3);
        ofDrawLine(xStep, 0, xStep, h);
    }
    
    switch(mode){
        case 1:
            ofDrawBitmapString("vertical mode", 10, 10);
            break;
        case 2:
            ofDrawBitmapString("horizontal mode", 10, 10);
            break;
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == ' '){
        record = !record;
        yStep = 0;
        xStep = 0;
    }
    
    if(key == 'x'){
        img.grabScreen(0, 0 , w, h);
        img.save(name + ofToString(pNum) + ".png");
        pNum++;
    }
    
    if(key == '1'){
        mode = 1;
        record = false;
        yStep = 0;
    }
    
    if(key == '2'){
        mode = 2;
        record = false;
        xStep = 0;
    }
    
    if(key == 's'){
        stop = !stop;
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

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
