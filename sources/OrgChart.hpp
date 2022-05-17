#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Node.hpp"
using namespace std;
using namespace ariel;

namespace ariel
{
    class OrgChart
    {
    private:
        Node root;

    public:
        OrgChart();
        ~OrgChart(){};
        OrgChart &add_root(std::string name);
        OrgChart &add_sub(std::string boss, std::string worker);
        std::string *begin();
        std::string *end();
        std::string *begin_level_order();
        std::string *end_level_order();
        std::string *begin_reverse_order();
        std::string *reverse_order();
        std::string *begin_preorder();
        std::string *end_preorder();
        friend std::ostream &operator<<(std::ostream &output, OrgChart &o);
    };
}
