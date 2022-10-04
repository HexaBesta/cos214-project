#ifndef BATTLE_H
#define BATTLE_H

namespace Main {
	class Battle {

	private:
		Main::Platoon* sideOne;
		Main::Platoon* sideTwo;
		/**
		 * true = side 1
		 * false = side 2
		 */
		bool turn;
		boolean active;
		Main::Area* area;

	public:
		virtual void changeStrategy() = 0;

		virtual void attack() = 0;

		virtual bool requestReinforcements() = 0;

		string stateSummary();

		void takeTurn();
	};
}

#endif
