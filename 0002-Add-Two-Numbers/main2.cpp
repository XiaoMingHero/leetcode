//
// Created by xuyanming on 2019-05-18.
//

/***
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// Using l1 as the result list
/// Time Complexity: O(n)
/// Space Complexity: O(n)

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *cur = NULL;
        int carried = 0;

        while (p1 || p2) {
            int a = p1 ? p1->val : 0;
            int b = p2 ? p2->val : 0;

            if (p1) {
                p1->val = (a + b + carried) % 10;
            } else {
                cur->next = new ListNode((a + b + carried) % 10);
                p1 = cur->next;
            }
            carried = (a + b + carried) / 10;

            cur = p1;
            p1 = p1 ? p1->next : NULL;
            p2 = p2 ? p2->next : NULL;
        }

        cur->next = carried ? new ListNode(1) : NULL;
        return l1;
    }
};

int main() {
    return 0;
}