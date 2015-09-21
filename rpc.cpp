#include "rpc.h"
#include "array2D.hpp"
#include <iostream>

void updateConfiguration(const DaemonConfiguration&) {
}

void sourceEvent(const SourceEvent&) {
}

void sendFrame(Frame f1, Frame f2) {
	std::cout << "Daemon ------(sendFrame)-----> Emu, id: " << f1.id << ", color:" << "(" << (int) f1.pixels(0,0).r << "," << (int) f1.pixels(0,0).g << "," << (int) f1.pixels(0,0).b << ")" << std::endl;
}

EmuConfiguration getConfiguration() {
	std::cout << "Emu --(getConfiguration)--> Daemon" << std::endl;
	EmuConfiguration config;
	config.height = 32;
	config.width = 26;
	config.framerate = 30;
	config.audio_latency = 0;
	config.bit_depth = 12;
	return config;
}
