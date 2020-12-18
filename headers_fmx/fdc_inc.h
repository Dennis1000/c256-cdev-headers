//////
////// Registers for the floppy drive controller
//////

#define SIO_FDC   (*(volatile unsigned char *)0xAF13F0)
#define SIO_FDC_SRA  (*(volatile unsigned char *)0xAF13F0)  // Read Only - Status Register A (not used in AT mode)

#define SIO_FDC_SRB  (*(volatile unsigned char *)0xAF13F1)  // Read Only - Status Register B (not used in AT mode)

#define SIO_FDC_DOR  (*(volatile unsigned char *)0xAF13F2)  // Read/Write - Digital Output Register
#define FDC_DOR_DSEL0  0x01  // Drive 0 Select
#define FDC_DOR_DSEL1  0x02  // Drive 1 Select
#define FDC_DOR_NRESET  0x04  // Reset the FDC
#define FDC_DOR_DMAEN  0x08  // Enable DMA
#define FDC_DOR_MOT0   0x10  // Turn on motor 0
#define FDC_DOR_MOT1   0x20  // Turn on motor 1
#define FDC_DOR_MOT2   0x40  // Turn on motor 2
#define FDC_DOR_MOT3   0x80  // Turn on motor 3

#define SIO_FDC_TSR  (*(volatile unsigned char *)0xAF13F3)  // Read/Write - Tape Drive Status (not used on the C256)

#define SIO_FDC_MSR  (*(volatile unsigned char *)0xAF13F4)  // Read - Main Status Register
#define FDC_MSR_DRV0BSY  0x01  // Indicates if drive 0 is busy
#define FDC_MSR_DRV1BSY  0x02  // Indicates if drive 1 is busy
#define FDC_MSR_CMDBSY  0x10  // Indicates if a command is in progress
#define FDC_MSR_NONDMA  0x20  //
#define FDC_MSR_DIO  0x40  // Data direction: 1 = read, 0 = write
#define FDC_MSR_RQM  0x80  // 1 = host can transfer data, 0 = host must wait

#define SIO_FDC_DSR  (*(volatile unsigned char *)0xAF13F4)  // Write - Data Select Register
// Bit[0..1] = data rate
// Bit[2..4] = precompensation select
#define FDC_DSR_LOPWR  0x40  // Turn on low power mode
#define FDC_DSR_RESET  0x80  // Software reset of the FDC

#define SIO_FDC_DTA  (*(volatile unsigned char *)0xAF13F5)  // Read/Write - Data - FIFO

#define SIO_FDC_RSV  (*(volatile unsigned char *)0xAF13F6)  // Reserved

#define SIO_FDC_DIR  (*(volatile unsigned char *)0xAF13F7)  // Read - Digital Input Register
#define FDC_DIR_DSKCHG  0x80  // Indicates if the disk has changed

#define SIO_FDC_CCR  (*(volatile unsigned char *)0xAF13F7)  // Write - Configuration Control Register
// Bit[0..1] = Data rate

//
// Bank 0 Status Register Bitfields and Masks
//

// ST0
#define FDC_ST0_DRVSEL  0x03  // Mask for the current selected drive
#define FDC_ST0_HEAD  0x04  // Bit for the current selected head
#define FDC_ST0_EC  0x08  // Bit for EQUIPMENT CHECK, error in recalibrate or relative seek
#define FDC_ST0_SEEKEND  0x10  // The FDC completed a seek, relative seek, or recalibrate
#define FDC_ST0_INTCODE  0xC0  // Mask for interrupt code:
                          //   00 = normal termination of command
                          //   01 = Abnormal termination of command
                          //   10 = Invalid command
                          //   11 = Abnormal termination caused by polling

// ST1
#define FDC_ST1_MA  0x01  // Missing address mark
#define FDC_ST1_NW  0x02  // Not writable (disk is write protected)
#define FDC_ST1_ND  0x04  // No data
#define FDC_ST1_OR  0x10  // Overrun/underrun of the data
#define FDC_ST1_DE  0x20  // Data error... a CRC check failed
#define FDC_ST1_EN  0x80  // End of cylinder: tried to acess a sector not on the track

// ST2
#define FDC_ST2_MD  0x01  // Missing address mark: FDC cannot detect a data address mark
#define FDC_ST2_BC  0x02  // Bad cylinder
#define FDC_ST2_WC  0x10  // Wrong cylinder: track is not the same as expected
#define FDC_ST2_DD  0x20  // Data error in field: CRC error
#define FDC_ST2_CM  0x40  // Control mark

// ST3
#define FDC_ST3_DRVSEL  0x03  // Drive select mask
#define FDC_ST3_HEAD  0x04  // Head address bit
#define FDC_ST3_TRACK0  0x10  // Track 0: Status of the TRK0 pin
#define FDC_ST3_WP  0x40  // Write Protect: status of the WP pin

//
//  FDC Commands
//

#define FDC_CMD_READ_TRACK          = 2
#define FDC_CMD_SPECIFY             = 3
#define FDC_CMD_SENSE_DRIVE_STATUS  = 4
#define FDC_CMD_WRITE_DATA          = 5
#define FDC_CMD_READ_DATA           = 6
#define FDC_CMD_RECALIBRATE         = 7
#define FDC_CMD_SENSE_INTERRUPT     = 8
#define FDC_CMD_WRITE_DELETED_DATA  = 9
#define FDC_CMD_READ_ID             = 10
#define FDC_CMD_READ_DELETED_DATA   = 12
#define FDC_CMD_FORMAT_TRACK        = 13
#define FDC_CMD_DUMPREG             = 14
#define FDC_CMD_SEEK                = 15
#define FDC_CMD_VERSION             = 16
#define FDC_CMD_SCAN_EQUAL          = 17
#define FDC_CMD_PERPENDICULAR_MODE  = 18
#define FDC_CMD_CONFIGURE           = 19
#define FDC_CMD_LOCK                = 20
#define FDC_CMD_VERIFY              = 22
#define FDC_CMD_SCAN_LOW_OR_EQUAL   = 25
#define FDC_CMD_SCAN_HIGH_OR_EQUAL  = 29

#define FDC_CMD_MT  0x80  // Command bit to turn on multi-track
#define FDC_CMD_MFM  0x40  // Command bit to operate in MFM format
#define FDC_CMD_SK  0x20  // Command bit to skip deleted sectors
#define FDC_CMD_EIS  0x40  // Command bit to turn on implied seek

//
// Floppy device command codes
//
#define FDC_DEVCMD_MOTOR_ON         = 1       // Device code to turn the motor on
#define FDC_DEVCMD_MOTOR_OFF        = 2       // Device code to turn the motor off
#define FDC_DEVCMD_RECAL            = 3       // Device code to recalibrate the drive
