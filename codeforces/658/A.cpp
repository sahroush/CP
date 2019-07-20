#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 
 
 
 
int main(){
	int n,c;
	cin >> n >> c;
	int p[n],t[n];
	int cnt=0,l=0;
	for (int i=0;i<n;i++){
		cin >> p[i];
	}
	for (int i=0;i<n;i++){
		cin >> t[i];
	}
	for (int i=0;i<n;i++){
		cnt+=t[i];
		if (p[i]-(cnt*c)>0){
			l+=p[i]-(cnt*c);
		}
	}
	cnt=0;
	int r=0;
	for (int i=n-1;i>=0;i--){
		cnt+=t[i];
		if (p[i]-(cnt*c)>0){
			r+=p[i]-(cnt*c);
		}

	}
	if (r>l){
		cout << "Radewoosh";
	}
 
	if (r==l){
		cout << "Tie";
	}
	if (r<l){
		cout << "Limak";
	}
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
