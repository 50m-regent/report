/********************************************************
*	piclib.h					*
*	���C�u�����֐��ꗗ�i�v���g�^�C�v�錾�p�j	*
*		 last update 2004/07/01 by ecstaff	*
*********************************************************/

/*-------------------------+----------------------------*/
/*�@       �֐���	   +	    �֐��@�\		*/
/*-------------------------+----------------------------*/

void init(void);		/* ���������[�`��	*/
void led_on(char bit1);		/* �w��r�b�gLED�_��	*/
void led_off(char bit1);	/* �w��r�b�gLED����	*/
char sw_read(void);		/* �X�C�b�`�Ǎ�		*/
void DispStatus(char bit1);	/* �X�e�[�^�X�pLED�_��	*/
void StampOut(int num);		/* �X�^���v�\��		*/
int DispCoinA(int num);		/* CoinA�pLED�_��	*/
int DispCoinB(int num);		/* CoinB�pLED�_��	*/
void timer(char i);		/* �^�C�}�[		*/
void halt(void);		/* LED�S�_���Ŗ������[�v*/
void interrupt isr(void);	/* ���荞�݊֐�		*/
