#include "testApp.h"

ofImage opal;
ofPlanePrimitive plane;
ofShader shader_keliedo;
ofShader shader;

bool use_kal = false;

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
   
   if(ofIsGLProgrammableRenderer()){
      shader_keliedo.load("gl3/kaleidoscope");
      shader.load("gl3/shader"); //passthrough shader
   }else{
      shader_keliedo.load("gl2/kaleidoscope");
      shader.load("gl2/shader"); //passthrough shader
   }
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
   ofClear(255.0f, 255.f, 255.f);
   ofSetColor(255);
   //The next 4 lines don't seem to work.
   opal.getTextureReference().setTextureWrap(GL_REPEAT,GL_REPEAT); //doesn't work
   ofSetTextureWrap(GL_REPEAT,GL_REPEAT); //doesn't work
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); //doesn't work
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); //doesn't work
   
   opal.getTextureReference().bind();
   
   float mousePositionX = ofMap(mouseX, 0, ofGetWidth(), plane.getWidth(), -plane.getWidth(), true);
   float mousePositionY = ofMap(mouseY, 0, ofGetHeight(), plane.getHeight(), -plane.getHeight(), true);
   
   if (use_kal){
      shader_keliedo.begin();
      shader_keliedo.setUniform2f("mouse", mousePositionX, mousePositionY);
      shader_keliedo.setUniform1f("time", ofGetElapsedTimef());
      shader_keliedo.setUniform2f("resolution", ofGetWidth(),ofGetHeight());
      ofPushMatrix();
      ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
      plane.draw();
      ofPopMatrix();
      shader_keliedo.end();
   }else{
      shader.begin();
      shader.setUniform2f("mouse", mousePositionX, mousePositionY);
      ofPushMatrix();
      ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
      plane.draw();
      ofPopMatrix();
      shader.end();
   }
   
   opal.getTextureReference().unbind();
}


//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
   use_kal = !use_kal;
}
/*
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
void testApp::windowResized(int w, int h){
   
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
   
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
   
}*/
