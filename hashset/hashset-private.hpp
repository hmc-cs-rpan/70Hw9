
/**
 * \file hashset-private.hpp
 *
 * \author Ricky Pan, Amy Huang
 *
 * \brief Implements HashSet<T>, a hash-table class template
 *
 * \remark There is no include-guard for this file, because it is
 *         only #included by hashset.hpp, inside hashset.hpp's
 *         own include guard.
 */


// Includes required for your templated code go here

#include <cmath>

// Templated code for member functions goes here
template <class T>
HashSet<T>::HashSet() : size_(0), buckets_(HashSet::STARTING_BUCKETS),
	table_(new std::forward_list<T>[buckets_])
{
	// Nothing to do here
}

template <class T>
HashSet<T>::~HashSet()
{
	delete[] table_;
}

template <class T>
size_t HashSet<T>::size() const
{
	return size_;
}

template <class T>
void HashSet<T>::insert(const T& value)
{
	// If load is too large, resize
	if(size_/buckets_ >= MAXLOAD) {
		std::forward_list<T> *newTable = new std::forward_list<T>[buckets_*2];
		
		// Copy all items to new hash table
		for(size_t ind = 0; ind < buckets_; ++ind) {

			for(auto iter = table_[ind].begin(); 
				iter != table_[ind].end(); ++iter) {

				size_t newHashKey = ::myhash(value) % (buckets_*2);
				newTable[newHashKey].push_front(value);
			}
		}
		table_ = newTable;
	}

	size_t hashKey = ::myhash(value) % buckets_;

	// Increment collisions, if necessary
	if (!table_[hashKey].empty()) {
		++collisions_;
	}

	// Insert new value into hash table
	table_[hashKey].push_front(value);
	
	++size_;
}

template <class T>
bool HashSet<T>::exists(const T& value) const
{
	// Use hash function, search linkedList
	size_t hashKey = ::myhash(value) % buckets_;
	for(auto iter = table_[hashKey].begin(); 
		iter != table_[hashKey].end(); ++iter) {
		if(value == *iter) {
			return true;
		}
	}
	return false;
}

template <class T>
size_t HashSet<T>::buckets() const
{
	return buckets_;
}

template <class T>
size_t HashSet<T>::reallocations() const
{
	return round(log(buckets_/STARTING_BUCKETS));
}

template <class T>
size_t HashSet<T>::collisions() const
{
	return collisions_;
}

template <class T>
size_t HashSet<T>::maximal() const
{
	return maxCluster_;
}

