#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p, q;
string s;

int main() {
    scanf("%lld %lld %lld", &n, &p, &q);
    cin >> s;

    ll a = 0, b = 0;

    while((n - (a * p))%q != 0 && a * p <= n) a++;

    if(a * p > n) {
        printf("-1\n");
        return 0;
    }

    ll i = 0;

    cout << a + (n - a * p)/q << endl;

    for(i = 0; i < a * p; i += p) {
        string t = s.substr(i, p);
        cout << t << endl;
    }

    for(i = i; i < s.length(); i += q) {
        string t = s.substr(i, q);
        cout << t << endl;
    }

    return 0;
}