#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// OSCメッセージの受信ポートを定義
#define PORT 12345

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();

    // OSC受信用
    ofxOscReceiver receiver;
    ofVideoPlayer player; // 動画プレイヤー
};