#ifndef __ArtNetAcnGlobal_H
#define __ArtNetAcnGlobal_H

/*

 Copyright Artistic Licence Holdings Ltd 1997-2017

 Headers for ArtNetAcn.dll

 Authors:

 Wayne Howell
 Benoit Massicot

 Released:		16/8/97
 Last Revised:	        24/8/98	Aux calls added
 Last Revised:         18/6/2001   Art-Net & Win2k added
 Last Revised:         26/3/2002 DllRevision = 5. Implemented Art-Net V1.4n
 Last Revised:         11/4/2003 DllRevision = 9.
 Last Revised:         25/7/03   DllRevision = 16. RDM V1.0 implemented.
 Last Revised:         25/5/04   DllRevision = 26. RDM Sub Devices implemented.
 Last Revised:         12/7/04   DllRevision = 27. User file transfer implemented.
 Last Revised:         20/6/05   DllRevision = 34. MaxNodes increased.
 Last Revised:         20/6/05   DllRevision = 84. MaxNodes & Pipes increased.
 Last Revised:         18/10/10  DllRevision = 90. MaxNodes & Pipes increased.
 Last Revised:         15/12/11  DllRevision = 109. Added 'Lost' timer to nodes.
 Last Revised:         22/5/12  DllRevision = 118. MaxNodes & Pipes increased to 300.
 Last Revised:         3/6/13  DllRevision = 2.008. New version numbering. OSC added
 This list is no longer updated - see about box.

 */

#include "Art-Net.h"
#include "Art-NetDeprecated.h"
#include "sACN.h"
#include "KiNet.h"
#include "ArtOsc.h"
#define	MaxNodes				600
#define	MaxPipes				600
#define	MaxDriverChannels		MaxPipes*MaxDataLength
#define MaxRoutePresets         50      // number of Art-Net routing patchs
#define MaxPersonalities		8		// Max personalities supported by driver
#define MaxRdmDevicePerUniverse 512
#define MaxSensor				32		// Max number of root sensors allowed
#define MaxSubDevice			512		// Max number of sub devices allowed
#define MaxTxIpInTable			4		// Max number of node IP addresses to which we unicast prior to forcing broadcast mode
#define RdmRetry                5       // Max number of retries to get rdm data
#define RdmRetrySet             10      // Max number of retries to set rdm data
#define MaxLegendLength			32		// Max char in swin/swout text labels.
#define TimerBackupReload		12000	// mS to wait without packet detected for fail-over

#define MaxLostTimer			4		//number of missed ArtPollReply packets to flag a node as lost

// FlagMax
#define UdpStatus Status_Trace

// #define Debug 1   // rem this out in release version

// Defines are used to set the priority of rdm messages within the scheduler, 0=high priority.
// If you change these, re-order the case statement in Timer2Timer

#define FlagSetStart             0
#define FlagSetSubStart          1
#define FlagSetSubLocate         2
#define FlagSetLocate            3
#define FlagSetPers              4
#define FlagSetDeviceLabel       5
#define FlagSetDisplayLevel      6
#define FlagGetPers              7
#define FlagGetSubs              8
#define FlagGetModel             9
#define FlagGetStart             10
#define FlagGetFoot              11
#define FlagGetSubFoot           12
#define FlagGetSupported         13
#define FlagGetSubSupported      14
#define FlagGetDeviceLabel       15
#define FlagGetRdmSub            16
#define FlagGetManufacturer      17
#define FlagGetSoftwareVersion   18
#define FlagGetSubStart          19
#define FlagGetDeviceHours       20
#define FlagGetLampHours         21
#define FlagGetLampStrikes       22
#define FlagGetDeviceId          23
#define FlagGetSensorCount       24
#define FlagGetSensorDescription 25
#define FlagGetSensorValue       26
#define FlagGetPersDescription   27
#define FlagGetPoll              28

#define FlagMax                  29

// -----------------------------------------------------------
//
// The PipeEntry structure provides access to all
// Art-Net Tx & Rx data
//
// -----------------------------------------------------------

typedef struct
	{
	bool TxEnable;  // true if this transmit is enabled
	T_ArtDmx TxDmx; // Contains the transmit Dmx data
	T_ArtDmx RxDmx; // Contains the receive Dmx data
	WORD RxRequestUniverse;
	// User sets the Universe number of the data that
	// the application would like to receive. Only low
	// 15 bits used: High Nibble = Subnet.
	// Application sets to 0xffff, Driver will then fill
	// table with first received packets.

	BYTE RxIpAddress[4];
	// Set to the IP address from which data was last received

	ulong RxFirstIpSeen;	//Log the IP that opened the pipe


	WORD RxPacketCount; // ArtDmx packet received counter
	WORD TxPacketCount; // ArtDmx packet sent counter

	unsigned long RxPacketCycleCount; // ArtDmx packet count between timers for refresh rate calculation
	unsigned long RxRateRefresh;      // Units = packets per 10 sec

	// The following entries are private to the driver

	BYTE TxProtocol; // Protocol to output from this pipe
	// #define ProtocolArtNetAutomatic	0	//send Art-Net to unicast array as defined in spec
	// #define ProtocolArtNetManual		1	//send Art-Net to TxIpManual
	// #define ProtocolsAcnAutomatic		2	//send sAcn to multicast address
	// #define ProtocolsAcnManual		3	//send sAcn to TxIpManual
	// #define ProtocolShowNet		4	//send ShowNet to TxIpManual
	// #define ProtocolKiNetDmxOut		5	//send Kinet v1 to TxIpManual
	// #define ProtocolKiNetPortOut		6      	//send Kinet v2 to TxIpManual

	BYTE TxIpManual[4];
	// The manual Tx IP address, used if TxProtocol>0

	BYTE TxKiNetPort;
	// The port number for ProtocolKiNetPortOut

	BYTE TxNodeArtNetIpTable[MaxTxIpInTable][4];
	// Set to the IP addresses of the node to which this pipe is transmitting. Art-Net only

	bool RxMaxMinChange;
	bool TxMaxMinChange;
	bool RxDataChange;
	bool RxDataTimeout;
	bool TxDataChange;
	bool TxRefreshed;

	} PipeEntry;

// -----------------------------------------------------------
//
// The _RdmDevice structure provides a list of all devices
// attached to a port of a node
//
// -----------------------------------------------------------

typedef struct S_RdmSensor
	{

	S_RdmSensor* LastSensorPtr; // Linked list. Null for start and end.
	S_RdmSensor* NextSensorPtr;

	bool Valid;   // Set once data received
	bool Warning; // Set if sensor is within 10% of nominal limits.
	bool Error;   // Set if sensor has exceeded nominal limits

	T_SensorDescription SensorDescription;
	T_SensorValue SensorValue;

	} _RdmSensor;

typedef struct S_RdmSubDevice
	{

	S_RdmSubDevice* LastSubPtr; // Linked list. Null for start and end.
	S_RdmSubDevice* NextSubPtr;

	int Index;  // Number of this sub device
	bool Valid; // Set once existance proven

	int StartAddress; // DMX Start Address
	int FootPrint;    // Number dmx channels used by sub device

	int PrivateStartAddress; // Used for setting start address
	int PrivateLocate;       // Used for setting locate mode
	int FlagsSetStart;
	int FlagsGetStart;
	int FlagsGetFoot;
	int FlagsSetLocate;
	bool FlagStartVerify;	//cleared by SetStart and set when a GetStart verifies
	} _RdmSubDevice;

// -----------------------------------------------------------
//
// The _RdmDevice structure provides a list of all devices
// attached to a port of a node
//
// -----------------------------------------------------------

typedef struct S_RdmDevice
	{

	S_RdmDevice* LastPtr; // Linked list. Null for start and end.
	S_RdmDevice* NextPtr;

	bool Valid; // Set to true when device first discovered
	// Set to false if device is lost by network

	bool AddToList; // Set when device first discovered, reset when
	// added to node display list

	unsigned char DevRdmVer; // 0= device is draft rdm, 1= standard rdm

	T_Uid Uid; // The UID of this device

	_RdmSensor* RdmSensorPtr;

	_RdmSubDevice* RdmSubPtr;

	int StartAddress; // DMX Start Address
	int FootPrint;    // Number dmx channels used by device
	int Pers;         // Personality numbers from zero
	int PersMax;      // Available personalities

	int SubDeviceCount; // Number of sub devices

	int CountDeviceHours;
	int CountLampHours;
	int CountLampStrikes;
	int DeviceId;

	bool Pending; // Used in discovery to handle multiple TOD packets

	bool ApplicationRedraw;
	// Set when any data changes. Application resets this after screen refresh

	char Manufacturer[COUNT_MANUFACTURER_LABEL + 1];
	// Name of manufacturer, zero terminated

	char Model[COUNT_DEVICE_MODEL_DESCRIPTION + 1];
	// Name of manufacturer, zero terminated

	char DeviceLabel[COUNT_DEVICE_LABEL + 1];
	// User programmed device name

	char SoftwareLabel[COUNT_SOFTWARE_LABEL + 1];
	// Software string from device

	T_Software SoftwareVersion;
	// Packed as per RDM data format

	char PersonalityLabel[MaxPersonalities][COUNT_PERSONALITY_DESCRIPTION + 1];

	// Following are private to the driver

	// Get... are used internally by driver to sequence RDM
	// message traffic.

	int Private[FlagMax];

	int PrivateNewStart;
	// New start address to be programmed by scheduler
	int PrivateNewPers;
	// New personality to be programmed by scheduler
	uchar PrivateNewDisplayLevel;
	// Display Level to be programmed by scheduler
	int PrivateNewLocate;

	char PrivateNewDeviceLabel[COUNT_DEVICE_LABEL + 1];
	// New device label to be programmed by scheduler

	bool SensorPending; // Used internally to flag that display of sensors needs rebuild

	bool SubPending; // Used internally to flag that display of sub devices needs rebuild

	bool RootSupportedPending;
	// Used internally to flag that display of root supported pids needs rebuild

	bool SubSupportedPending;
	// Used internally to flag that display of sub supported pids needs rebuild

	int SensorRootCount;
	// Number of sensors in root device, -1 = unknown

	int SensorRootTestCount;
	// Cycle counter for retrieving sensor descriptions

	int SensorSubCount;
	// Number of sensors in sub devices, -1 = unknown

	uchar FirmwareResponse;
	// Semaphore used for device firmware upload

	ushort FirmwareBlockSize;
	// Byte block size used for device firmware upload

	ushort PidList[MaxSupportedPid];
	// List of supported pids.

	ushort SubPidList[MaxSupportedPid];
	// List of supported pids for sub devices.

	T_PresetBlock PresetBlock;
	// Holds last preset block received on this device

	} _RdmDevice;

// -----------------------------------------------------------
//
// The NodeEntry structure provides access to all
// Art-Net Node data processed by the driver
//
// -----------------------------------------------------------

typedef struct
	{

	BYTE IpAddress[4];
	// Read Only
	// Driver fills this field with the IP address of the node
	// from which the reply was received.

	// The following structure is filled by the driver when
	// an ArtPollReply is received.

	bool IpOffNet; // This device not on our NetId but is Art-Net device

	T_ArtPollReply ArtPollReply;
	T_ArtIpProgReply ArtIpProgReply;
	// Driver polls for this info once only after node is discovered

	bool Enumerated;  // Used internally to driver.
	bool NeedDisplay; // Used internally to driver.
	bool ForceTod;    // Used internally to driver.
	bool AddBranch;   // Used internally to driver.

	BYTE LostTimer;
	// The lost timer is incremented by every ArtPoll but locks at MaxLostTimer which means a lost node.
	// Each ArtPollReply zeroes it.

	BYTE FirmwareReplyType; // Used internally for firmware upload handshake
	unsigned char RdmVer;   // =1 for RDM standard; =0 for draft

	_RdmDevice* RdmDevicePtr[4]; // Linked list of RDM devices discovered on each port of a node

	// Driver Private data.

	T_ArtDirectoryList* ArtDirectoryListPtr;
	bool ArtDirectoryChange;

	T_ArtPollFpReply* ArtPollFpReplyPtr;
	bool ArtPollFpRefresh;
	bool ArtPollTpRefresh;

	char LegendSwout[MaxLegendLength + 1]; // these are set by ArtCommand to give node inputs and outputs friendly names.
	char LegendSwin[MaxLegendLength + 1];

	} NodeEntry;

// -----------------------------------------------------------
//
// The FileManager contains data related to retrieving
// files from nodes
//
// -----------------------------------------------------------

typedef struct
	{

	bool RetrieveActive; // true if file transfer in progress
	unsigned long Length;
	unsigned long SoFar; // used for progress bar
	int FileHandle;      // the file being retrieved
	int Node;
	bool CompleteGood;
	bool CompleteBad;
	unsigned char LastBlock;

	} T_FileManager;


// -----------------------------------------------------------
//
// The _PacketLog structure is used for diagnostic packet
// monitoring in DMX-Workshop
//
// -----------------------------------------------------------

typedef struct
	{
	unsigned long Count;      // Count of packets between heartbeaks.
	unsigned long Frequency;  // Packet frequency for last sample
	unsigned long TotalCount; // Totals
	} _LogEntry;

typedef struct S_PacketLog
	{
	_LogEntry LogEntry[PkMax];

	} _PacketLog;

// -----------------------------------------------------------
//
// The _ArtNetControl structure houses misc control data
//  for the driver.
//
// -----------------------------------------------------------
typedef struct S_ArtNetControl
	{
	bool	ListenOnly;					//should driver listen only
	bool	GlobalArtSync;				//send ArtSync
	bool 	PollSuspend;        		//
	bool 	FastPollEnabled;
	bool 	StressActive;
	bool 	StartCodeHasChanged;
	bool 	BackGroundRdmEnabled;   	// true to allow continuous poll and sensor traffic
	bool 	KeepAliveEnabled;			// enable 3s keep alive on output
	bool 	BackupMode;					// true if we are the backup device
	bool 	BackupDoOutput;				// true if we should output to network
	int 	BackupStatus;
									// 0 = we have never seen a BackupIpPacket - we are dormant
									// 1 = we have seen packets - we are dormant
									// 2 = we have lost packets and are live.
	int 	FastPollNode;
	int 	FastPollPort;
	int 	FastPollDev;
	int 	Prescale1sReload;
	char 	LastLoopSet;				   // keeps a record of loop / merge for display in the popup menu
	String  HostIpAddress;                 // long dot format
	String  HostBroadcastIpAddress;        // long dot format
	String  HostLimitedBroadcastIpAddress; // long dot format
	String  HostNetmask;                   // long dot format

	String  		BackupIpAddress; 				// we monitor this for a fail-over trigger
	String  		OscTxIpAddress; 				// IP of the iPad
	String  		OscRxIpAddress; 				// That is our Nic
	String  		FirmwarePath;   				// Where to load firmware

	bool			EmulReplyEnable;				// Enable emulated reply mode - this sends ArtPollReplies for all enabled receive pipes
	unsigned int	EmulReplyOemCode;				// The oem code that this product is emulating
	int				EmulReplyPerPacket;				// The number of pipes (1-4) per ArtPollReply
	String			EmulReplyName;					// The name used in emulated reply ArtProolReply

	T_ArtAddress 	ArtAddress;
	T_ArtPoll 		ArtPoll;
	T_ArtIpProg 	ArtIpProg;

	T_ArtTodRequest ArtTodRequest;
	T_ArtTodControl ArtTodControl;
	T_ArtTrigger 	ArtTrigger;
	T_ArtTimeCode 	ArtTc;
	T_ArtDirectory 	ArtDirectory;
	T_ArtRdm 		ArtRdm;       			// Used for application calls
	T_ArtRdmSub 	ArtRdmSub; 				// Used for application calls
	T_FileManager 	FileManager;
	T_ArtTimeSync 	ArtTimeSync;
	T_ArtFileReply 	ArtFileReply;
	T_ArtSync 		TxArtSync;
	T_ArtCommand	ArtCommand;

	TsAcn 			TxAcn;                  // Temp buffer for sending sACN
	TKiNetDmxOut 	TxKiNetDmxOut;     		// Temp buffer for sending KiNetDmxOut
	TKiNetPortOut 	TxKiNetPortOut;   		// Temp buffer for sending KiNetPortOut
	TKiNetPortSync 	TxKiNetPortSync; 		// Temp buffer for sending KiNetPortSync

	T_ArtPollReply 	EmulArtPollReply;       // Used for emulated response mode - to publish the pipe we are receiving

	} _ArtNetControl;



#endif
