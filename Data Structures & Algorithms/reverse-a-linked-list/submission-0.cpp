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
    ListNode* reverseList(ListNode* head) {
        ListNode* currNode = head;
        ListNode* nextNode;
        if(currNode != NULL) nextNode = currNode->next;
        ListNode* prev  = NULL;
        while(currNode != NULL){
            currNode->next = prev;
            prev = currNode;
            currNode = nextNode;
            if(nextNode != NULL) nextNode = nextNode->next;
        }
        return prev;


    }
};
