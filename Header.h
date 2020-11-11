#ifndef LIST
#define LIST
#include <iostream>
using namespace std;

class List
{
private:
	class Node
	{
		int Data;
		class Node* Next;
		class Node* Prev;
		friend class List;
		Node(int data = 0)
		{
			Data = data;
			Next = NULL;
			Prev = NULL;
		};
		~Node() {};
	};
	Node* head;
	Node* last;
	Node* current;
	size_t size;
	Node* tail;
public:
	List() {
		head = NULL;
		last = NULL;
		current = NULL;
		size=0;
		tail=NULL;
	};
	void push_back(int data);
	void push_front(int data);
	void pop_back();
	void pop_front();
	void insert(int index, int data);
	int at(int index);
	void remove(int index);
	size_t get_size();
	void print_to_console();
	void clear();
	void set(int index, int data);
	bool isEmpty();
	int find_last(List lst2);
	~List() {};
};

//adding an item to the end of the list
void List::push_back(int data)
{
	if (size == 0) {
		head = new Node(data);
		tail = head;;
	}
	else {
		tail->Next = new Node(data);
		tail = tail->Next;
	}
	size++;
}

//adding an item to the beginning of the list
void List::push_front(int data)
{
	Node* elem = new Node(data);

	if (head == NULL)
	{
		elem->Next = NULL;
		elem->Prev = NULL;
		head = elem;
	}
	else
	{
		elem->Next = head;
		head->Prev = elem;
		elem->Prev = NULL;
		head = elem;
	}
	size++;
}

//removing the last item in the list
void List::pop_back()
{
	if (size == 0) return;

	if (size == 1) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node* current = head;
		while (current->Next != tail) {
			current = current->Next;
		}
		current->Next = nullptr;
		delete tail;
		tail = current;
	}
	size--;
}

//removing the first element of the list
void List::pop_front()
{
	current = head;
	head = head->Next;
	current->Prev = NULL;
	current->Next = NULL;
	delete current;
	head->Prev = NULL;
	size--;
}

//adding an item by index to the list
void List::insert(int index, int data)
{
	Node* elem = new Node(data);
	current = head;
	if (index == 0)
	{
		elem->Next = current;
		elem->Prev = NULL;
		current->Prev = elem;
		head = elem;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			current = current->Next;
		}
		elem->Next = current;
		elem->Prev = current->Prev;
		current->Prev = elem;
		current = elem->Prev;
		current->Next = elem;
	}
	size++;
}

//getting list item by index
int List::at(int index)
{
	current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}
	return current->Data;
}

//deleting a list item by index
void List::remove(int index)
{
	current = head;
	if (index == 0)
	{
		head = current->Next;
		current->Next->Prev = NULL;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	}
	else if (index == size - 1)
	{
		for (int i = 0; i < index; i++)
		{
			current = current->Next;
		}
		last = current->Prev;
		current->Prev->Next = NULL;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			current = current->Next;
		}
		current->Prev->Next = current->Next;
		current->Next->Prev = current->Prev;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;

	}
	size--;
}

//getting list size
size_t List::get_size()
{
	return size;
}

//outputting list items to the console
void List::print_to_console()
{
	current = head;
	cout << "|";
	while (1)
	{
		if (current == NULL)
		{
			cout << "NULL|" << "\n";
			break;
		}
		cout << current->Data << "|->|";
		current = current->Next;

	}
}

//removing all list items
void List::clear()
{
	int i = size;
	for (int j = 0; j < size; j++)
	{
		current = head;
		head = head->Next;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	}
	size = 0;
}

//replacing the element by index with the passed element
void List::set(int index, int data)
{
	current = head;
	for (int i = 0; i < index; i++)
	{
		current = current->Next;
	}
	Node* elem = new Node(data);

	if (index == 0)
	{
		elem->Next = current->Next;
		elem->Prev = NULL;
		current->Next->Prev = elem;
		current->Next = NULL;
		current->Prev = NULL;
		head = elem;
		delete current;
	}
	else if (index == size - 1)
	{
		current->Prev->Next = elem;
		elem->Next = NULL;
		elem->Prev = current->Prev;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	}
	else
	{
		elem->Next = current->Next;
		elem->Prev = current->Prev;
		current->Prev->Next = elem;
		current->Next->Prev = elem;
		current->Next = NULL;
		current->Prev = NULL;
		delete current;
	}
}

//checking if the list is empty
bool List::isEmpty()
{
	return (size != 0);
}

//find the last occurrence of another list in the list
int List::find_last(List lst2)
{
	int index = 0;
	current = head;
	int i = 0;
		while (1)
		{
			if (current == NULL)
			{
				break;
			}
			if (current->Data == lst2.head->Data) {
			index = i; 
			break; 
			}
			current = current->Next;
			i++;
		}
	return index;
}
#endif