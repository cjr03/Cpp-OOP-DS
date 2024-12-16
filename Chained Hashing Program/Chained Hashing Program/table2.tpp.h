// FILE: table2.tpp.h
// TEMPLATE CLASS IMPLEMENTED: Table (see table2.h for documentation)
// INVARIANT for the Table ADT:
//   1. The number of records in the Table is in the member variable
//      total_records.
//   2. The actual records of the table are stored in a chained hash table.
//      An entry with key i is stored on the linked list with the head
//      pointer at data[hash(i)].

#include <assert.h> // Provides assert

template <class RecordType> size_t Table<RecordType>::hash_function(int key) const {
    return (key % TABLE_SIZE);
}

template <class RecordType> Table<RecordType>::Table( ) {
    total_records = 0;
    for (size_t i = 0; i < TABLE_SIZE; i++) hash_table[i] = nullptr;
}

template <class RecordType> Table<RecordType>::~Table( ) {
	total_records = 0;
    for (size_t i = 0; i < TABLE_SIZE; ++i) {
        Node<RecordType> *r;
        while (hash_table[i] != nullptr) {
            r = hash_table[i];
            hash_table[i] = hash_table[i]->link;
            delete r;
        }
    }
}

template <class RecordType> Table<RecordType>::Table(const Table<RecordType>& source) {
    total_records = 0;
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = nullptr;
        Node<RecordType>* c = source.hash_table[i];
        Node<RecordType>* p = nullptr;
        while (c != nullptr) {
            Node<RecordType>* n = new Node<RecordType>{c->data, c->link};
            if (p == nullptr) hash_table[i] = n;
            else p->link= n;
            p = n;
            c = c->link;
        }
    }
    total_records = source.total_records;
}

template <class RecordType> void Table<RecordType>::insert(const RecordType& entry){
    assert(entry.key >= 0);
    if (find_node(entry.key) == nullptr) {
        hash_table[hash_function(entry.key)] = new Node<RecordType>{entry, hash_table[hash_function(entry.key)]};
        total_records++;
    } else find_node(entry.key)-> data = entry;
}

template <class RecordType> void Table<RecordType>::remove(int key) {
    assert(key >= 0);
	Node<RecordType> *c;
	Node<RecordType> *p;
    c = find_node(key);
    if (c != nullptr) {
        if (c == hash_table[hash_function(key)]) hash_table[hash_function(key)] = c->link;
        else {
            p = hash_table[hash_function(key)];
            while (p->link != c) p = p->link;
            p->link = c->link;
        }
        delete c;
        --total_records;
    }
}

template <class RecordType> void Table<RecordType>::operator =(const Table<RecordType>& source) {
    if (this != &source) return;
    for (size_t i = 0; i < TABLE_SIZE; i++) {
        while (hash_table[i] != nullptr) {
            Node<RecordType>* h = hash_table[i];
            hash_table[i] = hash_table[i]->link;
            delete h;
        }
        Node<RecordType> *c = source.hash_table[i], *p = nullptr;
        while (c != nullptr) {
            p = new Node<RecordType>{c->data, hash_table[i]};
            hash_table[i] = p;
            c = c->link;
        }
    }
    total_records = source.total_records;
}

template <class RecordType> bool Table<RecordType>::is_present(int key) const {
    assert(key >= 0);
    return (find_node(key) != nullptr);
}

template <class RecordType> void Table<RecordType>::find(int key, bool& found, RecordType& result) const{
    found = is_present(key);
    if (found) result = find_node(key)->data;
}

template <class RecordType> Node<RecordType>* Table<RecordType>::find_node(int key) const {
    assert(key >= 0);
    for (Node<RecordType>* c = hash_table[hash_function(key)];; c = c->link) if (c==nullptr or (c->data.key==key)) return c;
}
