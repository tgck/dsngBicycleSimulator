#include "ofApp.h"

//--------------------------------------------------------------
// setupReceiver
// - 上位のアプリケーションからの接続をリスン開始します。

void ofApp::setupReceiver(bool flag){

    // 受信モードオフであれば、
    // receiverを初期化せず抜ける。
    if (!flag) return;

	cout << "listening on [" << L_PORT << "]" << endl;
	receiver.setup(L_PORT);
    
}

//--------------------------------------------------------------
// updateReceiver
// - 上位アプリケーションからのメッセージを受信します。

// Note: 受信メッセージの例
//      /steerReset         -- ※不使用
//      /pedal              -- ※ 1回転するごとに bang
//      /steerAngle 0.111   -- ハンドル角 (-1.0 .. 1.0)
//
// ForTest: $oscsend localhost 8001 /sample/address iTfs 1 3.14 hello
//          $oscsend localhost 8001 /pedal
//          $oscsend localhost 8001 /steerAngle f 0.1111
//

void ofApp::updateReceiver(){
    
	// hide old messages
	for(int i = 0; i < NUM_MSG_STRINGS; i++){
		if(timers[i] < ofGetElapsedTimef()){
			msg_strings[i] = "";
		}
	}
    
	while(receiver.hasWaitingMessages()){
        
		ofxOscMessage m;
		receiver.getNextMessage(&m);
        
        // pedal, steer
        // TODO : bike モデルへの取り込み
        // TODO : switch 文にする
        if (m.getAddress() == OSCA_SENSOR_PEDAL) {
            cout  << " received PEDAL" << endl;
        } else if (m.getAddress() == OSCA_SENSOR_STEER) {
            float tmpSteer = m.getArgAsFloat(0);
            cout  << " received STEER[" << tmpSteer << "]" << endl;
        }
        
        // dumpOSC(m);
    }
    
}

//--------------------------------------------------------------
// dumpOSC
// - OSCメッセージをコンソールに出力するユーティリティ関数です。

string ofApp::dumpOSC(ofxOscMessage m) {
	string str = m.getAddress();
	for (int i=0; i<m.getNumArgs(); i++ ) {
		str += " ";
		switch (m.getArgType(i)) {
			case OFXOSC_TYPE_INT32:
				str += ofToString( m.getArgAsInt32(i));
				break;
			case OFXOSC_TYPE_FLOAT:
				str += ofToString( m.getArgAsFloat(i));
				break;
			case OFXOSC_TYPE_STRING:
				str += m.getArgAsString(i);
				break;
			default:
				break;
		}
	}
	cout << str << endl;
	return str;
}