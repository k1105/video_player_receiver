#include "ofApp.h"

void ofApp::setup(){
    // OSC受信の設定
    receiver.setup(PORT);

    // 動画ファイルの読み込み
    player.load("FILENAME.mp4");
    player.setLoopState(OF_LOOP_NORMAL);

    // 動画の再生をここで開始しない
    // player.play(); を削除
}

void ofApp::update(){
    // OSCメッセージの受信と処理
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        // 受信したメッセージに関するログ出力
        ofLogNotice() << "Received OSC message: " << m.getAddress();

        if(m.getAddress() == "/play"){
            if(!player.isPlaying()){
                player.play();
                // 再生開始のログ出力
                ofLogNotice() << "Starting video playback.";
            }
        }
    }
    player.update();
}

void ofApp::draw(){
    player.draw(0, 0, ofGetWidth(), ofGetHeight());
}