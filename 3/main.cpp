//Ascii Neighbors
#include <iostream>
#include <string> 
#include <vector>
using std::cout, std::cin, std::endl, std::string, std::vector;

void FilterNeighbors(string& word){
    vector<int> index_to_remove;
    string copy_word = word;
    for(int index = 0; index < word.size(); ++index){
        if (index != 0 && index != word.size() - 1){
            if(word.at(index) == word.at(index - 1) - 1 || word.at(index) == word.at(index + 1) -1) continue;
            if(word.at(index) == word.at(index - 1) + 1 || word.at(index) == word.at(index + 1) + 1) continue;
            if(word.at(index) == word.at(index - 1) || word.at(index) == word.at(index + 1)) continue;
            else index_to_remove.push_back(index); continue;
        }
        else if (index == 0){
            if(word.at(index) == word.at(index + 1) + 1 || word.at(index) == word.at(index + 1) || word.at(index) == word.at(index + 1) - 1) continue;
            else index_to_remove.push_back(index); continue;
        }
        else if (index == word.size() -1){
            if(word.at(index) == word.at(index -1) -1 || word.at(index) == word.at(index - 1) + 1 || word.at(index) == word.at(index - 1)) continue;
            else index_to_remove.push_back(index); continue;
        }
    }
    int inc = 0;
    for(auto ind: index_to_remove){
        word.erase(ind-inc, 1);
        inc++;
    }
}


int main() {
    string word;
    string output_str;
    while(cin >> word){
        FilterNeighbors(word);
        output_str += (word + '\n');
        word.clear();
    }
    cout << output_str; 

    return 0;
}