#include "monty.h"

instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{NULL, NULL}
};

global_t global = {
	instructions,
	0
};
