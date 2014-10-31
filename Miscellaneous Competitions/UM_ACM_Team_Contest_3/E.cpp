#include <iostream>
#include <cmath>

using namespace std;

double myRound(double v) {
    return round(v * 100)/ 100.0; 
}

main() {
    int N;
    cin >> N;
    for(;N>0;--N) {
        double rate, balance, payment;
        cin >> rate >> balance >> payment;
        rate = rate / 100;
        int i = 1;
        for(; i <= 1200; ++i) {
            double interest = myRound(balance * rate);
            if(interest > payment) {
                i = 1201;
                break;
            }
            balance = balance + interest - payment;
            if(balance <= 0) {
                cout << i << endl;
                break;
            }
        }
        if(i == 1201)
            cout << "impossible" << endl;
    }
}
