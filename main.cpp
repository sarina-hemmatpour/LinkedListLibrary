#include <iostream>
using namespace std;

#include "LinkedList.h"


int main() {

    LinkedList<string> linkedList=LinkedList<string>();

    linkedList.append("hello");
    linkedList.append("hi");
    linkedList.append("how you");

    linkedList.add("sssss",1);
//    cout<<(linkedList.getHead()->data);
//    cout<<(linkedList.getTail()->data);
//    cout<<endl<<(*linkedList.getHead()).data;

    LinkedList<int> h=LinkedList<int >();
    h.append(7);
//    h.append(linkedList);
//    cout<<(h.getHead()->data);



}