#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

namespace ariel
{
    std::string ans;
    OrgChart::OrgChart() {}

    OrgChart &OrgChart::add_root(std::string name)
    {
        return *this;
    }
    OrgChart &OrgChart::add_sub(std::string boss, std::string worker)
    {
        return *this;
    }
    std::string *OrgChart::begin()
    {
        return &ans;
    }
    std::string *OrgChart::end()
    {
        return &ans;
    }

    std::string *OrgChart::begin_level_order()
    {
        return &ans;
    }
    std::string *OrgChart::end_level_order()
    {
        return &ans;
    }
    std::string *OrgChart::begin_reverse_order()
    {
        return &ans;
    }
    std::string *OrgChart::reverse_order()
    {
        return &ans;
    }
    std::string *OrgChart::begin_preorder()
    {
        return &ans;
    }
    std::string *OrgChart::end_preorder()
    {
        return &ans;
    }
    std::ostream &operator<<(std::ostream &output, OrgChart &o)
    {
        return output;
    }
}