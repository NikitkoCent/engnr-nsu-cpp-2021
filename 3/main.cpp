#include <iostream>

#include "./inc/linked_list.h"

using namespace ns_LLIST;

int main()
{
    LinkedList<int> list = {5, 8, 8, 8, 10, 10};
    list.unique();
    LinkedList<int> list1 = {5, 8, 10};
    
    std::cout << "all okay" << std::endl;
    return 0;
}
