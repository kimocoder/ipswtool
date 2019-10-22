// wxblank
// 10/20/19

#include <iostream>
#include <vector>

#include "include/artie/artie.h"

#define PROGRAM_NAME "ipswtool"
#define PROGRAM_DESCRIPTION "Read IPSW file properties"
#define PROGRAM_AUTHOR "wxblank"
#define PROGRAM_WEBSITE "https://wxb1ank.github.io/"

#define VERSION "1.0"

std::vector<arg_t> args = {
	{'i', "ipsw"},
	{'h', "help"},
	{NULL, "version"}
};

int main(int argc, char *argv[]) {
	artie art(PROGRAM_NAME, PROGRAM_DESCRIPTION, PROGRAM_AUTHOR, argv);
	art.website = PROGRAM_WEBSITE;
	art.version = VERSION;

	#ifdef BUILD_NUMBER
	art.build = BUILD_NUMBER;
	#endif

	#ifdef BUILD_DATE
	art.builddate = BUILD_DATE;
	#endif

	art.args = args;

	if(argc == 1) { art.print_help(); exit(0); }
	art.print_version(); exit(0);

	// TODO

	
	
	return 0;
}