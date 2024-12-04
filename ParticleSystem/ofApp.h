#pragma once

#include "ofMain.h"

class Particle {
public:
    ofVec3f position;
    ofVec3f velocity;
    float mass;
    float lifeTime;
    bool isDead;
    float zGravity;
    
    ofVec3f gravity;
    float length;
    ofFloatColor color;
    
    
    Particle() {
        position.set(0, 0, 0);
        velocity.set(0, 0, 0);
        mass = ofRandom(0.9) + 0.1;
        lifeTime = ofRandom(1.0);
        isDead = false;
        zGravity = ofRandom(-0.05, 0.05);
    }
    
    void update(ofVec3f mouse, float size){
        
        ofVec3f mouseNow;
        mouseNow = mouse;
        
        if(isDead) {
            position = mouseNow * size;
            isDead = false;
        }
        
        position /= size;  //valeurs relative entre -1/1 = normalisation // *POSITION*
        gravity = {0, -0.01, 0}; // *GRAVITÉ*
        ofVec3f attriction = velocity * -0.02; // *ATTRICTION*
        
        // TRAITEMENT
        lifeTime -= 0.003;
        if(lifeTime <= 0) isDead = true;
        lifeTime = ofWrap(lifeTime, 0., 1.);
        
        mouseNow -= position;
        
        length = (pow(mouse.length(), 3) * 3.) + 1 ;
        
        mouseNow = mouseNow.normalize() * 0.005;
        mouseNow /= length;
        
        velocity += mouseNow;
        velocity += attriction;
        
        gravity.z = zGravity;
        gravity += velocity;
        gravity *= mass;
        
        position += gravity;
        
        position.y = ofClamp(position.y, -1, 1);
        position.x = ofClamp(position.x, -1, 1);
        position.z = ofClamp(position.z, -1,1);
        
        // DE-NORMALISATION
        position *= size;
        
        color = ofFloatColor(1-(lifeTime * 0.8) + 0.2,lifeTime,lifeTime);
        
    }
    
    void draw(){
        ofSetColor(color);
        ofDrawCircle(position.x, position.y, position.z, 0.1);
    }
};


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVec3f toCoordRelative(ofVec3f position);
    
    std::vector< Particle > particles;
    ofEasyCam cam;
    ofVec3f mouse;
    
    ofMesh mesh;
    
    int total_Points;
    float screenRatio;
    float width = ofGetWidth();
    float height = ofGetHeight();
    float depth = 1000;
    float size = 35;
    
    bool shouldSaveScreen;
};
