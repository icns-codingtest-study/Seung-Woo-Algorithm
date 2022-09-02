// link: https://www.acmicpc.net/problem/1890

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<vector<int>> v(N, vector<int>(N, 0));
	vector<vector<long>> dp(N, vector<long>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	dp[0][0] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1) {
				break;
			}

			if (dp[i][j] != 0) {
				int nx = i + v[i][j];
				int ny = j + v[i][j];

				if (nx < N) {
					dp[nx][j] += dp[i][j];
				}

				if (ny < N) {
					dp[i][ny] += dp[i][j];
				}
			}
		}
	}

	cout << dp[N - 1][N - 1] << "\n";

	return 0;
}