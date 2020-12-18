// Pixel Layer Collision Detection Status
// This is the registers @ $AF:0300

//
#define COL_STAT_SP0  0x0001
#define COL_STAT_SP1  0x0002
#define COL_STAT_SP2  0x0004
#define COL_STAT_SP3  0x0008
#define COL_STAT_SP4  0x0010
#define COL_STAT_SP5  0x0020
#define COL_STAT_SP6  0x0040

#define COL_STAT_BM0  0x0080
#define COL_STAT_BM1  0x0100
#define COL_STAT_COL  0x0200

#define COL_STAT_TL0  0x0400
#define COL_STAT_TL1  0x0800
#define COL_STAT_TL2  0x1000
#define COL_STAT_TL3  0x2000
#define COL_RESERVE0  0x4000  // Reserved
#define COL_RESERVE1  0x8000  // Reserved

// Sprite Layers
#define COLLISION_SPRITE_L0_L    (*(volatile unsigned char *)0xAF0300)
#define COLLISION_SPRITE_L0_H    (*(volatile unsigned char *)0xAF0301)
#define COLLISION_SPRITE_L1_L    (*(volatile unsigned char *)0xAF0302)
#define COLLISION_SPRITE_L1_H    (*(volatile unsigned char *)0xAF0303)
#define COLLISION_SPRITE_L2_L    (*(volatile unsigned char *)0xAF0304)
#define COLLISION_SPRITE_L2_H    (*(volatile unsigned char *)0xAF0305)
#define COLLISION_SPRITE_L3_L    (*(volatile unsigned char *)0xAF0306)
#define COLLISION_SPRITE_L3_H    (*(volatile unsigned char *)0xAF0307)
#define COLLISION_SPRITE_L4_L    (*(volatile unsigned char *)0xAF0308)
#define COLLISION_SPRITE_L4_H    (*(volatile unsigned char *)0xAF0309)
#define COLLISION_SPRITE_L5_L    (*(volatile unsigned char *)0xAF030A)
#define COLLISION_SPRITE_L5_H    (*(volatile unsigned char *)0xAF030B)
#define COLLISION_SPRITE_L6_L    (*(volatile unsigned char *)0xAF030C)
#define COLLISION_SPRITE_L6_H    (*(volatile unsigned char *)0xAF030D)
// Bitmap Layers
#define COLLISION_BITMAP_L0_L    (*(volatile unsigned char *)0xAF030E)
#define COLLISION_BITMAP_L0_H    (*(volatile unsigned char *)0xAF030F)
#define COLLISION_BITMAP_L1_L    (*(volatile unsigned char *)0xAF0310)
#define COLLISION_BITMAP_L1_H    (*(volatile unsigned char *)0xAF0311)
#define COLLISION_COLMAP_L0_L    (*(volatile unsigned char *)0xAF0312)  // Collision Bitmap - Not Implemented yet
#define COLLISION_COLMAP_L0_H    (*(volatile unsigned char *)0xAF0313)
// Tile Map Layers
#define COLLISION_TILEMAP_L0_L   (*(volatile unsigned char *)0xAF0314)
#define COLLISION_TILEMAP_L0_H   (*(volatile unsigned char *)0xAF0315)
#define COLLISION_TILEMAP_L1_L   (*(volatile unsigned char *)0xAF0316)
#define COLLISION_TILEMAP_L1_H   (*(volatile unsigned char *)0xAF0317)
#define COLLISION_TILEMAP_L2_L   (*(volatile unsigned char *)0xAF0318)
#define COLLISION_TILEMAP_L2_H   (*(volatile unsigned char *)0xAF0319)
#define COLLISION_TILEMAP_L3_L   (*(volatile unsigned char *)0xAF031A)
#define COLLISION_TILEMAP_L3_H   (*(volatile unsigned char *)0xAF031B)

// When there is a collision the Pixel Value are stored here
#define COLLISION_PXL_VALUE_SP   (*(volatile unsigned char *)0xAF031C)
#define COLLISION_SPRITE_NUMBER  (*(volatile unsigned char *)0xAF031D)
#define COLLISION_PXL_VALUE_BM0  (*(volatile unsigned char *)0xAF031E)
#define COLLISION_PXL_VALUE_BM1  (*(volatile unsigned char *)0xAF031F)
#define COLLISION_PXL_VALUE_COL  (*(volatile unsigned char *)0xAF0320)
#define COLLISION_PXL_VALUE_TL0  (*(volatile unsigned char *)0xAF0321)
#define COLLISION_PXL_VALUE_TL1  (*(volatile unsigned char *)0xAF0322)
#define COLLISION_PXL_VALUE_TL2  (*(volatile unsigned char *)0xAF0323)
#define COLLISION_PXL_VALUE_TL3  (*(volatile unsigned char *)0xAF0324)

#define COLLISION_SPRITE_COORD_X_LO  (*(volatile unsigned char *)0xAF0326)
#define COLLISION_SPRITE_COORD_X_HI  (*(volatile unsigned char *)0xAF0327)
#define COLLISION_BITMAP_COORD_X_LO  (*(volatile unsigned char *)0xAF0328)
#define COLLISION_BITMAP_COORD_X_HI  (*(volatile unsigned char *)0xAF0329)
#define COLLISION_TILES_COORD_X_LO   (*(volatile unsigned char *)0xAF032A)
#define COLLISION_TILES_COORD_X_HI   (*(volatile unsigned char *)0xAF032B)
#define COLLISION_COORD_Y_LO         (*(volatile unsigned char *)0xAF032C)
#define COLLISION_COORD_Y_HI         (*(volatile unsigned char *)0xAF032D)

