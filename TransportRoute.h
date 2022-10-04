#ifndef TRANSPORTROUTE_H
#define TRANSPORTROUTE_H

namespace Main {
	class TransportRoute : Main::MapComponent {

	private:
		Main::Area* to;
		Main::Area* from;
		bool available;
	};
}

#endif
