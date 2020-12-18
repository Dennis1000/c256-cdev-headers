#define DEF_NULL_CHAR            0x00
#define DEF_WILDCARD_CHAR        0x2A
#define DEF_SEPAR_CHAR1          0x5C
#define DEF_SEPAR_CHAR2          0x2F

// CH376S Commands
#define CH_CMD_CHECK_EXIST       0x06
//CH_CMD_RD_VAR8         = $0A     // Read 8Bit Value
//CH_CMD_WR_VAR8         = $0B     // Write 8Bit Value to controller
//CH_CMD_RD_VAR32        = $0C     // Read 32Bit Value
#define CH_CMD_GET_FILE_SIZE     0x0C
//CH_CMD_WR_VAR32        = $0D
#define CH_CMD_SET_MODE          0x15  // Set the Controller's mode, in our Case in SDCARD

#define CH_CMD_GET_STATUS        0x22  // Get Interrupt Status
#define CH_CMD_RD_DATA0          0x27  //
#define CH_CMD_WR_DATA           0x2C
#define CH_CMD_SET_FILENAME      0x2F  //SET_FILE_NAME
#define CH_CMD_DISK_MOUNT        0x31  //DISK_MOUNT
#define CH_CMD_FILE_OPEN         0x32  //FILE_OPEN
#define CH_CMD_FILE_ENUM_GO      0x33
#define CH_CMD_FILE_CLOSE        0x36  // To be Implemented
#define CH_CMD_BYTE_LOCATE       0x39
#define CH_CMD_BYTE_READ         0x3A
#define CH_CMD_BYTE_RD_GO        0x3B
#define CH_CMD_BYTE_WRITE        0x3C
#define CH_CMD_BYTE_WR_GO        0x3D

// Varial When Reading 8Bits or 32Bits Values From controller
#define CH_VAR_DISK_ROOT		 0x44
#define CH_VAR_DSK_TOTAL_CLUS	 0x48
#define CH_VAR_DSK_START_LBA	 0x4C
#define CH_VAR_DSK_DAT_START	 0x50
#define CH_VAR_LBA_BUFFER		 0x54
#define CH_VAR_LBA_CURRENT		 0x58
#define CH_VAR_FAT_DIR_LBA		 0x5C
#define CH_VAR_START_CLUSTER	 0x60
#define CH_VAR_CURRENT_CLUST	 0x64
#define CH_VAR_FILE_SIZE		 0x68
#define CH_VAR_CURRENT_OFFSET	 0x6C


// Interruption state in SD card
#define CH376S_STAT_SUCCESS      0x14
#define CH376S_STAT_BUF_OVF      0x17
#define CH376S_STAT_DSK_RD       0x1D
#define CH376S_STAT_DSK_WR       0x1E
// File system notice code in SD card
#define CH376S_ERR_OPEN_DIR      0x41
#define CH376S_ERR_MISS_FIL      0x42
#define CH376S_ERR_FOUND_NAME    0x43
//File system error code in SD card
#define CH376S_ERR_DISK_DSC      0x82
#define CH376S_ERR_LRG_SEC       0x84
#define CH376S_ERR_PARTTION      0x92
#define CH376S_ERR_NOT_FORM      0xA1
#define CH376S_ERR_DSK_FULL      0xB1
#define CH376S_FDT_OVER          0xB2
#define CH376S_FILE_CLOSED       0xB4

#define CH376S_CMD_RET_SUCCESS   0x51
#define CH376S_CMD_RET_ABORT     0x5F

#define SDCARD_PRSNT_NO_CARD     0x00
#define SDCARD_PRSNT_CD          0x01
#define SDCARD_PRSNT_WP          0x02
#define SDCARD_PRSNT_MNTED       0x04  // Card is present and Mounted1
