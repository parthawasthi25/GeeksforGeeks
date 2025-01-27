//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache {
private:
    int capacity;
    list<pair<int, int>> cache; // Doubly linked list to maintain order
    unordered_map<int, list<pair<int, int>>::iterator> map; // Hashmap for fast lookup

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1; // Key not found
        }
        
        // Move the accessed key-value pair to the front (most recently used)
        auto it = map[key];
        int value = it->second;
        cache.erase(it);
        cache.push_front({key, value});
        map[key] = cache.begin();
        
        return value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            // If key exists, update the value and move to front
            auto it = map[key];
            cache.erase(it);
        } else if (cache.size() == capacity) {
            // If cache is full, remove the least recently used item
            auto last = cache.back();
            map.erase(last.first);
            cache.pop_back();
        }
        
        // Insert the new key-value pair at the front
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends