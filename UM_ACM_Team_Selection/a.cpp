#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <climits>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> cows;
	int ones = 0, twos = 0;
	while(N != 0) {
		int D;
		cin >> D;
		cows.push_back(D);
		if (D == 1) {
			ones++;
		} else {
			twos++;
		}
		N--;
	}
	int min = std::min(ones, twos);
	int ones_before = 0, twos_before = 0;
	for (int i = 0; i < cows.size(); ++i)
	{
		if (cows[i] == 1) {
			ones_before++;
			ones--;
		} else {
			twos_before++;
			twos--;
		}
		int move = twos_before + ones;
		if (move < min) {
			min = move;
		}
	}
	cout << min << endl;
	return 0;
}