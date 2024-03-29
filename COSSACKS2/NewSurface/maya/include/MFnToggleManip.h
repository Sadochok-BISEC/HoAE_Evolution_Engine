
#ifndef _MFnToggleManip
#define _MFnToggleManip
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
// CLASS:    MFnToggleManip
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnToggleManip)
//
// Function set for a base manipulator - the ToggleManip
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

// CLASS DECLARATION (MFnToggleManip)

/// ToggleManip function set (OpenMayaUI)
/**
MFnToggleManip is the function set for toggle manipulators.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAUI_EXPORT MFnToggleManip : public MFnManip3D
{
	declareDagMFn(MFnToggleManip, MFnManip3D);

public:
	///
	MObject		create(MStatus *ReturnStatus = NULL);
	///
	MObject		create(const MString &manipName,
					   const MString &toggleName,
					   MStatus *ReturnStatus = NULL);
	///
	MStatus		connectToTogglePlug(MPlug &togglePlug);
	///
	MPoint		startPoint(MStatus *ReturnStatus = NULL) const;
	///
	MVector		direction(MStatus *ReturnStatus = NULL) const;
	///
	double		length(MStatus *ReturnStatus = NULL) const;
	///
	bool		toggle(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	startPointIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	directionIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	lengthIndex(MStatus *ReturnStatus = NULL) const;
	///
	unsigned	toggleIndex(MStatus *ReturnStatus = NULL) const;
	///
	MStatus		setStartPoint(MPoint &startPoint);
	///
	MStatus		setDirection(MVector &direction);
	///
	MStatus		setLength(double length);
	///
	MStatus		setToggle(bool toggle);

protected:

private:

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnToggleManip */
