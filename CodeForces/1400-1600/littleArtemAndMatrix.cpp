#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,q;
	cin >> n >> m >> q;
	int p[n][m];
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++)p[i][j] = 0;
	}
	int a[q],b[q],c[q],d[q];
	for(int i = 0;i < q;i++){
		cin >> a[i] >> b[i];
		if(a[i] == 3)cin >> c[i] >> d[i];
	}
	for(int i = q-1;i >= 0;i--){
		if(a[i] == 3){
			p[b[i]-1][c[i]-1] = d[i];
		}
		else if(a[i] == 2){
			int k = b[i]-1;
			int temp = p[n-1][k];
			for(int i = n-1;i >= 0;i--){
				p[i][k] = p[i-1][k];
			}
			p[0][k] = temp; 
		}
		else{
			int k = b[i]-1;
			int temp = p[k][m-1];
			for(int i = m-1;i >= 0;i--){
				p[k][i] = p[k][i-1];
			}
			p[k][0] = temp;
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 0;j < m;j++)cout << p[i][j] << " ";
		cout << endl;
	}
	return 0;
}