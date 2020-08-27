#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, res;
vector<string> v;
string s;

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    scanf("%lld %lld", &n, &m);

    for(ll i = 0; i < 2 * n; ++i) {
        cin >> s;
        v.push_back(s);
    }   

    for(ll a = 0; a < m; ++a) {
        for(ll b = a + 1; b < m; ++b) {
            for(ll c = b + 1; c < m; ++c) {
                set<string> st;
                bool flag = false;
                for(ll i = 0; i < n; ++i) {
                    string temp;
                    temp.push_back(v[i][a]);
                    temp.push_back(v[i][b]);
                    temp.push_back(v[i][c]);
                    st.insert(temp);
                }
                for(ll i = n; i < 2 * n; ++i) {
                    string temp;
                    temp.push_back(v[i][a]);
                    temp.push_back(v[i][b]);
                    temp.push_back(v[i][c]);
                    if(st.count(temp)) {
                        flag = 1;
                        break;
                    }
                }

                if(!flag) res++;
            }
        }
    }

    printf("%lld\n", res);
    return 0;
}