#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class ListNode
{

public:
    int val;
    ListNode *next;



    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2) {

        if (head1 == NULL || head2 == NULL) {

            return head1 == NULL ? head2 : head1;
        }

        if (head1->val <= head2->val) {

            head1->next = mergeTwoLists(head1->next, head2);
            return head1;
        } else {

            head2->next = mergeTwoLists(head2->next, head1);
            return head2;
        }
    }
};  