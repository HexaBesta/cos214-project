#ifndef DEPLOYEDSTATE_H
#define DEPLOYEDSTATE_H

namespace Main {
	class DeployedState : Main::UnitsState {


	public:
		virtual void handleDeployed() = 0;

		virtual Main::DeployedState changeDeployedState() = 0;
	};
}

#endif
