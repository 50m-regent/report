/****************************************************************
*	global.h						*
*	�O���[�o���ϐ��ꗗ�@(�O���Q�Ɨp�w�b�_�t�@�C���j		*
*			 last update 2004/07/01 by ecstaff	*
*****************************************************************/

extern const	unsigned char	UPDATE;	/* LED�̍X�V����		*/
extern unsigned char	cnt;		/* cnt��LED�X�V�����p�J�E���^	*/
extern unsigned char	outfg;		/* �_�Ńt���O 1:�_�Ł@0:�_��	*/
extern unsigned char	outcoin;	/* �R�C���o�͏��		*/

typedef enum {
	stEmpty,	/* �� */
	stCoin1,	/* 10�~ */
	stCoin2,	/* 20�~ */
	stExit		/* �I�� */
} Status;

extern char red_led[];		/* ��LED�\�����	*/
extern char status_bit[];	/* �X�e�[�^�X�\���r�b�g	*/
