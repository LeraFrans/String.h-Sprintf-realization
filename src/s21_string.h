
#include <inttypes.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#define MAX_STRING_LEN 4096
#define MAX_LEN_NUMBER 30
#define LOW_CASE 0
#define HIGHT_CASE 1
#define TYPE_NAME(X) \
  _Generic((X),  \
    short: "short", \
    int: "int", \
    long: "long",   \
    char: "char",   \
    char*: "string",    \
    double: "double",   \
    float: "float", \
    default: "unknown")

#define s21_NULL (void *)0
#define s21_size_t unsigned long long

struct variables {
  char flags[6];
  char sizes[4];
  char types[17];

  char flag[5];
  int width;
  int precision;
  char size;
  char type;
};

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_short_to_string(char *dest, unsigned short number, int base,
                          int hight);
char *s21_int_to_string(char *dest, unsigned int number, int base, int hight);
char *s21_long_to_string(char *dest, unsigned long number, int base, int hight);
char *s21_reverse_string(char *str);
char s21_number_to_char(int number, int hight);
char *s21_double_to_notation(char *dest, long double number, int accuracy,
                             int hight);
//

void s21_doubleToString(double number, char *rezult, int accuracy,
                        int is_sharp);
void s21_long_doubleToString(long double number, char *rezult, int accuracy,
                             int is_sharp);
void s21_processing(va_list param, struct variables options,
                    char *output_string_pointer, char **p_output_string_pointer,
                    char *str);
int s21_specifire(char *c, va_list param, struct variables options,
                  char *c_copy, char *output_string_pointer,
                  char **p_output_string_pointer, char *str);
int s21_sprintf(char *str, const char *format, ...);

int s21_is_in_str(char symbol, char str[]);

char *s21_type_d_i_for_int(unsigned int arg, struct variables options,
                           char *output_string_pointer);
char *s21_type_d_i_for_short_int(unsigned short int arg,
                                 struct variables options,
                                 char *output_string_pointer);
char *s21_type_d_i_for_long_int(unsigned long int arg, struct variables options,
                                char *output_string_pointer);
char *s21_for_double(double arg, struct variables options,
                     char *output_string_pointer);
char *s21_for_long_double(long double arg, struct variables options,
                          char *output_string_pointer);
char *s21_type_c_for_int(char arg, struct variables options,
                         char *output_string_pointer);
char *s21_type_s_for_char(char *arg, struct variables options,
                          char *output_string_pointer);
char *s21_type_p_for_void(void *arg, struct variables options,
                          char *output_string_pointer);

void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_to_lower(const char *str);
void *s21_to_upper(const char *str);
void *s21_trim(const char *src, const char *trim_chars);
s21_size_t s21_strspn_r(const char *str, const char *trim_chars);

char *s21_flag_g_double(char *dest, double number, int accuracy, int is_sharp,
                        int hight);
char *s21_flag_g_long_double(char *dest, long double number, int accuracy,
                             int is_sharp, int hight);
int s21_get_power(long double number);
char *s21_delete_end_null_f(char *dest);
char *s21_delete_end_null_e(char *dest);
