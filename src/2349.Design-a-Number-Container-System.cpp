class NumberContainers {
    private:
        unordered_map<int,int>mp;
        unordered_map<int,priority_queue<int,vector<int>,greater<>>>idx;
    public:
        NumberContainers() {
            
        }
        
        void change(int index, int number) {
            mp[index]=number;
            idx[number].push(index);
        }
        
        int find(int number) {
            if(idx.find(number)!=idx.end())
                while(!idx[number].empty() && mp[idx[number].top()]!=number)    
                    idx[number].pop();
            if(!idx[number].empty())    return idx[number].top();
            else    return -1;
        }
    };
    
    /**
     * Your NumberContainers object will be instantiated and called as such:
     * NumberContainers* obj = new NumberContainers();
     * obj->change(index,number);
     * int param_2 = obj->find(number);
     */