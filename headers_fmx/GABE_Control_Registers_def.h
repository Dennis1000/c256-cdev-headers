//GABE Control Registers

//$AFE880..$AFE887

#define GABE_MSTR_CTRL       (*(volatile unsigned char *)0xAFE880)
#define GABE_CTRL_PWR_LED    0x01  // Controls the LED in the Front of the case (Next to the reset button)
#define GABE_CTRL_SDC_LED    0x02  // Controls the LED in the Front of the Case (Next to SDCard)
#define GABE_CTRL_BUZZER     0x10  // Controls the Buzzer
#define GABE_CTRL_WRM_RST    0x80  // Warm Reset (needs to Setup other registers)

#define GABE_NOTUSED         (*(volatile unsigned char *)0xAFE881)  // Reserved for future use
#define GABE_RST_AUTH0       (*(volatile unsigned char *)0xAFE882)  // Must Contain the BYTE $AD for Reset to Activate
#define GABE_RST_AUTH1       (*(volatile unsigned char *)0xAFE883)  // Must Contain the BYTE $DE for Reset to Activate

// READ
#define GABE_RNG_DAT_LO      (*(volatile unsigned char *)0xAFE884)  // Low Part of 16Bit RNG Generator
#define GABE_RNG_DAT_HI      (*(volatile unsigned char *)0xAFE885)  // Hi Part of 16Bit RNG Generator

// WRITE
#define GABE_RNG_SEED_LO     (*(volatile unsigned char *)0xAFE884)  // Low Part of 16Bit RNG Generator
#define GABE_RNG_SEED_HI     (*(volatile unsigned char *)0xAFE885)  // Hi Part of 16Bit RNG Generator

// READ
#define GABE_RNG_STAT        (*(volatile unsigned char *)0xAFE886)  //
#define GABE_RNG_LFSR_DONE   0x80  // indicates that Output = SEED Database

// WRITE
#define GABE_RNG_CTRL        (*(volatile unsigned char *)0xAFE886)  //
#define GABE_RNG_CTRL_EN     0x01  // Enable the LFSR BLOCK_LEN
#define GABE_RNG_CTRL_DV     0x02  // After Setting the Seed Value, Toggle that Bit for it be registered

#define GABE_SYS_STAT        (*(volatile unsigned char *)0xAFE887)  //
#define GABE_SYS_STAT_MID0   0x01  // Machine ID -- LSB
#define GABE_SYS_STAT_MID1   0x02  // Machine ID -- MSB
#define GABE_SYS_STAT_EXP    0x08  // if Zero, there is an Expansion Card Preset
#define GABE_SYS_STAT_CPUA   0x40  // Indicates the (8bit/16bit) Size of the Accumulator
#define GABE_SYS_STAT_CPUX   0x80  // Indicates the (8bit/16bit) Size of the Accumulator


// Machine ID
// $00 = FMX - Development Platform
// $01 = C256 Foenix - Dev Platform
// $10 = C256 Foenix - User Version (65C816)
// $11 = TBD
