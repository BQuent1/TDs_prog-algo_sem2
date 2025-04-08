#pragma once
#include <vector>

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    Node *create_node(int value);
    bool is_leaf() const;
    void insert(int value);
    int height() const;
    void delete_childs();
    int height() const;
    void display_infixe() const;
    std::vector<Node const*> prefixe() const;
    void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left);
};
