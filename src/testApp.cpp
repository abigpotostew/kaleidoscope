#include "testApp.h"


//#define USE_KAL

ofImage opal;
ofPlanePrimitive plane;
#ifdef USE_KAL
ofShader shader_keliedo;
#endif
ofShader shader;


//--------------------------------------------------------------
void testApp::setup(){
   
   std::cout<<glGetString(GL_VERSION)<<std::endl;
   
   opal.loadImage("opal.jpg");
   
   float planeScale = 0.75;
   int planeWidth = ofGetWidth() * planeScale;
   int planeHeight = ofGetHeight() * planeScale;
   int planeGridSize = 20;
   int planeColumns = planeWidth / planeGridSize;
   int planeRows = planeHeight / planeGridSize;
   
   plane.set(planeWidth, planeHeight, planeColumns, planeRows, OF_PRIMITIVE_TRIANGLES);
   
   plane.mapTexCoordsFromTexture(opal.getTextureReference());
   
   
#ifdef USE_KAL
   shader_keliedo.load("gl3/kaleidoscope");
#endif
   shader.load("gl3/shader");
   
   //shader_keliedo.setUniform2f("resolution", ofGetWidth(), ofGetHeight());
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
   ofClear(255.0f, 255.f, 255.f);
   ofSetColor(255);
   opal.getTextureReference().setTextureWrap(GL_REPEAT,GL_REPEAT);
   ofSetTextureWrap(GL_REPEAT,GL_REPEAT);
   
   opal.getTextureReference().bind();
   
   float mousePositionX = ofMap(mouseX, 0, ofGetWidth(), plane.getWidth(), -plane.getWidth(), true);
   float mousePositionY = ofMap(mouseY, 0, ofGetHeight(), plane.getHeight(), -plane.getHeight(), true);
   
#ifdef USE_KAL
   shader_keliedo.begin();
   shader_keliedo.setUniform2f("mouse", mousePositionX, mousePositionY);
   shader_keliedo.setUniform1f("time", ofGetElapsedTimef());
   shader_keliedo.setUniform2f("resolution", ofGetWidth(),ofGetHeight());
   ofPushMatrix();
   ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
   plane.draw();
   ofPopMatrix();
   shader_keliedo.end();
#endif
   
#ifndef USE_KAL
   shader.begin();
   
   shader.setUniform2f("mouse", mousePositionX,mousePositionY);
   ofPushMatrix();
   ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   plane.draw();
   ofPopMatrix();
   
   shader.end();
#endif
   
      opal.getTextureReference().bind();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
