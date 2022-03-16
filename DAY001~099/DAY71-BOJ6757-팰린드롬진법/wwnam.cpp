/* ����� �� Ǯ�� */
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int X;
vector<int> ans;
bool palindrome() {
	int size = ans.size();
	for (int i = 0; i < size / 2; i++) {
		if (ans[i] != ans[size - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	cin >> X;
	for (int i = 2; i * i <= X; i++) {
		ans.clear();
		int cur = X;
		while (cur) {
			ans.push_back(cur % i);
			cur /= i;
		}
		if (palindrome()) {
			cout << i << '\n';
		}
	}

	for (int i = sqrt(X); i >= 1; i--) {
		if ((X - i) % i == 0 && (X - i) / i > i) {
			cout << (X - i) / i << '\n';
		}
	}
}

/* �õ������� 79%���� ����(?) Ǯ��
   �� Ǯ�� ����� 5(101)�� 6(110)�� ��� �Ӹ�������� ���ϴ�.
   ������ 2������ ���ο� ���ؼ��� �̷� ������ �߻��ؼ�
   2������ ���� ó���ϸ� ������ ���� �� �����ϴ�.
*/

/*
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
bool checkDigitLength(int X, int d) {
	int cnt = 0;
	int cur = X;
	while (cur) {
		cur /= d;
		cnt++;
	}
	return (cnt == 2);
}
bool checkBase(int X, int b) {
	vector<int> arr(33, -1);
	int cur = X;
	int top = 0;

	while (cur) {
		arr[top++] = cur % b;
		cur /= b;
	}
	for (int i = 0; i < top / 2; i++) {
		if (arr[i] != arr[top - 1 - i]) {
			return false;
		}
	}
	return true;
}
int main(void) {
	unordered_set<int> candidate;
	int X;
	cin >> X;

	// 3�ڸ� �̻� ǥ���ؾ� �ϴ� ����
	for (int base = 2; !checkDigitLength(X, base); base++) {
		if (checkBase(X, base)) {
			cout << base << '\n';
		}
	}

	// 2�ڸ� ǥ�� ������ ����
	for (int base = 1; base * base <= X; base++) {
		if (X % base) {
			continue;
		}
		candidate.insert(base);
		candidate.insert(X / base);
	}

	vector<int> candArr(candidate.begin(), candidate.end());
	sort(candArr.begin(), candArr.end());
	int size = candArr.size();
	for (int i = 0; i < size; i++) {
		int zari = X / candArr[i];
		int base = candArr[i];
		if (zari < base) {
			cout << base - 1 << '\n';
		}
	}
}
*/