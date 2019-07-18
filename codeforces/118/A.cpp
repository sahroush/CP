#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;

typedef long long ll;
//const ll MAX1 = 1e5+10;






int main(){
	string s;
	cin >> s;
	string f;
	for (int i=0;i<s.size();i++){
		if(s[i]!='A' and s[i]!='O' and s[i]!='Y' and s[i]!='E' and s[i]!='U' and s[i]!='I' and s[i]!='a' and s[i]!='o' and s[i]!='y' and s[i]!='e' and s[i]!='u' and s[i]!='i'){
			f+='.';
			f+=towlower(s[i]);
		}
	}
	cout << f;
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
