/*
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma")
//*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int  ,int > pii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll maxn  = 3e6;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

string s[4];

bool hor(int x , int y){
	if(x < 1 or x > 2)return(0);
	int cnt = 0;
	if(s[x][y] == 'o')return(0);
	if(s[x][y] == '.')cnt++;
	if(s[x-1][y] == 'o')return(0);
	if(s[x-1][y] == '.')cnt++;
	if(s[x+1][y] == 'o')return(0);
	if(s[x+1][y] == '.')cnt++;
	return(cnt < 2);
}

bool ver(int x , int y){
	if(y < 1 or y > 2)return(0);
	int cnt = 0;
	if(s[x][y] == 'o')return(0);
	if(s[x][y] == '.')cnt++;
	if(s[x][y-1] == 'o')return(0);
	if(s[x][y-1] == '.')cnt++;
	if(s[x][y+1] == 'o')return(0);
	if(s[x][y+1] == '.')cnt++;
	return(cnt < 2);
}

bool dia(int x , int y){
	int cnt = 0;
	if(x < 1 or x > 2)return(0);
	if(y < 1 or y > 2)return(0);
	if(s[x][y] == 'o')return(0);
	if(s[x][y] == '.')cnt++;
	if(s[x-1][y-1] == 'o')return(0);
	if(s[x-1][y-1] == '.')cnt++;
	if(s[x+1][y+1] == 'o')return(0);
	if(s[x+1][y+1] == '.')cnt++;
	return(cnt < 2);
}

bool diag(int x , int y){
	int cnt = 0;
	if(x < 1 or x > 2)return(0);
	if(y < 1 or y > 2)return(0);
	if(s[x][y] == 'o')return(0);
	if(s[x][y] == '.')cnt++;
	if(s[x-1][y+1] == 'o')return(0);
	if(s[x-1][y+1] == '.')cnt++;
	if(s[x+1][y-1] == 'o')return(0);
	if(s[x+1][y-1] == '.')cnt++;
	return(cnt < 2);
}

bool chk(int x , int y){
	if(ver(x , y))return(1);
	if(hor(x , y))return(1);
	if(dia(x , y))return(1);
	if(diag(x , y))return(1);
	return(0);
	
}

int32_t main(){
    migmig;
	for(int i = 0 ; i < 4 ; i ++)
		cin >> s[i];
	for(int i = 0 ; i < 4 ; i ++)
		for(int j = 0 ; j < 4 ; j ++)
			if(chk(i , j))dokme("YES");
	cout << "NO";




    return(0);
}
