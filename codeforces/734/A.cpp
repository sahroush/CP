#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;
 
ll trl( ll q){
	ll r=0;
    while (q >= 5) {
        r += q / 5;
        q /= 5;
    }
	return(r) ;
}
 
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a=0,d=0;
	for (int i=0;i<n;i++){
		if (s[i]=='A'){
			a++;
		}	
		else{
			d++;
		}
	}
	if (a>d){
		cout <<"Anton" ;
	}
	else if (d>a){
		cout <<"Danik"   ;
	}
	else {
		 cout <<  "Friendship";
	}
	return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
