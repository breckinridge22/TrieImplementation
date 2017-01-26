// File name: TrieNode.cpp
// Author: Breck Stodghill
// userid: stodghbs
// Email: breckinridge.s.stodghill@vanderbilt.edu
// Class: CS2201
// Assignment Number: 9
// Honor Statement:“I pledge on my honor that I have neither given nor received unauthorized aid on this examination.”
// Description:  This is the class definition of the TrieNode class which is used in the Trie class for holding data for the letters
// Last Changed:  Dec 2

#include "TrieNode.h"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;



// constructor
TrieNode::TrieNode(char c, bool b):data(c),end(b)
{
    for (int i = 0; i < NUM_LETTERS; i++){
        myArr[i] = nullptr;
    }
}




// copy ctor
TrieNode::TrieNode(const TrieNode& rhs):data(rhs.data),end(rhs.end), myArr()
{
    // deep copy of the array of pointers
    for (int i = 0; i < NUM_LETTERS; i ++){
        if (rhs.myArr[i] != nullptr){
            myArr[i] = new TrieNode(*rhs.myArr[i]);
        }
    }
}







// dtor
TrieNode::~TrieNode()
{
    // deallocate memory for pointers in the array
    for (int i = 0; i < NUM_LETTERS; i++){
        if (myArr[i] != nullptr){
            delete myArr[i];
            myArr[i] = nullptr;
        }
    }
}







// assignment operator
const TrieNode& TrieNode::operator= (const TrieNode & rhs)
{
    // must check for self assignment
    
    
    TrieNode tmp (rhs);
    std::swap(data, tmp.data);
    std::swap(end, tmp.end);
    for (int i = 0; i < NUM_LETTERS; i++){
        std::swap(myArr[i], tmp.myArr[i]);
    }
    return *this;
}









// insert
/*
 * Inserts the parameter word into the Trie
 * If word is empty doesnt insert into the Trie
 * Pre:
 * Post: Word is inserted into the Trie
 */
void TrieNode::insert (const string& str)
{
    // base case is if pointer is null
    // else
    // basecase is empty string
    if (str.length() == 0){
        end = true;
        return;
    } else {
        int index = str[0] - 'a';
        if (myArr[index] == nullptr){
            myArr[index] = new TrieNode(str[0],str.length()==1);
        }
        myArr[index]->insert(str.substr(1, str.length()-1));
    }
}








// isWord
/*
 * Returns true if the word is in the Trie, else returns false
 * Pre:
 * Post:
 */
bool TrieNode::isWord (const string& str) const
{
    if (str.length() == 0){
        return end;
    } else{
        int index = str[0] - 'a';
        if (myArr[index] == nullptr){
            return false;
        }
        return myArr[index]->isWord(str.substr(1,str.length()-1));
    }
}







// isPrefix
/*
 * Returns true if word is a prefix of a word in the trie, else returns false
 * Pre:
 * Post:
 */
bool TrieNode::isPrefix (const string & str) const
{
    if (str.length() == 0){
        return true;
    } else {
        int index = str[0] - 'a';
        if (myArr[index] == nullptr){
            return false;
        }
        return myArr[index]->isPrefix(str.substr(1,str.length()-1));
    }
}










// print
/*
 * Prints all the words in the Trie, one per line, in alphabetical order
 * Pre:
 * Post: All words are printed in alphabetical order
 */
void TrieNode::print (const string& str) const
{
   // traverse the trienode structure and print each word when the flag is true
    
    // go through the entire array and look for matches
    // if a match is found, first check the flag
    // then call the print function recursivley and pass that character as the paramemt
    if (end)
        cout << str << data << endl;
    for (int i = 0; i < NUM_LETTERS; i++){
        if (myArr[i] != nullptr){
            string s = str;
            myArr[i]->print(s + data);
        }
    }
}







// wordCount
/*
 * Counts all the words in the Trie and returns it
 * Pre:
 * Post:
 */
size_t TrieNode::wordCount() const
{
    size_t result;
    if (end){
        result = 1;
    } else
        result = 0;
    for (int i = 0; i < NUM_LETTERS; i++){
        if (myArr[i] != nullptr){
            result += myArr[i]->wordCount();
        }
    }
    return result;
}













