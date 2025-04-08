#include "node.hpp"
#include <iostream>
#include <string>
#include <vector>

Node* Node::create_node(int value) {
    Node* node = new Node;
    node->value = value;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool Node::is_leaf() const {
    return left == nullptr && right == nullptr;
}

void Node::insert(int value) {
    if (value < this->value) {
        if (left == nullptr) {
            left = create_node(value);
        } else {
            left->insert(value);
        }
    } else if (value > this->value) {
        if (right == nullptr) {
            right = create_node(value);
        } else {
            right->insert(value);
        }
    }
}

int Node::height() const {
    if (this == nullptr) {
        return 0;
    }
    int left_height = left ? left->height() : 0;
    int right_height = right ? right->height() : 0;
    return std::max(left_height, right_height) + 1;
}


void Node::display_infixe() const {
    if (left != nullptr) {
        left->display_infixe();
    }
    std::cout << value << " ";
    if (right != nullptr) {
        right->display_infixe();
    }
}

std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> parcours;
    
}



void Node::delete_childs(){
    if(this->left != nullptr){
        this->left->delete_childs();
        delete this->left;
        this->left = nullptr;
    }
    if(this->right != nullptr){
        this->right->delete_childs();
        delete this->right;
        this->right = nullptr;
    }
}


void Node::pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}


