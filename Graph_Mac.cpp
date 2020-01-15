//
//  Graph_Mac.cpp
//  Leetcodes
//
//  Created by 张环宇 on 10/29/19.
//  Copyright © 2019 Huanyu Zhang. All rights reserved.
//

#include "Graph_Mac.hpp"

//886. Possible Bipartition
class Solution886 {
public:
    bool possibleBipartition() {
        int N=4;
        vector<vector<int>> dislikes{{1,2},{1,3},{2,4}};
        vector<vector<int>> adjList(N+1);
        vector<int> v(N+1);
        queue<int> q;
        if(dislikes.empty()) return false;
        if(dislikes.size()==1) return true;
        //create ajdList
        for(int i=0;i<dislikes.size();i++){
            adjList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjList[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        
        for (int i=1; i<=N; i++) {
            if (v[i]!=0) continue;
            v[i]=1;
            q.push(i);
            while (!q.empty()) {
                int t=q.front(); q.pop();
                for(auto cur:adjList[t]){
                    if (v[cur]==v[t]) {
                        return false;
                    }
                    if (v[cur]==0) {
                        v[cur]-=v[t];
                        q.push(cur);
                    }
                }
            }
        }
        return true;
    }
};

//785. Is Graph Bipartite?
class Solution785 {
public:
    bool isBipartite() {
        vector<vector<int>> graph={{1,3},{0,2},{1,3},{0,2}};
        queue<int>q;
        vector<int> v(graph.size());
        
        for (int i=0; i<graph.size(); i++) {
            if (v[i]!=0) continue;
            v[i]=1;
            q.push(i);
            while (!q.empty()) {
                int t=q.front(); q.pop();
                for (auto cur : graph[t]) {
                    if (v[cur]==v[t]) return false;
                    if (v[cur]==0) {
                        v[cur]-=v[t];
                        q.push(cur);
                    }
                }
            }
        }
        
        return true;
    }
};

//863. All Nodes Distance K in Binary Tree
class Solution863 {
public:
    vector<int> distanceK() {
        TreeNode* root=new TreeNode(3);  node(root);
        TreeNode* target=root->left;
        int K=2;
        unordered_map<TreeNode*, vector<TreeNode*>> g;
        vector<int> res;
        vector<TreeNode*> visited;
        queue<TreeNode*> q;
        list(NULL, root, g);
        int k=0;
        q.push(target); visited.push_back(target);
        
        while (!q.empty()&&k<=K) {
            
            int s=q.size();
            while (s--) {
                TreeNode* tmp=q.front();q.pop();
                visited.push_back(tmp);
                if (k==K) {
                    res.push_back(tmp->val);
                }
                for (auto cur : g[tmp]) {
                    if (count(visited.begin(),visited.end(),cur)) continue;
                    q.push(cur);
                }
            }
             k++;
        }
        return res;
    }
    
    //create adjlist
    void list(TreeNode* parent,TreeNode* child,unordered_map<TreeNode*, vector<TreeNode*>>& g){
        
        if (parent) {
            
            g[parent].push_back(child);
            g[child].push_back(parent);
        }
        if (child->left) {
            list(child, child->left, g);
        }
        if (child->right) {
            list(child, child->right, g);
        }
        
    }
    
    void node(TreeNode* root){
        root->left=new TreeNode(5);
        root->right=new TreeNode(1);
        root->left->left=new TreeNode(6);
        root->left->right=new TreeNode(2);
        root->left->right->left=new TreeNode(7);
        root->left->right->right=new TreeNode(4);
        root->right->left=new TreeNode(0);
        root->right->left=new TreeNode(8);
        
    }
};

//743. Network Delay Time  Bellman-ford
class Solution743 {
public:
    int networkDelayTime() {
        vector<vector<int>> times={{2,1,1},{2,3,1},{3,4,1}};
        int N=4;
        int K=2;
        vector<int> dis(N+1,INT_MAX);
        dis[K]=0;
        for (int i=1; i<N; i++) {
            for (auto t : times) {
                int pre=t[0]; int cur=t[1]; int w=t[2];
                
                if (dis[pre]!=INT_MAX&&(dis[cur]>dis[pre]+w)) {
                    dis[cur]=dis[pre]+w;
                }
                
            }
        }
        dis[0]=INT_MIN/2;
        int res=*max_element(dis.begin(), dis.end());
       
        return res==INT_MAX?-1:res;
    }
    
    
};

//684. Redundant Connection
class Solution684 {
public:
    vector<int> findRedundantConnection() {
        vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};
        unordered_map<int , vector<int>> adjList;
        vector<int> visited;
        for(auto e: edges){
            if (hasCycle(e[0], e[1], edges, adjList,visited)) {
                return {e[0],e[1]};
            }
            visited.clear();
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        
        
        return {};
    }
    
    //dfs detect cycle
    bool hasCycle(int u,int v,vector<vector<int>>& edges,unordered_map<int , vector<int>>& adjList,vector<int>& visited){
        if (u==v) return true;
        visited.push_back(u);
        for (auto i : adjList[u]) {
            if (count(visited.begin(),visited.end(),i)) {
                continue;
            }
            if (hasCycle(i, v, edges, adjList,visited)) {
                return true;
            }
        }
        return false;
        
    }
    
    //union find
    vector<int> output(){
        vector<vector<int>> edges={{1,2},{2,3},{3,4},{1,4},{1,5}};
        vector<int> m(2000,-1);
        for (auto i : edges) {
            int x=find(m, i[0]);
            int y=find(m, i[1]);
            if (x==y) {
                return i;
            }
            m[x]=y;
            
        }
        return {};
    }
    
    int find(vector<int>& m,int tmp){
        if (m[tmp]!=-1) {
            tmp=m[tmp];
        }
        return tmp;
        
    }
    
};

//261  Graph Valid Tree
class Solution261 {
public:
    //union find
    bool validTree() {
        int n=5;
//        vector<vector<int>> edges{{0,1},{1,2},{2,3},{1,3},{1,4}};
        vector<vector<int>> edges{{0,1},{0,2},{0,3},{1,4}};
        if (edges.empty()) return false;
        vector<int> m(n,-1);
        for (auto e : edges) {
            int x=find(m,e[0]); int y =find(m, e[1]);
            if(x==y) return false;
            m[x]=y;
        }
        return edges.size()==n-1;  //检查是否是全部连通
    }
    
    int find(vector<int>& m,int tmp){
        while (m[tmp]!=-1) {
            tmp=m[tmp];
        }
        return tmp;
    }
    
};

//990. Satisfiability of Equality Equations
class Solution990 {
public:
    bool equationsPossible() {
        vector<string> equations={"f==b","c==b","c==b","e!=f"};
        vector<int> roots('z'+1,-1);
        vector<string> visited;
        for (auto e: equations) {
            if (count(visited.begin(), visited.end(), e)) {
                continue;
            }
            visited.push_back(e);
            if (e[0]==e[3]&&e[1]=='=') {
                continue;
            }else if(e[0]==e[3]&&e[1]=='!'){
                return false;
            }
            int x=find(roots, e[0]);  int y=find(roots, e[3]);
            
            if (e[1]=='=') {
                roots[x]=y;
            }
        }
        for (auto x: equations) {
            if ((x[1]=='!')&&(find(roots, x[0])==find(roots, x[3]))){
                return false;
            }
        }
        return true;
    }
    
    int find(vector<int>& roots,int tmp){
        
        while (roots[tmp]!=-1) {
            tmp=roots[tmp];
        }
        return tmp;
    }
    int uf_find(vector<int> &uf, int i) {
        return uf[i] == -1 || uf[i] == i ? i : uf_find(uf, uf[i]);
    }
    
    
    
};
