#ifndef BOOMBOOMATTACK_H
#define BOOMBOOMATTACK_H

namespace Main {
	class BoomBoomAttack : Main::PlatoonStrategy {


	public:
		virtual void attack(Main::Platoon plankton) = 0;
	};
}

#endif
