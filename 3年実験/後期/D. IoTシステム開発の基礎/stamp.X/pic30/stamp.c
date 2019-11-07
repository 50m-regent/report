/****************************************************************
*	stamp.c							*
*	EC3　学生実験：30円切手自動販売機			*
*	　　　　　　   10円のみ使用可能、遷移関数使用版		*
*			 last update 2014/06/12 by ecstaff	*
*****************************************************************/
#include	"pic.h"		/* ヘッダ・ファイル		*/
#include	"def.h"		/* define宣言一覧		*/
#include	"global.h"	/* グローバル変数		*/
#include	"extern.h"	/* 外部関数一覧			*/

/* コンフィギュレーション・ビットの設定	*/
__CONFIG(FOSC_HS &	/* 高速 水晶・発振器 */
	 WDTE_OFF &	/* ウォッチドッグ・タイマ = OFF */
	 PWRTE_ON &	/* パワーアップ・タイマ = ON */
	 MCLRE_ON &	/* RA5ピンの機能をMaster Clearに設定 */
	 BOREN_OFF &	/* 低電圧リセット = OFF */
	 LVP_OFF &	/* 低電圧プログラミング = OFF */
	 CPD_OFF &	/* データ・コード・プロテクト = OFF */
	 CP_OFF		/* コード・プロテクト = OFF */
);

/* 関数プロトタイプ宣言 */
int Transition (	/* 切手出力->1, それ以外->0 */
	char	 it,	/* 入力 */
	Status* st,	/* 状態 */
	int* a,		/* コインAの出力枚数 */
	int* b		/* コインBの出力枚数 */
);

/********************************************************
*	関数名： int main(void)				*
*	機能　： 自動販売機メインプログラム		*
*********************************************************/
int main(void) {
	int	s, a, b;
	char it;
	Status st = stEmpty;	/* 初期状態 		*/

	init();			/* I/O初期化		*/

	outfg = outcoin = 0;	/* コイン点滅なし。	*/
	do {
		it = sw_read();
		if (it == 0) continue;
		outfg = outcoin = 0;
		s = Transition(it, &st, &a, &b);
		DispStatus(status_bit[st]);
		if (a | b) outfg = 1;
		StampOut(s);
		if (a) DispCoinA(a);
		if (b) DispCoinB(b);
		while(it = sw_read()){	/*  スイッチ入力監視	*/
			if (it == Exit) break;
			timer(30);
		}
	} while (st != stExit);

	halt();
}
/********************************************************
*	関数名： int Transition(char it, ･････)		*
*	機能　： 状態遷移を遷移関数を使用し表現		*
*********************************************************/
int Transition (	/* 切手出力枚数*/
	char	 it,	/* 入力 */
	Status* st,	/* 状態 */
	int* a,		/* コインAの出力枚数 */
	int* b		/* コインBの出力枚数 */
) {
	*a = *b = 0;	/* コインA,Bの出力枚数を0にしておく */
	if (it == Exit) {
		*st = stExit;
	}
	if (it == Cancel) {
		*a = *st;
		*st = stEmpty;
	}
    if (it == CoinA) {
        ++*st;
        *st = *st % 2;
        if (!*st) {
            return 1;
        }else {
            return 0;
        }
    }
    if (it == CoinB) {
        *st += 5;
        *st = *st % 2;
        if (*st) {
            return 2;
        }else {
            return 3;
        }
    }
    return 0;
}
