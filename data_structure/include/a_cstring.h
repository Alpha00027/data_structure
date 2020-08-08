#pragma once
#include <stdio.h>
/**
 * @brief 字符串拷贝函数
 * @param des 目标字符串,长度必须要大于等于源字符串的长度
 * @param src 源字符串
 * @return 目标字符串首地址
*/
char *a_strcpy(char *des, const char *src);

/**
 * @brief 字符串长度函数.
 * @param src 字符串
 * @return 字符串长度
*/
size_t a_strlen(const char *src);

/**
 * @brief 将src字符串追加在des尾部,des和src内存区域需要不重叠，且des必须有足够大的空间来存放src
 * @param des 目标字符串
 * @param src 源字符串
 * @return 尾部追加过源字符串的目标字符串
*/
char *a_strcat(char *des, const char *src);

/**
 * @brief 比较两个字符串
 * @param s1 字符串1
 * @param s2 字符串2
 * @return s1或s2为nullptr,返回-1;s1<s2,返回-1;s1=s2,返回0;s2>s2,返回1;
*/
int a_strcmp(const char *s1, const char *s2);

/**
 * @brief 考虑字符串最大数据长度的字符串长度函数。
 * @param src 字符串指针
 * @param max_size 字符串数据最大可用长度。如字符数组长度
 * @return 长度
*/
size_t a_strnlen_s(const char *src, const size_t max_size);