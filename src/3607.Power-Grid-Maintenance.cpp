class  UnionFind{
private:
    vector<int>root, rank;
public:
    UnionFind(int N):root(N+1), rank(N+1){
        rank.assign(N+1, 1);
        iota(root.begin(), root.end(), 0);
    }

    int find(int x){
        return (x==root[x])?x:root[x]=find(root[x]);
    }

    bool merge(int x, int y){
        x=find(x);
        y=find(y);
        if(x==y)    return 0;
        if(rank[x]>rank[y]) swap(x,y);
        root[x]=y;
        if(rank[x]==rank[y])    rank[y]++;
        return 1;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        UnionFind G(c);
        for(auto&e:connections){
            G.merge(e[0], e[1]);
        }
        vector<set<int>>comp(c+1);
        for(int i=1; i<=c; i++){
            comp[G.find(i)].insert(i);
        }

        vector<int>ans;
        for(auto&q:queries){
            const int type=q[0];
            const int x=q[1];
            const int rootx=G.find(x);
            auto& cset=comp[rootx];
            if(type==2){
                cset.erase(x);
            }else{
                if(cset.empty())    ans.push_back(-1);
                else if(cset.count(x))  ans.push_back(x);
                else ans.push_back(*cset.begin());
            }
        }
        return ans;
    }
};
