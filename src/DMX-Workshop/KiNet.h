//////////////////////////////////////////////////////////////////////////
//
//	Copyright Artistic Licence Holdings Ltd 2012-2012
//	Author:	Wayne Howell
//	Email:	Support@ArtisticLicence.com
//
//	This file contains all key defines and structures for KiNet v1
//
//////////////////////////////////////////////////////////////////////////

#ifndef _KINET_H_
#define _KINET_H_

#define uchar unsigned char
#define ushort unsigned short int
#define ulong unsigned int
// 8, 16, 32 bit fields

#define KiNetHeaderMagicNumberSize		4
#define KiNetHeaderVersionSize			2
#define KiNetHeaderTypeSize			2
#define KiNetHeaderSequenceNumberSize		4


typedef struct {
	uchar	HeaderMagicNumber[KiNetHeaderMagicNumberSize];
	uchar	HeaderVersion[KiNetHeaderVersionSize];
	uchar	HeaderType[KiNetHeaderTypeSize];
	uchar	HeaderSequenceNumber[KiNetHeaderSequenceNumberSize];
} TKiNetHeader;

typedef struct {
	TKiNetHeader 	KiHeader;

	uchar		Port;			//not used
	uchar		Flags;			//not used
	uchar		TimerValueLo;		//not used
	uchar		TimerValueHi;		//not used

	uchar		Universe0;		//
	uchar		Universe1;		//
	uchar		Universe2;		//
	uchar		Universe3;		//

	uchar		StartCode;		//

	uchar		Payload[512];


} TKiNetDmxOut;

typedef struct {
	TKiNetHeader 	KiHeader;

	uchar		Universe0;		//
	uchar		Universe1;		//
	uchar		Universe2;		//
	uchar		Universe3;		//

	uchar		Port;			//1-16
	uchar		Pad;			//not used
	uchar		FlagsLo;		//Bit fields.
	uchar		FlagsHi;

	uchar		LengthLo;		//Limited to 512
	uchar		LengthHi;		// so we use fixed length


	uchar		StartCodeLo;		//This is not the DMX Start Code
	uchar		StartCodeHi;		//Set to zero

	uchar		Payload[512];


} TKiNetPortOut;

typedef struct {
	TKiNetHeader 	KiHeader;

	uchar		Universe0;		//
	uchar		Universe1;		//
	uchar		Universe2;		//
	uchar		Universe3;		//

	uchar		Pad[4];			//not used

} TKiNetPortSync;

#endif

