#include <bits/stdc++.h>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll MAX1 = 1e5+10;
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 

	
	

 
int main(){
	int n;
	bool f=0;
	string s[1000];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> s[i];
		if (s[i][0]==s[i][1] and s[i][0]=='O' and f==0){
			f=1;
			//cout << "++" ;
			for(int j=2;j<5;j++){
				//cout << s[j];
			}
		}
		if (s[i][4]==s[i][3] and s[i][4]=='O' and f==0){
			f=1;
			for(int j=0;j<3;j++){
				//cout << s[j];
			}
			//cout << "++" ;
		}
		else{
			//cout << s << endl;
		}
	}
	if (f==0){
		cout << "NO";
		return(0);
	}
	else{
		cout << "YES";
	}
	f=0;
	cout << endl;
	for (int i=0;i<n;i++){
		if (s[i][0]==s[i][1] and s[i][0]=='O' and f==0){
			f=1;
			cout << "++" ;
			for(int j=2;j<5;j++){
				cout << s[i][j];
			}
		}
		else if (s[i][4]==s[i][3] and s[i][4]=='O' and f==0){
			f=1;
			for(int j=0;j<3;j++){
				cout << s[i][j];
			}
			cout << "++" ;
		}
		else{
			cout << s[i] ;
		}
		cout << endl;
	}

	
 
	return(0);
}
 
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, life is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
