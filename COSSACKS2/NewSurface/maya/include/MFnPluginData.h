
#ifndef _MFnPluginData
#define _MFnPluginData
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
// CLASS:    MFnPluginData
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MFnPluginData)
//
//	diagram if the class is visual in nature.
//	All user defined data that is to be passed between nodes in the dependency
//	graph must be derived from MPxData.  The use of this class is closely
//	linked to the use of MPxDataCreator, MFnPluginData, MDataHandle, and
//	MTypeId.
//
//	In order to use user defined data, one must first create an instance of
//	the
//	MTypeId class that is initialized with a unique id tag.  Then create a new
//	class derived from MPxData to hold the user-defined data, As well as a
//	helper class derived from MPxDataCreator that can create instances of the
//	new derived type.
//
//	For data of this type that needs to be passed into a plug, one would get
//	an
//	MDataHandle for the attribute that uses the type.  This would result in a
//	call to the MPxDataCreator helper class that would create an instance of
//	the type inside the MDataHandle.  The MDataHandle::data method can then be
//	used to get an get an MObject for the user defined data and this should be
//	used to initialize an instance of MFnPluginData.  Then the
//	MFnPluginData::data method can be used to get an MPxData pointer, which
//	can
//	be safely cast to a pointer of the user defined type.  The data can be
//	updated through this pointer, after which the MDataHandle::setClean method
//	is used to complete the operation.
//
//	To receive data of this type from a plug, an MDataHandle for the attribute
//	that uses the new data type is created.  The MDataHandle::type method
//	should be used to ascertain that it contains kPlugin data.  Then the
//	MDataHandle::data method is used to get an MObject for the user defined
//	data and this should be used to initialize an instance of MFnPluginData.
//	The MFnPluginData::typeId method can be used to ascertain that the data is
//	in fact of the user defined type.  Then the MFnPluginData::data method can
//	be used to get an MPxData pointer, which can be safely cast to a pointer
//	to
//	the user defined type.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MFnData.h>

// *****************************************************************************

// DECLARATIONS

class MTypeId;
class MPxData;

// *****************************************************************************

// CLASS DECLARATION (MFnPluginData)

/// User defined data function set for dependency node data
/**
  Create and manipulate user defined dependency node data.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MFnPluginData : public MFnData 
{

	declareMFn(MFnPluginData, MFnData);

public:
	///
	MTypeId			typeId( MStatus* ReturnStatus = NULL ) const;
	///
	MPxData*		data( MStatus* ReturnStatus = NULL );
	///
	const MPxData*	constData( MStatus* ReturnStatus = NULL ) const;
	///
	MObject			create( const MTypeId& id, MStatus* ReturnStatus = NULL );

protected:
// No protected members

private:
// No private members

};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MFnPluginData */
