#ifndef TRANSPORTROUTE_H
#define TRANSPORTROUTE_H

namespace Main {
	class TransportRoute : Main::MapNode {

	private:
		Main::Area* to;
		Main::Area* from;
		bool available;

	public:
		 bool attach(Main::Area* to);

		void notify();
	};
}

#endif
