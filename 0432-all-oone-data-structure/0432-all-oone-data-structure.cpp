#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class AllOne {
    struct Node {
        int count;
        unordered_set<string> keys;
        Node *prev, *next;
        Node(int cnt) : count(cnt), prev(nullptr), next(nullptr) {}
    };
    
    Node* head; 
    Node* tail; 
    unordered_map<string, Node*> keyNodeMap;  

    Node* addNodeAfter(Node* prevNode, int count) {
        Node* newNode = new Node(count);
        newNode->prev = prevNode;
        newNode->next = prevNode->next;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;
        return newNode;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    
public:
    AllOne() {
        head = new Node(0);  
        tail = new Node(0);  
        head->next = tail;
        tail->prev = head;
    }

    void inc(string key) {
        if (keyNodeMap.find(key) == keyNodeMap.end()) {
            if (head->next == tail || head->next->count != 1) {
                addNodeAfter(head, 1);
            }
            head->next->keys.insert(key);
            keyNodeMap[key] = head->next;
        } else {
            Node* currNode = keyNodeMap[key];
            int newCount = currNode->count + 1;
            currNode->keys.erase(key);
            
            if (currNode->next == tail || currNode->next->count != newCount) {
                addNodeAfter(currNode, newCount);
            }
            currNode->next->keys.insert(key);
            keyNodeMap[key] = currNode->next;
            
            if (currNode->keys.empty()) {
                removeNode(currNode);
            }
        }
    }

    void dec(string key) {
        Node* currNode = keyNodeMap[key];
        int newCount = currNode->count - 1;
        currNode->keys.erase(key);
        
        if (newCount == 0) {
            keyNodeMap.erase(key);
        } else {
            if (currNode->prev == head || currNode->prev->count != newCount) {
                addNodeAfter(currNode->prev, newCount);
            }
            currNode->prev->keys.insert(key);
            keyNodeMap[key] = currNode->prev;
        }
        
        if (currNode->keys.empty()) {
            removeNode(currNode);
        }
    }

    string getMaxKey() {
        if (tail->prev == head) {
            return "";  
        }
        return *(tail->prev->keys.begin());
    }

    string getMinKey() {
        if (head->next == tail) {
            return ""; 
        }
        return *(head->next->keys.begin());
    }
};
