#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>


bool is_sorted(std::vector<int> const& vec) { return std::is_sorted(vec.begin(), vec.end()); }

void afficher_tab(std::vector<int> const& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
} 


std::vector<int> triFusion(std::vector<int> vec){
    if (vec.size() <= 1) return vec;
    std::vector<int> vec1(vec.begin(), vec.begin() + vec.size() / 2);
    std::vector<int> vec2(vec.begin() + vec.size() / 2, vec.end());
    vec1 = triFusion(vec1);
    vec2 = triFusion(vec2);
    std::vector<int> vec_sorted;
    int i = 0, j = 0;
    while (i < vec1.size() && j < vec2.size())
    {
        if (vec1[i] < vec2[j])
        {
            vec_sorted.push_back(vec1[i]);
            i++;
        }
        else
        {
            vec_sorted.push_back(vec2[j]);
            j++;
        }
    }
    while (i < vec1.size())
    {
        vec_sorted.push_back(vec1[i]);
        i++;
    }
    while (j < vec2.size())
    {
        vec_sorted.push_back(vec2[j]);
        j++;
    }
    return vec_sorted;
}


size_t quick_sort_partition(std::vector<int>& vec, size_t left, size_t right) {
    int pivot = vec[right]; 
    size_t i = left; 

    for (size_t j = left; j < right; ++j) {
        if (vec[j] < pivot) {
            std::swap(vec[i], vec[j]);
            ++i;
        }
    }
    std::swap(vec[i], vec[right]); 
    return i; 
}

void quick_sort(std::vector<int>& vec, size_t left, size_t right) {
    if (left < right) {
        size_t pivot_index = quick_sort_partition(vec, left, right);
        if (pivot_index > 0) quick_sort(vec, left, pivot_index - 1);
        quick_sort(vec, pivot_index + 1, right);
    }
}

void quick_sort(std::vector<int>& vec) {
    if (!vec.empty()) {
        quick_sort(vec, 0, vec.size() - 1);
    }
}


int main(){
    std::vector<int> vec = {5, 2, 4, 6, 1, 3, 9};
    afficher_tab(vec);
    auto start = std::chrono::high_resolution_clock::now();
    quick_sort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    afficher_tab(vec);

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Temps d'execution : " << duration.count() << " ms" << std::endl;
    return 0;
}
