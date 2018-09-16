#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int LIS(vector<int>& nums)
{
	vector<int> dp;
	dp.push_back(nums[0]);
	
	for(int i = 1; i < nums.size(); i++)
	{
		int pos = dp.size() - 1;
 		if(nums[i] > dp[pos])
			dp.push_back(nums[i]);
		else if(nums[i] < dp[pos])
		{
			int lo = 0, hi = pos;
			while(lo < hi)
			{
				int mid = lo + (hi - lo)/2;
				if(dp[mid] > nums[i])
					hi = mid - 1;
				else
					lo = mid;
			}
			dp[lo] = nums[i];
			for(int i = 0; i < dp.size(); i++)
				cout << dp[i] << " ";
			cout << endl;
		}
	}
	for(int i = 0; i < dp.size(); i++)
		cout << dp[i] << " ";
	cout << endl;
	return dp.size();
}


int dp(int j, vector<int>& nums) // DP version of LIS 
{

    if(vis[j])
        return len[j];
    vis[j] = 1;
    for(int i = j - 1; i >= 0; i--)
    {
        if(nums[j] > nums[i])
        {
            int len1 = dp(i, nums);
            if(len1 + 1 > len[j])
            {
                len[j] = len1 + 1;
                cnt[j] = cnt[i];
            }
            else if(len1 + 1 == len[j])
                cnt[j] += cnt[i];
        }
    }
    return len[j];
}

int findNumberOfLIS(vector<int>& nums) { // count the number of LIS
    int n = nums.size(), maxlen = 1;
	fill(vis, vis + 2000, 0);
	fill(len, len + 2000, 1);
	fill(cnt, cnt + 2000, 1);
    for(int i = 0; i < n; i++)
    	dp(i, nums);
    int ans = 0;
//    for(int i = 0; i < 5; i++)
//		cout << "cnt = " << cnt[i] << " ";
//	cout << endl;
    for(int i = 0; i < n; i++)
        maxlen = max(maxlen, len[i]);
;
    for(int i = 0; i < n; i++)
        if(len[i] == maxlen)
            ans += cnt[i];
    return ans;
}
int main()
{
	vector<int> nums = {4, 10, 4, 3, 8, 9};
	LIS(nums);
}






