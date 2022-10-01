#ifndef VISITOR_H
#define VISITOR_H

namespace Main {
	class Visitor {


	public:
		virtual void visitArea(Main::Area* area) = 0;

		virtual void visitTransportRoute(Main::TransportRoute* transportRoute) = 0;
	};
}

#endif
