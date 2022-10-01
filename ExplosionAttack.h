#ifndef EXPLOSIONATTACK_H
#define EXPLOSIONATTACK_H

namespace Main {
	class ExplosionAttack : Main::PlatoonStrategy {


	public:
		virtual void attack(Main::Platoon plankton) = 0;
	};
}

#endif
