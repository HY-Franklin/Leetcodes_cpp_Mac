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
#include <queue> 
using namespace std;
//peak finding
class algrithmpeak {
public:
	void FindPeak() {
		vector<int> q = { 3,2,1,2,3,4 };
		cout << helper(q, 0, q.size() - 1, NULL);
	}
private:
	int helper(vector<int>& q, int left, int right, int mid) {
		mid = left + (right - left) / 2;
		if (mid == 0 || q[mid - 1] < q[mid] && q[mid + 1] < q[mid])	return q[mid];
		if (q[mid - 1] > q[mid])	return helper(q, 0, mid, mid);
		if (q[mid + 1] > q[mid])	return helper(q, mid, q.size(), mid);
        return 0;
	}
};

//take pills
class pill {
public:
	vector<vector<int>> TakePill() {
		int n = 1; //testcase
		vector<vector<int>> res;
		vector<int> cur;
		if (n == 1) {
			res.push_back({ n });
			return res;
		}
		helper(res, n, cur, 1);
		helper(res, n, cur, 2);
		return res;
	}
	void helper(vector<vector<int>>& res, int n, vector<int> cur, int m) {
		if (n == 0)
		{
			res.push_back(cur);
			return;
		}
		cur.push_back(m);
		helper(res, n - m, cur, 1);
		if (n - m == 0 || n - m == 1) return;
		helper(res, n - m, cur, 2);
	}
};

//Karatsuba_algorithm   still doing....
class Karatsuba {
public:
	long long int Karatsuba_algorithm(string x,string y,int m) {
		int a= std::stoi(x.substr(0,x.size() - m));
		int b = std::stoi(x.substr(x.size()-m));
		int c = std::stoi(y.substr(0, y.size() - m));
		int d= std::stoi(y.substr(y.size() - m));
		
		cout << c<<endl;
		
		return b;
	}
};

//Sort a nearly sorted (or K sorted) array
class Karry {
public:
	vector<int> SortK(int arr[],int n, int k) {
		vector<int> res;
		priority_queue<int, vector<int>, greater<int> > pq(arr, arr + k + 1);
		for (int j = k+1; j < n; j++)
		{
			res.push_back(pq.top());
			pq.pop();
			pq.push(arr[j]);
		}
		while (!pq.empty())
		{
			res.push_back(pq.top());
			pq.pop();  
		}
		return res;
	}
};


