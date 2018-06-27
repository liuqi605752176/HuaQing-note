/*
 6.2.3.198 GPX1CON
   Base Address: 0x1100_0000
   Address = Base Address + 0x0C20, Reset Value = 0x0000_0000
 Name  Bit  Type  Description  Reset Value
 GPX1CON[7]  [31:28]  RW
 0x0 = Input
 0x1 = Output
 0x2 = Reserved
 0x3 = KP_COL[7]
 0x4 = Reserved
 0x5 = ALV_DBG[11]
 0x6 to 0xE = Reserved
 0xF = WAKEUP_INT1[7]

 6.2.2.61 GPF3CON
  Base Address: 0x1140_0000
  Address = Base Address + 0x01E0, Reset Value = 0x0000_0000

 */

#include "exynos_4412.h"


#define  GPX1CON  (*(volatile unsigned int *) (0x11000000 + 0x0C20))
#define  GPX1DAT  (*(volatile unsigned int *) (0x11000000 + 0x0C24))

#define  GPF3CON  (*(volatile unsigned int *) (0x11400000 + 0x01E0))
#define  GPF3DAT  (*(volatile unsigned int *) (0x11400000 + 0x01E4))

void laoli(int *x) {
	//unsigned int *p;
	//p = (unsigned int *) (0x11000000 + 0x0C20);
	//*p = (*p & 0xfffffff0) | 0x00000001;
	(*(unsigned int *) (0x11000000 + 0x0C20)) =
			( (*(unsigned int *) (0x11000000 + 0x0C20) ) & 0xfffffff0) | 0x00000001;
	GPX1CON = (GPX1CON & 0XFFFFFFF0) | 0x00000001;
	GPX1CON = (GPX1CON & ~0xf) | 0x1;
	//p = (unsigned int *) (0x11000000 + 0x0C24);
	//*p |= 0b00000001;
	(*(unsigned int *) (0x11000000 + 0x0C24)) |= (0b00000001);
	GPX1DAT |= 1;


	GPX1CON = (GPX1CON & ~0xf) | 0x1;
	GPX1DAT |= 1;

	//GPF3CON = (GPF3CON & ~0X000F0000) | (0X00010000);
	GPF3CON = (GPF3CON & ~(0XF << 16)) | (0X1 << 16);
	GPF3DAT |= (1 << 4);

	GPF3.CON = (GPF3.CON & ~(0XF << 20)) | (0X1 <<20);
	GPF3.DAT |= (1 << 5);

	while (1)
		;

	return;
}

