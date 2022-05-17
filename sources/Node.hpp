#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace ariel
{
    class Node
    {
    private:
        std::string name;
        std::vector<Node *> employes;

    public:
        Node(){};
        Node(std::string entered_name);
        ~Node(){};
        std::string get_name();
        std::vector<Node *> get_employes();
    };
}
