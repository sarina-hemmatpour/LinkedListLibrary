//
// Created by rolijesoo on 8/23/20.
//

#ifndef LINKLIST_LINKEDLIST_H
#define LINKLIST_LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
struct Node{
    T data;
    struct Node<T> *next=NULL;
    struct Node<T> *prev=NULL;
};

template <class T>
class LinkedList{

private:
    Node<T> *head;
    Node<T> *tail;

public:

    //constructor
    LinkedList() {
        this->head=NULL;
        this->tail=NULL;
    }


    //getter and setter
    Node<T>* getHead() {
        return head;
    }

    void setHead( Node<T> *head) {
        this->head = head;
    }

    Node<T>* getTail() const {
        return tail;
    }

    void setTail(Node<T> *tail) {
        LinkedList::tail = tail;
    }

    //functions
    Node<T> append(T data);
    Node<T> add(T data, int position);
    bool append(LinkedList<T> &list);
    bool isEmpty();
    int size();
    double min();
    double max();
    bool find(T element);
    T get(int index);
    Node<T> remove(int position);
    void reverse();
    void sort(bool type);
};

//sort
template <class T>
void LinkedList<T>::sort(bool type)
{
    if (size()==1 || size()==0)
    {
        return;
    }

    //save data in an arrayList
    T arrayList[size()];
    Node<T>* checkNode=head;
    for (int i = 0; i < size(); ++i) {
        arrayList[i]=checkNode->data;

        checkNode=checkNode->next;
    }

    //sort kardane array list be surate soudi
    int i,j,min,temp;
    for (i = 0; i < size()-1 ; ++i) {
        min=i;
        for ( j = i+1; j < size() ; ++j) {
            if (arrayList[j]<arrayList[min])
            {
                min=j;
                temp=arrayList[i];
                arrayList[i]=arrayList[min];
                arrayList[min]=temp;
            }
        }
    }

    if (type)
    {
        //soudi
        Node<T>* checkNode=head;
        for (int i = 0; i < size(); ++i) {
            checkNode->data=arrayList[i];

            checkNode=checkNode->next;
        }

        return;
    } else
    {
        //nozuli
        Node<T>* checkNode=head;
        for (int i = size()-1; i >= 0; i--) {
            checkNode->data=arrayList[i];

            checkNode=checkNode->next;
        }

        return;
    }

}

//reverse
template <class T>
void LinkedList<T>::reverse()
{
    if (size()==0 || size()==1)
    {
        return;
    }

    Node<T> *tempHead=head;
    Node<T> *tempTail=tail;

    if (size()==2)
    {

        head=tail;
        tail=tempHead;

        return;
    }

    Node<T> *checkNode=head;
    for (int i = 0; checkNode!=tail ; ++i) {

        Node<T> *tempNext=checkNode->next;

        checkNode->next=checkNode->prev;
        checkNode->prev=tempNext;

        checkNode=tempNext;

    }

    tail->next=tempTail->prev;
    tail->prev=NULL;

    head=tail;
    tail=tempHead;

    return;

}

//remove
template <class T>
Node<T> LinkedList<T>::remove(int position)
{
    if (position<size())
    {
        Node<T> *nodeToRemove=head;

        if (size()==1)
        {
            head=NULL;
            tail=NULL;

            return *nodeToRemove;
        }

        if (size()>1 && position==0){

            head->next->prev=NULL;
            head=head->next;

            return *nodeToRemove;
        }

        if (position==size()-1)
        {
            nodeToRemove=tail;

            tail->prev->next=NULL;
            tail=tail->prev;

            return *nodeToRemove;
        }


        nodeToRemove=head->next;
        for (int i = 1; nodeToRemove!=tail ; ++i) {

            if (i==position)
            {
                nodeToRemove->next->prev=nodeToRemove->prev;
                nodeToRemove->prev->next=nodeToRemove->next;

                return *nodeToRemove;
            }

            nodeToRemove=nodeToRemove->next;
        }
    }



}

//get
template <class T>
T LinkedList<T>::get(int index)
{
    if (index>=size())
    {
        return NULL;
    }

    if (index==size()-1)
    {
        return tail->data;
    }
    if (index==0)
    {
        return head->data;
    }

    Node<T> *checkNode=head;
    for (int i = 0; checkNode!=tail ; ++i) {

        if (index==i)
        {
            return checkNode->data;
        }

        checkNode=checkNode->next;

    }



}

//find
template <class T>
bool LinkedList<T>::find(T element)
{
    if (head==NULL)
    {
        return false;
    }
    if (size()==1)
    {
        if (head->data==element)
        {
            return true;
        }
    }

    Node<T> *checkNode=head;
    for (int i = 0; checkNode!=tail ; ++i) {

        if (checkNode->data==element)
        {
            return true;
        }

        checkNode=checkNode->next;

    }

    if (tail->data==element)
    {
        return true;
    }

    return false;
}


//is empty
template <class T>
bool LinkedList<T>::isEmpty()
{
    if (head==NULL)
    {
        return true;
    }

    return false;
}

//min
template <class T>
double LinkedList<T>::max()
{
    if (isEmpty())
    {
        return NULL;
    }

    if (size()==1)
    {
        double max=head->data;

        return max;
    }

    int max=head->data;
    Node<T> *checkNode=head;
    for (int i = 0; checkNode!=tail ; ++i) {

        if (max<checkNode->data)
        {
            max=checkNode->data;
        }

        checkNode=checkNode->next;

    }
    if (max<tail->data)
    {
        max=tail->data;
    }

    return max;

}


//min
template <class T>
double LinkedList<T>::min()
{
    if (isEmpty())
    {
        return NULL;
    }

    if (size()==1)
    {
        double min=head->data;

        return min;
    }

    int min=head->data;
    Node<T> *checkNode=head;
    for (int i = 0; checkNode!=tail ; ++i) {

        if (min>checkNode->data)
        {
            min=checkNode->data;
        }

        checkNode=checkNode->next;

    }
    if (min>tail->data)
    {
        min=tail->data;
    }

    return min;

}

//size
template <class T>
int LinkedList<T>::size()
{
    if (head==NULL)
    {
        return 0;
    }
    if (head==tail)
    {
        return 1;
    }

    int size=1;
    Node<T> *checkNode=head;
    for ( ; checkNode!=tail ; ++size) {
        checkNode=checkNode->next;
    }

    return size;

}


//add a node
template <class T>
Node<T> LinkedList<T>::append(T Data)
{
    //creating a new node
    Node<T> newNode;
    newNode.data=Data;

    if (head==NULL)
    {
        head=&(newNode);
        tail=&newNode;
    } else
    {
        tail->next=&(newNode);
        newNode.prev=tail;
        tail=&newNode;
    }

    return newNode;
}

//add a list at the end of another list
template <class T>
bool LinkedList<T>::append(LinkedList<T> &list) {

    if (list.head==NULL)
    {
        return false;
    }

    if (head==NULL)
    {
        head=list.head;
        tail=list.tail;

        //clear the given list
        list.tail=NULL;
        list.head=NULL;

        return true;
    }
    else
    {
        tail->next=list.head;
        list.head->prev=tail;

        tail=list.tail;

        //clear the given list
        list.head=NULL;
        list.tail=NULL;

        return true;
    }

    return false;

}

//add a node in a special position
template <class T>
Node<T> LinkedList<T>::add(T data, int position)
{
    //creating a new node
    Node<T> newNode;
    newNode.data=data;

    if(position<0)
    {
        return newNode;
    } else if (position!=0 && head==NULL)
    {
        return newNode;

    }
    else if (position==0 && head==NULL)
    {
        head=&newNode;
        tail=&newNode;
        return newNode;
    }
    else
    {

        if (position==0)
        {

            newNode.next=head;
            head->prev=&newNode;
            head=&newNode;
            return newNode;
        }
        else
        {
            Node<T> *checkNodeAfter=head->next;
            int check;
            for (int i = 1; checkNodeAfter != tail ; ++i) {
                if (i==position)
                {
                    Node<T> *checkNodeBefore= checkNodeAfter->prev;
                    checkNodeBefore->next=&newNode;

                    checkNodeAfter->prev=&newNode;

                    newNode.next=checkNodeAfter;
                    newNode.prev=checkNodeBefore;

                    return newNode;

                }
                checkNodeAfter = checkNodeAfter->next;
                check=i;
            }


            if (checkNodeAfter==tail &&position==check)
            {
                Node<T> *checkNodeBefore= checkNodeAfter->prev;
                checkNodeBefore->next=&newNode;

                checkNodeAfter->prev=&newNode;

                newNode.next=checkNodeAfter;
                newNode.prev=checkNodeBefore;

                return newNode;
            }
        }


    }

    return newNode;


}


#endif //LINKLIST_LINKEDLIST_H
