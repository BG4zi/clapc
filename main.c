#include "nob.h"
#include <stdio.h>
#include <string.h>

typedef enum {
  ARG_SHORT,
  ARG_LONG,  
} ArgType;

void check(char *argv, ArgType type, char *arg_list[]) {
  (void) arg_list;
  (void) argv;
  (void) type;
  printf("NOT IMPLEMENTED YET!\n");
}

int main(int argc, char *argv[])
{
  printf("Argc: %d\n", argc);
  printf("Argv: %s\n", argv[0]);
  char *arg_list[] = {""};

  while (*argv != NULL) {
	 char *arg = *argv++;
	 if (arg[0] == '-' && arg[1] == '-') {
		printf("%s: This is a long subcommand\n", arg);
		check(arg, ARG_LONG, arg_list);
	 }
	 else if (arg[0] == '-' && arg[1] != '-') {
		printf("%s: This is a short subcommand\n", arg);
		check(arg, ARG_SHORT, arg_list);
	 }
	 else {
		printf("%s: This is not a familiar subcommand\n", arg);
	 }
  }
  
  return 0;
}
