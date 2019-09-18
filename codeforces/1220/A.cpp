#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll maxn = 1e6+10;
const ll ZERO = 0;
const ll SADAT = 7.84e-17;
const ll INF = 1e10;
const ll mod = 1e9+7;

#define endl '\n'
#define dokme(x) cout << x ;  return(0);
#define migmig ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_init freopen("input.txt", "r+", stdin); freopen("output.txt", "w+", stdout);

int q;
int n = 0 , o= 0 , e = 0 , z = 0 , r = 0;

string s , ans = "";

int main(){
    cin >> q;
    cin >> s;
    for (int i = 0 ; i < q ; i ++){
        if (s[i] == 'z'){
            z++;
        }
        if (s[i] == 'n'){
            n++;
        }
        if (s[i] == 'o'){
            o++;
        }
        if (s[i] == 'e'){
            e++;
        }
        if (s[i] == 'r'){
            r++;
        }
    }
    while (n != 0 and o!=0 and e!=0){
        n-- , o-- , e--;
        ans+='1';
        ans +='\t';
    }
    while (z and e and r and o){
        z-- , e -- ,r-- ,o--;
        ans+='0';
        ans +='\t';
    }
    cout << ans;



    return(0);
}
//When we hit our lowest point, we are open to the greatest change.
//If I try, I fail. If I don't try, I'm NEVER GOING TO GET IT.
//Sometimes, l is like this dark tunnel. You can't always see the light at the end of the tunnel. But if you just keep moving... you will come to a better place.
