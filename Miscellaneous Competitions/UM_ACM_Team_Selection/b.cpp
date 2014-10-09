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
	string b2_input, b3_input;
	getline(cin, b2_input);
	getline(cin, b3_input);
	vector<char> b2;
	vector<char> b3;
	long long sum1 = 0, sum2 = 0;
	for (int i = 0; i < b2_input.size(); ++i)
	{
		b2.push_back(b2_input[i]);
		sum1 += ((b2_input[i] - '0') << (b2_input.size() - 1 - i)); 
	}
	for (int i = 0; i < b3_input.size(); ++i)
	{
		b3.push_back(b3_input[i]);
		sum2 += (b3_input[i] - '0') * pow(3, b3_input.size() - 1 - i);
	}

	set<long long> s;
	for (int i = 0; i < b2.size(); ++i)
	{
		long long diff = 1 << (b2_input.size() - 1 - i);
		if (b2[i] == '0') {
			s.insert(sum1 + diff);
		} else {
			s.insert(sum1 - diff);
		}
	}

	for (int i = 0; i < b3.size(); ++i)
	{
		long long diff = pow(3, b3_input.size() - 1 - i);
		long long ck1;
		long long ck2;
		if (b3[i] == '0') {
			ck1 = sum2 + diff;
			ck2 = sum2 + 2 * diff;
		} else if (b3[i] == '1') {
			ck1 = sum2 - diff;
			ck2 = sum2 + diff;
		} else if (b3[i] == '2') {
			ck1 = sum2 - 2 * diff;
			ck2 = sum2 - diff;
		}
		if (s.find(ck1) != s.end()) {
			cout << ck1 << endl;
			break;
		}
		if (s.find(ck2) != s.end()) {
			cout << ck2 << endl;
			break;
		}
	}

	return 0;
}