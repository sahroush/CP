#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;






int main(){
	int n;
	cin >> n;
	string s;
	for (int i=0;i<n;i++){
		cin>>s;
		if (s.size()>10){
			cout<<s[0]<<s.size()-2<<s[s.size()-1] << endl;
		}
		else{
			cout<<s << endl;
		}
	}

	return(0);

}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
