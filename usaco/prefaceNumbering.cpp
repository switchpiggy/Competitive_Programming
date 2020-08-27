/*
ID: alanxia1
LANG: C++
PROG: preface
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

static char *encode[] = {
    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"
};

char *romanDigit(char *charset, ll x) {
    static char str[10];
    char *s, *p;

    for(s = encode[(int)x%10], p = str; *s; s++, p++) {
        switch(*s) {
            case 'I': 
                *p = charset[0];
                break;
            case 'V':
                *p = charset[1];
                break;
            case 'X':
                *p = charset[2];
                break;
        }
    }

    *p = '\0';

    return str;
}

char *roman(ll n) {
    static char buffer[20];

    strcpy(buffer, "");
    strcat(buffer, romanDigit("M", n/1000));
    strcat(buffer, romanDigit("CDM", n/100));
    strcat(buffer, romanDigit("XLC", n/10));
    strcat(buffer, romanDigit("IVX", n));

    return buffer;
}

ll c[256];

int main() {
    freopen("preface.in", "r", stdin);
    freopen("preface.out", "w", stdout);

    char *s;
    ll n;

    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i) {
        for(s = roman(i); *s; s++) {
            c[*s]++;
        }
    }

    for(s = "IVXLCDM"; *s; s++) {
        if(c[*s]) printf("%c %lld\n", *s, c[*s]);
    }
}