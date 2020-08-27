#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

string s;
char k;
ll maxn;
bool f[1007];
map<char, ll> cnt;

void no() {
    printf("NO\n");
    exit(0);
}

int main() {
    cin >> s;
    ll n = s.length();
    for(ll i = 0; i < s.length(); ++i) {
        cnt[s[i]]++;
    }
    for(auto itr = cnt.begin(); itr != cnt.end(); ++itr) {
        if(itr->second >= maxn) {
            k = itr->first;
            maxn = itr->second;
        }
    }

    memset(f, 1, sizeof(f));

    for(ll i = 2; i * i <= n; ++i) {
        if(f[i]) {
            for(ll j = i * i; j <= n; j += i) f[j] = false;
        }
    }

    f[1] = true;
    for(ll i = 2; i + i <= n; ++i) f[i] = false;

    for(ll i = 1; i <= n; ++i) {
        if(f[i]) continue;
        if(!cnt[k]) no();
        s[i - 1] = k;
        cnt[k]--;
    }

    auto itr = cnt.begin();
    for(ll i = 1; i <= n; ++i) {
        if(!f[i]) continue;
        while(itr->second == 0) itr++;
        s[i - 1] = itr->first;
        cnt[itr->first]--;
    }

    printf("YES\n");
    cout << s << endl;

    return 0;
}