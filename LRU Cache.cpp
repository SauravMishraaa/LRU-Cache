#include <iostream>
#include <unordered_map>
using namespace std;


class Node {
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};


class LRUCache {
private:
    unordered_map<int, Node*> cache;  // Hash map for O(1) lookup of cache items
    Node* head;  
    Node* tail;  
    int capacity;  
    int size;  

    void addNode(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* popTail() {
        Node* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; 
        }
        Node* node = cache[key];
        moveToHead(node);  
        return node->value;
    }

    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            
            Node* newNode = new Node(key, value);
            cache[key] = newNode;
            addNode(newNode);
            size++;

            if (size > capacity) {
                Node* tailNode = popTail();
                cache.erase(tailNode->key);
                delete tailNode;
                size--;
            }
        }
    }

    // Destructor 
    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};


int main() {
    LRUCache cache(2); 

    cache.put(1, 10);
    cache.put(2, 20);
    cout << "Get 1: " << cache.get(1) << endl;  

    cache.put(3, 30);  
    cout << "Get 2: " << cache.get(2) << endl;  

    cache.put(4, 40); 
    cout << "Get 1: " << cache.get(1) << endl; 
    cout << "Get 3: " << cache.get(3) << endl;  
    cout << "Get 4: " << cache.get(4) << endl;  

    return 0;
}
