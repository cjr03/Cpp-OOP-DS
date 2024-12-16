// FILE: Stack3.tpp.h
// TEMPLATE CLASS IMPLEMENTED: Stack<Item> (see Stack1.h for documentation)
// This file is included in the header file, and not compiled separately.
// INVARIANT for the Stack class:
//   1. The number of items in the Stack is in the member variable used.
//   2. The actual items of the Stack are stored in a partially-filled
//      array data[0]..data[used-1]. The Stack elements appear from the
//      bottom (at data[0]) to the top (at data[used-1]).

#include <cassert>  // Provides assert

namespace main_savitch_7A
{
	template <class Item>
	void Stack<Item>::push(const Item& entry) {
        assert(size( ) < CAPACITY);
        data[CAPACITY - 1 - used] = entry;
        ++used;
        return;
	}
	
	template <class Item> Item Stack<Item>::pop( ) {
        assert(used > 0);
        used--;
        return data[CAPACITY - 1 - used];
	}
	
	template <class Item> Item Stack<Item>::top( ) const {
        assert(used > 0);
        return data[CAPACITY - used];
	}
	
	template <class Item> Item Stack<Item>::peek(size_t index) {
        assert(used >= index and index > 0);
        return data[CAPACITY - 1 - used + index];
	}
}
