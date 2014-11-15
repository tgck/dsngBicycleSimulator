#include "ofApp.h"

//--------------------------------------------------------------
// setupSender
// - クライアントとの通信系を構築します。
// - Note: 宛先は固定です。

void ofApp::setupSender(bool flag){
    
    // フラグの初期化
    bSendMode = flag;
    _prevSendTime = ofGetElapsedTimeMillis();
    
    if (!bSendMode) {
        // 送信オフ
        cout << "setupSender....NO" << endl;
        return;
        
    } else {
        // 送信オン
        cout << "setupSender...YES" << endl;
        // ofxOSCの初期化
        // 宛先は3つ。

        // TODO
        senders[0].setup("127.0.0.1", 3001); // Tested with Max
//        senders[0].setup("127.0.0.1", 12011);
        senders[1].setup("127.0.0.1", 12022);
        senders[2].setup("127.0.0.1", 12033);
    }
}

//--------------------------------------------------------------
// updateSender
// - クライアントとの通信を更新します。
// - Note: 宛先は固定です。

void ofApp::updateSender(){
    
    // 送信モードかつ、送信対象メッセージありの時のみ送信
    if (bSendMode && bNeedSending) {
        
        // 3000ミリ秒経過していれば送信する。
        if (ofGetElapsedTimeMillis() > _prevSendTime + 3000.0 ){
            _prevSendTime = ofGetElapsedTimeMillis();

            cout << "send!" << endl;
            send();
            
            // 後始末 - 1回ぽっきりで送信を抑止する場合はコメントアウトする。
            // bNeedSending = false;
        }
    }
}


//--------------------------------------------------------------
// send
// - クライアントとの通信をおこないます。
// - Note: 宛先は固定です。
// - TODO: 自転車情報の送信

void ofApp::send(){
    
    // メッセージ送信
    ofxOscMessage m;
    m.setAddress("/test");
    m.addIntArg(1);
    senders[0].sendMessage(m);
    
    m.addFloatArg(3.5f);
    senders[1].sendMessage(m);
    
    m.addStringArg("hello");
    m.addFloatArg(ofGetElapsedTimef());
    senders[2].sendMessage(m);
}
