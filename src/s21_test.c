
#include "s21_test.h"
// ===================== memchr =====================

START_TEST(memchr_test_01) {
  char str[20] = "Hello, world!\0";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

// ====== memchr SUITE ======

Suite *memchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====S21_MEMCHR=====\033[0m");
  tc_core = tcase_create("MemchrCore");

  tcase_add_test(tc_core, memchr_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

/////////////////////////
/////////////////////////
/////////////////////////

START_TEST(s21_memchr_test_1) {
  int a = 'f';
  char string[] = "qwerty_fow,fow_qwerty";
  ck_assert_ptr_eq(memchr(string, a, 15), s21_memchr(string, a, 15));
}
END_TEST
START_TEST(s21_memchr_test_2) {
  int a = 'W';
  char string[] = "qwerty_foW,Fow_qwerty";
  ck_assert_ptr_eq(memchr(string, a, 15), s21_memchr(string, a, 15));
}
END_TEST
START_TEST(s21_memchr_test_3) {
  int a = 'X';
  char string[] = "qwerty_foW,Fow_qwerty";
  ck_assert_ptr_eq(memchr(string, a, 21), s21_memchr(string, a, 21));
}
// START_TEST(s21_memchr_test_4) {
//   int a = 'X';
//   char string[] = "qwerty_foW,Fow_qwerty";
//   ck_assert_ptr_eq(s21_memchr(string, a, 100), memchr(string, a, 100));
// }
END_TEST
START_TEST(s21_memchr_test_5) {
  int a = 'w';
  char string[] = "qwerty_fow,fow_qwerty";
  ck_assert_ptr_eq(memchr(string, a, 1), s21_memchr(string, a, 1));
}
END_TEST
START_TEST(s21_memchr_test_6) {
  int a = ',';
  char string[] = "qwerty_fow,fow_qwerty";
  ck_assert_ptr_eq(memchr(string, a, 0), s21_memchr(string, a, 0));
}
END_TEST
START_TEST(s21_memchr_test_7) {
  int a = '\0';
  char string[] = "qwerty_fow,\0fow_qwerty";
  ck_assert_ptr_eq(memchr(string, a, 20), s21_memchr(string, a, 20));
}
END_TEST
START_TEST(s21_memchr_test_8) {
  int a = '\\';
  char string[] = "qwerty_fow,\0fow_qwerty";
  ck_assert_ptr_eq(memchr(string, a, 21), s21_memchr(string, a, 21));
}
END_TEST
START_TEST(s21_memchr_test_9) {
  int a = ' ';
  char string[] = "aaaaaa aaa";
  ck_assert_ptr_eq(memchr(string, a, 10), s21_memchr(string, a, 10));
}
END_TEST
START_TEST(s21_memchr_test_10) {
  char string[] = "qwerty_fow,fow_qwerty";
  ck_assert_ptr_eq(memchr(string, 33, 10), s21_memchr(string, 33, 10));
}
END_TEST

Suite *s21_memchr_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_memchr");
  tc = tcase_create("case_memchr");
  tcase_add_test(tc, s21_memchr_test_1);
  tcase_add_test(tc, s21_memchr_test_2);
  tcase_add_test(tc, s21_memchr_test_3);
  tcase_add_test(tc, s21_memchr_test_5);
  tcase_add_test(tc, s21_memchr_test_6);
  tcase_add_test(tc, s21_memchr_test_7);
  tcase_add_test(tc, s21_memchr_test_8);
  tcase_add_test(tc, s21_memchr_test_9);
  tcase_add_test(tc, s21_memchr_test_10);

  suite_add_tcase(s, tc);
  return s;
}

////////////////////////
////////////////////////

// ===================== memcmp =====================

START_TEST(memcmp_test_01) {
  char str[20] = "Ohayo, Sempai!\0";
  char str2[20] = "Ohayo, Sempai!\0";
  s21_size_t n = 10;
  ck_assert_int_eq(memcmp(str, str2, n), s21_memcmp(str, str2, n));
}
END_TEST

// ====== memcmp SUITE ======

Suite *memcmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====S21_MEMCMP=====\033[0m");
  tc_core = tcase_create("MemcmpCore");

  tcase_add_test(tc_core, memcmp_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

////////////////////////
////////////////////////
////////////////////////

// 1 - Сравнение пустых строк
START_TEST(s21_memcmp_test_1) {
  char string_1[] = "";
  char string_2[] = "";
  ck_assert_int_eq(memcmp(string_1, string_2, 0),
                   s21_memcmp(string_1, string_2, 0));
}
END_TEST

// 2 - Сравнение строк одинаковой длины
START_TEST(s21_memcmp_test_2) {
  char string_1[] = "Eto moya pomoyka!";
  char string_2[] = "Eto moya pomoyka!";
  ck_assert_int_eq(memcmp(string_1, string_2, sizeof(string_1)),
                   s21_memcmp(string_1, string_2, sizeof(string_1)));
}
END_TEST

// 4 - Сравнение строк с разными символами
START_TEST(s21_memcmp_test_4) {
  char string_1[] = "Eto moya pomoyka?";
  char string_2[] = "Eto moya pomoyka!";
  ck_assert_int_eq(memcmp(string_1, string_2, sizeof(string_1)),
                   s21_memcmp(string_1, string_2, sizeof(string_1)));
}
END_TEST

// 5 - Сравнение строк с учетом лексикографического порядка
START_TEST(s21_memcmp_test_5) {
  char string_1[] = "Eto moya pomoyka!";
  char string_2[] = "Pomoyka eto moya!";
  ck_assert_int_eq(memcmp(string_1, string_2, sizeof(string_1)),
                   s21_memcmp(string_1, string_2, sizeof(string_1)));
}
END_TEST

// 7 - Сравнение строк при нулевом символе
START_TEST(s21_memcmp_test_7) {
  char string_1[] = "Eto moya \0pomoyka!";
  char string_2[] = "Eto moya pomoyka\0!";
  ck_assert_int_eq(memcmp(string_1, string_2, sizeof(string_1)),
                   s21_memcmp(string_1, string_2, sizeof(string_1)));
}
END_TEST


// 9 - При использовании разного регистра
START_TEST(s21_memcmp_test_9) {
  char string_1[] = "Eto moya pomoyka!";
  char string_2[] = "Eto moya Pomoyka!";
  ck_assert_int_eq(memcmp(string_1, string_2, sizeof(string_1)),
                   s21_memcmp(string_1, string_2, sizeof(string_1)));
}
END_TEST

Suite *s21_memcmp_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_memcmp");
  tc = tcase_create("case_memcmp");
  tcase_add_test(tc, s21_memcmp_test_1);
  tcase_add_test(tc, s21_memcmp_test_2);
  tcase_add_test(tc, s21_memcmp_test_4);
  tcase_add_test(tc, s21_memcmp_test_5);
  tcase_add_test(tc, s21_memcmp_test_7);
  tcase_add_test(tc, s21_memcmp_test_9);

  suite_add_tcase(s, tc);
  return s;
}

/////////////////////////
/////////////////////////

// ===================== memcpy =====================

START_TEST(memcpy_test_01) {
  char str[20] = "This is Elon Musk.";
  char str2[20] = "This is Elon Musk.";
  char str3[25] = "Tesla's co-founder & CEO";
  s21_size_t n = 9;
  ck_assert_int_eq(memcmp(str, str3, n), s21_memcmp(str2, str3, n));
}
END_TEST

// ====== memcpy SUITE ======

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====S21_MEMCPY=====\033[0m");
  tc_core = tcase_create("MemcpyCore");

  tcase_add_test(tc_core, memcpy_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

////////////////////////////////
///////////////////////////////
///////////////////////////////

// 1 - тест на копирование части destination'a

START_TEST(s21_memcpy_test_1) {
  char source[] = "Help me!";
  char destination_1[] = "Menya zastavili pisat' tetsti";
  char destination_2[] = "Menya zastavili pisat' tetsti";

  memcpy(destination_1, source, 4);
  s21_memcpy(destination_2, source, 4);
  ck_assert_str_eq(destination_1, destination_2);
}
END_TEST

// 2 - тест на копирование отрезка destination'a

START_TEST(s21_memcpy_test_2) {
  char source[] = "Help me!";
  char destination_1[] = "Menya zastavili pisat' tetsti";
  char destination_2[] = "Menya zastavili pisat' tetsti";

  memcpy(destination_1, source + 5, 3);
  s21_memcpy(destination_2, source + 5, 3);

  ck_assert_str_eq(destination_1, destination_2);
}
END_TEST

// 3 - тест на идентичность строк
START_TEST(s21_memcpy_test_3) {
  char source[] = "Help me!";
  char destination_1[20] = {'\0'};  // используются мусорные данные...
  char destination_2[20] = {'\0'};

  memcpy(destination_1, source, sizeof(source));  // ...т.к занимаем всю память
  s21_memcpy(destination_2, source, sizeof(source));

  ck_assert_str_eq(destination_1, destination_2);
}
END_TEST

// 4 - тест на идентичность скопированных блоков памяти
START_TEST(s21_memcpy_test_4) {
  int source[] = {1, 2, 3, 4, 5};
  int destination_1[5] = {'\0'};
  int destination_2[5] = {'\0'};

  memcpy(destination_1, source, sizeof(source));
  s21_memcpy(destination_2, source, sizeof(source));

  ck_assert_mem_eq(destination_1, destination_2, sizeof(source));
}

// 5 - тест на возвращаемое значение
END_TEST
START_TEST(s21_memcpy_test_5) {
  char source[] = "Help me!";
  char destination_1[20] = {'\0'};
  char destination_2[20] = {'\0'};

  void *res_1 = memcpy(destination_1, source, sizeof(source));
  void *res_2 = s21_memcpy(destination_2, source, sizeof(source));

  ck_assert_ptr_eq(res_1, destination_1);
  ck_assert_ptr_eq(res_2, destination_2);
}

// 6 - тест на копирование пустых строк
START_TEST(s21_memcpy_test_6) {
  char source[] = "";
  char destination_1[20] = {'\0'};
  char destination_2[20] = {'\0'};

  memcpy(destination_1, source, sizeof(source));
  s21_memcpy(destination_2, source, sizeof(source));

  ck_assert_str_eq(destination_1, destination_2);
}
END_TEST

Suite *s21_memcpy_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_memcpy");
  tc = tcase_create("case_memcpy");
  tcase_add_test(tc, s21_memcpy_test_1);
  tcase_add_test(tc, s21_memcpy_test_2);
  tcase_add_test(tc, s21_memcpy_test_3);
  tcase_add_test(tc, s21_memcpy_test_4);
  tcase_add_test(tc, s21_memcpy_test_5);
  tcase_add_test(tc, s21_memcpy_test_6);

  suite_add_tcase(s, tc);
  return s;
}

///////////////////////////////
///////////////////////////////

// ===================== memset =====================

START_TEST(memset_test_01) {
  char str[20] = "This is Elon Musk.";
  char str2[20] = "This is Elon Musk.";
  char ch = ' ';
  s21_size_t n = strlen(str);
  ck_assert_str_eq(memset(str, ch, n), s21_memset(str2, ch, n));
}
END_TEST

// ====== memset SUITE ======

Suite *memset_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====S21_MEMSET=====\033[0m");
  tc_core = tcase_create("MemchrCore");

  tcase_add_test(tc_core, memset_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

/////////////////////////////
/////////////////////////////
/////////////////////////////

// 1 - тест на заполнение части массива символами
START_TEST(s21_memset_test_1) {
  char array_1[] = "AAAAAAAAAA";
  char array_2[] = "AAAAAAAAAA";

  memset(array_1, 'X', 3);
  s21_memset(array_2, 'X', 3);

  ck_assert_mem_eq(array_1, array_2, sizeof(array_1));
}

// 2 - тест на заполнение отрезка массива символами
START_TEST(s21_memset_test_2) {
  char array_1[] = "AAAAAAAAAA";
  char array_2[] = "AAAAAAAAAA";

  memset(array_1 + 3, 'X', 3);
  s21_memset(array_2 + 3, 'X', 3);

  ck_assert_mem_eq(array_1, array_2, sizeof(array_1));
}
// 3 - тест на заполнение массива символами
START_TEST(s21_memset_test_3) {
  char array_1[10] = {'\0'};
  char array_2[10] = {'\0'};

  memset(array_1, 'X', sizeof(array_1));
  s21_memset(array_2, 'X', sizeof(array_2));

  ck_assert_mem_eq(array_1, array_2, sizeof(array_1));
}
END_TEST

// 4 - тест на заполнение массива нулевыми байтами
START_TEST(s21_memset_test_4) {
  int array_1[5] = {'\0'};
  int array_2[5] = {'\0'};

  memset(array_1, 0, sizeof(array_1));
  s21_memset(array_2, 0, sizeof(array_2));

  ck_assert_mem_eq(array_1, array_2, sizeof(array_1));
}

// 5 - Тест на возвращаемое значение
START_TEST(s21_memset_test_5) {
  char array_1[10] = {'\0'};
  char array_2[10] = {'\0'};

  void *result_1 = memset(array_1, 'X', sizeof(array_1));
  void *result_2 = memset(array_2, 'X', sizeof(array_2));

  ck_assert_ptr_eq(result_1, array_1);
  ck_assert_ptr_eq(result_2, array_2);
}

// 6 - тест на заполнение массива отрицательными значениями
START_TEST(s21_memset_test_6) {
  unsigned char array_1[10] = {'\0'};
  unsigned char array_2[10] = {'\0'};

  memset(array_1, -1, sizeof(array_1));
  s21_memset(array_2, -1, sizeof(array_2));

  ck_assert_mem_eq(array_1, array_2, sizeof(array_1));
}
END_TEST

Suite *s21_memset_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_memset");
  tc = tcase_create("case_memset");
  tcase_add_test(tc, s21_memset_test_1);
  tcase_add_test(tc, s21_memset_test_2);
  tcase_add_test(tc, s21_memset_test_3);
  tcase_add_test(tc, s21_memset_test_4);
  tcase_add_test(tc, s21_memset_test_5);
  tcase_add_test(tc, s21_memset_test_6);

  suite_add_tcase(s, tc);
  return s;
}

//////////////////////////////
//////////////////////////////

// ===================== strncat =====================

START_TEST(strncat_test_01) {
  char str[20] = "This is Elon Musk.";
  char str2[20] = "This is Elon Musk.";
  char str3[20] = "This is Elon Musk.";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(str, str3, n), s21_strncat(str2, str3, n));
}
END_TEST

// ====== strncat SUITE ======

Suite *strncat_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====S21_STRNCAT=====\033[0m");
  tc_core = tcase_create("StrncatCore");

  tcase_add_test(tc_core, strncat_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

////////////////////////////////////
////////////////////////////////////
////////////////////////////////////

// 1 - Тест на конкатенацию строк
START_TEST(s21_strncat_test_1) {
  //для str1 и str2 обязательно нужно выделять память, чтобы вместить str3
  char str1[255] = "Ya hochu ";
  char str2[255] = "Ya hochu ";
  char str3[] = "spat'";
  int n = sizeof(str3) - 1;

  strncat(str1, str3, n);
  s21_strncat(str2, str3, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// 2 - Тест на копирование пустой строки
START_TEST(s21_strncat_test_2) {
  char str1[255] = "Ya hochu ";
  char str2[255] = "Ya hochu ";
  char str3[] = "";
  int n = sizeof(str3) - 1;

  strncat(str1, str3, n);
  s21_strncat(str2, str3, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// 3 - Тест на копирование пустой исходной строки
START_TEST(s21_strncat_test_3) {
  char str1[255] = "";
  char str2[255] = "";
  char str3[] = "spat'";
  int n = sizeof(str3) - 1;

  strncat(str1, str3, n);
  s21_strncat(str2, str3, n);

  ck_assert_str_eq(str1, str2);
}
END_TEST

// 4 - Тест на копирование определенного кол-ва байтов
START_TEST(s21_strncat_test_4) {
  char str1[15] = "Ya hochu ";
  char str2[15] = "Ya hochu ";
  char str3[] = "spat'";

  strncat(str1, str3, 3);
  s21_strncat(str2, str3, 3);

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *s21_strncat_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strncat");
  tc = tcase_create("case_strncat");
  tcase_add_test(tc, s21_strncat_test_1);
  tcase_add_test(tc, s21_strncat_test_2);
  tcase_add_test(tc, s21_strncat_test_3);
  tcase_add_test(tc, s21_strncat_test_4);

  suite_add_tcase(s, tc);
  return s;
}

////////////////////////////////////
////////////////////////////////////

// ===================== strlen =====================

START_TEST(strlen_test_01) {
  char str[10] = "TEST\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_02) {
  char str[20] = "Lorem\nipsum";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_03) {
  char str[20] = "\0Lorem\0Ipsum\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_04) {
  char str[20] = "\nLoremIpsum";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_05) {
  char str[20] = "\0\nLorem Ipsum";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_06) {
  char str[15] = "1234567890\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_07) {
  char str[10] = "TEST\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_08) {
  char str[10] = "TEST\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_09) {
  char str[10] = "TEST\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(strlen_test_10) {
  char str[10] = "TEST\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

// ====== strlen ======

Suite *strlen_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("\033[35m=====S21_SRLEN=====\033[0m");
  tc_core = tcase_create("StrlenCore");

  tcase_add_test(tc_core, strlen_test_01);
  tcase_add_test(tc_core, strlen_test_02);
  tcase_add_test(tc_core, strlen_test_03);
  tcase_add_test(tc_core, strlen_test_04);
  tcase_add_test(tc_core, strlen_test_05);
  tcase_add_test(tc_core, strlen_test_06);
  tcase_add_test(tc_core, strlen_test_07);
  tcase_add_test(tc_core, strlen_test_08);
  tcase_add_test(tc_core, strlen_test_09);
  tcase_add_test(tc_core, strlen_test_10);
  suite_add_tcase(s, tc_core);
  return s;
}

////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

// 1 - Тест на пустую строку
START_TEST(s21_strlen_test_1) {
  const char str[] = "";

  s21_size_t res1 = strlen(str);
  s21_size_t res2 = s21_strlen(str);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 2 - Тест на строку с ненулевой длиной
START_TEST(s21_strlen_test_2) {
  const char str[] = "Hello, World!";

  s21_size_t res1 = strlen(str);
  s21_size_t res2 = s21_strlen(str);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 3 - Тест на строку с большой длиной
START_TEST(s21_strlen_test_3) {
  const char str[1447] = "A";

  s21_size_t res1 = strlen(str);
  s21_size_t res2 = s21_strlen(str);

  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_strlen_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_sstrlen");
  tc = tcase_create("case_strlen");
  tcase_add_test(tc, s21_strlen_test_1);
  tcase_add_test(tc, s21_strlen_test_2);
  tcase_add_test(tc, s21_strlen_test_3);

  suite_add_tcase(s, tc);
  return s;
}

////////////////////////////////////////////////
////////////////////////////////////////////////

// ====== strcspn ======

START_TEST(strcspn_test_01) {
  char str[10] = "1-Lorem";
  char str1[15] = "1234567890";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(strcspn_test_02) {
  char str[60] = "The quick brown fox jumps over a lazy dog";
  char str1[10] = "quick";
  ck_assert_int_eq(strcspn(str, str1), s21_strcspn(str, str1));
}
END_TEST

START_TEST(s21_strcspn_test_03) {
  char str[30] = "Lorem ipsum dolor sit ame";
  ck_assert_int_eq(strcspn(str, "text"), s21_strcspn(str, "text"));
}
END_TEST

START_TEST(s21_strcspn_test_04) {
  char str[50] = "example_mail@\nstudent.21-schoool.ru";
  ck_assert_int_eq(strcspn(str, "@s"), s21_strcspn(str, "@s"));
}
END_TEST

START_TEST(s21_strcspn_test_05) {
  char str[10] = "\0\n";
  ck_assert_int_eq(strcspn(str, "\n"), s21_strcspn(str, "\n"));
}
END_TEST

START_TEST(s21_strcspn_test_06) {
  char str[13] = "Hello, World";
  ck_assert_int_eq(strcspn(str, "xyz"), s21_strcspn(str, "xyz"));
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====s21_STRCSPN=====\033[0m");
  tc_core = tcase_create("StrcspnCore");

  tcase_add_test(tc_core, strcspn_test_01);
  tcase_add_test(tc_core, strcspn_test_02);
  tcase_add_test(tc_core, s21_strcspn_test_03);
  tcase_add_test(tc_core, s21_strcspn_test_04);
  tcase_add_test(tc_core, s21_strcspn_test_05);
  tcase_add_test(tc_core, s21_strcspn_test_06);
  suite_add_tcase(s, tc_core);
  return s;
}

////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

// 1 - Тест на поиск символа, который не содержится в строке
START_TEST(s21_strcspn_test_1) {
  const char str1[] = "Tom's Dinner song";
  const char str2[] = "12312312312312312";

  s21_size_t res1 = strcspn(str1, str2);
  s21_size_t res2 = s21_strcspn(str1, str2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 2 - Тест на поиск символа, который находится в начале строки
START_TEST(s21_strcspn_test_2) {
  const char str1[] = "Tom's Dinner song";
  const char str2[] = "T";

  s21_size_t res1 = strcspn(str1, str2);
  s21_size_t res2 = s21_strcspn(str1, str2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 3 - Тест на поиск символа, который находится в конце строки
START_TEST(s21_strcspn_test_3) {
  const char str1[] = "Tom's Dinner song";
  const char str2[] = "g";

  s21_size_t res1 = strcspn(str1, str2);
  s21_size_t res2 = s21_strcspn(str1, str2);

  ck_assert_int_eq(res1, res2);
}
END_TEST
#include <stdio.h>
// 4 - Тест на поиск символа, который находится в середине строки
START_TEST(s21_strcspn_test_4) {
  const char str1[] = "Tom's Dinner song";
  const char str2[] = "n";

  s21_size_t res1 = strcspn(str1, str2);
  s21_size_t res2 = s21_strcspn(str1, str2);
  // printf("\n\n\n%d, %d\n\n\n", sizeof(res1), sizeof(res2));
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(s21_strcspn_test_5) {
  const char str1[] = "Tom's Dinner song";
  const char str2[] = "";

  s21_size_t res1 = strcspn(str1, str2);
  s21_size_t res2 = s21_strcspn(str1, str2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 6 - Тест на поиск пустой строки
START_TEST(s21_strcspn_test_6) {
  const char str1[] = "";
  const char str2[] = "!@#$abc^&*()";

  s21_size_t res1 = strcspn(str1, str2);
  s21_size_t res2 = s21_strcspn(str1, str2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 7 - Тест на поиск \n
START_TEST(s21_strcspn_test_7) {
  const char str1[] = "Tom's Dinner\nsong";
  const char str2[] = "\n";

  s21_size_t res1 = strcspn(str1, str2);
  s21_size_t res2 = s21_strcspn(str1, str2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 8 - Тест на разый регистр
START_TEST(s21_strcspn_test_8) {
  const char str1[] = "Tom's Dinner song";
  const char str2[] = "d";

  s21_size_t res1 = strcspn(str1, str2);
  s21_size_t res2 = s21_strcspn(str1, str2);

  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_strcspn_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strcspn");
  tc = tcase_create("case_strcspn");
  tcase_add_test(tc, s21_strcspn_test_1);
  tcase_add_test(tc, s21_strcspn_test_2);
  tcase_add_test(tc, s21_strcspn_test_3);
  tcase_add_test(tc, s21_strcspn_test_4);
  tcase_add_test(tc, s21_strcspn_test_5);
  tcase_add_test(tc, s21_strcspn_test_6);
  tcase_add_test(tc, s21_strcspn_test_7);
  tcase_add_test(tc, s21_strcspn_test_8);

  suite_add_tcase(s, tc);
  return s;
}

////////////////////////////////////////////////
////////////////////////////////////////////////

// ===================== strchr =====================

START_TEST(strchr_test_01) {
  char str[10] = "1-Lorem";
  int ch = 'o';
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

START_TEST(strchr_test_02) {
  char str[400] =
      "§123456789900-=qwwerttyuiioopp[[]assdfghjkl;;'\\`zxcvbnm,../"
      "±!@#$%^&*()_+QWERTYUIOP{{{{{{}ASDFGHJKL:\"|~ZXCVBNM<<>>?>1234567890-="
      "йцукенгшщзхъъфывапролджэё]ячсмитьбю/"
      "<!\"№%:,.;()_+ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЁ[ЯЧСМИТЬБЮ?";
  int ch = 255;
  ck_assert_pstr_eq(strchr(str, ch), s21_strchr(str, ch));
}
END_TEST

Suite *strchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====s21_STRCHR=====\033[0m");
  tc_core = tcase_create("StrchrCore");

  tcase_add_test(tc_core, strchr_test_01);
  tcase_add_test(tc_core, strchr_test_02);

  suite_add_tcase(s, tc_core);
  return s;
}

///////////////////////////////////////////
//////////////////////////////////////////
///////////////////////////////////////////

// 1 - Тест на поиск символа в строке
START_TEST(s21_strchr_test_1) {
  const char str[] = "Naydi tut Xy";

  char *res_1 = strchr(str, 'X');
  char *res_2 = s21_strchr(str, 'X');
  ck_assert_ptr_eq(res_1, res_2);
}
END_TEST

// 2 - Тест на поиск символа, отсутствующего в строке
START_TEST(s21_strchr_test_2) {
  const char str[] = "Naydi tut Xy";

  char *res_1 = strchr(str, 'Z');
  char *res_2 = s21_strchr(str, 'Z');

  ck_assert_ptr_eq(res_1, res_2);
}
END_TEST

// 3 - Тест на поиск символа в пустой строке
START_TEST(s21_strchr_test_3) {
  const char str[] = "";

  char *res_1 = strchr(str, 'X');
  char *res_2 = s21_strchr(str, 'X');

  ck_assert_ptr_eq(res_1, res_2);
}
END_TEST

// 4 - Тест на поиск символа, когда символ является нулевым символом
START_TEST(s21_strchr_test_4) {
  const char str[] = "Naydi\0Xy";
  char *res_1 = strchr(str, '\0');
  char *res_2 = s21_strchr(str, '\0');

  ck_assert_ptr_eq(res_1, res_2);
}
END_TEST

// 5 - Тест на поиск символа, когда символ находится в конце строки
START_TEST(s21_strchr_test_5) {
  const char str[] = "Naydi tut Xy";
  char *res_1 = strchr(str, 'y');
  char *res_2 = s21_strchr(str, 'y');

  ck_assert_ptr_eq(res_1, res_2);
}
END_TEST

// 6 - Тест на поиск символа в строке, когда строка состоит только из этого
// символа
START_TEST(s21_strchr_test_6) {
  const char str[] = "XXXXXXXXX";
  char *res_1 = strchr(str, 'X');
  char *res_2 = s21_strchr(str, 'X');

  ck_assert_ptr_eq(res_1, res_2);
}
END_TEST

// 7 - Тест на поиск символа с учетом регистра
START_TEST(s21_strchr_test_7) {
  const char str[] = "Naydi tut Xy";
  char *res_1 = strchr(str, 'x');
  char *res_2 = s21_strchr(str, 'x');

  ck_assert_ptr_eq(res_1, res_2);
}
END_TEST

Suite *s21_strchr_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strchr");
  tc = tcase_create("case_strchr");
  tcase_add_test(tc, s21_strchr_test_1);
  tcase_add_test(tc, s21_strchr_test_2);
  tcase_add_test(tc, s21_strchr_test_3);
  tcase_add_test(tc, s21_strchr_test_4);
  tcase_add_test(tc, s21_strchr_test_5);
  tcase_add_test(tc, s21_strchr_test_6);
  tcase_add_test(tc, s21_strchr_test_7);

  suite_add_tcase(s, tc);
  return s;
}

///////////////////////////////////////////
///////////////////////////////////////////

// ===================== strncmp =====================

START_TEST(strncmp_test_01) {
  char ch1[400] =
      "§123456789900-=qwwerttyuiioopp[[]assdfghjkl;;'\\`zxcvbnm,../"
      "±!@#$%^&*()_+QWERTYUIOP{{{{{{}ASDFGHJKL:\"|~ZXCVBNM<<>>?>1234567890-="
      "йцукенгшщзхъъфывапролджэё]ячсмитьбю/"
      "<!\"№%:,.;()_+ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЁ[ЯЧСМИТЬБЮ?";
  char ch2[400] =
      "§123456789900-=qwwerttyuiioopp[[]assdfghjkl;;'\\`zxcvbnm,../"
      "±!@#$%^&*()_+QWERTYUIOP{{{{{{}ASDFGHJKL:\"|~ZXCVBNM<<>>?>1234567890-="
      "йцукенгшщзхъъфывапролджэё]ячсмитьбю/"
      "<!\"№%:,.;()_+ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЁ[ЯЧСМИТЬБЮ?";
  s21_size_t n = 100;
  ck_assert_int_eq(strncmp(ch1, ch2, n), s21_strncmp(ch1, ch2, n));
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====s21_STRNCMP=====\033[0m");
  tc_core = tcase_create("StrncmpCore");

  tcase_add_test(tc_core, strncmp_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

///////////////////////////////////////////
///////////////////////////////////////////
///////////////////////////////////////////

// 1 - Тест на сравнение равных строк
START_TEST(s21_strncmp_test_1) {
  const char str1[] = "Mi v rabstve";
  const char str2[] = "Mi v rabstve";
  int n = sizeof(str1) - 1;

  int res1 = strncmp(str1, str2, n);
  int res2 = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(res1, res2);
}
END_TEST



// 4 - Тест на сравнение строк, где первая строка короче второй
START_TEST(s21_strncmp_test_4) {
  const char str1[] = "Mi v";
  const char str2[] = "Mi v rabstve";
  int n = sizeof(str1) - 1;

  int res1 = strncmp(str1, str2, n);
  int res2 = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(res1, res2);
}
END_TEST


// 6 - Тест на сравнение пустых строк
START_TEST(s21_strncmp_test_6) {
  const char str1[] = "";
  const char str2[] = "";
  int n = 5;

  int res1 = strncmp(str1, str2, n);
  int res2 = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 7 - Тест на сравнение строк с ограниченной длиной n
START_TEST(s21_strncmp_test_7) {
  const char str1[] = "Mi v rabrabrabrab";
  const char str2[] = "Mi v rabstve!";
  int n = 7;

  int res1 = strncmp(str1, str2, n);
  int res2 = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(res1, res2);
}
END_TEST

// 8 - Тест на сравнение строк, где первая строка короче второй и используется
// максимальная длина
START_TEST(s21_strncmp_test_8) {
  const char str1[] = "Hello";
  const char str2[] = "Hello, World!";
  int n = strlen(str1);

  int res1 = strncmp(str1, str2, n);
  int res2 = s21_strncmp(str1, str2, n);

  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *s21_strncmp_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strncmp");
  tc = tcase_create("case_strncmp");
  tcase_add_test(tc, s21_strncmp_test_1);
  tcase_add_test(tc, s21_strncmp_test_4);
  tcase_add_test(tc, s21_strncmp_test_6);
  tcase_add_test(tc, s21_strncmp_test_7);
  tcase_add_test(tc, s21_strncmp_test_8);

  suite_add_tcase(s, tc);
  return s;
}

///////////////////////////////////////////
///////////////////////////////////////////

// ===================== strncpy =====================

START_TEST(strncpy_test_01) {
  char str[20] = "This is Elon Musk.";
  char str2[20] = "This is Elon Musk.";
  char str3[] = "Tesla";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(str, str3, n), s21_strncpy(str2, str3, n));
}
END_TEST

Suite *strncpy_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====s21_STRNCPY=====\033[0m");
  tc_core = tcase_create("StrnpyCore");

  tcase_add_test(tc_core, strncpy_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

/////////////////////////////////////////////////
////////////////////////////////////////////////
////////////////////////////////////////////////

// 1 - Тест на копирование строки с ограниченной длиной
START_TEST(s21_strncpy_test_1) {
  const char src[] = "Za KOD i Dvor...";
  char dest1[20] = {'\0'};
  char dest2[20] = {'\0'};
  int n = sizeof(dest1) - 1;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// 2 - Тест на копирование строки, превышающей размер буфера
START_TEST(s21_strncpy_test_2) {
  const char src[] = "Za KOD i Dvor...";
  char dest1[5] = {'\0'};
  char dest2[5] = {'\0'};
  int n = sizeof(dest1) - 1;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// 3 - Тест на копирование строки, которая короче размера буфера
START_TEST(s21_strncpy_test_3) {
  const char src[] = "Za KOD";
  char dest1[10] = {'\0'};
  char dest2[10] = {'\0'};
  int n = sizeof(dest1) - 1;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

// 4 - Тест на копирование пустой строки
START_TEST(s21_strncpy_test_4) {
  const char src[] = "";
  char dest1[10] = {'\0'};
  char dest2[10] = {'\0'};
  int n = sizeof(dest1) - 1;

  strncpy(dest1, src, n);
  s21_strncpy(dest2, src, n);

  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *s21_strncpy_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strncpy");
  tc = tcase_create("case_strncpy");
  tcase_add_test(tc, s21_strncpy_test_1);
  tcase_add_test(tc, s21_strncpy_test_2);
  tcase_add_test(tc, s21_strncpy_test_3);
  tcase_add_test(tc, s21_strncpy_test_4);

  suite_add_tcase(s, tc);
  return s;
}

////////////////////////////////////////////////
///////////////////////////////////////////////

// ===================== strpbrk =====================

START_TEST(strpbrk_test_01) {
  char str[20] = "This is Elon Musk.";
  char str2[20] = "This is Elon Musk.";
  ck_assert_pstr_eq(strpbrk(str, str2), s21_strpbrk(str, str2));
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====s21_STRPBRK=====\033[0m");
  tc_core = tcase_create("StrpbrkCore");

  tcase_add_test(tc_core, strpbrk_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

// 1 - Тест на поиск первого вхождения одного символа
START_TEST(s21_strpbrk_test_1) {
  const char str1[] = "abcd... дальше не знаю";
  const char str2[] = "zxya";

  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 2 - Тест на поиск символа, которого нет в str1
START_TEST(s21_strpbrk_test_2) {
  const char str1[] = "abcd... дальше не знаю";
  const char str2[] = "XYZ";

  const char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 3 - Тест на поиск первого вхождения символа с другим регистром
START_TEST(s21_strpbrk_test_3) {
  const char str1[] = "abcd... дальше не знаю";
  const char str2[] = "A";

  const char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 4 - Тест на поиск первого символа в str1
START_TEST(s21_strpbrk_test_4) {
  const char str1[] = "abcd... дальше не знаю";
  const char str2[] = "a";

  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 5 - Тест на поиск последнего символа в str1
START_TEST(s21_strpbrk_test_5) {
  const char str1[] = "abcd... дальше не знаюz";
  const char str2[] = "z";

  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 6 - Тест на поиск \0
START_TEST(s21_strpbrk_test_6) {
  const char str1[] = "abcd... дальше\0не знаюz";
  const char str2[] = "ab\0";

  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 7 - Тест на поиск пробела
START_TEST(s21_strpbrk_test_7) {
  const char str1[] = "abcd... дальше\0не знаюz";
  const char str2[] = " ";

  char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 8 - Тест на поиск пустой str2
START_TEST(s21_strpbrk_test_8) {
  const char str1[] = "abcd... дальше\0не знаюz";
  const char str2[] = "";

  const char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 9 - Тест на поиск пустой str1
START_TEST(s21_strpbrk_test_9) {
  const char str1[] = "";
  const char str2[] = "str1? Где ты?";

  const char *res1 = strpbrk(str1, str2);
  char *res2 = s21_strpbrk(str1, str2);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

Suite *s21_strpbrk_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strpbrk");
  tc = tcase_create("case_strpbrk");
  tcase_add_test(tc, s21_strpbrk_test_1);
  tcase_add_test(tc, s21_strpbrk_test_2);
  tcase_add_test(tc, s21_strpbrk_test_3);
  tcase_add_test(tc, s21_strpbrk_test_4);
  tcase_add_test(tc, s21_strpbrk_test_5);
  tcase_add_test(tc, s21_strpbrk_test_6);
  tcase_add_test(tc, s21_strpbrk_test_7);
  tcase_add_test(tc, s21_strpbrk_test_8);
  tcase_add_test(tc, s21_strpbrk_test_9);

  suite_add_tcase(s, tc);
  return s;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////

// ===================== strrchr =====================

START_TEST(strrchr_test_01) {
  char str[20] = "This is Elon Musk.";
  int ch = 'i';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====s21_STRRCHR=====\033[0m");
  tc_core = tcase_create("strrchrCore");

  tcase_add_test(tc_core, strrchr_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

START_TEST(strrchr_1) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_2) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_3) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(strrchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

Suite *s21_strrchr_suite(void) {
  Suite *s = suite_create("\033[45m-=S21_STRRCHR=-\033[0m");
  TCase *tc = tcase_create("strrchr_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);

  suite_add_tcase(s, tc);
  return s;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////

// ===================== strstr =====================

START_TEST(strstr_test_01) {
  char str[20] = "This is Elon Musk.";
  char str2[20] = "This is Elon Musk.";
  ck_assert_pstr_eq(strstr(str, str2), s21_strstr(str, str2));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[35m=====s21_STRSTR=====\033[0m");
  tc_core = tcase_create("StrstrCore");

  tcase_add_test(tc_core, strstr_test_01);
  suite_add_tcase(s, tc_core);
  return s;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

// 1 - Тест на поиск подстроки, которая присутствует в строке
START_TEST(s21_strstr_test_1) {
  const char str[] = "Mojet ne nado?";
  const char substr[] = "nado";

  char *res1 = strstr(str, substr);
  char *res2 = s21_strstr(str, substr);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 2 - Тест на поиск подстроки, которая отсутствует в строке
START_TEST(s21_strstr_test_2) {
  const char str[] = "Mojet ne nado?";
  const char substr[] = "kavo?";

  char *res1 = strstr(str, substr);
  char *res2 = s21_strstr(str, substr);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 3 - Тест на поиск подстроки, которая встречается дважды
START_TEST(s21_strstr_test_3) {
  const char str[] = "ne Mojet ne Mojet ne";
  const char substr[] = "Mojet";

  char *res1 = strstr(str, substr);
  char *res2 = s21_strstr(str, substr);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 4 - Тест на поиск пустой подстроки
START_TEST(s21_strstr_test_4) {
  const char str[] = "Hello, World!";
  const char substr[] = "";

  char *res1 = strstr(str, substr);
  char *res2 = s21_strstr(str, substr);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 5 - Тест на поиск подстроки в пустой строке
START_TEST(s21_strstr_test_5) {
  const char str[] = "";
  const char substr[] = "nado";

  char *res1 = strstr(str, substr);
  char *res2 = s21_strstr(str, substr);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 6 - Тест на поиск подстроки, которая является началом строки
START_TEST(s21_strstr_test_6) {
  const char str[] = "Mojet ne nado?";
  const char substr[] = "Mojet";

  char *res1 = strstr(str, substr);
  char *res2 = s21_strstr(str, substr);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

Suite *s21_strstr_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strstr");
  tc = tcase_create("case_strstr");
  tcase_add_test(tc, s21_strstr_test_1);
  tcase_add_test(tc, s21_strstr_test_2);
  tcase_add_test(tc, s21_strstr_test_3);
  tcase_add_test(tc, s21_strstr_test_4);
  tcase_add_test(tc, s21_strstr_test_5);
  tcase_add_test(tc, s21_strstr_test_6);

  suite_add_tcase(s, tc);
  return s;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////

// ===================== strtok =====================

START_TEST(strtok_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_2) {
  char s1[] = "";
  char s2[] = "";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_4) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_5) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_7) {
  char s1[] = "ABABABABABBABABABBABABABABABBA";
  char s2[] = "ABABABABABBABABABBABABABABABBA";
  char s3[] = "B";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_8) {
  char s1[] = "\0ABABABABABBABABABBABABABABABBA";
  char s2[] = "\0ABABABABABBABABABBABABABABABBA";
  char s3[] = "A";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_9) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_10) {
  char s1[] = "\0Hello, world!";
  char s2[] = "\0Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_11) {
  char *s1 = s21_NULL;
  char *s2 = s21_NULL;
  char s3[] = "";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_12) {
  char s1[] = "tuz-tuz-tuz";
  char s2[] = "tuz-tuz-tuz";
  char s3[] = "z-tuz-tuz";
  ck_assert_pstr_eq(strtok(s1, s3), s21_strtok(s2, s3));
}
END_TEST

START_TEST(strtok_13) {
  char s1[] = "Hello, world! And other people";
  char s2[] = "Hello, world! And other people";
  char s3[] = "\0Come here";
  char s4[] = "\0Come here";
  char s5[] = "";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_14) {
  char s1[] = "Hello,       world! And other people";
  char s2[] = "Hello,       world! And other people";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " o";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_15) {
  char s1[] = "Hello,      worllllllllllld! And lother people      ";
  char s2[] = "Hello,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = " l";

  ck_assert_pstr_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  }
  ck_assert_pstr_eq(strtok(s3, s5), s21_strtok(s4, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
  ck_assert_pstr_eq(strtok(s21_NULL, s5), s21_strtok(s21_NULL, s5));
}
END_TEST

START_TEST(strtok_16) {
  char s1[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s2[] = "Helllllllo,      worllllllllllld! And lother people      ";
  char s3[] = "Come here";
  char s4[] = "Come here";
  char s5[] = "l";
  char s6[] = " ";

  ck_assert_str_eq(strtok(s1, s5), s21_strtok(s2, s5));
  for (int i = 0; i < 5; i++) {
    ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  }
  ck_assert_pstr_eq(strtok(s3, s6), s21_strtok(s4, s6));
  ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
  ck_assert_pstr_eq(strtok(s21_NULL, s6), s21_strtok(s21_NULL, s6));
}
END_TEST

START_TEST(strtok_17) {
  char s1[] = "ROROROROMA!!!!!!!!!";
  char s2[] = "ROROROROMA!!!!!!!!!";
  char s3[] = "R";
  strtok(s1, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(strtok_18) {
  char s1[] = "AGONIA";
  char s2[] = "AGONIA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s3);
  strtok(NULL, s3);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

START_TEST(strtok_19) {
  char s1[] = "MYPHONENUM68697317172648";
  char s2[] = "MYPHONENUM68697317172648";
  char s3[] = "MYPHONENUM6869";
  char *s4 = strtok(s1, s3);
  char *s6 = strtok(s21_NULL, s3);

  char *s5 = s21_strtok(s2, s3);
  char *s7 = s21_strtok(s21_NULL, s3);

  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s4, s5);
  ck_assert_pstr_eq(s6, s7);
}
END_TEST

START_TEST(strtok_20) {
  char s1[] = "AAAAAAGOONIAAAAA";
  char s2[] = "AAAAAAGOONIAAAAA";
  char s3[] = "A";
  strtok(s1, s3);
  strtok(NULL, s2);
  strtok(NULL, s2);
  s21_strtok(s2, s3);
  s21_strtok(NULL, s3);
  s21_strtok(NULL, s3);
  ck_assert_pstr_eq(s1, s2);
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("\033[45m-=S21_STRTOK=-\033[0m");
  TCase *tc = tcase_create("strtok_tc");

  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  tcase_add_test(tc, strtok_6);
  tcase_add_test(tc, strtok_7);
  tcase_add_test(tc, strtok_8);
  tcase_add_test(tc, strtok_9);
  tcase_add_test(tc, strtok_10);
  tcase_add_test(tc, strtok_11);
  tcase_add_test(tc, strtok_12);
  tcase_add_test(tc, strtok_13);
  tcase_add_test(tc, strtok_14);
  tcase_add_test(tc, strtok_15);
  tcase_add_test(tc, strtok_16);
  tcase_add_test(tc, strtok_17);
  tcase_add_test(tc, strtok_18);
  tcase_add_test(tc, strtok_19);
  tcase_add_test(tc, strtok_20);

  suite_add_tcase(s, tc);
  return s;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////
///////////////////////////////////////////////////

// 1 - Тест на разделение строки на токены с использованием пробела в качестве
// разделителя
START_TEST(s21_strtok_test_1) {
  char str[] = "Welcome to the hell";
  const char delim[] = " ";

  char *res1 = strtok(str, delim);
  char *res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 2 - Тест на разделение строки на токены с использованием символа запятой в
// качестве разделителя
START_TEST(s21_strtok_test_2) {
  char str[] = "apple,banana,cherry";
  const char delim[] = ",";

  char *res1 = strtok(str, delim);
  char *res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 3 - Тест на разделение строки на токены с использованием символа "!" в
// качестве разделителя
START_TEST(s21_strtok_test_3) {
  char str[] = "one!two!three";
  const char delim[] = "!";

  char *res1 = strtok(str, delim);
  char *res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 4 - Тест на разделение пустой строки
START_TEST(s21_strtok_test_4) {
  char str[] = "";
  const char delim[] = ",";

  char *res1 = strtok(str, delim);
  char *res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 5 - Тест на разделение строки с использованием символа разделителя, который
// не содержится в строке
START_TEST(s21_strtok_test_5) {
  char str[] = "Twisti Twist";
  const char delim[] = "?";

  char *res1 = strtok(str, delim);
  char *res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 6 - Тест на разделение строки на токены с использованием нескольких
// разделителей
START_TEST(s21_strtok_test_6) {
  char str[] = "apple,banana;cherry orange";
  const char delim[] = ", ;";

  char *res1 = strtok(str, delim);
  char *res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

// 7 - Тест на разделение строки на токены, начиная с пустого токена
START_TEST(s21_strtok_test_7) {
  char str[] = ",Hello,,World!";
  const char delim[] = ",";

  char *res1 = strtok(str, delim);
  char *res2 = s21_strtok(str, delim);

  ck_assert_ptr_eq(res1, res2);
}
END_TEST

Suite *s21_strtok_suite(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("s21_strtok");
  tc = tcase_create("case_strtok");
  tcase_add_test(tc, s21_strtok_test_1);
  tcase_add_test(tc, s21_strtok_test_2);
  tcase_add_test(tc, s21_strtok_test_3);
  tcase_add_test(tc, s21_strtok_test_4);
  tcase_add_test(tc, s21_strtok_test_5);
  tcase_add_test(tc, s21_strtok_test_6);
  tcase_add_test(tc, s21_strtok_test_7);

  suite_add_tcase(s, tc);
  return s;
}

///////////////////////////////////////////////////
///////////////////////////////////////////////////



START_TEST(test_sprintf_c_1) {
  char str1[100] = {0};
  char str2[100] = {0};
  int a = 78;
  ck_assert_int_eq(sprintf(str1, "%-4c", a), s21_sprintf(str2, "%-4c", a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_3) {
  char str1[100] = {0};
  char str2[100] = {0};
  int b = 66;
  ck_assert_int_eq(sprintf(str1, "%5c", b), s21_sprintf(str2, "%5c", b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_4) {
  char str1[100] = {0};
  char str2[100] = {0};
  int c = '\0';
  sprintf(str1, "%c", c);
  s21_sprintf(str2, "%c", c);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_5) {
  char str1[100] = {0};
  char str2[100] = {0};
  int e = -123;
  ck_assert_int_eq(sprintf(str1, "%c", e), s21_sprintf(str2, "%c", e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_c_6) {
  char str1[100] = {0};
  char str2[100] = {0};
  int e = 123;
  ck_assert_int_eq(sprintf(str1, "%c", e), s21_sprintf(str2, "%c", e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_c_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_C=-\033[0m");
  tc_core = tcase_create("SprintfcCore");

  tcase_add_test(tc_core, test_sprintf_c_1);
  tcase_add_test(tc_core, test_sprintf_c_3);
  tcase_add_test(tc_core, test_sprintf_c_4);
  tcase_add_test(tc_core, test_sprintf_c_5);
  tcase_add_test(tc_core, test_sprintf_c_6);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sprintf_d_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "% d";
  int val = 0;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_2) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%-4d";
  int a = 78;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_3) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%4d";
  int e = 123;
  ck_assert_int_eq(sprintf(str1, str3, e), s21_sprintf(str2, str3, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_4) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%hd";
  int b = -66;
  ck_assert_int_eq(sprintf(str1, str3, b), s21_sprintf(str2, str3, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_5) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%ld";
  int c = 35;
  ck_assert_int_eq(sprintf(str1, str3, c), s21_sprintf(str2, str3, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_6) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%.5d";
  int d = 124;
  ck_assert_int_eq(sprintf(str1, str3, d), s21_sprintf(str2, str3, d));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_7) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%+d";
  int e = 123;
  ck_assert_int_eq(sprintf(str1, str3, e), s21_sprintf(str2, str3, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_8) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%-+ 5.5hd";
  int e = 12368598;
  ck_assert_int_eq(sprintf(str1, str3, e), s21_sprintf(str2, str3, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_9) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%-+ 5.5ld";
  int e = 12368598;
  ck_assert_int_eq(sprintf(str1, str3, e), s21_sprintf(str2, str3, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_d_10) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%15ld";
  int e = 12368598;
  ck_assert_int_eq(sprintf(str1, str3, e), s21_sprintf(str2, str3, e));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_d_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_D=-\033[0m");
  tc_core = tcase_create("SprintfdCore");

  tcase_add_test(tc_core, test_sprintf_d_1);
  tcase_add_test(tc_core, test_sprintf_d_2);
  tcase_add_test(tc_core, test_sprintf_d_3);
  tcase_add_test(tc_core, test_sprintf_d_4);
  tcase_add_test(tc_core, test_sprintf_d_5);
  tcase_add_test(tc_core, test_sprintf_d_6);
  tcase_add_test(tc_core, test_sprintf_d_7);
  tcase_add_test(tc_core, test_sprintf_d_8);
  tcase_add_test(tc_core, test_sprintf_d_9);
  tcase_add_test(tc_core, test_sprintf_d_10);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sprintf_s_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "(%   s%-20s%20s| ";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val, val, val),
                   s21_sprintf(str2, str3, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_2) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "(%-20s| ";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_3) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "(%*s| ";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, 20, val),
                   s21_sprintf(str2, str3, 20, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_4) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "(%+-  50s)";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_s_5) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "(%.5s)";
  char *val = "Why am I here?!";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_s_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_S=-\033[0m");
  tc_core = tcase_create("SprintfsCore");

  tcase_add_test(tc_core, test_sprintf_s_1);
  tcase_add_test(tc_core, test_sprintf_s_2);
  tcase_add_test(tc_core, test_sprintf_s_3);
  tcase_add_test(tc_core, test_sprintf_s_4);
  tcase_add_test(tc_core, test_sprintf_s_5);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sprintf_u_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%u";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_2) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%4u";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_3) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%-4u";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_4) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%.4u";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_5) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%hu";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_6) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%lu";
  unsigned int val = 012;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_7) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%u";
  unsigned int val1 = 0;
  ck_assert_int_eq(sprintf(str1, str3, val1), s21_sprintf(str2, str3, val1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_u_8) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%+- 20.20lu";
  unsigned int val1 = 0123;
  ck_assert_int_eq(sprintf(str1, str3, val1), s21_sprintf(str2, str3, val1));
  ck_assert_str_eq(str1, str2);
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *sprintf_u_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_U=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_u_1);
  tcase_add_test(tc_core, test_sprintf_u_2);
  tcase_add_test(tc_core, test_sprintf_u_3);
  tcase_add_test(tc_core, test_sprintf_u_4);
  tcase_add_test(tc_core, test_sprintf_u_5);
  tcase_add_test(tc_core, test_sprintf_u_6);
  tcase_add_test(tc_core, test_sprintf_u_7);
  tcase_add_test(tc_core, test_sprintf_u_8);
  suite_add_tcase(s, tc_core);

  return s;
}

///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////

START_TEST(test_sprintf_i_1) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%-5i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_i_2) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%012i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_i_3) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%0.*i";
  int val = 69;
  ck_assert_int_eq(s21_sprintf(str1, format, 5, val),
                   sprintf(str2, format, 5, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_i_4) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char format[] = "%0.*i %d %4.*i %013d %d";
  int val = 69;
  ck_assert_int_eq(
      s21_sprintf(str1, format, 5, val, -10431, 13, 5311, 0, -581813581),
      sprintf(str2, format, 5, val, -10431, 13, 5311, 0, -581813581));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_i_5) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%+5.31li";
  long int val = 698518581899;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_i_6) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%-16.9hi";
  short int val = 6958;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_i_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_I=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_i_1);
  tcase_add_test(tc_core, test_sprintf_i_2);
  tcase_add_test(tc_core, test_sprintf_i_3);
  tcase_add_test(tc_core, test_sprintf_i_4);
  tcase_add_test(tc_core, test_sprintf_i_5);
  tcase_add_test(tc_core, test_sprintf_i_6);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sprintf_o_1) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%15o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_2) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%-16o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_3) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_4) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%-5.51o";
  int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_5) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%o";
  ck_assert_int_eq(s21_sprintf(str1, format, 0), sprintf(str2, format, 0));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_6) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#o";
  int val = 57175;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_7) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%hd";
  short int val = 14140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_8) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%lo";
  long int val = 949149114140;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_9) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%lo, %o, %ho, %.5o, %5.o";
  long int val = 949149114140;
  ck_assert_int_eq(
      s21_sprintf(str1, format, val, 14, 1441, 14414, 9681),
      sprintf(str2, format, val, (unsigned)14, (unsigned short)1441,
              (unsigned)14414, (unsigned)9681));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_10) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%lo";
  long int val = 84518;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_11) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#o";
  long int val = 84;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_o_12) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#lo";
  long int val = 84;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_o_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_O=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_o_1);
  tcase_add_test(tc_core, test_sprintf_o_2);
  tcase_add_test(tc_core, test_sprintf_o_3);
  tcase_add_test(tc_core, test_sprintf_o_4);
  tcase_add_test(tc_core, test_sprintf_o_5);
  tcase_add_test(tc_core, test_sprintf_o_6);
  tcase_add_test(tc_core, test_sprintf_o_7);
  tcase_add_test(tc_core, test_sprintf_o_8);
  tcase_add_test(tc_core, test_sprintf_o_9);
  tcase_add_test(tc_core, test_sprintf_o_10);
  tcase_add_test(tc_core, test_sprintf_o_11);
  tcase_add_test(tc_core, test_sprintf_o_12);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sprintf_x_1) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_2) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#-10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_3) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%.15x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_4) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#-10x%x%X%#x%#X%5.5x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val, val, val, val, val),
                   sprintf(str2, format, val, val, val, val, val, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_5) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#-5.10x";
  unsigned val = 858158158;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_6) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#x";
  unsigned val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_7) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#x";
  unsigned val = 18571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_8) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#hx";
  unsigned short val = 12352;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_9) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#lx";
  unsigned long val = 18571757371571;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_10) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#2x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_11) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%#30x";
  unsigned val = 1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_x_12) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  ck_assert_int_eq(
      s21_sprintf(str1, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123),
      sprintf(str2, "%X%X%X%X%X", 12340987, 135, 0, -1230, -123213123));
  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_x_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_X=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_x_1);
  tcase_add_test(tc_core, test_sprintf_x_2);
  tcase_add_test(tc_core, test_sprintf_x_3);
  tcase_add_test(tc_core, test_sprintf_x_4);
  tcase_add_test(tc_core, test_sprintf_x_5);
  tcase_add_test(tc_core, test_sprintf_x_6);
  tcase_add_test(tc_core, test_sprintf_x_7);
  tcase_add_test(tc_core, test_sprintf_x_8);
  tcase_add_test(tc_core, test_sprintf_x_9);
  tcase_add_test(tc_core, test_sprintf_x_10);
  tcase_add_test(tc_core, test_sprintf_x_11);
  tcase_add_test(tc_core, test_sprintf_x_12);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sprintf_p_1) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_2) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%15p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_p_3) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  char *format = "%.5p";
  ck_assert_int_eq(s21_sprintf(str1, format, format),
                   sprintf(str2, format, format));

  ck_assert_str_eq(str1, str2);
}
END_TEST


Suite *sprintf_p_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_P=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_p_1);
  tcase_add_test(tc_core, test_sprintf_p_2);
  tcase_add_test(tc_core, test_sprintf_p_3);

  suite_add_tcase(s, tc_core);

  return s;
}


START_TEST(test_sprintf_f_1) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%Lf";
  long double val = 513515.131513515151351;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_2) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%10Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_3) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.0Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_4) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_5) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.15Lf";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_6) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.15Lf";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_7) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%Lf";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_8) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "% f";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_9) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_10) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%10Lf";
  long double val = 15;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_f_11) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%+Lf";
  long double val = 15.1;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_f_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_F=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_f_1);
  tcase_add_test(tc_core, test_sprintf_f_2);
  tcase_add_test(tc_core, test_sprintf_f_3);
  tcase_add_test(tc_core, test_sprintf_f_4);
  tcase_add_test(tc_core, test_sprintf_f_5);
  tcase_add_test(tc_core, test_sprintf_f_6);
  tcase_add_test(tc_core, test_sprintf_f_7);
  tcase_add_test(tc_core, test_sprintf_f_8);
  tcase_add_test(tc_core, test_sprintf_f_9);
  tcase_add_test(tc_core, test_sprintf_f_10);
  tcase_add_test(tc_core, test_sprintf_f_11);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sprintf_e_1) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.17Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_2) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.0Le";
  long double val = 15.35;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_3) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.Le";
  long double val = 15.000009121;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_sprintf_e_4) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.15Le";
  long double val = 0.000000000000000123;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_5) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%.15Le";
  long double val = -15.35581134;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_6) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%Le";
  long double val = 72537572375.1431341;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_7) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%015E";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_8) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "%15e";
  float val = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, val), sprintf(str2, format, val));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_e_9) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  char *format = "% .0e %.le %Le %e %le %Le";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 0.094913941;
  long double val5 = 95919539159.53151351131;
  ck_assert_int_eq(s21_sprintf(str1, format, val, val1, val2, val3, val4, val5),
                   sprintf(str2, format, val, val1, val2, val3, val4, val5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_e_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_E=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_e_1);
  tcase_add_test(tc_core, test_sprintf_e_2);
  tcase_add_test(tc_core, test_sprintf_e_3);
  tcase_add_test(tc_core, test_sprintf_e_4);
  tcase_add_test(tc_core, test_sprintf_e_5);
  tcase_add_test(tc_core, test_sprintf_e_6);
  tcase_add_test(tc_core, test_sprintf_e_7);
  tcase_add_test(tc_core, test_sprintf_e_8);
  tcase_add_test(tc_core, test_sprintf_e_9);

  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(test_sprintf_empty_1) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};
  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_empty_2) {
  char str1[STR_LEN] = {'\0'};
  char str2[STR_LEN] = {'\0'};

  ck_assert_int_eq(s21_sprintf(str1, "abc"), sprintf(str2, "abc"));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_empty_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_EMPTY=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_empty_1);
  tcase_add_test(tc_core, test_sprintf_empty_2);

  suite_add_tcase(s, tc_core);

  return s;
}



////////////////////////////////////////////////

START_TEST(test_sprintf_g_1) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%g";
  double hex = 0.50300;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_2) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%g";
  double hex = 5131.43141;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_3) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_4) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%.5g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_5) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%.0g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_6) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%.g";
  double hex = 0.123000;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_7) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%.g";
  double hex = 0.0004;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_8) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_9) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%.5g";
  double hex = 0;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_12) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%g";
  double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_13) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%LG";
  long double hex = 0.005;
  ck_assert_int_eq(s21_sprintf(str1, format, hex), sprintf(str2, format, hex));

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_sprintf_g_14) {
  char str1[MAX_STRING_LEN] = {'\0'};
  char str2[MAX_STRING_LEN] = {'\0'};
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.0005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;
  ck_assert_int_eq(s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5),
                   sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5));

  ck_assert_str_eq(str1, str2);
}
END_TEST

Suite *sprintf_g_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("\033[42m-=S21_SPRINTF_G=-\033[0m");
  tc_core = tcase_create("SprintfuCore");

  tcase_add_test(tc_core, test_sprintf_g_1);
  tcase_add_test(tc_core, test_sprintf_g_2);
  tcase_add_test(tc_core, test_sprintf_g_3);
  tcase_add_test(tc_core, test_sprintf_g_4);
  tcase_add_test(tc_core, test_sprintf_g_5);
  tcase_add_test(tc_core, test_sprintf_g_6);
  tcase_add_test(tc_core, test_sprintf_g_7);
  tcase_add_test(tc_core, test_sprintf_g_8);
  tcase_add_test(tc_core, test_sprintf_g_9);
  tcase_add_test(tc_core, test_sprintf_g_12);
  tcase_add_test(tc_core, test_sprintf_g_13);
  tcase_add_test(tc_core, test_sprintf_g_14);
  suite_add_tcase(s, tc_core);

  return s;
}

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////s21_to_upper///////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

START_TEST(test_to_upper_1) {
  char s1[30] = "Hello, world!";
  char *s2 = s21_to_upper(s1);
  char s3[] = "HELLO, WORLD!";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_2) {
  char s1[30] = "\nh\t\\g123123";
  char *s2 = s21_to_upper(s1);
  char s3[] = "\nH\t\\G123123";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_3) {
  char s1[30] = "ALREADY UPPER";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ALREADY UPPER";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_4) {
  char s1[30] = "";
  char *s2 = s21_to_upper(s1);
  char s3[] = "";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char *s2 = s21_to_upper(s1);
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_6) {
  char s1[30] = "_?};!234";
  char *s2 = s21_to_upper(s1);
  char s3[] = "_?};!234";
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_upper_7) {
  char *s1 = s21_NULL;
  char *s2 = s21_to_upper(s1);
  char *s3 = s21_NULL;
  ck_assert_pstr_eq(s3, s2);
  if (s2) free(s2);
}
END_TEST

Suite *test_to_upper(void) {
  Suite *s = suite_create("\033[45m-=S21_TO_UPPER=-\033[0m");
  TCase *tc = tcase_create("to_upper_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_upper_1);
  tcase_add_test(tc, test_to_upper_2);
  tcase_add_test(tc, test_to_upper_3);
  tcase_add_test(tc, test_to_upper_4);
  tcase_add_test(tc, test_to_upper_5);
  tcase_add_test(tc, test_to_upper_6);
  tcase_add_test(tc, test_to_upper_7);

  suite_add_tcase(s, tc);
  return s;
}

//////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////s21_to_lower/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

START_TEST(test_to_lower_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_2) {
  char s1[30] = "\nh\t\\g123123";
  char s3[] = "\nH\t\\G123123";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_3) {
  char s1[30] = "already lower";
  char s3[] = "already lower";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_4) {
  char s1[30] = "";
  char s3[] = "";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_5) {
  char s1[30] = "abcdefghijklmnopqrstuvwxyz";
  char s3[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_6) {
  char s1[30] = "_?};!234";
  char s3[] = "_?};!234";
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_to_lower_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s2 = s21_to_lower(s3);
  ck_assert_pstr_eq(s1, s2);
  if (s2) free(s2);
}
END_TEST

Suite *test_to_lower(void) {
  Suite *s = suite_create("\033[45m-=S21_TO_LOWER=-\033[0m");
  TCase *tc = tcase_create("to_lower_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, test_to_lower_1);
  tcase_add_test(tc, test_to_lower_2);
  tcase_add_test(tc, test_to_lower_3);
  tcase_add_test(tc, test_to_lower_4);
  tcase_add_test(tc, test_to_lower_5);
  tcase_add_test(tc, test_to_lower_6);
  tcase_add_test(tc, test_to_lower_7);

  suite_add_tcase(s, tc);
  return s;
}

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////s21_insert/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

START_TEST(test_insert_1) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_3) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_4) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = s21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_6) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = s21_NULL;
  s21_size_t num = -1;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_9) {
  char s1[] = "wtf";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_insert_10) {
  char s1[] = "";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

Suite *test_insert(void) {
  Suite *s = suite_create("\033[45m-=S21_INSERT=-\033[0m");
  TCase *tc = tcase_create("insert_tc");

  tcase_add_test(tc, test_insert_1);
  tcase_add_test(tc, test_insert_2);
  tcase_add_test(tc, test_insert_3);
  tcase_add_test(tc, test_insert_4);
  tcase_add_test(tc, test_insert_5);
  tcase_add_test(tc, test_insert_6);
  tcase_add_test(tc, test_insert_7);
  tcase_add_test(tc, test_insert_8);
  tcase_add_test(tc, test_insert_9);
  tcase_add_test(tc, test_insert_10);

  suite_add_tcase(s, tc);
  return s;
}

//////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////s21_trim/////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

START_TEST(test_trim_1) {
  char s1[30] = "-?hello, world!";
  char s3[] = "!?-";
  char s4[] = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_2) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_3) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_4) {
  char s1[30] = "!!!abcdefghij!?!";
  char s3[] = "!?";
  char s4[] = "abcdefghij";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = "abc";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_6) {
  char s1[30] = "hello, world!";
  char s3[] = "?!";
  char *s4 = "hello, world";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_9) {
  char s1[] = " wtf ";
  char *s3 = s21_NULL;
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_trim_10) {
  char s1[] = " wtf ";
  char *s3 = "";
  char *s4 = " wtf ";
  char *s2 = s21_trim(s1, s3);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

Suite *test_trim(void) {
  Suite *s = suite_create("\033[45m-=S21_TRIM=-\033[0m");
  TCase *tc = tcase_create("trim_tc");

  tcase_add_test(tc, test_trim_1);
  tcase_add_test(tc, test_trim_2);
  tcase_add_test(tc, test_trim_3);
  tcase_add_test(tc, test_trim_4);
  tcase_add_test(tc, test_trim_5);
  tcase_add_test(tc, test_trim_6);
  tcase_add_test(tc, test_trim_7);
  tcase_add_test(tc, test_trim_8);
  tcase_add_test(tc, test_trim_9);
  tcase_add_test(tc, test_trim_10);

  suite_add_tcase(s, tc);
  return s;
}

int main(void) {
  int failed = 0;
  Suite *string_tests[] = {
      memchr_suite(), s21_memchr_suite(), memcmp_suite(), s21_memcmp_suite(),
      memcpy_suite(), s21_memcpy_suite(), memset_suite(), s21_memset_suite(),
      strncat_suite(), s21_strncat_suite(), strchr_suite(), s21_strchr_suite(),
      strncmp_suite(), s21_strncmp_suite(), strncpy_suite(),
      s21_strncpy_suite(), strcspn_suite(), s21_strcspn_suite(), strlen_suite(),
      s21_strlen_suite(), strpbrk_suite(), s21_strpbrk_suite(), strrchr_suite(),
      s21_strrchr_suite(), strstr_suite(), s21_strstr_suite(), strtok_suite(),
      s21_strtok_suite(),
      /////
      sprintf_c_suite(), sprintf_d_suite(), sprintf_s_suite(),
      sprintf_u_suite(), sprintf_i_suite(), sprintf_o_suite(),
      sprintf_x_suite(), sprintf_p_suite(), sprintf_f_suite(),
      sprintf_e_suite(), sprintf_empty_suite(), sprintf_g_suite(),
      //////////
      test_to_upper(), test_to_lower(), test_insert(), test_trim(), s21_NULL};
  ////////

  for (int i = 0; string_tests[i] != s21_NULL; i++) {
    SRunner *runner;
    runner = srunner_create(string_tests[i]);
    srunner_set_fork_status(runner, CK_NOFORK);
    srunner_run_all(runner, CK_NORMAL);
    failed += srunner_ntests_failed(runner);
    srunner_free(runner);
  }

  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
