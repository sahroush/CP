#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;





int main(){
	int n;
	cin>>n;
	string s;
	cin >> s;
	int sea=0,san=0;
	for (int i=0;i<n-1;i++){
		if(s[i]=='S' and s[i+1]=='F'){
			sea++;
		}
		if ( s[i]=='F' and s[i+1]=='S'){
			san++;
		}
	}
	if (sea> san){
		cout <<"YES";
	}
	else{
		cout << "NO";
	}
	return(0);
}

//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
