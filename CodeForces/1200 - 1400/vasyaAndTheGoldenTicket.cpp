#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;
string s;

int main() {
    scanf("%lld", &n);
    cin >> s;

    ll sum = 0;

    for(ll i = 0; i < n; ++i) {
        sum += s[i] - '0';

        bool flag = false;
        ll pos = i + 1;
        ll sum2=  0;

        while(pos < n) {
            sum2 = s[pos++] - '0';

            while(pos < n && sum2 + s[pos] - '0' <= sum) {
                sum2 += s[pos] - '0';
                ++pos;
            }

            if(sum2 != sum) flag = true;
        }

        if(sum2 != sum) flag = true;

        if(!flag) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");
    return 0;
}