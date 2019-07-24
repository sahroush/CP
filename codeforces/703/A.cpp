#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
//const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);




int main(){
	int n,cnt=0,a,b;
	cin >>n;
	int cnb=0,cnc=0;;
	for(int i=0;i<n;i++){
		cin >> a >>b;
		if (a>b){
			cnt++;
		}
		else if (a==b) {
			cnc++;
		}
		else{
			cnb++;
		}
	}
	if (cnt <cnb ){
		cout << "Chris";
	}
	else if (cnt > cnb ){
		cout << "Mishka";
	}
	else{
		cout << "Friendship is magic!^^";
	}
	return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
