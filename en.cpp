#include "en.h"

//�~�̓����蔻��֐�
bool isHit(En en1, En en2)
{
	//��̉~�̓����蔻��
	double dx = en1.x - en2.x;//���̋���
	double dy = en1.y - en2.y;//�c�̋���
	double r2 = en1.r + en2.r;//���a�̍��Z

	if (dx * dx + dy * dy < r2 * r2)
	{
		//�������Ă���
		return true;
	}
	return false;
}