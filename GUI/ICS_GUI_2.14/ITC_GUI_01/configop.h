/* wAccess can be one of the following */
#define ACE_ACCESS_MAXNUM   3       /* 3 access types supported */
#define ACE_ACCESS_CARD     0       /* ACE card running on W32 OS */
#define ACE_ACCESS_SIM      1       /* simulated memory */
#define ACE_ACCESS_USR      2       /* user defined memory location */

/* wMode parameter can be one of the following */
#define ACE_MODE_MASK       0x0FFF
#define ACE_MODE_MAXNUM     0x0008  /* 7 modes supported */
#define ACE_MODE_TEST       0x0000  /* self test mode */
#define ACE_MODE_BC         0x0001  /* 1553 bus controller mode */
#define ACE_MODE_RT         0x0002  /* 1553 remote terminal mode */
#define ACE_MODE_MT         0x0003  /* 1553 monitor terminal mode */
#define ACE_MODE_RTMT       0x0004  /* 1553 RT with monitoring */
#define ACE_MODE_MTI        0x0006  /* Flexcore MT Improved mode */
#define ACE_MODE_RTMTI      0x0007  /* Flexcore RTMT Improved mode */

/* ACEX Modes - Not all of these are needed, come back to this */
#define ACE_MODE_MRT        0x0008  /* MRT mode */
#define ACE_MODE_MRTMTI     0x000A  /* MRT/MTI Combination mode */
#define ACE_MODE_BCMTI      0x000C  /* BC/MTI Combination mode */

#define ACE_MODE_BCMRT      0x0010  /* BC/MRT Combination mode */
#define ACE_MODE_BCMRTMTI   0x0011  /* BC/MRT/MTI Combination mode */
#define ACE_MODE_ALL        0x0011  /* shortcut of BC/MRT/MTI Combination mode */

/* the following values can be or'd in to the selected mode */
#define ACE_OPTION_MASK     0xF000
#define ACE_NO_TT_RESET     0x1000  /* or'd in value to not reset TT */
#define ACE_ADVANCED_MODE   0x2000  /* or'd in value to run in adv mode */

/* Software states that the hardware can be in */
#define ACE_STATE_RESET     0       /* Not initialized */
#define ACE_STATE_READY     1       /* Initialized in mode of operation*/
#define ACE_STATE_RUN       2       /* ACE mode is running */

/* The different ways to address hardware. A0-A0-> Incrementing the
 * host address by 1 will access next word on the Mini-ACE. A1-A0->
 * Incrementing the host address by 2 will access the next word on
 * the Mini-ACE. A2-A0-> Incrementing the host address by 4 will
 * access the next word on the Mini-ACE.
 */
#define ACE_ADDRMODE_A0_A0  0
#define ACE_ADDRMODE_A1_A0  1
#define ACE_ADDRMODE_A2_A0  2

/* wTTRes parameter can be one of the following */
#define ACE_TT_2US          0       /* 2us Time Tag resolution */
#define ACE_TT_4US          1       /* 4us Time Tag resolution */
#define ACE_TT_8US          2       /* 8us Time Tag resolution */
#define ACE_TT_16US         3       /* 16us Time Tag resolution*/
#define ACE_TT_32US         4       /* 32us Time Tag resolution*/
#define ACE_TT_64US         5       /* 64us Time Tag resolution*/
#define ACE_TT_TEST         6       /* Test Time Tag clock */
#define ACE_TT_EXT          7       /* Use external TT clock */
#define ACE_TT_1US          8       /* 1us Time Tag resolution */
#define ACE_TT_500NS        9       /* 500ns Time Tag resolution */
#define ACE_TT_100NS        10      /* 100ns Time Tag resolution */
#define ACE_TT_TEST_CLK     11      /* Test Time Tag clock */

/* wRespTimeOut parameter can be one of the following */
#define ACE_RESPTIME_18US   0       /* 18.5us before reponse timout*/
#define ACE_RESPTIME_22US   1       /* 22.5us before reponse timout*/
#define ACE_RESPTIME_50US   2       /* 50.5us before reponse timout*/
#define ACE_RESPTIME_130US  3       /* 130us before reponse timout*/
#define ACE_RESPTIME_14US   4       /* 14us before reponse timout */

/* wClockIn parameter can be one of the following */
#define ACE_CLOCK_16MHZ     0       /* 16MHz clock input */
#define ACE_CLOCK_12MHZ     1       /* 12MHz clock input */
#define ACE_CLOCK_20MHZ     2       /* 20MHz clock input */
#define ACE_CLOCK_10MHZ     3       /* 10MHz clock input */

/* wLvlOrPulse parameter can be one of the following */
#define ACE_IRQ_PULSE       0       /* Pulse interrupts */
#define ACE_IRQ_LEVEL       1       /* Level mode interrupts */

/* Interrupt status queue header can be one of the following */
#define ACE_ISQ_MSG_NONMSG          0x0001

/* Message based */
#define ACE_ISQ_TX_TIMEOUT          0x8000
#define ACE_ISQ_ILL_LKUP            0x4000
#define ACE_ISQ_MT_DSTK_50P_ROVR    0x2000
#define ACE_ISQ_MT_DSTK_ROVER       0x1000
#define ACE_ISQ_RT_DSTK_50P_ROVR    0x0800
#define ACE_ISQ_RT_DSTK_ROVER       0x0400
#define ACE_ISQ_MT_CSTK_50P_ROVR    0x0200
#define ACE_ISQ_MT_CSTK_ROVR        0x0100
#define ACE_ISQ_RT_CSTK_50P_ROVR    0x0080
#define ACE_ISQ_RT_CSTK_ROVR        0x0040
#define ACE_ISQ_HNDSHK_FAIL         0x0020
#define ACE_ISQ_FMT_ERR             0x0010
#define ACE_ISQ_MCODE               0x0008
#define ACE_ISQ_SA_EOM              0x0004
#define ACE_ISQ_EOM                 0x0002

/* Non-Message Based */
#define ACE_ISQ_TIME_TAG            0x0010
#define ACE_ISQ_RT_ADDR_PAR         0x0008
#define ACE_ISQ_SELF_TEST           0x0004

/* RT_AUTO_BOOT information */
#define RT_AUTO_BOOT_MEM_OFFSET_WORD    0x6000
#define RT_AUTO_BOOT_MEM_SIZE_WORD      0x1000

#pragma once
class configop
{
public:
    configop(void);
    ~configop(void);
};

