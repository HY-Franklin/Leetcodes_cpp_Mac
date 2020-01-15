//
//  STL.cpp
//  Leetcodes
//
//  Created by 张环宇 on 10/11/19.
//  Copyright © 2019 Huanyu Zhang. All rights reserved.
//

#include "STL.hpp"



class testmultimap{
public:
    //multimap
    void test_multimap(){
            multimap<int,int> t;
            t.insert(pair<int, int>(3,10));
            t.insert(pair<int, int>(2,4));
            t.insert(pair<int, int>(12,0));
            t.insert(pair<int, int>(7,6));
            t.insert(pair<int, int>(8,5));
            
            multimap<int,int>::iterator iter;
//            for(iter=t.begin();iter!=t.end();iter++){
//                cout<<iter->first<<" "<<iter->second<<endl;
//            }
        
        multimap<string,string> p;
        p.insert(pair<string, string>("kindle book","1"));
        p.insert(pair<string, string>("echo show","2"));
        p.insert(pair<string, string>("kindle book","3"));
        p.insert(pair<string, string>("echo dot second generation","4"));
        multimap<string,string>::iterator it;
//        for(it=p.begin();it!=p.end();it++){
//            cout<<it->first<<" "<<it->second<<endl;
//        }
//        input:
//        echo dot second generation 4
//        echo show 2
//        kindle book 1
//        kindle book 3
//        cout << "endl";
        
        map<int, int> x; x.insert(pair<int, int>(9,3));
        cout<<x[9];
        
    }
};

class test_istringstream{
public:
    void output(){
        string txt="Jack and Jill went to the market to buy bread and cheese. Cheese is Jack’s and Jill’s favorite food.";
        istringstream iss(txt);
        string test;
        while(iss>>test){
//            iss>>test;//遇到空格停
            cout<<test<<endl;
        }
//        char i='2'; string j;  char add into string
//        j+=i;
        
    }
    
};

class list_test{   //不支持位置索引，只能用迭代器
public:
    void output(){
//        list<int> p(20);
//        p.emplace_front(2);
        std::list<int> values{ 1, -2, 7, 10};
        list<int> *l=new list<int>[5];  //create 5 lists
        list<int> *ll=new list<int>(5);  //create 1 list with first 5 null elements
            l[0].push_back(100); l->push_back(101);
            l[1].push_back(1);l[1].push_back(4);l[1].push_back(1);l[0].push_back(2);
//        p.merge(values);  ////两个容器中的元素都必须是升序
//        values.empty();   //return true
//        p.unique(); //移除连续的重复元素
//        p.sort(greater<int>()); p.sort(greater<>());
        
        list<int>::iterator it;
        for (it=l[1].begin(); it!=l[1].end(); it++) {
            cout<<*it<<" ";
        }
        
//        cout<<"p.size():"<<p.size()<<" ";
    }
};

class heap_test{
public:
    void output(){
        vector<int> v1 = {20, 30, 40, 25, 15};
        
        int i=40; int d;
        vector<int>::iterator it=find(v1.begin(), v1.end(), i);
        if (it!=v1.end()) {
            d=distance(v1.begin(), it);
        }
        cout<<d;
//        make_heap(v1.begin(), v1.end());  //max heap
//        sort_heap(v1.begin(), v1.end());        //ascending order
//        printv(v1);
        TestNode* t=new TestNode();
        t->x=2;
        t->y=3;
        t->dis=4;
        cout<<t->x;
        
    }
    
    void printv(vector<int> p){
        for (auto i : p) cout<<i<<" ";
    }
};

class PriorityQueue_test{
public:
    void output(){
        vector<int> v1 = {20, 30, 40, 25, 15}; vector<int> v2 = {123, 2, 51, 67, 12};
        queue<vector<int>> hp;hp.push(v1);hp.push(v2); hp.pop();
//        for(auto i:hp.front())
            cout<<hp.front()[0]<<"|";
//        cout<<hp.size();
        priority_queue<int> p={v1.begin(),v1.end()};
        priority_queue<int, vector<int>, greater<int>>q={v1.begin(),v1.end()}; //ascending order
        
    }
};


