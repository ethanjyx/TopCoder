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
	int N, M;
	cin >> N >> M;
	vector<int> T(N, 0);
	int a, b, t;
	while(M != 0) {
		cin >> a >> b >> t;
		T[a-1] = std::max(T[a-1], t);
		T[b-1] = std::max(T[b-1], t);
		--M;
	} 
	cout << *min_element(T.begin(), T.end()) << endl;
	return 0;
}