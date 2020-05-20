
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 7

void getData(int[], int);
void result_output(int[]);

int selectmink1(int a[], int low, int high, int k);
int selectmink2(int a[], int low, int high, int k);
int split(int a[], int low, int high);

int main(void)
{
	int a[N], k, r;

	getData(a, N); /* 获得数据放入数组a中 */

	printf("datas: \n");
	result_output(a);

	scanf("%d", &k);
	if (k >= 0 && k <= N - 1) {
		r = selectmink1(a, 0, N - 1, k);
		printf("result=%d\n", r);
		r = selectmink2(a, 0, N - 1, k);
		printf("result=%d\n", r);
	}
	else
		printf("input error: k=%d\n", k);

	return 0;
}

int selectmink1(int a[], int low, int high, int k)
{
	int middle;

	middle = split(a, low, high);
	if (middle == k)
		return a[k];
	else if (middle < k)
		return selectmink1(a, middle + 1, high, k);
	else /* if(middle > k) */
		return selectmink1(a, low, middle - 1, k);
}

int selectmink2(int a[], int low, int high, int k)
{
	int middle;

	for (;;) {
		middle = split(a, low, high);
		if (middle == k)
			return a[k];
		else if (middle < k)
			low = middle + 1;
		else /* if(middle > k) */
			high = middle - 1;
	}
}

int split(int a[], int low, int high)
{
	int part_element = a[low];

	for (;;) {
		while (low < high && part_element <= a[high])
			high--;
		if (low >= high) break;
		a[low++] = a[high];

		while (low < high && a[low] <= part_element)
			low++;
		if (low >= high) break;
		a[high--] = a[low];
	}

	a[high] = part_element;
	return high;
}

void getData(int d[], int n)
{
	time_t t;
	srand((unsigned)time(&t));  /* 设置随机数起始值 */

	int i;
	for (i = 0; i < n; i++)
		d[i] = rand() % 100; /* 获得0-99之间的整数值 */
}

void result_output(int a[])
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d ", a[i]);
	printf("\n");
}