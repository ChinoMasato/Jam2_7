#include "DxLib.h"
#include "player.h"
#include "shot.h"
#include "enemy.h"
#include "en.h"
#include "game.h"

void init();//初期化関数のプロトタイプ宣言
void update();//更新関数のプロトタイプ宣言
void updateGame();//ゲーム内容の更新
void draw();//描画処理
void drawGame();//ゲーム関連の描画

enum GameScene
{
	Title,
	Game
};
GameScene scene = Title;
int Titleimg;



// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);//ログ無効
	//DXライブラリの初期化処理 ここから
	ChangeWindowMode(TRUE);	//ウィンドウモードにする
	SetGraphMode(800, 600, 32);	//ウィンドウサイズを設定する
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);	//裏画面を描画対象へ
	//DXライブラリの初期化処理 ここまで

	init();//初期化処理の呼び出し　起動時一度だけ呼び出す

	//メインループ処理
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {

		update();//更新処理の呼び出し

		ScreenFlip();		//裏画面と表画面の入替
		ClearDrawScreen();	//裏画面の描画を全て消去
	}
	//メインループ処理ここまで

	DxLib_End();			// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}
//初期化関数　引数、戻り値なし
void init()
{
	Titleimg = LoadGraph("bg2.jpg");
	//プレイヤーの初期化
	initPlayer();
	//弾の初期化
	initShot();
	//敵の初期化処理
	initEnemy();
	//BGM再生
	//PlayMusic("ファイル名", DX_PLAYTYPE_LOOP);
}
//更新関数
void update()
{
	//ゲーム(審判)の更新
	updateGame();
	//プレイヤーの更新
	updatePlayer();
	//弾の更新
	updateShot();
	//敵の更新
	updateEnemy();
	//描画処理
	draw();
}

//描画処理
void draw()
{
	//敵の描画
	drawEnemy();
	//プレイヤーの描画
	drawPlayer();
	//弾の描画
	drawShot();
	//ゲーム関連の描画
	drawGame();
}

