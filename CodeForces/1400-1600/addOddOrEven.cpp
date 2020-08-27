#include <bits/stdc++.h>

using namespace std;

int main() {

    int t, a, b;

    scanf("%d", &t);

    while(t--) {

        cin >> a >> b;
        
        if(a == b) {
        	
        	printf("0\n");
        	
        	continue;
        	
        }
        
        if(a > b) {
        	
        	if((a - b)%2 == 0) printf("1\n");

            else printf("2\n");
        	
        }

        else if((b - a)%2 == 0) printf("2\n");

        else if((b - a)%2 == 1) printf("1\n");

    }

}