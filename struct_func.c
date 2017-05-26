#include <unistd.h>
#include <sys/syscall.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <linux/sysctl.h>

typedef struct HELLO
{
	char *c;
	int a;
	int (*func)(int);
};

int world(int c)
{
	printf("%d\n", c);
}

struct HELLO hi = {
	.c = "good morning",
	.func = world,
};

int main()
{
	// struct HELLO hello;
	// hello.func = world;
	// hello.func(10);
	hi.func(10);
	return 0;
}