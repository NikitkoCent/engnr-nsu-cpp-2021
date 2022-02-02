//
// Created by bulga on 27.01.2022.
//
#include "linked_list.h"
#include <gtest/gtest.h>

TEST(LL__Test, Copy_Test) {
LinkedList<int> li = {1, 2, 3, 4, 5};
LinkedList<int> li1(li);

ASSERT_EQ(li == li1, true);
}
TEST(LL__Test, Nikita_Test){
    LinkedList<int> list = {1, 2, 3};
    const auto iter = list.rbegin();

    ASSERT_EQ(*iter==3, true);
}

TEST(LL__Test, Copy_Assigment_Test) {
LinkedList<int> li = {1, 2, 3, 4, 5};
LinkedList<int> li1;
li1 = li;

ASSERT_EQ(li == li1, true);
}
struct test_struct{
    int data;
};
TEST(LL__Test, TEst_wn) {

    LinkedList<test_struct> li ;
    test_struct cringe;
    cringe.data=1;
    auto it =li.begin();
    li.insert(it,cringe);
    ASSERT_EQ(  it->data== 1, true);
}
TEST(LL__Test, Move_Test) {
LinkedList<int> list = {1, 2, 3, 4, 5};
LinkedList<int> list1(std::move(list));
LinkedList<int> list2 = {1, 2, 3, 4, 5};

ASSERT_EQ(list1 == list2, true);
}

TEST(LL__Test, Move_Assigment_Test) {
LinkedList<int> list = {1, 2, 3, 4, 5};
LinkedList<int> list1;
list1 = std::move(list);
LinkedList<int> list2 = {1, 2, 3, 4, 5};

ASSERT_EQ(list1 == list2, true);
}

TEST(LL_Test, Move_Assigment_Test_NoEmpty) {
LinkedList<int> list1 = {1, 2, 3, 4, 5};
LinkedList<int> list2 = {5, 6, 7, 8, 9};
list2 = std::move(list1);
LinkedList<int> list3 = {1, 2, 3, 4, 5};

ASSERT_EQ(list2 == list3, true);
}

TEST(LL__Test, InitList_Test) {
LinkedList<int> li = {1, 2, 3, 4, 5};
auto it = li.begin();
for (int i = 1; i < 6; i++) {
ASSERT_EQ(i, *it);
++it;
}
}
TEST(LL__Test, Constructor_test) {
    size_t t = 5;
    LinkedList<int> l(t, 5);
    auto it = l.begin();
    for (int i = 1; i < 6; i++) {
        ASSERT_EQ(i, *it);
        ++it;
    }
}

TEST(LL__Test, Insert_Test_simple) {
LinkedList<int> list = {1, 2, 3, 4, 5};
auto it = (++(++list.cbegin()));
list.insert(it, 100500);
LinkedList<int> list1 = {1, 2, 100500, 3, 4, 5};

ASSERT_EQ(list1 == list, true);
}

TEST(LL__Test, Insert_Test_multi_Tvalue) {
LinkedList<int> list = {1, 2, 3, 4, 5};
auto it = (++(++list.cbegin()));

list.insert(it, (int16_t) 3, 100);
LinkedList<int> list1 = {1, 2, 100, 100, 100, 3, 4, 5};

ASSERT_EQ(list1 == list, true);
}

TEST(LL__Test, Insert_Test_iterators) {
LinkedList<int> list = {1, 2, 3, 4, 5};

auto it = (++(++list.cbegin()));
auto it1 = it;
it++;
++it1;
++it1;

LinkedList<int> list1 = {1, 2, 3, 4, 5};

auto it2 = list1.cbegin();

list1.insert(it2, it, it1);
LinkedList<int> list2 = {4, 5, 1, 2, 3, 4, 5};

ASSERT_EQ(list1 == list2, true);
}

TEST(LL__Test, Insert_Test_initList) {
LinkedList<int> list = {1, 2, 3, 4, 5};
auto it = (++(++list.cbegin()));

list.insert(it, {1, 2, 3, 4});
LinkedList<int> list2 = {1, 2, 1, 2, 3, 4, 3, 4, 5};

ASSERT_EQ(list == list2, true);
}

TEST(LL__Test, Back_Front_Pop_Test) {
LinkedList<int> list = {1, 2, 3, 4, 5};
list.pop_back();
list.pop_front();
LinkedList<int> list2 = {2, 3, 4};

ASSERT_EQ(list == list2, true);
}

TEST(LL__Test, Back_Front_Push_Test) {
LinkedList<int> list = {1, 2, 3, 4, 5};
list.push_back(228);
list.push_front(1488);
LinkedList<int> list2 = {1488, 1, 2, 3, 4, 5, 228};

ASSERT_EQ(list == list2, true);
}

TEST(LL__Test, Erase_Test_Simple) {
LinkedList<int> list1 = {1, 2, 3, 4, 5};
LinkedList<int> list2(list1);
LinkedList<int> list3(list1);

LinkedList<int> list1_t = {1, 3, 4, 5};
LinkedList<int> list2_t = {2, 3, 4, 5};
LinkedList<int> list3_t = {1, 2, 3, 4};

auto it1 = ++list1.cbegin();
list1.erase(it1);

auto it2 = list2.cbegin();
list2.erase(it2);

auto it3 = --list3.cend();
list3.erase(it3);

ASSERT_EQ(list1 == list1_t, true);
ASSERT_EQ(list2 == list2_t, true);
ASSERT_EQ(list3 == list3_t, true);
}

TEST(LL__Test, Erase_Test_Iterators) {
LinkedList<int> list1 = {1, 2, 3, 4, 5};
LinkedList<int> list2(list1);
LinkedList<int> list3(list1);

LinkedList<int> list1_t = {1, 4, 5};
LinkedList<int> list2_t = {3, 4, 5};
LinkedList<int> list3_t = {1, 2, 5};

auto it1 = ++list1.cbegin();
auto it1_ = it1;
++it1_;
++it1_;
list1.erase(it1, it1_);

auto it2 = list2.cbegin();
auto it2_ = it2;
++it2_;
++it2_;
list2.erase(it2, it2_);

auto it3 = --list3.cend();
auto it3_ = ++list3.cbegin();
++it3_;
list3.erase(it3_, it3);

ASSERT_EQ(list1 == list1_t, true);
ASSERT_EQ(list2 == list2_t, true);
ASSERT_EQ(list3 == list3_t, true);
}

TEST(LL__Test, Erase_Test_Same_Iterator) {
LinkedList<int> list1 = {1, 2, 3, 4, 5};
auto it1 = ++list1.cbegin();
auto it2 = ++list1.cbegin();
list1.erase(it1, it2);
LinkedList<int> list2 = {1, 2, 3, 4, 5};

ASSERT_EQ(list1 == list2, true);
}

TEST(LL_TEST, Equality_Test_Simple) {
LinkedList<int> list1 = {1, 2, 3, 4, 5};
LinkedList<int> list2 = {1, 2, 3};

ASSERT_EQ(list1 != list2, true);
}

TEST(LL_TEST, Equality_Test_NOT) {
LinkedList<int> list1 = {1, 2, 3, 4, 5};
LinkedList<int> list2 = {1, 2, 3, 3, 3};

ASSERT_EQ(list1 != list2, true);
}

TEST(LL_TEST, Equality_Test_YES) {
LinkedList<int> list1 = {1, 2, 3, 4, 5};
LinkedList<int> list2 = {1, 2, 3, 4, 5};

ASSERT_EQ(list1 == list2, true);
}

TEST(LL__Test, Reverse_Test) {
LinkedList<int> list = {1, 2, 3, 4, 5};
LinkedList<int> list1 = {5, 4, 3, 2, 1};
list.reverse();
ASSERT_EQ(list1 == list, true);
}

TEST(LL__Test, Swap_Test) {
LinkedList<int> list1 = {1, 2, 3, 4, 5};
LinkedList<int> list1_ = {51, 42, 33, 24, 15};

LinkedList<int> list2_ = {1, 2, 3, 4, 5};
LinkedList<int> list2 = {51, 42, 33, 24, 15};

list1.swap(list1_);

ASSERT_EQ(list1 == list2, true);
ASSERT_EQ(list1_ == list2_, true);
}

TEST(LL_Test, Sort_Test) {
LinkedList<int> list = {8, 10, 5, 1, -12};
LinkedList<int> list1 = {-12, 1, 5, 8, 10};
list.sort();

ASSERT_EQ(list == list1, true);
}

TEST(LL_Test, Sort_Reverse_Test) {
LinkedList<int> list = {8, 10, 5, 1, -12};
LinkedList<int> list1 = {10, 8, 5, 1, -12};
list.sort(std::greater<int>{});

ASSERT_EQ(list == list1, true);
}

TEST(LL_Test, Remove_Test) {
LinkedList<int> list = {8, 8, 5, 8, 10};
LinkedList<int> list1 = {5, 10};
list.remove(8);

ASSERT_EQ(list == list1, true);
}

TEST(LL_Test, Remove_If_Test) {
LinkedList<int> list = {8, 8, 5, 8, 10};
LinkedList<int> list1 = {5};
list.remove_if([](auto &item) { return item % 2 == 0; });

ASSERT_EQ(list == list1, true);
}

TEST(LL_Test, Unique_Test) {
LinkedList<int> list = {5, 8, 8, 8, 10, 10};
list.unique();
LinkedList<int> list1 = {5, 8, 10};

ASSERT_EQ(list == list1, true);
}

TEST(LL_Test, Post_Prefix_It_Inc) {
LinkedList<int> list = {5, 8, 8, 8, 10, 10};
auto it1 = list.cbegin();
auto it2 = it1++;
ASSERT_EQ(*it1 == 8, true);
ASSERT_EQ(*it2 == 5, true);
}

TEST(LL_TEST, Swap_Iters) {
LinkedList<int> list = {1, 2};

auto it1 = list.begin();
auto it2 = it1++;

list.swap(it1, it2);

ASSERT_EQ(*it2 == 2, true);
ASSERT_EQ(*it1 == 1, true);
}

TEST(LL_TEST, Reverse_Iterators1) {
const LinkedList<int> from = {1, 2, 3, 4, 5};
LinkedList<int> actual;

for (auto it = from.rbegin(); it != from.rend(); ++it) {
actual.push_back(*it);
}

const LinkedList<int> expected = {5, 4, 3, 2, 1};

EXPECT_EQ(expected == actual, true);
}

TEST (LL_TEST, Reverse_Iterators2) {
const LinkedList<int> from;
LinkedList<int> actual;

for (auto it = from.rbegin(); it != from.rend(); ++it) {
actual.push_back(*it);
}

const LinkedList<int> expected;

EXPECT_EQ(expected == actual, true);
};

TEST (LL_TEST, Reverse_Iterators3) {
LinkedList<int> list;
list.reverse();

for (const auto &a: {1, 2, 3, 4, 5}) {
list.push_back(a);
}

const LinkedList<int> expected = {1, 2, 3, 4, 5};

EXPECT_EQ(expected, list);
}

TEST (LL_TEST, Resize_test) {
LinkedList<int> list = {1, 2, 3};
list.resize(5);
list.resize(2);
list.resize(6, 4);

LinkedList<int> expected = {1, 2, 4, 4, 4, 4};

EXPECT_EQ(expected, list);
}
