#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

std::string to_lowercase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

bool is_palindrome(std::string const& str){
    std::string str_lower = to_lowercase(str);
    auto i = str_lower.begin();
    auto j = str_lower.end() - 1;
    while (i < j) {
        if (*i != *j) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

int main(){
    
        std::string str {};
        std::cout << "Entre un mot : " << std::endl;
        std::cin >> str;
        if (is_palindrome(str))
        {
            std::cout << "Le mot " << str << " est un palindrome" << std::endl;
        }
        else
        {
            std::cout << "Le mot " << str << " n'est pas un palindrome" << std::endl;
        }
        
        return 0;
}