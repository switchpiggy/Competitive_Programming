#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
char s[100007];

int main() {
    char cur = 'a';
    scanf("%s", s);

    for(ll i = 0; s[i]; ++i) {
        if(s[i] <= cur && cur <= 'z') {
            s[i] = cur;
            cur++;
            //cout << cur << endl;
        }
    }
    if(cur > 'z') cout << s << endl;
    else printf("-1\n");

    return 0;
}