//
//  HW3.cpp
//  Leetcodes
//
//  Created by 张环宇 on 10/15/19.
//  Copyright © 2019 Huanyu Zhang. All rights reserved.
//

#include "HW3.hpp"
class heapsort_test{
public:
    vector<int> output(){
        vector<int> H1={10, 5, 6, 2};   make_heap(H1.begin(), H1.end());
        vector<int> H2={12, 7, 9};  make_heap(H2.begin(), H2.end());
        int h1=H1.size();int h2=H2.size();
        vector<int> res={10, 5, 6, 2};

       
        return res;
    }
};

//Median of Stream of Running Integers using STL
class NumberTwo{
public:
    void start(){
        int arr[]={1,2,3,4,5,6,7};  //testcase
        int m=sizeof(arr)/sizeof(arr[0]);
        output(arr, m);
    }
    
    void output(int arr[],int& m){
        priority_queue<int> maxp;
        priority_queue<int,vector<int>,greater<int>> minp;
        double pre=arr[0];
        maxp.push(pre);
        cout<<pre<<endl;
        int n;
        for (int i=1; i<m; i++) {
             n=arr[i];
            if (maxp.size()>minp.size()&&n<pre) {
                minp.push(maxp.top());  maxp.pop();
                maxp.push(n);
                pre=(double)(maxp.top()+minp.top())/2;
            }else if(maxp.size()>minp.size()&&n>=pre){
                minp.push(n);
                pre=(double)(maxp.top()+minp.top())/2;
            }else if (maxp.size()<minp.size()&&n>=pre) {
                maxp.push(minp.top());  minp.pop();
                minp.push(n);
                pre=(double)(maxp.top()+minp.top())/2;
            }else if(maxp.size()<minp.size()&&n<pre){
                maxp.push(n);
                pre=(double)(maxp.top()+minp.top())/2;
            }else if (maxp.size()==minp.size()&&n<pre) {
                maxp.push(n);
                pre=maxp.top();
            }else if(maxp.size()==minp.size()&&n>=pre){
                minp.push(n);
                pre=minp.top();
            }
            cout<<pre<<endl;
        }
    }
    
    double prem(priority_queue<int>& maxp,priority_queue<int,vector<int>,greater<int>>& minp){
        double pre=INT_MAX;
        if(maxp.size()==minp.size()){
            pre=(double)(maxp.top()+minp.top())/2;
        }else if(maxp.size()>minp.size()){
            pre=maxp.top();
        }
        else if(maxp.size()<minp.size()){
            pre=minp.top();
        }
        return pre;
    }
};
