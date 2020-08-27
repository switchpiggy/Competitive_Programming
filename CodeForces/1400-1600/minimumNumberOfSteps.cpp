#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll maxn = 1000000007;
ll c, k;

int main() {
    string s;
    cin >> s;

    for(int i = s.size() - 1; i >= 0; --i) {
        if(s[i] == 'b') c++;
        else {
            k += c;
            c *= 2;
            k %= maxn;
            c %= maxn;
        }
    }

    printf("%lld", k);
}