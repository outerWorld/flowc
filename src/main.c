// encoding = utf-8
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "util.h"

#include "version.h"
#include "opt.h"
#include "log.h"
#include "pkt_sender.h"
#include "pkt_capture.h"
#include "pkt_gen.h"
#include "scheduler.h"

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

	if (opt.daemon_on) {
		set_daemon();
	}

	if (0 != log_init()) {
		return 1;
	}

	if (!opt.capture_open && !opt.gen_open) {
		usage(argv[0]);
		return 1;
	}

	pkt_sender_init(opt.send_num, opt.dest_list, opt.interval);
	pkt_sender_run();

	if (opt.storage_open) {
		storage_init(opt.split_interval, opt.file_info);
		storage_run();
	}

	if (opt.capture_open) {
		pkt_capture_init(opt.dev_list, opt.filter);
		pkt_capture_run();
	}

	if (opt.gen_open) {
		pkt_gen_init(opt.gen_file);
		pkt_gen_run();
	}

	scheduler_init();
	scheduler_run();

	return 0;
}
