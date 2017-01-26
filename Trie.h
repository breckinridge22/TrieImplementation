// File name: Trie.h
// Author: Breck Stodghill
// userid: stodghbs
// Email: breckinridge.s.stodghill@vanderbilt.edu
// Class: CS2201
// Assignment Number: 9
// Honor Statement:“I pledge on my honor that I have neither given nor received unauthorized aid on this examination.”
// Description:  This is the class declaration of the Trie class which is a lexicon container of words
// Last Changed:  Dec 2

#ifndef Trie_h
#define Trie_h


#include <stdio.h>
#include <string>
#include "TrieNode.h"

using namespace std;

typedef char ItemType;

class Trie
{
    
private:
    // TrieNode class and Data Members
    TrieNode myRoot;
    
    

public:
    //function members
    
    // default constructor
    Trie();
    
    // insert
    /*
     * Inserts the parameter word into the Trie
     * If word is empty doesnt insert into the Trie
     * Pre:
     * Post: Word is inserted into the Trie
     */
    void insert(const string & word);
    
    // loadFromFile
    /*
     * Inserts all words in the specified file into the Trie
     * Throws a std::invalid_argument exception if file cannot be opened
     * Pre:
     * Post: all of the words in the file are now in the Trie
     */
    void loadFromFile(const string & filename);
    
    // isWord
    /*
     * Returns true if the word is in the Trie, else returns false
     * Pre:
     * Post:
     */
    bool isWord(const string & word);
    
    // isPrefix
    /*
     * Returns true if word is a prefix of a word in the trie, else returns false
     * Pre:
     * Post:
     */
    bool isPrefix(const string & pre) const;
    
    // print
    /*
     * Prints all the words in the Trie, one per line, in alphabetical order
     * Pre:
     * Post: All words are printed in alphabetical order
     */
    void print() const;
    
    // wordCount
    /*
     * Counts all the words in the Trie and returns it
     * Pre:
     * Post:
     */
    size_t wordCount() const;
    

};




#endif /* Trie_hpp */
