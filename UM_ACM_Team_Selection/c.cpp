#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <queue>
#include <climits>
#include <cmath>
#include <string>

using namespace std;

int main() {
	char* traversed = new char[2000000000]; // origin 1000000000 [0 1]
	for (int i = 0; i < 2000000000; ++i)
	{
		traversed[i] = 'N';
	}
	int N;
	int cur = 0;
	int move = 0;
	int r = 0;
	int origin = 1000000000;
	char dir;
	cin >> N;
	while(N != 0) {
		cin >> move >> dir;
		if (dir == 'R') {
			for (int i = 0; i < move; ++i)
			{
				if (traversed[origin + cur + i] == 'N') {
					traversed[origin + cur + i] = 'Y';
				} else if (traversed[origin + cur + i] == 'Y') {
					++r;
					traversed[origin + cur + i] = 'S';
				}
			}
			cur = cur + move;
		} else {
			for (int i = 0; i < move; ++i)
			{
				if (traversed[origin + cur - i] == 'N') {
					traversed[origin + cur - i] = 'Y';
				} else if (traversed[origin + cur - i] == 'Y') {
					++r;
					traversed[origin + cur - i] = 'S';
				}
			}
			cur = cur - move;
		}
		--N;
	}
	delete[] traversed;
	cout << r << endl;
	return 0;
}