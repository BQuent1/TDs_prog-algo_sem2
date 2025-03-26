#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include "stdlib.h"
#include "time.h"



auto const is_space = [](char letter){ return letter == ' '; };

int compteur_lettre_premier_mot(std::string const& str){
    auto first_space = std::find_if(str.begin(), str.end(), is_space);
    return std::distance(str.begin(), first_space);

}

std::vector<std::string> split_string(std::string const& str){
    std::vector<std::string> words;
    std::string::const_iterator first {str.begin()};
    std::string::const_iterator second {str.begin()};
    while (first != str.end())
    {
        std::string str_to_push {};
        second = std::find_if(first, str.end(), is_space);
        str_to_push.assign(first, second);
        words.push_back(str_to_push);
        first = (second != str.end()) ? std::next(second) : second;
    }
    
    return words;
}

void afficher_words(std::vector<std::string> const& words){
    for (std::string const& word: words)
    {
        std::cout << word << std::endl;
    }
}



int main(){

    std::string str {"Maitre corbeau sur son arbre perché tenait en son bec un fromage, Matre renard par l'odeur alleché lui tint a peu pres ce langage. Et bonjour Monsieur du corbeau, que vous êtes joli, que vous êtes beau, sans mentir si votre ramage se rapporte a votre plumage, vous êtes le phénix des hôtes de ces bois."};
    std::cout << "Le premier mot contient " << compteur_lettre_premier_mot(str) << " lettres" << std::endl;

    std::vector<std::string> words {split_string(str)};
    afficher_words(words);

    return 0;
}