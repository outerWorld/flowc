
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <time.h>
#include <sys/time.h>

#include "perf_mon.h"

#define QUE_NUM		1024
#define ELEM_SIZE	1024
static char queue[QUE_NUM][ELEM_SIZE];

static int test_memcpy(int times)
{
	int i, j;

	for (i = 0; i < times; i++) {
		for (j = 0; j < QUE_NUM; j++) {
			perf_mon_here(0, ST_START);
			memcpy(queue[j], queue[QUE_NUM], ELEM_SIZE);
			perf_mon_here(0, ST_END);
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	int times = 0;
	
	if (argc < 2) times = 100;
	else times = atoi(argv[1]);

	perf_mon_init(5, times*QUE_NUM);
	perf_mon_add(0, "mod_memcpy");

	test_memcpy(times);

	while (1) usleep(1000);	

	perf_mon_destroy();

	return 0;
}
