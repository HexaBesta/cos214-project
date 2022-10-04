#ifndef PEWPEWATTACK_H
#define PEWPEWATTACK_H

namespace Main {
	class PewPewAttack : Main::PlatoonStrategy {


	public:
		virtual void attack(Main::Platoon* plankton) = 0;
	};
}

#endif
