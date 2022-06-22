// link: https://www.acmicpc.net/problem/2108

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <cmath>

int arr[8001] = { 0, };

using namespace std;

int main() {
	int N; cin >> N;
	vector<int> v(N);

	int avg = 0;
	int max = INT_MIN;
	int min = INT_MAX;
	int max_value = 0;
	int max_count = 0;

	for (int i = 0; i < N; i++) {
		int num; cin >> num;
		arr[num + 4000] += 1;
		v[i] = num;
		avg += num;

		if (max < num) {
			max = num;
		}
		if (min > num) {
			min = num;
		}
	}

	for (int i = 0; i < 8001; i++) {
		if (max_value < arr[i]) {
			max_value = arr[i];
			max_count = 1;
		}
		else if (max_value == arr[i]) {
			max_count += 1;
		}
	}

	sort(v.begin(), v.end());

	int avg_ans = round(avg / (float)N);
	if (avg_ans == -0) {
		avg_ans = 0;
	}

	cout << avg_ans << "\n";
	cout << v[N / 2] << "\n";

	for (int i = 0; i < 8001; i++) {
		if (max_count == 1 && max_value == arr[i]) {
			cout << i - 4000 << "\n";
			break;
		}
		else if(max_count >= 2 && max_value == arr[i]) {
			max_count = 1;
		}
	}

	cout << max - min << "\n";



	return 0;
}