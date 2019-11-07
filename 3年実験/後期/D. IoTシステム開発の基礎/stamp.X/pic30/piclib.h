/********************************************************
*	piclib.h					*
*	ライブラリ関数一覧（プロトタイプ宣言用）	*
*		 last update 2004/07/01 by ecstaff	*
*********************************************************/

/*-------------------------+----------------------------*/
/*　       関数名	   +	    関数機能		*/
/*-------------------------+----------------------------*/

void init(void);		/* 初期化ルーチン	*/
void led_on(char bit1);		/* 指定ビットLED点灯	*/
void led_off(char bit1);	/* 指定ビットLED消灯	*/
char sw_read(void);		/* スイッチ読込		*/
void DispStatus(char bit1);	/* ステータス用LED点灯	*/
void StampOut(int num);		/* スタンプ表示		*/
int DispCoinA(int num);		/* CoinA用LED点灯	*/
int DispCoinB(int num);		/* CoinB用LED点灯	*/
void timer(char i);		/* タイマー		*/
void halt(void);		/* LED全点灯で無限ループ*/
void interrupt isr(void);	/* 割り込み関数		*/
