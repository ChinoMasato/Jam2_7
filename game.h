#pragma once
extern int score ;//点数
extern int t;
extern bool gameOverFlag ;//ゲームオーバー判定

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