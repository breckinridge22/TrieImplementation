// File name: TrieDriver.cpp
// Author: Breck Stodghill
// userid: stodghbs
// Email: breckinridge.s.stodghill@vanderbilt.edu
// Class: CS2201
// Assignment Number: 9
// Honor Statement:“I pledge on my honor that I have neither given nor received unauthorized aid on this examination.”
// Description:  This is the test driver of the Trie Class
// Last Changed:  Dec 2

#include <stdio.h>
#include <iostream>
#include "Trie.h"

/*
 * This tests the constructor and the print methods of the trie class
 *
 */

void test_constructorAndPrint()
{
    Trie t;
    t.insert("for");
    t.insert("fork");
    t.insert("fun");
    t.print();
    cout << "Constructor test: Pass" << endl;
}

/*
 * This tests the copy constructor of the trie class
 *
 */
void test_copyCtor()
{
    // copy ctor if trie has words
    Trie t;
    t.insert("for");
    t.insert("foreign");
    t.insert("yes");
    Trie t1(t);
    cout << "\nFirst object:"<< endl;
    t.print();
    cout << endl;
    cout << "Copied object:" << endl;
    t1.print();
    cout << endl;
    cout << "Copy Constructor test: Pass" << endl;
    
    // lets copy a black trie
    Trie t2;
    Trie t3(t2);
    cout << "\nFirst Object:" << endl;
    t2.print();
    cout << "\nCopied Object:" << endl;
    t3.print();
    cout << "\nBoth Objects are empty" << endl;
    cout << "Empty Copy Constructor Test: Pass" << endl;
}

/*
 * This tests the insert and isWord methods of the trie class
 *
 */
void test_insertAndIsWord()
{
    
    Trie t;
    t.insert("a");
    t.insert("animal");
    t.insert("beach");
    t.insert("zoo");
    cout << "\nPrinted object: " << endl;
    t.print();
    cout << "\nInsert and isWord Method test: ";
    if (t.isWord("a") && !t.isWord("an") && t.isWord("animal") && t.isWord("beach") && t.isWord("zoo")){
        cout << "Pass" << endl;
    } else {
        cout << "Fail" << endl;
    }
}

/*
 * This tests the isPrefix method of the trie class
 *
 */
void test_IsPrefix()
{
    Trie t;
    cout << "isPrefix method test: ";
    t.insert("an");
    t.insert("and");
    t.insert("tom");
    if (t.isPrefix("a") && t.isPrefix("to") && t.isPrefix("an") && t.isPrefix(" ")){
        cout << "Pass" << endl;
    }
}

/*
 * This tests the wordCount method
 *
 */
void test_WordCount()
{
    Trie t;
    cout << "WordCount method test: ";
    if (t.wordCount() != 0){
        cout << "Fail" << endl;
    }
    t.insert("a");
    t.insert("an");
    t.insert("bye");
    t.insert("baloon");
    t.insert("toot");
    if (t.wordCount() != 5){
        cout << "Fail" << endl;
    } else {
        cout << "Pass" << endl;
    }
    
}

/*
 * This tests the loadFromFile method of the trie class
 *
 */
void test_LoadFromFile()
{
    // need to read one file that works and one file that doesnt
    
    string s;
    cout << "Please enter the filename of the file to be read and scanned into the Trie: " << endl;
    cin >> s;
    Trie t;
    t.loadFromFile(s);
    t.print();
    cout << "Load From File Method Test: Pass" << endl;
}

int main ()
{
    test_constructorAndPrint();
    test_copyCtor();
    test_insertAndIsWord();
    test_IsPrefix();
    test_WordCount();
    test_LoadFromFile();
}



