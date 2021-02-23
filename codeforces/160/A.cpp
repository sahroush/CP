#include<bits/stdc++.h> 
using namespace std;
int n;
int a[110];
int sum = 0;
int32_t main(){
    cin >> n;
    for(int i = 0 ; i < n ; i ++)cin >> a[i] , sum += a[i];
    sort(a , a + n);
    int ans = 0;
    for(int i = 0 ; i < n ; i ++){
        if(i)a[i]+=a[i-1];
        if(sum - a[i] > a[i])ans = i + 1;
    }
    cout << n - ans;
    return 0;
}