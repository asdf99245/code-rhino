// �ڵ帮��� ������ ȯ���մϴ�.
// ��Ʈ��ŷ ����
// ���� : ���ڿ� -> ���� ��ȯ �������� C++ �����е��� stoi�� stoll�� �̿��Ͻó���?
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int k;
vector<char> inequal;
bool check[10] = { false, };
string str = "", minStr, maxStr;
long long maxVal = 0, minVal = 1e10;
void permutation()
{
	if (str.length() == k + 1)
	{
		long long val = stoll(str);

		if (val < minVal)
			minVal = val, minStr = str;
		if (val > maxVal)
			maxVal = val, maxStr = str;
		return;
	}
	for (int i = 0; i <= 9; i++)
	{
		if (check[i])
			continue;

		int len = str.length();
		if (len >= 1)
		{
			if (inequal[len - 1] == '<' && str[len - 1] > i + '0')
				continue;
			else if (inequal[len - 1] == '>' && str[len - 1] < i + '0')
				continue;
		}

		str += (i + '0');
		check[i] = true;
		permutation();
		check[i] = false;
		str = str.substr(0, str.length() - 1);
	}
}
int main(void)
{
	cin >> k;
	inequal.resize(k);
	for (int i = 0; i < k; i++)
		cin >> inequal[i];

	permutation();
	cout << maxStr << '\n' << minStr;
}