//
//  sequence4.h
//  Templates Program
//
//  Created by Cole Roberts on 3/17/23.
//

#ifndef sequence4_h
#define sequence4_h
#include "node2.h"  // Provides node class
#include <cstdlib> // Provides size_t
namespace main_savitch_6B {
    // TYPEDEF
    template <class Item>
    class sequence {
        public:
            // CONSTRUCTORS and DESTRUCTOR
            sequence( );
            sequence(const sequence& source);
            ~sequence( ){ };
            // MODIFICATION MEMBER FUNCTIONS
            void start( );
            void advance( );
            void insert(const Item& entry);
            void attach(const Item& entry);
            void operator =(const sequence& source);
            void remove_current( );
            // CONSTANT MEMBER FUNCTIONS
            size_t size( ) const { return many_nodes; }
            bool is_item( ) const { return (cursor != nullptr); }
            Item current( ) const;
        private:
            node<Item>* head_ptr;
            node<Item>* tail_ptr;
            node<Item>* cursor;
            node<Item>* precursor;
            size_t many_nodes = 0;
    };
} // End of namespace


#include "sequence4.tpp.h"

#endif /* sequence4_h */
