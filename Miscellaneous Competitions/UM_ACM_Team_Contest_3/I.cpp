#include <iostream>
#include <vector>
#include <utility>
#include <set>

using namespace std;

void solve(vector<vector<int> > &v);

void collectSet(vector<vector<int> > &v, set<pair<int,int> > &s, int num);

void explore(vector<vector<int> > &v, pair<int,int> p, set<pair<int,int> > &s, int num);

int main()
{
    int N;
    cin >> N;
    while(N > 0) {
        int n;
        cin >> n;
        vector<vector<int> > v(n, vector<int>(n));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                char tmp;
                cin >> tmp;
                v[i][j] = tmp - '0';
            }
        }
        
        solve(v);       

        --N;
    }
}

void solve(vector<vector<int> > &v)
{
    set<pair<int,int> > s;
    s.insert(make_pair(0,0));
    collectSet(v, s, v[0][0]);
    vector<int> count(6, 0);
    int numMoves = 0;
    while(s.size() != v.size() * v.size()) {
        vector<set<pair<int,int> > > connected(6, s);
        for(int i = 0; i < 6; ++i) {
            collectSet(v, connected[i], i+1);
        }
        int maxIndex = 0;
        int maxSize = connected[0].size();
        for(int i = 1; i < 6; ++i) {
            if(connected[i].size() > maxSize) {
                maxIndex = i;
                maxSize = connected[i].size();
            }
        }
        ++count[maxIndex];
        ++numMoves;
        s = connected[maxIndex];
    }

    cout << numMoves << endl;
    for(int i = 0; i < 5; ++i)
        cout << count[i] << ' ';
    cout << count[5] << endl;
}

void collectSet(vector<vector<int> > &v, set<pair<int,int> > &s, int num)
{
    for(auto & p : s) {
        explore(v, make_pair(p.first+1, p.second), s, num);
        explore(v, make_pair(p.first, p.second+1), s, num);
        explore(v, make_pair(p.first-1, p.second), s, num);
        explore(v, make_pair(p.first, p.second-1), s, num);
    }
}

void explore(vector<vector<int> > &v, pair<int,int> p, set<pair<int,int> > &s, int num)
{
    if(p.first < 0 || p.second < 0 || p.first >= v.size() || p.second >= v.size())
        return;

    if(s.find(p) != s.end())
        return;

    if(v[p.first][p.second] == num) {
        s.insert(p);
        explore(v, make_pair(p.first+1, p.second),s, num);
        explore(v, make_pair(p.first, p.second+1), s, num);
        explore(v, make_pair(p.first-1, p.second), s, num);
        explore(v, make_pair(p.first, p.second-1), s, num);
    }
}
