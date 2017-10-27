/*
	Implement a Queue class, using a linked list of strings. Supply operations
	size, push, pop, front, and back, just like in the standard stack template.
*/

#include <iostream>
#include <string>

using namespace std;

struct Node
{

	string data;
	Node *next;
};

class Queue
{
  public:
	Queue();

	void push(string s);
	void pop();
	void print_queue() const;
	int size();
	string front();
	string back();

  private:
	Node *rear;
	Node *top;
	int sizeOfQueue;
};

Queue::Queue()
{
	rear = NULL;
	top = NULL;
	sizeOfQueue = 0;
}

void Queue::push(string s)
{
	Node *temp = new Node;
	temp->data = s;
	temp->next = NULL;

	if (top != NULL)
	{
		rear->next = temp;
	}
	else
	{
		top = temp;
	}

	rear = temp;
	sizeOfQueue++;
}

void Queue::pop()
{
	Node *temp;

	if (top != NULL)
	{
		temp = top;
		top = top->next;
		sizeOfQueue--;
		delete temp;
	}
	else
	{
		cout << "Queue is empty." << endl;
	}
}

string Queue::front()
{
	Node *temp = top;

	if (top != NULL)
	{
		return temp->data;
	}
	else
	{
		cout << "Queue is empty." << endl;
	}
}

string Queue::back()
{
	Node *temp = rear;

	if (rear != NULL)
	{
		return temp->data;
	}
	else
	{
		cout << "Queue is empty." << endl;
	}
}

int Queue::size()
{
	return sizeOfQueue;
}

void Queue::print_queue() const
{
	Node *temp = top;

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

	Queue queue;

	queue.push("George");
	queue.push("Bryan");
	queue.push("Hacker Harry");
	queue.push("McJimBob");

	cout << "Currently in queue: " << endl;
	queue.print_queue();

	cout << "First in queue: " << queue.front() << endl
		 << endl;
	cout << "Last in queue: " << queue.back() << endl
		 << endl;

	cout << queue.front() << " has been removed from the queue." << endl
		 << endl;
	queue.pop();

	cout << "The updated queue: " << endl;
	queue.print_queue();

	return 0;
}