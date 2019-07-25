#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 

	
	

 
int main(){
	int n,l[10][10];
	cin >> n;
	for(int i=0;i<n;i++){
		fill (l[i],l[i]+n,1);
	}
	for(int i=0;i<n;i++){
		for (int j=0;j<n;j++){
			if (i>0 and j>0){
				l[i][j]=l[i-1][j]+l[i][j-1];
			}
		}
	}


	cout << l[n-1][n-1];

	
 
	return(0);
}
 
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
