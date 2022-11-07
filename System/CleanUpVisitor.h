#ifndef CLEANUPVISITOR_H
#define CLEANUPVISITOR_H
#include "Visitor.h"
#include "Area.h"
#include "TransportRoute.h"

class CleanUpVisitor : public Visitor {
    /**
     * @brief checks which areas are occupied and by who
     * 
     * @param area will check the area and the adjacent areas around the area
     */
	virtual void visit(Area* area);

    /**
     * @brief checks what transport routes are adjacent to the passed in transport route
     * 
     * @param route will iterate and find the adjacent transport routes and see which alliance they belong to.
     */
    virtual void visit(TransportRoute* route);
};

#endif