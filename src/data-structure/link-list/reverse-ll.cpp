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

Node* mergeSorted(Node* head1, Node* head2)
{
    if(!head1) return head2;
    if(!head2) return head1;
    
    Node* head = (head1->data < head2->data ? head1 : head2);
    // Merge LL2 into LL1
    while(head1 || head2)
    {
        if(!head1->next) {
            head1->next = head2;
            break;
        }
        else if (!head2) break;
        else if(head1->data <= head2->data && head2->data < head1->next->data)
        {
            Node* tmpNode = head2->next;
            head2->next = head1->next;
            head1->next = head2;
            head1 = head1->next;
            head2 = tmpNode;
        }
    }

    return head;
}

Node* mergeSorted(Node* head1, Node* head2) {
    Node dummy(0); // 建立一個暫時的起點
    Node* tail = &dummy;

    while (head1 && head2) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // 將剩餘的部分直接接上
    tail->next = head1 ? head1 : head2;

    return dummy.next;
}
