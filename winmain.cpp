#include "DxLib.h"
#include "player.h"
#include "enemy.h"
#include "en.h"
#include "game.h"
#include"effect.h"

void init();//初期化関数のプロトタイプ宣言
void update();//更新関数のプロトタイプ宣言
void updateGame();//ゲーム内容の更新
void draw();//描画処理
void drawGame();//ゲーム関連の描画
void titleUpdate();//タイトルの描画
void ClearUpdate();//クリア画面の描画

int Titleimg;
int press;



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
		if (scene == Title) {
			titleUpdate();//更新処理の呼び出し
		}
		if (scene == Game) {
			update();//更新処理の呼び出し
		}
		if (scene == Clear) {
			ClearUpdate();
		}
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
	Titleimg = LoadGraph("");
	press = LoadGraph("cooltext437636616251046.png");
	//ゲーム情報の初期化
	initGame();
	//プレイヤーの初期化
	initPlayer();
	//エフェクトの初期化
	initEffect();
	//敵の初期化処理
	initEnemy();
	//BGM再生
	//PlayMusic("ファイル名", DX_PLAYTYPE_LOOP);
}
void titleUpdate()
{
	//見た目変更
	if (CheckHitKey(KEY_INPUT_1) == 1)
	{
		playerimg = playerimg1;
	}
	if (CheckHitKey(KEY_INPUT_2) == 1)
	{
		playerimg = playerimg2;
	}
	if (CheckHitKey(KEY_INPUT_3) == 1)
	{
		playerimg = playerimg3;
	}
	if (CheckHitKey(KEY_INPUT_RETURN) == 1)
	{
		//タイトル画像の描画
		scene = Game;//Gameシーンへの切り替え
	}
	DrawGraph(0, 0, Titleimg, true);
	DrawGraph(300, 280, press, true);//プッシュロゴの表示設定
	DrawGraph(270, 320, playerimg, true);
}
//更新関数
void update()
{
	//ゲーム(審判)の更新
	updateGame();
	//プレイヤーの更新
	updatePlayer();
	//敵の更新
	updateEnemy();
	//エフェクトの更新
	updateEffect();
	//描画処理
	draw();
}

void ClearUpdate() 
{
	//DrawGraph(0, 0, Titleimg, true);//画像追加用
	DrawFormatString(300, 350, GetColor(255, 255, 0), "スコア %d 点", p);
}
//描画処理
void draw()
{
	//敵の描画
	drawEnemy();
	//プレイヤーの描画
	drawPlayer();
	//エフェクトの描画
	drawEffect();
	//ゲーム関連の描画
	drawGame();
}

