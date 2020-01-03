#ifndef _ARTNET_DEPRECATED_H_
#define _ARTNET_DEPRECATED_H_


#define uchar unsigned char
#define ushort unsigned short int
#define ulong unsigned int

#define MaxExNumPorts 32



/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Video related packet structures
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
typedef struct S_ArtVideoSetup {
	uchar ID[8];                    // protocol ID = "Art-Net"
	ushort OpCode;                  // == OpVideoSetup
	uchar VersionH;                 // 0
	uchar Version;                  // protocol version, set to ProtocolVersion
	uchar Filler1;			// 0
	uchar Filler2;                  // 0

	uchar Filler3;                  // 0
        uchar Filler4;                  // 0
	uchar Control;                  // 0 = local video, 1 = use ArtVideoData

	uchar FontHeight;               // Scan lines per char. 8-16 valid

	uchar FirstFont;                // First font to program  0-255

	uchar FontRange;                // Number fonts to program  1-(255-FirstFont)

	char WinFontName[MaxWinFontChar];
                                        // nearest windows font, null if not used
	uchar FontData[MaxFontChar*MaxFontHeight];
					// font data, array defined to max size


} T_ArtVideoSetup;


typedef struct S_ArtVideoPalette {
	uchar ID[8];                    // protocol ID = "Art-Net"
	ushort OpCode;                  // == OpVideoPalette
	uchar VersionH;                 // 0
	uchar Version;                  // protocol version, set to ProtocolVersion
	uchar Filler1;			// 0
	uchar Filler2;                  // 0
	uchar ColourRed[MaxColourPalette];    // New red values, 0x00 - 0x3f
	uchar ColourGreen[MaxColourPalette];  // New green values, 0x00 - 0x3f
	uchar ColourBlue[MaxColourPalette];   // New blue values, 0x00 - 0x3f


} T_ArtVideoPalette;


typedef struct S_ArtVideoData {
	uchar ID[8];                    // protocol ID = "Art-Net"
	ushort OpCode;                  // == OpVideoData
	uchar VersionH;                 // 0
	uchar Version;                  // protocol version, set to ProtocolVersion
	uchar Filler1;			// 0
	uchar Filler2;                  // 0
	uchar PosX;                     // Start X Coord, 0 - VideoColumns-1
	uchar PosY;                     // Start Y Coord, 0 - VideoLines-1
	uchar LenX;                     // Number of char in each line, 0 - VideoColums-PosX
	uchar LenY;                     // Number of lines, 0 - VideoLines-PosY


	ushort Data[MaxVideoX*MaxVideoY];
					// New character data

} T_ArtVideoData;


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Status packet from Four-Play
//
// This is broadcast by Four-Play, Unicast by controller to program the product
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
//

#define FpStatAutoRun   0       // Autobackup active - awaiting failure
#define FpStatAutoWait  1       // Autobackup active - failed
#define FpStatLoop      2       // Loop mode
#define FpStatPlay      3       // Play
#define FpStatPlayPause 4       // Play pause
#define FpStatPlayTrig  5       // Play awaiting trigger
#define FpStatRec       6       // Record
#define FpStatRecPause  7       // Record pause
#define FpStatRecTrig   8       // Record awaiting trigger
#define FpMax           9


typedef struct S_FpMac {
	uchar Name[10];
        uchar Mode;                     // trigger mode
        uchar Data1;
        uchar Data2;
} T_FpMac;


typedef struct S_ArtPollFpReply {
	uchar ID[8];                    // protocol ID = "Art-Net"
	ushort OpCode;                  // == OpPollFpReply
	T_Addr BoxAddr;                 // 0 if not yet configured

	uchar VersionInfoH;             // The node's current FIRMWARE VERS hi
	uchar VersionInfo;              // The node's current FIRMWARE VERS lo

	uchar Filler1;			// 0
	uchar Filler2;                  // 0

	uchar OemH;
        uchar Oem;			// Manufacturer code, bit 15 set if
                                        // extended features avail


        ushort EstaMan;			  // Reserved for ESTA manufacturer id lo, zero for now

	uchar ShortName[ShortNameLength];       // short name defaults to IP
	uchar LongName[LongNameLength];         // long name
	uchar StatusReport[LongNameLength];     // same as vdu status line

        uchar Flags;                    // bit 7 = 1 for master time sync
        uchar Prog;                     // == 0x81 to program, == 0x00 for information.

        uchar NumPorts;                  // number of ports implemented

	uchar PortStat[MaxExNumPorts];    // As per Stat defines

	uchar RxSource[MaxExNumPorts];    // bit 1 = 0 for DMX, = 1 for Art-Net

	uchar RxUniverse[MaxExNumPorts];  // sub-net and universe for each input

	uchar TxDest[MaxExNumPorts];      // bit 1 = 1 to enable network output

	uchar TxUniverse[MaxExNumPorts];  // sub-net and universe for each output

        uchar TrigChanHi;

        uchar TrigChanLo;

        uchar ElapsedTime[4];           // Hi byte first. Elapsed time in mS

        uchar CurrentFileTime[4];       // Hi byte first. Length of selected file in mS

        uchar TimeCode[4];              // Hi byte first. Received timecode

        uchar CurrentFile;

        uchar BootMode;

        uchar BootFile;

        uchar PanelLock;                // Bit 0=1 to lock out front panel

        uchar MidiChannel;

        uchar MidiNote;

        uchar RemoteMode;               // Bit 0=1 to disable remote trigger until file playback completed

	T_FpMac Macro[16];              // macro and remotes

        uchar Filler[32];               // Filler bytes, currently zero.

} T_ArtPollFpReply;


#define KeyText		4       //Payload contains text
#define KeyPlay         10      //Device start playing current file
#define KeyPause        11      //Device pause current playback or record
#define KeyContinue     12      //Device continue current playback or record from current location
#define KeyPlayTrig     13      //Device enter play pause and await trigger
#define KeyRec          14      //Device start recording to current file
#define KeyRecTrig      15      //Device enter record pause and await trigger
#define KeyScanRev      16      //Scan reverse by number of frames defined in Data[0], enter play pause
#define KeyScanFwd      17      //Scan forward by number of frames defined in Data[0], enter play pause
#define KeyLocate       18      //Locate frames defined in Data[0]msb->Data[7]lsb, enter play pause
#define KeyEtoE         19      //Switch inputs to outputs configuration. Data[x] defines loop through state
				//where first array entry is first DMX universe. 1= loop, 0=playback
#define KeyStop         20      //Device stop playback or record
#define KeyAutoRun      21      //Run in automatic mode


#define KeyCursUp        100     //Cursor Up
#define KeyCursDown      101     //Cursor Down
#define KeyCursLeft      102     //Cursor Left
#define KeyCursRight     103     //Cursor Right

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
// Strand Show-Net Deinitions
//
// Note: This information is taken from a combination of:
//
//       A) The original ShowNet document that was released by Strand.
//       B) Empirical tests on actual product.
//
// It should be noted that these two sources of information conflict!
// As Strand has decided not to publish the latest specification, information
//  is limited.
//
// Artistic Licence acknowledge all trade marks
//
/////////////////////////////////////////////////////////////////////////////////////////////////////
//
typedef struct S_ShowDmx {
	uchar SignatureHi;              // protocol ID = 0x80
        uchar SignatureLo;              // protocol ID = 0x8f
	uchar IP[4];	                // IP address, first entry in array is MSB.
        ushort NetSlot[4];              // The packet can contain up to 4 non contiguous blocks, this is the start channel of each.
        ushort SlotSize[4];             // The number of channels in each block, 0 if block not used
        ushort IndexBlock[5];           // Index into Data for each block of data
        uchar PacketCountHi;            // Packet count
        uchar PacketCountLo;            // Packet count
        uchar BlockD[4];                // No idea!
        uchar Name[9];                  // name of console
        uchar Data[MaxDataLength];
} T_ShowDmx;







#endif
