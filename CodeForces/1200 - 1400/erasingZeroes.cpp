
#include <bits/stdc++.h>

using namespace std;

int main() {

    int t;

    scanf("%d", &t);

    while(t--) {

        string s;

        cin >> s;

        int first = -1;

        int last = -1;

        int count = 0;

        for(int i = 0; i < s.length(); ++i) {

            if(s[i] - '0' == 1) {

                first = i;

                break;

            }
                
        }

        for(int i = s.length() - 1; i >= 0; --i) {

            if(s[i] - '0' == 1) {

                last = i;

                break;

            }

        }

        if((first == -1 && last == -1) || first == last) {

            printf("0\n");

            continue;

        }

        for(int i = first; i <= last; ++i) {

            if(s[i] - '0' == 0) count++;

        }

        printf("%d\n", count);

    }

}