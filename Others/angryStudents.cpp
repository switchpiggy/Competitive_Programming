#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, n;

    string s;

    scanf("%d", &t);

    while(t--) {

        int count = 0, curr = INT_MIN;

        scanf("%d", &n);

        cin >> s;

        for(int i = 0; i < n; ++i) {

            if(s[i] == 'A') {

                curr = 0;

            }

            else {
            	
            	curr++;
            	
            	count = max(curr, count);
            		
            		
            	
            }

        }

        printf("%d\n", count);



    }

}