#pragma once
extern int score ;//�_��
extern int t;
extern bool gameOverFlag ;//�Q�[���I�[�o�[����

enum GameScene
{
	Title,
	Game,
	Clear
};
extern GameScene scene;

void initGame();
void updateGame();
void drawGame();