#ifndef MAPNODE_H
#define MAPNODE_H

namespace Main {
	class MapNode {


	public:
		virtual void accept(Main::Visitor v) = 0;
	};
}

#endif
