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


std::vector <int> selectionSort(std::vector<int> vec) {
    int n = vec.size();
    int min = 0;
    int temp = 0;
    while (!is_sorted(vec))
    {
        for (int i = 0; i < n; i++)
        {
            min = i;
            for (int j = i + 1; j < n; j++)
            {
                if (vec[j] < vec[min])
                {
                    min = j;
                }
            }
            temp = vec[i];
            vec[i] = vec[min];
            vec[min] = temp;
        }
    }
    return vec;
}

std::vector<int> bubbleSort(std::vector<int> vec){
    int n = vec.size();
    int temp = 0;
    while (!is_sorted(vec))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if (vec[j] > vec[j + 1])
                {
                    temp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = temp;
                }
            }
        }
    }
    return vec;
}


int main(){
    std::vector<int> vec = {5, 2, 4, 6, 1, 3};
    afficher_tab(vec);
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> vec_sorted = bubbleSort(vec);
    auto end = std::chrono::high_resolution_clock::now();
    afficher_tab(vec_sorted);

    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Temps d'execution : " << duration.count() << " ms" << std::endl;
    return 0;
}
