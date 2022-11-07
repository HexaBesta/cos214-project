#ifndef COUNTVISITOR_H
#define COUNTVISITOR_H

#include "Visitor.h"
class TranportRoute;
class Area;

using namespace std;

class CountVisitor : public Visitor
{
    public:
    /**
     * @brief this function will count how many areas are occupied by different alliances
     * 
     * @param area takes in a pointer of the area to iterate through the area
     */
    virtual void visit(Area* area);

    /**
     * @brief this function will count the amount of transport routes adjacent to the specific area
     * 
     * @param transport will take in the transport route to iterate through the adjacent transport routes
     */
    virtual void visit(TransportRoute* transport);

    /**
     * @brief Returns the counts of the Areas and TransportRoutes
     * 
     * @return string 
     */
    string displayCount();

    /**
     * @brief Returns if either alliance has won
     * 
     * @return int 
     */
    int warLoopComplete();
    
    private:
        int alliance2Count = 0;
        int alliance1Count = 0;
        int alliance2CountTransport = 0;
        int alliance1CountTransport = 0;
};

#endif
