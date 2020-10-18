#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a, b;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> a >> b;

    string t = "";
    char last = '.';
    ll streak = 0;
    while(a && b) {
        if(streak == k) {
            if(last == 'G') {
                if(!b) {
                    cout << "NO\n";
                    return 0;
                } else {
                    t += 'B';
                    b--;
                    last = 'B';
                    streak = 1;
                }
            } else {
                if(!a) {
                    cout << "NO\n";
                    return 0;
                } else {
                    t += 'G';
                    a--;
                    last = 'G';
                    streak = 1;
                }
            }
        }
        if(a >= b) {
            t += 'G';
            a--;
            if(last == 'G') streak++;
            else streak = 1;
            last = 'G';
        } else {
            t += 'B';
            b--;
            if(last == 'B') streak++;
            else streak = 1;
            last = 'B';
        }
    }

    if(a + (t.back() == 'G') > k || b + (t.back() == 'B') > k) {
        cout << "NO\n";
        return 0;
    }

    if(a) t += string(a, 'G');
    else if(b) t += string(b, 'B');

    cout << t << '\n';
    return 0;
}