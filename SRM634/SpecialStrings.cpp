// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// 
A string S is called special if it satisfies the following two properties:

Each character in S is either '0' or '1'.
Whenever S = UV where both U and V are nonempty strings, U is strictly smaller than V in lexicographic order.




For example, the string S = "00101" is special because we have "0" < "0101", "00" < "101", "001" < "01", and "0010" < "1".



You are given a string current that is guaranteed to be special.
Let N be the length of current.
Consider the lexicographically sorted list of all special strings of length N.
Compute and return the string that comes immediatelly after current in this list.
If current happens to be the last string in the list, return an empty string instead.


DEFINITION
Class:SpecialStrings
Method:findNext
Parameters:string
Returns:string
Method signature:string findNext(string current)


NOTES
-Given two different strings U and V, the string U precedes the string V in lexicographic order if one of two conditions is satisfied: Either U is a proper prefix of V, or there is an integer x such that U and V have the same first x characters, and the x+1th character in U is smaller than the x+1th character in V.


CONSTRAINTS
-current will contain between 1 and 50 characters, inclusive.
-current will be a special string.


EXAMPLES

0)
"01"

Returns: ""

"01" is the only special string of length 2.

1)
"00101"

Returns: "00111"

The special strings of length 5 are "00001", "00011", "00101", "00111", "01011", "01111".

2)
"0010111"

Returns: "0011011"



3)
"000010001001011"

Returns: "000010001001101"



4)
"01101111011110111"

Returns: "01101111011111111"



*/
// END CUT HERE
#include <string>
#include <iostream>
#include <climits>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
#include <numeric>
#include <deque>
using namespace std;
class SpecialStrings {
	public:
	string findNext(string current) {
		while(true) {
			if(isend(current)) {
				return "";
			}
			increment(current);
			if(isSpecial(current))
				break;
		}
		return current;
	}

	bool isend(string& current) {
		if(current[0] != '0')
			return true;
		for (int i = 1; i < current.length(); ++i)
		{
			if (current[i] == '0')
			{
				return false;
			}
		}
		return false;
	}

	void increment(string& current) {
		int carry = 0;
		for (int i = current.length() - 1; i >= 0 ; i--)
		{
			if (current[i] == '1')
			{
				current[i] = '0';
				carry = 1;
			} else {
				current[i] = '1';
				carry = 0;
			}
			if (carry == 0)
			{
				break;
			}
		}
	}

	bool isSpecial(string& current) {
		int min = INT_MAX, cur = 0;
		for (int i = 0; i < current.size(); ++i)
		{
			if (current[i] == '0')
			{
				i++;
			} else {
				if (cur > min)
				{
					return false;
				}
				min = cur;
				cur = 0;
			}
		}
		for (int i = 0; i < current.size() - 1; ++i)
		{
			if (current.substr(0, i+1) >= current.substr(i+1, current.size()-i-1))
			{
				return false;
			}
		}
		return true;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "01"; string Arg1 = ""; verify_case(0, Arg1, findNext(Arg0)); }
	void test_case_1() { string Arg0 = "00101"; string Arg1 = "00111"; verify_case(1, Arg1, findNext(Arg0)); }
	void test_case_2() { string Arg0 = "0010111"; string Arg1 = "0011011"; verify_case(2, Arg1, findNext(Arg0)); }
	void test_case_3() { string Arg0 = "000010001001011"; string Arg1 = "000010001001101"; verify_case(3, Arg1, findNext(Arg0)); }
	void test_case_4() { string Arg0 = "01101111011110111"; string Arg1 = "01101111011111111"; verify_case(4, Arg1, findNext(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	SpecialStrings ___test;
	___test.run_test(-1);
 	// getch() ;
 	return 0;
}
// END CUT HERE
