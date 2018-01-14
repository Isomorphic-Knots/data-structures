#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <functional>
#include <iterator>
#include <fstream>

namespace cop4530{

template <typename K, typename V>
class HashTable
{
public:
	HashTable(size_t = 101);			//constructor
	~HashTable();						//destructor
	bool contains(const K & k);			//checks if key k is in the hash table
	bool match(const std::pair<K,V> & kv);	//checks if if key pair is in table


	bool insert(const std::pair<K,V> & kv);	//add key value pair into table
	bool insert(const std::pair<K,V> && kv);//move version of insert
	bool remove(const K & k);			//delete key k, if deleted return true
	void clear();						//delete all elements in table(makeempty)

	size_t getsize();
	size_t bucketsize();

	bool load(const char * filename);	//load content from file to table.
	void dump();						//display entries in hash table

	//write all elements in the hash table into a file with the name filename
	//seperated by white space
	bool write_to_file(const char * filename);
    
private:
	void makeEmpty();		//delete all elements in hash table;
	void rehash();			//if elements > size.vector call rehash
	size_t myhash(const K & k);	//return index of vector entry where k should be
	unsigned long prime_below(unsigned long);
	void setPrimes(std::vector<unsigned long> &);


	static const unsigned int max_prime = 1301081;
	static const unsigned int default_capacity = 11;

	std::vector<std::list<std::pair<K,V>>> bucket;
	size_t currentsize;
};
#include "hashtable.hpp"
}
#endif









