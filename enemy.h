#pragma once
#include "en.h"

extern int enemyimg1;
extern int enemyimg2;
extern int enemyimg3;

const int EnemyNum = 30;
const int i = 0;
extern En enemy[EnemyNum];//�G

void initEnemy();//�G�̏�����
void updateEnemy();//�G�̍X�V
void drawEnemy();//�G�̕`��
