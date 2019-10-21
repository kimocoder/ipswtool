// wxblank
// 10/20/19

#ifndef ARTIE_H
#define ARTIE_H

#include <string>
#include <vector>

#define ARTIE_TAG "<ARTIE> "
#define ARTIE_ERROR "ERROR: "
#define ARTIE_WARN "WARNING: "

typedef struct {
	char shortarg;
	std::string longarg;
} arg_t;

class artie {
public:
	std::string author;
	std::string description;
	std::string program;
	std::string website;

	std::string build;
	std::string builddate;
	std::string version;

	std::vector<std::string> given;

	std::vector<arg_t> args;
	std::string help_statement;
	std::string version_statement;

	void generate_help();
	void print_help();
	void generate_version();
	void print_version();

	std::vector<std::string> argv_vector(char *_argv[]);

	// constructors
	artie(char *_argv[]) { given = argv_vector(_argv); }
	artie(std::string _program, char *_argv[]) { program = _program; given = argv_vector(_argv); }
	artie(std::string _program, std::string _description, char *_argv[]) { program = _program; description = _description; given = argv_vector(_argv); }
	artie(std::string _program, std::string _description, std::string _author, char *_argv[]) {
		program = _program; description = _description; author = _author; given = argv_vector(_argv);
	}
};

#endif