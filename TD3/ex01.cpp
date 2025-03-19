#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>

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
