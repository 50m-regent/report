/****************************************************************
*	extern.h						*
*	���C�u�����֐��ꗗ�@(�O���Q�Ɨp�w�b�_�t�@�C���j		*
*			 last update 2004/07/01 by ecstaff	*
*****************************************************************/

/*---------------------------------+----------------------------*/
/*�@       �֐���		   +	    �֐��@�\		*/
/*---------------------------------+----------------------------*/
extern void init(void);			/* ���������[�`��	*/
extern void led_on(char bit1);		/* �w��r�b�gLED�_��	*/
extern void led_off(char bit1);		/* �w��r�b�gLED����	*/
extern char sw_read(void);		/* �X�C�b�`�Ǎ�		*/
extern void DispStatus(char bit1);	/* �X�e�[�^�X�pLED�_��	*/
extern void StampOut(int num);		/* �X�^���v�\��		*/
extern int DispCoinA(int num);		/* CoinA�pLED�_��	*/
extern int DispCoinB(int num);		/* CoinB�pLED�_��	*/
extern void timer(char i);		/* �^�C�}�[		*/
extern void halt(void);			/* LED�S�_���Ŗ������[�v*/
extern void interrupt isr(void);	/* �^�C�}���荞�݊֐�	*/
