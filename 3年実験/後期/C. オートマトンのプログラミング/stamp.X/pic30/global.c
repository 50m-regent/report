/********************************************************
*	global.c					*
*	グローバル変数一覧				*
*		last update 2004/07/01 by ecstaff	*
*********************************************************/

#include	"def.h"

const	unsigned char	UPDATE = 9;	/* LEDの更新周期		*/
unsigned char	cnt = 1;		/* cntはLED更新周期用カウンタ	*/
unsigned char	outfg;			/* 点滅フラグ 1:点滅　0:点灯	*/
unsigned char	outcoin;		/* コイン出力状態		*/

//extern Status;

char	red_led[]= { LED00,LED10,LED20,LED30, LED40 /* 赤LED用ステータス */
	};

char status_bit[] = { LED00,		/* ステータス用ビット	*/
	LED10, LED20, LED30, LED40, LED50,
	LED60, LED70, LED80, LED90, LED100,
	LED110,LED120,LED130,LED140,LED150,
	LED160,LED170,LED180,LED190
};

void global(void);		/* 空関数プロトタイプ宣言	*/
void global(void)		/* 空関数			*/
{}
