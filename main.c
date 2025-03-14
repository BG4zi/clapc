#include "nob.h"
#include <stdio.h>
#include <string.h>

typedef enum {
  INT,
  CHAR,
  STR,
  BOOL,
} ArgValType;

struct arg
{
  ArgValType valType;  
};


void check(char *argv,  struct arg *arg_list[]) {
  (void) arg_list;
  (void) argv;
  printf("NOT IMPLEMENTED YET!\n");
}

int main(int argc, char *argv[])
{
  printf("Argc: %d\n", argc);
  printf("Argv: %s\n", argv[0]);
  struct arg sample = {.valType=INT};
  struct arg *arg_list[100] = {
	 &sample
  };

  

  while (*argv != NULL) {
	 char *arg = *argv++;
	 if (arg[0] == '-' && arg[1] == '-') {
		printf("%s: This is a long subcommand\n", arg);
		check(arg, arg_list);
	 }
	 else if (arg[0] == '-' && arg[1] != '-') {
		printf("%s: This is a short subcommand\n", arg);
		check(arg, arg_list);
	 }
	 else {
		printf("%s: This is not a familiar subcommand\n", arg);
	 }
  }
  
  return 0;
}
