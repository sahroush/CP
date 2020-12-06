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

int q , n;
string s[maxn];
string S[maxn];

bool chk(int a , int b , int x , int y , int p , int q){
	if(min({a , b , x , y , p, q}) < 0)return(0);
	if(max({a , b , x , y , p, q}) >= n)return(0);
	char dick = s[a][b];
	if(dick == '.')return(0);
	return(s[x][y] == dick and s[p][q] == dick);
}

bool solve(int i , int j){
	bool ok = 0;
	if(chk(i , j , i+1 , j , i+2 , j))ok=1;
	if(chk(i , j , i+1 , j , i-1 , j))ok=1;
	if(chk(i , j , i-1 , j , i-2 , j))ok=1;
	if(chk(i , j , i , j - 1 , i , j - 2))ok=1;
	if(chk(i , j , i , j + 1 , i , j + 2))ok=1;
	if(chk(i , j , i , j - 1 , i , j + 1))ok=1;
	return(!ok);
}

bool fuck[400][400];
int k;

int test(int x , int y){
	if(x == y)return(0);
	for(int i = 0 ; i < n ; i ++)s[i] = S[i];
	int cnt = 0;
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < n ; j ++){
			if(s[i][j] == 'X' and (i + j)%3 == x){
				cnt ++ ;
				s[i][j] = 'O';
			}
			else if(s[i][j] == 'O' and (i + j)%3 == y){
				cnt ++ ;
				s[i][j] = 'X';
			}
		}
	if(cnt > k/3)return(0);
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < n ; j ++)
			if(!solve(i , j))return(0);
	return(1);
}

int32_t main(){
    migmig;
	cin >> q;
	while(q -- ){
		cin >> n;
		for(int i = 0 ; i < n ; i ++)cin >> S[i];
		k = 0;
		for(int i = 0 ; i < n ; i ++)
			for(int j = 0 ; j < n ; j ++)
				if(S[i][j]!='.')k++;
		for(int i = 0 ; i < 3 ; i ++)
			for(int j = 0 ; j < 3 ; j ++)
				if(test(i , j)){
					i = 3;
					break;	
				}
		for(int i = 0 ; i < n ; i ++)
			cout << s[i] << endl;
	}
    return(0);
}
