class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        cur=1;
    }
    
    int popSmallest() {
        if(!minHeap.empty()){
            int s=minHeap.top();
            minHeap.pop();
            mp.erase(s);
            return s;
        }
        return cur++;
    }
    
    void addBack(int num) {
        if(num<cur && mp.find(num)==mp.end()){
            minHeap.push(num);
            mp.insert(num);
        }
    }
private:
    int cur;
    priority_queue<int, vector<int>, greater<>> minHeap;
    unordered_set<int>mp;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
