//Word Scrambler
#include <iostream>
#include <string>
using std::cout, std::cin, std::endl, std::string;


void swap_element(string& str, int index1, int index2){
    char temp = str[index1];
    str[index1] = str[index2];
    str[index2] = temp;
}

void ScrambleWord(string& word){
    int start_ind = 1;
    int end_ind = word.size() -2;
    if (word.size() <= 3) word = word;
    else{
        while(start_ind < end_ind){
            swap_element(word, start_ind, end_ind);
            ++start_ind;
            --end_ind; 
        }
    }
}


int main(){
    string input_str; 
    string output_str; 
    string word; 
    getline(cin, input_str);
    input_str += ' '; 
    int word_count = 0; 
    int index = 0; 
    for(index; index < input_str.size(); ++index){
        if(input_str[index] != ' ') word += input_str[index];
        else if (input_str[index] == ' '){
            ScrambleWord(word);
            output_str += (word + ' ');
            word.clear();
            ++word_count;
            if (word_count % 8 == 0) output_str += '\n';
        }
    }
    cout << output_str;
    return 0;
    }


