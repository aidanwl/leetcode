// Problem 2: Add Two Numbers (https://leetcode.com/problems/add-two-numbers)
// Date: 6/5/2026
//
// Solution Method: Since the numbers are given in reverse order and there are no leading zeros, to add the numbers we can simply add position by position and take note of any leading terms to add to the next value as well. This can be done in O(n) with a single while loop that checks if both inputs are at the nullptr. The tricky part is dealing with numbers of different lengths, but this can be handeled with if statements to see if any of them are at the nullptr, and if they are just add the number to the next position in our solution linked list. 

#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* solution = new ListNode();
        
        ListNode* head = solution;

        int carry = 0;
    
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int toAdd = 0;
            toAdd += carry;
            if (l1 == nullptr && l2 != nullptr) {
                toAdd += l2->val;
                l2 = l2->next;
            }
            if (l2 == nullptr && l1 != nullptr) {
                toAdd += l1->val;
                l1 = l1->next;
            }
            else if (l1 != nullptr && l2 != nullptr) {
                toAdd += l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            solution->val = toAdd % 10;
            carry = toAdd / 10;
            if (l1 != nullptr || l2 != nullptr || carry != 0) {
                ListNode* nextNode = new ListNode();
                solution->next = nextNode;
                solution = solution->next;
            }
        }
        
        return head;  

    }
};

