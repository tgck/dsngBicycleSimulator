#pragma once

// アプリケーションのウィンドウサイズ(ピクセル)
static int winSize[2] = {1200, 800};

// メッセージ送信間隔(ミリ秒) [333.3]
static float sendInterval = 3000.0;

// アプリケーションウィンドウに対する、デスクトップフィールドの大きさ
#define WINDOW_DESKTOPFIELD_RATIO 0.4

//
// color schemes
//
static ofColor COLOR_BIKE = ofColor(212, 0, 0);
static ofColor COLOR_TRACK = ofColor(212, 188, 0);

static ofColor COLOR_DEBUGINFO = ofColor(0, 0, 0);

static ofColor COLOR_GUIDE_X = ofColor(188, 0, 0);
static ofColor COLOR_GUIDE_Y = ofColor(0, 188, 0);
static ofColor COLOR_BACKGROUND = ofColor(128, 128, 128);
