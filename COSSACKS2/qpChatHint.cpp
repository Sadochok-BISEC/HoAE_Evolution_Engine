#include "stdheader.h"
//////////////////////////////////////////////////////////////////////////
#include "supereditor.h"
//////////////////////////////////////////////////////////////////////////
bool qpChatHint::Execute(){
	StringType op;
	if(Op.Get()&&Op.Get()->Get(&op)){
		AssignHint1(op.String.pchar(),100);
		return true;
	}
	return false;
};