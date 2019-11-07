/********************************************************
*	def.h						*
*	define宣言一覧					*
*		last update 2004/07/01 by ecstaff	*
*********************************************************/
/*   LED表示	*/
#define	LED00	0x00
#define	LED10	0x01
#define	LED20	0x03
#define	LED30	0x07
#define	LED40	0x0f
#define	LED50	0x10
#define	LED60	0x11
#define	LED70	0x13
#define	LED80	0x17
#define	LED90	0x1f
#define	LED100	0x20
#define	LED110	0x21
#define	LED120	0x23
#define	LED130	0x27
#define	LED140	0x2f
#define	LED150	0x30
#define	LED160	0x31
#define	LED170	0x33
#define	LED180	0x37
#define	LED190	0x3f
#define	ALL_LED	0xff
#define	STAMP1	0x40
#define	STAMP2	0x80
#define	STPALL	0xc0

/* スイッチ入力	*/
#define	CoinA	0x01
#define	CoinB	0x02
#define CoinC	0x04
#define	Buy	0x08
#define	Cancel	0x10
#define	Exit	0x18

/* その他	*/
#define	MX_NCOIN	4
