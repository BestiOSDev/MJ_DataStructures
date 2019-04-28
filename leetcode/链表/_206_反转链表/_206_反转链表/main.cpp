//
//  main.cpp
//  _206_反转链表
//
//  Created by dzb on 2019/4/28.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#include <iostream>

struct ListNode {
public:
	ListNode *next;
	int data;
};


 ListNode * reverseList(ListNode *head) {
	if (head == NULL || head->next == NULL) return head;
	
	ListNode *newHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return newHead;
}

 ListNode * reverseList2(ListNode *head) {
	if (head == NULL || head->next == NULL) return head;
	
	ListNode *newHead = NULL;
	while (head != NULL) {
		ListNode *tmp = head->next;
		head->next = newHead;
		newHead = head;
		head = tmp;
	}
	
	return newHead;
}

int main(int argc, const char * argv[]) {
	
	return 0;
}
