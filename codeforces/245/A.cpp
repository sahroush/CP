#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;




int main(){
	int n,alost=0,blost=0,ax=0,bx=0;
	cin >> n;
	int inp[3];
	for (int i=0;i<n;i++){
		for (int j=0;j<3;j++){
			cin >> inp[j];
		}
		if (inp[0]==1){
			alost+=inp[2];
			ax+=inp[1];
		}
		if (inp[0]!=1){
			blost+=inp[2];
			bx+=inp[1];
		}
	}
	if (alost<=ax){
		cout << "LIVE";
	}
	else {
		cout <<"DEAD";
	}
	cout  << endl;
	if (blost<=bx){
		cout <<"LIVE" ;
	}
	else{
		cout << "DEAD";
	}
		
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
