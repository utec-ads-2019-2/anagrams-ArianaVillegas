#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string lowerandsortWord(string word){
    unsigned int size = word.size();
    for (int i=0; i<size; i++){
        word[i] = tolower(word[i]);
    }
    sort(word.begin(),word.end());
    return word;
}

void printWords(vector<string>* words,map<string,unsigned int>* wordreptitions){
    unsigned int size = words->size();
    for (int i=0; i<size; i++){
        if((*wordreptitions)[lowerandsortWord((*words)[i])] == 1){
            cout << (*words)[i] << '\n';
        }
    }
}

int main() {
    vector<string> words;
    map<string, unsigned int> wordreptitions;
    string word;
    cin >> word;
    while(word[0]!='#'){
        words.push_back(word);
        wordreptitions[lowerandsortWord(word)]++;
        cin >> word;
    }
    sort(words.begin(),words.end());
    printWords(&words, &wordreptitions);

    return EXIT_SUCCESS;
}
