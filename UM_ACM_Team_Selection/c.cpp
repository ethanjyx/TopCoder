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

struct Interval {
	int start;
	int end;
};

struct comp {
	bool operator() (Interval i1, Interval i2) {
		if (i1.start == i2.start) {
			return i1.end > i2.end;
		}
		return i1.start < i2.start;
	}
} mycomp;

int main() {
	int N;
	cin >> N;
	int cur = 0;
	int move;
	char dir;
	vector<Interval> ivs;
	while(N != 0) {
		cin >> move >> dir;
		if (dir == 'L') {
			ivs.push_back(Interval{cur-move, cur});
			cur -= move;
		} else {
			ivs.push_back(Interval{cur, cur+move});
			cur += move;
		}
		--N;
	}
	sort(ivs.begin(), ivs.end(), mycomp);

	int r = 0;
	auto itr = ivs.begin();
	int s = itr->start, e = itr->end;
	++itr;
	for(; itr != ivs.end(); ++itr) {
		if (itr->start > e) {
			s = itr->start;
			e = itr->end;
		} else if(itr->start >= s){
			if (itr->end <= e) {
				r += itr->end - itr->start;
				s = itr->end;
			} else {
				r += e - itr->start;
				s = e;
				e = itr->end;
			}
		} else {
			if (itr->end < s) {
				continue;
			} else if (itr->end <= e) {
				r += itr->end - s;
				s = itr->end;
			} else {
				r += e - s;
				s = e;
				e = itr->end;
			}
		}
	}
	cout << r << endl;
	return 0;
}