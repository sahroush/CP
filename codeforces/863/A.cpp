#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
 
typedef long long ll;
//const ll MAX1 = 1e5+10;
 

 
int main(){
	string s;
	cin >> s;
	string p="";
	int n=s.size();
	bool f=0,f1=0;
	for (int i=n-1;i>=0;i--){
		if (f==0 and s[i]=='0'){
			f1=1;
		}
		else{
			p+=s[i];
		}
		if (s[i]!='0'){
			f=1;
		}
	}
	string q="";
	for(int i=p.size()-1;i>=0;i--){
		q+=p[i];
	}
	if (p==q){
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return (0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
