/****************************************************************
*	global.h						*
*	グローバル変数一覧　(外部参照用ヘッダファイル）		*
*			 last update 2004/07/01 by ecstaff	*
*****************************************************************/

extern const	unsigned char	UPDATE;	/* LEDの更新周期		*/
extern unsigned char	cnt;		/* cntはLED更新周期用カウンタ	*/
extern unsigned char	outfg;		/* 点滅フラグ 1:点滅　0:点灯	*/
extern unsigned char	outcoin;	/* コイン出力状態		*/

typedef enum {
	stEmpty,	/* 空 */
	stCoin1,	/* 10円 */
	stCoin2,	/* 20円 */
	stExit		/* 終了 */
} Status;

extern char red_led[];		/* 赤LED表示状態	*/
extern char status_bit[];	/* ステータス表示ビット	*/
