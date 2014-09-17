// BEGIN CUT HERE
/*
// PROBLEM STATEMENT
// Here at [topcoder], we call a contestant a "target" if their rating is 3000 or more.
In the arena, the targets have a red icon with a small target on it.
Do you want to become a target as well?
Sure you do.
But before you get there, let's start with something easier: drawing a target.



The target you need to draw consists of nested squares.
The innermost square is just a single '#' character.
The larger squares use alternatingly the character ' ' (space) and the character '#'.
Here is an example in which the side of the largest square is n = 5:




#####
#   #
# # #
#   #
#####



And here is an example for n = 9:



#########
#       #
# ##### #
# #   # #
# # # # #
# #   # #
# ##### #
#       #
#########




You will be given an int n.
Your method must return a vector <string> which contains a drawing of the target with side n.
More precisely, each element of the returned vector <string> must be one row of the drawing, in order.
Therefore, the returned vector <string> will consist of n elements, each with n characters.
(See the examples below for clarification.)



The value of n will be such that a target like the ones above can be drawn: 5, 9, 13, and so on.
Formally, n will be of the form 4k+1, where k is a positive integer.

DEFINITION
Class:Target
Method:draw
Parameters:int
Returns:vector <string>
Method signature:vector <string> draw(int n)


CONSTRAINTS
-n will be between 5 and 49, inclusive.
-n mod 4 will be 1.


EXAMPLES

0)
5

Returns: {"#####", "#   #", "# # #", "#   #", "#####" }



1)
9

Returns: {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" }



2)
13

Returns: {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" }



3)
17

Returns: {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" }



*/
// END CUT HERE
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
class Target {
	public:
	vector <string> draw(int n) {
        string f(n, '#');
        string e(n, ' ');
        vector<string> result(n);
        for (int i = 0; i <= n / 2; i++) {
            if (i % 2 == 0) {
                string tmp = f;
                for (int j = 1; j < i; j += 2) {
                    tmp[j] = tmp[n-1-j] = ' ';
                }
                result[i] = result[n-i-1] = tmp;
            } else {
                string tmp = e;
                for (int j = 0; j < i; j += 2) {
                    tmp[j] = tmp[n-1-j] = '#';
                }
                result[i] = result[n-i-1] = tmp;
            }
        }
        return result;
	}
	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 5; string Arr1[] = {"#####", "#   #", "# # #", "#   #", "#####" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, draw(Arg0)); }
	void test_case_1() { int Arg0 = 9; string Arr1[] = {"#########", "#       #", "# ##### #", "# #   # #", "# # # # #", "# #   # #", "# ##### #", "#       #", "#########" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, draw(Arg0)); }
	void test_case_2() { int Arg0 = 13; string Arr1[] = {"#############", "#           #", "# ######### #", "# #       # #", "# # ##### # #", "# # #   # # #", "# # # # # # #", "# # #   # # #", "# # ##### # #", "# #       # #", "# ######### #", "#           #", "#############" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, draw(Arg0)); }
	void test_case_3() { int Arg0 = 17; string Arr1[] = {"#################", "#               #", "# ############# #", "# #           # #", "# # ######### # #", "# # #       # # #", "# # # ##### # # #", "# # # #   # # # #", "# # # # # # # # #", "# # # #   # # # #", "# # # ##### # # #", "# # #       # # #", "# # ######### # #", "# #           # #", "# ############# #", "#               #", "#################" }; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, draw(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main(){
	Target ___test;
	___test.run_test(-1);
 	// getch() ;
 	return 0;
}
// END CUT HERE
