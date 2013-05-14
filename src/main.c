
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "opt.h"

static int usage(char *progname)
{
	return 0;
}

int main(int argc, char*argv[])
{
	opt_t opt;

	opt_init("opt_define");

	if (0 != get_opt(argc, argv, &opt)) {
		usage(argv[0]);
		return 1;
	}

	return 0;
}
