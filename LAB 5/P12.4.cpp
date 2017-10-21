/*
	Write a function merge that merges two lists into one, alternating elements
	from each list until the end of one of the lists has been reached, then appending
	the remaining elements of the other list. For example, merging the lists
	containing A B C and D E F G H should yield the list A D B E C F G H.
*/

#include <iostream>

using namespace std;

struct Node {

	char data;
	Node* next;
};

bool isEmpty(Node* head)
{
	return head == NULL;
}

void insertAsFirstElement(Node* &head, Node* &last, char c)
{
	Node *temp = new Node;
	temp->data = c;
	temp->next = NULL;
	head = temp;
	last = temp;
}

void insert(Node* &head, Node* &last, char c)
{
	if (isEmpty(head))
		insertAsFirstElement(head, last, c);
	else
	{
		Node *temp = new Node;
		temp->data = c;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

void print_list(Node* head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}

	cout << endl;
}

Node* merge_lists(Node* head1, Node* head2)
{
	Node* head = new Node;
	Node* current = head;

	while (head1 != NULL && head2 != NULL)
	{
		current->next = head1;
		current = current->next;
		head1 = head1->next;

		current->next = head2;
		current = current->next;
		head2 = head2->next;
	}

	if (head1 != NULL)
	{
		current->next = head1;
	}
	else
	{
		current->next = head2;
	}

	return head->next;
}

int main() {

	Node* head1 = NULL;
	Node* last1 = NULL;

	insert(head1, last1, 'A');
	insert(head1, last1, 'B');
	insert(head1, last1, 'C');

	Node* head2 = NULL;
	Node* last2 = NULL;

	insert(head2, last1, 'D');
	insert(head2, last1, 'E');
	insert(head2, last1, 'F');
	insert(head2, last1, 'G');
	insert(head2, last1, 'H');

	cout << "List 1: ";
	print_list(head1);

	cout << "List 2: "; 
	print_list(head2);

	Node* mList = merge_lists(head1, head2);

	cout << "List 1 & List 2 merged: ";
	print_list(mList);

	return 0;
}