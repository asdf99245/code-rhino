// �ڵ帮��� ������ ȯ���մϴ�.
// 10844 - ���� ��ܼ� ������ 0~9 üũ�� ���ԵǴ� �����Դϴ�.
// 0~9 üũ�� ��Ʈ����ŷ���� �����ϸ� �ذ� �����մϴ�.
// 0���� �۰ų�, 9���� ū ���� �� �� ���� ������ �׿� ���� ��츸 ���������� ó���ϸ� �˴ϴ�.
// 0123456789
// 0000000000
#include <iostream>
#include <vector>
using namespace std;
long long dp[101][10][1024] = { 0, }, ans = 0, MOD = 1e9;
int main(void)
{
	int N, all = 1023;
	cin >> N;

	for (int i = 1; i < 10; i++)
		dp[1][i][1 << i] = 1;

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k <= all; k++)
			{
				if (j == 0)
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j + 1][k]) % MOD;
				else if (j == 9)
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k]) % MOD;
				else
				{
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j + 1][k]) % MOD;
					dp[i][j][k | 1 << j] = (dp[i][j][k | 1 << j] + dp[i - 1][j - 1][k]) % MOD;
				}
			}
		}
	}

	for (int i = 0; i < 10; i++)
		ans = (ans + dp[N][i][all]) % MOD;
	cout << ans;
}