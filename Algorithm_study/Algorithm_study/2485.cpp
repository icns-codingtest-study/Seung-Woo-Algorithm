// link: https://www.acmicpc.net/problem/2485

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GetGcd(int a, int b) {
	int mod = a % b;
	
	if (mod == 0) {
		return b;
	}
	else {
		return GetGcd(b, mod);
	}
}

int main() {
	int N; cin >> N;

	vector<int> tree(N);
	vector<int> dist(N-1);

	for (int i = 0; i < N; i++) {
		cin >> tree[i];
	}

	sort(tree.begin(), tree.end());

	for (int i = 0; i < N - 1; i++) {
		dist[i] = tree[i + 1] - tree[i];
	}

	int gcd = dist[0];
	int ans = 0;

	for (int i = 0; i < N - 1; i++) {
		gcd = GetGcd(gcd, dist[i]);
	}

	for (int i = 0; i < N - 1; i++) {
		ans += (dist[i] / gcd) - 1;
	}

	cout << ans << "\n";

	return 0;
}