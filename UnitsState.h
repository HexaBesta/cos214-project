#ifndef UNITSSTATE_H
#define UNITSSTATE_H

namespace Main {
	class UnitsState {

	private:
		Main::DeployedState* deployedState;

	public:
		virtual void handleUnits() = 0;

		virtual Main::UnitsState changeUnitState() = 0;

		void request();

		void setDeployedState(Main::DeployedState deployedState);
	};
}

#endif
