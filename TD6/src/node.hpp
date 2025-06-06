#ifndef NODE_HPP
#define NODE_HPP

#include <vector>

struct Node
{
    int value;
    Node *left{nullptr};
    Node *right{nullptr};

    Node(int val);
    Node(int val, Node *leftChild, Node *rightChild);

    ~Node();

    bool is_leaf() const;

    void insert(int value);

    int height() const;

    void delete_children();

    void display_infix() const;

    std::vector<Node const *> prefix() const;

    std::vector<Node const *> postfix() const;

    static Node *&most_left(Node *&node);

    static bool remove(Node *&node, int value);

    static void delete_tree(Node *node);
};

Node *create_node(int value);

#endif
