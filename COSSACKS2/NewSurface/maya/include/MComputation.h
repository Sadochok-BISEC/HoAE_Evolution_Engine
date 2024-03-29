#ifndef _MComputation
#define _MComputation
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
// CLASS:    MComputation
//
// *****************************************************************************
//
// CLASS DESCRIPTION (MComputation)
//
// An MComputation allows long computations to check for user interrupts.  It is
// very simple to use.  Create a new MComputation object and call the
// beginComputation method at the beginning of the computation and call
// the endComputation method when you finish.  Then, during the computation,
// use the isInterruptRequested method to check if the user has requested
// that the computation terminate.
// 
// Example:
// 
//     MComputation computation;
//     computation.beginComputation();
//     for (int i= 1; i<1000; i++) {
//         Computation();  // Some expensive operation
//         if  (computation.isInterruptRequested()) break ;
//     }
//     computation.endComputation();			
//
//
// *****************************************************************************

#if defined __cplusplus

// *****************************************************************************

// INCLUDED HEADER FILES


#include <maya/MTypes.h>

// *****************************************************************************
// FORWARD DECLARATIONS
// *****************************************************************************

// CLASS DECLARATION (MComputation)

/// Interupt monitor for long computations
/**
 An MComputation is used to monitor user-interupts during int computations.
*/

#if defined(_WIN32)
#pragma warning(disable: 4522)
#endif // _WIN32

class OPENMAYA_EXPORT MComputation {

public:  
	///
			MComputation();
	///
	virtual	~MComputation();
	///
    void	beginComputation();
	///
    bool	isInterruptRequested();
	///
    void	endComputation();

protected:
// No protected members

private:
    const char* className() const;
	void *f_data;
};

#if defined(_WIN32)
#pragma warning(default: 4522)
#endif // _WIN32

// *****************************************************************************
#endif /* __cplusplus */
#endif /* _MComputation */
