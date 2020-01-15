//
//  Amazon.hpp
//  Leetcodes
//
//  Created by 张环宇 on 10/11/19.
//  Copyright © 2019 Huanyu Zhang. All rights reserved.
//

#ifndef Amazon_hpp
#define Amazon_hpp
#endif /* Amazon_hpp */
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#include <list>
#include <queue> 
#include <unordered_set>
#include <unordered_map>
#include <numeric>      // std::accumulate
#include <cstdlib> //string to int
#include <sstream>      // std::istringstream
#include <cmath>  // std::abs
#include <ctype.h> //isalpha() tolower()
#include<cstdio>
#include <stack> 

using namespace std;

//binary tree
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

// Definition for a N-ray Node.
class Node {
public:
    int val;
    vector<Node*> children;
    
    Node() {}
    
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

//x,y move obstacle
class TNode {
public:
    int x;
    int y;
    int dis;
    
    TNode(){}
    
    TNode(int x,int y,int dis) {
        this->x=x;
        this->y=y;
        this->dis=dis;
        
    }
};

//TreasureIslandI node structure
class TINode {
public:
    int x;
    int y;
    vector<vector<int>> path;
    
    TINode(){}
    
    TINode(int x,int y,vector<vector<int>> path) {
        this->x=x;
        this->y=y;
        this->path=path;
        
    }
};




