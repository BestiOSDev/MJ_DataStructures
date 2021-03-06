//
//  main.cpp
//  203_linkedlistremove
// 
//  Created by dzb on 2019/4/21.
//  Copyright © 2019年 dzb. All rights reserved.
//
///leetcode 203. 移除链表元素  https://leetcode-cn.com/problems/remove-linked-list-elements/


#include <iostream>

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
    
    int indexOf(int val) {
        Solution::ListNode *cur = m_head->next;
        for (int i = 0; i<m_size; i++) {
            if (val == cur->val) {
                return i;
            }
            cur = cur->next;
        }
        return -1;
    }
    
    void remove(int index) {
        Solution::ListNode *cur = NULL; //要删除的节点
        if (index == 0) {
            cur = node(index);
            m_head->next = cur->next;
        } else {
            ///待删除节点前一个节点
            Solution::ListNode *pre = node(index-1);
            cur = pre->next;
            pre->next = cur->next;
        }
        m_size--;
        delete cur; //删除节点 对于节点数据需要开发者自行管理内存
    }
    
    ListNode* removeElements(ListNode* head, int val) {
        
        int idx = indexOf(val);
        if (idx == -1) {
            return m_head;
        } else {
            remove(idx);
        }
        
        return removeElements(m_head,val);
    }
};

int main(int argc, const char * argv[]) {
  
    Solution *list = new Solution();
    list->add(1);
    list->add(2);
    list->add(6);
    list->add(3);
    list->add(4);
    list->add(5);
    list->add(6);

    list->removeElements(list->m_head,6);
    
    delete list;
    
    return 0;
}
