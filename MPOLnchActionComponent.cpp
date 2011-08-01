//========================================================================================
//  
//  $File: //depot/indesign_6.0/highprofile/source/sdksamples/wlistboxcomposite/MPOLnchActionComponent.cpp $
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
//========================================================================================

#include "VCPlugInHeaders.h"


// Interface includes:
#include "IWidgetUtils.h"
#include "IPanelControlData.h"
#include "IControlView.h"
#include "IActionStateList.h"
#include "ITreeViewController.h"
#include "ITreeViewMgr.h"
#include "ITreeViewHierarchyAdapter.h"
#include "IStringListData.h"

// General includes:
#include "CActionComponent.h"
#include "CAlert.h"
#include "MPOLnchNodeID.h"

#include "K2Vector.tpp" // For NodeIDList to compile

// Project includes:
#include "MPOLnchID.h"
// file creation
#include "FileUtils.h"
#include "CoreFileUtils.h"
#include "StreamUtil.h"
#include <fstream>
#include <cstdlib>
#include <string>


/** MPOLnchActionComponent
	All about the user actions

	@ingroup wlistboxcomposite
	
*/
class MPOLnchActionComponent : public CActionComponent
{
	public:
		/**
			Constructor.
			@param boss interface ptr from boss object on which this interface is aggregated.
		*/
		MPOLnchActionComponent(IPMUnknown* boss);

		/**
			The action component should do the requested action.
			This is where the menu item's action is taken.
			When a menu item is selected, the Menu Manager determines
			which plug-in is responsible for it, and calls its DoAction
			with the ID for the menu item chosen.

			@param actionID identifies the menu item that was selected.
			*/
		virtual void DoAction(IActiveContext *myContext, ActionID actionID, GSysPoint mousePoint, IPMUnknown *widget);
		/**

			Framework will call this method to ask us to update the states of the items.
		*/
		virtual void	UpdateActionStates(IActiveContext *myContext, IActionStateList *listToUpdate, GSysPoint mousePoint, IPMUnknown *widget);

	private:
		/** Encapsulates functionality for the about menu item. */
		void DoAbout();

		/** Encapsulates functionality for the AddItem menu item. 
			
			@param invokedWidget Widget that initiated the event (the panel menu), useful for getting the panel & other widgets.
		*/
		void DoAddItem(IPMUnknown *invokedWidget);
	
	
		/* My personal copyFile
		 * until i get FileUtils::CopyFile() to work
		 */
	//	bool copyFile (const char SRC[], const char DEST[]);


		/** Encapsulates functionality for the RemoveItem menu item. 
		
			@param invokedWidget Widget that initiated the event. (The panel menu.)
		*/
		void DoRemoveItem(IPMUnknown *invokedWidget);

};

/* CREATE_PMINTERFACE
 Binds the C++ implementation class onto its
 ImplementationID making the C++ code callable by the
 application.
*/
CREATE_PMINTERFACE(MPOLnchActionComponent, kMPOLnchActionComponentImpl)

/* MPOLnchActionComponent Constructor
*/
MPOLnchActionComponent::MPOLnchActionComponent(IPMUnknown* boss)
: CActionComponent(boss)
{
}

/* DoAction
*/
void MPOLnchActionComponent::DoAction(IActiveContext *myContext, ActionID actionID, GSysPoint mousePoint, IPMUnknown *widget)
{
	switch (actionID.Get())
	{
		case kMPOLnchPopupAboutThisActionID:
		case kMPOLnchAboutActionID:
		{
			this->DoAbout();
			break;
		}

		case kMPOLnchAddItemActionID:
		{
			this->DoAddItem(widget);
			break;
		}

		case kMPOLnchRemoveItemActionID:
		{
			//this->DoRemoveItem(widget);
			CAlert::InformationAlert("This optin doesn't work right now. Sry");

			break;
		}

		default:
		{
			break;
		}
	}
}


/* UpdateActionStates

*/

void MPOLnchActionComponent::UpdateActionStates(IActiveContext *myContext, IActionStateList *listToUpdate, GSysPoint mousePoint, IPMUnknown *widget)
{
	do {

		int listElementCount = 0;
		InterfacePtr<IControlView> treeWidget(static_cast<IControlView*>(Utils<IWidgetUtils>()->QueryRelatedWidget(widget, kMPOLnchListBoxWidgetID, IID_ICONTROLVIEW)));
		ASSERT(treeWidget);
		if(!treeWidget) {
			break;
		}

		InterfacePtr<ITreeViewController> 	controller(treeWidget, UseDefaultIID());
		ASSERT(controller);
		if(!controller)
		{
			break;
		}

		NodeIDList selectedItems;
		controller->GetSelectedItems(selectedItems);
		listElementCount = selectedItems.size();

		for(int i=0; i < listToUpdate->Length(); i++) {

			ActionID action = listToUpdate->GetNthAction(i);
			switch (action.Get())
			{

				case kMPOLnchRemoveItemActionID:
					if(listElementCount>0) {
						listToUpdate->SetNthActionState(i,kEnabledAction);
					}
					else {
						listToUpdate->SetNthActionState(i,kDisabled_Unselected);
					}
					break;
			}
		}

	} while(0);


}



/* DoAbout
*/
void MPOLnchActionComponent::DoAbout()
{
	CAlert::ModalAlert
	(
	   kMPOLnchAboutBoxStringKey,			// Alert string
	   kOKString, 							// OK button
	   kNullString, 						// No second button
	   kNullString, 						// No third button
	   1,									// Set OK button to default
	   CAlert::eInformationIcon				// Information icon.
	);
}

/* DoAddItem
*/
void MPOLnchActionComponent::DoAddItem(IPMUnknown *invokedWidget)
{
	// building the scripts
	
		const int MAXITEMS = 12;
		
		
		PMString newscriptfiles[MAXITEMS] = {
			"newscriptfile01.jsx",
			"newscriptfile02.jsx",
			"newscriptfile03.jsx",
			"newscriptfile04.jsx",
			"newscriptfile05.jsx",
			"newscriptfile06.jsx",
			"newscriptfile07.jsx",
			"newscriptfile08.jsx",
			"newscriptfile09.jsx",
			"newscriptfile10.jsx",
			"newscriptfile11.jsx",
			"newscriptfile12.jsx"};
		

	PMString helpfiles[MAXITEMS] = {
		"help_newscriptfile01.jsx",
		"help_newscriptfile02.jsx",
		"help_newscriptfile03.jsx",
		"help_newscriptfile04.jsx",
		"help_newscriptfile05.jsx",
		"help_newscriptfile06.jsx",
		"help_newscriptfile07.jsx",
		"help_newscriptfile08.jsx",
		"help_newscriptfile09.jsx",
		"help_newscriptfile10.jsx",
		"help_newscriptfile11.jsx",
		"help_newscriptfile12.jsx"};

		
		for (int i = 0; i < MAXITEMS ; i++) {
			

			IDFile theSource;//scriptfiles[i];
			
			FileUtils::GetAppInstallationFolder(&theSource); 
			FileUtils::AppendPath(&theSource, PMString("Plug-Ins"));                
			FileUtils::AppendPath(&theSource, PMString("tmn"));                
			FileUtils::AppendPath(&theSource, PMString("MPOLauncher.InDesignPlugin"));                
//			
			FileUtils::AppendPath(&theSource, PMString("Versions"));                
			FileUtils::AppendPath(&theSource, PMString("A"));                
			FileUtils::AppendPath(&theSource, PMString("Resources"));

			IDFile theHelpSource;//scriptfiles[i];
			
			FileUtils::GetAppInstallationFolder(&theHelpSource); 
			FileUtils::AppendPath(&theHelpSource, PMString("Plug-Ins"));                
			FileUtils::AppendPath(&theHelpSource, PMString("tmn"));                
			FileUtils::AppendPath(&theHelpSource, PMString("MPOLauncher.InDesignPlugin"));                
			//			
			FileUtils::AppendPath(&theHelpSource, PMString("Versions"));                
			FileUtils::AppendPath(&theHelpSource, PMString("A"));                
			FileUtils::AppendPath(&theHelpSource, PMString("Resources"));
			
			
			FileUtils::AppendPath(&theSource, PMString(newscriptfiles[i]));
			FileUtils::AppendPath(&theHelpSource, PMString(helpfiles[i]));
			
			PMString sourceFileStringUrl = FileUtils::SysFileToFileURL(theSource);
			PMString sourceHelpFileStringUrl = FileUtils::SysFileToFileURL(theHelpSource);

			if(!FileUtils::DoesFileExist(theSource)){
				CAlert::InformationAlert(" could not find the Source File. I am Here-> " + sourceFileStringUrl 
										 +"\n"+
										 " Please report this bug to: fabiantheblind@the-moron.net");
				break;
			}
			
			if(!FileUtils::DoesFileExist(theHelpSource)){
				CAlert::InformationAlert(" could not find the Help File. I am Here-> " + sourceHelpFileStringUrl 
										 +"\n"+
										 " Please report this bug to: fabiantheblind@the-moron.net");
				break;
			}
				
			
			IDFile theTarget; 
			FileUtils::GetAppInstallationFolder(&theTarget); 
			FileUtils::AppendPath(&theTarget, PMString("Scripts"));                
			FileUtils::AppendPath(&theTarget, PMString("Scripts Panel"));
			FileUtils::AppendPath(&theTarget, PMString("MPO Launcher"));
			FileUtils::CreateFolderIfNeeded(theTarget,kTrue);

			IDFile theHelpTarget; 
			FileUtils::GetAppInstallationFolder(&theHelpTarget); 
			FileUtils::AppendPath(&theHelpTarget, PMString("Scripts"));                
			FileUtils::AppendPath(&theHelpTarget, PMString("Scripts Panel"));
			FileUtils::AppendPath(&theHelpTarget, PMString("MPO Launcher"));
			FileUtils::AppendPath(&theHelpTarget, PMString("help"));
			
			FileUtils::CreateFolderIfNeeded(theHelpTarget,kTrue);

			PMString fn(newscriptfiles[i]);
			PMString fnh(helpfiles[i]);
			
			FileUtils::AppendPath(&theTarget, fn);
			FileUtils::AppendPath(&theHelpTarget, fnh);

			if(!FileUtils::DoesFileExist(theTarget)){
				CAlert::InformationAlert("I will try to copy "+fn+ " to the folder: Scripts Panel/MPO Launcher");
					if(!FileUtils::CopyFile(theSource, theTarget)){
						CAlert::InformationAlert("Could not copy "+fn+". Sorry");
					}
			}
			
			if(!FileUtils::DoesFileExist(theHelpTarget)){
				CAlert::InformationAlert("I will try to copy "+fnh+ " to the folder: Scripts Panel/MPO Launcher/help");
					if(!FileUtils::CopyFile(theHelpSource, theHelpTarget)){
						CAlert::InformationAlert("Could not copy "+fnh+". Sorry");
					}
				}			
			}

		
		
	
}


/* DoRemoveItem
*/
void MPOLnchActionComponent::DoRemoveItem(IPMUnknown *invokedWidget)
{
	InterfacePtr<IControlView> treeWidget(static_cast<IControlView*>(Utils<IWidgetUtils>()->QueryRelatedWidget(invokedWidget, kMPOLnchListBoxWidgetID, IID_ICONTROLVIEW)));
	InterfacePtr<ITreeViewMgr> treeMgr(treeWidget, UseDefaultIID());

	InterfacePtr<ITreeViewController> 	controller(treeWidget, UseDefaultIID());


	NodeIDList selectedItems;
	controller->GetSelectedItems(selectedItems);
	int32 listElementCount = selectedItems.size();
    if (selectedItems.size() > 0)
    {
		//Notify node to be deleted
        treeMgr->BeforeNodesDeleted(selectedItems);

        // delete items
        K2Vector<NodeID>::const_iterator iter, startIter, endIter;
        startIter = selectedItems.begin();
        endIter = selectedItems.end();
 		InterfacePtr<IStringListData> iListData(treeWidget, IID_ISTRINGLISTDATA);
		K2Vector<PMString> lists = iListData->GetStringList();
        for(iter = startIter; iter != endIter; ++iter)
        {
			const MPOLnchNodeID* oneNode = static_cast<const MPOLnchNodeID*>(iter->Get());
			PMString item = oneNode->GetName();

			K2Vector<PMString>::iterator s_iter = std::find(lists.begin(), lists.end(), item);
			if (s_iter != lists.end())
				lists.erase(s_iter);
        }
		iListData->SetStringList(lists);
	}
 	
}


// End, MPOLnchActionComponent.cpp.


