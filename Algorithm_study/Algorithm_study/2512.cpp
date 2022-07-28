// link: https://www.acmicpc.net/problem/2512

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N; 
	int M;
	cin >> N;

	vector<int> v(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	cin >> M;

	sort(v.begin(), v.end());

	int start = 0;
	int end = v[N - 1];
	int ans = 0;

	while (start <= end) {
		int sum = 0;
		int mid = (start + end) / 2; 
		
		for (auto i = 0; i < N; i++) {
			sum += min(mid, v[i]);
		}

		if (M >= sum) {
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}