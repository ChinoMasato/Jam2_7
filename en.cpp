#include "en.h"

//円の当たり判定関数
bool isHit(En en1, En en2)
{
	//二つの円の当たり判定
	double dx = en1.x - en2.x;//横の距離
	double dy = en1.y - en2.y;//縦の距離
	double r2 = en1.r + en2.r;//半径の合算

	if (dx * dx + dy * dy < r2 * r2)
	{
		//当たっている
		return true;
	}
	return false;
}