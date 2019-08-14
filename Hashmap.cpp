class MyHashMap {
private:
    int m_sizeMap = 10000;
    vector<list<pair<int, int>>> hashMap;
    
public:
    MyHashMap() {
        hashMap.resize(m_sizeMap);
    }
    
    // Constant lookup time on average, linear at worst
    
    // adds key and value into the hashmap
    void put(int key, int value) {
        int index = key % m_sizeMap;
        auto & list = hashMap[index];
        for(auto & i: list)
        {
            if(i.first == key) {
                i.second = value;
                return;
            }
        }
        hashMap[index].emplace_back(key,value);
    }
    
    // Gets value with associated key
    int get(int key) {
        int index = key % m_sizeMap;
        if(hashMap[index].empty()) return -1;
        auto & list = hashMap[index];
        for(auto & i:list)
        {
            if(key == i.first)
                return i.second;
        }
        return -1;
    }
    
    // Removes key and value 
    void remove(int key) {
        int index = key % m_sizeMap;
        auto & list = hashMap[index];
        for(auto & i:list)
        {
            if(key == i.first)
            {
                hashMap[index].remove(i);
                return;
            }
        } 
    }
};
