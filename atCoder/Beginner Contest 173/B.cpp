#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;
ll ac, tle, wa, re;

int main() {
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        cin >> s;
        if(s == "AC") ac++;
        else if(s == "TLE") tle++;
        else if(s == "WA") wa++;
        else re++;
    }

    printf("AC x %lld\nWA x %lld\nTLE x %lld\nRE x %lld\n", ac, wa, tle, re);
    return 0;
}