/*
 * @file: 	opt.h
 * @encode: utf-8
 * @author: huang chunping
 * @date:   2013-05-14
 * @history:
 */
#ifndef __OPT_H
#define __OPT_H

typedef struct _opt_s {
}opt_t, *opt_p;

int opt_init(char *opt_def_file);

int get_opt(int argc, char *argv[], opt_t *opt);

#endif // __OPT_H
