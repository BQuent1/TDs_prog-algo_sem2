#include "node.hpp"
#include <iostream>

Node::Node(int val) : value(val), left(nullptr), right(nullptr) {}

Node::Node(int val, Node *leftChild, Node *rightChild)
    : value(val), left(leftChild), right(rightChild) {}

Node::~Node()
{
    delete left;
    delete right;
}

Node *create_node(int value)
{
    return new Node(value);
}

bool Node::is_leaf() const
{
    return left == nullptr && right == nullptr;
}

void Node::insert(int val)
{
    if (val < value)
    {
        if (left == nullptr)
        {
            left = create_node(val);
        }
        else
        {
            left->insert(val);
        }
    }
    else
    {
        if (right == nullptr)
        {
            right = create_node(val);
        }
        else
        {
            right->insert(val);
        }
    }
}

int Node::height() const
{
    int left_height = left ? left->height() : 0;
    int right_height = right ? right->height() : 0;
    return 1 + (left_height > right_height ? left_height : right_height);
}

void Node::delete_children()
{
    delete left;
    left = nullptr;
    delete right;
    right = nullptr;
}

void Node::display_infix() const
{
    if (left)
        left->display_infix();
    std::cout << value << " ";
    if (right)
        right->display_infix();
}

std::vector<Node const *> Node::prefix() const
{
    std::vector<Node const *> nodes;
    nodes.push_back(this);
    if (left)
    {
        auto left_nodes = left->prefix();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right)
    {
        auto right_nodes = right->prefix();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    return nodes;
}

std::vector<Node const *> Node::postfix() const
{
    std::vector<Node const *> nodes;
    if (left)
    {
        auto left_nodes = left->postfix();
        nodes.insert(nodes.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right)
    {
        auto right_nodes = right->postfix();
        nodes.insert(nodes.end(), right_nodes.begin(), right_nodes.end());
    }
    nodes.push_back(this);
    return nodes;
}

Node *&Node::most_left(Node *&node)
{
    if (node->left == nullptr)
    {
        return node;
    }
    return most_left(node->left);
}

bool Node::remove(Node *&node, int val)
{
    if (node == nullptr)
        return false;

    if (val < node->value)
    {
        return remove(node->left, val);
    }
    else if (val > node->value)
    {
        return remove(node->right, val);
    }
    else
    {
        if (node->is_leaf())
        {
            delete node;
            node = nullptr;
            return true;
        }
        else if (node->left == nullptr)
        {
            Node *old = node;
            node = node->right;
            old->left = old->right = nullptr;
            delete old;
            return true;
        }
        else if (node->right == nullptr)
        {
            Node *old = node;
            node = node->left;
            old->left = old->right = nullptr;
            delete old;
            return true;
        }
        else
        {
            Node *&minNode = most_left(node->right);
            node->value = minNode->value; // copie valeur
            return remove(minNode, minNode->value);
        }
    }
}

void Node::delete_tree(Node *node)
{
    if (!node)
        return;
    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}
