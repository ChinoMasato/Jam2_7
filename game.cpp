#include "en.h"
#include "DxLib.h"
#include <math.h>
#include "enemy.h"
#include "player.h"
#include "game.h"


 int score ;//�_��
 int t;//����
 bool gameOverFlag ;//�Q�[���I�[�o�[����
  GameScene scene;

void updateGame()
{
	if (gameOverFlag == false) {
		score++;//�P�t���[�����ƂɂP�_���Z
		if (score >= 200) {
			t++;
			score = 0;
		}
	}

	if (GetRand(199) == 0)//��������鎞��
	{
		//����
		for (int i = 0; i < EnemyNum; i++) {
			if (enemy[i].enable == false) {
				enemy[i].x = GetRand(799);
				enemy[i].y = 50;
				enemy[i].r = GetRand(20) + 10;
				enemy[i].color = GetColor(GetRand(100) + 155, GetRand(100) + 155, GetRand(100) + 155);
				enemy[i].cooltime = 300;//�����Ă��痎���鎞��
				
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

//�Q�[�����̕`��
void drawGame()
{
	DrawFormatString(0, 0, GetColor(255, 255, 0), "�^�C�� %d �b", t);
	DrawFormatString(0, 50, GetColor(255, 255, 0), "�X�R�A %d �_", p);
	if (gameOverFlag == true) {
		DrawFormatString(350, 300, GetColor(255, 0, 0), "�Q�[���I�[�o�[");
	}
}