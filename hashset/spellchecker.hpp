/**
 * \file spellchecker.hpp
 *
 * \author Amy Huang, Ricky Pan
 *
 * \brief Provides the spellchecker class.
 */

#ifndef SPELLCHECKER_HPP_INCLUDED
#define SPELLCHECKER_INCLUDED 1

#include "hashset.hpp"
#include <cstddef>

class SpellChecker {

public:
	/**
	 * \brief Constructor
	 *
	 * \params filename, a file containing the dictionary
	 *
	 * \details Populates a HashSet using the dictionary
	 */
	SpellChecker(const std::string& filename);

	SpellChecker() = delete;
	SpellChecker(const SpellChecker&) = delete;
	SpellChecker operator=(const SpellChecker&) = delete;

	/**
	 * \brief Prints the misspelled words in the given file
	 *        with a list of suggestions for each one
	 *
	 * \param filename, a file containing words
	 *
	 */
	 void spellCheck(std::string& filename) const;

private:
	HashSet<std::string> dict_;

};

#endif