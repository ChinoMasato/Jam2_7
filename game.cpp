#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "shot.h"
#include "enemy.h"
#include "player.h"
#include "game.h"


 int score ;//�_��
 bool gameOverFlag ;//�Q�[���I�[�o�[����

void updateGame()
{
	if (gameOverFlag == false) {
		score++;//�P�t���[�����ƂɂP�_���Z
	}

	if (GetRand(199) == 0)
	{
		//����
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

//�Q�[�����̕`��
void drawGame()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "�^�C�� %d �_", score);
	DrawFormatString(0, 50, GetColor(255, 255, 0), "�X�R�A %d �_", p);
	if (gameOverFlag == true) {
		DrawFormatString(350, 300, GetColor(255, 0, 0), "�Q�[���I�[�o�[");
	}
}