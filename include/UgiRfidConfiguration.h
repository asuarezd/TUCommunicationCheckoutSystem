//
//  UgiRfidConfiguration.h
//  UGrokItApi
//
//  Copyright (c) 2012 U Grok It. All rights reserved.
//

#define __UGI_RFID_CONFIGURATION_H

#import <Foundation/Foundation.h>

///////////////////////////////////////////////////////////////////////////////////////
// Enums must be defined outside the class for Swift, but inside the class for
// Doxygen (the documentation generator)
///////////////////////////////////////////////////////////////////////////////////////

typedef NS_ENUM(int, UgiMemoryBank) {
  UGI_MEMORY_BANK_RESERVED = 0,
  UGI_MEMORY_BANK_EPC = 1,
  UGI_MEMORY_BANK_TID = 2,
  UGI_MEMORY_BANK_USER = 3
};

typedef NS_ENUM(int, UgiSoundTypes) {
  UGI_INVENTORY_SOUNDS_NONE = 0,
  UGI_INVENTORY_SOUNDS_GEIGER_COUNTER = 1,
  UGI_INVENTORY_SOUNDS_FIRST_FIND = 2,
  UGI_INVENTORY_SOUNDS_FIRST_FIND_AND_LAST = 6
};

typedef NS_ENUM(int, UgiInventoryTypes) {
  UGI_INVENTORY_TYPE_LOCATE_DISTANCE = 1,
  UGI_INVENTORY_TYPE_INVENTORY_SHORT_RANGE = 2,
  UGI_INVENTORY_TYPE_INVENTORY_DISTANCE = 3,
  UGI_INVENTORY_TYPE_LOCATE_SHORT_RANGE = 4,
  UGI_INVENTORY_TYPE_LOCATE_VERY_SHORT_RANGE = 5,
  UGI_INVENTORY_TYPE_SINGLE_FIND = 6,
  UGI_INVENTORY_TYPE_HF_INVENTORY = 7,
  UGI_INVENTORY_TYPE_HF_SINGLE_FIND = 8
};

typedef NS_ENUM(int, UgiSingleFindRampPowerModes) {
  UGI_SINGLE_FIND_RAMP_POWER_NO_RAMP = 0,
  UGI_SINGLE_FIND_RAMP_POWER_SLOW = 1,
  UGI_SINGLE_FIND_RAMP_POWER_MEDIUM = 2,
  UGI_SINGLE_FIND_RAMP_POWER_FAST = 3
};

///////////////////////////////////////////////////////////////////////////////////////
// End enums
///////////////////////////////////////////////////////////////////////////////////////

/**
 RFID configuration instances, used by startInventory(). Common configuration
 instances are provided
 */
@interface UgiRfidConfiguration : NSObject<NSCopying>

#define MAX_RFID_CONFIGURATION_MASK_LENGTH_BYTES 12

#if DOXYGEN   // Defined before class for Swift compatibility, documented here for Doxygen compatibility

/**
 Memory banks
 */
typedef enum {
  UGI_MEMORY_BANK_RESERVED = 0,   //! RESERVED bank
  UGI_MEMORY_BANK_EPC = 1,        //! EPC bank
  UGI_MEMORY_BANK_TID = 2,        //! TID bank
  UGI_MEMORY_BANK_USER = 3        //! USER bank
} UgiMemoryBank;

/**
 Sound types
 */
typedef enum {
  UGI_INVENTORY_SOUNDS_NONE = 0,                    //! Make no sounds
  UGI_INVENTORY_SOUNDS_GEIGER_COUNTER = 1,          //! Geiger counter sounds when epc(s) are found
  UGI_INVENTORY_SOUNDS_FIRST_FIND = 2,              //! Found-item sound once when epc is first found
  UGI_INVENTORY_SOUNDS_FIRST_FIND_AND_LAST = 6      //! Found-item sound once when epc is first found and special sound for last tag
} UgiSoundTypes;

/**
 Inventory types (passed to startInventory)
 */
typedef enum {
  UGI_INVENTORY_TYPE_LOCATE_DISTANCE = 1,          //! Locate at a distance
  UGI_INVENTORY_TYPE_INVENTORY_SHORT_RANGE = 2,    //! Inventory (count) at short range, especially in dense environments
  UGI_INVENTORY_TYPE_INVENTORY_DISTANCE = 3,       //! Inventory (count) a at a distance
  UGI_INVENTORY_TYPE_LOCATE_SHORT_RANGE = 4,       //! Locate at short range
  UGI_INVENTORY_TYPE_LOCATE_VERY_SHORT_RANGE = 5,  //! Locate at very short range
  UGI_INVENTORY_TYPE_SINGLE_FIND = 6,              //! Find a single tag
  UGI_INVENTORY_TYPE_HF_INVENTORY = 7,             //! HF inventory
  UGI_INVENTORY_TYPE_HF_SINGLE_FIND = 8            //! HF inventory, find a single tag
} UgiInventoryTypes;

/**
 Values for singleFindRampPowerMode
 */
typedef enum {
  UGI_SINGLE_FIND_RAMP_POWER_NO_RAMP = 0,   //! Do not ramp power (normal power setting)
  UGI_SINGLE_FIND_RAMP_POWER_SLOW = 1,      //! Ramp power slowly (250 rounds from lowest to highest, about 4 seconds)
  UGI_SINGLE_FIND_RAMP_POWER_MEDIUM = 2,    //! Ramp power medium (125 rounds from lowest to highest, about 2 seconds)
  UGI_SINGLE_FIND_RAMP_POWER_FAST = 3       //! Ramp power quickly (50 rounds from lowest to highest, about 1 second)
} UgiSingleFindRampPowerModes;

#endif

///////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Properties
///////////////////////////////////////////////////////////////////////////////////////

//! Initial power level for running inventory, in dBm.
//! The reader will start at this power level, but will vary down to minPowerLevel and up to maxPowerLevel
@property (nonatomic) double initialPowerLevel;

//! Minimum power level for running inventory, in dBm
@property (nonatomic) double minPowerLevel;

//! Maximum power level for running inventory, in dBm
@property (nonatomic) double maxPowerLevel;

//! Initial Q value to use when running inventory.
//!The reader will start with this Q value, but will vary down to minQValue and up to maxQValue based on the number of tags in the environment.
@property (nonatomic) int initialQValue;

//! Minimum Q value to use when running inventory
@property (nonatomic) int minQValue;

//! Maximum Q value to use when running inventory
@property (nonatomic) int maxQValue;

//! Session number to use when running inventory (0, 1, 2 or 3)
@property (nonatomic) int session;

//! Number of inventory rounds with no finds after which to toggle A/B (0 = never toggle)
@property (nonatomic) int roundsWithNoFindsToToggleAB;

//! Sensitivity level for running inventory, db
@property (nonatomic) int sensitivity;

//! Power level for writing tags, in dBm
@property (nonatomic) double powerLevelWrite;

//! Sensitivity level for writing tags, dB
@property (nonatomic) int sensitivityWrite;

//! YES for reader to use this listen-before-talk setting, if allowed (default is NO)
@property (nonatomic) BOOL setListenBeforeTalk;

//! YES for reader to listen-before-talk (default is NO)
@property (nonatomic) BOOL listenBeforeTalk;

/////////

//! Maximum number of inventory rounds per second (0 = no limit)
@property (nonatomic) int maxRoundsPerSecond;

//! Minimum number of TID memory bank bytes to return. If the TID memory size is known, set minTidBytes=maxTidBytes
@property (nonatomic) int minTidBytes;
//! Maximum number of TID memory bank bytes to return (0 = don't read TID). The maximum supported is getMaxAllowableMemoryBankBytes (currently 208)
@property (nonatomic) int maxTidBytes;

//! Minimum number of USER memory bank bytes to return. If the USER memory size is known, set minUserBytes=maxUserBytes
@property (nonatomic) int minUserBytes;
//! Maximum number of USER memory bank bytes to return (0 = don't read USER). The maximum supported is getMaxAllowableMemoryBankBytes (currently 208)
@property (nonatomic) int maxUserBytes;

//! Minimum number of RESERVED memory bank bytes to return. If the RESERVED memory size is known, set minReservedBytes=maxReservedBytes
@property (nonatomic) int minReservedBytes;
//! Maximum number of RESERVED memory bank bytes to return (0 = don't read RESERVED). The maximum supported is getMaxAllowableMemoryBankBytes (currently 208)
@property (nonatomic) int maxReservedBytes;

//! Mask to use in SELECT before inventory round. If nil (the default) then no SELECT is done before each inventory
@property (nonatomic, retain) NSData * _Nullable selectMask;
//! Length of the mask, in bits. If zero, then selectMask.length*8 is used
@property (nonatomic) int selectMaskBitLength;
//! Bit offset for SELECT
@property (nonatomic) int selectOffset;
//! Memory bank for SELECT
@property (nonatomic) UgiMemoryBank selectBank;


//! YES to run inventory until stopped, NO to run inventory once (default is YES)
@property (nonatomic) BOOL continual;

//! YES for reader to report RSSI data (default is NO)
@property (nonatomic) BOOL reportRssi;

//! YES for reader to report detailed data for each read (default is NO)
@property (nonatomic) BOOL detailedPerReadData;

//! Number of words for reader to read every time the tags is read (0, 1, or 2)
@property (nonatomic) int detailedPerReadNumReads;

//! memory bank #1 to read for detailed per-read
@property (nonatomic) UgiMemoryBank detailedPerReadMemoryBank1;

//! word offset #1 to read for detailed per-read
@property (nonatomic) int detailedPerReadWordOffset1;

//! memory bank #2 to read for detailed per-read
@property (nonatomic) UgiMemoryBank detailedPerReadMemoryBank2;

//! word offset #2 to read for detailed per-read
@property (nonatomic) int detailedPerReadWordOffset2;

//! YES to report subsequent finds
@property (nonatomic) BOOL reportSubsequentFinds;

//! YES to force a Tari of 25uS (useful for some sensor tags) - requires firmware 1.10.4 or above
@property (nonatomic) BOOL forceTari25;

//! YES to delay for 3ms after SELECT (useful for some sensor tags) - requires firmware 1.10.4 or above
@property (nonatomic) BOOL delayAfterSelect;

//! YES to use single find mode (find one tag only) - requires firmware 1.12.5 or above
@property (nonatomic) BOOL singleFindMode;

//! YES to stop inventory in singleFindMode after tag is found - requires firmware 1.12.5 or above
@property (nonatomic) BOOL singleFindContinueInventory;

//! If and how to ramp power from min to max in singleFindMode - requires firmware 1.12.5 or above
@property (nonatomic) UgiSingleFindRampPowerModes singleFindRampPowerMode;

//! Type of sounds to make when tags are found
@property (nonatomic) UgiSoundTypes soundType;

//! Volume level (0...1)
@property (nonatomic) double volume;

//! Length of each history period (default is 500ms)
@property (nonatomic) int historyIntervalMSec;

//! Number of history periods (default is 20)
@property (nonatomic) int historyDepth;

///////////////////////////

//! YES for HF inventory (on supported hardware)
@property (nonatomic) BOOL hf;

//! YES to run ISO 15693 inventory (if hf is YES)
@property (nonatomic) BOOL hfInventoryISO15693;
//! YES to run ISO 14443A inventory (if hf is YES)
@property (nonatomic) BOOL hfInventoryISO14443A;
//! YES to run Topaz inventory (if hf is YES)
@property (nonatomic) BOOL hfInventoryTopaz;
//! YES to run FeliCA inventory (if hf is YES)
@property (nonatomic) BOOL hfInventoryFelica;

//! YES to use 16 slots for ISO 15693 inventory, NO to use 1 slot
@property (nonatomic) BOOL hfIso15693use16slots;

///////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Methods
///////////////////////////////////////////////////////////////////////////////////////

/**
 Create a configuration object from a pre-defined inventory type.

 @param inventoryType  One of UgiInventoryTypes
 @return                Configuration structure
 */
+ (UgiRfidConfiguration * _Nonnull) configWithInventoryType:(UgiInventoryTypes)inventoryType;

/**
 Get the name for an inventory type.

 @param inventoryType  One of UgiInventoryTypes
 @return                Name
 */
+ (NSString * _Nonnull) nameForInventoryType:(UgiInventoryTypes)inventoryType;

/**
 Get the number of inventory types

 @return          Number of inventory types
 */
+ (int) numInventoryTypes;

///////////////////////////////////////////////////////////////////////////////////////
#pragma mark - Limits
///////////////////////////////////////////////////////////////////////////////////////

/**
 Get the minimum power value (dBm)

 @return          Minimum power value (dBm)
 */
+ (double) getMinAllowablePowerLevel;

/**
 Get the maximum power value (dBm)

 @return          Maximum power value (dBm)
 */
+ (double) getMaxAllowablePowerLevel;

/**
 Get the minimum Q value

 @return          Minimum Q value
 */
+ (int) getMinAllowableQValue;

/**
 Get the maximum Q value

 @return          Maximum Q value
 */
+ (int) getMaxAllowableQValue;

/**
 Get the maximum value for roundsWithNoFindsToToggleAB

 @return          Maximum value for roundsWithNoFindsToToggleAB
 */
+ (int) getMaxAllowableRoundsWithNoFindsToToggleAB;

/**
 Get the maximum value for maxTidBytes/maxReservedBytes/maxUserBytes

 @return          Maximum value for maxTidBytes/maxReservedBytes/maxUserBytes
 */
+ (int) getMaxAllowableMemoryBankBytes;

@end
