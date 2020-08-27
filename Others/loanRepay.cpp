#include <bits/stdc++.h>

using namespace std;

int main() {

    int n, k, m, res = INT_MIN;

    ifstream fin;

    ofstream fout;

    fin.open("loan.in");

    fout.open("loan.out");

    fin >> n >> k >> m;

    for(int i = 1; i <= n; ++i) {

        int g = 0;

        int sum = 0;

        int a = 0;

        while(1) {

            a++;

            sum += max((n - g)/i, m);

            g += max((n - g)/i, m);

            if(sum >= n || a == k) break;

        }

        if(sum >= n) res = max(res, i);
        
        else break;

    }
    
    fout << res;

    fin.close();

    fout.close();

}