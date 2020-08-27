#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, fsum, ssum, temp, last;
vector<ll> f, s;

void first() {
    printf("first");
    exit(0);
}

void second() {
    printf("second");
    exit(0);
}

int main() {
    scanf("%lld", &n);

    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        if(temp < 0) {
            last = 2;
            ssum += abs(temp);
            s.push_back(abs(temp));
        } else {
            last = 1;
            fsum += temp;
            f.push_back(temp);
        }
    }

    if(fsum > ssum) first();
    else if(ssum > fsum) second();
    else {
        for(ll i = 0; i < min(f.size(), s.size()); ++i) {
            if(f[i] > s[i]) first();
            else if(s[i] > f[i]) second();
        }

        if(f.size() > s.size()) first();
        else if(s.size() > f.size()) second();
        else {
            if(last == 1) first();
            else second();
        }
    }

    return 0;
}