#ifndef BRANCH_H
#define BRANCH_H

namespace Main {
	class Branch : Main::Unit {

	public:
		Main::Unit* unit;

		Branch(Main::Unit* unit);
	};
}

#endif
