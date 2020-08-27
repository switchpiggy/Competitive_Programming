#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll t, n;

int main() {
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &n);

        ll ans = 0;
        vector<bool> visited(n);
        vector<string> a(n);
        set<string> have;

        for(string &pin : a) {
            cin >> pin;
            have.insert(pin);
        }
        for(int i = 0; i < n; ++i) {
            if(visited[i]) {
                continue;
            }

            vector<int> sameId;

            for(int j = i + 1; j < n; ++j) {
                if(a[i] == a[j]) {
                    sameId.push_back(j);
                    visited[j] = 1;
                    ans++;

                    for(int k = 0; k < 4 && a[i] == a[j]; ++k) {
                        for(int c = '0'; c <= '9'; ++c) {
                            string t = a[j];
                            t[k] = c;

                            if(!have.count(t)) {
                                have.insert(t);
                                a[j] = t;
                                break;
                            }
                        }
                    }
                }
            }
        }

        printf("%lld\n", ans);
        for(string &s : a) {
            cout << s << endl;
        }
    }
}