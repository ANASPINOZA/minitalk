#include<stdio.h>

int g_pid = 0;

int	func(void)
{
	static int a;
	
	g_pid += 5;
	a += 5;
	printf("--------a-------%d\n",a);
}

int	main(void)
{
	func();
	func();
	func();
	printf("---------g_pid----------%d\n",g_pid);
}
