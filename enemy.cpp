#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemy.h"
#include "player.h"

extern bool gameOverFlag;//ゲームオーバー判定
int p;
En enemy[EnemyNum];//敵
//extern int p;
//敵の初期化
void initEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		enemy[i].x = GetRand(799);
		enemy[i].y = GetRand(100);
		enemy[i].r = GetRand(20) + 10;
		enemy[i].color = GetColor(0, 200, 0);
		enemy[i].fill = true;
		enemy[i].enable = false;

		double speed = GetRand(50) / 500 + 1.0;//速度
		//double dx = player.x - enemy[i].x;//プレイヤーと敵のx方向の距離
		//double dy = player.y - enemy[i].y;//プレイヤーと敵のy方向の距離

		//double d = sqrt(dx * dx + dy * dy);//敵とプレイヤーとの距離
		//enemy[i].vx = speed * (dx / d);//xの移動量
		enemy[i].vy = speed ;//yの移動量
	}
}
//敵の更新
void updateEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			enemy[i].cooltime--;
			//敵を自動で動かす
			//enemy[i].x = enemy[i].x + enemy[i].vx;
			if (enemy[i].cooltime <= 0) {
				enemy[i].y = enemy[i].y + enemy[i].vy;
			}
			/*if (enemy[i].x < 0) {
				//もし左端に出たら
				enemy[i].x = 0;
				enemy[i].vx = -enemy[i].vx;
			}
			if (enemy[i].x >= 800) {
				//もし右端に出たら
				enemy[i].x = 800;
				enemy[i].vx = -enemy[i].vx;
			}*/
			if (enemy[i].y < 0) {
				//もし左端に出たら
				enemy[i].y = 0;
				enemy[i].vy = -enemy[i].vy;
			}
			if (enemy[i].y >= 600) {
				//もし右端に出たら
				//enemy[i].y = 600;
				//enemy[i].vy = -enemy[i].vy;
			}

			if (isHit(player, enemy[i]))
			{
				//当たっている
				p = p + 1;
				enemy[i].enable = false;
				//gameOverFlag = true;//ゲームオーバーフラグを立てる
			}

			/*for (int j = 0; j < ShotNum; j++) {
				//敵と弾との当たり判定
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//当たっている
						enemy[i].enable = false;//敵を無効
						shot[j].enable = false;//弾を無効
						break;
					}
				}
			}*/
		}
	}
}

//敵の描画
void drawEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			DrawCircle(enemy[i].x, enemy[i].y, enemy[i].r, enemy[i].color, enemy[i].fill);
		}
	}
}