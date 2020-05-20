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

//Ѱ�ҵ�kС��Ԫ�أ������ƻ�ԭ�����˳��
int select(int * A, int low, int high, int k) {
	int result = 0;
	/**p����*/
	int p = high - low + 1;

	/*������5��һ��**/
	if (p < 6) {
		QuickSort(A, low, high);
		return A[k - 1];
	}

	/*����5��һ�飬���з���**/
	int q = p / 5;
	int * M = new int[q];

	/**ÿ�鶼������������
	M[i]Ϊ������λ��
	 �ҳ���λ���������λ��
	 */
	for (int i = 0; i < q; i++) {
		QuickSort(A, i * 5, i * 5 + 4);
		M[i] = A[i * 5 + 2];
	}
	int mm = select(M, 0, q - 1, int(ceil(q / 2.0)));

	/**��С�ڡ����ڡ�����mm�Ĳ��ִ洢��������ΪA1,A2,A3������count��¼ÿ������*/
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

	/**�Ƚ�k��A1��ĸ������������������select�ݹ�*/
	if (count1 >= k) {
		//ȡС�ڲ���
		result = select(A1, 0, count1 - 1, k);
	}
	else if (count1 + count2 >= k) {
		result = mm;
	}
	else if (count1 + count2 < k) {
		//ȡ���ڲ���
		result = select(A3, 0, count3 - 1, k - count1 - count2);
	}

	/**ɾ���ռ� ����ֵ*/
	delete[] M;
	delete[] A1;
	delete[] A2;
	delete[] A3;
	return result;
}

int main(void) {
	int k, n;
	cout << "�������и�����";
	cin >> n;
	int a[10000];
	memset(a, 0, sizeof(a));
	/**���������*/
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 1000;
	}

	cout << "���У�";
	for (int i = 0; i < n; i++) {
		cout << a[i] << "  ";
	}
	cout << "������ҵĵ�kС������k=";
	cin >> k;
	cout << endl;

	int result = select(a, 0, n - 1, k);
	cout << "���е�" << k << "СԪ��Ϊ��" << result << endl;

	getchar();
	return 0;
}