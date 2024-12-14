/*
    Leetcode: 143. Reorder List
    https://leetcode.com/problems/reorder-list/submissions/1478614841/
    Time: O(n)
    Space: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next == NULL) return;
        ListNode *second = splitList(head);
        second = reverseList(second);
        merge(head, second);
    }
private:
    ListNode* splitList(ListNode *head){
        ListNode *slow = head, *fast = head, *prev = NULL;
        if(!head) return head;
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }

    ListNode* reverseList(ListNode *head){
        ListNode *prev = NULL, *curr = head, *temp;
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    void merge(ListNode *first, ListNode *second){
        while(first){
            ListNode  *p1 = first->next, *p2 = second->next;
            first->next = second;
            if(!p1) break;
            second->next = p1;
            first = p1;
            second = p2;
        }
    }
};
