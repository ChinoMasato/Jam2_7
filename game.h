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

void updateGame();
void drawGame();