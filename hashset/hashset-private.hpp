
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
HashSet<T>::HashSet(): 
	size_(0), buckets_(43), table_(new std::forward_list<T>[buckets_])
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
void HashSet<T>::insert(const T&)
{
	// check load
	// use hash function, add to end of linkedList
	++size_;
}

template <class T>
bool HashSet<T>::exists(const T&) const
{
	// use hash function, search linkedList
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
	return round(log(buckets_/43));
}

template <class T>
size_t HashSet<T>::collisions() const
{
	return 0;
}

template <class T>
size_t HashSet<T>::maximal() const
{
	return 0;
}

