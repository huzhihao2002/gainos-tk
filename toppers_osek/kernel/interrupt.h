/*
 *  TOPPERS/OSEK Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      OSEK Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004 by Witz Corporation, JAPAN
 * 
 *  Copyright (C) 2013 by Fan Wang(parai), China
 * 
 * The above copyright holders grant permission gratis to use,
 * duplicate, modify, or redistribute (hereafter called use) this
 * software (including the one made by modifying this software),
 * provided that the following four conditions (1) through (4) are
 * satisfied.
 * 
 * (1) When this software is used in the form of source code, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be retained in the source code without modification.
 *
 * (2) When this software is redistributed in the forms usable for the
 *    development of other software, such as in library form, the above
 *    copyright notice, this use conditions, and the disclaimer shown
 *    below must be shown without modification in the document provided
 *    with the redistributed software, such as the user manual.
 *
 * (3) When this software is redistributed in the forms unusable for the
 *    development of other software, such as the case when the software
 *    is embedded in a piece of equipment, either of the following two
 *    conditions must be satisfied:
 *
 *  (a) The above copyright notice, this use conditions, and the
 *      disclaimer shown below must be shown without modification in
 *      the document provided with the redistributed software, such as
 *      the user manual.
 *
 *  (b) How the software is to be redistributed must be reported to the
 *      TOPPERS Project according to the procedure described
 *      separately.
 *
 * (4) The above copyright holders and the TOPPERS Project are exempt
 *    from responsibility for any type of damage directly or indirectly
 *    caused from the use of this software and are indemnified by any
 *    users or end users of this software from any and all causes of
 *    action whatsoever.
 *
 * THIS SOFTWARE IS PROVIDED "AS IS." THE ABOVE COPYRIGHT HOLDERS AND
 * THE TOPPERS PROJECT DISCLAIM ANY EXPRESS OR IMPLIED WARRANTIES,
 * INCLUDING, BUT NOT LIMITED TO, ITS APPLICABILITY TO A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL THE ABOVE COPYRIGHT HOLDERS AND THE
 * TOPPERS PROJECT BE LIABLE FOR ANY TYPE OF DAMAGE DIRECTLY OR
 * INDIRECTLY CAUSED FROM THE USE OF THIS SOFTWARE.
 */

/*
 *	�����݊Ǘ��@�\
 */

#ifndef _INTERRUPT_H_
#define _INTERRUPT_H_

/*
 *  ISR�i�J�e�S��2�jID�̓���Ȓl�̒�`
 */
#define ISRID_NULL		((IsrType) UINT8_INVALID)	/* ����ID */

/*
 *  ISR�i�J�e�S��2�j����ێ�����ϐ��̐錾�ikernel_cfg.c�j
 */
extern const UINT8		tnum_isr2;			/* ISR�i�J�e�S��2�j�̐� */

/*
 *  ISR�i�J�e�S��2�j�������u���b�N�ikernel_cfg.c�j
 */
extern const Priority	isrinib_intpri[];	/* �����ݗD��x */

/*
 *  ISR�i�J�e�S��2�j�Ǘ��u���b�N�ikernel_cfg.c�j
 */
extern ResourceType		isrcb_lastres[];	/* �Ō�Ɋl���������\�[�X */

/*
 *  ISR�i�J�e�S��2�j�̍ō��D�惌�x���ikernel_cfg.c�j
 */
extern const IPL		ipl_maxisr2;

/*
 *  ���s����ISR�i�J�e�S��2�j
 *
 *  ISR�i�J�e�S��2�j�����s���Ă��Ȃ����́CISRID_NULL �ɂ���D
 */
extern IsrType		runisr;

/*
 *  SuspendAllInterrupts �̃l�X�g��
 */
extern UINT8		sus_all_cnt;	/* SuspendAllInterrupts �̃l�X�g�� */

/*
 *  �����݊Ǘ��@�\�̏�����
 */
extern void	interrupt_initialize(void);

#endif /* _INTERRUPT_H_ */