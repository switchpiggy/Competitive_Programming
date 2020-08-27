#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q;
map<ll, ll> a;
char c;
ll temp;

int main() {
    ll two = 0, four = 0, six = 0, eight = 0;
    scanf("%lld", &n);
    for(ll i = 0; i < n; ++i) {
        scanf("%lld", &temp);
        a[temp]++;
        if(a[temp] == 2) two++;
        else if(a[temp] == 4) {
            two--;
            four++;
        } else if(a[temp] == 6) {
            four--;
            six++;
        } else if(a[temp] == 8) {
            six--;
            eight++;
        }
    }
   
    scanf("%lld", &q);
    for(ll d = 0; d < q; ++d) {
        cin >> c >> temp;
        if(c == '+') {
            a[temp]++;
            if(a[temp] == 2) two++;
            else if(a[temp] == 4) {
                two--;
                four++;
            } else if(a[temp] == 6) {
                four--;
                six++;
            } else if(a[temp] == 8) {
                six--;
                eight++;
            }
        } else {
            a[temp]--;
            if(a[temp] == 1) {
                two--;
            } else if(a[temp] == 3) {
                four--;
                two++;
            } else if(a[temp] == 5) {
                six--;
                four++;
            } else if(a[temp] == 7) {
                eight--;
                six++;
            }
        }

        if((two >= 2 && four > 0) || (four >= 2) || (six > 0 && (two > 0 || four > 0 || six > 1)) || (eight > 0)) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}