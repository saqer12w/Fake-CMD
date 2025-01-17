#include <iostream>
#include <string>
#include <map>
#include <thread>
#include <vector>
#include <stdexcept>
#include <chrono>
#include <sstream>
#include "modules/modules.h"
#include "utility/utility.h"

extern std::map<std::string, module> modules;

int main(int argc, char **argv) {

	puts("Microsoft Windows [Version 10.0.69420.6789]\n(c) Microsoft Corporation. All rights reserved.\n");

	while (true) {

		std::string input;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		fputs("C:\\WINDOWS\\System32>", stdout);
		fflush(stdout);
		std::getline(std::cin, input);

		command cmd = tokenizeCommand(input);

		if (cmd[0].empty()) {
			continue;
		}

		if (cmd[0] == "exit") {
			break;

		} else if (modules.count(cmd[0]) > 0) {
			auto func = modules[cmd[0]];
			func(cmd);
		} else {
			fputs("Unknown Command\n", stderr);
			fflush(stderr);
		}

	}

	return 0;

}