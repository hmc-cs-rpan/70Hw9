/**
 * \file stringhash.cpp
 * \authors Ricky Pan, Amy Huang
 *
 * \brief Hash function for strings
 */

#include "stringhash.hpp"

using std::string;

// Hash Function Gallery
//
// These are the hash functions our group has examined, one of them is used
// as myhash (see later code in the file)
//
// All the code below is in an anonymous namespace, so these function names
// are hidden from other code.
namespace {


/**
 * DJB-2
 *
 * /remarks This hash function generates pseudo-random numbers quickly, 
 *          contributing to a fast runtime and a reasonable distribution of 
 *          hash values.
 *
 * /source
 *     http://stackoverflow.com/questions/19892609/djb2-by-dan-bernstein-for-c
 */
size_t djb2(const string& str)
{
    unsigned long hash = 5381;
    for (auto c : str) {
        hash = (hash << 5) + hash + c; /* hash * 33 + c */
    }
    return hash;
}


/**
 * FNV-1a
 *
 * /remarks 
 *
 * /source
 *     http://www.boost.org/doc/libs/1_38_0/libs/unordered/examples/fnv1.hpp
 */
size_t fnv1a(const string& str)
{
    size_t OffsetBasis = 14695981039346656037U;
    size_t FnvPrime = 1099511628211U;

    size_t hash = OffsetBasis;
    for(std::string::const_iterator it = str.begin(), end = str.end();
            it != end; ++it)
    {
        hash ^= *it;
        hash *= FnvPrime;
    }

    return hash;
}

/**
 * SDBM
 *
 * /remarks Scrambles bits, which causes a fairly uniform distribution 
 *          of keys and fewer splits.
 *
 * /source http://www.cse.yorku.ca/~oz/hash.html
 */
size_t sdbm(const string& str)
{
    unsigned int hash = 0;
    unsigned int i = 0;
    unsigned int len = str.length();

    for (i = 0; i < len; i++)
    {
        hash = (str[i]) + (hash << 6) + (hash << 16) - hash;
    }

    return hash;
}

} // end of anonymous namespace

size_t myhash(const string& str)
{
    return fnv1a(str);
}

// You don't have to fully understand this code, but it is used to provide a
// table used by stringhash-test.cpp, all you need to do is list the name
// of your hash function (for printing) and the actual function name from
// above.
std::initializer_list<HashFunctionInfo> hashInfo = {
    {"DJB2",        djb2},
    {"FNV-1a",      fnv1a},
    {"SDBM",        sdbm}
};

