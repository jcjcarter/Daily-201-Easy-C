// Daily 201 Easy C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <time.h>

int main(int argc, char** argv) {

	time_t today;
	struct tm until;
	time(&today);
	until = *localtime(&today);
	until.tm_year = atoi(argv[1]) - 1900;
	until.tm_mon = atoi(argv[2]) - 1;
	until.tm_mday = atoi(argv[3]);

	long dif = (mktime(&until) - today) / 86400;
	printf("%li day%c %s %s-%s-%s.\n",
		dif < 0 ? -dif : dif,
		(dif*dif) == 1 ? 0 : 's',
		dif < 0 ? "since" : "until",
		argv[1], argv[2], argv[3]);
	return 0;
}