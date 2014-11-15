#include "ofApp.h"

//--------------------------------------------------------------
// setupSender
// - クライアントとの通信系を構築します。
// - Note: 宛先は固定です。

void ofApp::setupSender(bool bNeedSending){
    
    // フラグの初期化
    bSending = bNeedSending;
    
    if (!bSending) {
        // 送信オフ
        cout << "setupSender....NO" << endl;
        return;
        
    } else {
        // 送信オン
        cout << "setupSender...YES" << endl;
        // ofxOSCの初期化
        // 宛先は3つ。
        // TODO
    }
}

//--------------------------------------------------------------
// updateSender
// - クライアントとの通信を更新します。
// - Note: 宛先は固定です。
void ofApp::updateSender(){
    if (bSending) {send();}
}


//--------------------------------------------------------------
// send
// - クライアントとの通信をおこないます。
// - Note: 宛先は固定です。

void ofApp::send(){
    // メッセージ送信
    
    
}
