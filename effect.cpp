#include"effect.h"
#include "DxLib.h"
Effect effe[EffectNum];
int img[10];//画像10枚入れる変数
void initEffect()
{
	LoadDivGraph("effect.png", 5, 5, 1, 120, 120, img);
}
void updateEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)//有効になったら
		{
			//アニメーションを進める
			effe[i].animeNo = effe[i].animeNo + 0.1;//切り捨てでimg1,2,3,4,5になる
			//６コマ目になったら無効
			if ((int)(effe[i].animeNo) > 5) {
				effe[i].enable = false;
			}
		}
	}
}
void drawEffect()
{
	for (int i = 0; i < EffectNum; i++) {
		if (effe[i].enable == true)
		{
			int no = effe[i].animeNo;
			DrawGraph(effe[i].x, effe[i].y, img[no], true);
		}
	}
}
