#include <iostream>
#include <string>
#include "exo3.hpp" // contient aussi tout ce qu’il faut de exo2.hpp

int main()
{
    std::string input = "3 + 4 * 2 / ( 1 - 5 ) ^ 2";

    std::vector<Token> npi = infix_to_npi_tokens(input);

    float result = npi_evaluate_ex2(npi);

    std::cout << "Résultat : " << result << std::endl;
    return 0;
}
