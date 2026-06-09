#include<iostream>
using namespace std;

class LinkedListManipulation{
public:
    // Linked list Maninpulation
    // LC - 206
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head ->next == nullptr) return head;
        ListNode * curr = head , * prev = nullptr, * next = nullptr;
        while(curr != nullptr){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev ;
    }
    // LC - 21
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr && list2 == nullptr) return nullptr;
        else if(list1 == nullptr && list2 != nullptr) return list2;
        else if(list1 != nullptr && list2 == nullptr) return list1;
        else{
            ListNode * dummy = new ListNode(-1);
            if(list1->val <= list2->val){
                dummy->next = list1;
                list1 = list1->next;
            }else{
                dummy->next = list2;
                list2 = list2->next;
            }
            ListNode * temp = dummy->next;
            while(list1 != nullptr && list2 != nullptr){
                if(list1->val <= list2->val){
                    temp->next = list1;
                    list1 = list1->next;
                }else{
                    temp->next = list2;
                    list2 = list2->next;
                }
                temp = temp->next;
            }
            temp->next = (list1 != nullptr) ? list1 : list2;
            return dummy->next;
        }
    }
    // LC - 1669
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode * temp = list1;
        for(int i = 0 ; i < a - 1; ++i){
            temp = temp->next;
        }
        ListNode * temp2 = list1;
        for(int i = 0 ; i < b ; ++i){
            temp2 = temp2 ->next;
        }
        ListNode * l2End = list2;
        while(l2End->next != nullptr) l2End = l2End -> next;
        l2End->next = temp2->next;
        temp2->next = nullptr;
        temp->next = nullptr;
        temp->next = list2;
        return list1;
    }
    // LC - 2181
    ListNode* mergeNodes(ListNode* head) {
        ListNode * dummy = new ListNode(-1);
        ListNode * temp = dummy;
        int sum = 0 ;
        ListNode * curr = head->next ;
        while(curr != nullptr){
            if(curr -> val == 0){
                temp -> next = new ListNode(sum);
                sum = 0;
                temp = temp -> next;
            }else{
                sum += curr -> val;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
    // LC - 24
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        ListNode * first = head , * second = head->next;
        ListNode * dummy = new ListNode(-1);
        ListNode * temp = dummy;
        while(first != nullptr && second != nullptr ){
            temp->next = second;
            first->next = second->next;
            second->next = first;
            temp = temp->next->next;
            if(temp->next != nullptr && temp->next->next != nullptr) {        
                first = temp->next;
                second = temp->next->next;
            }else{
                break;
            }
        }
        return dummy->next;
    }
    // LC - 3217
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> set(nums.begin(),nums.end());
        ListNode * dummy = new ListNode(-1);
        dummy->next = head;
        ListNode * curr = dummy->next, * temp = dummy;
        while(curr != nullptr){
            if(set.find(curr->val) != set.end()){
                temp->next = curr->next;
            }else{
                temp->next = curr;
                temp = temp -> next;
            }
            curr = curr->next;
        }
        return dummy->next;
    }
    // LC - 2
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0 ;
        ListNode * head = nullptr, * temp = nullptr;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry;
            if(head == nullptr) {
                ListNode * newNode = new ListNode(sum%10);
                head = newNode;
                temp = newNode;
            }else{
                temp->next = new ListNode(sum%10);
                temp = temp->next;
            }
            carry = sum / 10;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        temp->next = (l1) ? l1 : l2;
        return head;
    }
    // LC - 445
    ListNode* addTwoNumbersII(ListNode* l1, ListNode* l2) {
        ListNode * head = nullptr, * temp = nullptr;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x + y + carry ;
            if(head == nullptr){
                ListNode * newNode = new ListNode(sum % 10);
                head = newNode;
                temp = newNode;
            }else{
                temp->next = new ListNode(sum % 10);
                temp = temp->next;
            }
            carry = sum / 10;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        temp->next = (l1) ? l1 : l2;
        head = reverseList(head);
        return head;
    }
};