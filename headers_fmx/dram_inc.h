//
// Memory Map
//
#define SCREEN_PAGE0      (*(volatile unsigned char *)0xAFA000)  //8192 Bytes First page of display RAM. This is used at boot time to display the welcome screen and the BASIC or MONITOR command screens.
#define SCREEN_PAGE1      (*(volatile unsigned char *)0xAFC000)  //8192 Bytes Additional page of display RAM. This can be used for page flipping or to handle multiple edit buffers.
//SCREEN_PAGE2     = $AFE000 //8192 Bytes Additional page of display RAM. This can be used for page flipping or to handle multiple edit buffers.
//SCREEN_PAGE3     = $B00000 //8192 Bytes Additional page of display RAM. This can be used for page flipping or to handle multiple edit buffers.
#define SCREEN_END        (*(volatile unsigned char *)0xB00000)  //End of display memory
