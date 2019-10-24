/****************************************************************
*	stamp.c							*
*	EC3�@�w�������F30�~�؎莩���̔��@			*
*	�@�@�@�@�@�@   10�~�̂ݎg�p�\�A�J�ڊ֐��g�p��		*
*			 last update 2014/06/12 by ecstaff	*
*****************************************************************/
#include	"pic.h"		/* �w�b�_�E�t�@�C��		*/
#include	"def.h"		/* define�錾�ꗗ		*/
#include	"global.h"	/* �O���[�o���ϐ�		*/
#include	"extern.h"	/* �O���֐��ꗗ			*/

/* �R���t�B�M�����[�V�����E�r�b�g�̐ݒ�	*/
__CONFIG(FOSC_HS &	/* ���� �����E���U�� */
	 WDTE_OFF &	/* �E�H�b�`�h�b�O�E�^�C�} = OFF */
	 PWRTE_ON &	/* �p���[�A�b�v�E�^�C�} = ON */
	 MCLRE_ON &	/* RA5�s���̋@�\��Master Clear�ɐݒ� */
	 BOREN_OFF &	/* ��d�����Z�b�g = OFF */
	 LVP_OFF &	/* ��d���v���O���~���O = OFF */
	 CPD_OFF &	/* �f�[�^�E�R�[�h�E�v���e�N�g = OFF */
	 CP_OFF		/* �R�[�h�E�v���e�N�g = OFF */
);

/* �֐��v���g�^�C�v�錾 */
int Transition (	/* �؎�o��->1, ����ȊO->0 */
	char	 it,	/* ���� */
	Status* st,	/* ��� */
	int* a,		/* �R�C��A�̏o�͖��� */
	int* b		/* �R�C��B�̏o�͖��� */
);

/********************************************************
*	�֐����F int main(void)				*
*	�@�\�@�F �����̔��@���C���v���O����		*
*********************************************************/
int main(void) {
	int	s, a, b;
	char it;
	Status st = stEmpty;	/* ������� 		*/

	init();			/* I/O������		*/

	outfg = outcoin = 0;	/* �R�C���_�łȂ��B	*/
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
		while(it = sw_read()){	/*  �X�C�b�`���͊Ď�	*/
			if (it == Exit) break;
			timer(30);
		}
	} while (st != stExit);

	halt();
}
/********************************************************
*	�֐����F int Transition(char it, �����)		*
*	�@�\�@�F ��ԑJ�ڂ�J�ڊ֐����g�p���\��		*
*********************************************************/
int Transition (	/* �؎�o�͖���*/
	char	 it,	/* ���� */
	Status* st,	/* ��� */
	int* a,		/* �R�C��A�̏o�͖��� */
	int* b		/* �R�C��B�̏o�͖��� */
) {
	*a = *b = 0;	/* �R�C��A,B�̏o�͖�����0�ɂ��Ă��� */
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
