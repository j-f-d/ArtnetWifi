//////////////////////////////////////////////////////////////
//
//	Copyright Artistic Licence Holdings Ltd 2013-2015
//	Author:	Wayne Howell
//	Email:	Support@ArtisticLicence.com
//
//	This file contains all enumerations for Art-Osc
//
//      Created 3/6/13 (DllRevision = 2.008).
//
//
//////////////////////////////////////////////////////////////

#ifndef _ARTOSC_H_
#define _ARTOSC_H_


#define ArtOscMaxPacket         400     // Max size packet we send
#define ArtOscMinPacket         33      //
#define ArtOscMaxParameter      32      // Max length of a parameter string inc null
#define ArtOscMaxParameterDesc  255     // Max length of a parameter description string inc null


// Art-Osc Language enums
//
#define ArtOscLanguageNull              0       // Unknown Language
#define ArtOscLanguageRdm               1       // RDM
#define ArtOscLanguageAutomation        2       // Automation and remote control
#define ArtOscLanguageDaf               3       // DALI forward frame
#define ArtOscLanguageDar               4       // DALI reverse frame
#define ArtOscLanguageMax               5       //

//Art-Osc Manufacturer enums (These are ESTA Man IDs) (Fields 1&2 of Vector)

#define ArtOscCompanyHiArtisticLicence          65
#define ArtOscCompanyLoArtisticLicence          76

//Art-Osc Product enums (Fields 3&4 of Vector)

#define ArtOscProductHiColourTramp              100
#define ArtOscProductLoColourTramp              1

#define ArtOscProductHiDvNet                    100
#define ArtOscProductLoDvNet                    2

#define ArtOscProductHiDmxWorkshop              100
#define ArtOscProductLoDmxWorkshop              3

#define ArtOscProductHiMultiPlay                100
#define ArtOscProductLoMultiPlay                4


// Art-Osc Parameters
//
#define ArtOscParamNull                 0
#define ArtOscParamAutFaderA            1
#define ArtOscParamAutXyPadA            2
#define ArtOscParamAutSwitchA           3
#define ArtOscParamAutMacroA            4
#define ArtOscParamAutLedA              5
#define ArtOscParamAutLedB              6

#define ArtOscParamAutLabelA            50
#define ArtOscParamAutLabelFaderA       51
#define ArtOscParamAutLabelXyPadA       52
#define ArtOscParamAutLabelSwitchA      53
#define ArtOscParamAutLabelMacroA       54
#define ArtOscParamAutLabelLedA         55
#define ArtOscParamAutLabelLedB         56

#define ArtOscParamRdmCommsStatus               100
#define ArtOscParamRdmStatusMessages            101
#define ArtOscParamRdmDeviceInfo                102
#define ArtOscParamRdmDeviceModelDescription    103
#define ArtOscParamRdmManufacturerLabel         104
#define ArtOscParamRdmDeviceLabel               105
#define ArtOscParamRdmSoftwareVersionLabel      106
#define ArtOscParamRdmBootSoftwareVersionLabel  107
#define ArtOscParamRdmPersonality               108
#define ArtOscParamRdmPersonalityDescription    109
#define ArtOscParamRdmStartAddress              110
#define ArtOscParamRdmSensor                    111
#define ArtOscParamRdmSensorQuantity            112
#define ArtOscParamRdmSensorDefinition          113
#define ArtOscParamRdmDeviceHours               114
#define ArtOscParamRdmLampHours                 115
#define ArtOscParamRdmLampStrikes               116
#define ArtOscParamRdmPanInvert                 117
#define ArtOscParamRdmTiltInvert                118
#define ArtOscParamRdmPanTiltSwap               119
#define ArtOscParamRdmDisplayInvert             120
#define ArtOscParamRdmDisplayLevel              121
#define ArtOscParamRdmLampState                 122
#define ArtOscParamRdmLampOnMode                123


typedef struct S_Parameter {
        int     Parameter;                              //Parameter enum
        int     Language;                               //Language in which this parameter is valid
	char    Name[ArtOscMaxParameter];               //Name of parameter
	char    Description[ArtOscMaxParameterDesc];    //Description of parameter
        int     RdmPid;                                 //the related RDM PID
} T_Parameter;



extern T_Parameter ArtOscParameterLookup[];
extern int sizeofArtOscParameterLookup;


#endif







