#include<stdio.h>
#include<math.h>


 int main()
 {
         int a[5]={1,2,3,4,5};
	abs(a[0]);
         printf("a=%x\n",a);
         printf("&a=%x\n",&a);
         printf("*(int*)&a=%x\n",(*((int *)(&a))));
         printf("*&a=%x\n",(*(*(&a))));
         printf("&a[0]=%x\n",&a[0]);
         printf("*&a[0]=%x\n",*(&a[0]));
         return 0;
 }

