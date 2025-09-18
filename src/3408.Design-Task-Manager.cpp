class TaskManager {
    unordered_map<int, pair<int, int>>mp;   // taskId -> priority+userId
    priority_queue<pair<int, int>>pq;       // priority, taskId
public:
    TaskManager(vector<vector<int>>& tasks) {
        mp.reserve(tasks.size());
        for(auto& t:tasks){
            mp[t[1]]={t[2], t[0]};
            pq.emplace(t[2], t[1]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId]={priority, userId};
        pq.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].first=newPriority;
        pq.emplace(newPriority, taskId);
    }
    
    void rmv(int taskId) {
        mp[taskId].first=-1;
    }
    
    int execTop() {
        while(!pq.empty()){
            auto [p,i]=pq.top();
            if(mp.count(i) && mp[i].first==p){
                pq.pop();
                int id=mp[i].second;
                mp.erase(i);
                return id;
            }
            pq.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
