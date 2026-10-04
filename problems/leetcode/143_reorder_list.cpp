class Solution {
        public:
                void reorderList(ListNode* head) {
                        if (!head) return;

                        /* Find the middle of the list */
                        ListNode* slow = head;
                        ListNode* fast = head->next;
                        while (fast && fast->next) {
                                slow = slow->next;
                                fast = fast->next->next;
                        }

                        /* Reverse the second half of the list */
                        ListNode* curr = slow->next;
                        ListNode* prev = nullptr;
                        slow->next = nullptr;

                        while (curr) {
                                ListNode* temp = curr->next;
                                curr->next = prev;
                                prev = curr;
                                curr = temp;
                        }

                        /* Merge the two halves */
                        ListNode* first = head;
                        ListNode* second = prev;
                        while (second) {
                                ListNode* t1 = first->next;
                                ListNode* t2 = second->next;
                                second->next = first->next;
                                first->next = second;
                                first = t1;
                                second = t2;
                        }

                }
};

/* MY SOLUTION (high time complexity) */
class Solution {
        public:
                void reorderList(ListNode* head) {
                        while (head->next != nullptr && head->next->next != nullptr) {
                                ListNode* pntr = head;
                                while (pntr->next->next != nullptr) {
                                        pntr = pntr->next;
                                }

                                ListNode* slastptr = pntr;
                                ListNode* lastptr = pntr->next;
                                lastptr->next = head->next;
                                head->next = lastptr;
                                slastptr->next = nullptr;

                                head = head->next->next;
                        }
                }
};
