
#ifndef _MAnimCurveClipboardItemArray
#define _MAnimCurveClipboardItemArray
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
// CLASS:    MAnimCurveClipboardItemArray
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MAnimCurveClipboardItemArray)
//
//  This class implements an array of MAnimCurveClipboardItems.  Common
// 	convenience functions are available, and the implementation is compatible
// 	with the internal Maya implementation so that it can be passed efficiently
// 	between plugins and internal maya data structures.
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MAnimCurveClipboardItem.h>
#include <maya/MStatus.h>

// *****************************************************************************

// DECLARATIONS

// *****************************************************************************

// CLASS DECLARATION (MAnimCurveClipboardItemArray)

///  Array of MAnimCurveClipboardItem data type (OpenMayaAnim)
/**
  Implement an array of MAnimCurveClipboardItem data type.
*/
#ifdef _WIN32
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYAANIM_EXPORT MAnimCurveClipboardItemArray
{

public:
    ///
					MAnimCurveClipboardItemArray();
    ///
					MAnimCurveClipboardItemArray(
									const MAnimCurveClipboardItemArray& other );
    ///
					MAnimCurveClipboardItemArray(
									const MAnimCurveClipboardItem src[],
									unsigned count );
    ///
					~MAnimCurveClipboardItemArray();
    ///
 	const MAnimCurveClipboardItem&		operator[]( unsigned index ) const;
    ///
 	MAnimCurveClipboardItem&			operator[]( unsigned index );
    ///
 	MStatus			set( const MAnimCurveClipboardItem& element,
						 unsigned index );
    ///
 	unsigned		length() const;
    ///
 	MStatus			remove( unsigned index );
    ///
 	MStatus			insert( const MAnimCurveClipboardItem & element,
							unsigned index );
    ///
 	MStatus			append( const MAnimCurveClipboardItem & element );
    ///
 	MStatus			clear();
    ///
	MStatus			get( MAnimCurveClipboardItem array[] ) const;
	///
	void			setSizeIncrement ( unsigned newIncrement );
	///
	unsigned		sizeIncrement () const;
	///
	bool			isValid( unsigned & failedIndex ) const;

protected:
// No protected members

private:
	bool							validate( unsigned int & index,
											  unsigned int rowCount ) const;
 	MAnimCurveClipboardItemArray&	operator = (
										const MAnimCurveClipboardItemArray&)
										const;
 	MAnimCurveClipboardItemArray&	operator = (
										const MAnimCurveClipboardItemArray&);
 	void*							fArray;
	static const char*				className();
};

#ifdef _WIN32
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MAnimCurveClipboardItemArray */
