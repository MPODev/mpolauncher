//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchID.h $
//  
//  Owner: Adobe Developer Technologies
//  
//  $Author: pmbuilder $
//  
//  $DateTime: 2008/08/19 04:03:07 $
//  
//  $Revision: #1 $
//  
//  $Change: 643572 $
//  
//  Copyright 1997-2008 Adobe Systems Incorporated. All rights reserved.
//  
//  NOTICE:  Adobe permits you to use, modify, and distribute this file in accordance 
//  with the terms of the Adobe license agreement accompanying it.  If you have received
//  this file from a source other than Adobe, then your use, modification, or 
//  distribution of it requires the prior written permission of Adobe.
//  
//  
//  Defines IDs used by the MPOLnch plug-in.
//  
//========================================================================================

#ifndef __MPOLnchID_h__
#define __MPOLnchID_h__

#include "SDKDef.h"

// Company:
#define kMPOLnchCompanyKey	kSDKDefPlugInCompanyKey		// Company name used internally for menu paths and the like. Must be globally unique, only A-Z, 0-9, space and "_".
#define kMPOLnchCompanyValue	kSDKDefPlugInCompanyValue	// Company name displayed externally.

// Plug-in:
#define kMPOLnchPluginName	"MPOLauncher"			// Name of this plug-in.
#define kMPOLnchPrefixNumber	0x174600 					// Unique prefix number for this plug-in(*Must* be obtained from Adobe Developer Support).
#define kMPOLnchVersion		kSDKDefPluginVersionString						// Version of this plug-in (for the About Box).
#define kMPOLnchAuthor		"fabiantheblind"				// Author of this plug-in (for the About Box).

// Plug-in Prefix: (please change kMPOLnchPrefixNumber above to modify the prefix.)
#define kMPOLnchPrefix		RezLong(kMPOLnchPrefixNumber)			// The unique numeric prefix for all object model IDs for this plug-in.
#define kMPOLnchStringPrefix	SDK_DEF_STRINGIZE(kMPOLnchPrefixNumber)	// The string equivalent of the unique prefix number for  this plug-in.

// PluginID:
DECLARE_PMID(kPlugInIDSpace, kMPOLnchPluginID, kMPOLnchPrefix + 0)

// ClassIDs:
DECLARE_PMID(kClassIDSpace, kMPOLnchActionComponentBoss,	kMPOLnchPrefix + 0)
DECLARE_PMID(kClassIDSpace, kMPOLnchStringRegisterBoss,	kMPOLnchPrefix + 1)
DECLARE_PMID(kClassIDSpace, kMPOLnchPanelRegisterBoss,	kMPOLnchPrefix + 2)
DECLARE_PMID(kClassIDSpace, kMPOLnchMenuRegisterBoss,	kMPOLnchPrefix + 3)
DECLARE_PMID(kClassIDSpace, kMPOLnchActionRegisterBoss,	kMPOLnchPrefix + 4)
DECLARE_PMID(kClassIDSpace, kMPOLnchPanelWidgetBoss,		kMPOLnchPrefix + 5)
DECLARE_PMID(kClassIDSpace, kMPOLnchListBoxWidgetBoss,	kMPOLnchPrefix + 6)
DECLARE_PMID(kClassIDSpace, kMPOLnchTextWidgetBoss,		kMPOLnchPrefix + 7)
DECLARE_PMID(kClassIDSpace, kMPOLnchEyeballWidgetBoss,	kMPOLnchPrefix + 8)
DECLARE_PMID(kClassIDSpace, kMPOLnchPenWidgetBoss,	kMPOLnchPrefix + 9)
// InterfaceIDs:
// None in this plug-in.

// ImplementationIDs:
DECLARE_PMID(kImplementationIDSpace, 	kMPOLnchActionComponentImpl,		kMPOLnchPrefix + 0)
DECLARE_PMID(kImplementationIDSpace, 	kMPOLnchListBoxObserverImpl,		kMPOLnchPrefix + 1)
DECLARE_PMID(kImplementationIDSpace,	kMPOLnchEyeballObserverImpl,		kMPOLnchPrefix + 2)
DECLARE_PMID(kImplementationIDSpace,	kMPOLnchPenObserverImpl,		kMPOLnchPrefix + 3)
DECLARE_PMID(kImplementationIDSpace,	kMPOLnchTVWidgetMgrImpl, 	kMPOLnchPrefix + 4)
DECLARE_PMID(kImplementationIDSpace,	kMPOLnchTVHierarchyAdapterImpl, 	kMPOLnchPrefix + 5)
// ActionIDs:
DECLARE_PMID(kActionIDSpace, kMPOLnchAboutActionID,				kMPOLnchPrefix + 0)
DECLARE_PMID(kActionIDSpace, kMPOLnchPanelWidgetActionID,		kMPOLnchPrefix + 1)
DECLARE_PMID(kActionIDSpace, kMPOLnchSeparator1ActionID,			kMPOLnchPrefix + 2)
DECLARE_PMID(kActionIDSpace, kMPOLnchPopupAboutThisActionID,		kMPOLnchPrefix + 3)
DECLARE_PMID(kActionIDSpace, kMPOLnchAddItemActionID,			kMPOLnchPrefix + 11)
DECLARE_PMID(kActionIDSpace, kMPOLnchRemoveItemActionID,			kMPOLnchPrefix + 12)
DECLARE_PMID(kActionIDSpace, kMPOLnchFCQueriesActionID,			kMPOLnchPrefix + 13)
DECLARE_PMID(kActionIDSpace, kMPOLnchHelpActionID,			kMPOLnchPrefix + 14)
DECLARE_PMID(kActionIDSpace, kMPOLnchShowScriptsActionID,			kMPOLnchPrefix + 15)
DECLARE_PMID(kActionIDSpace, kMPOLnchShowFCActionID,			kMPOLnchPrefix + 16)


// WidgetIDs:
DECLARE_PMID(kWidgetIDSpace, kMPOLnchPanelWidgetID,				kMPOLnchPrefix + 0) 
DECLARE_PMID(kWidgetIDSpace, kMPOLnchTextWidgetID,				kMPOLnchPrefix + 1)
DECLARE_PMID(kWidgetIDSpace, kMPOLnchListParentWidgetId,			kMPOLnchPrefix + 2)
DECLARE_PMID(kWidgetIDSpace, kMPOLnchListBoxWidgetID,			kMPOLnchPrefix + 3)
DECLARE_PMID(kWidgetIDSpace, kMPOLnchListElementEyeballWidgetID,	kMPOLnchPrefix + 4)
DECLARE_PMID(kWidgetIDSpace, kMPOLnchListElementPenWidgetID,	kMPOLnchPrefix + 5)
// "About Plug-ins" sub-menu:
#define kMPOLnchAboutMenuKey			kMPOLnchStringPrefix "kMPOLnchAboutMenuKey"
#define kMPOLnchAboutMenuPath		kSDKDefStandardAboutMenuPath kMPOLnchCompanyKey

// "Plug-ins" sub-menu:
#define kMPOLnchPluginsMenuKey 		kMPOLnchStringPrefix "kMPOLnchPluginsMenuKey"
#define kMPOLnchPluginsMenuPath		kSDKDefPlugInsStandardMenuPath kMPOLnchCompanyKey kSDKDefDelimitMenuPath kMPOLnchPluginsMenuKey

// Menu item keys:
#define kMPOLnchAddItemMenuItemKey			kMPOLnchStringPrefix "kMPOLnchAddItemMenuItemKey"
#define kMPOLnchRemoveItemMenuItemKey		kMPOLnchStringPrefix "kMPOLnchRemoveItemMenuItemKey"
#define kMPOLnchFCQueriesMenuItemKey		kMPOLnchStringPrefix "kMPOLnchFCQueriesMenuItemKey"
#define kMPOLnchHelpMenuItemKey		kMPOLnchStringPrefix "kMPOLnchHelpMenuItemKey"
#define kMPOLnchShowScriptsMenuItemKey		kMPOLnchStringPrefix "kMPOLnchShowScriptsMenuItemKey"
#define kMPOLnchShowFCMenuItemKey		kMPOLnchStringPrefix "kMPOLnchShowFCMenuItemKey"

// Other StringKeys:
#define kMPOLnchAboutBoxStringKey			kMPOLnchStringPrefix "kMPOLnchAboutBoxStringKey"
#define kMPOLnchAddItemStringKey				kMPOLnchStringPrefix "kMPOLnchAddItemStringKey"
#define kMPOLnchRemoveItemStringKey			kMPOLnchStringPrefix "kMPOLnchRemoveItemStringKey"
#define kMPOLnchFCQueriesItemStringKey		kMPOLnchStringPrefix "kMPOLnchFCQueriesItemStringKey"
#define kMPOLnchHelpItemStringKey		kMPOLnchStringPrefix "kMPOLnchHelpItemStringKey"
#define kMPOLnchShowScriptsItemStringKey		kMPOLnchStringPrefix "kMPOLnchShowScriptsItemStringKey"
#define kMPOLnchShowFCItemStringKey		kMPOLnchStringPrefix "kMPOLnchShowFCItemStringKey"


#define kMPOLnchMissingScriptItemStringKey		kMPOLnchStringPrefix "kMPOLnchMissingScriptItemStringKey"

#define kMPOLnchPanelTitleKey				kMPOLnchStringPrefix	"kMPOLnchPanelTitleKey"
#define kMPOLnchInternalPopupMenuNameKey		kMPOLnchStringPrefix	"kMPOLnchInternalPopupMenuNameKey"
#define kMPOLnchTargetMenuPath kMPOLnchInternalPopupMenuNameKey
#define kMPOLnchItemBaseKey					kMPOLnchStringPrefix "kMPOLnchItemBaseKey"
#define kMPOLnchAddedElementKey 				kMPOLnchStringPrefix"kMPOLnchAddedElementKey"




// Menu item positions:
#define kMPOLnchAddItemMenuItemPosition			1.0
#define kMPOLnchShowScriptsMenuItemPosition		2.0

#define kMPOLnchFCQueriesMenuItemPosition		3.0
#define kMPOLnchShowFCMenuItemPosition		4.0

#define kMPOLnchHelpMenuItemPosition		5.0

#define kMPOLnchRemoveItemMenuItemPosition		6.0

#define	kMPOLnchSeparator1MenuItemPosition		10.0
#define kMPOLnchAboutThisMenuItemPosition		11.0

// Initial data format version numbers
#define kMPOLnchFirstMajorFormatNumber  kSDKDef_30_PersistMajorVersionNumber
#define kMPOLnchFirstMinorFormatNumber  kSDKDef_30_PersistMinorVersionNumber

// Data format version numbers for the PluginVersion resource 
#define kMPOLnchCurrentMajorFormatNumber kMPOLnchFirstMajorFormatNumber // most recent major format change
#define kMPOLnchCurrentMinorFormatNumber kMPOLnchFirstMinorFormatNumber // most recent minor format change


// PNG specific IDs
#define kMPOLnchPNGIconRsrcID 10250
#define kMPOLnchPNGIconRollRsrcID 10250

// PNG specific IDs
#define kMPOLnchPNGHelpIconRsrcID 10251
#define kMPOLnchPNGHelpIconRollRsrcID 10251

// PNG specific IDs
#define kMPOLnchUIPanelIconRsrcID 10252
#define kMPOLnchUIPanelIconRollRsrcID 10252

// PNG specific IDs The MPO_importer
#define kMPOLnchMPOBtnIconRsrcID 10253
#define kMPOLnchMPOBtnIconRollRsrcID 10253

// PNG specific IDs The theNumbers
#define kMPOLnchNUMBtnIconRsrcID 10254
#define kMPOLnchNUMBtnIconRollRsrcID 10254

// PNG specific IDs The clear all stayles
#define kMPOLnchCLSTYBtnIconRsrcID 10255
#define kMPOLnchCLSTYBtnIconRollRsrcID 10255

// PNG specific IDs The find Change
#define kMPOLnchFCBtnIconRsrcID 10256
#define kMPOLnchFCBtnIconRollRsrcID 10256


// PNG specific IDs The item finder
#define kMPOLnchIFBtnIconRsrcID 10257
#define kMPOLnchIFBtnIconRollRsrcID 10257

// PNG specific IDs The image placer
#define kMPOLnchIMGBtnIconRsrcID 10258
#define kMPOLnchIMGBtnIconRollRsrcID 10258


// PNG specific IDs The clear xml
#define kMPOLnchCLXMLBtnIconRsrcID 10259
#define kMPOLnchCLXMLBtnIconRollRsrcID 10259



// PNG specific IDs color key
#define kMPOLnchCKEYBtnIconRsrcID 10260
#define kMPOLnchCKEYBtnIconRollRsrcID 10260

// PNG specific IDs The color paper
#define kMPOLnchCPAPBtnIconRsrcID 10261
#define kMPOLnchCPAPBtnIconRollRsrcID 10261

// PNG specific IDs The color xxx
#define kMPOLnchCXXXBtnIconRsrcID 10262
#define kMPOLnchCXXXBtnIconRollRsrcID 10262

// PNG specific IDs The color black mixed
#define kMPOLnchCMXDBtnIconRsrcID 10263
#define kMPOLnchCMXDBtnIconRollRsrcID 10263


// PNG specific IDs The link
#define kMPOLnchLNKBtnIconRsrcID 10264
#define kMPOLnchLNKBtnIconRollRsrcID 10264

// PNG specific IDs The link
#define kMPOLnchQCKBtnIconRsrcID 10265
#define kMPOLnchQCKBtnIconRollRsrcID 10265

#endif // __MPOLnchID_h__

// End, MPOLnchID.h.


