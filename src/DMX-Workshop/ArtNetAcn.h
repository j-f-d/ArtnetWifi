#ifndef __ArtNetAcn_H
#define __ArtNetAcn_H

#include "ArtNetAcnGlobal.h"

#define DLL_MODE __declspec(dllexport)

#define WN(S) ArtNetWideToNarrow(S, Narrow, sizeof(Narrow), true)

extern "C" WORD DLL_MODE ArtNetInit(int Command);
extern "C" WORD DLL_MODE ArtNetSetAcnIpByPipe(int ThisPipe, char* Ip);

extern "C" void DLL_MODE ArtNetEnd(void);
extern "C" void DLL_MODE ArtNetSkinEnable(bool Enable);
extern "C" bool DLL_MODE ArtNetReadWrite(int Pipe);
extern "C" bool DLL_MODE ArtNetSendSyncs(void);
extern "C" void DLL_MODE ArtNetEnableKeepAliveSyncs(bool Keep);

extern "C" void DLL_MODE ArtNetSendUdp(BYTE* Ptr, WORD Size);                           // broadcast
extern "C" void DLL_MODE ArtNetSendUdpUnicast(String Ip, BYTE* Ptr, WORD Size);			// unicast
extern "C" void DLL_MODE ArtNetSendUdpPrivate(int NodeIndex, BYTE* Ptr, WORD Size);     // to node's private address

extern "C" void DLL_MODE ArtNetSetCallBackFromTimeCode( void(*Function)( uchar Frames, uchar Seconds, uchar Minutes, uchar Hours, uchar Type) );
extern "C" void DLL_MODE ArtNetSetCallBackPromReceivePre( void(*Function)( T_IpPacket* packIpPtr, int lenIp, T_UdpPacket* packUdpPtr, int lenUdp, wchar_t* FromIp, wchar_t* ToIp) );
extern "C" void DLL_MODE ArtNetSetCallBackUdpReceivePre( void(*Function)( T_IpPacket* packIpPtr, int lenIp, T_UdpPacket* packUdpPtr, int lenUdp, wchar_t* FromIp, wchar_t* ToIp, bool* Handled) );
extern "C" void DLL_MODE ArtNetSetCallBackUdpReceivePost( void(*Function)( T_IpPacket* packIpPtr, int lenIp, T_UdpPacket* packUdpPtr, int lenUdp, wchar_t* FromIp, wchar_t* ToIp) );
extern "C" void DLL_MODE ArtNetSetCallBackUdpTransmit( void(*Function)( BYTE* Ptr, int NumberByte) );
extern "C" void DLL_MODE ArtNetSetCallBackRdmDeviceSelect( void(*Function)( _RdmDevice* RdmDevicePtr, int Node, int Port, int Dev) );
extern "C" void DLL_MODE ArtNetSetCallBackPacketCounter( void(*Function)( int a, int b, int c, int d) );
extern "C" void DLL_MODE ArtNetSetCallBackArtTrigger( void(*Function)( T_ArtTrigger* ArtTriggerPtr) );
extern "C" void DLL_MODE ArtNetSetCallBackOsc( void(*Function)( int Length, bool IsArtOsc, int Language, char* Vector, int Instance, int Parameter, char* FullString, int IntData1, int IntData2, char* Legend) );

extern "C" void DLL_MODE ArtNetCancelCallBack (void);
extern "C" void DLL_MODE ArtNetSetTxPipeUniverse (int Pipe, WORD NetUni);
extern "C" void DLL_MODE ArtNetEnableTxPipe(int Pipe);
extern "C" void DLL_MODE ArtNetDisableTxPipe(int Pipe);
extern "C" WORD DLL_MODE ArtNetGetTxPipeUniverse(int Pipe);
extern "C" void DLL_MODE ArtNetSetRxPipeRequestUniverse(int Pipe, WORD NetUni);
extern "C" bool DLL_MODE ArtNetIsRxPipeActive(int Pipe);
extern "C" bool DLL_MODE ArtNetIsTxPipeActive(int Pipe);

extern "C" void DLL_MODE ArtNetSetTxPipeKiNetPort (int Pipe, BYTE NewPort);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeKiNetPort (int Pipe);
extern "C" void DLL_MODE ArtNetSetTxPipeProtocol (int Pipe, BYTE NewProtocol);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeProtocol (int Pipe);
extern "C" void DLL_MODE ArtNetSetTxPipeManualIp (int Pipe, BYTE* NewIp);
extern "C" BYTE DLL_MODE* ArtNetGetTxPipeManualIp (int Pipe);

extern "C" WORD DLL_MODE ArtNetGetRxPipeRequestUniverse (int Pipe);
extern "C" void DLL_MODE ArtNetEnumerate(void);
extern "C" void DLL_MODE ArtNetSoftEnumerate(void);
extern "C" bool DLL_MODE ArtNetAnyArtNetReceived(void);

extern "C" String DLL_MODE ArtNetGetRxPipeIpAddress(int Pipe);
extern "C" String DLL_MODE ArtNetGetTxPipeIpAddress(int Pipe);
extern "C" String DLL_MODE ArtNetGetNodeIpAddress(int Node);
extern "C" String DLL_MODE ArtNetGetNodeIpBindAddress(int Node);
extern "C" int DLL_MODE ArtNetGetNodeIpBindLetter(int Node);
extern "C" String DLL_MODE ArtNetGetNodeMacString(int Node);
extern "C" String DLL_MODE ArtNetGetNodeIntegrityIndexString(int Node);
extern "C" String DLL_MODE ArtNetGetNodeSwinLegend(int Node);
extern "C" String DLL_MODE ArtNetGetNodeSwoutLegend(int Node);
extern "C" String DLL_MODE ArtNetGetNodeFailSafeString(int Node);


extern "C" WORD DLL_MODE ArtNetGetRxPipeUniverse(int Pipe);


extern "C" bool DLL_MODE ArtNetGetRxPipeStatusUbeaActive(int Pipe);
extern "C" bool DLL_MODE ArtNetGetTxPipeStatusUbeaActive(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeStatusUbeaActive(int Node);

extern "C" unsigned char DLL_MODE ArtNetGetRxPipeStatusIndicators(int Pipe);
extern "C" unsigned char DLL_MODE ArtNetGetTxPipeStatusIndicators(int Pipe);
extern "C" unsigned char DLL_MODE ArtNetGetNodeStatusIndicators(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeWebSupport(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeSquawk(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeMode7(void);
extern "C" unsigned char DLL_MODE ArtNetGetNodeDhcp(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeDhcpCapable(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeAcnCapable(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeOutputStyleCapable(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeOutputRdmSwitchCapable(int Node);

extern "C" unsigned char DLL_MODE ArtNetGetNodeFailOverCapable(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeFailOver(int Node);


extern "C" unsigned char DLL_MODE ArtNetGetRxPipeStatusAuthority(int Pipe);
extern "C" unsigned char DLL_MODE ArtNetGetTxPipeStatusAuthority(int Pipe);
extern "C" unsigned char DLL_MODE ArtNetGetNodeStatusAuthority(int Node);

extern "C" bool DLL_MODE ArtNetGetRxPipeStatusRdmCapable(int Pipe);
extern "C" bool DLL_MODE ArtNetGetTxPipeStatusRdmCapable(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeStatusRdmCapable(int Node);
extern "C" unsigned char DLL_MODE ArtNetGetNodeStatusRdmVersion(int Node);


extern "C" bool DLL_MODE ArtNetGetRxPipeStatusRomBoot(int Pipe);
extern "C" bool DLL_MODE ArtNetGetTxPipeStatusRomBoot(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeStatusRomBoot(int Node);


extern "C" BYTE DLL_MODE ArtNetGetRxPipeUbeaVersion(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeUbeaVersion(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeUbeaVersion(int Node);

extern "C" WORD DLL_MODE ArtNetGetRxPipeEstaMan(int Pipe);
extern "C" WORD DLL_MODE ArtNetGetTxPipeEstaMan(int Pipe);
extern "C" WORD DLL_MODE ArtNetGetNodeEstaMan(int Node);

extern "C" String DLL_MODE ArtNetGetRxPipeEstaManString(int Pipe);
extern "C" String DLL_MODE ArtNetGetTxPipeEstaManString(int Pipe);
extern "C" String DLL_MODE ArtNetGetNodeEstaManString(int Node);
extern "C" bool DLL_MODE ArtNetGetNodeIsIntegrityCapable(int Node);
extern "C" String DLL_MODE ArtNetGetEstaManString(WORD EstaCode);



extern "C" BYTE DLL_MODE ArtNetGetRxPipeOemH(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeOemH(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeOemH(int Node);

extern "C" BYTE DLL_MODE ArtNetGetRxPipeOem(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeOem(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeOem(int Node);

extern "C" String DLL_MODE ArtNetGetRxPipeOemString(int Pipe);
extern "C" String DLL_MODE ArtNetGetTxPipeOemString(int Pipe);
extern "C" String DLL_MODE ArtNetGetNodeOemString(int Node);
extern "C" String DLL_MODE ArtNetGetOemString(WORD Oem);
extern "C" String DLL_MODE ArtNetGetOemStringExt(WORD Oem);
extern "C" String DLL_MODE ArtNetGetDaliCommandString(int Command);
extern "C" String DLL_MODE ArtNetGetDaliAddressString(int Address);

extern "C" WORD DLL_MODE ArtNetSwapW(WORD Input);

extern "C" bool DLL_MODE ArtNetGetNodeRxImplemented(int Node, int Port);
extern "C" bool DLL_MODE ArtNetGetNodeTxImplemented(int Node, int Port);

extern "C" bool DLL_MODE ArtNetGetRxPipeRxReceived(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeRxReceived(int Node, int Port);

extern "C" bool DLL_MODE ArtNetGetRxPipeRxErrors(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeRxErrors(int Node, int Port);

extern "C" bool DLL_MODE ArtNetGetRxPipeRxTest(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeRxTest(int Node, int Port);

extern "C" bool DLL_MODE ArtNetGetRxPipeRxSip(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeRxSip(int Node, int Port);

extern "C" bool DLL_MODE ArtNetGetRxPipeRxText(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeRxText(int Node, int Port);

extern "C" bool DLL_MODE ArtNetGetRxPipeRxDisable(int Pipe);
extern "C" bool DLL_MODE ArtNetGetNodeRxDisable(int Node, int Port);

extern "C" WORD DLL_MODE ArtNetGetNodeRxUniverse(int Node, int Port);
extern "C" WORD DLL_MODE ArtNetGetNodeTxUniverse(int Node, int Port);


extern "C" bool DLL_MODE ArtNetGetNodeTxGood(int Node, int Port);
extern "C" bool DLL_MODE ArtNetGetNodeTxMerge(int Node, int Port);
extern "C" bool DLL_MODE ArtNetGetNodeTxLtp(int Node, int Port);
extern "C" bool DLL_MODE ArtNetGetNodeTxShort(int Node, int Port);
extern "C" unsigned char DLL_MODE ArtNetGetNodeTxProtocol(int Node, int Port);
extern "C" bool DLL_MODE ArtNetGetNodeTxOutputStyle(int Node, int Port);
extern "C" bool DLL_MODE ArtNetGetNodeTxRdmSwitch(int Node, int Port);

extern "C" uchar DLL_MODE ArtNetGetNodeFailOverMode(int Node);


extern "C" BYTE DLL_MODE ArtNetGetRxPipeVersionInfoH(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeVersionInfoH(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeVersionInfoH(int Node);

extern "C" BYTE DLL_MODE ArtNetGetRxPipeVersionInfo(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeVersionInfo(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeVersionInfo(int Node);

extern "C" BYTE DLL_MODE ArtNetGetRxPipeNumberPorts(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeNumberPorts(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeNumberRxPorts(int Node);
extern "C" BYTE DLL_MODE ArtNetGetNodeNumberTxPorts(int Node);

extern "C" String DLL_MODE ArtNetGetRxPipeShortName(int Pipe);
extern "C" String DLL_MODE ArtNetGetTxPipeShortName(int Pipe);
extern "C" String DLL_MODE ArtNetGetRxNodeShortName(int Node, int Port);
extern "C" String DLL_MODE ArtNetGetTxNodeShortName(int Node, int Port);

extern "C" String DLL_MODE ArtNetGetRxPipeLongName(int Pipe);
extern "C" String DLL_MODE ArtNetGetTxPipeLongName(int Pipe);
extern "C" String DLL_MODE ArtNetGetNodeLongName(int Node);

extern "C" String DLL_MODE ArtNetGetRxPipeNodeReport(int Pipe);
extern "C" String DLL_MODE ArtNetGetTxPipeNodeReport(int Pipe);
extern "C" String DLL_MODE ArtNetGetNodeNodeReport(int Node);

extern "C" BYTE DLL_MODE ArtNetGetRxPipeMacroKeys(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeMacroKeys(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeMacroKeys(int Node);

extern "C" BYTE DLL_MODE ArtNetGetRxPipeRemoteKeys(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeRemoteKeys(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeRemoteKeys(int Node);

extern "C" BYTE DLL_MODE ArtNetGetRxPipeVideo(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetTxPipeVideo(int Pipe);
extern "C" BYTE DLL_MODE ArtNetGetNodeVideo(int Node);

extern "C" WORD DLL_MODE ArtNetGetRxPipeChannelCount(int Pipe);
extern "C" WORD DLL_MODE ArtNetGetRxPipePacketCount(int Pipe);
extern "C" WORD DLL_MODE ArtNetGetTxPipePacketCount(int Pipe);
extern "C" void DLL_MODE ArtNetResetCounters(int Pipe);

extern "C" void DLL_MODE ArtNetSetNodeShortName (int Node, char* Name);
extern "C" void DLL_MODE ArtNetSetNodeLongName (int Node, char* Name);
extern "C" void DLL_MODE ArtNetSetNodeSwitches(int Node,BYTE In0,
BYTE In1,BYTE In2,BYTE In3,BYTE Out0,
BYTE Out1,BYTE Out2,BYTE Out3,BYTE SubNet,BYTE Net,
BYTE Video);

extern "C" bool DLL_MODE  ArtNetReplaceIp(unsigned char SeedIp0, unsigned char SeedIp1, unsigned char SeedIp2, unsigned char SeedIp3, unsigned char ReplaceIp0, unsigned char ReplaceIp1, unsigned char ReplaceIp2, unsigned char ReplaceIp3);
extern "C" bool DLL_MODE  ArtNetIsBinding(int SeedNode);
extern "C" int DLL_MODE ArtNetGetBindNodeForThisTxPort(int SeedNode, int Port);
extern "C" int DLL_MODE ArtNetGetBindNodeForThisBind(int SeedNode, int Bind);
extern "C" int DLL_MODE ArtNetGetRootNodeForThisNode(int SeedNode);
extern "C" int DLL_MODE ArtNetGetNodeNumberArtNet4TxPorts(int SeedNode);
extern "C" bool DLL_MODE ArtNetDeferenceBindNodeForThisTxPort(int *SeedNodePtr, int *PortExtendedPtr);

extern "C" int DLL_MODE ArtNetGetNodeNumberArtNet4RxPorts(int SeedNode);
extern "C" bool DLL_MODE ArtNetDeferenceBindNodeForThisRxPort(int *SeedNodePtr, int *PortExtendedPtr);


extern "C" void DLL_MODE ArtNetSetNodeConfig(int Node, wchar_t* ShortName, wchar_t* LongName, BYTE In0,
BYTE In1,BYTE In2,BYTE In3,BYTE Out0,
BYTE Out1,BYTE Out2,BYTE Out3,BYTE SubNet,BYTE Net,
BYTE Video);

extern "C" void DLL_MODE ArtNetSetNodeCommandTx(int Node, int Port, BYTE NewCommand);
extern "C" void DLL_MODE ArtNetSetNodeCommandRx(int Node, int Port, BYTE NewCommand);
extern "C" void DLL_MODE ArtNetSetNodeCommandAll(int SeedNode, BYTE NewCommand);

extern "C" int DLL_MODE ArtNetGetRxPipeIndexForIp(wchar_t* IpAddress);
extern "C" int DLL_MODE ArtNetGetNodeIndexForIp(wchar_t* IpAddress, unsigned char BindIndex);
extern "C" int DLL_MODE ArtNetGetNodeIndexForIpArray(int Ip0, int Ip1, int Ip2, int Ip3, unsigned char BindIndex);
extern "C" int DLL_MODE ArtNetGetNodeIndexForRxPipe(int Pipe);
extern "C" int DLL_MODE ArtNetGetNodeIndexForTxPipe(int Pipe);
extern "C" bool DLL_MODE ArtNetIsRxPipeThisUniverse(int Pipe, WORD Universe);

extern "C" void DLL_MODE ArtNetSetTxData (int Pipe, WORD Channel,BYTE Data);                  //
extern "C" void DLL_MODE ArtNetSetTxDataGroup (int Pipe, WORD StartCh,WORD EndCh,BYTE Data);  //
extern "C" BYTE DLL_MODE ArtNetGetRxData (WORD Channel);                            //
extern "C" void DLL_MODE ArtNetClearDataBuffer (BYTE Data);		        	//

extern "C" bool DLL_MODE ArtNetShowAboutBox(void);
extern "C" bool DLL_MODE ArtNetShowNetworkStatusForm(void);
extern "C" bool DLL_MODE ArtNetShowNicForm(void);
extern "C" bool DLL_MODE ArtNetShowDataMonitorForm(void);
extern "C" bool DLL_MODE ArtNetShowRoutingForm(void);
extern "C" bool DLL_MODE ArtNetShowRdmDecoder(void);
extern "C" bool DLL_MODE ArtNetShowArtNetDecoder(void);
extern "C" bool DLL_MODE ArtNetShowArtNetDiag(void);
extern "C" bool DLL_MODE ArtNetShowArtNetMacro(void);
extern "C" bool DLL_MODE ArtNetShowDriverPopup(int X, int Y);
extern "C" bool DLL_MODE ArtNetShowUserIpForm(void);
extern "C" bool DLL_MODE ArtNetShowAutoAddressForm(void);
extern "C" bool DLL_MODE ArtNetShowRadarForm(void);
extern "C" bool DLL_MODE ArtNetShowOscTxForm(void);


extern "C" bool DLL_MODE ArtNetRecordRouting(int Preset, String NewName);
extern "C" bool DLL_MODE ArtNetSelectRouting(int Preset);
extern "C" String DLL_MODE ArtNetGetRoutingName(int Preset);
extern "C" bool DLL_MODE ArtNetDeleteRouting(int Preset);
extern "C" bool DLL_MODE ArtNetDeleteAllRouting(void);

extern "C" bool DLL_MODE ArtNetSaveCurrentIp(int Channel, String Ip, String NetMask);
extern "C" bool DLL_MODE ArtNetGetCurrentIp(int Channel, String* Ip, String* NetMask);

extern "C" bool DLL_MODE ArtNetSaveBackupIp(String Ip);
extern "C" String DLL_MODE ArtNetGetBackupIp(void);

extern "C" String DLL_MODE ArtNetGetOscTxIp(void);
extern "C" void DLL_MODE ArtNetSetOscTxIp(String NewIp);

extern "C" String DLL_MODE ArtNetGetOscRxIp(void);
extern "C" void DLL_MODE ArtNetSetOscRxIp(String NewIp);



// Rdm procedures are all Node indexed - new functions need to be documented in SDK

extern "C" void DLL_MODE ArtNetForceNodeDiscovery(int Node, int Port);
extern "C" void DLL_MODE ArtNetForceNodeDiscoveryLo(int Node, int Port);

extern "C" _RdmDevice* DLL_MODE RdmDeviceGetPtr(int Node, int Port, T_Uid* SeedUid);
extern "C" _RdmDevice* DLL_MODE RdmDeviceGetAnyPtr(int Node, T_Uid* SeedUid);
extern "C" bool DLL_MODE RdmDeviceUidMatch(T_Uid* Uid1, T_Uid* Uid2);
extern "C" _RdmDevice* DLL_MODE RdmDeviceDoesUidExist(T_Uid* SeedUid);

extern "C" _RdmDevice* DLL_MODE RdmDeviceGetFirstPtr(int Node, int Port);
extern "C" _RdmDevice* DLL_MODE RdmDeviceGetNextPtr(_RdmDevice* ThisPtr);
extern "C" _RdmDevice* DLL_MODE RdmDeviceGetIndexPtr(int Node, int Port, int Dev);
extern "C" _RdmDevice* DLL_MODE RdmDeviceAdd(int Node, int Port, T_Uid* SeedUid);
extern "C" bool DLL_MODE RdmDeviceInvalidate(_RdmDevice* DelPtr);
extern "C" bool DLL_MODE RdmDeviceInvalidateKill(_RdmDevice* DelPtr);
extern "C" void DLL_MODE RdmDeviceInvalidatePort(int Node, int Port);

extern "C" _RdmSensor* DLL_MODE RdmDeviceAddRootSensor(_RdmDevice* RdmPtr, T_RdmStd* DataPtr, int Len);
extern "C" bool DLL_MODE RdmDeviceDeleteSensors(_RdmDevice* DelPtr);
extern "C" bool DLL_MODE RdmDeviceInvalidateSensors(_RdmDevice* DelPtr);

extern "C" int DLL_MODE RdmDeviceAddSubDevices(_RdmDevice* RdmPtr, T_RdmStd* DataPtr);
extern "C" bool DLL_MODE RdmDeviceDeleteSubDevices(_RdmDevice* DelPtr);
extern "C" bool DLL_MODE RdmDeviceInvalidateSubDevices(_RdmDevice* DelPtr);

extern "C" int DLL_MODE RdmDeviceGetRootSensorCount(int Node, int Port, int Dev);
extern "C" int DLL_MODE RdmDeviceGetRootSensorCountPtr(_RdmDevice* RdmPtr);

extern "C" bool DLL_MODE RdmDeviceGetRootSensorValid(int Node, int Port, int Dev, int Sensor);

extern "C" bool DLL_MODE RdmDeviceGetRootSensorWarning(int Node, int Port, int Dev, int Sensor);
extern "C" bool DLL_MODE RdmDeviceGetRootSensorWarningPtr(_RdmDevice* RdmPtr, int Sensor);

extern "C" bool DLL_MODE RdmDeviceGetRootSensorError(int Node, int Port, int Dev, int Sensor);
extern "C" bool DLL_MODE RdmDeviceGetRootSensorErrorPtr(_RdmDevice* RdmPtr, int Sensor);

extern "C" wchar_t* DLL_MODE RdmDeviceGetRootSensorValueString(int Node, int Port, int Dev, int Sensor, int SensorValueType );
extern "C" wchar_t* DLL_MODE RdmDeviceGetRootSensorValueStringBySensorPtr(_RdmSensor* ListPtr, int SensorValueType );

extern "C" _RdmSensor* DLL_MODE RdmDeviceGetRootSensor(int Node, int Port, int Dev, int Sensor);
extern "C" _RdmSensor* DLL_MODE RdmDeviceGetRootSensorPtr(_RdmDevice* RdmPtr, int SensorId);

extern "C" bool DLL_MODE RdmDeviceGetAnySensorWarning(int Node, int Port, int Dev);
extern "C" bool DLL_MODE RdmDeviceGetAnySensorWarningPtr(_RdmDevice* RdmPtr);

extern "C" bool DLL_MODE RdmDeviceGetAnySensorError(int Node, int Port, int Dev);
extern "C" bool DLL_MODE RdmDeviceGetAnySensorErrorPtr(_RdmDevice* RdmPtr);

extern "C" bool DLL_MODE RdmDeviceAnyDevices(int Node, int Port);
extern "C" int DLL_MODE RdmDeviceGetDeviceCount(int Node, int Port);
extern "C" int DLL_MODE RdmDeviceGetActiveDeviceCount(int Node, int Port);

extern "C" void DLL_MODE RdmDeviceRequestTod(int Node);
extern "C" void DLL_MODE RdmDeviceArmAllGets(_RdmDevice* NewPtr);

extern "C" T_ArtRdm* DLL_MODE RdmDeviceArtRdmTemplate(T_ArtRdm* RdmPtr, int Node, int Port, int Dev);
extern "C" T_ArtRdmSub* DLL_MODE RdmDeviceArtRdmSubTemplate(T_ArtRdmSub* RdmSubPtr, int Node, int Port, int Dev);
extern "C" bool DLL_MODE RdmDeviceArtRdmSubSend(T_ArtRdmSub* RdmSubPtr, int Node, int Port, int Dev, bool Broadcast);
extern "C" bool DLL_MODE RdmDeviceArtRdmSend(T_ArtRdm* RdmPtr, int Node, int Port, int Dev, bool Broadcast, unsigned char RdmVer);
extern "C" bool DLL_MODE RdmDeviceArtRdmSendStress(T_ArtRdm* RdmPtr);
extern "C" bool DLL_MODE RdmSetStress(bool Enable);


extern "C" bool DLL_MODE RdmDeviceGetValid(int Node, int Port, int Dev);
extern "C" bool DLL_MODE RdmDeviceGetValidPtr(_RdmDevice* RdmPtr);
extern "C" bool DLL_MODE RdmDeviceGetApplicationRedraw(int Node, int Port, int Dev);
extern "C" bool DLL_MODE RdmDeviceGetApplicationRedrawPtr(_RdmDevice* RdmPtr);
extern "C" bool DLL_MODE RdmDeviceGetAddToList(int Node, int Port, int Dev);
extern "C" bool DLL_MODE RdmDeviceGetAnyAddToList(int Node, int Port);
extern "C" bool DLL_MODE RdmDeviceExistsOnNode(int Node);
extern "C" wchar_t* DLL_MODE RdmDeviceGetModelName(int Node, int Port, int Dev);
extern "C" wchar_t* DLL_MODE RdmDeviceGetModelNamePtr(_RdmDevice* RdmPtr);

extern "C" wchar_t* DLL_MODE RdmDeviceGetManufacturerName(int Node, int Port, int Dev);
extern "C" wchar_t* DLL_MODE RdmDeviceGetManufacturerNamePtr(_RdmDevice* RdmPtr);

extern "C" wchar_t* DLL_MODE RdmDeviceGetDeviceLabel(int Node, int Port, int Dev);
extern "C" void DLL_MODE RdmDeviceSetDeviceLabel(int Node, int Port, int Dev, char* NewLabel);

extern "C" ushort DLL_MODE RdmDeviceGetSoftwareStatus(int Node, int Port, int Dev);
extern "C" wchar_t* DLL_MODE RdmDeviceGetSoftwareVersionString(int Node, int Port, int Dev);

extern "C" wchar_t* DLL_MODE RdmDeviceGetSoftwareVersionStringPtr(_RdmDevice* ListPtr);

extern "C" int DLL_MODE RdmDeviceGetStartAddressPtr(_RdmDevice* RdmPtr, int Sub);
extern "C" int DLL_MODE RdmDeviceGetStartAddress(int Node, int Port, int Dev, int Sub);

extern "C" void DLL_MODE RdmDeviceSetStartAddress(int Node, int Port, int Dev, int Sub, int NewAddress);
extern "C" void DLL_MODE RdmDeviceSetStartAddressPtr(_RdmDevice* RdmPtr, int Sub, int NewAddress);

extern "C" void DLL_MODE RdmDeviceSetPers(int Node, int Port, int Dev, int NewPers);
extern "C" void DLL_MODE RdmDeviceSetPersPtr(_RdmDevice* RdmPtr, int NewPers);

extern "C" int DLL_MODE RdmDeviceGetPers(int Node, int Port, int Dev);
extern "C" wchar_t* DLL_MODE RdmDeviceGetPersLabel(int Node, int Port, int Dev, int Per);
extern "C" int DLL_MODE RdmDeviceGetPersMax(int Node, int Port, int Dev);

extern "C" int DLL_MODE RdmDeviceGetFootprint(int Node, int Port, int Dev, int Sub);
extern "C" int DLL_MODE RdmDeviceGetFootprintPtr(_RdmDevice* RdmPtr, int Sub);

extern "C" int DLL_MODE RdmDeviceGetSubDeviceCount(int Node, int Port, int Dev);
extern "C" int DLL_MODE RdmDeviceGetCountDeviceHours(int Node, int Port, int Dev);
extern "C" int DLL_MODE RdmDeviceGetCountLampHours(int Node, int Port, int Dev);
extern "C" int DLL_MODE RdmDeviceGetCountLampStrikes(int Node, int Port, int Dev);
extern "C" int DLL_MODE RdmDeviceGetDeviceId(int Node, int Port, int Dev);


extern "C" T_Uid* DLL_MODE RdmDeviceGetUid(int Node, int Port, int Dev);
extern "C" wchar_t* DLL_MODE RdmDeviceGetUidString(int Node, int Port, int Dev);
extern "C" wchar_t* DLL_MODE RdmDeviceGetUidStringShort(int Node, int Port, int Dev);
extern "C" void DLL_MODE RdmDeviceSetUidStringShort(int NodeIndex, int Port, int Dev, char* ShortUidString);
extern "C" void DLL_MODE RdmDeviceSetLocate(int Node, int Port, int Dev, int Sub, int OnOff);
extern "C" void DLL_MODE RdmDeviceSetLocatePtr(_RdmDevice* RdmPtr, int Sub, int OnOff);
extern "C" void DLL_MODE RdmPortBroadcastLocate(int NodeIndex, int Port, int OnOff);
extern "C" void DLL_MODE RdmPortAllPortsLocate(int Node, int OnOff);
extern "C" void DLL_MODE RdmPortAllNodesLocate(int OnOff);

extern "C" void DLL_MODE RdmDevicePlayPresetScene(int NodeIndex, int Port, int Dev, unsigned int Test, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceRecordPresetScene(int NodeIndex, int Port, int Dev, uchar Test, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceSetPresetScene(int NodeIndex, int Port, int Dev, bool Broadcast, T_PresetBlock* BlockPtr);
extern "C" void DLL_MODE RdmDeviceGetPresetScene(int NodeIndex, int Port, int Dev, bool Broadcast,  uchar PresetNumber, uchar PresetBlock);

extern "C" void DLL_MODE RdmDeviceSetSelfTest(int Node, int Port, int Dev, uchar Test, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceDataLossMode(int NodeIndex, int Port, int Dev, uchar Mode, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceSetResetDevice(int Node, int Port, int Dev, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceSetFactoryDefaults(int Node, int Port, int Dev, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceSetRomBoot(int Node, int Port, int Dev, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceSetExitCommand(int Node, int Port, int Dev, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceSetDisplayLevel(int Node, int Port, int Dev, uchar Level);
extern "C" void DLL_MODE RdmDeviceSetDisplayLevelPtr(_RdmDevice* RdmPtr, uchar Level);

extern "C" _RdmSubDevice* DLL_MODE RdmDeviceGetSubDevicePtr(_RdmDevice* RdmPtr, int Sub);

extern "C" void DLL_MODE RdmDeviceSetDisplayInvert(int Node, int Port, int Dev, uchar Mode, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceSetLampState(int Node, int Port, int Dev, uchar Mode, bool Broadcast);
extern "C" void DLL_MODE RdmDeviceSetFastPoll(bool Enable, int NodeIndex, int Port, int Dev);


extern "C" unsigned int DLL_MODE RdmDeviceGetLastBlockSize(int Node, int Port, int Dev);
extern "C" unsigned char DLL_MODE RdmDeviceGetFirmwareReplyType(int Node, int Port, int Dev);
extern "C" void DLL_MODE RdmDeviceClearFirmwareReplyType(int Node, int Port, int Dev);

extern "C" char* DLL_MODE TextFromRdm(T_RdmStd* DataPtr, ushort Count, ushort Offset);

extern "C" bool DLL_MODE RdmDeviceConvertUidStringToStructure( wchar_t* ShortUidString, T_Uid* Uid);
extern "C" bool DLL_MODE RdmDeviceConvertStructureToUidString( char* ShortUidString, T_Uid* Uid);

extern "C" ushort DLL_MODE WordFromRdm(T_RdmStd* DataPtr, ushort Offset);
extern "C" unsigned long DLL_MODE LongWordFromRdm(T_RdmStd* DataPtr, ushort Offset);
extern "C" uchar DLL_MODE ByteFromRdm(T_RdmStd* DataPtr, ushort Offset);

extern "C" void DLL_MODE ArtNetIpProgPollRequest(int NodeIndex);
extern "C" ushort DLL_MODE RdmDeviceGetRootSupportedPid(int Node, int Port, int Dev, int Index);
extern "C" ushort DLL_MODE RdmDeviceGetSubSupportedPid(int Node, int Port, int Dev, int Index);
extern "C" bool DLL_MODE RdmDeviceIsPidSupported(int Node, int Port,int Dev, bool Sub, ushort ThisPid);


extern "C" int DLL_MODE ArtNetGetDLLRevisionHi(void);                               //
extern "C" int DLL_MODE ArtNetGetDLLRevisionLo(void);                               //

extern "C" String DLL_MODE ArtNetGetPacketString(int Pk);

extern "C" String DLL_MODE ArtNetGetProtocolString(BYTE Protocol);

//Functions below are used to set the caption of the editors for the different protocol parameters.
//
extern "C" wchar_t* DLL_MODE ArtNetVisualManualIpCaption(BYTE Protocol);
extern "C" wchar_t* DLL_MODE ArtNetVisualNetCaption(BYTE Protocol);
extern "C" wchar_t* DLL_MODE ArtNetVisualSubUniCaption(BYTE Protocol);
extern "C" wchar_t* DLL_MODE ArtNetVisualKiPortCaption(BYTE Protocol);


//Functions below are used to enable or disable the parameter editors used for the different protocols.
//
extern "C" bool DLL_MODE ArtNetVisualManualIpActive(BYTE Protocol);
extern "C" bool DLL_MODE ArtNetVisualNetActive(BYTE Protocol);
extern "C" bool DLL_MODE ArtNetVisualSubUniActive(BYTE Protocol);
extern "C" bool DLL_MODE ArtNetVisualKiPortActive(BYTE Protocol);

extern "C" bool DLL_MODE ArtNetSetKeepAlive(bool Enable);

extern "C" bool DLL_MODE ArtNetSendOscString    (char* IpOverride, char* Vector, char* Data);
extern "C" bool DLL_MODE ArtNetSendOscStringExt (char* IpOverride, char* Vector, int Tag, int Instance, char* Parameter, char* Data);
extern "C" bool DLL_MODE ArtNetSendOscFloat1     (char* IpOverride, char* Vector, float Data);
extern "C" bool DLL_MODE ArtNetSendOscFloat2     (char* IpOverride, char* Vector, float Data1, float Data2);
extern "C" bool DLL_MODE ArtNetSendOscFloatExt  (char* IpOverride, char* Vector, int Tag, int Instance, char* Parameter, float Data);
extern "C" bool DLL_MODE ArtNetSendOscDali1  (char* IpOverride, char* Vector, int Circuit, unsigned char Ballast, unsigned char Data);
extern "C" bool DLL_MODE ArtNetSendOscDali2  (char* IpOverride, char* Vector, int Circuit, unsigned char Ballast, unsigned char Data1, unsigned char Data2);
extern "C" char* DLL_MODE ArtNetWideToNarrow(String Wide, char* Narrow, int Len, bool StopOnZero);
extern "C" unsigned long DLL_MODE ArtNetInetAddr(String IpString);


extern "C" void DLL_MODE ArtNetSetEmulatedArtPollResponseMode(bool Enab, int ReplyPerPacket, unsigned int OemCode, String Name);

extern "C" void* DLL_MODE ArtNetGetPipeLibrary(void);
extern "C" void* DLL_MODE ArtNetGetNodeLibrary(void);
extern "C" S_PacketLog* DLL_MODE ArtNetGetPacketLog(void);
extern "C" S_ArtNetControl* DLL_MODE ArtNetGetArtNetControl(void);

























// The following functions are exported for internal DLL use. Not part of API
//
void SendArtPollBroadcast(void);
void ClearArtAddressStructure(void);
void ClearArtIpProgStructure(void);
void ClearArtTodRequestStructure(void);
void ClearArtTodControlStructure(void);
void ClearEmulArtPollReplyStructure(void);
void ClearArtCommandStructure(void);


extern "C" BYTE DLL_MODE ArtNetGetNodeFirmwareReplyType(int Node);
extern "C" void DLL_MODE ArtNetClearNodeFirmwareReplyType(int Node);
extern "C" void DLL_MODE RdmDeviceSetAllPending(int Node, int Port);
extern "C" void DLL_MODE RdmDeviceInvalidateAllPending(int Node, int Port);

extern "C" T_ArtPollFpReply*  DLL_MODE ArtNetGetNodeFpPtr(int Node);
extern "C" T_ArtDirectoryList* DLL_MODE ArtNetGetNodeDirectoryList(int Node);
extern "C" void DLL_MODE ArtNetSendDirectoryRequest (int Node, bool Bcast, unsigned int File);

extern "C" void DLL_MODE ArtNetSendTimeCode(unsigned char Frames, unsigned char Seconds, unsigned char Minutes, unsigned char Hours, unsigned char Type);
extern "C" void DLL_MODE ArtNetSendTrigger (int Node, bool Bcast, bool Global, uchar Key, uchar SubKey, uchar *DataPtr);
extern "C" bool DLL_MODE ArtNetSendFileRequest (int Node, wchar_t* Path, wchar_t* FileName, int FileNum);
extern "C" void DLL_MODE ArtNetAbortFile(void);
extern "C" void DLL_MODE ArtNetSendTimeSyncDateTime(TDateTime dt);
extern "C" void DLL_MODE ArtNetSendTimeSync(void);
extern "C" void DLL_MODE ArtNetSendArtCommand(int Node, uchar eHi, uchar eLo, String Command);


extern "C" void DLL_MODE ArtNetSetRdmPollEnable(bool Enab);
extern "C" bool DLL_MODE ArtNetGetRdmPollEnable(void);
extern "C" void DLL_MODE ArtNetSetListenOnly(bool Enab);
extern "C" bool DLL_MODE ArtNetGetListenOnly(void);
extern "C" void DLL_MODE ArtNetSetFirmwarePath(String NewPath);
extern "C" String DLL_MODE ArtNetGetFirmwarePath(void);

extern "C" void DLL_MODE ArtNetSetBackupMode(bool Enab);
extern "C" bool DLL_MODE ArtNetGetBackupMode(void);

extern "C" void DLL_MODE ArtNetCheckModesBackgroundColour(void);


extern "C" void DLL_MODE RdmDeviceForceSubDeviceRefresh(_RdmDevice* RdmPtr);
extern "C" bool DLL_MODE RdmDeviceGetRdmShortPacket(int Node);



extern "C" void DLL_MODE ArtNetSendFileFnReply (int Node, unsigned char Type);

extern "C" void DLL_MODE ArtNetSetPacketCountRate(int NewRate);
extern "C" char* DLL_MODE GetTextFromIndex(ushort Tag, ushort Max, T_Pid* Lookup, char* ErrorText);
extern "C" T_Pid* DLL_MODE GetTpidFromIndex(ushort Tag, ushort Max, T_Pid* Lookup);
extern "C" bool DLL_MODE GetIsGoodFromIndex(ushort Tag, ushort Max, T_Pid* Lookup);



// testing only

extern "C" void DLL_MODE DllUdpReceiver(void); //on udp receive
extern "C" T_RdmStd* DLL_MODE ConvertDraftToStd(_RdmDevice* RdmPtr, T_ArtRdm* ArtRdmPtr, int Len);

















#endif



