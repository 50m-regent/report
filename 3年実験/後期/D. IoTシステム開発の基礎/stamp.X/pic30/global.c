/********************************************************
*	global.c					*
*	�O���[�o���ϐ��ꗗ				*
*		last update 2004/07/01 by ecstaff	*
*********************************************************/

#include	"def.h"

const	unsigned char	UPDATE = 9;	/* LED�̍X�V����		*/
unsigned char	cnt = 1;		/* cnt��LED�X�V�����p�J�E���^	*/
unsigned char	outfg;			/* �_�Ńt���O 1:�_�Ł@0:�_��	*/
unsigned char	outcoin;		/* �R�C���o�͏��		*/

//extern Status;

char	red_led[]= { LED00,LED10,LED20,LED30, LED40 /* ��LED�p�X�e�[�^�X */
	};

char status_bit[] = { LED00,		/* �X�e�[�^�X�p�r�b�g	*/
	LED10, LED20, LED30, LED40, LED50,
	LED60, LED70, LED80, LED90, LED100,
	LED110,LED120,LED130,LED140,LED150,
	LED160,LED170,LED180,LED190
};

void global(void);		/* ��֐��v���g�^�C�v�錾	*/
void global(void)		/* ��֐�			*/
{}
