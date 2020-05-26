#include<iostream>
#include<iomanip>
#include <algorithm>
#include <vector>
using namespace std;
class Action {
private:
	int id;
	int begin_time;
	int end_time;
public:
	Action() {}
	Action(int name, int beginTime, int endTime) {
		this->id = name;
		this->begin_time = beginTime;
		this->end_time = endTime;
	}
	int getId() {
		return id;
	}
	int getBeginTime() {
		return begin_time;
	}
	int getEndTime() {
		return end_time;
	}
	void print() {
		cout << setw(4) << id << setw(4) << begin_time << setw(4) << end_time << endl;
	}
};
bool cmp(Action a, Action b) {
	if (a.getEndTime() > b.getEndTime()) {
		return false;
	}
	else if (a.getEndTime() < b.getEndTime()) {
		return true;
	}
	else {
		if (a.getBeginTime() > b.getBeginTime()) {
			return false;
		}
		else {
			return true;
		}
	}
}
int main() {
	cout << "请输入活动总数：";
	int n;
	cin >> n;
	cout << "请输入各活动的开始、截止时间:" << endl;
	int i, j;
	int begin, end;
	vector<Action> actions(n);
	for (i = 1; i <= n; i++) {
		cout << "活动" << i << ":";
		cin >> begin >> end;
		actions[i - 1] = Action(i, begin, end);
	}

	sort(actions.begin(), actions.end(), cmp);

	vector<Action> A(n);
	A[0] = actions[0];
	j = 0;
	for (i = 1; i < n; i++) {
		if (actions[i].getBeginTime() >= A[j].getEndTime()) {
			A[++j] = actions[i];
		}
	}
	cout << "最大相容活动数为：" << j + 1 << endl;
	cout << "活动|开始|截止" << endl;

	for (i = 0; i <= j; i++) {
		A[i].print();
	}
}
