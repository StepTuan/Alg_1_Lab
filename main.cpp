#include "/Users/hollo/source/repos/Alg_3_1/Header.h"
#include <iostream>
using namespace std;

void main()
{
	List *lst1 = new List;
	lst1->push_back(2);
	lst1->push_back(3);
	lst1->push_front(1);
	lst1->push_back(4);
	lst1->push_back(5);
	lst1->print_to_console();
	cout << endl;
	lst1->pop_back();
	lst1->print_to_console();
	cout << endl;
	lst1->pop_front();
	lst1->print_to_console();
	cout << endl;
	lst1->insert(0, 555);
	lst1->print_to_console();
	cout << endl;
	cout << "Getting an item by index: " << lst1->at(3) << endl<<endl;
	cout << "Getting an item by index: " << lst1->at(0) << endl<<endl;
	lst1->remove(1);
	lst1->print_to_console();
	cout << endl;
	cout << "\n\n\n\n\n";
	lst1->set(1, 1000);
	lst1->print_to_console();
	cout << endl;
	List *lst2=new List;
	lst2->push_back(4);
	lst2->print_to_console();
	cout << endl;
	cout<< "the index of the last occurrence of an element of another list in the list: "
	<<lst1->find_last(*lst2)<<endl;
}
