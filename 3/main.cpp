#include <iostream>

#include "./inc/linked_list.h"

using namespace ns_LLIST;

int main()
{
    LinkedList<int> li;
    li.push_back(5);
    li.push_back(5);
    li.push_back(6);
    li.push_back(6);
    
    LinkedList<int> ll = li;
    li.print();
    std::cout << "count = " << li.size() << std::endl;
    li.reverse();
    li.print();

    ll.unique();
    ll.print();
}
