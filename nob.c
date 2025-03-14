#include <stdlib.h>
#include <string.h>
#define NOB_IMPLEMENTATION
#include "nob.h"

#define CFLAGS "-Wall", "-Wextra", "-std=c11", "-pedantic"
#define BIN "clap"
#define SRC "main.c"


int main(int argc, char *argv[])
{
  NOB_GO_REBUILD_URSELF(argc, argv);
  Nob_Cmd cmd = {0};
  
  nob_cmd_append(&cmd, "cc", CFLAGS, "-o", BIN, SRC);
  if (!nob_cmd_run_sync(cmd)) return 1;

  if (argc > 1) {
	 if (strcmp(argv[1], "run") == 0) {
		Nob_Cmd cmd = {0};
		nob_cmd_append(&cmd, "./clap");
		argv+=2; // For escaping from ./nob amd run arguments
		for (size_t i = 0; i < argc - 2; ++i)
		  nob_cmd_append(&cmd, *argv++);
		if (!nob_cmd_run_sync(cmd)) return 1;
	 }
	 else {
		nob_log(NOB_ERROR, "ERROR: Unfamiliar subcommand: %s", argv[1]);
		exit(-1);
	 }

  }
  
  return 0;
}
