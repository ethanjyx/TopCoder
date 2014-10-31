#include <iostream>
#include <set>
#include <vector>

using namespace std;

struct Prize {
    vector<int> required;
    int cash;
};

main() {
    int N;
    cin >> N;
    for(;N>0;--N) {
        int n, m;
        cin >> n >> m;
        vector<Prize> prizes;
        for(;n>0;--n) {
            Prize pr;
            int p;
            cin >> p;
            for(;p>0;--p) {
                int type;
                cin >> type;
                pr.required.push_back(type);
            }
            cin >> pr.cash;
            prizes.push_back(pr);
        }
        vector<int> stickers(m+1, 0);
        for(int i = 1; i <= m; ++i) {
            cin >> stickers[i];
        }

        int total = 0;
        for(auto & pr : prizes) {
            int num = 1000000;
            for(auto type : pr.required) {
                if(stickers[type] < num)
                    num = stickers[type];
            }
            total += num * pr.cash;
        }
        cout << total << endl;
    }
}
