#include "sequence4.h"
#include <cstdlib>
#include <assert.h>

namespace main_savitch_6B {

template <class Item>
sequence<Item>::sequence( ) {
    head_ptr = tail_ptr = cursor = precursor = nullptr;
    many_nodes = 0;
}

template <class Item>
sequence<Item>::sequence(const sequence& source){
    head_ptr = tail_ptr = cursor = precursor = nullptr;
    many_nodes = 0;
    if(source.head_ptr == nullptr) return;
    node<Item>* source_ptr = source.head_ptr;
    while (source_ptr != nullptr) {
        node<Item>* new_node = new node<Item>(source_ptr->data());
        if (head_ptr == nullptr) head_ptr = new_node;
        if (tail_ptr != nullptr) tail_ptr->set_link(new_node);
        tail_ptr = new_node;
        if (source_ptr == source.cursor) cursor = new_node;
        if (source_ptr == source.precursor) precursor = new_node;
        source_ptr = source_ptr->link();
    }
    many_nodes = source.many_nodes;
}

template <class Item>
void sequence<Item>::start(){
    cursor = head_ptr;
    precursor = nullptr;
}

template <class Item>
void sequence<Item>::advance(){
    if(cursor != nullptr) {
        precursor = cursor;
        cursor = cursor->link();
    } else if (head_ptr != nullptr){
        precursor = tail_ptr;
        cursor = nullptr;
    }
}
    

template <class Item>
void sequence<Item>::insert(const Item& entry){
    if(cursor == nullptr){
        cursor = new node<Item>(entry, head_ptr);
        head_ptr = cursor;
        precursor = nullptr;
        if (many_nodes == 0) tail_ptr = cursor;
    } else {
        cursor = new node<Item>(entry, cursor);
        if(precursor == nullptr) head_ptr = cursor;
        else precursor->set_link(cursor);
    }
    ++many_nodes;
}

template <class Item>
void sequence<Item>::attach(const Item& entry){
    if(cursor != nullptr){
        precursor = cursor;
        cursor->set_link(new node<Item>(entry, cursor->link()));
        if (cursor == tail_ptr) tail_ptr = cursor->link();
        cursor = cursor->link();
    } else {
        if(tail_ptr != nullptr){
            tail_ptr->set_link(new node<Item>(entry));
            precursor = tail_ptr;
            cursor = tail_ptr = tail_ptr->link();
        } else cursor = tail_ptr = head_ptr = new node<Item>(entry);
    }
    ++many_nodes;
}

template <class Item>
void sequence<Item>::remove_current( ){
    assert(is_item());
    if(cursor == head_ptr) {
        head_ptr = cursor->link();
        delete cursor;
        cursor = head_ptr;
        if (head_ptr == nullptr) tail_ptr = nullptr;
    } else {
        precursor->set_link(cursor->link());
        if(cursor == tail_ptr) tail_ptr = precursor;
        delete cursor;
        cursor = precursor->link();
    }
    --many_nodes;
}

template <class Item>
void sequence<Item>::operator =(const sequence& source){
    if(this == &source) return;
    if (source.head_ptr == nullptr) {
        head_ptr = tail_ptr = cursor = precursor = nullptr;
        many_nodes = 0;
        return;
    }
    else list_copy(source.head_ptr, head_ptr, tail_ptr);
    if(source.cursor == source.head_ptr) {
        precursor = nullptr;
        cursor = head_ptr;
    } else if (source.cursor == nullptr){
        cursor = source.cursor;
        precursor = source.precursor;
    } else {
        cursor = new node<Item>(source.cursor->data(), source.cursor->link());
        precursor = new node<Item>(source.precursor->data(), source.precursor->link());
    }
    many_nodes = source.many_nodes;
};

template <typename Item>
Item sequence<Item>::current( ) const {
    assert(is_item());
    return cursor->data();
};





}
