//
//  easy.cpp
//  Leetcodes
//
//  Created by 张环宇 on 12/19/19.
//  Copyright © 2019 Huanyu Zhang. All rights reserved.
//

#include "hppFiles/easy.hpp"
//617. Merge Two Binary Trees https://leetcode.com/problems/merge-two-binary-trees/
class Solution617 {
public:
    
    TreeNodeE* mergeTrees(TreeNodeE* t1, TreeNodeE* t2) {
        TreeNodeE* res=NULL;
        helper(t1, t2, res);
        return res;
    }
    void helper(TreeNodeE* t1, TreeNodeE* t2,TreeNodeE*& res){
        if (!t1&&!t2) return;
        if(!t1&&t2){
            res=new TreeNodeE(t2->val);
            helper(NULL, t2->left, res->left);
            helper(NULL, t2->right, res->right);
        }
        else if (!t2&&t1) {
            res=new TreeNodeE(t1->val);
            helper(t1->left, NULL, res->left);
            helper(t1->right, NULL, res->right);
        }
        else if(t1&&t2){
            res=new TreeNodeE(t1->val+t2->val);
            helper(t1->left, t2->left, res->left);
            helper(t1->right, t2->right, res->right);
        }
        
        
    }
};

//136. Single Number https://leetcode.com/problems/single-number/
class Solution136 {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (auto num : nums) res ^= num;
        return res;
        
    }
};

//406. Queue Reconstruction by Height


//739. Daily Temperatures
class Solution739 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res; int c=0;
        for (int i=0; i<T.size(); i++) {
            c=0;
            for (int j=i+1; j<T.size(); j++) {
                if (T[i]<T[j]) {
                    int t=j-i;
                    cout<<i<<"|"<<j<<endl;
                    res.push_back(t);
                    c++;
                    break;
                }
            }
            if (c==0) {
                res.push_back(0);
            }
        }
        return res;
    }
};
