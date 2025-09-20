class Router {
public:
    int binarySearchUpper(int timestamp, const pair<int, vector<int>>& search){
        int left = search.first;
        int right = search.second.size()-1;
        int ans = -1;
        while(left <= right){
            int mid = left+(right-left)/2;
            if(search.second[mid] <= timestamp){
                ans = mid;
                left = mid+1;

            } else {
                right = mid - 1;
            }
        }
        return ans; 
    }
    int binarySearchLower(int timestamp, const pair<int, vector<int>>& search){
        int left = search.first;
        int right = search.second.size()-1;
        int ans = -1;
        while(left <= right){
            int mid = left+(right-left)/2;
            if(search.second[mid] >= timestamp){
                ans = mid;
                right = mid - 1;

            } else {
                left = mid+1;
            }
        }
        return ans; 
    }
    struct hash_tuple {
        template <class T1, class T2, class T3>
        size_t operator()(
            const tuple<T1, T2, T3>& x)
            const
        {
            return get<0>(x)
                ^ get<1>(x)
                ^ get<2>(x);
        }
    };
    Router(int memoryLimit) {
        m_memoryLimit = memoryLimit;
        currentSize = 0;
        s.clear();
        q.clear();
        h.clear();
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        //check if packet exists
        if(s.find({source, destination, timestamp}) != s.end()){
            return false;
        }
        //check if over capacity
        if(currentSize == m_memoryLimit){
            //remove front
            forwardPacket();
        }

        //add it to the set
        s.insert({source, destination, timestamp});
        //push it to the front
        q.push_front({source, destination, timestamp});
        //add it to hash
        h[destination].second.push_back(timestamp);
        
        currentSize++;
        return true;
    }
    
    vector<int> forwardPacket() {
        if(currentSize == 0){
            return {};
        }
        //grab from back of deque and remove it
        auto [source, destination, timestamp] = q.back();
        q.pop_back();
        //remove it from the set
        auto it = s.find({source, destination, timestamp});
        s.erase(it);
        //remove it from hash
        h[destination].first++;
        currentSize--;
        return {source, destination, timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int count = 0;
        auto it = h.find(destination);
        if(it != h.end()){
            //get lower bound
            int low = binarySearchLower(startTime, h[destination]);
            int high = binarySearchUpper(endTime, h[destination]);
            return low < 0 || high < 0 ? 0 : high - low + 1;
        }
        return count;
    }
private:
    int m_memoryLimit;
    int currentSize;
    int left;
    unordered_set<tuple<int, int, int>, hash_tuple> s;
    deque<tuple<int, int, int>> q;
    //map destination to tuples where first is time, seocnd is source
    unordered_map<int, pair<int,vector<int>>> h;
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */