#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll MAX = 5e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int n,m,x,y;
int cnt=0;
int main(){
	int n;
	cin >> n >> m;
	bool l [n];
	memset(l,0,n);
	for (int i =0 ; i < m*2 ; i ++){
		cin >> y;
		l[y-1]=1;
	}
	for (int i = 0 ; i < n ; i ++){
		if (l[i] == 0 ){
			y=i+1;		
		}
	}
	bool f=0;
	cout << n-1 << endl;
	for (int i = 0 ; i < n -1; i ++){
		if (i+1 == y){
			f=1;
		}
		if (f==0){
			cout << i+1  << '\t'<< y << endl;
		}
		if (f==1){
			cout << i+2 <<'\t' <<  y  << endl;			
		}
	}

	
 
    return (0);
}
