#include <bits/stdc++.h>

using namespace std;

int n , q;
int a[200];

int32_t main(){
    cin >> q;
    while(q --){
        cin >> n;
        for(int i = 1 ; i <= n ; i ++)
            cin >> a[i];
        sort(a + 1 , a + n + 1);
        int ans = 0;
        for(int i = 2 ; i <= n ; i ++)
            ans += (a[i] != a[1]);
        cout << ans << endl;
    }
    return(0);
}
