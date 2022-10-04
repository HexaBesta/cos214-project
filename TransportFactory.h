#ifndef TRANSPORTFACTORY_H
#define TRANSPORTFACTORY_H

namespace Main {
	class TransportFactory {

	private:
		Main::Transport* transport;

	public:
		virtual Main::Transport* makeTypeTransport() = 0;
	};
}

#endif
