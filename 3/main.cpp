#include <iostream>

#include "./inc/linked_list.h"

using namespace ns_LLIST;

int main(int argc, char** argv)
{
    LinkedList<int> li = {1, 2, 3, 4, 5};
    LinkedList<int> li1(std::move(li));
    LinkedList<int> li2 = {1, 2, 3, 4, 5};
    std::cout << (li1 == li2);
}
