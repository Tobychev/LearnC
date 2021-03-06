#include <stdio.h>
#include <apr_general.h>
#include <apr_strings.h>
#include <apr_getopt.h>
#include <apr_lib.h>

#include "../dbg.h"
#include "commands.h"
#include "db.h"

int main(int argc, const char const *argv[])
{
	apr_pool_t* p = NULL;
	apr_pool_initialize();
	apr_pool_create(&p,NULL);

	apr_getopt_t* opt;
	apr_status_t rv;

	char ch = '\0';
    const char *optarg = NULL;
    const char *config_opts = NULL;
    const char *install_opts = NULL;
    const char *make_opts = NULL;
    const char *url = NULL;
    enum CommandType request = COMMAND_NONE;

	rv = apr_getopt_init(&opt, p, argc, argv);

	while (apr_getopt(opt,"I:Lc:m:i:d:SF:B:", &ch, &optarg) == APR_SUCCESS) {
		switch (ch) {
			case 'I':
				request = COMMAND_INSTALL;
				url = optarg;
				break;

			case 'L':
				request = COMMAND_LIST;
				break;

			case 'c':
				config_opts = optarg;
				break;

			case 'm':
				make_opts = optarg;
				break;

			case 'i':
				install_opts = optarg;
				break;

			case 'S':
				request = COMMAND_INIT;
				break;

			case 'F':
				request = COMMAND_FETCH; 
				url = optarg;
				break;

			case 'B':
				request = COMMAND_BUILD;
				url = optarg;
				break;

			default:
				log_info("Unknown command");}}

	switch (request) {
		case COMMAND_INSTALL:
			check(url != NULL, "You must specify an URL.");
			Command_install(p, url, config_opts, make_opts, install_opts);
			break;

		case COMMAND_LIST:
			DB_list();
			break;

		case COMMAND_FETCH:
			check(url != NULL, "You must specify an URL.");
			Command_fetch(p, url, 1);
			log_info("Downloaded target to %s",BUILD_DIR);
			break;

		case COMMAND_BUILD:
			check(url != NULL, "You must specify an URL.");
			Command_install(p, url, config_opts, make_opts, install_opts);
			break;

		case COMMAND_INIT:
			rv = DB_init();
			check(rv == 0, "Failed to create database.");
			break;

		case COMMAND_NONE:
			printf("Usage: give one of the flags -S -I -L -F -B with apropriate arguments\n");
			break;

		default:
			sentinel("Invalid command given");}

	apr_pool_terminate();
	return 0;

error:

	apr_pool_terminate();
	return 1;
}
