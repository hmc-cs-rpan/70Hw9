/**
 * \file hashset.hpp
 *
 * \author Ricky Pan, Amy Huang
 *
 * \brief Provides HashSet<T>, a set class template, using hash tables
 */

#ifndef HASHSET_HPP_INCLUDED
#define HASHSET_HPP_INCLUDED 1

#include <cstddef>
#include <forward_list>
#include <iostream>

template <class T>
class HashSet {
public:
	/**
	 * \brief Default constructor
	 *
	 */
	HashSet();

	~HashSet();

	HashSet(const HashSet&) = delete;
	HashSet operator=(const HashSet&) = delete;

	/**
	 * \brief Returns the size of the hash table
	 */
	size_t size() const;

	/**
	 * \brief Inserts an element into the hash table
	 *
	 * \param T& a templated object
	 *
	 */
	void insert(const T& value);

	/**
	 * \brief Checks if an element is in the hash table
	 *
	 * \param T& a templated object
	 *
	 * \returns true if T is present in the hash table
	 */
	bool exists(const T& value) const;

	/**
	 * \brief Returns the number of buckets in the hash table
	 *
	 */
	size_t buckets() const;

	/**
	 * \brief Returns the number of times the has table has been resized
	 *
	 */
	size_t reallocations() const;

	/**
	 * \brief Returns the number of times an insert into the current
	 * 		  hash table representation has found a non-empty bucket
	 *
	 */
	size_t collisions() const;

	/**
	 * \brief Returns the length of the longest chain in the hash table
	 *
	 */
	size_t maximal() const;

private:
	static constexpr double MAXLOAD = 10;
	static const size_t STARTING_BUCKETS = 8;

	size_t size_; 			// current num elements
	size_t buckets_; 		// current size of the hash table
	size_t reallocations_;	// number of resizes
	size_t maxChain_; 		// size of the longest chain so far
	size_t collisions_; 	// number of collisions so far
	std::forward_list<T> *table_; 

};

#include "hashset-private.hpp"

#endif
