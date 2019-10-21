// wxblank
// 10/20/19

#include <iostream>
#include <sstream>

#include "artie.h"

void artie::generate_help() {
	if(program.empty()) {
		std::cerr << ARTIE_TAG << ARTIE_WARN << "No program name given!\n";
		program = "artie";
	}

	std::string short_nop_opt, required;
	short_nop_opt = ""; // short, no params, optional
	required = "";

	std::ostringstream oss;
	oss << "Usage: " << program << " " << short_nop_opt << required << "OPTIONS..." << "\n";
	oss << description << "\n";
	//oss << "Options\n";
	help_statement = oss.str();
}

void artie::print_help() {
	if(help_statement.empty()) generate_help();

	std::cout << help_statement << std::endl;
}

void artie::generate_version() {
	if(program.empty()) {
		std::cerr << ARTIE_TAG << ARTIE_WARN << "No program name given!\n";
		program = "artie";
	}

	std::ostringstream oss;
	oss << program;
	if(!version.empty()) oss << " " << version;
	if(!build.empty()) oss << " (" << build << ")";
	if(!builddate.empty()) oss << "\n" << "Compiled on " << builddate;
	oss << "\n\n";

	oss << "Written by " << author;
	if(!website.empty()) oss << " <" << website << ">";
	version_statement = oss.str();
}

void artie::print_version() {
	if(version_statement.empty()) generate_version();

	std::cout << version_statement << std::endl;
}

// cstring array to std::string vector
std::vector<std::string> artie::argv_vector(char *_argv[]) {
	std::vector<std::string> v;
	for(char **a = _argv; *a; ++a) {
		v.push_back(std::string(*a));
	}
	return v;
}