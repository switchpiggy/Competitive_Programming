#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
char s[1007];
bool h, v;

int main() {
    scanf("%s", s);

    for(ll i = 0; s[i]; ++i) {
        if(s[i] == '0') {
            if(v) {
                printf("1 1\n");
                v = 0;
            } else {
                printf("3 1\n");
                v = 1;
            }
        } else {
            if(h) {
                printf("1 1\n");
                h = 0;
            } else {
                printf("1 3\n");
                h = 1;
            }
        }
    }

    return 0;
}