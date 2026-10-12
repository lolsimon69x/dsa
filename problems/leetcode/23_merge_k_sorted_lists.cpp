class Solution {
        public:
                ListNode* mergeKLists(vector<ListNode*>& lists) {
                        // empty list edge case
                        if (lists.empty()) {
                                return nullptr;
                        }

                        // merging list till the list size is 1, that is, list is fully
                        // merged
                        while (lists.size() > 1) {
                                vector<ListNode*> temp;
                                for (int i = 0; i < lists.size(); i += 2) {
                                        ListNode* l1 = lists[i];
                                        ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                                        temp.push_back(mergeLists(l1, l2));
                                }
                                lists = move(temp);
                        }

                        return lists[0];
                }
        private:
                ListNode* mergeLists(ListNode* l1, ListNode* l2) {
                        // dummy pointing to the head of the list
                        ListNode dummy;
                        // node pointing to the tail of the list
                        ListNode* node = &dummy;

                        // adding nodes one by one in increasing order
                        while (l1 && l2) {
                                if (l1->val > l2->val) {
                                        node->next = l2;
                                        l2 = l2->next;
                                }
                                else {
                                        node->next = l1;
                                        l1 = l1->next;
                                }
                                node = node->next;
                        }

                        // merging the leftover nodes and 
                        // returning the head of the merged list
                        node->next = l1 ? l1 : l2;
                        return dummy.next;
                }
};
