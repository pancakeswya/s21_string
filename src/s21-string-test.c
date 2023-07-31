#include <check.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>

#include "s21_string.h"

START_TEST(memchr_test) {
  char *s1 = "This is a s21_memchr test";

  ck_assert_ptr_eq(s21_memchr(s1, 's', 0), memchr(s1, 's', 0));
  ck_assert_ptr_eq(s21_memchr(s1, 's', 2), memchr(s1, 's', 2));
}
END_TEST

START_TEST(memcmp_test) {
  char *s1 = "This is a 1st string s21_memcmp test";
  char *s2 = "This is a 2nd string s21_memcmp test";

  ck_assert_msg(s21_memcmp(s1, s2, 0) == memcmp(s1, s2, 0),
                "4rth memcmp test failed.");
  ck_assert_msg(s21_memcmp(s1, s2, 36) == memcmp(s1, s2, 36),
                "5rth memcmp test failed.");
}
END_TEST

START_TEST(memcpy_test) {
  char *src1 = "schesrdsfdsfdsfesr";
  int len = s21_strlen(src1);
  char dest1[100] = {0};
  char dest2[100] = {0};
  char dest3[100] = {0};
  char dest4[100] = {0};
  char dest5[100] = {0};
  char dest6[100] = {0};
  char dest7[100] = {0};
  char dest8[100] = {0};
  char dest9[100] = {0};
  char dest10[100] = {0};

  s21_memcpy(dest1, src1, len + 1);
  memcpy(dest2, src1, len + 1);

  s21_memcpy(dest3, src1, 5);
  memcpy(dest4, src1, 5);

  s21_memcpy(dest5, src1, 0);
  memcpy(dest6, src1, 0);

  s21_memcpy(dest7, src1, 18);
  memcpy(dest8, src1, 18);

  s21_memcpy(dest9, src1, 1);
  memcpy(dest10, src1, 1);

  ck_assert_str_eq(dest1, dest2);
  ck_assert_str_eq(dest3, dest4);
  ck_assert_str_eq(dest5, dest6);
  ck_assert_str_eq(dest7, dest8);
  ck_assert_str_eq(dest9, dest10);
}
END_TEST

START_TEST(memmove_test) {
  char *src1 = "schesrdsfdsfdsfesr";
  int len = s21_strlen(src1);
  char dest1[100];
  char dest2[100];
  char dest3[100];
  char dest4[100];
  char dest5[100];
  char dest6[100];
  char dest7[100];
  char dest8[100];
  char dest9[100];
  char dest10[100];

  s21_memmove(dest1, src1, len + 1);
  memmove(dest2, src1, len + 1);

  s21_memmove(dest3, src1, 5);
  memmove(dest4, src1, 5);

  s21_memmove(dest5, src1, 0);
  memmove(dest6, src1, 0);

  s21_memmove(dest7, src1, 18);
  memmove(dest8, src1, 18);

  s21_memmove(dest9, src1, 1);
  memmove(dest10, src1, 1);

  ck_assert_msg(memcmp(dest1, dest2, len) == 0, "1st memmove test failed.");
  ck_assert_msg(memcmp(dest3, dest4, 5) == 0, "2nd memmove test failed.");
  ck_assert_msg(memcmp(dest5, dest6, 0) == 0, "3rd memmove test failed.");
  ck_assert_msg(memcmp(dest7, dest8, 18) == 0, "4rth memmove test failed.");
  ck_assert_msg(memcmp(dest9, dest10, 1) == 0, "5rth memmove test failed.");
}
END_TEST

START_TEST(memset_test) {
  char str1[] = "School is cool";
  char str2[] = "School-21";
  char str3[] = "amogus";
  char str4[] = "This is a string!";
  char str5[] = "Shrek";
  char res1[] = "School is cool";
  char res2[] = "School-21";
  char res3[] = "amogus";
  char res4[] = "This is a string!";
  char res5[] = "Shrek";

  s21_memset(str1, '_', 5);
  s21_memset(str2, '_', 4);
  s21_memset(str3, 'M', 2);
  s21_memset(str4, '-', 1);
  s21_memset(str5, 'S', 1);

  memset(res1, '_', 5);
  memset(res2, '_', 4);
  memset(res3, 'M', 2);
  memset(res4, '-', 1);
  memset(res5, 'S', 1);

  ck_assert_msg(memcmp(str1, res1, sizeof(str1)) == 0,
                "1st memset test failed");
  ck_assert_msg(memcmp(str2, res2, sizeof(str2)) == 0,
                "2nd memset test failed");
  ck_assert_msg(memcmp(str3, res3, sizeof(str3)) == 0,
                "3rd memset test failed");
  ck_assert_msg(memcmp(str4, res4, sizeof(str4)) == 0,
                "4rth memset test failed");
  ck_assert_msg(memcmp(str5, res5, sizeof(str5)) == 0,
                "5rth memset test failed");
}
END_TEST

START_TEST(strcat_test) {
  char str1[21] = "TEST";
  char str2[8] = "strcat";
  char str3[9] = "function";
  char str4[1] = "";
  char str5[2] = " ";

  s21_strcat(str1, str5);
  ck_assert_msg(!memcmp(str1, "TEST ", 6), "1st strcat test failed");

  s21_strcat(str1, str2);
  ck_assert_msg(!memcmp(str1, "TEST strcat", 12), "2nd strcat test failed");

  s21_strcat(str1, str5);
  ck_assert_msg(!memcmp(str1, "TEST strcat ", 13), "3rd strcat test failed");

  s21_strcat(str1, str3);
  ck_assert_msg(!memcmp(str1, "TEST strcat function", 21),
                "4rth strcat test failed");

  s21_strcat(str1, str4);
  ck_assert_msg(!memcmp(str1, "TEST strcat function", 21),
                "5th strcat test failed");
}
END_TEST

START_TEST(strncat_test_1) {
  char str1[25] = "TEST";
  char str2[8] = "strncat";
  char str3[35] = "function";
  char str4[1] = "";
  char str5[30] = "amogus";

  s21_strncat(str1, str2, 3);
  ck_assert_msg(!memcmp(str1, "TESTstr", 8), "1st strncat test failed");

  s21_strncat(str1, str4, 3);
  ck_assert_msg(!memcmp(str1, "TESTstr", 8), "2nd strncat test failed");

  s21_strncat(str2, str4, 1);
  ck_assert_msg(!memcmp(str2, "strncat", 8), "3rd strncat test failed");

  s21_strncat(str5, str3, 3);
  ck_assert_msg(!memcmp(str5, "amogusfun", 10), "4rth strncat test failed");
}
END_TEST

START_TEST(strncat_test_2) {
  char str1[25] = "TEST";
  char str5[30] = "amogus";
  s21_strncat(str5, str1, 1);
  ck_assert_str_eq(str5, "amogusT");
}
END_TEST

START_TEST(strchr_test) {
  char *str1 = "TEST";
  char *str2 = "strchr";
  char *str3 = "function";
  char *str4 = "";
  char *str5 = "amogus";
  ck_assert_str_eq(s21_strchr(str1, 'E'), strchr(str1, 'E'));
  ck_assert_str_eq(s21_strchr(str3, 'i'), strchr(str3, 'i'));
  ck_assert_str_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
  ck_assert_str_eq(s21_strchr(str1, 'E'), strchr(str1, 'E'));
  ck_assert_ptr_eq(s21_strchr(str2, 'E'), strchr(str2, 'E'));
  ck_assert_str_eq(s21_strchr(str3, 'i'), strchr(str3, 'i'));
  ck_assert_ptr_eq(s21_strchr(str4, ' '), strchr(str4, ' '));
  ck_assert_str_eq(s21_strchr(str5, 'a'), strchr(str5, 'a'));
}
END_TEST

START_TEST(strcmp_test) {
  char t1[] = "Sample Text";
  char t2[] = "Sample Text Plus Some Text";
  ck_assert_msg(s21_strcmp(t1, t2) == -32, "1st strcmp test failed");

  char t3[] = "AAA";
  char t4[] = "B";
  ck_assert_msg(s21_strcmp(t3, t4) == -1, "2nd strcmp test failed");

  char t5[] = "A\0BCD";
  char t6[] = "A";
  ck_assert_msg(s21_strcmp(t5, t6) == 0, "3rd strcmp test failed");

  char t7[] = "amogus";
  char t8[] = "m";
  ck_assert_msg(s21_strcmp(t7, t8) == -12, "4rth strcmp test failed");

  char t9[] = "shrek";
  char t10[] = "as";
  ck_assert_msg(s21_strcmp(t9, t10) == 18, "5th strcmp test failed");
}
END_TEST

START_TEST(strncmp_test) {
  char *t1 = "Sample Text";
  char *t2 = "Sample Text Plus Some Text";
  ck_assert_msg(!s21_strncmp(t1, t2, 10) && !strncmp(t1, t2, 10),
                "1st strncmp test failed");
  ck_assert_msg(s21_strncmp(t1, t2, 14) < 0 && strncmp(t1, t2, 14) < 0,
                "2nd strncmp test failed");
  char *t3 = "";
  char *t4 = "A";
  ck_assert_msg(s21_strncmp(t3, t4, 0) == 0 && strncmp(t3, t4, 0) == 0,
                "3rd strncmp test failed");
  ck_assert_msg(s21_strncmp(t3, t4, 1) < 0 && strncmp(t3, t4, 1) < 0,
                "3rd strncmp test failed");
  char *t5 = "ShrekAmogus";
  char *t6 = "Shr";
  ck_assert_msg(s21_strncmp(t5, t6, 5) > 0 && strncmp(t5, t6, 5) > 0,
                "4rth strncmp test failed");
  ck_assert_msg(s21_strncmp(t5, t6, 0) == 0 && strncmp(t5, t6, 0) == 0,
                "5th strncmp test failed");
}
END_TEST

START_TEST(strcpy_test) {
  char s1[50] = "Sample Text";
  char d1[50] = "";
  s21_strcpy(d1, s1);
  ck_assert_msg(!strcmp(d1, s1), "1st  strcpy test failed");

  char s2[50] = "AAAAA";
  char d2[50] = "NO";
  s21_strcpy(d2, s2);
  ck_assert_msg(!strcmp(d2, s2), "2nd strcpy test failed");

  char s3[50] = "";
  char d3[50] = "HELLO";
  s21_strcpy(d3, s3);
  ck_assert_msg(!strcmp(d3, s3), "3rd strcpy test failed");

  char s4[50] = "amogus";
  char d4[50] = "HELLO";
  s21_strcpy(d4, s4);
  ck_assert_msg(!strcmp(d4, s4), "4rth strcpy test failed");

  char s5[50] = "Shrek";
  char d5[50] = "what";
  s21_strcpy(d5, s5);
  ck_assert_msg(!strcmp(d5, s5), "5th strcpy test failed");
}
END_TEST

START_TEST(strncpy_test) {
  char s1[50] = "Sample Text";
  char d1[50] = "";
  s21_strncpy(d1, s1, 2);
  ck_assert_msg(!strcmp(d1, "Sa"), "1st strncpy test failed");

  char s2[50] = "AAAAA";
  char d2[50] = "NO";
  s21_strncpy(d2, s2, 0);
  ck_assert_msg(!strcmp(d2, "NO"), "2nd strncpy test failed");

  char s3[50] = "H";
  char d3[50] = "fELLO";
  s21_strncpy(d3, s3, 1);
  ck_assert_msg(!strcmp(d3, "HELLO"), "3rd strncpy test failed");

  char s4[50] = "amo";
  char d4[50] = "qwegus";
  s21_strncpy(d4, s4, 3);
  ck_assert_msg(!strcmp(d4, "amogus"), "4rth strncpy test failed");

  char s5[50] = "shrek";
  char d5[50] = "s";
  s21_strncpy(d5, s5, 5);
  ck_assert_msg(!strcmp(d5, "shrek"), "5th strncpy test failed");
}
END_TEST

START_TEST(strcspn_test) {
  char *str1 = "0123456789";
  char *str2 = "9876";
  ck_assert_msg(s21_strcspn(str1, str2) == strcspn(str1, str2),
                "1st strcspn test failed");

  char *str3 = "0123456789";
  char *str4 = "";
  ck_assert_msg(s21_strcspn(str3, str4) == strcspn(str3, str4),
                "2nd strcspn test failed");

  char *str5 = "";
  char *str6 = "123";
  ck_assert_msg(s21_strcspn(str5, str6) == strcspn(str5, str6),
                "3rd strcspn test failed");

  char *str7 = "1337";
  char *str8 = "228";
  ck_assert_msg(s21_strcspn(str7, str8) == strcspn(str7, str8),
                "4rth strcspn test failed");

  char *str9 = "19642";
  char *str10 = "64";
  ck_assert_msg(s21_strcspn(str9, str10) == strcspn(str9, str10),
                "5th strcspn test failed");
}
END_TEST

START_TEST(strlen_test) {
  char *s1 = "0123456789";
  ck_assert_msg(s21_strlen(s1) == strlen(s1), "1st strlen test failed");

  char *s2 = "";
  ck_assert_msg(s21_strlen(s2) == strlen(s2), "2nd strlen test failed");

  char *s3 = "amogus";
  ck_assert_msg(s21_strlen(s3) == strlen(s3), "3rd strlen test failed");

  char *s4 = "shrek";
  ck_assert_msg(s21_strlen(s4) == strlen(s4), "4rth strlen test failed");

  char *s5 = "is love";
  ck_assert_msg(s21_strlen(s5) == strlen(s5), "5th strlen test failed");
}
END_TEST

START_TEST(strpbrk_test) {
  char *str1 = "hello";
  char *str2 = "hel";
  char *res1, *res2;
  res1 = s21_strpbrk(str1, str2);
  res2 = strpbrk(str1, str2);
  ck_assert_str_eq(res1, res2);

  char *str4 = "ab";
  res1 = s21_strpbrk(str1, str4);
  res2 = strpbrk(str1, str4);
  ck_assert_ptr_eq(res1, res2);

  char *str5 = "o";
  res1 = s21_strpbrk(str1, str5);
  res2 = strpbrk(str1, str5);
  ck_assert_str_eq(res1, res2);

  char *str6 = "abcdefghjkl";
  char *str7 = "abcd";
  res1 = s21_strpbrk(str6, str7);
  res2 = strpbrk(str6, str7);
  ck_assert_str_eq(res1, res2);

  char *str8 = "amogus is shrek?";
  char *str9 = "is";
  res1 = s21_strpbrk(str8, str9);
  res2 = s21_strpbrk(str8, str9);
  ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(strrchr_test) {
  char *s1 = "School-21";
  char *s2 = "";
  char *s3 = "amogus";

  ck_assert_msg(s21_strrchr(s1, 'm') == strrchr(s1, 'm'),
                "1st strrchr test failed");
  ck_assert_msg(s21_strrchr(s1, 'o') == strrchr(s1, 'o'),
                "2nd strrchr test failed");
  ck_assert_msg(s21_strrchr(s2, 'o') == strrchr(s2, 'o'),
                "3rd strrchr test failed");
  ck_assert_msg(s21_strrchr(s3, ' ') == strrchr(s3, ' '),
                "4rth strrchr test failed");
  ck_assert_msg(s21_strrchr(s3, 's') == strrchr(s3, 's'),
                "5th strrchr test failed");
}
END_TEST

START_TEST(strspn_test) {
  char *s1 = "School-21";
  char *s2 = "ho";
  char *s3 = "";

  ck_assert_msg(s21_strspn(s1, s2) == strspn(s1, s2), "1st strspn test failed");
  ck_assert_msg(s21_strspn(s3, s2) == strspn(s3, s2), "2nd strspn test failed");
  ck_assert_msg(s21_strspn(s2, s3) == strspn(s2, s3), "3rd strspn test failed");
  ck_assert_msg(s21_strspn(s1, s3) == strspn(s1, s3),
                "4rth strspn test failed");
  ck_assert_msg(s21_strspn(s3, s1) == strspn(s3, s1), "5th strspn test failed");
}
END_TEST

START_TEST(strstr_test) {
  char *s1 = "School-21";
  char *s2 = "ho";
  char *s3 = "";

  ck_assert_msg(s21_strstr(s1, s2) == strstr(s1, s2), "1st strstr test failed");
  ck_assert_msg(s21_strstr(s1, s3) == strstr(s1, s3), "2nd strstr test failed");
  ck_assert_msg(s21_strstr(s3, s2) == strstr(s3, s2), "3rd strstr test failed");
  ck_assert_msg(s21_strstr(s2, s3) == strstr(s2, s3),
                "4rth strstr test failed");
  ck_assert_msg(s21_strstr(s3, s1) == strstr(s3, s1), "5th strstr test failed");
}
END_TEST

START_TEST(to_upper_test) {
  char *s1 = "";
  char *s2 = "School is Cool";
  char *s3 = "amogus";
  char *s4 = "Shrek is amogus";
  char *s5 = "what";

  char *r1 = s21_to_upper(s1);
  char *r2 = s21_to_upper(s2);
  char *r3 = s21_to_upper(s3);
  char *r4 = s21_to_upper(s4);
  char *r5 = s21_to_upper(s5);

  ck_assert_str_eq(r1, "");
  ck_assert_str_eq(r2, "SCHOOL IS COOL");
  ck_assert_str_eq(r3, "AMOGUS");
  ck_assert_str_eq(r4, "SHREK IS AMOGUS");
  ck_assert_str_eq(r5, "WHAT");

  free(r1);
  free(r2);
  free(r3);
  free(r4);
  free(r5);
}
END_TEST

START_TEST(to_lower_test) {
  char s1[] = "SChOOl-21";
  char s2[] = "ScHool is CoOl";
  char s3[] = "amogus";
  char s4[] = "ShrEK is Amogus";
  char s5[] = "what";

  char *r1 = s21_to_lower(s1);
  char *r2 = s21_to_lower(s2);
  char *r3 = s21_to_lower(s3);
  char *r4 = s21_to_lower(s4);
  char *r5 = s21_to_lower(s5);

  ck_assert_msg(!strcmp(r1, "school-21"), "1st to_lower test failed");
  ck_assert_msg(!strcmp(r2, "school is cool"), "2nd to_lower test failed");
  ck_assert_msg(!strcmp(r3, "amogus"), "3rd to_lower test failed");
  ck_assert_msg(!strcmp(r4, "shrek is amogus"), "4rth to_lower test failed");
  ck_assert_msg(!strcmp(r5, "what"), "5th to_lower test failed");

  free(r1);
  free(r2);
  free(r3);
  free(r4);
  free(r5);
}
END_TEST

START_TEST(insert_test) {
  char *s1 = "School-21 test";
  char *s2 = "insert ";
  char *s3 = "amogus";
  char *s4 = "is";
  char *s5 = "shrek";
  char *res1 = s21_insert(s1, " ", 3);
  char *res2 = s21_insert(s5, s3, 5);
  char *res3 = s21_insert(s3, s5, 0);
  char *res4 = s21_insert(s5, s4, 5);
  char *res5 = s21_insert(s2, s1, 4);

  ck_assert_str_eq(res1, "Sch ool-21 test");
  ck_assert_str_eq(res2, "shrekamogus");
  ck_assert_str_eq(res3, "shrekamogus");
  ck_assert_str_eq(res4, "shrekis");
  ck_assert_str_eq(res5, "inseSchool-21 testrt ");

  free(res1);
  free(res2);
  free(res3);
  free(res4);
  free(res5);
}
END_TEST

START_TEST(trim_test) {
  char *s1 = "School-21";
  char *s2 = "";
  char *s3 = "S";
  char *s4 = "Sch";
  char *s5 = "School";
  char *s6 = "School-21";
  char *s7 = NULL;
  char *r1 = s21_trim(s1, s2);
  char *r2 = s21_trim(s1, s3);
  char *r3 = s21_trim(s1, s4);
  char *r4 = s21_trim(s1, s5);
  char *r5 = s21_trim(s1, s6);
  char *r6 = s21_trim(s1, s7);
  ck_assert_msg(!strcmp(r1, "School-21"), "1st trim test failed");
  ck_assert_msg(!strcmp(r2, "chool-21"), "2nd trim test failed");
  ck_assert_msg(!strcmp(r3, "ool-21"), "3rd trim test failed");
  ck_assert_msg(!strcmp(r4, "-21"), "4rth trim test failed");
  ck_assert_msg(!strcmp(r5, ""), "5th trim test failed");
  ck_assert_msg(!strcmp(r6, "School-21"), "6th trim test failed");
  free(r1);
  free(r2);
  free(r3);
  free(r4);
  free(r5);
  free(r6);
}
END_TEST

START_TEST(strerror_test) {
  char *str1 = s21_strerror(20);
  char *str2 = strerror(20);
  ck_assert_str_eq(str1, str2);

  char *str3 = s21_strerror(12);
  char *str4 = strerror(12);
  ck_assert_str_eq(str3, str4);

  char *str7 = s21_strerror(1);
  char *str8 = strerror(1);
  ck_assert_str_eq(str7, str8);

  char *str9 = s21_strerror(25);
  char *str10 = strerror(25);
  ck_assert_str_eq(str9, str10);
}
END_TEST

START_TEST(strtok_test) {
  char test1[50] = "aboba,hello,world,trim";
  char test2[50] = "aboba,hello,world,trim";
  char delim1[10] = "123,";
  char *orig1, *copy1;
  orig1 = strtok(test1, delim1);
  copy1 = s21_strtok(test2, delim1);
  char orig_res1[1000] = {0};
  char copy_res1[1000] = {0};
  while (orig1 != NULL) {
    strcat(orig_res1, orig1);
    orig1 = strtok(NULL, delim1);
  }
  while (copy1 != NULL) {
    strcat(copy_res1, copy1);
    copy1 = s21_strtok(NULL, delim1);
  }
  ck_assert_str_eq(orig_res1, copy_res1);

  char str[] = "School-21";
  char *tok1 = s21_strtok(str, "-");
  char *tok2 = strtok(str, "-");
  char *tok3 = s21_strtok(str, "");
  char *tok4 = strtok(str, "");
  char *tok5 = s21_strtok(str, "oo");
  char *tok6 = strtok(str, "oo");
  char *tok7 = s21_strtok(str, "Sc");
  char *tok8 = strtok(str, "Sc");
  char *tok9 = s21_strtok(str, "21");
  char *tok10 = strtok(str, "21");

  ck_assert_msg(!strcmp(tok1, tok2), "1st strtok test failed");
  ck_assert_msg(!strcmp(tok3, tok4), "2nd strtok test failed");
  ck_assert_msg(!strcmp(tok5, tok6), "3rd strtok test failed");
  ck_assert_msg(!strcmp(tok7, tok8), "4rth strtok test failed");
  ck_assert_msg(!strcmp(tok9, tok10), "5th strtok test failed");
}
END_TEST

START_TEST(sscanf_test_e) {
  float e1 = 0, e2 = 0;
  int r1 = 0, r2 = 0;

  r1 = sscanf("123e34", "%e", &e1);
  r2 = s21_sscanf("123e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12e34", "%e", &e1);
  r2 = s21_sscanf("12e34", "%e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.345e-34", "%9e", &e1);
  r2 = s21_sscanf("123.345e-34", "%9e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.345e34", "%8e", &e1);
  r2 = s21_sscanf("123.345e34", "%8e", &e2);
  ck_assert_msg(e1 == e2, "float not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_l) {
  int r1 = 0, r2 = 0;
  unsigned long lu1 = 0, lu2 = 0;
  long ld1 = 0, ld2 = 0;
  wchar_t lc1, lc2, ls1[100], ls2[100];

  r1 = sscanf("a", "%lc", &lc1);
  r2 = s21_sscanf("a", "%lc", &lc2);
  ck_assert_int_eq(lc1, lc2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12345", "%lu", &lu1);
  r2 = s21_sscanf("12345", "%lu", &lu2);
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12345", "%ld", &ld1);
  r2 = s21_sscanf("12345", "%ld", &ld2);
  ck_assert_int_eq(ld1, ld2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("amogus", "%9ls", ls1);
  r2 = s21_sscanf("amogus", "%9ls", ls2);
  ck_assert_int_eq(wcscmp(ls1, ls2), 0);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("amogus", "%2ls", ls1);
  r2 = s21_sscanf("amogus", "%2ls", ls2);
  ck_assert_int_eq(wcscmp(ls1, ls2), 0);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_L) {
  int r1 = 0, r2 = 0;
  long double Lf1 = 0, Lf2 = 0;

  r1 = sscanf("123.45", "%Lf", &Lf1);
  r2 = s21_sscanf("123.45", "%Lf", &Lf2);
  ck_assert_msg((int)Lf1 == (int)Lf2, "floats not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_u) {
  int r1 = 0, r2 = 0;
  unsigned u1 = 0, u2 = 0;

  r1 = sscanf("0x12345", "%2u", &u1);
  r2 = s21_sscanf("0x12345", "%2u", &u2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%u", &u1);
  r2 = s21_sscanf("123.456", "%u", &u2);
  ck_assert_msg(u1 == u2, "floats not equals");
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_h) {
  int r1 = 0, r2 = 0;
  unsigned short hu1 = 0, hu2 = 0;

  r1 = sscanf("12345", "%hu", &hu1);
  r2 = s21_sscanf("12345", "%hu", &hu2);
  ck_assert_int_eq(hu1, hu2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_s) {
  int r1 = 0, r2 = 0;
  char s1[100], s2[100];

  r1 = sscanf("shrek amogus", "%*s%2s", s1);
  r2 = s21_sscanf("shrek amogus", "%*s%2s", s2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_f) {
  int r1 = 0, r2 = 0;
  float f1 = 0, f2 = 0;

  r1 = sscanf("12e-3", "%f", &f1);
  r2 = s21_sscanf("12e-3", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-123.45", "%f", &f1);
  r2 = s21_sscanf("-123.45", "%f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("-12.345", "%5f", &f1);
  r2 = s21_sscanf("-12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("12.345", "%5f", &f1);
  r2 = s21_sscanf("12.345", "%5f", &f2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_o) {
  int r1 = 0, r2 = 0;
  unsigned o1 = 0, o2 = 0;

  r1 = sscanf("12345678", "%3o", &o1);
  r2 = s21_sscanf("12345678", "%3o", &o2);
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123.456", "%o", &o1);
  r2 = s21_sscanf("123.456", "%o", &o2);
  ck_assert_uint_eq(o1, o2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_x) {
  int r1 = 0, r2 = 0;
  unsigned x1 = 0, x2 = 0;

  r1 = sscanf("0x12345", "%2x", &x1);
  r2 = s21_sscanf("0x12345", "%2x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("AMOGUS", "%x", &x1);
  r2 = s21_sscanf("AMOGUS", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("amogus", "%x", &x1);
  r2 = s21_sscanf("amogus", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x1234567890123456789", "%x", &x1);
  r2 = s21_sscanf("0x1234567890123456789", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%x", &x1);
  r2 = s21_sscanf("0x123", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123456", "%x", &x1);
  r2 = s21_sscanf("123456", "%x", &x2);
  ck_assert_uint_eq(x1, x2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_i) {
  int r1 = 0, r2 = 0;
  int i1 = 0, i2 = 0;

  r1 = sscanf("0123", "%i", &i1);
  r2 = s21_sscanf("0123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("0x123", "%i", &i1);
  r2 = s21_sscanf("0x123", "%i", &i2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_proc) {
  char proc1[100] = {0}, proc2[100] = {0};

  sscanf("123.456", "%%%9s", proc1);
  s21_sscanf("123.456", "%%%9s", proc2);
  ck_assert_str_eq(proc1, proc2);
}
END_TEST

START_TEST(sscanf_test_p) {
  void *p1 = 0, *p2 = 0;

  sscanf("0x123", "%4p", &p1);
  s21_sscanf("0x123", "%4p", &p2);
  ck_assert_ptr_eq(p1, p2);

  sscanf("0x12345", "%p", &p1);
  s21_sscanf("0x12345", "%p", &p2);
  ck_assert_ptr_eq(p1, p2);

  sscanf("123.456", "%p", &p1);
  s21_sscanf("123.456", "%p", &p2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_test_n) {
  int n1 = 0, n2 = 0, r1 = 0, r2 = 0;

  r1 = sscanf("123.456", "%n", &n1);
  r2 = s21_sscanf("123.456", "%n", &n2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_d) {
  int r1 = 0, r2 = 0, d1 = 0, d2 = 0;

  r1 = sscanf("123", "%002d", &d1);
  r2 = s21_sscanf("123", "%002d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(sscanf_test_all) {
  int d1 = 0, d2 = 0, i1 = 0, i2 = 0, n1 = 0, n2 = 0, r1 = 0, r2 = 0;
  float e1 = 0, e2 = 0, E1 = 0, E2 = 0, f1 = 0, f2 = 0, g1 = 0, g2 = 0, G1 = 0,
        G2 = 0;
  unsigned o1 = 0, o2 = 0, u1 = 0, u2 = 0, x1 = 0, x2 = 0, X1 = 0, X2 = 0;
  void *p1 = 0, *p2 = 0;
  char s1[100], s2[100], c1, c2, proc1[100] = {0}, proc2[100] = {0};
  short hi1 = 0, hi2 = 0, hd1 = 0, hd2 = 0;
  unsigned long lo1 = 0, lo2 = 0, lu1 = 0, lu2 = 0;
  long double Le1 = 0, Le2 = 0, LE1 = 0, LE2 = 0, Lg1 = 0, Lg2 = 0, LG1 = 0,
              LG2 = 0;

  r1 = sscanf("123", "%d", &d1);
  r2 = s21_sscanf("123", "%d", &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 amogus", "%d%9s", &d1, s1);
  r2 = s21_sscanf("123 amogus", "%d%9s", &d2, s2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("123 amogus q", "%d%9s%c", &d1, s1, &c1);
  r2 = s21_sscanf("123 amogus q", "%d%9s%c", &d2, s2, &c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q", "%i%d%9s%c", &i1, &d1, s1, &c1);
  r2 = s21_sscanf("4 123 amogus q", "%i%d%9s%c", &i2, &d2, s2, &c2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34", "%i%d%9s%c%e", &i1, &d1, s1, &c1, &e1);
  r2 =
      s21_sscanf("4 123 amogus q 12e34", "%i%d%9s%c%e", &i2, &d2, s2, &c2, &e2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21", "%i%d%9s%c%e%E", &i1, &d1, s1, &c1,
              &e1, &E1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21", "%i%d%9s%c%e%E", &i2, &d2, s2,
                  &c2, &e2, &E2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21 13.37", "%i%d%9s%c%e%E%f", &i1, &d1,
              s1, &c1, &e1, &E1, &f1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13,37", "%i%d%9s%c%e%E%f", &i2,
                  &d2, s2, &c2, &e2, &E2, &f2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28", "%i%d%9s%c%e%E%f%g", &i1,
              &d1, s1, &c1, &e1, &E1, &f1, &g1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28", "%i%d%9s%c%e%E%f%g",
                  &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 =
      sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
             "%i%d%9s%c%e%E%f%g%G", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
                  "%i%d%9s%c%e%E%f%g%G", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2,
                  &G2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 =
      sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
             "%i%d%9s%c%e%E%f%g%G", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228",
                  "%i%d%9s%c%e%E%f%g%G", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2,
                  &G2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101",
              "%i%d%9s%c%e%E%f%g%G%o", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
              &G1, &o1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101",
                  "%i%d%9s%c%e%E%f%g%G%o", &i2, &d2, s2, &c2, &e2, &E2, &f2,
                  &g2, &G2, &o2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854",
              "%i%d%9s%c%e%E%f%g%G%o%u", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
              &G1, &o1, &u1);
  r2 = s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854",
                  "%i%d%9s%c%e%E%f%g%G%o%u", &i2, &d2, s2, &c2, &e2, &E2, &f2,
                  &g2, &G2, &o2, &u2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab",
              "%i%d%9s%c%e%E%f%g%G%o%u%x", &i1, &d1, s1, &c1, &e1, &E1, &f1,
              &g1, &G1, &o1, &u1, &x1);
  r2 =
      s21_sscanf("4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab",
                 "%i%d%9s%c%e%E%f%g%G%o%u%x", &i2, &d2, s2, &c2, &e2, &E2, &f2,
                 &g2, &G2, &o2, &u2, &x2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(
      "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
      "%i%d%9s%c%e%E%f%g%G%o%u%x%X", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1, &G1,
      &o1, &u1, &x1, &X1);
  r2 = s21_sscanf(
      "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
      "%i%d%9s%c%e%E%f%g%G%o%u%x%X", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2, &G2,
      &o2, &u2, &x2, &X2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(
      "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
      "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p1", &i1, &d1, s1, &c1, &e1, &E1, &f1, &g1,
      &G1, &o1, &u1, &x1, &X1, &p1);
  r2 = s21_sscanf(
      "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
      "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p2", &i2, &d2, s2, &c2, &e2, &E2, &f2, &g2,
      &G2, &o2, &u2, &x2, &X2, &p2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(
      "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 shrek "
      "& amogus is sus?",
      "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%%", &i1, &d1, s1, &c1, &e1, &E1, &f1,
      &g1, &G1, &o1, &u1, &x1, &X1, &p1, &n1);
  r2 = s21_sscanf(
      "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21",
      "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%%", &i2, &d2, s2, &c2, &e2, &E2, &f2,
      &g2, &G2, &o2, &u2, &x2, &X2, &p2, &n2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(
      "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 shrek "
      "& amogus is sus?",
      "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%9s%%", &i1, &d1, s1, &c1, &e1, &E1, &f1,
      &g1, &G1, &o1, &u1, &x1, &X1, &p1, &n1, proc1);
  r2 = s21_sscanf(
      "4 123 amogus q 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 shrek "
      "& amogus is sus?",
      "%i%d%9s%c%e%E%f%g%G%o%u%x%X%p%n%9s%%", &i2, &d2, s2, &c2, &e2, &E2, &f2,
      &g2, &G2, &o2, &u2, &x2, &X2, &p2, &n2, proc2);
  ck_assert_int_eq(i1, i2);
  ck_assert_int_eq(d1, d2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(o1, o2);
  ck_assert_int_eq(u1, u2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(proc1, proc2);
  ck_assert_int_eq(r1, r2);

  r1 = sscanf(
      "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 shrek "
      "& amogus is sus?",
      "%*i%12hi%4hd%20s%c%3Le%7LE%*i%1f%9Lg%5LG%6lo%12lu%*x%11x%2X%10p%n%21s%%",
      &hi1, &hd1, s1, &c1, &Le1, &LE1, &f1, &Lg1, &LG1, &lo1, &lu1, &x1, &X1,
      &p1, &n1, proc1);
  r2 = s21_sscanf(
      "4 123 amogusq 12e34 43e21 13.37 2.28 1337.228 101 1854 12ab BA21 shrek "
      "& amogus is sus?",
      "%*i%12hi%4hd%20s%c%3Le%7LE%*i%1f%9Lg%5LG%6lo%12lu%*x%11x%2X%10p%n%21s%%",
      &hi2, &hd2, s2, &c2, &Le2, &LE2, &f2, &Lg2, &LG2, &lo2, &lu2, &x2, &X2,
      &p2, &n2, proc2);
  ck_assert_int_eq(hi1, hi2);
  ck_assert_int_eq(hd1, hd2);
  ck_assert_str_eq(s1, s2);
  ck_assert_int_eq(c1, c2);
  ck_assert_msg(e1 == e2, "floats not equals");
  ck_assert_msg(E1 == E2, "floats not equals");
  ck_assert_msg(f1 == f2, "floats not equals");
  ck_assert_msg(g1 == g2, "floats not equals");
  ck_assert_msg(G1 == G2, "floats not equals");
  ck_assert_int_eq(lo1, lo2);
  ck_assert_int_eq(lu1, lu2);
  ck_assert_int_eq(x1, x2);
  ck_assert_int_eq(X1, X2);
  ck_assert_ptr_eq(p1, p2);
  ck_assert_int_eq(n1, n2);
  ck_assert_str_eq(proc1, proc2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test1) {
  char str1[100];
  char str2[100];
  void *p = (void *)0x3456;
  int n1, n2;
  int r1 = sprintf(str1, "%d%o%s%c%i%e%f%E%g%u%x%G%X%n%p%%%s", 25, 342, "aboba",
                   'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345, 12345u,
                   8342, 0.0000456, 1235, &n1, p, "hello my friend");
  int r2 =
      s21_sprintf(str2, "%d%o%s%c%i%e%f%E%g%u%x%G%X%n%p%%%s", 25, 342, "aboba",
                  'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345, 12345u,
                  8342, 0.0000456, 1235, &n2, p, "hello my friend");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test2) {
  char str1[100];
  char str2[100];
  int r1 = sprintf(str1, "%+-25.3d%25.15o%#10.f%015d", 252, 243, 256.34, 15);
  int r2 =
      s21_sprintf(str2, "%+-25.3d%25.15o%#10.f%015d", 252, 243, 256.34, 15);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test3) {
  char str1[100];
  char str2[100];
  int r1 = sprintf(str1, "%#+34.10g%#.10x%#15.1o%25.10s", 25.3456, 1234, 4567,
                   "HELLOMYDEARFRIEND");
  int r2 = s21_sprintf(str2, "%#+34.10g%#.10x%#15.1o%25.10s", 25.3456, 1234,
                       4567, "HELLOMYDEARFRIEND");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test4) {
  char str1[100];
  char str2[100];
  void *p = (void *)43252342;
  int r1 = sprintf(str1, "%#24.e%-15.20i%20p%020u", 43253242.4342, 4567899, p,
                   43252342u);
  int r2 = s21_sprintf(str2, "%#24.e%-15.20i%20p%020u", 43253242.4342, 4567899,
                       p, 43252342u);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
  char str3[50];
  char str4[100];
  int r3 = sprintf(str3, "%*.0f", 25, 25432.34345);
  int r4 = s21_sprintf(str4, "%*.0f", 25, 25432.34345);
  ck_assert_str_eq(str3, str4);
  ck_assert_int_eq(r3, r4);
}
END_TEST

START_TEST(s21_sprintf_test_d) {
  char str1[1000];
  char str2[1000];
  short h = 34;
  int r1 = sprintf(
      str1, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
      335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
  int r2 = s21_sprintf(
      str2, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
      335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_i) {
  char str1[1000];
  char str2[1000];
  short h = 34;
  long l = 2353423523424;
  int r1 = sprintf(str1, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                   34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
  int r2 =
      s21_sprintf(str2, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                  34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_c) {
  char str1[1000];
  char str2[1000];
  wint_t c1 = 'T', c2 = 'Z';
  int r1 = sprintf(str1, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a', 'e',
                   'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
  int r2 = s21_sprintf(str2, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a',
                       'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_e) {
  char str1[1000];
  char str2[1000];
  int r1 =
      sprintf(str1, "%+-20e%010.*e%-*.16e%#025.10e%*.*e%*.15e%#010.*e%25.16e",
              2543.43254, 10, 1012.34567, 15, -0.00123, 45678.342532, 10, 15,
              11111.22, 16, -3245.3425342, 16, -0.00123, 235423424.43252);
  int r2 = s21_sprintf(
      str2, "%+-20e%010.*e%-*.16e%#025.10e%*.*e%*.15e%#010.*e%25.16e",
      2543.43254, 10, 1012.34567, 15, -0.00123, 45678.342532, 10, 15, 11111.22,
      16, -3245.3425342, 16, -0.00123, 235423424.43252);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_E) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(str1, "%+-25.4E%25.*E%-*.10E%#02.E%*.*E%*.15E%*E%12.16E",
                   3456.4325, 10, 23452.43242, 5, -0.05234, 25.432523432, 10, 2,
                   53242.4242, 10, 456789.43242, 25, 1111122222.34567899,
                   2345678.23453242);
  int r2 = s21_sprintf(str2, "%+-25.4E%25.*E%-*.10E%#02.E%*.*E%*.15E%*E%12.16E",
                       3456.4325, 10, 23452.43242, 5, -0.05234, 25.432523432,
                       10, 2, 53242.4242, 10, 456789.43242, 25,
                       1111122222.34567899, 2345678.23453242);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_f) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(
      str1, "%+-10.5f%+10.2f%15.16f%+*.10f%*.16f%-10.*f%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  int r2 = s21_sprintf(
      str2, "%+-10.5f%+10.2f%15.16f%+*.10f%*.16f%-10.*f%25.*f%25.f%#+10.f%*.*f",
      2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
      2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
      34567.43244);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_o) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 253;
  unsigned long l = 4325234324242l;
  int r1 = sprintf(str1, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                   12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  int r2 =
      s21_sprintf(str2, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                  12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_x) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 345;
  unsigned long l = 52342353242l;
  int r1 = sprintf(str1,
                   "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%20.*"
                   "x%#10.*x%*.5hx%10.25lx",
                   235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                   8, 23452, 10, 34254, 3, 33334, 10, h, l);
  int r2 = s21_sprintf(str2,
                       "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%"
                       "20.*x%#10.*x%*.5hx%10.25lx",
                       235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                       3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_X) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 234;
  unsigned long l = 4325243132l;
  int r1 = sprintf(str1,
                   "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%21.*X%"
                   "#12.*X%*.8hx%14.12lX",
                   235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                   8, 23452, 10, 34254, 3, 33334, 10, h, l);
  int r2 = s21_sprintf(str2,
                       "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%"
                       "21.*X%#12.*X%*.8hx%14.12lX",
                       235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                       3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_u) {
  char str1[1000];
  char str2[1000];
  unsigned short h = 115;
  unsigned long l = 123325242342l;
  int r1 =
      sprintf(str1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
              4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u,
              20, 2432u, l, h);
  int r2 = s21_sprintf(
      str2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu", 4321u,
      34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l,
      h);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_s) {
  char str1[1000];
  char str2[1000];
  wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
  int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                   "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                   "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
  int r2 =
      s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                  "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                  "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_p) {
  char str1[1000];
  char str2[1000];
  void *p1 = (void *)0x123456789;
  void *p2 = (void *)4325234;
  void *p3 = (void *)0x123f324b;
  void *p4 = (void *)432520;
  int r1 = sprintf(str1, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4, p2,
                   10, p3, p1, 10, p4);
  int r2 = s21_sprintf(str2, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4,
                       p2, 10, p3, p1, 10, p4);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_percent) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_g) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(
      str1, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
      2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
      2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
  int r2 = s21_sprintf(
      str2, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
      2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
      2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(s21_sprintf_test_G) {
  char str1[1000];
  char str2[1000];
  int r1 = sprintf(
      str1,
      "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
      43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
      111.432534243243242, 4324.43242, 25, -3213.43242, 16, -43.43242353242342,
      111.24324242, 25, 5, 0.000000342);
  int r2 = s21_sprintf(
      str2,
      "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
      43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
      111.432534243243242, 4324.43242, 25, -3213.43242, 16, -43.43242353242342,
      111.24324242, 25, 5, 0.000000342);
  ck_assert_str_eq(str1, str2);
  ck_assert_int_eq(r1, r2);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, memchr_test);
  tcase_add_test(tc1_1, memcmp_test);
  tcase_add_test(tc1_1, memcpy_test);
  tcase_add_test(tc1_1, memmove_test);
  tcase_add_test(tc1_1, memset_test);
  tcase_add_test(tc1_1, strcat_test);
  tcase_add_test(tc1_1, strncat_test_1);
  tcase_add_test(tc1_1, strncat_test_2);
  tcase_add_test(tc1_1, strchr_test);
  tcase_add_test(tc1_1, strcmp_test);
  tcase_add_test(tc1_1, strncmp_test);
  tcase_add_test(tc1_1, strcpy_test);
  tcase_add_test(tc1_1, strncpy_test);
  tcase_add_test(tc1_1, strcspn_test);
  tcase_add_test(tc1_1, strlen_test);
  tcase_add_test(tc1_1, strpbrk_test);
  tcase_add_test(tc1_1, strrchr_test);
  tcase_add_test(tc1_1, strspn_test);
  tcase_add_test(tc1_1, strstr_test);
  tcase_add_test(tc1_1, to_upper_test);
  tcase_add_test(tc1_1, to_lower_test);
  tcase_add_test(tc1_1, insert_test);
  tcase_add_test(tc1_1, trim_test);
  tcase_add_test(tc1_1, strerror_test);
  tcase_add_test(tc1_1, strtok_test);
  tcase_add_test(tc1_1, sscanf_test_e);
  tcase_add_test(tc1_1, sscanf_test_l);
  tcase_add_test(tc1_1, sscanf_test_L);
  tcase_add_test(tc1_1, sscanf_test_u);
  tcase_add_test(tc1_1, sscanf_test_h);
  tcase_add_test(tc1_1, sscanf_test_s);
  tcase_add_test(tc1_1, sscanf_test_f);
  tcase_add_test(tc1_1, sscanf_test_o);
  tcase_add_test(tc1_1, sscanf_test_x);
  tcase_add_test(tc1_1, sscanf_test_i);
  tcase_add_test(tc1_1, sscanf_test_proc);
  tcase_add_test(tc1_1, sscanf_test_p);
  tcase_add_test(tc1_1, sscanf_test_n);
  tcase_add_test(tc1_1, sscanf_test_d);
  tcase_add_test(tc1_1, sscanf_test_all);
  tcase_add_test(tc1_1, s21_sprintf_test1);
  tcase_add_test(tc1_1, s21_sprintf_test2);
  tcase_add_test(tc1_1, s21_sprintf_test3);
  tcase_add_test(tc1_1, s21_sprintf_test4);
  tcase_add_test(tc1_1, s21_sprintf_test_d);
  tcase_add_test(tc1_1, s21_sprintf_test_i);
  tcase_add_test(tc1_1, s21_sprintf_test_c);
  tcase_add_test(tc1_1, s21_sprintf_test_e);
  tcase_add_test(tc1_1, s21_sprintf_test_E);
  tcase_add_test(tc1_1, s21_sprintf_test_f);
  tcase_add_test(tc1_1, s21_sprintf_test_o);
  tcase_add_test(tc1_1, s21_sprintf_test_x);
  tcase_add_test(tc1_1, s21_sprintf_test_X);
  tcase_add_test(tc1_1, s21_sprintf_test_u);
  tcase_add_test(tc1_1, s21_sprintf_test_s);
  tcase_add_test(tc1_1, s21_sprintf_test_p);
  tcase_add_test(tc1_1, s21_sprintf_test_percent);
  tcase_add_test(tc1_1, s21_sprintf_test_g);
  tcase_add_test(tc1_1, s21_sprintf_test_G);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
