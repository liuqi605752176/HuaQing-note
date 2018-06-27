

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

*/


.text
.globl _start
_start:

	mov sp,#0x7ffffff0  @初始化栈起始位置

	mov r0,#0x50000000
	bl laoli  @跳转到c



_stop:
	b _stop


a:
	.word






