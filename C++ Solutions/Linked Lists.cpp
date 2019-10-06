#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include "Node.h"
#include <unordered_set>

//Q2.1 Time=O(n), Memory=O(n)
void RemoveDups1(Node<int>& n){
    unordered_set<int> hashset;
    Node<int>* i=&n;
    while(i->Next() != nullptr) {
        if (hashset.find(i->Next()->data) == hashset.end()){
            hashset.insert(i->Next()->data);
            i = i->Next();
        }
        else{
            i->PopAfter();
        }
    }
}

//Q2.1 Time=O(n^2), Memory=O(1)
void RemoveDups2(Node<int>& n){
    Node<int>* i=&n;
    while(i->Next() != nullptr) {
        if (i->Next()->Next()->Contains(i->Next()->data)){
            i->PopAfter();
        }
        else{
            i = i->Next();
        }
    }
}

//Q2.2
const Node<int>& ReturnKthToLast(const Node<int>& n, int k){
    const Node<int> *i=&n, *runner=&n;
    for(;i->Next() != nullptr; i= i->Next()) {
        if (k)
            --k;
        else {
            runner = runner->Next();
        }
    }
    return *runner;
}

//Q2.3
void DeleteMiddleNode(Node<char>& n){
    Node<char> next(*n.Next());
    n.PopAfter();
    n=next;
}

//Q2.4
Node<int> Partiotion(const Node<int>& n, int p){
    Node<int> r(n.data);
    Node<int> *head=&r, *tail=&r;
    for(const Node<int>* i=n.Next();
        i != nullptr;
        i= i->Next()){
        if(i->data<p)
            head= new Node<int>(i->data, head);
        else{
            tail= tail->Append(i->data);
        }
    }
    return *head;
}

int main() {
    Node<int> l(3);
    l.Append(5);
    l.Append(8);
    l.Append(5);
    l.Append(10);
    l.Append(2);
    l.Append(1);
    cout << l << endl;
    cout << Partiotion(l, 5) << endl;

}

