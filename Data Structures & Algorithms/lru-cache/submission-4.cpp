class LRUCache {
    struct Node{
        int key,val;
        Node *prev,*next;
        Node(int k,int v) : key(k),val(v),prev(nullptr),next(nullptr){}
    };
    int cap;
    unordered_map<int,Node*> mp;
    Node *head,*tail;
    void remove(Node* n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    void insertFront(Node *n){
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next =n;
    }
public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache(){
        Node* cur = head;
        while(cur){
            Node* nx = cur->next;
            delete cur;
            cur =nx;
        }
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it==mp.end()) return -1;
        Node* n = it->second;
        remove(n);
        insertFront(n);
        return n->val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it!=mp.end()){
            Node *n = it->second;
            n->val=value;
            remove(n);
            insertFront(n);
            return;
        }
        if(mp.size()==cap){
        Node* lru = tail->prev;
            mp.erase(lru->key);
            remove(lru);
            delete lru;
        }
        Node* n = new Node(key,value);
        insertFront(n);
        mp[key] = n;
    }
};
