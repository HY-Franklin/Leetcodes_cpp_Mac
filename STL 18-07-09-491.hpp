//
//  STL.hpp
//  Leetcodes
//
//  Created by 张环宇 on 10/11/19.
//  Copyright © 2019 Huanyu Zhang. All rights reserved.
//

#ifndef STL_hpp
#define STL_hpp

#endif /* STL_hpp */
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

class TestNode {
public:
	int x;
	int y;
	int dis;

	TestNode() {}

	TestNode(int x, int y, int dis) {
		this->x = x;
		this->y = y;
		this->dis = dis;

	}
};
