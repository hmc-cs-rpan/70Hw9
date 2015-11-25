/**
 * \file hashset-test.cpp
 * \authors Amy Huang, Ricky Pan
 *
 * \brief Tests HashSet functionality.
 */

#include <ostream> // For std::ostream
#include <cstddef> // For size_t

#include "signal.h" // For signal
#include "unistd.h" // For alarm

#include <sstream>  // Convert char to string
#include <fstream>  // Read files

#include "stringhash.hpp"
#include "hashset.hpp"

template class HashSet<std::string>;

#include "gtest/gtest.h"

/// Tests basic methods before and after one insert
TEST(stringTestSuite, oneInsertTest)
{
    std::string testStr = "hello";
    HashSet<std::string> stringSet;

    EXPECT_FALSE(stringSet.exists(testStr));
    EXPECT_EQ(stringSet.size(), 0U);
    EXPECT_EQ(stringSet.buckets(), 8U);
    EXPECT_EQ(stringSet.reallocations(), 0U);
    EXPECT_EQ(stringSet.collisions(), 0U);
    EXPECT_EQ(stringSet.maximal(), 0U);

    stringSet.insert(testStr);
    EXPECT_TRUE(stringSet.exists(testStr));
    EXPECT_EQ(stringSet.size(), 1U);
    EXPECT_EQ(stringSet.buckets(), 8U);
    EXPECT_EQ(stringSet.reallocations(), 0U);
    EXPECT_EQ(stringSet.collisions(), 0U);
    EXPECT_EQ(stringSet.maximal(), 1U);
}

/// Tests large number of inserts
TEST(stringTestSuite, manyInsertTest)
{
    HashSet<std::string> stringSet;
    
    std::stringstream ss;
    std::string s;

    // Insert characters
    for (size_t ch = 32; ch < 127; ++ch) {
        ss << (char)ch;
        ss >> s;
        stringSet.insert(s);
    }

    // Check that all the characters have been inserted
    for (size_t ch = 32; ch < 127; ++ch) {
        ss << ch;
        ss >> s;
        EXPECT_TRUE(stringSet.exists(s));
    }

    EXPECT_EQ(stringSet.size(), 95U);
    EXPECT_EQ(stringSet.buckets(), 16U);
    EXPECT_EQ(stringSet.reallocations(), 1U);
}

/// Tests insert on strings from smallDict.words
TEST(stringTestSuite, smallDictStringInsertTest)
{
    HashSet<std::string> stringSet;

    std::string filename = "smalldict.words";
    
    // Open provided file
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Couldn't open file: " << filename << std::endl;
        exit(1);
    }

    // Read data from the file, one item per line
    std::string line;
    while(inFile.good()) {
        getline(inFile, line);
        if (inFile.fail())
            break;
        stringSet.insert(line);
    };

    EXPECT_EQ(stringSet.size(), 341U);
    EXPECT_EQ(stringSet.buckets(), 64U);
    EXPECT_EQ(stringSet.reallocations(), 3U);
}

/****************************
 * Boilerplate main function
 * **************************/

// Called if the test runs too long.
static void timeout_handler(int)
{
    // We go super-low-level here, because we can't trust anything in
    // the C/C++ library to really be working right.
    write(STDERR_FILENO, "Timeout occurred!\n", 18);
    abort();
}

/// Run tests
int main(int argc, char** argv)
{
    // Initalize testing environment
    ::testing::InitGoogleTest(&argc, argv);

    signal(SIGALRM, timeout_handler);   // Call this when the timer expires
    alarm(10);                          // set the timer at 10 seconds
    return RUN_ALL_TESTS();
}
