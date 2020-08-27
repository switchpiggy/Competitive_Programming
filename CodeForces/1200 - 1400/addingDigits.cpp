#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, n;

void no() {
    printf("-1\n");
    exit(0);
}

int main() {
    scanf("%lld %lld %lld", &a, &b, &n);
    string s = to_string(a);
    a %= b;

    for(ll i = 0; i < n; ++i) {
        bool flag = false;
        //cout << a << endl;

        for(ll j = 0; j <= 9; ++j) {
            if((10 * a + j)%b == 0) {
                flag = 1;
                a = 10 * a + j;
                a %= b;
                s += '0' + j;
                break;
            }
        }

        if(!flag) no();
    }

    cout << s << endl;
    return 0;
}