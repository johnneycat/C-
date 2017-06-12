#include <stdio.h>
#include <stdlib.h>
//1/
 typedef int (*hande_type_inner)(char* s);

 void handle_type(hande_type_inner hande_type_inner_func, void *match_data)
 {
 	if(hande_type_inner_func((char*)match_data))
 		printf("%s\n", "------1-----\n");
 }
 //2/
 void handle_type_2(int (*handle_type)(char* s), char* s)
 {
 	handle_type(s);
 }


int fuck(char*s)
{
	printf("%s\n", "------2-----");
	printf("%s\n", s);
	return 1;
}

int main()
{
	//1
	//handle_type(fuck, "hello world");
	handle_type_2(fuck, "hello world");
	return 0;
}