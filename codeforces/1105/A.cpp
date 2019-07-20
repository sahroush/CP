#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 

 
int main(){
	int n,l[1024];
	cin >> n;
	int cnt=1e9;
	for(int i=0;i<n;i++){
		cin >> l[i];
	}
	int cou=0;
	int mc=1e9;
	for(int j=1;j<101;j++){
		cou=0;
		for(int i=0;i<n;i++){
			cou+=sqrt(pow((l[i]-j),2));
			if( sqrt(pow((l[i]-j),2))!=0){
				cou--;
			}
		}
		if(cou <mc){
			cnt=j;
			mc=cou;
		}
	}
	cout<<cnt << '\t' << mc;
	return(0);
		
	
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
