//
//  main.cpp
//  _141_环形链表
//
//  Created by dzb on 2019/4/28.
//  Copyright © 2019 大兵布莱恩特. All rights reserved.
//

#include <iostream>

struct ListNode {
	public :
	ListNode *next;
	int data;
};

bool hasCycle(ListNode *head) {
	if (head == NULL || head->next == NULL) return false;
	
	ListNode *slow = head;
	ListNode *fast = head->next;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
		
		if (slow == fast) return true;
	}
	
	return false;
}

int main(int argc, const char * argv[]) {
	
	
	
	return 0;
}
