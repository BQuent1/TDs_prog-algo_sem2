#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <string>
#include <cctype>
#include "stdlib.h"
#include "time.h"


int somme_carre(std::vector<int> const& v){
    return std::accumulate(v.begin(), v.end(), 0, [](int acc, int val){ return acc + val*val; });
}

int produit_element_pairs(std::vector<int> const& v){
    return std::accumulate(v.begin(), v.end(), 1, [](int acc, int val){ return (val % 2 == 0) ? acc * val : acc; });
}

int main(){
    std::vector<int> v {1, 2, 3, 4, 5};
    std::cout << "La somme des carres des elements est : " << somme_carre(v) << std::endl;
    std::cout << "Le produit des elements pairs est : " << produit_element_pairs(v) << std::endl;
    return 0;
}