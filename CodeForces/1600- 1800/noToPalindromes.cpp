#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, p;
string s;
//all palindromes contain a subpalindrome of length 2 or 3.
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> p >> s;
    for(ll i = n - 1; i >= 0; --i) {
        for(char a = s[i] + 1; a <= p + 'a' - 1; ++a) {
            if((i == 0 || a != s[i - 1]) && (i <= 1 || a != s[i - 2])) {
                s[i] = a;
                for(ll j = i + 1; j < n; ++j) {
                    for(char a = 'a'; a <= 'z'; ++a) {
                        if(a != s[j - 1] && (j <= 1 || a != s[j - 2])) {
                            s[j] = a;
                            break;
                        }
                    }
                }

                cout << s << '\n';
                return 0;
            }
        }
    }

    cout << "NO\n";
    return 0;
}