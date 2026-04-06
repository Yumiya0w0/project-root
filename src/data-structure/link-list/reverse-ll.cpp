class Node
{
private:
public:
    int data;
    Node* next;
    Node(int data){ this->data = data; };
    ~Node(){};
};


Node* reverseLink(Node* node)
{
    if(!node) return nullptr;
    Node* curr = node->next;
    Node* prev = node;
    prev->next = nullptr;
    while(curr)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

//recursive way
Node* reverseLink(Node* node)
{
    if(!node || !node->next) return node;
    Node* root = reverseLink(node->next);
    node->next->next = node;
    node->next = nullptr;
}


// detect cycle
bool hasCycle(Node* node)
{
    if(!node) return false;
    Node* fast = node;
    Node* slow = node;
    while(fast && fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}