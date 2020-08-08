#include <gtest/gtest.h>
#include "a_cstring.h"

TEST(a_strcpy, nullptr) {

	char* a = "";

	EXPECT_STREQ(nullptr, a_strcpy(nullptr, nullptr));
	EXPECT_STREQ(nullptr, a_strcpy(a, nullptr));
	EXPECT_STREQ(nullptr, a_strcpy(nullptr, a));
}

TEST(a_strcpy, negative) {
	char a[6] = "aaaaa";
	char b[2] = "b";

	EXPECT_STRNE("baaaa", a_strcpy(a, b));
}

TEST(a_strcpy, positive) {
	char a[6] = "aaaaa";
	char b[2] = "b";

	EXPECT_STREQ("b", a_strcpy(a, b));
}

TEST(a_strlen, nullptr) {
	EXPECT_EQ(0, a_strlen(nullptr));
}

TEST(a_strlen, positive) {
	EXPECT_EQ(0, a_strlen(""));
	EXPECT_EQ(1, a_strlen("a"));
	EXPECT_EQ(2, a_strlen("ab"));
}

TEST(a_strcat, nullptr) {
	char a[] = "";
	EXPECT_STREQ(nullptr, a_strcat(nullptr, nullptr));
	EXPECT_STREQ(a, a_strcat(a, nullptr));
	EXPECT_STREQ(nullptr, a_strcat(nullptr, a));
}

TEST(a_strcat, positive) {
	char a[10] = "";
	char b[10] = "bbb";
	EXPECT_STREQ("", a_strcat(a, ""));
	EXPECT_STREQ("aaa", a_strcat(a, "aaa"));

	EXPECT_STREQ("bbb", a_strcat(b, ""));
	EXPECT_STREQ("bbbaaa", a_strcat(b, "aaa"));
}

TEST(a_strcmp, nullptr) {
	EXPECT_EQ(-2, a_strcmp(nullptr, nullptr));
	EXPECT_EQ(-2, a_strcmp("", nullptr));
	EXPECT_EQ(-2, a_strcmp(nullptr, ""));
}

TEST(a_strcmp, LT) {
	EXPECT_EQ(-1, a_strcmp("", "a"));
	EXPECT_EQ(-1, a_strcmp("a", "ab"));
	EXPECT_EQ(-1, a_strcmp("ab", "abc"));
}

TEST(a_strcmp, EQ) {
	EXPECT_EQ(0, a_strcmp("", ""));
	EXPECT_EQ(0, a_strcmp("a", "a"));
	EXPECT_EQ(0, a_strcmp("ab", "ab"));
}

TEST(a_strcmp, GT) {
	EXPECT_EQ(1, a_strcmp("a", ""));
	EXPECT_EQ(1, a_strcmp("ab", "a"));
	EXPECT_EQ(1, a_strcmp("abc", "ab"));
}

TEST(a_strnlen_s, nullptr) {
	EXPECT_EQ(0, a_strnlen_s(nullptr, 10));
}

TEST(a_strnlen_s, positive) {
	EXPECT_EQ(0, a_strnlen_s("", 1));
	EXPECT_EQ(1, a_strnlen_s("a", 2));
	EXPECT_EQ(2, a_strnlen_s("ab", 3));

	char x0[3] = "";
	EXPECT_EQ(0, a_strnlen_s(x0, 3));
	char x1[3] = "a";
	EXPECT_EQ(1, a_strnlen_s(x1, 3));
	char x2[3] = "ab";
	EXPECT_EQ(2, a_strnlen_s(x2, 3));
	char x3[3] = "ab";
	x3[2] = 'c';
	EXPECT_EQ(3, a_strnlen_s(x3, 3));
}