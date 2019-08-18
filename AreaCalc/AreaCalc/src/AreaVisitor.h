///////////////////////////////////////////////////////////
//  AreaVisitor.h
//  Implementation of the Class AreaVisitor
//  Created on:      17-Aug-2019 22:53:36
///////////////////////////////////////////////////////////

#if !defined(EA_5EE63171_AEB5_403e_9B5F_B4306B566EBC__INCLUDED_)
#define EA_5EE63171_AEB5_403e_9B5F_B4306B566EBC__INCLUDED_

#include "IVisitor.h"

class AreaVisitor : public IVisitor
{

public:
	AreaVisitor();
	virtual ~AreaVisitor();

	virtual double Visit(Circle& c);
	virtual double Visit(Rectangle& r);
	virtual double Visit(Triangle& t);

};
#endif // !defined(EA_5EE63171_AEB5_403e_9B5F_B4306B566EBC__INCLUDED_)
