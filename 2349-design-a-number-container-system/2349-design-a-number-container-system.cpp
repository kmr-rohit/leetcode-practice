class NumberContainers {
public:
        map<int, int> mp;
    map<int, set<int>> m;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        mp[index] = number;
        m[number].insert(index);
    }
    
    int find(int number) {
        if(m.find(number) == m.end()) return -1;
        else {
            auto it = m[number].begin();
            while(mp[*it] != number) {
                if(m[number].empty()) return -1;
                m[number].erase(it);
                it = m[number].begin();
            }
            return *it;
        }
    }
    
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */