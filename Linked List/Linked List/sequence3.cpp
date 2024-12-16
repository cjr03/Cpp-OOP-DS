//
//  sequence3.cpp
//  Linked List
//
//  Created by Cole Roberts on 3/9/23.
//

#include "sequence3.hpp"
#include "node1.hpp"
//#include "node1.cpp"
#include <cstdlib>
#include <assert.h>

namespace main_savitch_5 {

sequence::sequence( ) {
    head_ptr = nullptr;
    tail_ptr = nullptr;
    cursor = nullptr;
    precursor = nullptr;
    many_nodes = 0;
}

sequence::sequence(const sequence& source){
    if(source.many_nodes == 0) {
        head_ptr = nullptr;
        tail_ptr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
        return;
    }
    list_copy(source.head_ptr, head_ptr, tail_ptr);
    many_nodes = source.many_nodes;
    if (source.cursor == nullptr){
        cursor = source.cursor;
        precursor = source.precursor;
    } else if (source.precursor == nullptr){
        cursor = head_ptr;
        precursor = nullptr;
    } else if (source.cursor->link() == nullptr) {
        cursor = tail_ptr;
        node* tmp = new node(source.precursor->data(), source.precursor->link());
        precursor = tmp;
        delete tmp;
    } else {
        node* tmp1 = new node(source.cursor->data(), source.cursor->link());
        cursor = tmp1;
        delete tmp1;
        node* tmp2 = new node(source.precursor->data(), source.precursor->link());
        precursor = tmp2;
        delete tmp2;
    }
}

void sequence::start(){
    cursor = head_ptr;
    precursor = nullptr;
}

void sequence::advance(){
    assert(is_item());
    precursor = cursor;
    cursor = cursor->link();
    if(cursor == nullptr) precursor = nullptr;
}
    

void sequence::insert(const value_type& entry){
    if(head_ptr == nullptr){
        head_ptr = new node(entry, nullptr);
        cursor = head_ptr;
        tail_ptr = head_ptr;
        precursor = nullptr;
    } else if (head_ptr == cursor){
        tail_ptr = cursor;
        cursor = new node(entry, cursor);
        head_ptr = cursor;
    } else {
        cursor = new node(entry, cursor);
    }
    if (precursor != nullptr) precursor->set_link(cursor);
    ++many_nodes;
}

void sequence::attach(const value_type& entry){
    if(head_ptr == nullptr){
        head_ptr = new node(entry, tail_ptr);
        tail_ptr = head_ptr;
        cursor = head_ptr;
        precursor = nullptr;
    } else if (cursor == tail_ptr){
        precursor = cursor;
        tail_ptr = new node(entry, nullptr);
        cursor = tail_ptr;
        precursor->set_link(cursor);
    } else if (cursor == nullptr){
        cursor = new node(entry, nullptr);
        tail_ptr = cursor;
        precursor->set_link(cursor);
    } else {
        precursor = cursor;
        cursor = new node(entry, cursor->link());
        precursor->set_link(cursor);
    }
    ++many_nodes;
}

void sequence::remove_current( ){
    assert(is_item());
    if(precursor == nullptr) {
        head_ptr = cursor->link();
        cursor = head_ptr;
    } else if (cursor->link() == nullptr) {
        tail_ptr = precursor;
        tail_ptr->set_link(nullptr);
        cursor = nullptr;
        precursor->set_link(cursor);
    } else {
        cursor = cursor->link();
        precursor->set_link(cursor);
    }
    --many_nodes;
}

void sequence::operator =(const sequence& source){
    if(this == &source) return;
    if (source.head_ptr == nullptr) {
        head_ptr = nullptr;
        tail_ptr = nullptr;
        cursor = nullptr;
        precursor = nullptr;
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
        cursor = new node(source.cursor->data(), source.cursor->link());
        precursor = new node(source.precursor->data(), source.precursor->link());
    }
    many_nodes = source.many_nodes;
};

value_type sequence::current( ) const {
    return cursor->data();
};





}
