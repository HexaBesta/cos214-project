#ifndef MAPCOMPONENT_H
#define MAPCOMPONENT_H

namespace Main {
	class MapComponent {

	private:
		Map *  map;

	public:
		void attach(Map *  map);

		void detach(Map *  map);

		void accept(Main::Visitor* visitor);

		void attach(Map *  map);

		void detach(Map *  map);
	};
}

#endif
