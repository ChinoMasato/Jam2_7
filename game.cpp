#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemy.h"
#include "player.h"
#include "game.h"


 int score ;//点数
 bool gameOverFlag ;//ゲームオーバー判定

void updateGame()
{
	if (gameOverFlag == false) {
		score++;//１フレームごとに１点加算
	}

	if (GetRand(199) == 0)
	{
		//実る
		for (int i = 0; i < EnemyNum; i++) {
			if (enemy[i].enable == false) {
				enemy[i].enable = true;
				enemy[i].x = GetRand(799);
				enemy[i].y = 50;
				enemy[i].r = GetRand(20) + 10;
				enemy[i].color = GetColor(GetRand(100) + 155, GetRand(100) + 155, GetRand(100) + 155);
				enemy[i].cooltime = 100;
				break;
			}
		}
	}
}

//ゲーム情報の描画
void drawGame()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "タイム %d 点", score);
	DrawFormatString(0, 50, GetColor(255, 255, 0), "スコア %d 点", p);
	if (gameOverFlag == true) {
		DrawFormatString(350, 300, GetColor(255, 0, 0), "ゲームオーバー");
	}
}