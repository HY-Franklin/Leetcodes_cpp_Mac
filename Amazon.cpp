//
//  Amazon.cpp
//  Leetcodes
//
//  Created by 张环宇 on 10/11/19.
//  Copyright © 2019 Huanyu Zhang. All rights reserved.
//

#include "Amazon.hpp"


class MoviesonFlight{
public:
    int output(){
        vector<int> d={90, 85, 75, 60, 120, 150, 125};
        vector<vector<int>> ress;
        int m=INT_MIN;
        for (int i=0; i<d.size(); i++) {
            for (int j=0; j<d.size(); j++) {
                if (d[i]==d[j]) {
                    continue;
                }
                if (d[i]+d[j]>220) {
                    continue;
                }
                ress.push_back({d[i],d[j]});
            }
        }
        for (int i=0; i<ress.size(); i++) {
            m=max(m,ress[i][0]+ress[i][1]);
        }
        return m;
    }
};

class TreasureIslandI{
public:
    vector<vector<int>> output(){
        vector<vector<char>> p={
            {'O', 'O', 'O', 'O'},
            {'D', 'O', 'D', 'O'},
            {'O', 'O', 'X', 'O'},
            {'O', 'D', 'D', 'O'}
        };
        
        vector<vector<int>> res;vector<vector<int>> tmp;tmp.push_back({0,0});
        res.push_back({});
        queue<TINode*> q;q.push(new TINode(0,0,{{0,0}}));
        int n=p.size();int m=p[0].size();
        bool visited[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                visited[i][j]=false;
            }
        }
        visited[0][0]=true;
        while (!q.empty()) {
            TINode* t=q.front();q.pop();
            int x=t->x;int y=t->y; vector<vector<int>> ans=t->path;
            
           
            
            //down
            if (x+1<p.size()&&p[x+1][y]!='D'&&visited[x+1][y]!=true) {
                ans.push_back({x+1,y});
                q.push(new TINode(x+1,y,ans));
                visited[x+1][y]=true;
                if (p[x+1][y]=='X') {
                    return ans;
                }
            }
            
            //up
            if (x-1>=0&&p[x-1][y]!='D'&&visited[x-1][y]!=true) {
                ans.push_back({x-1,y});
                q.push(new TINode(x-1,y,ans));
                visited[x-1][y]=true;
                if (p[x-1][y]=='X') {
                    return ans;
                }
            }
            //left
            if (y-1>=0&&p[x][y-1]!='D'&&visited[x][y-1]!=true) {
                ans.push_back({x,y-1});
                q.push(new TINode(x,y-1,ans));
                visited[x][y-1]=true;
                if (p[x][y-1]=='X') {
                    return ans;
                }
            }
            //right
            if (y+1<p[0].size()&&p[x][y+1]!='D'&&visited[x][y+1]!=true) {
                ans.push_back({x,y+1});
                q.push(new TINode(x,y+1,ans));
                visited[x][y+1]=true;
                if (p[x][y+1]=='X') {
                    return ans;
                }
            }
        }
        

        
        
        
        return res;
    }
    
    

};

class KNearestPostOffices{
public:
    vector<vector<int>> output(){
        vector<vector<int>> p={
            {-16, 5},
            {-1,2},
            {4,3},
            {10,-2},
            {0,3},
            {-5,-9}
        };
       
        vector<int> me={0,0};
        int k=3;
        int dis;
        
        vector<vector<int>> res;
        multimap<int,vector<int>> t;
        
        for (int i=0; i<p.size(); i++) {
            dis=((me[0]-p[i][0])*(me[0]-p[i][0])+(me[1]-p[i][1])*(me[1]-p[i][1]));
            t.insert(pair<int, vector<int>>(dis,{p[i][0],p[i][1]}));
           
        }
        multimap<int,vector<int>> :: iterator it;
        int count=0;
        for (it=t.begin(); it!=t.end(); ++it) {
            
            if (count==k) {
                break;
            }
            count++;
            res.push_back(it->second);
        }
        
        return res;
    }
};

class AmazonSortCenter{
public:
    vector<int> output(){
        int truckSpace=90;
        int actualSpace=90-30;
        vector<int> packagesSpace={1, 10, 25, 35, 60};
        vector<int> res;
        vector<int> tmp;
        for (int i=0; i<packagesSpace.size(); i++) {
            int tm=0;
            tm=packagesSpace[i];
            tmp.clear();
            tmp.push_back(packagesSpace[i]);
            for (int j=i+1; j<packagesSpace.size(); j++) {
                if (i==j) {
                    continue;
                }
                
                tm+=packagesSpace[j];
                tmp.push_back(packagesSpace[j]);
                if (tm==actualSpace) {
//                    printv(tmp);
                    res=tmp;
                    return res;
                }else if(tm>actualSpace){
                    break;
                }
            }
        }
        return  res;
    }
    void printv(vector<int> p){
        for (auto i : p) cout<<i<<" ";
    }
};

class MostCommonWords{
public:
    vector<string> output(){
        string txt="Jack and Jill went to the market to buy bread and cheese. Cheese is Jack’s and Jill’s favorite food.";
        vector<string> exp={"and","he","the", "to", "is", "Jack", "Jill"};
        vector<string> res;
        vector<string> out;
        string tmp;string null;
        unordered_map<string, int> hp;
        
        //to lowercase
        for (int i=0; i<exp.size(); i++) {
            for (int j=0; j<exp[i].size(); j++) {
                exp[i][j]=tolower(exp[i][j]);
            }
        }
        
        for(auto i:txt){  //i:char
            
            if (isalpha(i)) {
                i=tolower(i);
                tmp+=i;  //string append char
            }else{
                if(count(exp.begin(),exp.end(),tmp)==0&&!tmp.empty()){
                res.push_back(tmp);
                }
                tmp=null;
            }
        }
        
        
        for(auto i:res){
            cout<<"[i]:"<<i<<endl;
            
            if(hp[i]==0||hp[i]==1){
                hp[i]+=1;
                cout<<hp[i]<<endl;
            }
            if (hp[i]>1) {
                out.push_back(i);
            }
        }
        return out;
    }
};

class Rolldice{
public:
    int output(){
        vector<int> p={1,2,3};
        int res=INT_MAX;
        int sum;
        int last;
        unordered_map<int,int> hp;
        hp.insert(pair<int, int>(1,6));
        hp.insert(pair<int, int>(2,5));
        hp.insert(pair<int, int>(3,4));
        hp.insert(pair<int, int>(4,3));
        hp.insert(pair<int, int>(5,2));
        hp.insert(pair<int, int>(6,1));
        for (int i=0; i<p.size(); i++) {
//            res=min(res,hp[i]*5);
//            cout<<"sum:"<<sum<<endl;
            
            last=7-hp[0];
            res=min(res,sum);
            sum=0;
            for (int j=0; j<p.size(); j++) {
                if (i==j) {
                    continue;
                }
                if (hp[last]==hp[j]) {
                    sum=+2;
                }else{
                    sum+=1;
                }
            }
        }
        return res;
    }
};



// A utility function to create a dummy tree shown in above diagram
//Node *createDummyTree()
//{
//    Node *root = newNode('A');
//    root->child[0] = newNode('B');
//    root->child[1] = newNode('C');
//    root->child[2] = newNode('D');
//    root->child[0]->child[0] = newNode('E');
//    root->child[0]->child[1] = newNode('F');
//    root->child[2]->child[0] = newNode('G');
//    root->child[2]->child[1] = newNode('H');
//    root->child[2]->child[2] = newNode('I');
//    root->child[2]->child[3] = newNode('J');
//    root->child[0]->child[1]->child[0] = newNode('K');
//    return root;
//} 

class SubtreewithMaximumAverage{
public:
    int output(){
        int res=1;
        //N-ary tree instantiation
//        Node* r22 =new Node(-2,{});
//        Node* r21 =new Node(4,{});
//        Node* r12 =new Node(2,{});
//        Node* r11 =new Node(1,{});
//        Node* r1 =new Node(-5,{r11,r12});
//        Node* r2 =new Node(13,{r21,r22});
//        Node* r3 =new Node(4,{});
//        Node* root =new Node(1,{r1,r2,r3});
        Node* r13=new Node(5,{});
        Node* r14=new Node(-1,{});
        Node* r12=new Node(21,{});
        Node* r11=new Node(-5,{});
        Node* root=new Node(1,{r11,r12,r13,r14});
        
        stack<Node*> p;
        int sum;
        int ave=INT_MIN;
        p.push(root);
        unordered_map<int, int> out;
        
        while (!p.empty()) {
            Node* t=p.top();p.pop();
            sum=t->val;
            if (!t->children.empty()) {
            for (int i=0; i<t->children.size(); i++) {
                sum+=t->children[i]->val;
                p.push(t->children[i]);
                }
            }
            int tmp=t->children.size()+1;
            sum=sum/tmp;
            ave=max(ave,sum);
            out.insert(pair<int, int>(sum,t->val));
            sum=0;
            
        }
       
       
        return out[ave];
    }
    
};

class MinCosttoConnectAllNodes{
public:
    int output(){
        int res;
        return res;
    }
};

class CellStateAfterNDays{
public:
    vector<int> output(){
        vector<int> p={1, 1, 1, 0, 1, 1, 1, 1};
        int day=2;
        vector<int> res;
        for (int i=0; i<day; i++) {
            
            
            for (int j=0; j<p.size(); j++) {
                if (j==0){
                    if (p[1]==0) {
                        res.push_back(0);
                        continue;
                    }else{
                        res.push_back(1);
                        continue;
                    }
                }
                if (j==p.size()-1) {
                    if (p[p.size()-2]==0) {
                        res.push_back(0);
                        continue;
                    }else{
                        res.push_back(1);
                        continue;
                    }
                }
                if (p[j-1]==p[j+1]) {
                    res.push_back(0);
                }else{
                    res.push_back(1);
                }
            }
            p=res;
            res.clear();
        }
        return p;
    }
};

class MoveObstacle{
public:
    int output(){
        vector<vector<int>> lot={
            {1, 0, 0},
            {1, 0, 1},
            {1, 0, 1}
        };
        int n=lot.size();int m=lot[0].size();
        vector<int>dx={-1,+1,0,0};
        vector<int>dy={0,0,-1,+1};
        queue<TNode*> q;    q.push(new TNode(0,0,0));
        bool visited[n][m];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                visited[i][j]=false;
            }
        }
        visited[0][0]=true;
        
        //BFS
        while (!q.empty()) {
            TNode* tmp=q.front();q.pop();
            int x=tmp->x;int y=tmp->y;int d=tmp->dis;
            if (lot[x][y]==9) {
                return tmp->dis;
            }
            //down
            if (x+1<lot.size()&&lot[x+1][y]!=0&&visited[x+1][y]!=true) {
                q.push(new TNode(x+1,y,d+1));
                visited[x+1][y]=true;
            }
            
            //up
            if (x-1>=0&&lot[x-1][y]!=0&&visited[x-1][y]!=true) {
                 q.push(new TNode(x-1,y,d+1));
                visited[x-1][y]=true;
            }
            //left
            if (y-1>=0&&lot[x][y-1]!=0&&visited[x][y-1]!=true) {
                 q.push(new TNode(x,y-1,d+1));
                visited[x][y-1]=true;
            }
            //right
            if (y+1<lot[0].size()&&lot[x][y+1]!=0&&visited[x][y+1]!=true) {
                 q.push(new TNode(x,y+1,d+1));
                visited[x][y+1]=true;
            }
        }
        
      
        
        return  -1;
    }
    
    void printvv(vector<vector<int>> p){
        for(auto i:p){
            for (auto j : i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }
    
 
    
    
};

//Optimize Memory Usage
class OptimizeMemoryUsage{
public:
    vector<vector<int>> output(){
        vector<int> f={1, 7, 2, 4, 5, 6};
        vector<int> b={3, 1, 2};
        int k=10;
        vector<vector<int>> res;
        
        for (int i=0; i<f.size(); i++) {
            
            for (int j=0; j<b.size(); j++) {
                if (f[i]+b[j]==k) {
                    res.push_back({i,j});
                    
                }
            }
        }
        return res;
        
    }
    
    
    
};

//Connect Ropes
class ConnectRopes{
public:
    int output(){
    
        int m1=INT_MAX;
        int m2=INT_MAX;
        int sum;
        vector<int> ropes={2, 2, 3, 3};
        vector<int> tmp;
        vector<int> cost;
        
        for (int j=ropes.size();j>0; j--) {
            
            if (ropes.size()==1) {
                break;
            }
        
            for (int i=0; i<ropes.size(); i++) {
                m1=min(ropes[i],m1);
            }
            
            int c=0;
            for (int i=0; i<ropes.size(); i++) {
                
                if (ropes[i]==m1&&c==0) {
                    c++;
                    continue;
                }
                m2=min(ropes[i],m2);
            }
            sum=m1+m2;
            tmp.push_back(sum);
            cost.push_back(sum);
            int cm1=0;int cm2=0;
            for (int i=0; i<ropes.size(); i++) {
                
                if (ropes[i]==m1&&cm1==0) {
                    cm1++;
                    continue;
                }
                if (ropes[i]==m2&&cm2==0) {
                    cm2++;
                    continue;
                }
                tmp.push_back(ropes[i]);
            }
            ropes=tmp;
            tmp.clear();
            m1=INT_MAX;
            m2=INT_MAX;
            
            
        }
        sum=0;
        for(auto i:cost) sum+=i;
        
        
        return sum;
    }
};

//Prioritize Orders
class PrioritizeOrders{
public:
    vector<vector<string>> output(){
        vector<string> p={
            {"Zid 93 12"},
            {"fp kindle book"},
            {"IOa echo show"},
            {"17g 12 256"},
            {"abl kindle book"},
            {"125 echo dot second generation"}
        };
        set<string> np;
        vector<vector<string>> res;
        istringstream iss; string tmp;string pretmp;
        multimap<string,string> t;
        for (int i=0; i<p.size(); i++) {
            iss.str(p[i]);  iss>>pretmp;   iss>>tmp; int c=0;
            //insert np NotPrime
            for (int k=0; k<tmp.size(); k++) {
                if (isdigit(tmp[k])) {
                    c++;
                    np.insert(p[i]);
                }
            }
            if (c==0) {
                //insert Prime to multimap
                t.insert(pair<string, string>(iss.str().substr(pretmp.size()+1),pretmp));
            }
            
            c=0;
            
        }

        multimap<string,string>::iterator preit; //afterit
        multimap<string,string>::iterator it; string tmpp;
        for (it=t.begin(); it!=t.end(); it++) {
//            cout<<it->first<<" "<<it->second<<endl;
            
            //check same
            preit=it; preit++;
            if (it->first==preit->first) {
                tmpp=it->second; tmpp.append(" ");tmpp.append(it->first);
                res.push_back({tmpp});
                tmpp.clear();
                tmpp=preit->second; tmpp.append(" ");tmpp.append(preit->first);
                res.back().push_back(tmpp);
                tmpp.clear();
                it++;
            }
            
            
            tmpp=it->second; tmpp.append(" ");tmpp.append(it->first);
            res.push_back({tmpp});
            
            tmpp.clear();
        }
        for(auto i:np){
            res.push_back({i});
        }
        
        return res;
    }
};

//Shopkeeper Sale
class ShopkeeperSale{
public:
    vector<vector<int>> output(){
        vector<int> p={2, 3, 1, 2, 4, 2};
        vector<vector<int>> res;vector<int> tmp;vector<int> index; int mi;  map<int, int> mp;int cj;int mx;
        for (int i=0; i<p.size(); i++) {
            mi=INT_MAX;mx=0;
            for (int j=i+1; j<p.size(); j++) {
                if (p[i]==p[j]&&j==i+1) {
                    tmp.push_back(0);cj=j;
                    break;
                }else if (p[i]>p[j]) {
                    mi=min(mi,p[j]);
                }
                else if (p[i]==p[j]&&j!=i+1) {
                    mi=min(mi,p[j]);
                }else if(p[i]<p[j]){
                    mx=1;
                }
                
                
            }
            if(p[i]>=mi){
                tmp.push_back(p[i]-mi); continue;
            }
            
            if (p[i]<mi&&cj!=i+1) {
                tmp.push_back(p[i]); index.push_back(i);continue;
            }else if(p[i]<mi&&mx==1){
                tmp.push_back(p[i]); index.push_back(i);
            }
            
        }
        //sum
        
        res.push_back(tmp);
        res.push_back(index);
        
        
        
        return res;
    }
    
    int sum(vector<int>& tmp){
        int res=0;
        for(auto i:tmp){
            res+=i;
        }
        return res;
    }
};

//Longest String Made Up Of Only Vowels  undone
class LongestStringMadeUpOfOnlyVowels{
public:
    int output(){
        string p="letsgosomewhere";
        string q="letsgosomewhere";
        vector<char> vo={'a','e','i','o','u'};  int res;int c,d=INT_MIN;
        vector<int> index;
        for (auto i : vo) {
            c=count(p.begin(), p.end(), i);
            d=max(c,d);
        }
        if (d==0) {
            return -1;
        }else if(d==1){
            return 1;
        }
        
        for (int m=0; m<p.size(); m++) {
            
            for (auto n : vo) {
                if (p[m]==n) {
                    index.push_back(m);
                }
            }
        }
        int cc=2;vector<int> tmp;
        for (int i=1; i<index.size(); i++) {
            
            if (index[i]==index[i-1]+1) {
                cc++; tmp.push_back(cc);
            }else{
                cc=1;
            }
            
        }
        
        cout<<endl;
        
        
        return res;
    }
    
};

//Favorite Genres  undone
class FavoriteGenres{
public:
    map<string,list<string>> output(){
        map<string,list<string>> user={
            {"David",{"song1", "song2", "song3", "song4", "song8"}},
            {"Emma",{"song5", "song6", "song7"}}
        };
        map<string,list<string>> genre={
            {"Rock",{"song1", "song3"}},
            {"Dubstep",{"song7"}},
            {"Techno",{"song2", "song4"}},
            {"Pop",{"song5", "song6"}},
            {"Jazz",{"song8", "song9"}}
        };
        map<string,list<string>> res;
        map<string,int> tmp;
        map<string,list<string>>::iterator ig;
        map<string,list<string>>::iterator iu;
        list<string>::iterator ul;
        
        for (iu=user.begin(); iu!=user.end(); iu++) {
            
            
                list<string> t=iu->second;
                for (ul=t.begin(); ul!=t.end(); ul++) {
                    cout<<*ul<<" ";
                }
            
            cout<<endl;
            
            
            
        }
        
        //iterator iu
//        for (iu=user.begin(); iu!=user.end(); iu++) {
//            list<string> t=iu->second;
//            for (ul=t.begin(); ul!=t.end(); ul++) {
//                cout<<*ul<<" ";
//            }
        
            
//        }
        
       
        
        
//        cout<<res.size();
        
        
        
        return res;
    }
};


