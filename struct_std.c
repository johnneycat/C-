#include <stdio.h>
#include <stdlib.h>

struct mstru{
int x;
int y;
};

int main()
{
        struct mstru m = {.x = 10, .y = 20};
        struct mstru n = {20,30};
	struct mstru n = {.x = 40};
	return 0;
}

