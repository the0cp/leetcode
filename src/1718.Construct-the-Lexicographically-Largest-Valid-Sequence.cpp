class Solution {
private:
    vector<int>res;
    vector<int>path;
    vector<bool>used;
public:
    bool backtracking(int cur, int n){
        if(cur==2*n-1){
            res=path;
            return true;
        }
        if(path[cur]>0)    return backtracking(cur+1,n);
        for(int i=n; i>0; i--){
            if(used[i]==true)  continue;
            if(i>1 && (cur+i>=2*n-1 || path[cur+i]>0)) continue;
            path[cur]=i;
            if(i>1) path[cur+i]=i;
            used[i]=true;
            if(backtracking(cur+1,n))   return true;
            // backtracking
            path[cur]=0;
            if(i>1) path[cur+i]=0;
            used[i]=false;
        }
        return false;
    }
    vector<int> constructDistancedSequence(int n) {
        path=vector<int>(2*n-1,0);
        used=vector<bool>(n+1,false);
        backtracking(0,n);
        return res;
    }
};
