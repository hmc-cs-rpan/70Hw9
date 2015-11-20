# Overview


One of the most widely used spelling checkers in unix-like environments is`ispell`, written by our own Professor Kuenning. Is Professor Kuenning's fame and glory deserved? Just how hard *is* it to write a spelling checker?  It's time to find out!

In this assignment, you'll write a program almost entirely from scratch. The components of the program include:
* A hash function `myhash`. You won't need to write this from scratch, but your choice should be based on empirical data.
* A `HashSet<T>` class that can store arbitrary elements of type `T` in a hash table.
* A program `myspell` that uses your hash table to implement a spell-checker.

As with any piece of software, you'll need to test and document as you go.
 
# Reading
In addition to reading this assignment, we strongly recommend the following resources:

* The wiki page on [reading input](https://github.com/hmc-cs70-fall2015/Admin/wiki/ReadingInputHowTo)
* The wiki page on [processing command line arguments](https://github.com/hmc-cs70-fall2015/Admin/wiki/CommandLineArgumentHowTo)

# Steps
There are seven issues to complete for this assignment:

1. Required Documentation
1. Evaluate and Choose a Hash Function
1. Design your HashSet
1. Testing
1. Implement Your HashSet (Part 1)
1. Implement Your HashSet (Part 2)
1. Use Your Hash Table to Implement a Spell Checker


# Grading
Your submission will be graded as follows: 
* 15 points: correctness
* 10 points: completeness
* 6 points: style 
* 7 points: elegance
* 7 points: clarity 
* 5 points: peer review

See the [Grading Guidelines](https://github.com/hmc-cs70-fall2015/Admin/wiki/Grading-Guidelines) wiki page for more information about what we're looking for in each of those categories. 

# Footnote

Professor Kuenning's `ispell` implementation is based on the first `ispell` implementation, written by Pace Willisson, and is more properly referred to as *International Ispell*.   
