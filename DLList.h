#ifndef DLLIST_DLLIST_H
#define DLLIST_DLLIST_H
#include <iostream>
#include <cassert>
#include "Node.h"

template<typename T>
class DLList {
private:
    DLLNode<T>* m_head;
public:
    DLList();
    DLList(const DLList<T>&);
    DLList(DLList<T>&&) noexcept;
    DLList<T>& operator=(const DLList<T>&);
    DLList<T>& operator=(DLList<T>&&) noexcept;
    ~DLList();

    void insert(int, const T&);
    void erase(int);
    bool empty() const;
    T get_value(int);
    int size() const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream&, const DLList<U>&);
private:
    void clear() noexcept;
    DLLNode<T>* move_to_pos(int);
};

#include "DLList.tpp"

#endif //DLLIST_DLLIST_H
