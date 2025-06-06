#include <iostream>
#include <vector>
#include "node.hpp"

int main()
{
    Node *root = create_node(5);

    std::vector<int> values = {3, 7, 2, 4, 6, 8, 1, 9, 0};
    for (int val : values)
    {
        root->insert(val);
    }

    std::cout << "Affichage infixe : ";
    root->display_infix();
    std::cout << "\n";

    Node *current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    std::cout << "Valeur minimale : " << current->value << "\n";

    current = root;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    std::cout << "Valeur maximale : " << current->value << "\n";

    int sum = 0;
    for (auto node : root->prefix())
    {
        sum += node->value;
    }
    std::cout << "Somme des valeurs (parcours préfixe) : " << sum << "\n";

    std::cout << "Hauteur de l'arbre : " << root->height() << "\n";

    Node::delete_tree(root);
    root = nullptr;

    return 0;
}
