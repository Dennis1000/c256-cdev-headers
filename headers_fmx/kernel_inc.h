//Kernel_INC.asm
//Kernel ROM jump table

#define BOOT              (*(volatile unsigned char *)0x001000)  // Cold boot routine
#define RESTORE           (*(volatile unsigned char *)0x001004)  // Warm boot routine
#define BREAK             (*(volatile unsigned char *)0x001008)  // End program and return to command prompt
#define READY             (*(volatile unsigned char *)0x00100C)  // Print prompt and wait for keyboard input
#define SCINIT            (*(volatile unsigned char *)0x001010)  //
#define IOINIT            (*(volatile unsigned char *)0x001014)  //
#define PUTC              (*(volatile unsigned char *)0x001018)  // Print a character to the currently selected channel
#define PUTS              (*(volatile unsigned char *)0x00101C)  // Print a string to the currently selected channel
#define PUTB              (*(volatile unsigned char *)0x001020)  // Output a byte to the currently selected channel
#define PUTBLOCK          (*(volatile unsigned char *)0x001024)  // Ouput a binary block to the currently selected channel
#define SETLFS            (*(volatile unsigned char *)0x001028)  // Obsolete (done in OPEN)
#define SETNAM            (*(volatile unsigned char *)0x00102C)  // Obsolete (done in OPEN)
#define OPEN              (*(volatile unsigned char *)0x001030)  // Open a channel for reading and/or writing. Use SETLFS and SETNAM to set the channels and filename first.
#define CLOSE             (*(volatile unsigned char *)0x001034)  // Close a channel
#define SETIN             (*(volatile unsigned char *)0x001038)  // Set the current input channel
#define SETOUT            (*(volatile unsigned char *)0x00103C)  // Set the current output channel
#define GETB              (*(volatile unsigned char *)0x001040)  // Get a byte from input channel. Return 0 if no input. Carry is set if no input.
#define GETBLOCK          (*(volatile unsigned char *)0x001044)  // Get a X byes from input channel. If Carry is set, wait. If Carry is clear, do not wait.
#define GETCH             (*(volatile unsigned char *)0x001048)  // Get a character from the input channel. A=0 and Carry=1 if no data is wating
#define GETCHW            (*(volatile unsigned char *)0x00104C)  // Get a character from the input channel. Waits until data received. A=0 and Carry=1 if no data is wating
#define GETCHE            (*(volatile unsigned char *)0x001050)  // Get a character from the input channel and echo to the screen. Wait if data is not ready.
#define GETS              (*(volatile unsigned char *)0x001054)  // Get a string from the input channel. NULL terminates
#define GETLINE           (*(volatile unsigned char *)0x001058)  // Get a line of text from input channel. CR or NULL terminates.
#define GETFIELD          (*(volatile unsigned char *)0x00105C)  // Get a field from the input channel. Value in A, CR, or NULL terminates
#define TRIM              (*(volatile unsigned char *)0x001060)  // Removes spaces at beginning and end of string.
#define PRINTC            (*(volatile unsigned char *)0x001064)  // Print character to screen. Handles terminal commands
#define PRINTS            (*(volatile unsigned char *)0x001068)  // Print string to screen. Handles terminal commands
#define PRINTCR           (*(volatile unsigned char *)0x00106C)  // Print Carriage Return
#define PRINTF            (*(volatile unsigned char *)0x001070)  // Print a float value
#define PRINTI            (*(volatile unsigned char *)0x001074)  // Prints integer value in TEMP
#define PRINTH            (*(volatile unsigned char *)0x001078)  // Print Hex value in DP variable
#define PRINTAI           (*(volatile unsigned char *)0x00107C)  // Prints integer value in A
#define PRINTAH           (*(volatile unsigned char *)0x001080)  // Prints hex value in A. Printed value is 2 wide if M flag is 1, 4 wide if M=0
#define LOCATE            (*(volatile unsigned char *)0x001084)  //
#define PUSHKEY           (*(volatile unsigned char *)0x001088)  //
#define PUSHKEYS          (*(volatile unsigned char *)0x00108C)  //
#define CSRRIGHT          (*(volatile unsigned char *)0x001090)  //
#define CSRLEFT           (*(volatile unsigned char *)0x001094)  //
#define CSRUP             (*(volatile unsigned char *)0x001098)  //
#define CSRDOWN           (*(volatile unsigned char *)0x00109C)  //
#define CSRHOME           (*(volatile unsigned char *)0x0010A0)  //
#define SCROLLUP          (*(volatile unsigned char *)0x0010A4)  // Scroll the screen up one line. Creates an empty line at the bottom.
// Undefined label for: SCRGETWORD       = %ADDR% // Read a current word on the screen. A word ends with a space, punctuation (except _), or any control character (value < 32). Loads the address into CMPTEXT_VAL and length into CMPTEXT_LEN variables.
#define CLRSCREEN         (*(volatile unsigned char *)0x0010A8)  // Clear the screen
#define INITCHLUT         (*(volatile unsigned char *)0x0010AC)  // Init character look-up table
#define INITSUPERIO       (*(volatile unsigned char *)0x0010B0)  // Init Super-IO chip
#define INITKEYBOARD      (*(volatile unsigned char *)0x0010B4)  // Init keyboard
// Undefined label for: INITRTC          = %ADDR% // Init Real-Time Clock
#define INITCURSOR        (*(volatile unsigned char *)0x0010BC)  // Init the Cursors registers
#define INITFONTSET       (*(volatile unsigned char *)0x0010C0)  // Init the Internal FONT Memory
#define INITGAMMATABLE    (*(volatile unsigned char *)0x0010C4)  // Init the RGB GAMMA Look Up Table
#define INITALLLUT        (*(volatile unsigned char *)0x0010C8)  // Init the Graphic Engine (Bitmap/Tile/Sprites) LUT
#define INITVKYTXTMODE    (*(volatile unsigned char *)0x0010CC)  // Init the Text Mode @ Reset Time
#define INITVKYGRPMODE    (*(volatile unsigned char *)0x0010D0)  // Init the Basic Registers for the Graphic Mode
#define SETSIZES          (*(volatile unsigned char *)0x00112C)  // Set the text screen size variables based on the border and screen resolution.
#define F_OPEN            (*(volatile unsigned char *)0x0010F0)  // open a file for reading/writing/creating
#define F_CREATE          (*(volatile unsigned char *)0x0010F4)  // create a new file
#define F_CLOSE           (*(volatile unsigned char *)0x0010F8)  // close a file (make sure last cluster is written)
#define F_WRITE           (*(volatile unsigned char *)0x0010FC)  // write the current cluster to the file
#define F_READ            (*(volatile unsigned char *)0x001100)  // read the next cluster from the file
#define F_DELETE          (*(volatile unsigned char *)0x001104)  // delete a file / directory
// Undefined label for: F_RENAME         = %ADDR% // rename a file
#define F_DIROPEN         (*(volatile unsigned char *)0x001108)  // open a directory and seek the first directory entry
#define F_DIRNEXT         (*(volatile unsigned char *)0x00110C)  // seek to the next directory of an open directory
#define F_DIRREAD         (*(volatile unsigned char *)0x001110)  // Read the directory entry for the specified file
#define F_DIRWRITE        (*(volatile unsigned char *)0x001114)  // Write any changes in the current directory cluster back to the drive
#define F_LOAD            (*(volatile unsigned char *)0x001118)  // load a binary file into memory, supports multiple file formats
#define F_SAVE            (*(volatile unsigned char *)0x00111C)  // Save memory to a binary file
#define CMDBLOCK          (*(volatile unsigned char *)0x001120)  // Send a command to a block device
#define F_RUN             (*(volatile unsigned char *)0x001124)  // Load and run an executable binary file
#define F_MOUNT           (*(volatile unsigned char *)0x001128)  // Mount the designated block device
#define F_COPY            (*(volatile unsigned char *)0x001130)  // Copy a file
#define F_ALLOCFD         (*(volatile unsigned char *)0x001134)  // Allocate a file descriptor
#define F_FREEFD          (*(volatile unsigned char *)0x001138)  // Free a file descriptor

//
// Interrupt Jump Table
//

#define VEC_INT00_SOF    (*(volatile unsigned char *)0x001700)  // Interrupt routine for Start Of Frame interrupt
#define VEC_INT01_SOL    (*(volatile unsigned char *)0x001704)  // Interrupt routine for Start Of Line interrupt
#define VEC_INT02_TMR0   (*(volatile unsigned char *)0x001708)  // Interrupt routine for Timer0
#define VEC_INT03_TMR1   (*(volatile unsigned char *)0x00170C)  // Interrupt routine for Timer1
#define VEC_INT04_TMR2   (*(volatile unsigned char *)0x001710)  // Interrupt routine for Timer2
