#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemy.h"
#include "player.h"

extern bool gameOverFlag;//�Q�[���I�[�o�[����
int p;
En enemy[EnemyNum];//�G
//extern int p;
//�G�̏�����
void initEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		enemy[i].x = GetRand(799);
		enemy[i].y = GetRand(100);
		enemy[i].r = GetRand(20) + 10;
		enemy[i].color = GetColor(0, 200, 0);
		enemy[i].fill = true;
		enemy[i].enable = false;

		double speed = GetRand(50) / 500 + 1.0;//���x
		//double dx = player.x - enemy[i].x;//�v���C���[�ƓG��x�����̋���
		//double dy = player.y - enemy[i].y;//�v���C���[�ƓG��y�����̋���

		//double d = sqrt(dx * dx + dy * dy);//�G�ƃv���C���[�Ƃ̋���
		//enemy[i].vx = speed * (dx / d);//x�̈ړ���
		enemy[i].vy = speed ;//y�̈ړ���
	}
}
//�G�̍X�V
void updateEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			enemy[i].cooltime--;
			//�G�������œ�����
			//enemy[i].x = enemy[i].x + enemy[i].vx;
			if (enemy[i].cooltime <= 0) {
				enemy[i].y = enemy[i].y + enemy[i].vy;
			}
			/*if (enemy[i].x < 0) {
				//�������[�ɏo����
				enemy[i].x = 0;
				enemy[i].vx = -enemy[i].vx;
			}
			if (enemy[i].x >= 800) {
				//�����E�[�ɏo����
				enemy[i].x = 800;
				enemy[i].vx = -enemy[i].vx;
			}*/
			if (enemy[i].y < 0) {
				//�������[�ɏo����
				enemy[i].y = 0;
				enemy[i].vy = -enemy[i].vy;
			}
			if (enemy[i].y >= 600) {
				//�����E�[�ɏo����
				//enemy[i].y = 600;
				//enemy[i].vy = -enemy[i].vy;
			}

			if (isHit(player, enemy[i]))
			{
				//�������Ă���
				p = p + 1;
				enemy[i].enable = false;
				//gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
			}

			/*for (int j = 0; j < ShotNum; j++) {
				//�G�ƒe�Ƃ̓����蔻��
				if (shot[j].enable == true) {
					if (isHit(shot[j], enemy[i]))
					{
						//�������Ă���
						enemy[i].enable = false;//�G�𖳌�
						shot[j].enable = false;//�e�𖳌�
						break;
					}
				}
			}*/
		}
	}
}

//�G�̕`��
void drawEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			DrawCircle(enemy[i].x, enemy[i].y, enemy[i].r, enemy[i].color, enemy[i].fill);
		}
	}
}