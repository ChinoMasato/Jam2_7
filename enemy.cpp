#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "enemy.h"
#include "player.h"
#include"effect.h"

extern bool gameOverFlag;//�Q�[���I�[�o�[����
int p;

int enemyimg1;
int enemyimg2;
int enemyimg3;
int catchse;
int bombse;

En enemy[EnemyNum];//�G
//extern int p;
//�G�̏�����
void initEnemy()
{
	catchse = LoadSoundMem("catch.mp3");
	bombse = LoadSoundMem("bombse.mp3");
	enemyimg1 = LoadGraph("rakkasei.png");
	enemyimg2 = LoadGraph("bakudan.png");
	enemyimg3 = LoadGraph("nasi.png");
	
	for (int i = 0; i < EnemyNum; i++) {
		enemy[i].x = GetRand(799);
		enemy[i].y = GetRand(100);
		enemy[i].r =  16;
		enemy[i].color = GetColor(0, 200, 0);
		enemy[i].fill = true;
		enemy[i].enable = false;

		double speed = GetRand(50) / 500 + 1.0;//���x
		//double dx = player.x - enemy[i].x;//�v���C���[�ƓG��x�����̋���
		//double dy = player.y - enemy[i].y;//�v���C���[�ƓG��y�����̋���

		//double d = sqrt(dx * dx + dy * dy);//�G�ƃv���C���[�Ƃ̋���
		//enemy[i].vx = speed * (dx / d);//x�̈ړ���
		enemy[i].vy = speed ;//y�̈ړ���
		
		//���Ԑ��ȊO���o��m��
		enemy[i].typePb = GetRand(6);//type�̊m��
		
		if (enemy[i].typePb == 4 ||
			enemy[i].typePb == 5)
		{
			enemy[i].type = normal;
		}
		if (enemy[i].typePb == 0||
			enemy[i].typePb == 1)
		{
			enemy[i].type = bomb;
		}
		if (enemy[i].typePb == 2 ||
			enemy[i].typePb == 3)
		{
			enemy[i].type = nasi;
			enemy[i].vy = speed * 2.0;
		}
	}
}

//���������֐�
void explosion(En ene)
{
	for (int i = 0; i < EffectNum; i++)
	{
		if (effe[i].enable == false)
		{
			effe[i].enable = true;
			effe[i].x = ene.x - 60;
			effe[i].y = ene.y - 60;
			effe[i].animeNo = 0;
			break;
		}
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
				enemy[i].enable = false;
				//�����E�[�ɏo����
				//enemy[i].y = 600;
				//enemy[i].vy = -enemy[i].vy;
			}

			if (isHit(player, enemy[i]))
			{
				//�������Ă���
				if (enemy[i].type == normal)
				{
					p = p + 1;
					if (playerimg == playerimg1)
					{
						p = p + 1;
					}
					PlaySoundMem(catchse, DX_PLAYTYPE_BACK);
				}
				if (enemy[i].type == nasi)
				{
					p = p + 1;
					if (playerimg == playerimg2)
					{
						p = p + 1;
					}
					PlaySoundMem(catchse, DX_PLAYTYPE_BACK);
				}
				if (enemy[i].type == bomb)
				{
					if (p > 0)
					{
						p = p - 1;//���e�ɓ���������X�R�A�}�C�i�X
						if (playerimg == playerimg3)
						{
							p = p + 89;
						}
					}
					explosion(enemy[i]);
					PlaySoundMem(bombse, DX_PLAYTYPE_BACK);
					stop = 200;//���e�ɓ����������̃X�^������
				}
				//gameOverFlag = true;//�Q�[���I�[�o�[�t���O�𗧂Ă�
				enemy[i].enable = false;
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
			//DrawCircle(enemy[i].x, enemy[i].y, enemy[i].r, enemy[i].color, enemy[i].fill);
			if (enemy[i].type == normal) {
				DrawGraph(enemy[i].x - 32, enemy[i].y - 32, enemyimg1, true);
			}
			if (enemy[i].type == nasi) {
				DrawGraph(enemy[i].x - 32, enemy[i].y - 32, enemyimg3, true);
			}
			if (enemy[i].type == bomb) {
				DrawGraph(enemy[i].x - 32, enemy[i].y - 32, enemyimg2, true);
			}
		}
	}
}