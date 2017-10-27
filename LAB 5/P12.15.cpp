/* 
	Implement a Stack class, using a linked list of strings. Supply operations
	size, push, pop, and top, just like in the standard stack template.
*/

#include <iostream>
#include <string>

using namespace std;

struct Node
{

	string data;
	Node *next;
};

class Stack
{
  public:
	Stack();

	int size();
	void push(string s);
	void pop();
	string top();
	void print_stack();

  private:
	Node *head;
	int sizeOfStack;
};

Stack::Stack()
{
	head = NULL;
	sizeOfStack = 0;
}

void Stack::push(string s)
{
	Node *temp = new Node;
	temp->data = s;
	temp->next = NULL;

	if (head != NULL)
	{
		temp->next = head;
	}

	sizeOfStack++;

	head = temp;
}

void Stack::pop()
{
	Node *temp;

	if (head != NULL)
	{
		temp = head;
		head = head->next;

		delete temp;
		sizeOfStack--;
	}
	else
	{
		cout << "Stack is empty." << endl;
	}
}

string Stack::top()
{
	if (head != NULL)
	{
		return head->data;
	}
	else
	{
		return "S";
	}
}

int Stack::size()
{
	return sizeOfStack;
}

void Stack::print_stack()
{
	Node *temp = head;

	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}

	cout << endl
		 << endl;
}

int main()
{

	Stack names;

	names.push("George");
	names.push("Bryan");
	names.push("Hacker Harry");
	names.push("McJimBob");

	cout << "List of names in the stack: " << endl;
	names.print_stack();

	cout << "Name on top of the stack: " << names.top() << endl
		 << endl;

	cout << "Size of the stack: " << names.size() << endl
		 << endl;

	cout << names.top() << " has been removed from the stack." << endl
		 << endl;
	names.pop();

	return 0;
}