#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 3e5+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int a1,a2 , k1 , k2 , n;

int main(){
    cin >> a1 >> a2 >> k1 >> k2 >> n;
    int mn = a1 * (k1 - 1) + a2 * (k2 - 1);
    //cout << a1;
    if (mn >= n){
        cout << 0 << '\t';
    }

    else{
        mn = n - mn;
        cout << mn << '\t';
    }
    int cnt = 0;
    if (k1 > k2){
        while(a2 and n-k2 >= 0 ){
            n-=k2;
            a2--;
            cnt++;
        }
        while(a1 and n-k1 >= 0 ){
            n-=k1;
            a1--;
            cnt++;
        }
    }
    else{
        swap(k1 , k2);
        swap(a1 , a2);
        while(a2 and n-k2 >= 0 ){
            n-=k2;
            a2--;
            cnt++;
        }
        while(a1 and n-k1 >= 0 ){
            n-=k1;
            a1--;
            cnt++;
        }
    }
    cout << cnt;
	return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
