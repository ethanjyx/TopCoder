//
//  PrefixTree.cpp
//  Leetcode
//
//  Created by Yixing Jiang on 9/29/14.
//  Copyright (c) 2014 ethanjyx. All rights reserved.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

// assumption: all letters will be a-z

class TrieNode {
public:
    TrieNode();
    TrieNode(char c_);
    void insertWord(const string& word);
    void printAll();
    char getC() {return c;}
    bool isEnd() {return end;}
private:
    char c;
    vector<TrieNode*> children;
    bool end;
    
    void print(string&s, TrieNode* n);
};

TrieNode::TrieNode() : children(vector<TrieNode*>(26, nullptr)), end(false)
{
}

TrieNode::TrieNode(char c_) : c(c_), children(vector<TrieNode*>(26, nullptr)), end(false)
{
}

void TrieNode::insertWord(const string& word)
{
    TrieNode* cur = this;
    for (char c : word) {
        if (!cur->children[c-'a']) {
            cur->children[c-'a'] = new TrieNode(c);
        }
        cur = cur->children[c-'a'];
    }
    cur->end = true;
}

void TrieNode::printAll()
{
    string s;
    for (int i = 0; i < children.size(); i++) {
        if (children[i]) {
            print(s, children[i]);
        }
    }
}

void TrieNode::print(string &s, TrieNode *n)
{
    s.push_back(n->getC());
    if (n->isEnd()) {
        cout << s << endl;
    }
    
    for (int i = 0; i < n->children.size(); i++) {
        if (n->children[i]) {
            print(s, n->children[i]);
        }
    }
    
    s.pop_back();
}

int main()
{
    TrieNode t;
    vector<string> words{"hello", "world"};
    for(auto& s : words) {
        t.insertWord(s);
    }
    t.printAll();
    return 0;
}