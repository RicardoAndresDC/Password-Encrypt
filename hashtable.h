
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <fstream>
#include <string>
#include <sstream>

namespace cop4530
{
// max_prime is used by the helpful functions provided
// to you.
static const unsigned int max_prime = 1301081;
// the default_capacity is used if the initial capacity 
// of the underlying vector of the hash table is zero. 
static const unsigned int default_capacity = 11;
 
        template <class K, class V>
        class HashTable
        {

                public:
                HashTable(std::size_t size = 101);
                ~HashTable();
                bool contains(const K & k) const;
                bool match(const std::pair<K, V> &kv) const;
                bool insert(const std::pair<K, V> & kv);
                bool insert (std::pair<K,  V> && kv);
                bool remove(const K & k);
                void clear();
                bool load(const char *filename);
                void dump() const;
                bool write_to_file(const char *filename) const;
		std::size_t size() const;

                private:
                        size_t startingsize;
                        size_t currentsize;
                        std::vector<std::list<std::pair<K, V>>> table;
                        void makeEmpty();
                        void rehash();
                        std::size_t myhash(const K &k) const;
                        unsigned long prime_below(unsigned long) const;
                        void setPrimes(std::vector<unsigned long>&) const;
        };
#include "hashtable.hpp"
}
#endif
