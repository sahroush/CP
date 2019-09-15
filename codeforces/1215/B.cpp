#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 2e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int n, inp ;
bool a[maxn];
ll pos[maxn] , neg[maxn];

int main(){
    cin >> n;
    for (int  i = 0 ; i < n ; i ++){
        cin >> inp;
        if (inp > 0){
            a[i] = 1;
        }
        else{
            a[i] = 0;
        }
    }
    if (a[0]){
        pos[0] = 1;
        neg[0] = 0;
    }
    else{
        pos[0] = 0;
        neg[0] = 1;
    }
    for (int i = 1 ; i < n ; i ++){
        if(a[i]){
            pos[i] = pos[i-1] + 1;
            neg[i] = neg[i-1];
        }
        else{
            pos[i] = neg[i-1];
            neg[i] = pos[i-1]+1;

        }
    }

    ll ans1=0 , ans2=0;
    for (int i = 0 ; i < n ; i ++){
        ans1+=pos[i];
        ans2+=neg[i];
    }
    cout << ans2 << '\t' << ans1;


	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
