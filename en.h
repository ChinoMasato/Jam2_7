#pragma once
enum EnemyType
{
	normal,
	bomb
};

//�~�̍\����
struct En
{
	double x;//X���W
	double y;//Y���W
	double r;//���a
	int color;//�~�̐F
	bool fill;//�h��Ԃ����ۂ�
	double vx;//���̈ړ���
	double vy;//�c�̈ړ���
	bool enable;//�L���t���O�i�����Ă邩�A����ł邩�j
	int cooltime;//�A�˂ł��Ȃ��悤�ɂ���^�C�}�[
	EnemyType type;
	int typePb;//���e�̊m���Ɏg���ϐ�
};

bool isHit(En en1, En en2);//�����蔻��֐�
