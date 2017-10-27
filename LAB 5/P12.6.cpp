/*
	Write a member function List::reverse() that reverses the nodes in a list
*/
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

class List;
class Iterator;

class Node
{
  public:
	Node(string s);

  private:
	string data;
	Node *previous;
	Node *next;
	friend class List;
	friend class Iterator;
};

class List
{

  public:
	List();
	void push_back(string data);
	void insert(Iterator iter, string s);
	Iterator erase(Iterator iter);
	Iterator begin();
	Iterator end();
	void reverse();

  private:
	Node *first;
	Node *last;
	friend class Iterator;
};

class Iterator
{
  public:
	Iterator();

	string get() const;
	void next();
	void previous();
	bool equals(Iterator b) const;

  private:
	Node *position;
	List *container;
	friend class List;
};

Node::Node(string s)
{
	data = s;
	previous = NULL;
	next = NULL;
}

List::List()
{
	first = NULL;
	last = NULL;
}

void List::push_back(string data)
{
	Node *new_node = new Node(data);
	if (last == NULL)
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		new_node->previous = last;
		last->next = new_node;
		last = new_node;
	}
}

void List::insert(Iterator iter, string s)
{
	if (iter.position == NULL)
	{
		push_back(s);
		return;
	}

	Node *after = iter.position;
	Node *before = after->previous;
	Node *new_node = new Node(s);

	new_node->previous = before;
	new_node->next = after;
	after->previous = new_node;

	if (before == NULL)
		first = new_node;
	else
		before->next = new_node;
}

void List::reverse()
{
	Node *curr_node = first;
	Node *next_node = NULL;
	Node *prev_node = NULL;

	while (curr_node != NULL)
	{
		next_node = curr_node->next;
		curr_node->next = prev_node;
		prev_node = curr_node;
		curr_node = next_node;
	}

	first = prev_node;
}

Iterator List::erase(Iterator iter)
{
	assert(iter.position != NULL);
	Node *remove = iter.position;
	Node *before = remove->previous;
	Node *after = remove->next;
	if (remove == first)
		first = after;
	else
		before->next = after;

	if (remove == first)
		last = before;
	else
		after->previous = before;
	delete remove;
	Iterator r;
	r.position = after;
	r.container = this;
	return r;
}

Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

Iterator List::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}

Iterator::Iterator()
{
	position = NULL;
	container = NULL;
}

string Iterator::get() const
{
	assert(position != NULL);
	return position->data;
}

void Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

void Iterator::previous()
{
	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position->previous;
}

bool Iterator::equals(Iterator b) const
{
	return position == b.position;
}
int main()
{

	List staff;

	staff.push_back("Tom");
	staff.push_back("Dick");
	staff.push_back("Harry");
	staff.push_back("Juliet");

	Iterator pos;

	cout << "Original Order: " << endl;
	for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << endl;

	cout << endl;

	staff.reverse();

	cout << "In reverse order: " << endl;
	for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << endl;

	return 0;
}