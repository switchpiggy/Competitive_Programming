#include <bits/stdc++.h>

using namespace std;

int main() {

    long long int t, n, k;

    scanf("%lld", &t);

    while(t--) {

        string s;

        scanf("%lld %lld", &n, &k);

        cin >> s;

        long long int cnt = 0;

        bool flag = false;

        string res = "";

        for(int i = 0; i < n; ++i) {

            if(s[i] == '0') {

                if(cnt <= k) {

                    res += '0';

                    k -= cnt;

                } else {

                    res += string(cnt - k, '1');

                    res += '0';

                    res += string(k, '1');

                    res += s.substr(i + 1);

                    flag = true;

                    cout << res << endl;

                    break;

                }

            } else cnt++;

        }

        if(!flag) {

            res += string(cnt, '1');

            cout << res << endl;

        }

    }

}