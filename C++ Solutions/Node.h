#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;


template<class T> class Node;

template<class T>
ostream& operator<<(ostream& os, const Node<T>& n);

template<class T>
class Node {
    Node<T> * next;
public:
    T data;
    explicit Node(const T& root, Node<T>* next = nullptr);
    Node(const Node& n);
    ~Node();
    Node<T>& operator=(const Node&);
    Node<T>* Next();
    const Node<T>* Next() const;
    void InsertAfter(Node<T>*);
    Node<T>* PopAfter();
    Node<T>* Append(const T&);
    const Node<T>* Find(const T&) const;
    bool Contains(const T&) const;
    friend ostream& operator<< <T>(ostream&, const Node<T>&);
};


template<class T>
Node<T>::Node(const T& root, Node<T>* next):data(root),next(next){}

template<class T>
Node<T>::Node(const Node& n): next(nullptr), data(n.data){
    for(Node* i=n.next; i != nullptr; i=i->next){
        this->Append(i->data);
    }
}

template<class T>
Node<T>::~Node()
{
    if(next == nullptr)
        return;
    delete next;
}

template<class T>
Node<T>& Node<T>::operator=(const Node& n){
    if(this == &n) return *this;
    this->data= n.data;
    delete this->next;
    this->next= new Node(*n.next);
    return *this;
}

template<class T>
Node<T>* Node<T>::Next()
{
    return this->next;
}

template<class T>
const Node<T> *Node<T>::Next() const {
    return this->next;
}

template<class T>
void Node<T>::InsertAfter(Node<T> *p)
{
    if(this->next != nullptr) throw;
    p->next = this->next;
    this->next = p;
}

// Deletes the node from the list and returns the deleted node
template<class T>
Node<T>* Node<T>::PopAfter()
{
    // store the next Node in a temporary Node
    Node<T>* tempNode = next;
    // check if there is a next node
    if(next != nullptr)
        next = next->next;

    return tempNode;
}

template<class T>
Node<T>* Node<T>::Append(const T& d) {
    Node<T>* n=this;
    while(n->next != nullptr)
        n= n->next;
    n->InsertAfter(new Node<T>(d));
    return n->next;
}

template<class T>
const Node<T>* Node<T>::Find(const T& d) const{
    for(const Node<T>* i= this; i != nullptr; i= i->next){
        if(i->data==d)
            return i;
    }
    return nullptr;
}

template<class T>
bool Node<T>::Contains(const T& d) const {
    return Find(d) != nullptr;
}

template<class T>
ostream& operator<<(ostream& os, const Node<T>& n) {
    for (const Node<T>* i= &n; i != nullptr; i= i->next) {
        os << i->data << " -> ";
    }
    os << "END";
    return os;
}



#endif //NODE_H
