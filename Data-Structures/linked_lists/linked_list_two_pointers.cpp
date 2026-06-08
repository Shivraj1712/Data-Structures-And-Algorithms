#includ<iostream>
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class LinkedListTwoPointers {
public:
    // LC - 1721
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode * slow = head , * fast = head;
        int size = 0 ;
        ListNode * temp = head;
        while(temp != NULL){
            temp = temp -> next;
            size ++;
        }
        for(int i = 1 ; i < k ; i++) slow = slow -> next;
        for(int i = 1 ; i < size - k + 1 ; i++) fast = fast -> next;
        swap(slow->val,fast->val);
        return head;
    }
    // LC - 19
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0 ;
        ListNode * temp = head;
        while(temp != NULL){
            temp = temp -> next;
            size ++;
        }
        if(size == n){
            return head->next;
        }
        ListNode * slow = head, * fast = head;
        while(n > 0){
            fast = fast -> next;
            n--;
        }
        while(fast->next != NULL){
            fast = fast -> next;
            slow = slow -> next;
        }
        slow->next = slow->next->next;
        return head;
    }
    // LC - 143
    ListNode* revList(ListNode * head){
        ListNode * prev = nullptr, * curr = head, * next = nullptr;
        while(curr != nullptr){
            next = curr->next;
            curr->next= prev;
            prev = curr;
            curr= next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return ;
        ListNode * slow = head , * fast = head ;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow ->next;
        }
        ListNode * rev = slow->next;
        slow->next = nullptr;
        ListNode * l2 = revList(rev);
        ListNode * temp = head;
        bool first = false;
        ListNode * l1 = head->next;
        while(l1 && l2){
            if(first){
                temp->next= l1;
                l1 = l1 ->next ;
            }else{
                temp->next= l2;
                l2 = l2 ->next;
            }
            temp = temp->next;
            first = !first;
        }
        (l1 != nullptr) ? temp->next = l1 : temp->next = l2;
    }
    // LC - 61
    ListNode * reverseList(ListNode * head){
        ListNode * prev = nullptr, * curr = head , * next = nullptr;
        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev ;
            prev = curr ;
            curr = next ;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int size = 0 ;
        ListNode * t = head;
        while(t != nullptr){
            t = t -> next;
            size = size + 1;
        }
        if(!head || k == 0 || k % size == 0) return head;
        k = k % size;
        head = reverseList(head);
        ListNode * firstPart = head , * secondPart = head;
        ListNode * temp = head ;
        for(int i = 0 ; i < k - 1; ++i){
            temp = temp -> next;
        }
        secondPart = temp->next;
        temp->next = nullptr;
        firstPart = reverseList(firstPart);
        secondPart = reverseList(secondPart);
        temp = firstPart ;
        while(temp->next != nullptr) temp = temp->next;
        temp->next = secondPart ;
        return firstPart;
    }
    // LC - 141
    bool hasCycle(ListNode *head) {
        ListNode * fast = head , * slow = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};