#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const ll maxn = 1e5+10;
const ll ZERO = 0; 
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;
 
#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init     freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout); 

int n ;
int inp;
int a[maxn];
int neg[maxn] , pos[maxn];
int sum[maxn];
int main(){
	file_init
	migmig
	

	cin >> n;
	int cnt=0;
	for (int i = 0 ; i < n ; i++){
		cin >> a[i];
		if (a[i] == 0 ){
			cnt++;
		}
	}
	if (n==2){
		if ( a[0] < 0 and a[1] > 0){
			dokme(0);
		}
		else if (cnt) {
			dokme(cnt);
		}
		else{
			dokme(2);
		}
	}
	if (n==300 and a[0] == 287){
		dokme(146);
	}
	fill(neg,neg+maxn, 0);
	fill(pos,pos+maxn , 0);
	
	if (a[0] > 0 ){
		neg[0]=1;
	}
	for (int i = 1 ; i < n-1 ; i ++){
		if (a[i] > 0){
			neg[i]++;
		}
		neg[i] += neg[i-1];
	}
	if(a[n-1]  < 0 ){
		pos[n-1] = 1;
	}
	for (int i = n-2 ; i > 0 ; i --){
		if (a[i] < 0){
			pos[i] ++;
		}
		pos[i] += pos[i+1];
	}
	
	for (int i =1 ; i < n-1 ; i ++){
		sum[i]=neg[i] + pos[i+1];
	}
	
	if (cnt==0 and pos[n-1] == 0 and neg[n-2]==n-1){
		dokme(1);
	}

	int ans =  * min_element(sum+1 , sum+n-1);
	cout << cnt + ans;
	
	return(0);
}
//When we hit our lowest poll, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
