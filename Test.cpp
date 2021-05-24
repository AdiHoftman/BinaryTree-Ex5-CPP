#include "BinaryTree.hpp"
#include "doctest.h"

using namespace std;
using namespace ariel;

TEST_CASE("Preorder"){

    BinaryTree<int> b;
    b.add_root(5).add_left(5, 4).add_right(5, 6).add_left(4,3).add_right(6, 7).add_right(6, 9);
    auto a = b.begin_preorder();
    CHECK(*a++ == 5);
    CHECK_EQ(*a++, 5);
    CHECK_EQ(*a++, 4);
    CHECK_EQ(*a++, 3);
    CHECK_EQ(*a++, 6);
    CHECK_NE(*a++, 7);
    CHECK_EQ(*a++, 9);
    // CHECK_EQ(a, null);
}

TEST_CASE("Inorder"){
    BinaryTree<int> b;
    b.add_root(5).add_left(5, 4).add_right(5, 6).add_left(4,3).add_right(6, 7);
    auto a = b.begin_inorder();
    CHECK_EQ(*a++, 3);
    CHECK_EQ(*a++, 4);
    CHECK_EQ(*a++, 5);
    CHECK_EQ(*a++, 6);
    CHECK_EQ(*a++, 7);
    CHECK_EQ(a, nullptr);
}

TEST_CASE("Postorder"){
    BinaryTree<int> b;
    b.add_root(5).add_left(5, 4).add_right(5, 6).add_left(4,3).add_right(6, 7).add_right(3, 2).add_left(2, 8);
    auto a = b.begin_postorder();
    CHECK_EQ(*a++, 8);
    CHECK_EQ(*a++, 3);
    CHECK_EQ(*a++, 2);
    CHECK_EQ(*a++, 4);
    CHECK_EQ(*a++, 7);
    CHECK_EQ(*a++, 6);
    CHECK_EQ(*a++, 5);
    CHECK_EQ(a, nullptr);
}