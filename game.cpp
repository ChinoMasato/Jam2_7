#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "enemy.h"
#include "player.h"
#include "game.h"


 int score ;//点数
 int t;//時間
 bool gameOverFlag ;//ゲームオーバー判定
  GameScene scene;

void updateGame()
{
	if (gameOverFlag == false) {
		score++;//１フレームごとに１点加算
		if (score >= 200) {
			t++;
			score = 0;
		}
	}

	if (GetRand(199) == 0)//生成される時間
	{
		//実る
		for (int i = 0; i < EnemyNum; i++) {
			if (enemy[i].enable == false) {
				enemy[i].x = GetRand(799);
				enemy[i].y = 50;
				enemy[i].r = GetRand(20) + 10;
				enemy[i].color = GetColor(GetRand(100) + 155, GetRand(100) + 155, GetRand(100) + 155);
				enemy[i].cooltime = 300;//実ってから落ちる時間
				
				enemy[i].enable = true;
				break;
			}
		}
	}
	if (t >= 10)
	{
		scene = Clear;
	}
}

//ゲーム情報の描画
void drawGame()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "タイム %d 秒", t);
	DrawFormatString(0, 50, GetColor(255, 255, 0), "スコア %d 点", p);
	if (gameOverFlag == true) {
		DrawFormatString(350, 300, GetColor(255, 0, 0), "ゲームオーバー");
	}
}