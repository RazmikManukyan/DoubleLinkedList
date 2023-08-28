#ifndef DLLIST_NODE_H
#define DLLIST_NODE_H

template<typename T>
struct DLLNode{
    explicit DLLNode(const T& val, DLLNode<T>* n = nullptr, DLLNode<T>* p = nullptr)
    : data(val), next(n), prev(p)
    {
    }

    T data;
    DLLNode<T>* next;
    DLLNode<T>* prev;
};


#endif //DLLIST_NODE_H
