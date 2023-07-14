#include "en.h"
#include "DxLib.h"
#include "player.h"

En player;//�v���C���[
int playerimg;
int playerimg1;
int playerimg2;
int playerimg3;
int piyoimg;
int scoreimg;

int stop;

//�v���C���[�̏�����
void initPlayer()
{
	playerimg1 = LoadGraph("chi-bakun.png");
	playerimg2 = LoadGraph("funasi.png");
	playerimg3 = LoadGraph("nezumi.png");
	playerimg = playerimg1;
	piyoimg = LoadGraph("piyo.png");
	
	scoreimg= LoadGraph("scoreboard.png");

	player.x = 270 + 128;
	player.y = 500;
	player.r = 40;
	player.color = GetColor(255, 255, 255);
	player.fill = true;
	player.cooltime = 0;
	stop = 0;
}

//�v���C���[�̍X�V
void updatePlayer()
{
	//�v���C���[�𓮂���
	if (stop <= 0)
	{
		if (CheckHitKey(KEY_INPUT_RIGHT) == 1)
		{
			player.x = player.x + 1.0;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) == 1)
		{
			player.x = player.x - 1.0;
		}
	}
	stop--;
	
	/*if (CheckHitKey(KEY_INPUT_UP) == 1)
	{
		player.y = player.y - 2.0;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) == 1)
	{
		player.y = player.y + 2.0;
	}*/
	if (player.x < 0) {
		//�������[�ɏo����
		player.x = 0;
	}
	if (player.x >= 800) {
		//�����E�[�ɏo����
		player.x = 800;
	}
	/*if (player.y < 0) {
		//�������[�ɏo����
		player.y = 0;
	}
	if (player.y >= 600) {
		//�����E�[�ɏo����
		player.y = 600;
	}*/

	//�e��������
	/*if (CheckHitKey(KEY_INPUT_Z) == 1 &&
		player.cooltime <= 0)
	{
		//�e�������ȂƂ��̂ݏ����l���Z�b�g���L���ɂ���
		for (int i = 0; i < ShotNum; i++)
		{
			//���Ă�e���݂���
			if (shot[i].enable == false) {
				//�e������
				shot[i].x = player.x;
				shot[i].y = player.y;
				shot[i].enable = true;
				player.cooltime = 30;//�A�ˑ��x�@�������قǘA�˂ł���
				break;
			}
		}
	}
	//�e���₷����
	if (player.cooltime > 0) {
		player.cooltime--;
	}*/
}

//�v���C���[�̕`��
void drawPlayer()
{
	//DrawCircle(player.x, player.y, player.r, player.color, player.fill);
	DrawGraph(player.x - 125, player.y - 48, playerimg, true);
	DrawGraph(player.x - 65, player.y +10 , scoreimg, true);
	SetFontSize(32);
	DrawFormatString(player.x-7, player.y+58, GetColor(255, 255, 0), "%d", p);
	SetFontSize(16);
	if (stop > 0)
	{
		DrawGraph(player.x -40, player.y - 58, piyoimg, true);//�X�^���������̐�
	}
}