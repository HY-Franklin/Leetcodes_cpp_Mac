//
//  easy.hpp
//  Leetcodes
//
//  Created by 张环宇 on 12/19/19.
//  Copyright © 2019 Huanyu Zhang. All rights reserved.
//

#ifndef easy_hpp
#define easy_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue> //Priority Queue
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <numeric>      // std::accumulate
#include <cstdlib> //string to int
#include <sstream>      // std::istringstream
#include <cmath>  // std::abs
#include <list>
using namespace std;
//Definition for a binary tree node.
  struct TreeNodeE {
      int val;
      TreeNodeE *left;
      TreeNodeE *right;
      TreeNodeE(int x) : val(x), left(NULL), right(NULL) {}
  };
struct ListNodeE {
         int val;
         ListNodeE *next;
         ListNodeE(int x) : val(x), next(NULL) {}
     };

#endif / easy_hpp /
