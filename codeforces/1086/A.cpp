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

const ll maxn  = 1010;
const ll mod =1e9+7;
const ld PI = acos((ld)-1);

#define pb push_back
#define endl '\n'
#define dokme(x) cout << x , exit(0)
#define migmig ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define ms(x , y) memset(x , y , sizeof x)
ll pw(ll a, ll b, ll md = mod){ll res = 1;while(b){if(b&1){res=(a*res)%md;}a=(a*a)%md;b>>=1;}return(res);}

int x[3] , y[3];

int d(int X , int Y){
	int sum = 0;
	for(int i = 0 ; i < 3 ; i ++)
		sum += abs(X - x[i]) , sum += abs(Y - y[i]);
	return(sum+1);
}

bool mark[maxn][maxn];

void solve(int X , int Y){
	mark[X][Y] = 1;
	for(int i = 0 ; i < 3 ; i ++){
		int curx = x[i] , cury = y[i];
		while(curx != X or cury != Y){
			mark[curx][cury] = 1;
			if(curx < X)curx++;
			else if(curx > X)curx--;
			else if(cury < Y)cury++;
			else cury--;
		}
	}
	for(int i = 0 ; i <= 1000 ; i ++)
		for(int j = 0 ; j <= 1000 ; j ++)
			if(mark[i][j])cout << i << ' ' << j << endl;
}	

int32_t main(){
    migmig;
	for(int i = 0 ; i < 3 ; i ++)
		cin >> x[i] >> y[i];
	int diffx = 0 , diffy = 0;
	for(int i = 0 ; i < 3 ; i ++)
		for(int j = 0 ; j < 3 ; j ++)
			diffx = max(diffx , x[i] - x[j]),
			diffy = max(diffy , y[i] - y[j]);
	cout << diffx + diffy + 1 << endl;
	for(int i = 0 ; i <= 1000 ; i ++){
		for(int j = 0 ; j <= 1000 ; j ++){
			if(d(i , j) == diffx + diffy + 1){
				solve(i , j);
				exit(0);
			}
		}
	}
    return(0); 
}
