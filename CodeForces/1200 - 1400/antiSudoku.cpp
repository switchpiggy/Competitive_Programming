#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t;
vector<string> v;

int main() {
    scanf("%lld", &t);

    while(t--) {
        v.clear();
        for(ll i = 0; i < 9; ++i) {
            string temp;
            cin >> temp;
            v.push_back(temp);
        }

        for(ll i = 0; i < 9; ++i) {
            for(ll j = 0; j < 9; ++j) {
                if(v[i][j] == '2') v[i][j] = '1';
            }
        }

        for(ll i = 0; i < 9; ++i) cout << v[i] << endl;
    }

    return 0;
}