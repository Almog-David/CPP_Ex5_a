#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "doctest.h"
#include "Node.hpp"
#include "OrgChart.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("test Ex5")
{

    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));

    std::string level;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        level += (*it);
        level += " ";
    }
    CHECK(level == "CEO CTO CFO COO VP_SW VP_BI ");

    std::string reverse;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        reverse += (*it);
        reverse += " ";
    }
    CHECK(reverse == "VP_SW VP_BI CTO CFO COO CEO ");
    std::string pre;
    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
    {
        pre += (*it);
        pre += " ";
    }
    CHECK(pre == "CEO CTO VP_SW CFO COO VP_BI ");

    OrgChart jungle;
    CHECK_NOTHROW(jungle.add_root("jungle"));
    CHECK_NOTHROW(jungle.add_sub("jungle", "eagle"));
    CHECK_NOTHROW(jungle.add_sub("jungle", "lion"));
    CHECK_NOTHROW(jungle.add_sub("jungle", "whale"));
    CHECK_NOTHROW(jungle.add_sub("eagle", "bird"));
    CHECK_NOTHROW(jungle.add_sub("lion", "tiger"));
    CHECK_NOTHROW(jungle.add_sub("whale", "dolphin"));
    CHECK_NOTHROW(jungle.add_sub("tiger", "cat"));
    CHECK_NOTHROW(jungle.add_sub("dolphin", "fish"));

    std::string level2;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        level2 += (*it);
        level2 += " ";
    }
    CHECK(level2 == "jungle eagle lion whale bird tiger dolphin cat fish ");

    std::string reverse2;
    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
    {
        reverse2 += (*it);
        reverse2 += " ";
    }
    CHECK(reverse2 == "fish cat dolphin tiger bird whale lion eagle jungle ");

    std::string pre2;
    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it)
    {
        pre2 += (*it);
        pre2 += " ";
    }
    CHECK(pre2 == "jungle eagle bird lion tiger cat whale dolphin ");

    CHECK_THROWS(organization.add_sub("X", "CTO"));
    CHECK_THROWS(organization.add_sub("T", "CEO"));
    CHECK_THROWS(organization.add_sub("CFF", "CFO"));
    CHECK_THROWS(organization.add_sub("CTO", "CTO"));
    CHECK_THROWS(organization.add_sub("CEO", "CEO"));
    CHECK_THROWS(organization.add_sub("blabla", "VP_BI"));
    CHECK_THROWS(jungle.add_sub("dog", "puppy"));
    CHECK_THROWS(jungle.add_sub("shark", "dolphin"));
    CHECK_THROWS(jungle.add_sub("whale", "whale"));
    CHECK_THROWS(jungle.add_sub("cat", "cat"));
    CHECK_THROWS(jungle.add_sub("blabla", "wolf"));
    CHECK_THROWS(jungle.add_sub("jungle", "jungle"));
}
