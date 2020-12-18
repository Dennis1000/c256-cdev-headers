//////
////// Jump table to connect to BASIC816 and the machine language monitor
//////

#define BASIC  (*(volatile unsigned char *)0x3A0000)
#define MONITOR = BASIC + 4

