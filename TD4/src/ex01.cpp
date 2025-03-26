#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include "stdlib.h"
#include "time.h"

int main(){

    int log_user {0};

    std::vector<int> v;
    for (int i; i < 100; i++){
        v.push_back(rand() % 100);
    }

    //parcours avec declarations des iterateurs
    for (std::vector<int>::iterator i { v.begin() }; i != v.end(); ++i)
    {
        std::cout << *i << "  " << std::endl;
    }

    //parcours sans declaration des iterateurs
    for (int const elt:v)
    {
        std::cout << elt << "  " << std::endl;
    }

    std::cout << "Note un nombre : " << std::endl;
    std::cin >> log_user;
    if (std::find(v.begin(), v.end(), log_user) != v.end())
    {
        std::cout << "Le nombre est dans le vecteur" << std::endl;
    }
    else
    {
        std::cout << "Le nombre n'est pas dans le vecteur" << std::endl;
    }
    
    std::cout << "Entre un nombre : " << std::endl;
    std::cin >> log_user;
    int occurence = std::count(v.begin(), v.end(), log_user);
    std::cout << "Le nombre " << log_user << " est present " << occurence << " fois dans le vecteur" << std::endl;

    std::sort(v.begin(), v.end());
    std::cout << "Le vecteur trie est : " << std::endl;
    for (int const elt:v)
    {
        std::cout << elt << "  " << std::endl;
    }

    int somme = std::accumulate(v.begin(), v.end(), 0, [](int acc, int current_element) { return acc + current_element; });
    std::cout << "La somme des elements du vecteur est : " << somme << std::endl;

    return 0;
}