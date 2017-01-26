// File name: Trie.cpp
// Author: Breck Stodghill
// userid: stodghbs
// Email: breckinridge.s.stodghill@vanderbilt.edu
// Class: CS2201
// Assignment Number: 9
// Honor Statement:“I pledge on my honor that I have neither given nor received unauthorized aid on this examination.”
// Description:  This is the class definition of the Trie class which is a lexicon container of words
// Last Changed:  Dec 2


#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>


#include "Trie.h"
#include "TrieNode.h"

// default constructor
Trie::Trie():myRoot(' ', false){}

// insert
/*
 * Inserts the parameter word into the Trie
 * If word is empty doesnt insert into the Trie
 * Pre:
 * Post: Word is inserted into the Trie
 */
void Trie::insert(const string & word){
    myRoot.insert(word);
}







// loadFromFile
/*
 * Inserts all words in the specified file into the Trie
 * Throws a std::invalid_argument exception if file cannot be opened
 * Pre:
 * Post: all of the words in the file are now in the Trie
 */
void Trie::loadFromFile(const string & filename)
{
    // read a file and process it
    // as I read each word from the file i want to insert it into the Trie
    
    // open the file
    
    string str;
    ifstream file(filename.c_str());
    // Do error checking here
    if (!file) {
        throw std::invalid_argument("File Cannot be opened");
    }
    // read the file and insert into the Trie
    while (file >> str){
        myRoot.insert(str);
    }
    // close the file
    file.close();
    
}







// isWord
/*
 * Returns true if the word is in the Trie, else returns false
 * Pre:
 * Post:
 */
bool Trie::isWord(const string & word){
    return myRoot.isWord(word);
}





// isPrefix
/*
 * Returns true if word is a prefix of a word in the trie, else returns false
 * Pre:
 * Post:
 */
bool Trie::isPrefix(const string & pre) const
{
    return myRoot.isPrefix(pre);
}





// print
/*
 * Prints all the words in the Trie, one per line, in alphabetical order
 * Pre:
 * Post: All words are printed in alphabetical order
 */
void Trie::print() const
{
    myRoot.print("");
}




// wordCount
/*
 * Counts all the words in the Trie and returns it
 * Pre:
 * Post:
 */
size_t Trie::wordCount() const
{
    return myRoot.wordCount();
}
