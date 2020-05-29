#include <iostream>
#include <stdio.h>
#include <string.h>


int main(int argc, const char **argv) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else {
		for (size_t n = 1; n < argc; n++) {
			const size_t len = strlen(argv[n]);
			for (size_t i = 0; i < len; i++) {
    			std::cout << (char)std::toupper(argv[n][i]);
  			}
  		}
	}
}