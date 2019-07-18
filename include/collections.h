#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include<iostream>
#include<memory>
#include<string>
#include<utility>
#include<iterator>
#include<initializer_list>
#include<exception>
#include<vector>
#include<deque>
#include<stack>

class Collection {
public:
    Collection() = default;
    virtual std::ostream& print(std::ostream& os) const = 0;
    virtual ~Collection() = default;
};

template <typename T> class Bag : public Collection {
public:
    typedef typename std::vector<T>::size_type size_type;
    typedef typename std::vector<T>::iterator iter_type;
    typedef typename std::vector<T>::const_iterator c_iter_type;
    Bag();
    Bag(std::initializer_list<T> il);
    size_type size() const { return data->size(); }
    bool isEmpty() const { return data->empty(); }
    void add(const T& item) { data->push_back(item); }
    iter_type begin() { return data->begin(); }
    c_iter_type begin() const { return data->begin(); }
    iter_type end() { return data->end(); }
    c_iter_type end() const { return data->end(); }
    std::ostream& print(std::ostream& os) const;
private:
    std::shared_ptr<std::vector<T>> data;
};

template <typename T> class Queue : public Collection {
public:
    typedef typename std::deque<T>::size_type size_type;
    typedef typename std::deque<T>::iterator iter_type;
    typedef typename std::deque<T>::const_iterator c_iter_type;
    Queue(): data(std::make_shared<std::deque<T>>()) {}
    size_type size() const { return data->size(); }
    bool isEmpty() const { return data->empty(); }
    void enqueue(const T& item) { data->push_back(item); }
    T dequeue() const { T item = data->front(); data->pop_front(); return item; }
    std::ostream& print(std::ostream& os) const;
private:
    std::shared_ptr<std::deque<T>> data;
};

template <typename T> class Stack : public Collection {
public:
    typedef typename std::stack<T>::size_type size_type;
    Stack(): data(std::make_shared<std::stack<T>>()) {}
    size_type size() const { return data->size(); }
    bool isEmpty() const { return data->empty(); }
    void push(const T& item) { data->push(item); }
    T top() const { return data->top(); }
    T pop() const { T item = data->top(); data->pop(); return item; }
    std::ostream& print(std::ostream& os) const;
private:
    std::shared_ptr<std::stack<T>> data;
};


template <typename T>
Bag<T>::Bag(): data(std::make_shared<std::vector<T>>()) {}

template <typename T>
Bag<T>::Bag(std::initializer_list<T> il):
    data(std::make_shared<std::vector<T>>(il)) {}

template <typename T>
std::ostream& Bag<T>::print(std::ostream &os) const
{
    for(auto item : *data)
        os << item << " ";
    os << std::endl;
    return os;
}

template <typename T>
std::ostream& Queue<T>::print(std::ostream &os) const
{
    for(auto item : *data)
        os << item << " ";
    os << std::endl;
    return os;
}

template <typename T>
std::ostream& Stack<T>::print(std::ostream &os) const
{
    while (!this->isEmpty())
        os << this->pop() << " ";
    os << std::endl;
    return os;
}

#endif