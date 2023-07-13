#pragma once
#include "en.h"

extern En player;//プレイヤー
extern int p;
extern int stop;

extern int playerimg;
extern int playerimg1;
extern int playerimg2;
extern int playerimg3;

void initPlayer();//プレイヤーの初期化
void updatePlayer();//プレイヤーの更新
void drawPlayer();
