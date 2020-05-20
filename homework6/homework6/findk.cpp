#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int Split(int * a, int low, int high) {
	int i = low;
	int x = a[low];
	for (int j = low + 1; j <= high; j++) {
		if (a[j] <= x) {
			i++;
			if (i != j) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	int temp = a[low];
	a[low] = a[i];
	a[i] = temp;

	return i;
}

void QuickSort(int * a, int low, int high) {
	if (low >= high) {
		return;
	}

	stack<int> range;
	range.push(low);
	range.push(high);
	while (!range.empty()) {
		high = range.top();
		range.pop();
		low = range.top();
		range.pop();

		int w = Split(a, low, high);

		if (low < w - 1) {
			range.push(low);
			range.push(w - 1);
		}
		if (high > w + 1) {
			range.push(w + 1);
			range.push(high);
		}
	}
}

//寻找第k小的元素，但会破坏原数组的顺序
int select(int * A, int low, int high, int k) {
	int result = 0;
	/**p总数*/
	int p = high - low + 1;

	/*不构成5个一组**/
	if (p < 6) {
		QuickSort(A, low, high);
		return A[k - 1];
	}

	/*构成5个一组，进行分组**/
	int q = p / 5;
	int * M = new int[q];

	/**每组都进行升序排序
	M[i]为各组中位数
	 找出中位数数组的中位数
	 */
	for (int i = 0; i < q; i++) {
		QuickSort(A, i * 5, i * 5 + 4);
		M[i] = A[i * 5 + 2];
	}
	int mm = select(M, 0, q - 1, int(ceil(q / 2.0)));

	/**把小于、等于、大于mm的部分存储起来，分为A1,A2,A3，并用count记录每组数量*/
	int * A1 = new int[p];
	int * A2 = new int[p];
	int * A3 = new int[p];
	int count1 = 0, count2 = 0, count3 = 0;
	for (int i = low; i <= high; i++) {
		if (A[i] < mm) {
			A1[count1++] = A[i];
		}
		else if (A[i] == mm) {
			A2[count2++] = A[i];
		}
		else {
			A3[count3++] = A[i];
		}
	}

	/**比较k和A1组的个数，分三种情况进行select递归*/
	if (count1 >= k) {
		//取小于部分
		result = select(A1, 0, count1 - 1, k);
	}
	else if (count1 + count2 >= k) {
		result = mm;
	}
	else if (count1 + count2 < k) {
		//取大于部分
		result = select(A3, 0, count3 - 1, k - count1 - count2);
	}

	/**删除空间 返回值*/
	delete[] M;
	delete[] A1;
	delete[] A2;
	delete[] A3;
	return result;
}

int main(void) {
	int k, n;
	cout << "输入序列个数：";
	cin >> n;
	int a[10000];
	memset(a, 0, sizeof(a));
	/**生成随机数*/
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
	}

	cout << "序列：";
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << "输入查找的第k小的数，k=";
	cin >> k;
	cout << endl;

	int result = select(a, 0, n - 1, k);
	cout << "序列第" << k << "小元素为：" << result << endl;

	getchar();
	return 0;
}