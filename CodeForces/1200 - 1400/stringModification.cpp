#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n;
string s;

string modify(string st, ll n, ll k) {
    string s1 = st.substr(0, k - 1), s2 = st.substr(k - 1, n - k + 1);
    if(n%2 == k%2) reverse(s1.begin(), s1.end());

    return s2 + s1;
}

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);
        cin >> s;

        string minS = modify(s, n, 1), temp;
        ll mink = 1;

        for(ll k = 2; k <= n; ++k) {
            temp = modify(s, n, k);
            if(temp < minS) {
                mink = k;
                minS = temp;
            }
        }

        cout << minS << '\n' << mink << '\n';
    }

    return 0;
}