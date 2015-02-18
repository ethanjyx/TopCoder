// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// You had a non-empty string s but you lost it.
Cat Snuke found the string and removed one character from the string.
Later, Snuke gave you the string t.
Can this be the string created from your string s?

You are given the strings s and t.
Return "Possible" (quotes for clarity) if t can be obtained from s by erasing exactly one character.
Otherwise, return "Impossible".
Note that the return value is case-sensitive.

DEFINITION
Class:DecipherabilityEasy
Method:check
Parameters:string, string
Returns:string
Method signature:string check(string s, string t)


CONSTRAINTS
-The number of characters in s will be between 1 and 50, inclusive.
-Every character in s will be a lowercase letter ('a'-'z').
-The number of characters in t will be between 1 and 50, inclusive.
-Every character in t will be a lowercase letter ('a'-'z').


EXAMPLES

0)
"sunuke"
"snuke"

Returns: "Possible"

If Cat Snuke erase the first 'u' from s, it will equal to t.

1)
"snuke"
"skue"

Returns: "Impossible"

Swapping characters is not allowed.

2)
"snuke"
"snuke"

Returns: "Impossible"

Erasing nothing is not allowed.

3)
"snukent"
"snuke"

Returns: "Impossible"

Cat Snuke can erase exactly one character.

4)
"aaaaa"
"aaaa"

Returns: "Possible"



5)
"aaaaa"
"aaa"

Returns: "Impossible"



6)
"topcoder"
"tpcoder"

Returns: "Possible"



7)
"singleroundmatch"
"singeroundmatc"

Returns: "Impossible"



*/
// END CUT HERE
#include <string>
#include <map>
#include <climits>
#include <queue>
#include <stack>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <numeric>
#include <deque>
using namespace std;
class DecipherabilityEasy {
	public:
	string check(string s, string t) {
		int i = 0, j = 0;
		while(i <= s.length() && j <= t.length()) {
			if(i >= j + 2)
				return "Impossible";
			if(s[i] == t[j]) {
				i++;
				j++;
			} else {
				i++;
			}
		}
		if(i == j + 1)
			return "Possible";
		return "Impossible";
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "sunuke"; string Arg1 = "snuke"; string Arg2 = "Possible"; verify_case(0, Arg2, check(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "snuke"; string Arg1 = "skue"; string Arg2 = "Impossible"; verify_case(1, Arg2, check(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "snuke"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(2, Arg2, check(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "snukent"; string Arg1 = "snuke"; string Arg2 = "Impossible"; verify_case(3, Arg2, check(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "aaaaa"; string Arg1 = "aaaa"; string Arg2 = "Possible"; verify_case(4, Arg2, check(Arg0, Arg1)); }
	void test_case_5() { string Arg0 = "aaaaa"; string Arg1 = "aaa"; string Arg2 = "Impossible"; verify_case(5, Arg2, check(Arg0, Arg1)); }
	void test_case_6() { string Arg0 = "topcoder"; string Arg1 = "tpcoder"; string Arg2 = "Possible"; verify_case(6, Arg2, check(Arg0, Arg1)); }
	void test_case_7() { string Arg0 = "singleroundmatch"; string Arg1 = "singeroundmatc"; string Arg2 = "Impossible"; verify_case(7, Arg2, check(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	DecipherabilityEasy ___test;
	___test.run_test(-1);
 	return 0;
}
// END CUT HERE
