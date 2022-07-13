#if 0   /* DDC original code */
/******************************************************************************
*
* Data Device Corporation
* 105 Wilbur Place
* Bohemia N.Y. 11716
*
* Filename: bcdemo.c
*
* AceXtreme 'C' Run Time Library Toolbox
*
* Copyright (c) 2010 Data Device Corporation
*
*******************************************************************************
* Non-Disclosure Statement
* ------------------------
* This software is the sole property of Data Device Corporation. All
* rights, title, ownership, or other interests in the software remain
* the property of Data Device Corporation. This software may be used
* in accordance with applicable licenses. Any unauthorized use,
* duplication, transmission, distribution, or disclosure is expressly
* forbidden.
*
* This non-disclosure statement may not be removed or modified without
* prior written consent of Data Device Corporation.
*******************************************************************************
* Module Description:
*
*   This application runs the device in BC mode. It shows how the user can
*   operate the BC in a basic operation. It allows the user to output the
*   stack in raw or decoded(text) format.
*
*   Function used in this example:
*
*       aceInitialize
*       aceFree
*       aceGetLibVersion
*       aceErrorStr
*       aceGetMsgTypeString
*       aceCmdWordParse
*       aceGetBSWErrString
*       aceBCGetHBufMsgDecoded
*       aceBCGetHBufMsgRaw
*       aceDataBlkCreate
*       aceBCMsgCreateBCtoRT
*       aceBCMsgCreateRTtoBC
*       aceBCMsgCreateRTtoRT
*       aceBCOpCodeCreate
*       aceBCFrameCreate
*       aceBCInstallHBuf
*       aceBCStart
*       aceBCStop
******************************************************************************/

/* Include Files */
#ifdef WIN32
#include <windows.h>
#include <conio.h>
#endif

#include "stdemace.h"


/* define data blocks */
#define DBLK1   1

/* define message constants */
#define MSG1    1

/* define opcodes */
#define OP1     1
#define OP2     2

/* define frame constants */
#define MNR1    1
#define MJR     2

/* User input */
static S16BIT DevNum = 0x0000;              /* Logical Device 0 */
static U32BIT u32BusSelection = 1;          /* Bus A */
static S16BIT wDisplaySelection = 0x0002;   /* Decoded */



/*******************************************************************************
 * Name:    PrintHeader
 *
 * Description:
 *
 *      Prints the sample program header.
 *
 * In   none
 * Out  none
 ******************************************************************************/
static void PrintHeader
(
    void
)
{
    U16BIT wLibVer;

    wLibVer = aceGetLibVersion();

    printf("*********************************************\n");
    printf("AceXtreme Integrated 1553 Terminal          *\n");
    printf("BU-69092 1553 Runtime Library               *\n");
    printf("Release Rev %d.%d.%d                           *\n",
        (wLibVer >> 8),          /* Major*/
        (wLibVer & 0xF0) >> 4,   /* Minor*/
        (wLibVer & 0xF));        /* Devel*/

    if ((wLibVer & 0xF) != 0)
    {
        printf("=-=-=-=-=-=-=-INTERIM VERSION-=-=-=-=-=-=-=-*\n");
    }

    printf("Copyright (c) 2010 Data Device Corporation  *\n");
    printf("*********************************************\n");
    printf("BCDemo.c BC operations [Basic Op Demo]      *\n");
    printf("*********************************************\n\n");

    printf("   This program will send 20 messages to RT1/SA1.\n");
    printf("   Each message has 10 data words:\n");
    printf("      0x1111, 0x2222, 0x3333, 0x4444, 0x1111\n");
    printf("      0x2222, 0x3333, 0x4444, 0x1111, 0x2222\n");
    printf("\n");
    printf("   After the BC finishes sending, the messages\n");
    printf("   are read out from the host buffer and either\n");
    printf("   shown on the display in decoded format or\n");
    printf("   saved as raw data to a file.\n");
}

/*******************************************************************************
 * Name:    PrintOutError
 *
 * Description:
 *
 *      This function prints out errors returned from library functions.
 *
 * In   result - the error number
 * Out  none
 ******************************************************************************/
static void PrintOutError
(
    S16BIT nResult
)
{
    char buf[80];
    aceErrorStr(nResult, buf, 80);
    printf("RTL Function Failure-> %s.\n", buf);
}

/*******************************************************************************
 * Name:    DisplayDecodedMsg
 *
 * Description:
 *
 *      This function displays the information of a MSGSTRUCT to the screen.
 *
 * In   nMsgNum     Number of the message
 * In   pMsg        Relavant information of the message
 * Out  none
 ******************************************************************************/
static void DisplayDecodedMsg
(
    S16BIT nMsgNum,
    MSGSTRUCT *pMsg
)
{
    U16BIT i;
    char szBuffer[100];
    U16BIT wRT, wTR1, wTR2, wSA, wWC;

    /* Display message header info */
    printf("MSG #%04d.  TIME = %08dus    BUS %c   TYPE%d: %s ", nMsgNum,
        pMsg->wTimeTag * 2, pMsg->wBlkSts & ACE_MT_BSW_CHNL ? 'B' : 'A',
        pMsg->wType, aceGetMsgTypeString(pMsg->wType));

    /* Display command word info */
    aceCmdWordParse(pMsg->wCmdWrd1, &wRT, &wTR1, &wSA, &wWC);
    sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR1 ? 'T' : 'R', wSA, wWC);
    printf("\n            CMD1 %04X --> %s", pMsg->wCmdWrd1, szBuffer);

    if (pMsg->wCmdWrd2Flg)
    {
        aceCmdWordParse(pMsg->wCmdWrd2, &wRT, &wTR2, &wSA, &wWC);
        sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR2 ? 'T' : 'R', wSA, wWC);
        printf("\n        CMD2 %04X --> %s", pMsg->wCmdWrd2, szBuffer);
    }

    /* Display transmit status words */
    if ((wTR1 == 1) || (pMsg->wBlkSts & ACE_MT_BSW_RTRT))
    {
        if (pMsg->wStsWrd1Flg)
        {
            printf("\n            STA1 %04X", pMsg->wStsWrd1);
        }
    }

    /* Display Data words */
    for (i = 0; i < pMsg->wWordCount; i++)
    {
        if (i == 0)
        {
            printf("\n            DATA ");
        }

        printf("%04X  ", pMsg->aDataWrds[i]);

        if ((i % 8) == 7)
        {
            printf("\n                 ");
        }
    }

    /* Display receive status words */
    if ((wTR1 == 0) && !(pMsg->wBlkSts & ACE_MT_BSW_RTRT))
    {
        if (pMsg->wStsWrd1Flg)
        {
            printf("\n            STA1 %04X", pMsg->wStsWrd1);
        }
    }

    if (pMsg->wStsWrd2Flg)
    {
        printf("\n            STA2 %04X", pMsg->wStsWrd2);
    }

    /* Display Error information */
    if (pMsg->wBlkSts & ACE_MT_BSW_ERRFLG)
    {
        printf("\n ERROR: %s", aceGetBSWErrString(ACE_MODE_MT, pMsg->wBlkSts));
    }

    printf("\n\n");
}

#if DDC_SAMPLE_FILE_IO
/*******************************************************************************
 * Name:    OutputDecodedMsg
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE.
 *
 * In   DevNum      Device number of the hardware to be accessed.
 * In   pFileName   Pointer to a null terminated string containing file name
 * Out  none
 ******************************************************************************/
static void OutputDecodedMsg
(
    U32BIT nMsgNum,
    MSGSTRUCT *pMsg,
    FILE *pFile
)
{
    U16BIT i;
    char szBuffer[100];
    U16BIT wRT, wTR1, wTR2, wSA, wWC;

    /* Display message header info */
    fprintf(pFile, "MSG #%04d.  TIME = %08dus    BUS %c   TYPE%d: %s ",
        (int)nMsgNum, pMsg->wTimeTag * 2, pMsg->wBlkSts & ACE_BC_BSW_CHNL ? 'B' : 'A',
        pMsg->wType, aceGetMsgTypeString(pMsg->wType));

    /* Display command word info */
    aceCmdWordParse(pMsg->wCmdWrd1, &wRT, &wTR1, &wSA, &wWC);
    sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR1 ? 'T' : 'R', wSA, wWC);
    fprintf(pFile, "\n            CMD1 %04X --> %s", pMsg->wCmdWrd1, szBuffer);

    if (pMsg->wCmdWrd2Flg)
    {
        aceCmdWordParse(pMsg->wCmdWrd2, &wRT, &wTR2, &wSA, &wWC);
        sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR2 ? 'T' : 'R', wSA, wWC);
        fprintf(pFile, "\n            CMD2 %04X --> %s", pMsg->wCmdWrd2, szBuffer);
    }

    /* Display transmit status words */
    if ((wTR1 == 1) || (pMsg->wBCCtrlWrd & ACE_BCCTRL_RT_TO_RT))
    {
        if (pMsg->wStsWrd1Flg)
        {
            fprintf(pFile, "\n            STA1 %04X", pMsg->wStsWrd1);
        }
    }

    /* Display Data words */
    for (i = 0; i < pMsg->wWordCount; i++)
    {
        if (i == 0)
        {
            fprintf(pFile, "\n            DATA ");
        }

        fprintf(pFile, "%04X  ", pMsg->aDataWrds[i]);

        if ((i % 8) == 7)
        {
            fprintf(pFile, "\n                 ");
        }
    }

    /* Display receive status words */
    if ((wTR1 == 0) && !(pMsg->wBCCtrlWrd & ACE_BCCTRL_RT_TO_RT))
    {
        if (pMsg->wStsWrd1Flg)
        {
            fprintf(pFile, "\n            STA1 %04X", pMsg->wStsWrd1);
        }
    }

    if (pMsg->wStsWrd2Flg)
    {
        fprintf(pFile, "\n            STA2 %04X", pMsg->wStsWrd2);
    }

    /* Display Error information */
    if (pMsg->wBlkSts & 0x170f)
    {
        fprintf(pFile, "\n ERROR: %s", aceGetBSWErrString(ACE_MODE_BC, pMsg->wBlkSts));
    }

    fprintf(pFile, "\n---------------------------------------------------------\n");

}
#endif /* DDC_SAMPLE_FILE_IO */


/*******************************************************************************
 * Name:    GetBCHBufRawMsgs
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE and outputs to a file.
 *
 * In   DevNum - the device number of the hardware to be accessed
 * Out  none
 ******************************************************************************/
static void GetBCHBufRawMsgs
(
    S16BIT DevNum
)
{
    /* Variables */
#if DDC_SAMPLE_FILE_IO
    FILE *pFile = NULL;
    U16BIT i = 0x0000;
#endif /* DDC_SAMPLE_FILE_IO */


    U16BIT wMsgCount = 0x0000;
    U32BIT dwMsgCount = 0x00000000;
    U32BIT dwMsgLost = 0x00000000;
    U32BIT dwPrevCount = 0x00000000;
    U32BIT dwCurCount = 0x00000000;
    U16BIT wRepeatCount = 20;

    U16BIT wBuffer[64] =
    {
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    };

#if DDC_SAMPLE_FILE_IO
    /* Open file */
    pFile = fopen("bcstack.bin", "wb+");
#endif /* DDC_SAMPLE_FILE_IO */

    printf("\n** The BC will now send %d messages", wRepeatCount);

    /* Start BC */
    aceBCStart(DevNum, MJR, wRepeatCount);

    /* Run Information */
    printf("\n** BC Device Number %d, outputting to 'bcstack.bin', press <ENTER> to stop **\n\n", DevNum);

    ddcPressAKey("Press a key to continue");
    printf("\n\n");

#if DDC_SAMPLE_USER_INPUT
    while (!kbhit())
#else
    while (dwMsgCount < wRepeatCount)
#endif /* DDC_SAMPLE_USER_INPUT */
    {
        /* Check host buffer for msgs */
        aceBCGetHBufMsgsRaw(DevNum, wBuffer, ACE_MSGSIZE_BC, &dwMsgCount, &dwMsgLost);

        /* Msg found */
        if (dwMsgCount)
        {
            dwPrevCount += dwMsgLost;
            dwCurCount += dwMsgCount;

#if DDC_SAMPLE_FILE_IO
            for (i = 0; dwPrevCount < dwCurCount; dwPrevCount++, i++)
            {
                fwrite(&wBuffer[i * ACE_MSGSIZE_BC], 84, 1, pFile);
            }
#endif /* DDC_SAMPLE_FILE_IO */

            printf("BC: Total msgs captured: %d                  \r", (int)(dwCurCount + dwMsgLost));

            wMsgCount++;
        }

        DDC_MSLEEP(1);
    }

#if DDC_SAMPLE_FILE_IO
    /* Close out of file */
    fclose(pFile);
#endif /* DDC_SAMPLE_FILE_IO */

    /* Stop BC */
    aceBCStop(DevNum);

    printf("\n");
}

/*******************************************************************************
 * Name:    GetBCHBufDecodedMsgs
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE and outputs to a file.
 *
 * In   DevNum - the device number of the hardware to be accessed.
 * Out  none
 ******************************************************************************/
static void GetBCHBufDecodedMsgs
(
    S16BIT DevNum
)
{
#if DDC_SAMPLE_FILE_IO
    FILE *pFile = NULL;
#endif /* DDC_SAMPLE_FILE_IO */

    S16BIT nResult = 0x0000;
    U32BIT dwHBufLost = 0x00000000;
    U32BIT dwMsgCount = 0x00000000;
    U32BIT dwCurCount = 0x00000000;
    U16BIT wRepeatCount = 20;
    MSGSTRUCT sMsg;

#if DDC_SAMPLE_FILE_IO
    /* Open file */
    pFile = fopen("bcstack.txt", "w");
#endif /* DDC_SAMPLE_FILE_IO */

    printf("\n** The BC will now send %d messages", wRepeatCount);

    /* Start BC */
    aceBCStart(DevNum, MJR, wRepeatCount);

    /* Run Information */
    printf("\n** BC Device Number %d, outputting to 'bcstack.txt', press <ENTER> to stop **\n\n", DevNum);

    printf("** Messages will also be output to the screen\n");

    ddcPressAKey("Press a key to continue");
    printf("\n\n");

#if DDC_SAMPLE_USER_INPUT
    while (!kbhit())
#else
    while (dwCurCount < wRepeatCount)
#endif /* DDC_SAMPLE_USER_INPUT */
    {
        /* Check host buffer for msgs */
        nResult = aceBCGetHBufMsgDecoded(DevNum, &sMsg, &dwMsgCount, &dwHBufLost, ACE_BC_MSGLOC_NEXT_PURGE);

        if (nResult)
        {
            printf("Error reading host buffer\n");
        }

        /* Display msg lost count */
        if (dwHBufLost > 0)
        {
            printf("Number of msgs lost %u\n", (int)dwHBufLost);
        }

        /* Message found */
        if (dwMsgCount)
        {
            ++dwCurCount;

#if DDC_SAMPLE_FILE_IO
            OutputDecodedMsg(dwCurCount, &sMsg, pFile);
#endif /* DDC_SAMPLE_FILE_IO */

            printf("BC: Total msgs captured: %d                \r", (int)dwCurCount);
            DisplayDecodedMsg((U16BIT)dwCurCount, &sMsg);
        }

        DDC_MSLEEP(1);
    }

#if DDC_SAMPLE_FILE_IO
    /* Close out of file */
    fclose(pFile);
#endif /* DDC_SAMPLE_FILE_IO */

    /* Stop BC */
    aceBCStop(DevNum);

    printf("\n");
}

/*******************************************************************************
 * Name: main
 *
 * Description:
 *
 *      Program entry point.
 *
 * In   none
 * Out  none
 ******************************************************************************/
#ifndef VX_WORKS
int main
(
    void
)
#else

/* ========================================================================== */
/* ========================================================================== */
int bcdemo
(
    void
)
#endif
{
    /* Variables */
    S16BIT wResult = 0x0000;
    S16BIT aOpCodes[10] = { 0x0000 };

    U16BIT wBuffer[64] =
    {
        0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
        0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
        0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
        0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444
    };

#ifdef WIN32
    DDC_HANDLE hConsole = NULL;

    /* Setup Windows Console Screen */
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("DDC Enhanced Mini-ACE RTL [BCDemo.c - Console App BC (Basic Operations) Demo]");
#endif

    /* Print out sample header */
    PrintHeader();

    /* Get Logical Device # */
    printf("\nSelect BC Logical Device Number (0-31):\n");
    printf("> ");

#if DDC_SAMPLE_USER_INPUT
    scanf("%hd", &DevNum);
#else
    DevNum = 0;
    printf("%d", DevNum);
#endif /* DDC_SAMPLE_USER_INPUT */

    /* Get Logical Device # */
    printf("\nSelect 1 For Bus A or 2 for Bus B\n");
    printf("> ");

#if DDC_SAMPLE_USER_INPUT
    scanf("%d", &u32BusSelection);
#else
    u32BusSelection = 1;          /* Bus A */
    printf("%d", u32BusSelection);
#endif /* DDC_SAMPLE_USER_INPUT */

    /* Initialize Device */
    wResult = aceInitialize(DevNum, ACE_ACCESS_CARD, ACE_MODE_BC, 0, 0, 0);

    if (wResult)
    {
        printf("Initialize ");
        PrintOutError(wResult);
        ddcPressAKey("Press a key to continue");
        return 0;
    }

    /* Create 3 data blocks */
    aceBCDataBlkCreate(DevNum, DBLK1, 32, wBuffer, 32);

    if (u32BusSelection == 1)
    {
        u32BusSelection = ACE_BCCTRL_CHL_A;
    }
    else
    {
        u32BusSelection = ACE_BCCTRL_CHL_B;
    }

    /* Create message block */
    aceBCMsgCreateBCtoRT(
        DevNum,              /* Device number                    */
        MSG1,                /* Message ID to create             */
        DBLK1,               /* Message will use this data block */
        1,                   /* RT address                       */
        1,                   /* RT subaddress                    */
        10,                  /* Word count                       */
        0,                   /* Default message timer            */
        u32BusSelection);   /* use chl A options                */

    /* Create XEQ opcode that will use msg block */
    aceBCOpCodeCreate(DevNum, OP1, ACE_OPCODE_XEQ, ACE_CNDTST_ALWAYS, MSG1, 0, 0);

    /* Create CAL opcode that will call mnr frame from major */
    aceBCOpCodeCreate(DevNum, OP2, ACE_OPCODE_CAL, ACE_CNDTST_ALWAYS, MNR1, 0, 0);

    /* Create Minor Frame */
    aOpCodes[0] = OP1;
    aceBCFrameCreate(DevNum, MNR1, ACE_FRAME_MINOR, aOpCodes, 1, 0, 0);

    /* Create Major Frame */
    aOpCodes[0] = OP2;
    aceBCFrameCreate(DevNum, MJR, ACE_FRAME_MAJOR, aOpCodes, 1, 1000, 0);

    /* Create Host Buffer */
    aceBCInstallHBuf(DevNum, 16 * 1024);

    /* Display messages as Raw or Decoded Formats */
    printf("\nWould you like messages displayed as:\n");
    printf("1. Raw\n");
    printf("2. Decoded\n");
    printf(">  ");

#if DDC_SAMPLE_USER_INPUT
    scanf("%hd", &wDisplaySelection);
#else
    wDisplaySelection = 2;   /* Decoded */
    printf("%d", wDisplaySelection);
#endif /* DDC_SAMPLE_USER_INPUT */

    switch (wDisplaySelection)
    {
        case 1:
        {
            GetBCHBufRawMsgs(DevNum);
            break;
        }

        default:
        {
            GetBCHBufDecodedMsgs(DevNum);
            break;
        }
    }

    /* Free all resources */
    wResult = aceFree(DevNum);
    if (wResult)
    {
        printf("Free ");
        PrintOutError(wResult);
        return 0;
    }

    /* Pause before program exit */
    ddcPressAKey("Press a key to exit");

    return 0;
}
#endif



////////////////////////////////////////////////
// BC 메시지 스케줄링 실습 I .
////////////////////////////////////////////////
#if 0
/* Include Files */
#ifdef WIN32
#include <windows.h>
#include "stdemace.h"
#include <conio.h>
#endif

#ifdef LINUX
#include "stdemace.h"
//#include "../linuxutil.h"
#endif

#ifdef VX_WORKS
#include "../LibPrj/include/stdemace.h"
#include "../utils/vxwrksuti.h"
#endif

#ifdef INTEGRITY
#include "../Integrity_Samples.h"
#endif
/*
#include <mmsystem.h>  
#pragma comment(lib,"winmm.lib")  
*/
HANDLE hSemaphoreSync;
HANDLE hThreadMission;
//MMRESULT hTimer;


/* define data blocks */
#define DBLK1   1
#define DBLK2   2
#define DBLK3   3
#define DBLK4   4
#define DBLK5   5

/* define message constants */
#define MSG1    1
#define MSG2    2
#define MSG3    3
#define MSG4    4
#define MSG5    5

/* define opcodes */
#define OP1     1
#define OP2     2
#define OP3     3
#define OP4     4
#define OP5     5
#define OP6     6
#define OP7     7
#define OP8     8
#define OP_USR     1004

/* define frame constants */
#define MNR1    1
#define MNR2    2
#define MNR3    3
#define MNR4    4
#define MJR	5


S16BIT g_DevNum;
U32BIT TX_DATA;


//////////////////////////////////////////////////////////////////////////////////////////////
void cmOutputUpdate(DevNum)
{
	 U16BIT index;//, checksum=0;
	 S16BIT wResult;
   	 U16BIT xwBuffer[32] = { 0x0000 };
	 
	U16BIT rBuffer[32];


	 TX_DATA++;
	 if(TX_DATA>0xffff)
	 	TX_DATA = 0;

	#if 0
	checksum =0;
			
	for(index=0;index<31;index++)	
	{
		xwBuffer[index] =TX_DATA;
		checksum += xwBuffer[index];	

	}	
	xwBuffer[31] = checksum;
	 
	/* Write Data to TX Address */
	wResult = aceBCDataBlkWrite(g_DevNum, DBLK2, xwBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkWrite_1");
	}	
	//else
		//printf("[%04x] ", TX_DATA);
	#endif
	
			
	for(index=0;index<31;index++)	
	{
		xwBuffer[index] = (TX_DATA + index);
	}
	
	/* Write Data to TX Address */
#if 0	
	wResult = aceBCDataBlkWrite(g_DevNum, DBLK1, xwBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkWrite_1\n ");
	}	

	wResult = aceBCDataBlkRead(g_DevNum, DBLK1, rBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkRead_1\n ");
	}	

	
	for (index=0; index<10; index++)
	{		
	        if(index==0)
	            printf("\n DataBlkRead_1  ");

	        printf("%04X  ", rBuffer[index]);

	        if((index%8)==7)
	             printf("\n                ");	
	}		
#endif		

	wResult = aceBCDataBlkWrite(g_DevNum, DBLK2, xwBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkWrite_2\n ");
	}	
	
	wResult = aceBCDataBlkWrite(g_DevNum, DBLK5, xwBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkWrite_3\n ");
	}	
		
}

/*******************************************************************************
 * Name:    PressAKey
 *
 * Description:
 *
 *      Allows application to pause to allow screen contents to be read.
 *
 * In   none
 * Out  none
 ******************************************************************************/
static void PressAKey()
{
    /* flush input buffer */
    while (kbhit())
    {
        getchar();
    }

    printf("\nPress <ENTER> to continue...");

    /* flush the output buffer */
    fflush(stdout);

    while (!kbhit())
    {
        /* wait for keypress... */
        Sleep(10);
    }

    /* flush input buffer */
    while (kbhit())
    {
        getchar();
    }
}

/*******************************************************************************
 * Name:    PrintHeader
 *
 * Description:
 *
 *      Prints the sample program header.
 *
 * In   none
 * Out  none
 ******************************************************************************/
static void PrintHeader(void)
{
    U16BIT wLibVer;

    wLibVer = aceGetLibVersion();

    printf("*********************************************\n");
    printf("AceXtreme Integrated 1553 Terminal          *\n");
    printf("BU-69092 1553 Runtime Library               *\n");
    printf("Release Rev %d.%d.%d                           *\n",
            (wLibVer>>8),        /* Major*/
            (wLibVer&0xF0)>>4,   /* Minor*/
            (wLibVer&0xF));      /* Devel*/

    if ((wLibVer&0xF)!=0)
        printf("=-=-=-=-=-=-=-INTERIM VERSION-=-=-=-=-=-=-=-*\n");

    printf("Copyright (c) 2010 Data Device Corporation  *\n");
    printf("*********************************************\n");
    printf("BCDemo.c BC operations [Basic Op Demo]      *\n");
    printf("*********************************************\n\n");

  
    printf("   FAE_CWJ \n");
}

/*******************************************************************************
 * Name:    PrintOutError
 *
 * Description:
 *
 *      This function prints out errors returned from library functions.
 *
 * In   result - the error number
 * Out  none
 ******************************************************************************/
static void PrintOutError(S16BIT nResult)
{
   char buf[80];
   aceErrorStr(nResult,buf,80);
   printf("RTL Function Failure-> %s.\n",buf);
}

/*******************************************************************************
 * Name:    DisplayDecodedMsg
 *
 * Description:
 *
 *      This function displays the information of a MSGSTRUCT to the screen.
 *
 * In   nMsgNum     Number of the message
 * In   pMsg        Relavant information of the message
 * Out  none
 ******************************************************************************/
static void DisplayDecodedMsg(S16BIT nMsgNum,MSGSTRUCT *pMsg)
{
    U16BIT i;
    char szBuffer[100];
    U16BIT wRT, wTR1, wTR2, wSA, wWC;

    /* Display message header info */
    printf("MSG #%04d.  TIME = %08dus    BUS %c   TYPE%d: %s ", nMsgNum,
        pMsg->wTimeTag * 2, pMsg->wBlkSts & ACE_MT_BSW_CHNL ? 'B' : 'A',
        pMsg->wType, aceGetMsgTypeString(pMsg->wType));

    /* Display command word info */
    aceCmdWordParse(pMsg->wCmdWrd1, &wRT, &wTR1, &wSA, &wWC);
    sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR1 ? 'T' : 'R', wSA, wWC);
    printf("\n            CMD1 %04X --> %s", pMsg->wCmdWrd1, szBuffer);

    if (pMsg->wCmdWrd2Flg)
    {
        aceCmdWordParse(pMsg->wCmdWrd2, &wRT, &wTR2, &wSA, &wWC);
        sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR2 ? 'T' : 'R', wSA, wWC);
        printf("\n        CMD2 %04X --> %s", pMsg->wCmdWrd2, szBuffer);
    }

    /* Display transmit status words */
    if ((wTR1 == 1) || (pMsg->wBlkSts & ACE_MT_BSW_RTRT))
    {
        if (pMsg->wStsWrd1Flg)
        {
            printf("\n            STA1 %04X", pMsg->wStsWrd1);
        }
    }

    /* Display Data words */
    for (i = 0; i < pMsg->wWordCount; i++)
    {
        if (i == 0)
        {
            printf("\n            DATA ");
        }

        printf("%04X  ", pMsg->aDataWrds[i]);

        if ((i % 8) == 7)
        {
            printf("\n                 ");
        }
    }

    /* Display receive status words */
    if ((wTR1 == 0) && !(pMsg->wBlkSts & ACE_MT_BSW_RTRT))
    {
        if (pMsg->wStsWrd1Flg)
        {
            printf("\n            STA1 %04X", pMsg->wStsWrd1);
        }
    }

    if (pMsg->wStsWrd2Flg)
    {
        printf("\n            STA2 %04X", pMsg->wStsWrd2);
    }

    /* Display Error information */
    if (pMsg->wBlkSts & ACE_MT_BSW_ERRFLG)
    {
        printf("\n ERROR: %s", aceGetBSWErrString(ACE_MODE_MT, pMsg->wBlkSts));
    }

    printf("\n\n");
}

/*******************************************************************************
 * Name:    OutputDecodedMsg
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE.
 *
 * In   DevNum      Device number of the hardware to be accessed.
 * In   pFileName   Pointer to a null terminated string containing file name
 * Out  none
 ******************************************************************************/
static void OutputDecodedMsg(U32BIT nMsgNum,MSGSTRUCT *pMsg,FILE *pFile)
{
    U16BIT i;
    char szBuffer[100];
    U16BIT wRT,wTR1,wTR2,wSA,wWC;

    /* Display message header info */
    fprintf(pFile,"MSG #%04d.  TIME = %08dus    BUS %c   TYPE%d: %s ",
        (int)nMsgNum,pMsg->wTimeTag*2,pMsg->wBlkSts&ACE_BC_BSW_CHNL?'B':'A',
        pMsg->wType, aceGetMsgTypeString(pMsg->wType));

    /* Display command word info */
    aceCmdWordParse(pMsg->wCmdWrd1,&wRT,&wTR1,&wSA,&wWC);
    sprintf(szBuffer,"%02d-%c-%02d-%02d",wRT,wTR1?'T':'R',wSA,wWC);
    fprintf(pFile,"\n            CMD1 %04X --> %s",pMsg->wCmdWrd1,szBuffer);

    if(pMsg->wCmdWrd2Flg)
    {
        aceCmdWordParse(pMsg->wCmdWrd2,&wRT,&wTR2,&wSA,&wWC);
        sprintf(szBuffer,"%02d-%c-%02d-%02d",wRT,wTR2?'T':'R',wSA,wWC);
        fprintf(pFile,"\n            CMD2 %04X --> %s",pMsg->wCmdWrd2,szBuffer);
   }

    /* Display transmit status words */
    if((wTR1==1) || (pMsg->wBCCtrlWrd&ACE_BCCTRL_RT_TO_RT))
    {
        if(pMsg->wStsWrd1Flg)
            fprintf(pFile,"\n            STA1 %04X",pMsg->wStsWrd1);
    }

    /* Display Data words */
    for(i=0; i<pMsg->wWordCount; i++)
    {
        if(i==0)
            fprintf(pFile,"\n            DATA ");

        fprintf(pFile,"%04X  ",pMsg->aDataWrds[i]);

        if((i%8)==7)
            fprintf(pFile,"\n                 ");
   }

    /* Display receive status words */
    if((wTR1==0)  && !(pMsg->wBCCtrlWrd&ACE_BCCTRL_RT_TO_RT))
    {
        if(pMsg->wStsWrd1Flg)
            fprintf(pFile,"\n            STA1 %04X",pMsg->wStsWrd1);
    }

    if(pMsg->wStsWrd2Flg)
        fprintf(pFile,"\n            STA2 %04X",pMsg->wStsWrd2);

    /* Display Error information */
    if(pMsg->wBlkSts & 0x170f)
        fprintf(pFile, "\n ERROR: %s",aceGetBSWErrString(ACE_MODE_BC,pMsg->wBlkSts));

    fprintf(pFile,"\n---------------------------------------------------------\n");
}

/*******************************************************************************
 * Name:    GetBCHBufRawMsgs
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE and outputs to a file.
 *
 * In   DevNum - the device number of the hardware to be accessed
 * Out  none
 ******************************************************************************/
static void GetBCHBufRawMsgs(S16BIT DevNum)
{
   /* Variables */
#ifdef INTEGRITY
    Task kbhit_task;
#else
   FILE *pFile = NULL;
   U16BIT i =  0x0000;
#endif

    U16BIT wMsgCount    = 0x0000;
    U32BIT dwMsgCount   = 0x00000000;
    U32BIT dwMsgLost    = 0x00000000;
    U32BIT dwPrevCount  = 0x00000000;
    U32BIT dwCurCount   = 0x00000000;
    U16BIT wRepeatCount = 20;

    U16BIT wBuffer[64] =
    {
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    };

#ifndef INTEGRITY
    /* Open file */
    pFile = fopen("bcstack.bin","wb+");
#endif

    printf("\n** The BC will now send %d messages",wRepeatCount);

    /* Start BC */
    aceBCStart(DevNum,MJR,wRepeatCount);

    /* Run Information */
    printf("\n** BC Device Number %d, outputting to 'bcstack.bin', press <ENTER> to stop **\n\n", DevNum);

    PressAKey();
    printf("\n\n");

#ifdef INTEGRITY
    CreateProtectedTask(1,(Address)kbhit_task_func,0x1000,"kbhit", &kbhit_task);
    RunTask(kbhit_task);
#endif

    while(!kbhit())
    {
        /* Check host buffer for msgs */
        aceBCGetHBufMsgsRaw(DevNum,wBuffer,ACE_MSGSIZE_BC,&dwMsgCount,&dwMsgLost);

        /* Msg found */
        if(dwMsgCount)
        {
            dwPrevCount += dwMsgLost;
            dwCurCount += dwMsgCount;

#ifndef INTEGRITY
            for(i=0; dwPrevCount<dwCurCount; dwPrevCount++,i++)
            {
                fwrite(&wBuffer[i*ACE_MSGSIZE_BC], 84, 1, pFile);
            }
#endif

            printf("BC: Total msgs captured: %d                  \r", (int)(dwCurCount+dwMsgLost));

            wMsgCount++;
        }

       // Sleep(1);
    }

    /* Throw away key */
    getch();

#ifndef INTEGRITY
    /* Close out of file */
    fclose(pFile);
#endif

    /* Stop BC */
    aceBCStop(DevNum);

    printf("\n");
}

/*******************************************************************************
 * Name:    GetBCHBufDecodedMsgs
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE and outputs to a file.
 *
 * In   DevNum - the device number of the hardware to be accessed.
 * Out  none
 ******************************************************************************/
static void GetBCHBufDecodedMsgs(S16BIT DevNum)
{
#ifdef INTEGRITY
    Task kbhit_task;
#else
    FILE *pFile = NULL;
#endif
    S16BIT nResult      = 0x0000;
    U32BIT dwHBufLost   = 0x00000000;
    U32BIT dwMsgCount   = 0x00000000;
    U32BIT dwCurCount   = 0x00000000;
    U16BIT wRepeatCount = 5; // -1 : forever
    MSGSTRUCT sMsg;

#ifndef INTEGRITY
    /* Open file */
    pFile = fopen("bcstack.txt","w");
#endif

    printf("\n** The BC will now send %d messages",wRepeatCount);

    /* Start BC */
    aceBCStart(DevNum,MJR,wRepeatCount);

    /* Run Information */
    printf("\n** BC Device Number %d, outputting to 'bcstack.txt', press <ENTER> to stop **\n\n", DevNum);

    printf("** Messages will also be output to the screen\n");

    PressAKey();
    printf("\n\n");

#ifdef INTEGRITY
    CreateProtectedTask(1,(Address)kbhit_task_func,0x1000,"kbhit", &kbhit_task);
    RunTask(kbhit_task);
#endif

    while(!kbhit())
    {
      /* Check host buffer for msgs */
        nResult = aceBCGetHBufMsgDecoded(DevNum,&sMsg,&dwMsgCount,&dwHBufLost,ACE_BC_MSGLOC_NEXT_PURGE);

        if(nResult)
        {
            printf("Error reading host buffer\n");
        }

        /* Display msg lost count */
        if(dwHBufLost > 0)
            printf("Number of msgs lost %u\n",(int)dwHBufLost);

        /* Message found */
        if(dwMsgCount)
        {
            ++dwCurCount;
#ifndef INTEGRITY
            OutputDecodedMsg(dwCurCount,&sMsg,pFile);
#endif
           printf("BC: Total msgs captured: %d                \r",(int)dwCurCount);
            DisplayDecodedMsg((U16BIT)dwCurCount,&sMsg);
        }

        //Sleep(1);
    }

    /* Throw out key */
    getch();

#ifndef INTEGRITY
    /* Close out of file */
    fclose(pFile);
#endif

    /* Stop BC */
    aceBCStop(DevNum);

    printf("\n");
}


void _DECL MyISRCM(S16BIT DevNum, U32BIT dwIrqStatus)
{
	cmOutputUpdate(DevNum);
}


/*******************************************************************************
 * Name: main
 *
 * Description:
 *
 *      Program entry point.
 *
 * In   none
 * Out  none
 ******************************************************************************/
#ifndef VX_WORKS
int main(void)
#else
int bcdemo(void)
#endif
{
	/* Variables */
	S16BIT DevNum           = 0x0000;
	S16BIT wResult          = 0x0000;
	S16BIT wSelection       = 0x0000;
	S16BIT aOpCodes[10]     = { 0x0000 };
	U32BIT u32BusSelection  = 1;
	S16BIT nResult          = 0x0000;

	U16BIT wBuffer[64] =
	{
		0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
		0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
		0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
		0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444
	};

#ifdef WIN32
    HANDLE hConsole = NULL;

    /* Setup Windows Console Screen */
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("DDC Enhanced Mini-ACE RTL [BCDemo.c - Console App BC (Basic Operations) Demo]");
#endif

	/* Print out sample header */
	PrintHeader();

	/* Get Logical Device # */
	printf("\nSelect BC Logical Device Number (0-31):\n");
	printf("> ");

	scanf("%hd", &DevNum);

	g_DevNum = DevNum;

	/* Get Logical Device # */
	printf("\nSelect 1 For Bus A or 2 for Bus B\n");
	printf("> ");

	scanf("%d", &u32BusSelection);

	/* Initialize Device */
	wResult = aceInitialize(DevNum,ACE_ACCESS_CARD,ACE_MODE_BC,0,0,0);
	if(wResult)
	{
		printf("Initialize ");
		PrintOutError(wResult);
		PressAKey();
		return 0;
	}

	
	/* Retry  */
	aceBCSetMsgRetry(DevNum, ACE_RETRY_ONCE, ACE_RETRY_ALT, ACE_RETRY_SAME, 0);
	
	aceSetIrqConditions(DevNum,1,ACE_IMR2_BC_UIRQ3, MyISRCM);

	/* Create 5 data blocks */
	nResult = aceBCDataBlkCreate(DevNum,DBLK1,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_1 \n");
	
	nResult = aceBCDataBlkCreate(DevNum,DBLK2,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_2 \n");
	
	nResult = aceBCDataBlkCreate(DevNum,DBLK3,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_3 \n");
	
	nResult = aceBCDataBlkCreate(DevNum,DBLK4,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_4 \n");
	
	nResult = aceBCDataBlkCreate(DevNum,DBLK5,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_5 \n");
	

	if (u32BusSelection == 1)
	    	u32BusSelection = ACE_BCCTRL_CHL_A;
	else
	   	 u32BusSelection = ACE_BCCTRL_CHL_B;


	/* Create message block */
	nResult = aceBCMsgCreateRTtoBC(
			    DevNum,	/* Device number                       */
			    MSG1,		/* Message ID to create              */
			    DBLK1,	/* Message will use this data block */
			    11,		/* RT address                       	*/
			    3,			/* RT subaddress                    	*/
			    20,		/* Word count                       	*/
			    0,			/* Default message timer            */
			    u32BusSelection);   /* use chl A options        */
	if(nResult)
	        printf("Err, aceBCMsgCreateRTtoBC_1 \n");
	
	
	nResult = aceBCMsgCreateBCtoRT(
			    DevNum,	/* Device number                  */
			    MSG2,		/* Message ID to create         */
			    DBLK2,	/* Message will use this data block */
			    10,		/* RT address                       */
			    2,			/* RT subaddress                  */
			    32,		/* Word count                       */
			    0,			/* Default message timer       */
			    u32BusSelection);   /* use chl A options   */	
	if(nResult)
	        printf("Err, aceBCMsgCreateBCtoRT_2 \n");
	
	nResult = aceBCMsgCreateRTtoBC(
			    DevNum,	/* Device number                       */
			    MSG3,		/* Message ID to create              */
			    DBLK3,	/* Message will use this data block */
			    12,		/* RT address                       	*/
			    5,			/* RT subaddress                    	*/
			    30,		/* Word count                       	*/
			    0,			/* Default message timer            */
			    u32BusSelection);   /* use chl A options        */
	if(nResult)
	        printf("Err, aceBCMsgCreateRTtoRT_3 \n");
	

	 nResult = aceBCMsgCreateMode(
                            DevNum,        /* Device number				*/
                            MSG4,            /* Message ID to create		*/
                            DBLK4,           /* Message will use this data block */
                            1,                   /* RT address				*/
                            0,			/* T/R						*/
                            16,                 /* mode code command		*/
                            0,                   /* Default message timer           */
                            ACE_BCCTRL_CHL_A);   /* use chl A options	*/
	if(nResult)
	        printf("Err, aceBCMsgCreateMode_4(%d) \n", nResult);
	
	nResult = aceBCMsgCreateBCtoRT(
			    DevNum,	/* Device number                  */
			    MSG5,		/* Message ID to create         */
			    DBLK5,	/* Message will use this data block */
			    3, 		/* RT address                       */
			    1,			/* RT subaddress                  */
			    32,		/* Word count                       */
			    0,			/* Default message timer       */
			    u32BusSelection);   /* use chl A options   */	
	if(nResult)
	        printf("Err, aceBCMsgCreateBCtoRT_5(%d) \n", nResult);
	

	/* Create XEQ opcode that will use msg block */
	nResult =  aceBCOpCodeCreate(DevNum,OP1,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG1,0,0);
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_1 \n");
	
	nResult =  aceBCOpCodeCreate(DevNum,OP2,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG2,0,0);
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_2 \n");
	
	nResult =  aceBCOpCodeCreate(DevNum,OP3,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG3,0,0);
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_3 \n");
	
	nResult =  aceBCOpCodeCreate(DevNum,OP4,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG4,0,0); /* create mode code 16 command */
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_4 \n");
	
	nResult =  aceBCOpCodeCreate(DevNum,OP5,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG5,0,0);
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_5 \n");
	
	

	/* Create CAL opcode that will call mnr frame from major */
	nResult = aceBCOpCodeCreate(DevNum,OP6 ,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR1,0,0);
	if(nResult)
	   	 printf("Err, ACE_OPCODE_CAL_1 \n");
	
	nResult = aceBCOpCodeCreate(DevNum,OP7 ,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR2,0,0);
	if(nResult)
	   	 printf("Err, ACE_OPCODE_CAL_2 \n");
	
	
	/* Create Minor Frame */
	aOpCodes[0] = OP1;
	aOpCodes[1] = OP2;
	aOpCodes[2] = OP3;
	nResult = aceBCFrameCreate(DevNum,MNR1,ACE_FRAME_MINOR,aOpCodes,3,200,0); /* 20 ms */ /* 1 -> 100 us */
	if(nResult)
		printf("Err, ACE_FRAME_MINOR_1[%d] \n", nResult);
	
	/* Create Minor Frame */
	aOpCodes[0] = OP1;
	aOpCodes[1] = OP2;
	aOpCodes[2] = OP3;
	aOpCodes[3] = OP4;
	aOpCodes[4] = OP5;
	nResult = aceBCFrameCreate(DevNum,MNR2,ACE_FRAME_MINOR,aOpCodes,5,200,0); /* 20 ms */
	if(nResult)
		printf("Err, ACE_FRAME_MINOR_2[%d] \n", nResult);


	/* Create Major Frame */
	aOpCodes[0] = OP6;
	aOpCodes[1] = OP7;
	nResult = aceBCFrameCreate(DevNum,MJR,ACE_FRAME_MAJOR,aOpCodes,2,0,0);
	if(nResult)
		printf("Err, ACE_FRAME_MAJOR[%d] \n", nResult);
		

	/* Create Host Buffer */
	aceBCInstallHBuf(DevNum,32*1024);

	/* Display messages as Raw or Decoded Formats */
	printf("\nWould you like messages displayed as:\n");
	//  printf("1. Raw\n");
	printf("2. Decoded\n");
	printf(">  ");
	scanf("%hd", &wSelection);


	switch(wSelection)
	{
		//case 1: GetBCHBufRawMsgs(DevNum);      break;
		case 2: GetBCHBufDecodedMsgs(DevNum);  break;
		default:GetBCHBufDecodedMsgs(DevNum);  break;
	}	

	/* Free all resources */
	wResult = aceFree(DevNum);

	if(wResult)
	{
		printf("Free ");
		PrintOutError(wResult);
		return 0;
	}

	/* Pause before program exit */
	PressAKey();

	return 0;
}
#endif 


////////////////////////////////////////////////
// BC 메시지 스케줄링 실습 II .
////////////////////////////////////////////////
#if 1
/* Include Files */
#ifdef WIN32
#include <windows.h>
#include "stdemace.h"
#include <conio.h>
#endif

#ifdef LINUX
#include "stdemace.h"
//#include "../linuxutil.h"
#endif

#ifdef VX_WORKS
#include "../LibPrj/include/stdemace.h"
#include "../utils/vxwrksuti.h"
#endif

#ifdef INTEGRITY
#include "../Integrity_Samples.h"
#endif
/*
#include <mmsystem.h>  
#pragma comment(lib,"winmm.lib")  
*/
HANDLE hSemaphoreSync;
HANDLE hThreadMission;
//MMRESULT hTimer;


/* define data blocks */
#define DBLK1   1
#define DBLK2   2
#define DBLK3   3
#define DBLK4   4
#define DBLK5   5

/* define message constants */
#define MSG1    1
#define MSG2    2
#define MSG3    3
#define MSG4    4
#define MSG5    5

/* define opcodes */
#define OP1     1
#define OP2     2
#define OP3     3
#define OP4     4
#define OP5     5
#define OP6     6
#define OP7     7
#define OP8     8
#define OP_USR     1004

/* define frame constants */
#define MNR1    1
#define MNR2    2
#define MNR3    3
#define MNR4    4
#define MJR	5


S16BIT g_DevNum;
U32BIT TX_DATA;


//////////////////////////////////////////////////////////////////////////////////////////////
void cmOutputUpdate(DevNum)
{
	 U16BIT index;//, checksum=0;
	 S16BIT wResult;
   	 U16BIT xwBuffer[32] = { 0x0000 };
	 
	U16BIT rBuffer[32];


	 TX_DATA++;
	 if(TX_DATA>0xffff)
	 	TX_DATA = 0;

	#if 0
	checksum =0;
			
	for(index=0;index<31;index++)	
	{
		xwBuffer[index] =TX_DATA;
		checksum += xwBuffer[index];	

	}	
	xwBuffer[31] = checksum;
	 
	/* Write Data to TX Address */
	wResult = aceBCDataBlkWrite(g_DevNum, DBLK2, xwBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkWrite_1");
	}	
	//else
		//printf("[%04x] ", TX_DATA);
	#endif
	
			
	for(index=0;index<32;index++)	
	{
		xwBuffer[index] = TX_DATA;
	}
	
	/* Write Data to TX Address */
#if 0	
	wResult = aceBCDataBlkWrite(g_DevNum, DBLK1, xwBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkWrite_1\n ");
	}	

	wResult = aceBCDataBlkRead(g_DevNum, DBLK1, rBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkRead_1\n ");
	}	

	
	for (index=0; index<10; index++)
	{		
	        if(index==0)
	            printf("\n DataBlkRead_1  ");

	        printf("%04X  ", rBuffer[index]);

	        if((index%8)==7)
	             printf("\n                ");	
	}		
#endif		

	wResult = aceBCDataBlkWrite(g_DevNum, DBLK2, xwBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkWrite_2\n ");
	}	
	
	wResult = aceBCDataBlkWrite(g_DevNum, DBLK5, xwBuffer, 32, 0);
	if(wResult < 0)
	{
		printf("\n Err, aceBCDataBlkWrite_3\n ");
	}	
		
}

/*******************************************************************************
 * Name:    PressAKey
 *
 * Description:
 *
 *      Allows application to pause to allow screen contents to be read.
 *
 * In   none
 * Out  none
 ******************************************************************************/
static void PressAKey()
{
    /* flush input buffer */
    while (kbhit())
    {
        getchar();
    }

    printf("\nPress <ENTER> to continue...");

    /* flush the output buffer */
    fflush(stdout);

    while (!kbhit())
    {
        /* wait for keypress... */
        Sleep(10);
    }

    /* flush input buffer */
    while (kbhit())
    {
        getchar();
    }
}

/*******************************************************************************
 * Name:    PrintHeader
 *
 * Description:
 *
 *      Prints the sample program header.
 *
 * In   none
 * Out  none
 ******************************************************************************/
static void PrintHeader(void)
{
    U16BIT wLibVer;

    wLibVer = aceGetLibVersion();

    printf("*********************************************\n");
    printf("AceXtreme Integrated 1553 Terminal          *\n");
    printf("BU-69092 1553 Runtime Library               *\n");
    printf("Release Rev %d.%d.%d                           *\n",
            (wLibVer>>8),        /* Major*/
            (wLibVer&0xF0)>>4,   /* Minor*/
            (wLibVer&0xF));      /* Devel*/

    if ((wLibVer&0xF)!=0)
        printf("=-=-=-=-=-=-=-INTERIM VERSION-=-=-=-=-=-=-=-*\n");

    printf("Copyright (c) 2010 Data Device Corporation  *\n");
    printf("*********************************************\n");
    printf("BCDemo.c BC operations [Basic Op Demo]      *\n");
    printf("*********************************************\n\n");
	
    printf("\n");
    printf("   After the BC finishes sending, the messages\n");
    printf("   are read out from the host buffer and either\n");
    printf("   shown on the display in decoded format or\n");
    printf("   saved as raw data to a file.\n");
}

/*******************************************************************************
 * Name:    PrintOutError
 *
 * Description:
 *
 *      This function prints out errors returned from library functions.
 *
 * In   result - the error number
 * Out  none
 ******************************************************************************/
static void PrintOutError(S16BIT nResult)
{
   char buf[80];
   aceErrorStr(nResult,buf,80);
   printf("RTL Function Failure-> %s.\n",buf);
}

/*******************************************************************************
 * Name:    DisplayDecodedMsg
 *
 * Description:
 *
 *      This function displays the information of a MSGSTRUCT to the screen.
 *
 * In   nMsgNum     Number of the message
 * In   pMsg        Relavant information of the message
 * Out  none
 ******************************************************************************/
static void DisplayDecodedMsg
(
    S16BIT nMsgNum,
    MSGSTRUCT *pMsg
)
{
    U16BIT i;
    char szBuffer[100];
    U16BIT wRT, wTR1, wTR2, wSA, wWC;

    /* Display message header info */
    printf("MSG #%04d.  TIME = %08dus    BUS %c   TYPE%d: %s ", nMsgNum,
        pMsg->wTimeTag * 2, pMsg->wBlkSts & ACE_MT_BSW_CHNL ? 'B' : 'A',
        pMsg->wType, aceGetMsgTypeString(pMsg->wType));

    /* Display command word info */
    aceCmdWordParse(pMsg->wCmdWrd1, &wRT, &wTR1, &wSA, &wWC);
    sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR1 ? 'T' : 'R', wSA, wWC);
    printf("\n            CMD1 %04X --> %s", pMsg->wCmdWrd1, szBuffer);

    if (pMsg->wCmdWrd2Flg)
    {
        aceCmdWordParse(pMsg->wCmdWrd2, &wRT, &wTR2, &wSA, &wWC);
        sprintf(szBuffer, "%02d-%c-%02d-%02d", wRT, wTR2 ? 'T' : 'R', wSA, wWC);
        printf("\n        CMD2 %04X --> %s", pMsg->wCmdWrd2, szBuffer);
    }

    /* Display transmit status words */
    if ((wTR1 == 1) || (pMsg->wBlkSts & ACE_MT_BSW_RTRT))
    {
        if (pMsg->wStsWrd1Flg)
        {
            printf("\n            STA1 %04X", pMsg->wStsWrd1);
        }
    }

    /* Display Data words */
    for (i = 0; i < pMsg->wWordCount; i++)
    {
        if (i == 0)
        {
            printf("\n            DATA ");
        }

        printf("%04X  ", pMsg->aDataWrds[i]);

        if ((i % 8) == 7)
        {
            printf("\n                 ");
        }
    }

    /* Display receive status words */
    if ((wTR1 == 0) && !(pMsg->wBlkSts & ACE_MT_BSW_RTRT))
    {
        if (pMsg->wStsWrd1Flg)
        {
            printf("\n            STA1 %04X", pMsg->wStsWrd1);
        }
    }

    if (pMsg->wStsWrd2Flg)
    {
        printf("\n            STA2 %04X", pMsg->wStsWrd2);
    }

    /* Display Error information */
    if (pMsg->wBlkSts & ACE_MT_BSW_ERRFLG)
    {
        printf("\n ERROR: %s", aceGetBSWErrString(ACE_MODE_MT, pMsg->wBlkSts));
    }

    printf("\n\n");
}


/*******************************************************************************
 * Name:    OutputDecodedMsg
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE.
 *
 * In   DevNum      Device number of the hardware to be accessed.
 * In   pFileName   Pointer to a null terminated string containing file name
 * Out  none
 ******************************************************************************/
static void OutputDecodedMsg(U32BIT nMsgNum,MSGSTRUCT *pMsg,FILE *pFile)
{
    U16BIT i;
    char szBuffer[100];
    U16BIT wRT,wTR1,wTR2,wSA,wWC;

    /* Display message header info */
    fprintf(pFile,"MSG #%04d.  TIME = %08dus    BUS %c   TYPE%d: %s ",
        (int)nMsgNum,pMsg->wTimeTag*2,pMsg->wBlkSts&ACE_BC_BSW_CHNL?'B':'A',
        pMsg->wType, aceGetMsgTypeString(pMsg->wType));

    /* Display command word info */
    aceCmdWordParse(pMsg->wCmdWrd1,&wRT,&wTR1,&wSA,&wWC);
    sprintf(szBuffer,"%02d-%c-%02d-%02d",wRT,wTR1?'T':'R',wSA,wWC);
    fprintf(pFile,"\n            CMD1 %04X --> %s",pMsg->wCmdWrd1,szBuffer);

    if(pMsg->wCmdWrd2Flg)
    {
        aceCmdWordParse(pMsg->wCmdWrd2,&wRT,&wTR2,&wSA,&wWC);
        sprintf(szBuffer,"%02d-%c-%02d-%02d",wRT,wTR2?'T':'R',wSA,wWC);
        fprintf(pFile,"\n            CMD2 %04X --> %s",pMsg->wCmdWrd2,szBuffer);
   }

    /* Display transmit status words */
    if((wTR1==1) || (pMsg->wBCCtrlWrd&ACE_BCCTRL_RT_TO_RT))
    {
        if(pMsg->wStsWrd1Flg)
            fprintf(pFile,"\n            STA1 %04X",pMsg->wStsWrd1);
    }

    /* Display Data words */
    for(i=0; i<pMsg->wWordCount; i++)
    {
        if(i==0)
            fprintf(pFile,"\n            DATA ");

        fprintf(pFile,"%04X  ",pMsg->aDataWrds[i]);

        if((i%8)==7)
            fprintf(pFile,"\n                 ");
   }

    /* Display receive status words */
    if((wTR1==0)  && !(pMsg->wBCCtrlWrd&ACE_BCCTRL_RT_TO_RT))
    {
        if(pMsg->wStsWrd1Flg)
            fprintf(pFile,"\n            STA1 %04X",pMsg->wStsWrd1);
    }

    if(pMsg->wStsWrd2Flg)
        fprintf(pFile,"\n            STA2 %04X",pMsg->wStsWrd2);

    /* Display Error information */
    if(pMsg->wBlkSts & 0x170f)
        fprintf(pFile, "\n ERROR: %s",aceGetBSWErrString(ACE_MODE_BC,pMsg->wBlkSts));

    fprintf(pFile,"\n---------------------------------------------------------\n");
}

/*******************************************************************************
 * Name:    GetBCHBufRawMsgs
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE and outputs to a file.
 *
 * In   DevNum - the device number of the hardware to be accessed
 * Out  none
 ******************************************************************************/
static void GetBCHBufRawMsgs(S16BIT DevNum)
{
   /* Variables */
#ifdef INTEGRITY
    Task kbhit_task;
#else
   FILE *pFile = NULL;
   U16BIT i =  0x0000;
#endif

    U16BIT wMsgCount    = 0x0000;
    U32BIT dwMsgCount   = 0x00000000;
    U32BIT dwMsgLost    = 0x00000000;
    U32BIT dwPrevCount  = 0x00000000;
    U32BIT dwCurCount   = 0x00000000;
    U16BIT wRepeatCount = 20;

    U16BIT wBuffer[64] =
    {
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000
    };

#ifndef INTEGRITY
    /* Open file */
    pFile = fopen("bcstack.bin","wb+");
#endif

    printf("\n** The BC will now send %d messages",wRepeatCount);

    /* Start BC */
    aceBCStart(DevNum,MJR,wRepeatCount);

    /* Run Information */
    printf("\n** BC Device Number %d, outputting to 'bcstack.bin', press <ENTER> to stop **\n\n", DevNum);

    PressAKey();
    printf("\n\n");

#ifdef INTEGRITY
    CreateProtectedTask(1,(Address)kbhit_task_func,0x1000,"kbhit", &kbhit_task);
    RunTask(kbhit_task);
#endif

    while(!kbhit())
    {
        /* Check host buffer for msgs */
        aceBCGetHBufMsgsRaw(DevNum,wBuffer,ACE_MSGSIZE_BC,&dwMsgCount,&dwMsgLost);

        /* Msg found */
        if(dwMsgCount)
        {
            dwPrevCount += dwMsgLost;
            dwCurCount += dwMsgCount;

#ifndef INTEGRITY
            for(i=0; dwPrevCount<dwCurCount; dwPrevCount++,i++)
            {
                fwrite(&wBuffer[i*ACE_MSGSIZE_BC], 84, 1, pFile);
            }
#endif

            printf("BC: Total msgs captured: %d                  \r", (int)(dwCurCount+dwMsgLost));

            wMsgCount++;
        }

       // Sleep(1);
    }

    /* Throw away key */
    getch();

#ifndef INTEGRITY
    /* Close out of file */
    fclose(pFile);
#endif

    /* Stop BC */
    aceBCStop(DevNum);

    printf("\n");
}

/*******************************************************************************
 * Name:    GetBCHBufDecodedMsgs
 *
 * Description:
 *
 *      This function creates an BC stack file in ASCII text using all msgs
 *      read from the ACE and outputs to a file.
 *
 * In   DevNum - the device number of the hardware to be accessed.
 * Out  none
 ******************************************************************************/
static void GetBCHBufDecodedMsgs(S16BIT DevNum)
{
#ifdef INTEGRITY
    Task kbhit_task;
#else
    FILE *pFile = NULL;
#endif
    S16BIT nResult      = 0x0000;
    U32BIT dwHBufLost   = 0x00000000;
    U32BIT dwMsgCount   = 0x00000000;
    U32BIT dwCurCount   = 0x00000000;
    U16BIT wRepeatCount = 5; // -1 : forever
    MSGSTRUCT sMsg;

#ifndef INTEGRITY
    /* Open file */
    pFile = fopen("bcstack.txt","w");
#endif

    printf("\n** The BC will now send %d messages",wRepeatCount);

    /* Start BC */
    aceBCStart(DevNum,MJR,wRepeatCount);

    /* Run Information */
    printf("\n** BC Device Number %d, outputting to 'bcstack.txt', press <ENTER> to stop **\n\n", DevNum);

    printf("** Messages will also be output to the screen\n");

    PressAKey();
    printf("\n\n");

#ifdef INTEGRITY
    CreateProtectedTask(1,(Address)kbhit_task_func,0x1000,"kbhit", &kbhit_task);
    RunTask(kbhit_task);
#endif

    while(!kbhit())
    {
      /* Check host buffer for msgs */
        nResult = aceBCGetHBufMsgDecoded(DevNum,&sMsg,&dwMsgCount,&dwHBufLost,ACE_BC_MSGLOC_NEXT_PURGE);

        if(nResult)
        {
            printf("Error reading host buffer\n");
        }

        /* Display msg lost count */
        if(dwHBufLost > 0)
            printf("Number of msgs lost %u\n",(int)dwHBufLost);

        /* Message found */
        if(dwMsgCount)
        {
            ++dwCurCount;
#ifndef INTEGRITY
            OutputDecodedMsg(dwCurCount,&sMsg,pFile);
#endif
           printf("BC: Total msgs captured: %d                \r",(int)dwCurCount);
            DisplayDecodedMsg((U16BIT)dwCurCount,&sMsg);
        }

        //Sleep(1);
    }

    /* Throw out key */
    getch();

#ifndef INTEGRITY
    /* Close out of file */
    fclose(pFile);
#endif

    /* Stop BC */
    aceBCStop(DevNum);

    printf("\n");
}


void _DECL MyISRCM(S16BIT DevNum, U32BIT dwIrqStatus)
{
	cmOutputUpdate(DevNum);
}


/*******************************************************************************
 * Name: main
 *
 * Description:
 *
 *      Program entry point.
 *
 * In   none
 * Out  none
 ******************************************************************************/
#ifndef VX_WORKS
int main(void)
#else
int bcdemo(void)
#endif
{
	/* Variables */
	S16BIT DevNum           = 0x0000;
	S16BIT wResult          = 0x0000;
	S16BIT wSelection       = 0x0000;
	S16BIT aOpCodes[10]     = { 0x0000 };
	U32BIT u32BusSelection  = 1;
	S16BIT nResult          = 0x0000;

	U16BIT wBuffer[64] =
	{
		0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
		0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
		0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444,
		0x1111, 0x2222, 0x3333, 0x4444, 0x1111, 0x2222, 0x3333, 0x4444
	};

#ifdef WIN32
    HANDLE hConsole = NULL;

    /* Setup Windows Console Screen */
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTitle("DDC Enhanced Mini-ACE RTL [BCDemo.c - Console App BC (Basic Operations) Demo]");
#endif

	/* Print out sample header */
	PrintHeader();

	/* Get Logical Device # */
	printf("\nSelect BC Logical Device Number (0-31):\n");
	printf("> ");

	scanf("%hd", &DevNum);

	g_DevNum = DevNum;

	/* Get Logical Device # */
	printf("\nSelect 1 For Bus A or 2 for Bus B\n");
	printf("> ");

	scanf("%d", &u32BusSelection);

	/* Initialize Device */
	wResult = aceInitialize(DevNum,ACE_ACCESS_CARD,ACE_MODE_BC,0,0,0);
	if(wResult)
	{
		printf("Initialize ");
		PrintOutError(wResult);
		PressAKey();
		return 0;
	}

	/* Retry  */
	aceBCSetMsgRetry(DevNum, ACE_RETRY_ONCE, ACE_RETRY_ALT, ACE_RETRY_SAME, 0);
	
	aceSetIrqConditions(DevNum,1,ACE_IMR2_BC_UIRQ3, MyISRCM);

	/* Create 5 data blocks */
	nResult = aceBCDataBlkCreate(DevNum,DBLK1,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_1 \n");
	
	nResult = aceBCDataBlkCreate(DevNum,DBLK2,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_2 \n");
	
	nResult = aceBCDataBlkCreate(DevNum,DBLK3,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_3 \n");
	
	nResult = aceBCDataBlkCreate(DevNum,DBLK4,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_4 \n");
	
	nResult = aceBCDataBlkCreate(DevNum,DBLK5,ACE_BC_DBLK_DOUBLE,wBuffer,32);
	if(nResult)
	        printf("Err, aceBCDataBlkCreate_5 \n");
	

	if (u32BusSelection == 1)
	    	u32BusSelection = ACE_BCCTRL_CHL_A | ACE_MSGOPT_DOUBLE_BUFFER;
	else
	   	 u32BusSelection = ACE_BCCTRL_CHL_B | ACE_MSGOPT_DOUBLE_BUFFER;;

	/* Create message block */
	nResult = aceBCMsgCreateRTtoBC(
				    DevNum,	/* Device number                       */
				    MSG1,		/* Message ID to create              */
				    DBLK1,	/* Message will use this data block */
				    11,		/* RT address                       	*/
				    3,			/* RT subaddress                    	*/
				    20,		/* Word count                       	*/
				    0,			/* Default message timer            */
				    u32BusSelection);   /* use chl A options        */
	if(nResult)
	        printf("Err, aceBCMsgCreateRTtoBC_1 \n");
	
	
	nResult = aceBCMsgCreateBCtoRT(
			    DevNum,	/* Device number                  */
			    MSG2,		/* Message ID to create         */
			    DBLK2,	/* Message will use this data block */
			    10,		/* RT address                       */
			    2,			/* RT subaddress                  */
			    32,		/* Word count                       */
			    0,			/* Default message timer       */
			    u32BusSelection);   /* use chl A options   */	
	if(nResult)
	        printf("Err, aceBCMsgCreateBCtoRT_2 \n");
	
	nResult = aceBCMsgCreateRTtoBC(
			    DevNum,	/* Device number                       */
			    MSG3,		/* Message ID to create              */
			    DBLK3,	/* Message will use this data block */
			    12,		/* RT address                       	*/
			    5,			/* RT subaddress                    	*/
			    30,		/* Word count                       	*/
			    0,			/* Default message timer            */
			    u32BusSelection);   /* use chl A options        */
	if(nResult)
	        printf("Err, aceBCMsgCreateRTtoRT_3 \n");
	

	 nResult = aceBCMsgCreateMode(
                            DevNum,        /* Device number				*/
                            MSG4,            /* Message ID to create		*/
                            DBLK4,           /* Message will use this data block */
                            1,                   /* RT address				*/
                            0,			/* T/R						*/
                            16,                 /* mode code command		*/
                            0,                   /* Default message timer           */
                            ACE_BCCTRL_CHL_A);   /* use chl A options	*/
	if(nResult)
	        printf("Err, aceBCMsgCreateMode_4(%d) \n", nResult);
	
	nResult = aceBCMsgCreateBCtoRT(
			    DevNum,	/* Device number                  */
			    MSG5,		/* Message ID to create         */
			    DBLK5,	/* Message will use this data block */
			    3, 		/* RT address                       */
			    1,			/* RT subaddress                  */
			    32,		/* Word count                       */
			    0,			/* Default message timer       */
			    u32BusSelection);   /* use chl A options   */	
	if(nResult)
	        printf("Err, aceBCMsgCreateBCtoRT_5(%d) \n", nResult);
	

	/* Create XEQ opcode that will use msg block */
	nResult =  aceBCOpCodeCreate(DevNum,OP1,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG1,0,0);
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_1 \n");
	
	nResult =  aceBCOpCodeCreate(DevNum,OP2,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG2,0,0);
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_2 \n");
	
	nResult =  aceBCOpCodeCreate(DevNum,OP3,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG3,0,0);
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_3 \n");
	
	nResult =  aceBCOpCodeCreate(DevNum,OP4,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG4,0,0); /* create mode code 16 command */
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_4 \n");
	
	nResult =  aceBCOpCodeCreate(DevNum,OP5,ACE_OPCODE_XEQ,ACE_CNDTST_ALWAYS,MSG5,0,0);
	if(nResult)
	        printf("Err, aceBCOpCodeCreate_5 \n");

	
///////////////////////////////////////////////////////////////////////////////////////////////////
/* DSK FAE -- Create an OPCODE to generate USER ISR */
//////////////////////////////////////////////////////////////////////////////////////////////////
	nResult = aceBCOpCodeCreate(DevNum, OP_USR, ACE_OPCODE_IRQ,ACE_CNDTST_ALWAYS,0x0008,0,0);   
	if(nResult)
            printf("Err, ACE_OPCODE_IRQ\n");
///////////////////////////////////////////////////////////////////////////////////////////////////
	

	/* Create CAL opcode that will call mnr frame from major */
	nResult = aceBCOpCodeCreate(DevNum,OP6 ,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR1,0,0);
	if(nResult)
	   	 printf("Err, ACE_OPCODE_CAL_1 \n");
	
	nResult = aceBCOpCodeCreate(DevNum,OP7 ,ACE_OPCODE_CAL,ACE_CNDTST_ALWAYS,MNR2,0,0);
	if(nResult)
	   	 printf("Err, ACE_OPCODE_CAL_2 \n");
	
	
	/* Create Minor Frame */
	aOpCodes[0] = OP1;
	aOpCodes[1] = OP2;
	aOpCodes[2] = OP3;
	aOpCodes[3] = OP_USR; /* Create an OPCODE to generate USER ISR */
	nResult = aceBCFrameCreate(DevNum,MNR1,ACE_FRAME_MINOR,aOpCodes,3+1,200,0); /* 20 ms */
	if(nResult)
		printf("Err, ACE_FRAME_MINOR_1[%d] \n", nResult);
	
	/* Create Minor Frame */
	aOpCodes[0] = OP1;
	aOpCodes[1] = OP2;
	aOpCodes[2] = OP3;
	aOpCodes[3] = OP4;
	aOpCodes[4] = OP5;
	aOpCodes[5] = OP_USR; /* Create an OPCODE to generate USER ISR */
	nResult = aceBCFrameCreate(DevNum,MNR2,ACE_FRAME_MINOR,aOpCodes,5+1,200,0); /* 20 ms */
	if(nResult)
		printf("Err, ACE_FRAME_MINOR_2[%d] \n", nResult);


	/* Create Major Frame */
	aOpCodes[0] = OP6;
	aOpCodes[1] = OP7;
	nResult = aceBCFrameCreate(DevNum,MJR,ACE_FRAME_MAJOR,aOpCodes,2,0,0);
	if(nResult)
		printf("Err, ACE_FRAME_MAJOR[%d] \n", nResult);
		

	/* Create Host Buffer */
	aceBCInstallHBuf(DevNum,32*1024);

	/* Display messages as Raw or Decoded Formats */
	printf("\nWould you like messages displayed as:\n");
	//  printf("1. Raw\n");
	printf("2. Decoded\n");
	printf(">  ");
	scanf("%hd", &wSelection);


	switch(wSelection)
	{
		//case 1: GetBCHBufRawMsgs(DevNum);      break;
		case 2: GetBCHBufDecodedMsgs(DevNum);  break;
		default:GetBCHBufDecodedMsgs(DevNum);  break;
	}	

	/* Free all resources */
	wResult = aceFree(DevNum);

	if(wResult)
	{
		printf("Free ");
		PrintOutError(wResult);
		return 0;
	}

	/* Pause before program exit */
	PressAKey();

	return 0;
}
#endif 




