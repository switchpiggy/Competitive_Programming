#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define benqueue queue
#define pbenqueue priority_queue
ll n;
set<ll> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    //ll x = n;
    s.insert(n);
    while(n > 1) {
        n++;
        while(n%10 == 0) n /= 10;
        s.insert(n);
    }

    for(ll i = 2; i < 10; ++i) {
        if(!s.count(i)) s.insert(i);
    }

    cout << (ll)s.size() << '\n';
}