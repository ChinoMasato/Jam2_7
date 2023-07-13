#pragma once
#pragma once

const int EffectNum = 100;
extern int img[10];//最大コマ数　画像

struct Effect
{
	double x;
	double y;
	double animeNo = 0;//何コマ目か
	int maxAnimeNo;//最大コマ数
	bool enable = false;//有効フラグ
};
extern Effect effe[EffectNum];
void initEffect();
void updateEffect();
void drawEffect();
