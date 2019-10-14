#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#include <stack>
#include <queue>
#include <unordered_set>
#include <vector>


//Q3.2
template<class T>
struct Obj{
    T val;
    int min;
};

template<class T>
class StackMIn : public stack<Obj<T>>{
public:
    T min() const;
    void push(const T& i);
};

template<class T>
T StackMIn<T>::min() const {
    if(StackMIn<T>::empty())
        throw;
    return StackMIn<T>::top().min;
}

template<class T>
void StackMIn<T>::push(const T& i) {
    T m= StackMIn<T>::empty() ? i : std::min(i, min());
    Obj<T> o={i, m};
    stack<Obj<T>>::push(o);
}


//Q3.3 First-before the FOLLOW UP
template<class T>
class StackOfPlates{
        stack<stack<T>> plates_stack;
        int max_size;
public:
    explicit StackOfPlates(int max_size);
    void push(const T& i);
    T pop();
};

template<class T>
StackOfPlates<T>::StackOfPlates(int max_size): max_size(max_size){
    plates_stack.push(stack<T>());
}

template<class T>
void StackOfPlates<T>::push(const T &i) {
    if(plates_stack.top().size()==max_size)
        plates_stack.push(stack<T>());
    plates_stack.top().push(i);
}

template<class T>
T StackOfPlates<T>::pop() {
    if(plates_stack.empty())
        throw;
    T top= plates_stack.top().top();
    plates_stack.top().pop();
    if(plates_stack.top().empty())
        plates_stack.pop();
    return top;
}
//Q3.3 with the FOLLOW UP
template<class T>
class StackOfPlates2{
    vector<stack<T>> plates_stack;
    int max_size;
public:
    explicit StackOfPlates2(int max_size);
    void push(const T& i);
    T pop();
    T popAt(int index);
};
template<class T>
StackOfPlates2<T>::StackOfPlates2(int max_size): max_size(max_size){
    plates_stack.push_back(stack<T>());
}

template<class T>
void StackOfPlates2<T>::push(const T &i) {
    if(plates_stack.back().size()==max_size)
        plates_stack.push_back(stack<T>());
    plates_stack.back().push(i);
}

template<class T>
T StackOfPlates2<T>::pop() {
    if(plates_stack.empty())
        throw;
    T top= plates_stack.back().top();
    plates_stack.back().pop();
    if(plates_stack.back().empty())
        plates_stack.pop_back();
    return top;
}

template<class T>
T StackOfPlates2<T>::popAt(int index) {
    if(plates_stack.empty())
        throw;
    T top= plates_stack[index].top();
    plates_stack[index].pop();
    if(plates_stack[index].empty())
        plates_stack.erase(plates_stack.begin() + index);
    return top;
}

//Q3.4
template<class T>
class QueueVia2Stacks{
            stack<T> s1, s2;
            void switch_stacks();
        public:
            void add(const T& i);
            void remove();
            T& peek();
            bool is_empty();
        };

template<class T>
void QueueVia2Stacks<T>::add(const T &i) {
    s1.push(i);
}

template<class T>
bool QueueVia2Stacks<T>::is_empty() {
    return s1.empty();
}

template<class T>
void QueueVia2Stacks<T>::switch_stacks() {
    stack<T>& from= s1.empty() ? s2 : s1;
    stack<T>& to=   s1.empty() ? s1 : s2;
    while(!from.empty()){
        to.push(from.top());
        from.pop();
    }

}

template<class T>
void QueueVia2Stacks<T>::remove() {
    if(is_empty()) throw;
    switch_stacks();
    s2.pop();
    switch_stacks();
}

template<class T>
T &QueueVia2Stacks<T>::peek() {
    if(is_empty()) throw;
    switch_stacks();
    T& item= s2.top();
    switch_stacks();
    return item;
}

//Q3.5
void SortStack(stack<int>& s){
    if(s.empty()) return;
    stack<int> t;
    for(int i=0; i<s.size(); ++i) {
        int& max=s.top();
        s.pop();
        int counter= s.size();
        while (counter>i) {
            --counter;
            if (s.top() <= max) {
                t.push(s.top());
                s.pop();
            } else {
                t.push(max);
                max = s.top();
                s.pop();
            }
        }
        s.push(max);
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
    }
}

//Q3.6
class Animal{
    static int counter;
    protected:
    Animal():num(counter++){};
    public:
    virtual ~Animal()= default;
    int num;
    virtual string print() const{ return "a";};
    virtual Animal* clone() const=0;
    friend ostream& operator<< (ostream& os , const Animal& a){
        string s=a.print();
        os << a.print();
        return os;
    }
        ;
};
int Animal::counter=0;

class Dog :public Animal{
    string print() const override {
        return "Dog";
    }
    Dog* clone() const override{
        return new Dog(*this);
    }
};
class Cat :public Animal{
    string print() const override {
        return "Cat";
    }
    Cat* clone() const override{
        return new Cat(*this);
    }
};
class AnimalShelter{
    queue<Dog> dogs;
    queue<Cat> cats;
public:
    void enqueue(const Animal& a);
    Animal* dequeueAny();
    Animal dequeueAny();
    Dog dequeueDog();
    Cat dequeueCat();
};

void AnimalShelter::enqueue(const Animal &a) {
    auto* d= dynamic_cast<const Dog*>(&a);
    if(d){
        dogs.push(*d);
    }
    else{
        cats.push(dynamic_cast<const Cat&>(a));
    }
}

Animal AnimalShelter::dequeueAny() {
    Dog& d=dogs.back();
    Cat& c=cats.back();
    return d.num<c.num ? dequeueDog() : dequeueCat()
}


Animal* AnimalShelter::dequeueAny() {
    Dog& d=dogs.back();
    Cat& c=cats.back();
    auto& a=static_cast<Animal&>(d);
    if(d.num<c.num){
        dogs.pop();
    }
    else{
        a=static_cast<Animal&>(c);
        cats.pop();
    }
    return a.clone();
}

Dog AnimalShelter::dequeueDog() {
    Dog& d=dogs.back();
    dogs.pop();
    return d;
}

Cat AnimalShelter::dequeueCat() {
    Cat& c=cats.back();
    cats.pop();
    return c;
}

int main() {
    AnimalShelter as;

    as.enqueue(Dog());
    as.enqueue(Cat());
    as.enqueue(Dog());
    as.enqueue(Dog());
    as.enqueue(Cat());
    cout << *as.dequeueAny() << endl;
    cout << as.dequeueDog() << endl;
    cout << as.dequeueCat() << endl;

    }
