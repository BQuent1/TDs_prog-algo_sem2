#include <vector>
#include <algorithm>
#include <vector>
#include <iostream>
#include <chrono>

//version récursive
int search_recur(std::vector<int> const &vec, int value, int left, int right)
{
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;

    if (vec[mid] > value)
    {
        return search_recur(vec, value, left, mid - 1);
    }
    else if (vec[mid] < value)
    {
        return search_recur(vec, value, mid + 1, right);
    }
    else if (vec[mid] == value)
    {
        return mid;
    }

    return -1;
}


//version itérative
int search_iter(std::vector<int> const &vec, int value)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (vec[mid] > value)
        {
            right = mid - 1;
        }
        else if (vec[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            return mid; 
        }
    }

    return -1;
}


int main()
{
    std::vector<int> vec1 = {1, 2, 2, 3, 4, 8, 12};          // 8
    std::vector<int> vec2 = {1, 2, 3, 3, 6, 14, 12, 15};     // 15
    std::vector<int> vec3 = {2, 2, 3, 4, 5, 8, 12, 15, 16};  // 16
    std::vector<int> vec4 = {5, 6, 7, 8, 9, 10, 11, 12, 13}; // 6
    std::vector<int> vec5 = {1, 2, 3, 4, 5, 6, 7, 8, 9};     // 10

    std::cout << search_recur(vec1, 8, 0, vec1.size()) << std::endl;
    std::cout << search_iter(vec2, 15) << std::endl;
    std::cout << search_recur(vec3, 16, 0, vec3.size()) << std::endl;
    std::cout << search_iter(vec4, 6) << std::endl;
    std::cout << search_recur(vec5, 10, 0, vec5.size()) << std::endl;

    return 0;
}