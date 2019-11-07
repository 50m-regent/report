/****************************************************************
*	extern.h						*
*	ライブラリ関数一覧　(外部参照用ヘッダファイル）		*
*			 last update 2004/07/01 by ecstaff	*
*****************************************************************/

/*---------------------------------+----------------------------*/
/*　       関数名		   +	    関数機能		*/
/*---------------------------------+----------------------------*/
extern void init(void);			/* 初期化ルーチン	*/
extern void led_on(char bit1);		/* 指定ビットLED点灯	*/
extern void led_off(char bit1);		/* 指定ビットLED消灯	*/
extern char sw_read(void);		/* スイッチ読込		*/
extern void DispStatus(char bit1);	/* ステータス用LED点灯	*/
extern void StampOut(int num);		/* スタンプ表示		*/
extern int DispCoinA(int num);		/* CoinA用LED点灯	*/
extern int DispCoinB(int num);		/* CoinB用LED点灯	*/
extern void timer(char i);		/* タイマー		*/
extern void halt(void);			/* LED全点灯で無限ループ*/
extern void interrupt isr(void);	/* タイマ割り込み関数	*/
