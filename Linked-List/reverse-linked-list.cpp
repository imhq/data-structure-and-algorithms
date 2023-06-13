/*
Linked List - Reverse a Linked List

Given a pointer to the head node of a linked list, the task is to reverse the linked list. 
We need to reverse the list by changing the links between nodes.

Example: 
Original: 1->2->3->4->5->NULL
Reverse:  5->4->3->2->1->NULL
*/


#include<iostream>
using namespace std;

class Node{

public: 
	int data;
	Node *next;

	Node(){
		data = 0;
		next = NULL;
	}

	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

Node* createNode(int data){

	Node *tmpNode = new Node(data);

	return tmpNode;
}

Node* ReverseLinkedList(Node *head){

	Node* currentNode = head;

	while(currentNode->next != NULL)
	{
		
		Node* tmpNode = currentNode->next;
		currentNode->next = currentNode->next->next;
		tmpNode->next = head;
		head = tmpNode;
	}

	return head;
}

int main()
{	
	Node *temp = NULL;
	Node* head = new Node(1);
	head->next = createNode(2);
	head->next->next = createNode(3);
	head->next->next->next = createNode(4);
	head->next->next->next->next = createNode(5);

	cout<<"Linked List before Reversing:"<<endl;

	temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"Null"<<endl;

	head = ReverseLinkedList(head);

	cout<<"Linked List after Reversing:"<<endl;

	temp = head;
	while(temp != NULL)
	{
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<"Null"<<endl;

}