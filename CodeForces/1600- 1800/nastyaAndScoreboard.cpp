#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
vector<string> v;
ll n, k, dp[2007][2007], d[2007][2007];
string digits[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v.push_back(s);
        for(ll j = 0; j < 10; ++j) {
            ll cur = 0;
            for(ll l = 0; l < 7; ++l) {
                if(s[l] == '1' && digits[j][l] == '0') {
                    d[i][j] = -1;
                    break;
                }

                if(s[l] != digits[j][l]) cur++;
            }

            if(d[i][j] != -1) d[i][j] = cur;
        }
    }

    dp[n][0] = 1;
    for(ll i = n; i > 0; --i) {
        for(ll j = 0; j <= k; ++j) {
            if(dp[i][j]) {
                for(ll l = 0; l < 10; ++l) {
                    if(j + d[i - 1][l] <= k && d[i - 1][l] != -1) dp[i - 1][j + d[i - 1][l]] = 1;
                }
            }
        }
    }

    if(!dp[0][k]) {
        cout << "-1\n";
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 9; j >= 0; --j) {
            if(d[i][j] != -1 && k >= d[i][j] && dp[i + 1][k - d[i][j]]) {
                cout << j;
                k -= d[i][j];
                break;
            }
        }
    }

    cout << '\n';
    return 0;
}