#include <time.h>

unsigned int sleep(unsigned int seconds)
{
	struct timespec req;
	req.tv_sec = seconds;
	req.tv_nsec = 0;
	if (nanosleep(&req, NULL) == 0)
		return 0;
	return 0;
}
