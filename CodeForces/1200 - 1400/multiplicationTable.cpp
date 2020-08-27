#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll k;

string convertRadix(ll x) {
    string temp = "";
    while(x >= k) {
        ll cur = x%k;
        x /= k;
        temp += to_string(cur);
    }

    if(x) temp += to_string(x);
    reverse(temp.begin(), temp.end());

    return temp;
}

int main() {
    scanf("%lld", &k);

    for(ll i = 1; i < k; ++i) {
        for(ll j = 1; j < k; ++j) {
            cout << convertRadix(i * j) << ' ';
        }
        printf("\n");
    }
}