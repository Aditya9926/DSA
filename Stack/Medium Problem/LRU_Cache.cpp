#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache {
public:

    class Node{
        public : 
        int key, val;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            val = v;
            next = prev = NULL;
        }
    };

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1); 
    unordered_map<int,Node*> m;
    int limit;

    void addnode(Node* newnode){
        Node* oldnext = head -> next;
        head->next = newnode;
        oldnext->prev = newnode;
        newnode->next = oldnext;
        newnode->prev = head; 
    }

    void deletenode(Node* oldnode){
        Node* oldprev = oldnode->prev;
        Node* oldnext = oldnode->next;
        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }

        Node* ansNode = m[key];
        int ans = ansNode->val;

        m.erase(key);
        deletenode(ansNode);

        addnode(ansNode);
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()){
            Node* oldnode = m[key];
            deletenode(oldnode);
            m.erase(key);
        }
        if(m.size() == limit){
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        Node* newnode = new Node(key, value);
        addnode(newnode);
        m[key] = newnode;
    }
};

int main(){
    LRUCache* cache = new LRUCache(2); // capacity 2

    cache->put(1, 1);
    cache->put(2, 2);
    cout << cache->get(1) << endl;    // returns 1

    cache->put(3, 3);                 // evicts key 2
    cout << cache->get(2) << endl;    // returns -1 (not found)

    cache->put(4, 4);                 // evicts key 1
    cout << cache->get(1) << endl;    // returns -1 (not found)
    cout << cache->get(3) << endl;    // returns 3
    cout << cache->get(4) << endl;    // returns 4

    return 0;
}