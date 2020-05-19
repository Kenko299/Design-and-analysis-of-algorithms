#include <stdio.h>
int main()
{
	int a[10]={1, 2,3,4,5,6,7,8,9,10};
	int i;
	int n;
	scanf("%d", &n);
	int flag = 0;
	for (i = 0; i < 9; i++)
	{
		if (a[i] == n)
		{
			printf("%d", i);
			flag = 1;
			break;
		}
	}
	if (flag = 0)
	{
		printf("0");
	}
}