
#ifndef _MFnStateManip
#define _MFnStateManip
//
//-
// ==========================================================================
// Copyright  (C)  Alias Systems,  a division  of  Silicon Graphics  Limited.
// All rights  reserved.  These coded  instructions,  statements and computer
// programs  contain  unpublished information  proprietary to  Alias Systems,
// a  division  of  Silicon  Graphics  Limited,  which  is  protected by  the
// Canadian  and  US federal copyright law and  may not be disclosed to third
// parties or  copied  or  duplicated,  in  whole  or in part,  without prior
// written  consent  of Alias Systems, a division of Silicon Graphics Limited
// ==========================================================================
//+
//
// CLASS:    MFnStateManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnStateManip)
//
// Function set for a base manipulator - the state manipulator.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnBase.h>
#include <maya/MFnManip3D.h>
#include <maya/MObject.h>

// *****************************************************************************

// DECLARATIONS

class MPoint;

// *****************************************************************************

// CLASS DECLARATION (MFnStateManip)

/// StateManip function set (OpenMayaUI)
/**
MFnStateManip is the function set for state manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnStateManip : public MFnManip3D
{
	declareDagMFn(MFnStateManip, MFnManip3D);

public:
	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &stateName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToStatePlug(MPlug &statePlug);
	///
	MStatus		setInitialState(unsigned initialState);
	///
	MStatus		setMaxStates(unsigned numStates);
	///
	unsigned	maxStates(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	state(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	positionIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	stateIndex(MStatus *ReturnStatus = NULL) const;

protected:

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnStateManip */
