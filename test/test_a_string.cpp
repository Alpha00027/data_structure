#include "gtest/gtest.h"
#include "a_string.h"
#include <iostream>

TEST(a_string_test, constructor) {
	a_string s0;
	EXPECT_STREQ("\0", s0.get_cstr());

	a_string s1("abc");
	EXPECT_STREQ("abc", s1.get_cstr());

	a_string s2(5, 'a');
	EXPECT_STREQ("aaaaa", s2.get_cstr());
}

TEST(a_string_test, copy_constructor) {
	a_string s0("abcd");
	a_string s1(s0);

	EXPECT_STREQ("abcd", s1.get_cstr());
}

TEST(a_string_test, move_constructor) {
	a_string s0("move");
	a_string s1(std::move(s0));

	EXPECT_STREQ("move", s1.get_cstr());
	EXPECT_STREQ(nullptr, s0.get_cstr());
}

TEST(a_string_test, copy_assignment) {
	a_string s0(5, 'a');
	a_string s1(5, 'b');
	EXPECT_STREQ("aaaaa", s0.get_cstr());
	EXPECT_STREQ("bbbbb", s1.get_cstr());

	s1 = s0;
	EXPECT_STREQ("aaaaa", s0.get_cstr());
	EXPECT_STREQ("aaaaa", s1.get_cstr());
}

TEST(a_string_test, move_assignment) {
	a_string s0(5, 'a');
	a_string s1(5, 'b');
	EXPECT_STREQ("aaaaa", s0.get_cstr());
	EXPECT_STREQ("bbbbb", s1.get_cstr());

	s1 = std::move(s0);
	EXPECT_STREQ(nullptr, s0.get_cstr());
	EXPECT_STREQ("aaaaa", s1.get_cstr());
}

TEST(a_string_test, operator_square_brackets) {
	a_string s0 = "0123456789";
	EXPECT_EQ('0', s0[0]);
	EXPECT_EQ('9', s0[9]);
}

TEST(a_string_test, add_string) {
	a_string s0 = "01234";
	a_string s1 = "5678";
	s0 += s1;
	EXPECT_STREQ("012345678", s0.get_cstr());
}

TEST(a_string_test, add_cstr) {
	a_string s0 = "01234";
	const char* s1 = "5678";
	s0 += s1;
	EXPECT_STREQ("012345678", s0.get_cstr());
}

TEST(a_string_test, cout) {
	a_string s0 = "123";
	std::cout << s0 << std::endl;
}

TEST(a_string_test, equal) {
	a_string s0 = "123";
	a_string s1 = "123";
	EXPECT_TRUE(s0 == s1);
}

TEST(a_string_test, not_equal) {
	a_string s0 = "123";
	a_string s1 = "456";
	EXPECT_TRUE(s0 != s1);
}

TEST(a_string_test, get_cstr) {
	a_string s0 = "12345";
	EXPECT_STREQ("12345", s0.get_cstr());
}

TEST(a_string_test, size) {
	a_string s0;
	EXPECT_EQ(0, s0.size());
	s0 = "123";
	EXPECT_EQ(3, s0.size());
}