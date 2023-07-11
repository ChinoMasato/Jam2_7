#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemy.h"
#include "player.h"

extern bool gameOverFlag;//�Q�[���I�[�o�[����
En enemy[EnemyNum];//�G
//�G�̏�����
void initEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		enemy[i].x = GetRand(799);
		enemy[i].y = GetRand(599);
		enemy[i].r = GetRand(20) + 10;
		enemy[i].color = GetColor(255, 0, 0);
		enemy[i].fill = true;
		enemy[i].enable = true;

		//double speed = GetRand(50) / 10 + 1.0;//���x
		//double dx = player.x - enemy[i].x;//�v���C���[�ƓG��x�����̋���
		//double dy = player.y - enemy[i].y;//�v���C���[�ƓG��y�����̋���

		//double d = sqrt(dx * dx + dy * dy);//�G�ƃv���C���[�Ƃ̋���
		//enemy[i].vx = speed * (dx / d);//x�̈ړ���
		//enemy[i].vy = speed * (dy / d);//y�̈ړ���
	}
}
//�G�̍X�V
void updateEnemy()
{
	for (int i = 0; i < EnemyNum; i++) {
		if (enemy[i].enable == true) {
			//�G�������œ�����
			enemy[i].x = enemy[i].x + enemy[i].vx;
			enemy[i].y = enemy[i].y + enemy[i].vy;

			if (enemy[i].x < 0) {
				//�������[�ɏo����
				enemy[i].x = 0;
				enemy[i].vx = -enemy[i].vx;
			}
			if (enemy[i].x >= 800) {
				//�����E�[�ɏo����
				enemy[i].x = 800;
				enemy[i].vx = -enemy[i].vx;
			}
			if (enemy[i].y < 0) {
				//�������[�ɏo����
				enemy[i].y = 0;
				enemy[i].vy = -enemy[i].vy;
			}
			if (enemy[i].y >= 600) {
				//�����E�[�ɏo����
				enemy[i].y = 600;
				enemy[i].vy = -enemy[i].vy;
			}

			if (isHit(player, enemy[i]))
			{
				//�������Ă���
				player.color = enemy[i].color;
				gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
			}

			for (int j = 0; j < ShotNum; j++) {
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
			}
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