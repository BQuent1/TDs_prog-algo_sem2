#include <iostream>
#include <string>

size_t folding_string_hash(std::string const& s, size_t max);

size_t folding_string_hash(std::string const& s, size_t max) {
    size_t hash = 0;
    for (char c : s) {
        hash += static_cast<size_t>(c);
    }
    return hash % max;
}


size_t folding_string_ordered_hash(std::string const& s, size_t max){
    size_t hash = 0;
    for(int i = 0; i < s.size(); i++){
        hash += static_cast<size_t>(s[i])* (i+1);
    }
    return hash % max;
}


int puissance(int p, int n) {
    int result = 1;
    for (int i = 0; i < n; ++i) {
        result *= p;
    }
    return result;
}

size_t polynomial_rolling_hash(const std::string& s, size_t p, size_t m){
    size_t hash = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        hash = (hash + (s[i] * puissance(p, i)) % m) % m;
    }
    return hash;
}


int main() {
    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);
    
    int p = 31;
    size_t max = 1e9+9; 
    size_t hash_value = polynomial_rolling_hash(str, p, max);
    
    std::cout << "Hash value: " << hash_value << std::endl;
    
    return 0;
}