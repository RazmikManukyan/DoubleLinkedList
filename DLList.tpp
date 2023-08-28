#include "DLList.h"

template<typename T>
DLList<T>::DLList()
    :m_head(nullptr)
{
}

template<typename T>
DLList<T>::DLList(const DLList<T> &oth):m_head(nullptr) {
    DLLNode<T>* curr = oth.m_head;
    while(curr != nullptr) {
        insert(size(), curr->data);
        curr = curr->next;
    }
}

template<typename T>
DLList<T>::DLList(DLList<T>&& oth) noexcept :m_head(oth.m_head) {
    oth.m_head = nullptr;
}

template<typename T>
DLList<T>& DLList<T>::operator=(const DLList<T>& oth) {
    if(this != & oth) {
        clear();
        DLLNode<T>* curr = oth.m_head;
        while(curr != nullptr) {
            insert(size(), curr->data);
            curr = curr->next;
        }
    }
    return *this;
}

template<typename T>
DLList<T>& DLList<T>::operator=(DLList<T> &&oth) noexcept{
    if(this != &oth) {
        clear();
        m_head = oth.m_head;
        oth.m_head = nullptr;
    }
    return *this;
}

template<typename T>
DLList<T>::~DLList() {
    clear();
}

template<typename T>
void DLList<T>::insert(int pos, const T &item) {
    assert(pos >= 0 && pos <= size());

    if(pos == 0) {
        m_head = new DLLNode<T>(item, m_head);
        if(m_head->next) {
            m_head->next->prev = m_head;
        }
    } else {
        DLLNode<T>* ptr = move_to_pos(pos - 1);
        auto* tmp = new DLLNode<T>(item, ptr->next, ptr);
        ptr->next = tmp;
        if(tmp->next) {
            tmp->next->prev = tmp;
        }
    }
}

template<typename T>
void DLList<T>::erase(int pos) {
    assert(!empty() && pos >= 0 && pos < size());

    if(pos == 0) {
        if(m_head->next == nullptr) {
            delete m_head;
            m_head = nullptr;
        } else {
            m_head = m_head->next;
            delete m_head->prev;
            m_head->prev = nullptr;
        }
    } else {
        DLLNode<T>* tmp = move_to_pos(pos);
        tmp->prev->next = tmp->next;
        if(tmp->next) {
            tmp->next->prev = tmp->prev;
        }
        delete tmp;
    }
}

template<typename T>
bool DLList<T>::empty() const {
    return (m_head == nullptr);
}

template<typename T>
T DLList<T>::get_value(int pos) {
    assert(pos >= 0 && pos < size());
    return move_to_pos(pos)->data;
}

template<typename T>
int DLList<T>::size() const {
    DLLNode<T>* tmp = m_head;
    int count = 0;
    while(tmp != nullptr) {
        ++count;
        tmp = tmp->next;
    }
    return count;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const DLList<T>& list) {
    DLLNode<T>* curr = list.m_head;
    while(curr != nullptr) {
        os << curr->data << " ";
        curr = curr->next;
    }
    return os;
}

template<typename T>
void DLList<T>::clear() noexcept {
    while(m_head != nullptr) {
        DLLNode<T>* tmp = m_head;
        m_head = m_head->next;
        if(m_head != nullptr) {
            m_head->prev = nullptr;
        }
        delete tmp;
    }
}

template<typename T>
DLLNode<T>* DLList<T>::move_to_pos(int i) {
    assert(i >= 0 && i < size());
    if(m_head == nullptr) {
        throw std::out_of_range("List is empty!");
    }
    DLLNode<T>* tmp = m_head;
    for(int j = 0; j < i; ++j) {
        if(tmp == nullptr) {
            throw std::out_of_range("Invalid position!");
        }
        tmp = tmp->next;
    }
    return tmp;
}