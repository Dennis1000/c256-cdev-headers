////
//// Data storage needed by the file system (internal variables user apps shouldn't need)
////
//// NOTE: these locations are correct for the C256 Foenix FMX
////

// Device information from master boot record and boot sector

#define DOS_HIGH_VARIABLES       (*(volatile unsigned char *)0x38A000)
#define DEVICE                   (*(volatile unsigned char *)0x38A000)  // 1 byte - The number of the block device
#define FILE_SYSTEM              (*(volatile unsigned char *)0x38A001)  // 1 byte - The type of filesystem (FAT12, FAT32, etc.)
#define PARTITION                (*(volatile unsigned char *)0x38A002)  // 1 byte - The number of the partitions on the device
#define SECTORS_PER_CLUSTER      (*(volatile unsigned char *)0x38A003)  // 1 byte - The number of sectors in a cluster
#define FIRSTSECTOR              (*(volatile unsigned char *)0x38A004)  // 4 bytes - The LBA of the first sector on the volume
#define SECTORCOUNT              (*(volatile unsigned char *)0x38A008)  // 4 bytes - The number of sectors in the volume
#define NUM_RSRV_SEC             (*(volatile unsigned char *)0x38A00C)  // 2 bytes - The number of hidden or reserved sectors
#define CLUSTER_SIZE             (*(volatile unsigned char *)0x38A00E)  // 2 bytes - The size of a cluster in bytes
#define SEC_PER_FAT              (*(volatile unsigned char *)0x38A010)  // 4 bytes - The number of sectors per FAT
#define FAT_BEGIN_LBA            (*(volatile unsigned char *)0x38A014)  // 4 bytes - The LBA of the first sector of FAT #1
#define FAT2_BEGIN_LBA           (*(volatile unsigned char *)0x38A018)  // 4 bytes - The LBA of the first sector of FAT #2
#define CLUSTER_BEGIN_LBA        (*(volatile unsigned char *)0x38A01C)  // 4 bytes - The LBA of the first cluster in the storage area
#define ROOT_DIR_FIRST_CLUSTER   (*(volatile unsigned char *)0x38A020)  // 4 bytes - The number of the first cluster in the root directory
#define ROOT_DIR_MAX_ENTRY       (*(volatile unsigned char *)0x38A024)  // 2 bytes - The maximum number of entries in the root directory (0 = no limit)
#define VOLUME_ID                (*(volatile unsigned char *)0x38A026)  // 4 bytes - The ID of the volume

// Other variables we don't need in bank 0

#define DOS_CURR_CLUS            (*(volatile unsigned char *)0x38A02A)  // 4 bytes - The current cluster (for delete)
#define DOS_NEXT_CLUS            (*(volatile unsigned char *)0x38A02E)  // 4 bytes - The next cluster in a file (for delete)
#define DOS_DIR_BLOCK_ID         (*(volatile unsigned char *)0x38A032)  // 4 bytes - The ID of the current directory block
                                          //   If DOS_DIR_TYPE = 0, this is a cluster ID
                                          //   If DOS_DIR_TYPE = $80, this is a sector LBA
#define DOS_NEW_CLUSTER          (*(volatile unsigned char *)0x38A036)  // 4 bytes - Space to store a newly written cluster ID
#define DOS_SHORT_NAME           (*(volatile unsigned char *)0x38A03A)  // 11 bytes - The short name for a desired file
#define DOS_DIR_TYPE             (*(volatile unsigned char *)0x38A045)  // 1 byte - a code indicating the type of the current directory (0 = cluster based, $80 = sector based)
#define DOS_CURR_DIR_ID          (*(volatile unsigned char *)0x38A046)  // 4 byte - the ID of the first sector or cluster of the current directory
#define DOS_DEV_NAMES            (*(volatile unsigned char *)0x38A04A)  // 4 byte - pointer to the linked list of device names
#define FDC_MOTOR_TIMER          (*(volatile unsigned char *)0x38A04E)  // 2 bytes - count-down timer to automatically turn off the FDC spindle motor
#define DOS_MOUNT_DEV            (*(volatile unsigned char *)0x38A050)  // 1 byte - the device code of the currently mounted device

// Larger buffers

#define DOS_DIR_CLUSTER          (*(volatile unsigned char *)0x38A100)  // 512 bytes - A buffer for directory entries
#define DOS_DIR_CLUSTER_END      (*(volatile unsigned char *)0x38A300)  // The byte just past the end of the directory cluster buffer
#define DOS_SECTOR               (*(volatile unsigned char *)0x38A300)  // 512 bytes - A buffer for block device read/write
#define DOS_SECTOR_END           (*(volatile unsigned char *)0x38A500)  // The byte just past the end of the cluster buffer
#define DOS_FAT_SECTORS          (*(volatile unsigned char *)0x38A500)  // 1024 bytes - two sectors worth of the FAT
#define DOS_FAT_SECTORS_END      (*(volatile unsigned char *)0x38A900)  // The byte just past the end of the FAT buffers
#define DOS_BOOT_SECTOR          (*(volatile unsigned char *)0x38A900)  // A sector for holding the boot sector
#define DOS_BOOT_SECTOR_END      (*(volatile unsigned char *)0x38AB00)
#define DOS_SPARE_SECTOR         (*(volatile unsigned char *)0x38AB00)  // A spare 512 byte buffer for loading sectors
#define DOS_SPARE_SECTOR_END     (*(volatile unsigned char *)0x38AD00)
#define DOS_SPARE_FD             (*(volatile unsigned char *)0x38AD00)  // A spare file descriptor buffer
#define DOS_SPARE_FD_END        = DOS_SPARE_FD + SIZE(FILEDESC)

// Space for allocatable file descriptors (8 file descriptors of 32 bytes each)
#define DOS_FILE_DESCS          = DOS_SPARE_FD_END
#define DOS_FILE_DESCS_END      = DOS_FILE_DESCS + SIZE(FILEDESC) * DOS_FD_MAX

// Space for sector buffers for the file descriptors (8 buffers of 512 bytes each)
#define DOS_FILE_BUFFS           (*(volatile unsigned char *)0x38B000)
#define DOS_FILE_BUFFS_END      = DOS_FILE_BUFFS + DOS_SECTOR_SIZE * DOS_FD_MAX
