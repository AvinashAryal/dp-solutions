#include<bits/stdc++.h>

#define fo(i,n) for(int i = 0;i < int(n);i++)
#define fok(i,k,n) for(int i = k;i < int(n);i++)
#define ll long long

const int mod = 1e9 + 7;

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    fo(i,n)
        fo(j,n)
            cin >> a[i][j];
    vector<int> dp((1 << n) + 1, 0); //dp[i] represents the no of ways to pair subset i of woman with |i|th man (|i| is number of 1's in the bitset and jth bit of i in binary form represents if jth woman is included in current combination/subset//
    dp[0] = 1; // there is 1 way to pair no woman, and that is no pairing
    fo(subset,(1 << n) - 1) //((1<<n) - 1) is not considered because we cannot pair any more woman in that subset and also it will give segmentation fault because array a has index only upto (n-1) but (1 << n) - 1 has n ones
    {
        int currrent_men_count = __builtin_popcount(subset); //no of 1s in current subset is the no of men already paired
        fo(woman,n)
        {
            if(a[currrent_men_count][woman] && !(subset & (1 << woman)))
            {
                dp[subset | (1 << woman)] = (dp[subset | (1 << woman)] + dp[subset]) % mod;
                //
                //
                //for example, if current subset is 110, it means we can pair 0th woman cuz she's available and not already paired (0th bit of current subset is not set)
                //after pairing 0th woman, the new subset will be 111 i.e (110 OR 001) (0th bit set to one, indicating, curently 0th woman is being paired)
                //here, 0th woman means first woman, because indexing is done from 0
                //
                //
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl; //(1 << n) - 1 is the number with n bits and all its bits are '1'. it means, the number of ways to pair n women/ all women
    return 0;
} 

