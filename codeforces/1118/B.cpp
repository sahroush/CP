#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+1;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int a[maxn] , n;
ll o[maxn] , e[maxn];

int main(){
    migmig
    cin >> n;
    for (int i = 0 ; i < n ; i ++){
        cin >> a[i];
        if (!i){
            e[0] = a[0];
            o[0] = 0;
        }
        else if (i%2 == 0){
            e[i] = a[i] + e[i-1];
            o[i] = o[i-1];
        }
        else{
            o[i] = o[i-1] + a[i];
            e[i] = e[i-1];
        }



    }
    int ans = 0 ;
    if (e[n-1] - a[0]==o[n-1] ){
        ans++;
    }
    for (int i =1 ; i < n ; i ++){
        if (e[i-1] + (o[n-1]  - o[i] )  == o[i-1] +  (e[n-1] - e[i])){
            ans++;
        }
    }
    cout << ans;

    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
