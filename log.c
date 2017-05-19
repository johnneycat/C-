#include <stdio.h>
#include <stdlib.h>

#define HELLO "hello everyone"
#define WORLD "this morning i didn't eat anything"

#define Debug 0

#if Debug

#define DEBUG(format,...) printf("<"__FILE__" Line: %d: >"format"\n", __LINE__, ##__VA_ARGS__)  

#else
#define DEBUG(format,...)

#endif



//#define sh(x) printf("%s" ":" "%s" "=%d\n", __FILE__, __LINE__);

//#define log(...) printf(__VA_ARGS__)

int main()
{
	//char* hello = "hi" HELLO "fuck" WORLD "\n";
	//printf("%s", hello);
	int a = 10;
	//sh(10);
	DEBUG("-----:%d\n ", a);
}