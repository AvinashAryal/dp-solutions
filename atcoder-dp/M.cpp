#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(k+1,0); //dp[i] is the number of ways if i candies(in total) are used
    fo(i,n)
        cin >> a[i];
    dp[0] = 1;  //the combination (0,0,0.......)
//    fo(i,n)
//    {
//        for(int j = k;j >= 0;j--)
//        {
//            fok(val,1,a[i]+1) // for each value available (i.e. 1 to a[i]) number of ways to get sum j is increased by the number of ways to get j - val, because we can use "val" candies from current pile
//            {
//
//                    if(j - val >= 0) dp[j] = (dp[j] + dp[j-val])%mod;
//                    cout << i << " " << val << " : "; fo(s,k+1) cout << dp[s] << " ";
//                    cout << endl;
//                    or 
//                    if(j + val <= k) dp[j+val] = (dp[j+val] + dp[j])%mod;
//            }
//        }
//    }
//    the upper way works but since a[i] can be upto 10^5 and complexity is (N*k^2), it is very slow
//    so we use another technique
//    in the loop we see that, we increase dp[j] by the values in the interval (j-val,j-1)
//    if we use push dp because we increase every element in the interval (j+1,j+val) by the same value dp[j]
//    for this, we can use an array and assign the first element of the interval to the value to be increased and the element after the interval to the negative of the value to be increased
//    this way, when we compute prefix sum at last, we get the same effect
//    for increasing (l,r) by 5, put arr[l] = 5 and arr[r+1] = -5, and calculate prefix sums at last
//
//    if we use pull dp, it's even easier because we can calculate the increament value by adding dp[j-val] to dp[j-1] and increase dp[j] by that value;

// for push dp
//    fo(i,n)
//    {
//        vector<int> temp(k+1,0);
//        for(int j = k;j >= 0;j--)
//        {
//            int l = j+1;
//            int r = j+a[i];
//            int inc = dp[j];
//            if(l <= k) temp[l] = (temp[l] + inc) % mod;
//            if(r+1 <= k) 
//            {
//                temp[r+1] -= inc;
//                if(temp[r+1] < 0) temp[r+1] += mod;
//            }
//        }
//        int prefix_sum = 0;
//        fok(i,1,k+1)
//        {
//            prefix_sum = (prefix_sum + temp[i]) % mod;
//            dp[i] = (dp[i] + prefix_sum) % mod;
//        }
//    }
//
//for pull dp
//    fo(i,n)
//    {
//        vector<int> prefix_sum(k+2,0);
//        prefix_sum[0] = 0;
//        fok(index,1,k+2)
//            prefix_sum[index] = (prefix_sum[index - 1] + dp[index - 1]) % mod;
//        for(int j = k;j > 0;j--)
//        {
//            int l, r , inc;
//            r = j - 1;
//            l = max(0,j - a[i]); 
//            inc = prefix_sum[j] - prefix_sum[l];
//            if(inc < 0) inc += mod;
//            if(r >= 0 && l >= 0) dp[j] = (dp[j] + inc) % mod;
//        }
//    }
    cout << dp[k] << endl;
    return 0;
}

