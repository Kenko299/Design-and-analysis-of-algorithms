#include <stdio.h>
#include <stdlib.h>

int binary_search(int * list, int len, int target) {
	int low = 0;
	int hight = len - 1;
	int middle;
	while (low <= hight) {
		middle = (low + hight) / 2;
		if (list[middle] = target)	
		{
			printf("已找到该值，数组下标为:%d\n", middle+1);
			return middle;
		}
		else if (list[middle] > target)
		{
			hight = middle - 1;
		}
		else if (list[middle] < target)
		{
			low = middle + 1;
		}
	}
	printf("0");
	return -1;
}

int main()
{

	int a[] = { 2,4,5,8,9,44 };
	int n;
	scanf("%d", &n);
	int b = binary_search(a, sizeof(a) / 4, n);
	return 0;
}