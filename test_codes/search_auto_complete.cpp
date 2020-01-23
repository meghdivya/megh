#include<iostream>
#include<string>
using namespace std;

#define MAX_ALPHABETS 26
#define GET_INDEX(c) ((int)c-(int)'a')

class Trie{
    public:
    bool end_of_word;
    Trie* children[MAX_ALPHABETS];
    Trie* getNode() {
        Trie* node  = new Trie();
        for(int i=0; i<MAX_ALPHABETS; i++) {
            node->children[i] = NULL;
        }
        node->end_of_word = false;
        return node;
    }
    void setEndOfWord() {
        end_of_word = true;
    }
    int isLast() {
        for(int i=0; i<MAX_ALPHABETS; i++) {
            if(children[i])
                return 0;
        }
        return 1;
    }
    void print_trie(Trie* root, string word) {
        if(root->end_of_word) {
            cout<<word<<endl;
        }
//        if(root->isLast()) {
//            return;
//        }
        for(int i=0; i<MAX_ALPHABETS; i++) {
            if(root->children[i]) {
                word.push_back(97+i);
                //cout<<word<<endl;
                print_trie(root->children[i],word);
				word.pop_back();
            }
        }
    }

};

class AutoComplete {
    public:
    Trie* root;
    AutoComplete() {
        root = root->getNode();
    }

    void insert(const string word) {
        Trie* tmp = root;
        for(int i=0; i<word.size(); i++) {
            int index = GET_INDEX(word[i]);
            if(!tmp->children[index]) {
                tmp->children[index] = tmp->getNode();
            }
            tmp = tmp->children[index];
        }
        tmp->setEndOfWord();
    }
    void suggest_recur(Trie* tmp, string query) {
        if(tmp->end_of_word) {
            cout<<query<<endl;
        }
        if(tmp->isLast()) {
            return;
        }
        for(int i=0; i<MAX_ALPHABETS; i++) {
            if(tmp->children[i]) {
                query.push_back(97+i);
                suggest_recur(tmp->children[i], query);
				//query.pop_back();
            }
        }
    }

    void print_suggestions(const string prefix) {
		cout<<"Suggestion for "<<prefix<<endl;
        Trie* tmp = root;
        for(int i=0; i<prefix.size(); i++) {
            int index = GET_INDEX(prefix[i]);
            if(tmp->children[index]) {
                tmp = tmp->children[index];
            }
        }
        bool is_word = (tmp->end_of_word== true);
        int is_last = tmp->isLast();
        if(is_word && is_last) {
            cout<<prefix<<endl;
            return;
        }
		string word;
		tmp->print_trie(tmp, word);
        if(!is_last) {
            string query = prefix;
            suggest_recur(tmp, query);
        }
        
    }
};

int main() {
    AutoComplete ac;
    ac.insert("hello");
    ac.insert("hell");
    ac.insert("he");
    ac.insert("help");
    ac.insert("and");
    ac.insert("android");
    ac.insert("pot");
    ac.insert("policy");
    string word;
    //ac.root->print_trie(ac.root, word);
    ac.print_suggestions("he");
    ac.print_suggestions("a");
    ac.print_suggestions("ap");
    ac.print_suggestions("po");
    return 0;
}
