

#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>      // std::accumulate
#include <cstdlib> //string to int
#include <sstream>      // std::istringstream
#include <cmath>  // std::abs
#include <math.h>       /* pow */
#include <stack> 
#include <sstream>
using namespace std;
//70. Climbing Stairs


class Solution70 {
public:
	int climbStairs(int n) {
		if (n == 1) return 1;
		vector<int> dp(n);
		dp[0] = 1; dp[1] = 2;
		for (int i = 2; i < n-1; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp.back();
	}
};

//62. Unique Paths
class Solution62 {
public:
	int uniquePaths(int m, int n) {
		auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1) continue;
				
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[n][m];
	}       
};

//63. Unique Paths II
class Solution63 {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0] == 1) return 0;
		int n = obstacleGrid.size();
		int m = obstacleGrid[0].size();

		auto dp = vector<vector<unsigned int>>(n + 1, vector<unsigned int>(m + 1, 0));
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (i == 1 && j == 1) continue;
				
				if (obstacleGrid[i-1][j-1]==1)
				{
					continue;
				}
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				
			}
		}
		return dp[n][m];
	}
};

//[LeetCode] 279. Perfect Squares ?????
class Solution279 {
	int numSquares(int n) {
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;
		for (int i = 0; i <= n; ++i) {
			for (int j = 1; i + j * j <= n; ++j) {

				dp[i + j * j] = min(dp[i + j * j], dp[i] + 1);
				int x = i + j * j;
				cout << i << "+" << j << "*" << j << endl << "dp[" << x << "]:" << endl << dp[i + j * j] << endl;
			}
		}
		cout << dp.back();
		return dp.back();
	}
};

//139. Word Break
class Solution139 {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		unordered_set<string> res = {wordDict.cbegin(),wordDict.cend()};
		return wordBreak(s, res);
	}
	bool wordBreak(const string& s,const unordered_set<string>& res) {
		if (res.count(s))
		{
		
			return true;
		}
		for (int i = 0; i < s.size(); i++)
		{
			const string l = s.substr(0, i);
			const string r = s.substr(i);
			if (res.count(l)&&wordBreak(r,res))
			{
				return true;
			}
		}
		return false;

	}
};
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		// Create a hashset of words for fast query.
		unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
		// Query the answer of the original string.
		return wordBreak(s, dict);
	}

	bool wordBreak(const string& s, const unordered_set<string>& dict) {
		// In memory, directly return.
		
		if (mem_.count(s)) return mem_[s];
		// Whole string is a word, memorize and return.
		if (dict.count(s)) return mem_[s] = true;
		// Try every break point.
		for (int j = 1; j < s.length(); j++) {
			const string left = s.substr(0, j);
			const string right = s.substr(j);
			// Find the solution for s.
			if (dict.count(right) && wordBreak(left, dict))
				return mem_[s] = true;
		}
		// No solution for s, memorize and return.
		return mem_[s] = false;
	}
private:
	unordered_map<string, bool> mem_;
};

//375. Guess Number Higher or Lower II
class Solution375 {
public:
//    int getMoneyAmount(int n) {
//
//    }
};

//322. Coin Change  
class Solution322 {
public:
	//Leetcode:Memory Limit Exceeded
	int coinChange1() {
		vector<int> coins = { 186,419,83,408};
		int amount = 6249;
		int l=INT_MAX;
		vector<int> cur;
		vector<vector<int>> res;
		int stop=0;
		sort(coins.begin(), coins.end());
		reverse(coins.begin(), coins.end());
		helper(coins, amount, 0, cur, res,stop);
		//printVectorP(res);
		for (auto i : res) {
			int t = i.size();
			l = min(l, t);
			
		}
		return l==INT_MAX?-1:l;

	}

	void helper(vector<int>& coins, int amount,int s, vector<int>& cur, vector<vector<int>>& res,int& stop) {
		if (stop==1)
		{
			return;
		}
		if (amount==0)
		{
			stop = 1;
			res.push_back(cur);
			//printVecto(cur);
			return;
		}
		else if(amount<0)
		{
			return;
		}

		if (s==coins.size())
		{
			return;
		}
		for (int i = s; i < coins.size(); i++)
		{
			cur.push_back(coins[i]);
			helper(coins, amount- coins[i], s, cur, res,stop);
			cur.pop_back();
		}
	}

	void printVectorP(vector<vector<int>> res) {
		for (auto i : res) {
			for (auto j : i) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
	void printVecto(vector<int> vc) {
		for (auto i : vc) {
			cout << i << " ";
		}
		cout << endl;
	}
	//correct
	int coinChange() {
		vector<int> coins = { 1,2,5 };
		int amount=11;
		vector<int> dp(amount+1, INT_MAX);
		dp[0] = 0;
		for (auto i : coins) {
			for (int j = i; j <= amount; j++)
			{
				if (dp[j-i]!=INT_MAX)
				{
					dp[j] = min(dp[j], dp[j - i] + 1);
				}
			}
		}
		printVecto(dp);

		return dp[amount] == INT_MAX ? -1 : dp[amount];
	}

};

//256 Print house
class Solution256 {
public:
	int minCost() {
		vector<vector<int>> costs = {
		{14,2,11},
		{11,14,5},
		{14,3,10}
		};
		vector<vector<int>> dp=costs;
		
		for (int i = 0; i < costs.size(); i++)
		{
			if (i==0)
			{
				dp[0][0] = costs[0][0];
				dp[0][1] = costs[0][1];
				dp[0][2] = costs[0][2];
				continue;
			}
			dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
		}

		//printVectorP(dp);
		
		return min(dp[costs.size()-1][0], min(dp[costs.size() - 1][1], dp[costs.size() - 1][2]));




	}
	void printVectorP(vector<vector<int>> res) {
		for (auto i : res) {
			for (auto j : i) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
};

//64. Minimum Path Sum
class Solution64 {
public:
	int minPathSum() {
		vector<vector<int>> grid = {
		{1,2,5},
		{3,2,1}
		};
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m,INT_MAX));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i==0&&j==0)
				{
					dp[i][j] = grid[i][j];
					continue;
				}else if (i==0)
				{
					dp[i][j] = dp[i][j - 1] + grid[i][j];
					continue;
				}else if (j == 0)
				{
					dp[i][j] = dp[i - 1][j] + grid[i][j];
					continue;
				}
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1])+ grid[i][j];
			}
		}
		//printVectorP(dp);
	
		return dp.back().back();

	}
	void printVectorP(vector<vector<int>> res) {
		for (auto i : res) {
			for (auto j : i) {
				cout << j << " ";
			}
		}
		cout << endl;
	}
};


//198 House Robber
class Solution198 {
public:
    int rob() {
        vector<int> nums={2,1,1,2};
        if (nums.empty()) {
            return 0;
        }
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];dp[1]=max(dp[0],nums[1]);
        for (int i=0; i<nums.size(); i++) {
            if(i<=1) continue;
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        return dp.back();
        
    }
};

//
