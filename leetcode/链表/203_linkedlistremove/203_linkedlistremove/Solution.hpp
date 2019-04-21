//
//  Solution.hpp
//  203_linkedlistremove
//
//  Created by dzb on 2019/4/21.
//  Copyright © 2019年 dzb. All rights reserved.
//

#ifndef Solution_hpp
#define Solution_hpp

#include <stdio.h>

class Solution {
    class ListNode {
        public:
            int val;
            ListNode *next;
            ListNode(int x) : val(x), next(NULL) {}
    };
    public:
    ListNode *m_head;
    int m_size;
    Solution() {
        m_head = new Solution::ListNode(0);
        m_size = 0;
    }
    void add(int val) {
        add(val,m_size);
    }
    ListNode *node(int index) {
        Solution::ListNode *pFind = m_head->next;
        for (int i = 0; i<index; i++) {
            pFind = pFind->next;
        }
        return pFind;
    }
    void add(int val,int index) {
        if (index == 0) {
            Solution::ListNode *pFind = node(index);
            Solution::ListNode *cur = new Solution::ListNode(val);
            cur->next = pFind;
            m_head->next = cur;
        } else {
            //待添加节点的前一个节点
            Solution::ListNode *pre = node(index-1);
            Solution::ListNode *cur = new Solution::ListNode(val);
            cur->next = pre->next;
            pre->next = cur;
        }
        m_size++;
    }
    
    int LinkedList<E>::indexOf(E element) {
        LinkedList::Node *cur = m_head->m_element;
        for (int i = 0; i<m_size; i++) {
            if (element == cur->m_element) {
                return i;
            }
            cur = cur->m_next;
        }
        return ELEMENT_NOT_FOUND;
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        
        return m_head;
    }
};

#endif /* Solution_hpp */
