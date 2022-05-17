#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Node.hpp"

namespace ariel
{
    Node::Node(std::string entered_name)
    {
        this->name = entered_name;
        this->employes = {};
    }
    std::string Node::get_name()
    {
        return this->name;
    }
    std::vector<Node *> Node::get_employes()
    {
        return this->employes;
    }
}
