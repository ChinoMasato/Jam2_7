#pragma once
#pragma once

const int EffectNum = 100;
extern int img[10];//�ő�R�}���@�摜

struct Effect
{
	double x;
	double y;
	double animeNo = 0;//���R�}�ڂ�
	int maxAnimeNo;//�ő�R�}��
	bool enable = false;//�L���t���O
};
extern Effect effe[EffectNum];
void initEffect();
void updateEffect();
void drawEffect();