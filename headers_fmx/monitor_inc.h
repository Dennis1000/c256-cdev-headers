//MONITOR_INC.asm
//MONITOR ROM jump table
#define MONITOR           (*(volatile unsigned char *)0x198000)  // Cold boot routine
#define MBREAK            (*(volatile unsigned char *)0x198004)  // Warm boot routine
#define MSTATUS           (*(volatile unsigned char *)0x198008)  // Print status message
#define MREADY            (*(volatile unsigned char *)0x19800C)  // Prints status message and waits for input
#define MRETURN           (*(volatile unsigned char *)0x198010)  // Handle RETURN key (ie: execute command)
#define MPARSE            (*(volatile unsigned char *)0x198014)  // Parse the current command line
#define MPARSE1           (*(volatile unsigned char *)0x198018)  // Parse one word on the current command line
#define MEXECUTE          (*(volatile unsigned char *)0x19801C)  // Execute the current command line (requires MCMD and MARG1-MARG8 to be populated)
#define MASSEMBLE         (*(volatile unsigned char *)0x198020)  // Assemble a line of text.
#define MASSEMBLEA        (*(volatile unsigned char *)0x198024)  // Assemble a line of text.
#define MCOMPARE          (*(volatile unsigned char *)0x198028)  // Compare memory. len=1
#define MDISASSEMBLE      (*(volatile unsigned char *)0x19802C)  // Disassemble memory. end=1 instruction
#define MFILL             (*(volatile unsigned char *)0x198030)  // Fill memory with specified value. Start and end must be in the same bank.

#define MJUMP             (*(volatile unsigned char *)0x198038)  // Execute from spefified address
#define MHUNT             (*(volatile unsigned char *)0x19803C)  // Hunt (find) value in memory
#define MLOAD             (*(volatile unsigned char *)0x198040)  // Load data from disk. Device=1 (internal floppy) Start=Address in file
#define MMEMORY           (*(volatile unsigned char *)0x198044)  // View memory
#define MREGISTERS        (*(volatile unsigned char *)0x198048)  // View/edit registers
#define MSAVE             (*(volatile unsigned char *)0x19804C)  // Save memory to disk
#define MTRANSFER         (*(volatile unsigned char *)0x198050)  // Transfer (copy) data in memory
#define MVERIFY           (*(volatile unsigned char *)0x198054)  // Verify memory and file on disk
#define MEXIT             (*(volatile unsigned char *)0x198058)  // Exit monitor and return to BASIC command prompt
#define MMODIFY           (*(volatile unsigned char *)0x19805C)  // Modify memory
#define MDOS              (*(volatile unsigned char *)0x198060)  // Execute DOS command
