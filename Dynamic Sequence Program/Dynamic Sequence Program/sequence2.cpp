//
//  sequence2.cpp
//
//  Created by Cole Roberts on 2/15/23.
//

#include <iostream>
#include "sequence2.hpp"

namespace main_savitch_4 {

sequence::sequence(size_t initial_capacity) {
    data = new value_type[initial_capacity];
    used = 0;
    current_index = 0;
    capacity = initial_capacity;
}

sequence::sequence(const sequence& source) {
    data = new value_type[source.capacity];
    used = source.used;
    current_index = source.current_index;
    capacity = source.capacity;
    for (size_t i = 0; i < used; ++i) data[i] = source.data[i];
}

sequence::~sequence() {
    delete[] data;
}

void sequence::resize(size_t new_capacity) {
    if (new_capacity <= capacity) return;
    capacity = new_capacity;
    value_type* new_data {new value_type[new_capacity]};
    for (size_t i = 0; i < used; ++i) new_data[i] = data[i];
    delete[] data;
    data = new value_type[new_capacity];
    for (size_t i = 0; i < used; ++i) data[i] = new_data[i];
    delete[] new_data;
}

void sequence::start() {
    current_index = 0;
}

void sequence::advance() {
    ++current_index;
}

void sequence::insert(const value_type& entry) {
    if (used == capacity) resize(used + 10);
    for (size_t i = used; i > current_index; --i) data[i] = data[i-1];
    data[current_index] = entry;
    ++used;
}

void sequence::attach(const value_type& entry) {
    if (used == capacity) resize(used + 10);
    if (!is_item()) current_index = used - 1;
    ++current_index;
    for (size_t i = used; i > current_index; --i) data[i] = data[i-1];
    data[current_index] = entry;
    ++used;
}

void sequence::remove_current() {
    assert(is_item());
    for (size_t i = current_index; i < used - 1; ++i) data[i] = data[i + 1];
    --used;
}

size_t sequence::size() const {
    return used;
}

size_t sequence::max_size() const {
    return capacity;
}

bool sequence::is_item() const {
    return current_index < used;
}

sequence::value_type sequence::current() const {
    assert(is_item());
    return data[current_index];
}

void sequence::operator=(const sequence& source) {
    if (this == &source) return;
    if (capacity != source.capacity) {
        delete[] data;
        data = new double[source.capacity];
        capacity = source.capacity;
    }
    used = source.used;
    current_index = source.current_index;
    for (size_t i = 0; i < used; ++i) data[i] = source.data[i];
}

}
