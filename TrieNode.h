// File name: TrieNode.h
// Author: Breck Stodghill
// userid: stodghbs
// Email: breckinridge.s.stodghill@vanderbilt.edu
// Class: CS2201
// Assignment Number: 9
// Honor Statement:“I pledge on my honor that I have neither given nor received unauthorized aid on this examination.”
// Description:  This is the declaration of the TrieNode class
// Last Changed:  Dec 2

#ifndef TrieNode_h
#define TrieNode_h

#include <stdio.h>
#include <string>

using namespace std;

typedef char ItemType;
const size_t NUM_LETTERS = 26;

class TrieNode
{
    
private:// data members
    
    ItemType data;
    bool end;
    TrieNode* myArr[26];
    
public:
    
    // TrieNode function members
    
    // constructor
    TrieNode(char c, bool b);
    
    // copy ctor
    TrieNode(const TrieNode& rhs);
    
    // dtor
    ~TrieNode();
    
    // assignment operator
    const TrieNode& operator= (const TrieNode & rhs);
    
    // insert
    /*
     * Inserts the parameter word into the Trie
     * If word is empty doesnt insert into the Trie
     * Pre:
     * Post: Word is inserted into the Trie
     */
    void insert (const string& str);
    
    // isWord
    /*
     * Returns true if the word is in the Trie, else returns false
     * Pre:
     * Post:
     */
    bool isWord (const string& str) const;
    
    // isPrefix
    /*
     * Returns true if word is a prefix of a word in the trie, else returns false
     * Pre:
     * Post:
     */
    bool isPrefix (const string & str) const;
    
    // print
    /*
     * Prints all the words in the Trie, one per line, in alphabetical order
     * Pre:
     * Post: All words are printed in alphabetical order
     */
    void print (const string& str) const;
    
    // wordCount
    /*
     * Counts all the words in the Trie and returns it
     * Pre:
     * Post:
     */
    size_t wordCount() const;
};

typedef TrieNode* TrieNodePtr;


#endif /* TrieNode_hpp */
