#include <bits/stdc++.h>
using namespace std;
 
const int N = 50 + 5;
int n, l, ar[2][N];
vector <int> v;
 
int main() {
    cin >> n >> l;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < n; j++)
            cin >> ar[i][j];
    
    int tmp = l - ar[0][n - 1];
    for (int i = 0; i < n; i++)
        ar[0][i] += tmp;
    
    tmp = l - ar[1][n - 1];
    for (int i = 0; i < n; i++)
        ar[1][i] += tmp;
    
    for (int i = 0; i < 2; i++)
        for (int j = n - 1; j; j--)
            ar[i][j] -= ar[i][j - 1];
    
    for (int i = 0; i < n; i++) {
    	int now = i;
    	bool check = 1;;
    	for (int j = 0; j < n; j++) {
    		if (ar[0][now] != ar[1][j]) {
    			check = 0;
    			break;
    		}
    		now++;
    		if (now == n)
    			now = 0;
    	}
    	
    	if (check)
    		return cout << "YES", 0;
    }
    cout << "NO";
}