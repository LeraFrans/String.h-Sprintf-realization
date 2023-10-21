#include "s21_string.h"


void *s21_memchr(const void *p, int c, s21_size_t n) {
  void *res = s21_NULL;
  for (s21_size_t i = 0; i < n; i++)
    if (*((char *)p + i) == c) {
      res = (void *)(p + i);
      break;
    }
  return res;
}
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    res = *((char *)str1 + i) - *((char *)str2 + i);
    if (res != 0) break;
  }
  return res;
}
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) *((char *)dest + i) = *((char *)src + i);

  return dest;
}
void *s21_memset(void *p, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *((char *)p + i) = c;
  }

  return p;
}
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *p = dest;
  while (*p) p++;
  for (s21_size_t i = 0; i < n; i++) {
    *(p + i) = *(src + i);
    if (!*(src + i)) break;
  }

  return dest;
}
char *s21_strchr(const char *p, int c) {
  char *res = s21_NULL;
  s21_size_t len = s21_strlen(p);
  for (s21_size_t i = 0; i <= len; i++) {
    if (*p == c) {
      res = (char *)p;
      break;
    }
    p++;
  }

  return res;
}
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  for (s21_size_t i = 0; i < n; i++) {
    res = *(str1 + i) - *(str2 + i);
    if (res || !*(str1 + i) || !*(str2 + i)) break;
  }

  return res;
}
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    *(dest + i) = *(src + i);
    if (*(src + i) == '\0') break;
  }

  return dest;
}
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len = 0;
  int flag = 0;
  while (*str1 != '\0') {
    for (s21_size_t i = 0; *(str2 + i) != '\0'; i++)
      if (*str1 == *(str2 + i)) {
        flag++;
        break;
      }
    if (flag) break;
    len++;
    str1++;
  }

  return len;
}


s21_size_t s21_strlen(const char *str) {
  s21_size_t n = 0;
  if (str != s21_NULL) {
    while (str[n] != '\0') {
      n++;
    }
  }
  return n;
}


char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;

  for (; *str1 != '\0'; ++str1) {
    if (s21_strchr(str2, *str1) != s21_NULL) {
      result = (char *)str1;
      break;
    }
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  char *answer = s21_NULL;
  int size = (s21_strlen(str) + 1);
  for (; 0 <= size; size--) {
    if (str[size] == c) {
      answer = (char *)&str[size];
      break;
    }
  }
  return answer;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *result = s21_NULL;

  if (*needle == '\0') {
    result = (char *)haystack;
  } else {
    while (*haystack != '\0') {
      const char *h = haystack;
      const char *n = needle;

      while (*n != '\0' && *h == *n) {
        ++h;
        ++n;
      }

      if (*n == '\0') {
        result = (char *)haystack;
        break;
      }

      ++haystack;
    }
  }

  return result;
}

char *s21_strtok(char *str, const char *delim) {
  static char *ptr = s21_NULL;
  if (str == s21_NULL) str = ptr;
  while ((str != NULL) && (*str != '\0') && (s21_strchr(delim, *str) != NULL)) {
    str++;
  }
  if (str && *str == '\0') {
    str = s21_NULL;
    ptr = s21_NULL;
  }
  if (str && *str != '\0') {
    ptr = str;
    while (*ptr && !(s21_strchr(delim, *ptr))) {
      ptr++;
    }
  }
  if (ptr && *ptr) {
    *ptr = '\0';
    ptr++;
  }
  /*if (ptr && *ptr == '\0') {
    *ptr = s21_NULL;
 }
 */
  return str;
}


char *s21_int_to_string(char *dest, unsigned int number, int base, int hight) {
  int is_negative = 0;  // flag negative number
  char *string_pointer = dest;

  if (base == 0)
    base = 10;
  else if (base == 10 && (int)number < 0) {
    number = ~number + 1;  // reverse bytes for negative number
    is_negative = 1;       // set negative flag
  }

  do {
    *string_pointer++ = s21_number_to_char(
        number % base, hight);  // get remainder of div and add to result string
    number /= base;
  } while (number != 0);  // fill string with number

  if (base == 10 && is_negative)
    *string_pointer++ = '-';  // set '-' for negative decimal number
  *string_pointer = '\0';     // set end of string
  s21_reverse_string(dest);

  return dest;
}
char *s21_long_to_string(char *dest, unsigned long number, int base,
                         int hight) {
  int is_negative = 0;  // flag negative number
  char *string_pointer = dest;

  if (base == 0)
    base = 10;  // for %u(unsigned number)
  else if (base == 10 && (long)number < 0) {
    number = ~number + 1;  // reverse bytes for negative number
    is_negative = 1;       // set negative flag
  }

  do {
    *string_pointer++ = s21_number_to_char(
        number % base, hight);  // get remainder of div and add to result string
    number /= base;
  } while (number != 0);  // fill string with number

  if (base == 10 && is_negative)
    *string_pointer++ = '-';  // set '-' for negative decimal number
  *string_pointer = '\0';     // set end of string
  s21_reverse_string(dest);

  return dest;
}

char s21_number_to_char(int number, int hight) {
  char ch = '?';
  int shift = 0;
  if (!hight) shift = 'a' - 'A';
  if (number > -1 && number < 10) ch = number + '0';
  if (number > 9 && number < 16) ch = number + shift + 55;

  return ch;
}



char *s21_double_to_notation(char *dest, long double number, int accuracy,
                             int hight) {
  char *string_pointer = dest;
  int end = 0;

  if ((long)number == 0 && number != 0) {
    while ((long)number == 0) {
      end--;
      number *= 10.0;
    }
  } else
    while ((long)number > 1 || (long)number < -1) {
      number /= 10.0;
      end++;
    }

  // changes 1 start
  // dest = s21_double_to_string(dest, number, accuracy);
  s21_doubleToString(number, dest, accuracy, 0);
  // changes 1 end
  // printf("dest: %s\n", dest);
  int flag_displacement = 0;
  // printf("accuracy = %d\n", accuracy);
  // printf("number * 10 = %Lf\n", number*10);
  if ((dest[0] == '0' || (dest[0] == '-' && dest[1] == '0')) &&
      s21_strlen(dest) > 3) {
    for (int i = 0; (s21_size_t int)i < s21_strlen(dest) + 1; i++)
      dest[i] = '\0';
    s21_doubleToString(number * 10, dest, accuracy, 0);
    flag_displacement = 1;
  }
  // printf("dest:%s\n", dest);

  while (*string_pointer != '\0') string_pointer++;

  if (hight)
    *string_pointer++ = 'E';
  else
    *string_pointer++ = 'e';

  if (end < 0) {
    *string_pointer++ = '-';
    end *= -1;
  } else
    *string_pointer++ = '+';

  // changes 2 start
  if (flag_displacement == 1 && number != 0) end--;

  char *end_string = calloc(MAX_LEN_NUMBER, sizeof(char));
  s21_int_to_string(end_string, end, 10, LOW_CASE);
  if (s21_strlen(end_string) == 1) {
    end_string[2] = '\0';
    end_string[1] = end_string[0];
    end_string[0] = '0';
  }

  for (int i = 0; (s21_size_t int)i < s21_strlen(end_string); i++) {
    *string_pointer++ = end_string[i];
  }
  free(end_string);

  // changes 2 end

  *string_pointer = '\0';
  return dest;
}

char *s21_reverse_string(char *p) {
  s21_size_t len = s21_strlen(p) - 1;
  char c;
  for (s21_size_t i = 0; i < len; i++, len--) {
    c = *(p + i);
    *(p + i) = *(p + len);
    *(p + len) = c;
  }

  return p;
}


void *s21_to_upper(const char *str) {
  char *our_str1 = s21_NULL;
  if (str) {
    our_str1 = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  }
  if (our_str1) {
    s21_strncpy(our_str1, str, s21_strlen(str) + 1);
    for (char *i = our_str1; *i; i++) {
      if (*i >= 'a' && *i <= 'z') {
        *i -= 32;
      }
    }
  }
  return (void *)our_str1;
}

void *s21_to_lower(const char *str) {
  char *our_str1 = s21_NULL;
  if (str) {
    our_str1 = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
  }
  if (our_str1) {
    s21_strncpy(our_str1, str, s21_strlen(str) + 1);
    for (char *i = our_str1; *i; i++) {
      if (*i >= 'A' && *i <= 'Z') {
        *i += 32;
      }
    }
  }
  return (void *)our_str1;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  int check = 0;
  char *temp = s21_NULL;
  if (src && str) {
    temp =
        (char *)malloc((s21_strlen(src) + s21_strlen(str)) * sizeof(char) + 1);
    if (temp && s21_strlen(src) >= start_index) {
      s21_size_t i = 0;
      while (*src) {
        if (i == start_index) {
          while (*str) {
            temp[i++] = *str++;
          }
        }
        temp[i++] = *src++;
      }
      temp[i] = '\0';
      check = 1;
    } else {
      if (temp) free(temp);
      temp = s21_NULL;
    }
  }

  return check ? temp : s21_NULL;
}

void *s21_trim(const char *src, const char *trim_chars) {
  int check = 0;
  char *temp = s21_NULL;
  if (src) {
    if (!trim_chars || s21_strlen(trim_chars) == 0) {
      temp = (char *)malloc(s21_strlen(src) + 1);
      if (temp) {
        s21_strcpy(temp, src);
        check = 1;
      }
    } else {
      s21_size_t offset = s21_strspn(src, trim_chars);
      s21_size_t endoff = s21_strspn_r(src, trim_chars);
      temp = (char *)malloc((s21_strlen(src)) * sizeof(char) + 1);
      if (temp) {
        s21_size_t i = 0;
        for (; offset <= endoff; i++, offset++) {
          temp[i] = src[offset];
        }
        check = 1;
        temp[i] = '\0';
      }
    }
  }

  return check ? temp : s21_NULL;
}

char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t answer = 0;
  while (str1[answer] && s21_strchr(str2, str1[answer])) {
    answer++;
  }
  return answer;
}

s21_size_t s21_strspn_r(const char *str, const char *trim_chars) {
  s21_size_t i = s21_strlen(str);
  for (; (int)(i - 1) >= 0; i--) {
    if (s21_strchr(trim_chars, str[i]) == s21_NULL) break;
  }
  return i;
}


char *s21_flag_g_double(char *dest, double number, int accuracy, int is_sharp,
                        int hight) {
  int X = s21_get_power(number);
  int P = accuracy;
  if (P == 0) P++;
  if (P > X && X >= -4) {
    accuracy = P - (X + 1);
    s21_doubleToString(number, dest, accuracy, is_sharp);
    dest = s21_delete_end_null_f(dest);
  } else {
    accuracy = P - 1;
    dest = s21_double_to_notation(dest, number, accuracy, hight);
    dest = s21_delete_end_null_e(dest);
  }

  return dest;
}

char *s21_flag_g_long_double(char *dest, long double number, int accuracy,
                             int is_sharp, int hight) {
  int X = s21_get_power(number);
  int P = accuracy;
  if (P == 0) P++;
  if (P > X && X >= -4) {
    accuracy = P - (X + 1);
    s21_long_doubleToString(number, dest, accuracy, is_sharp);
    dest = s21_delete_end_null_f(dest);
  } else {
    accuracy = P - 1;
    dest = s21_double_to_notation(dest, number, accuracy, hight);
    dest = s21_delete_end_null_e(dest);
  }

  return dest;
}

int s21_get_power(long double number) {
  int result = 0;
  int incr = 0;
  long double multiplier = 0.1;
  number = fabsl(number);
  if ((long)number == 0) {
    multiplier = 10.0;
    incr = -1;
  } else {
    incr = 1;
  }
  if (number == 0.0) {
    result = 0;
  } else
    while ((long)number > 9 || (long)number == 0) {
      result += incr;
      number *= multiplier;
    }
  return result;
}

char *s21_delete_end_null_f(char *dest) {
  char *pointer = dest;
  while (*pointer != 0) pointer++;
  pointer--;
  while (*pointer == '0') {
    *pointer-- = '\0';
  }
  if (*pointer == '.') *pointer = '\0';

  return dest;
}

char *s21_delete_end_null_e(char *dest) {
  char *pointer = dest;
  char *end = NULL;
  while (*pointer != 'e' && *pointer != 'E') pointer++;
  end = pointer--;
  while (*pointer == '0') *pointer-- = '\0';
  if (*pointer == '.') *pointer = '\0';
  if ((pointer + 1) != end) (void)s21_strncat(dest, end, 10);

  return 0;
  return dest;
}

int s21_sprintf(char *str, const char *format, ...) {
  struct variables options = {"-+ #0", "hlL", "cdieEfgGosuxXp%", "aaaaa", 0, -2,
                              '\0',    '\0'};
  s21_memset(str, '\0', sizeof(str));
  va_list param;            // creat pointer to optional parameter
  va_start(param, format);  // to find the beginning of optional parameters

  char *output_string_pointer = str;
  char **p_output_string_pointer = &output_string_pointer;
  char *format_pointer = (char *)format;
  char *c_copy = s21_NULL;

  // c - pointer to first character of the format string. Then move the pointer,
  // until the end
  for (char *c = format_pointer; *c; c++) {
    
    // simple text in str
    if (*c != '%') {
      *output_string_pointer = *c;
      output_string_pointer++;
      
      continue;
    }
    // if symbol is '%' take the next symbol and do operation for specifires
    else {
      c++;
      if (*c == '%') {
        *output_string_pointer = *c;
        output_string_pointer++;
      } else {
        c = c + s21_specifire(c, param, options, c_copy, output_string_pointer,
                              p_output_string_pointer, str);

        for (int h = 0; h < 5; h++) {
          options.flag[h] = 'a';
        }

        options.width = 0;
        options.precision = -2;
        options.size = '\0';
        options.type = '\0';
      }
    }
    
  }

  va_end(param);

  return s21_strlen(str);
}

int s21_specifire(char *c, va_list param, struct variables options,
                  char *c_copy, char *output_string_pointer,
                  char **p_output_string_pointer, char *str) {
  int flag_error = 0, str_specifire_len = 0;
  char str_specifire[MAX_STRING_LEN] = {'\0'};
  c_copy = c;

  while (!s21_is_in_str(*c_copy, options.types) && *c_copy != '\0') {
    str_specifire[str_specifire_len] = *c_copy;
    str_specifire_len++;
    c_copy++;
  }


  int indicator = 0, i = 0;

  int flag_break = 0;
  if (indicator == 0) {  // check is it flag
    if (str_specifire[i] == '\0')
      flag_break = 1;
    else {
      indicator++;
      while (s21_is_in_str(str_specifire[i], options.flags) == 1) {
        if (str_specifire[i] == '-') options.flag[0] = '-';
        if (str_specifire[i] == '+') options.flag[1] = '+';
        if (str_specifire[i] == ' ') options.flag[2] = ' ';
        if (str_specifire[i] == '#') options.flag[3] = '#';
        if (str_specifire[i] == '0') options.flag[4] = '0';
        // options.flag = str_specifire[i];
        i++;
        // break;
      }
    }
  }

  if (indicator == 1 && flag_break == 0) {  // check is it width
    if (str_specifire[i] == '\0')
      flag_break = 1;
    else {
      indicator++;
      if (str_specifire[i] == '*') {
        options.width = -1;
        i++;
      } else if (str_specifire[i] >= 48 &&
                 str_specifire[i] <= 57) {  // if number go along the line until
                                            // the numbers ends
        int number = 0;

        while (str_specifire[i] >= 48 && str_specifire[i] <= 57) {
          number = number * 10 + (str_specifire[i] - 48);
          i++;
        }
        i--;
        options.width = number;
        i++;
      }
    }
  }

  if (indicator == 2 && flag_break == 0) {  // check is it presidion
    if (str_specifire[i] == '\0')
      flag_break = 1;
    else {
      indicator++;

      if (str_specifire[i] == '.') {
        i++;

        if (str_specifire[i] == '*') {
          options.precision = -1;
          i++;
        } else if (str_specifire[i] >= 48 &&
                   str_specifire[i] <= 57) {  // if number go along the line
                                              // until the numbers ends
          int number = 0;

          while (str_specifire[i] >= 48 && str_specifire[i] <= 57) {
            number = number * 10 + (str_specifire[i] - 48);
            i++;
          }
          i--;
          options.precision = number;
          i++;
        }
        else {
          options.precision = 0;
        }
      }
    }
  }

  if (indicator == 3 && flag_break == 0) {  // check is it width
    if (str_specifire[i] == '\0')
      flag_break = 1;
    else {
      indicator++;
      if (s21_is_in_str(str_specifire[i], options.sizes)) {
        options.size = str_specifire[i];
        i++;
        flag_break = 1;
      }
    }
  }

  if (flag_break == 0) {
    flag_error = 1;
  }

  /////////////////////


  if (flag_error == 0 && s21_is_in_str(*c_copy, options.types))
    options.type = *c_copy;

  if (flag_error == 1) {
    c_copy = &str_specifire[i];

    *output_string_pointer = str_specifire[i];
    output_string_pointer++;

    *p_output_string_pointer = output_string_pointer;
  }

  s21_processing(param, options, output_string_pointer, p_output_string_pointer,
                 str);

  return i;
}

void s21_processing(va_list param, struct variables options,
                    char *output_string_pointer, char **p_output_string_pointer,
                    char *str) {
  // if * in width or precision
  if (options.width == -1) {
    options.width = va_arg(param, int);
  }
  if (options.precision == -1) {
    options.precision = va_arg(param, int);
  }

  if (options.type == 'd' || options.type == 'i') {
    if (options.size == '\0') {
      int arg = va_arg(param, int);  // type(d,i) for int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_int(arg, options, output_string_pointer);
    } else if (options.size == 'h') {
      short arg = (short)va_arg(param, int);  // type(d,i) for short int *DONE
      *p_output_string_pointer =
          s21_type_d_i_for_int((int)arg, options, output_string_pointer);
    } else if (options.size == 'l') {
      long int arg = va_arg(param, long int);  // type(d,i) for long int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_long_int(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 'u' || options.type == 'o' || options.type == 'x' ||
      options.type == 'X') {
    if (options.size == '\0') {
      unsigned int arg =
          va_arg(param, unsigned int);  // type(u,o,x,X) for unsigned int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_int(arg, options, output_string_pointer);
    } else if (options.size == 'h') {
      unsigned short int arg = (unsigned short int)va_arg(
          param, unsigned int);  // type(u,o,x,X) for unsigned int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_int(arg, options, output_string_pointer);
    } else if (options.size == 'l') {
      unsigned long int arg = va_arg(
          param,
          unsigned long int);  // type(u,o,x,X) for unsigned long int DONE
      *p_output_string_pointer =
          s21_type_d_i_for_long_int(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 'f' || options.type == 'e' || options.type == 'E' ||
      options.type == 'g' || options.type == 'G') {
    if (options.size == '\0' || options.size == 'h' || options.size == 'l') {
      double arg = va_arg(param, double);  // type(f,e,E,g,G) for double WORK
      *p_output_string_pointer =
          s21_for_double(arg, options, output_string_pointer);
    } else if (options.size == 'L') {
      long double arg =
          va_arg(param, long double);  // type(f,e,E,g,G) for long double WORK
      *p_output_string_pointer =
          s21_for_long_double(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 'c') {
    if (options.size == '\0' || options.size == 'l' || options.size == 'h' ||
        options.size == 'L') {
      int arg = va_arg(param, int);  // type(c) for int DONE
      *p_output_string_pointer =
          s21_type_c_for_int(arg, options, output_string_pointer);
    } else if (options.size == 'l') {
      // wint_t arg = va_arg(param, wint_t);   // type(c) for wint_t    (with
      // #include <wchar.h>)
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 's') {
    if (options.size == '\0' || options.size == 'h' || options.size == 'L') {
      char *arg = va_arg(param, char *);  // type(s) for char* DONE
      *p_output_string_pointer =
          s21_type_s_for_char(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (options.type == 'p') {
    if (options.size == '\0') {
      void *arg = va_arg(param, void *);  // type(p) for void*

      *p_output_string_pointer =
          s21_type_p_for_void(arg, options, output_string_pointer);
    } else {
      fprintf(stderr, "INVALID VALIDATION\n");
    }
  }

  if (str == s21_NULL) {
    ;
  }

  if (options.type == '%') {
    // put % in str
  }
}

int s21_is_in_str(char symbol, char str[]) {
  int counter = 0;
  int result = 0;
  while (str[counter] != '\0') {
    if (symbol == str[counter]) {
      result = 1;
      break;
    }
    counter++;
  }

  return result;
}

// take argument and make a variable "arg" of the corect type

char *s21_type_d_i_for_int(unsigned int arg, struct variables options,
                           char *output_string_pointer) {
  int hight = LOW_CASE;
  if (options.type == 'X') hight = HIGHT_CASE;
  int base = 10;

  if (options.type == 'o')
    base = 8;
  else if (options.type == 'X' || options.type == 'x')
    base = 16;
  else if (options.type == 'u')
    base = 0;

  char *dest = calloc(MAX_STRING_LEN, sizeof(char));

  dest = s21_int_to_string(dest, arg, base, hight);

  // for flag # and type o

  if (options.flag[3] == '#' && options.type == 'o' && arg != 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    dest[0] = '0';
    for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
      dest[i + 1] = dest_copy[i];
    }
    free(dest_copy);
  }

  //            precision
  if (options.precision == 0 && arg == 0) {
    dest[0] = '\0';
  } else if ((int)s21_strlen(dest) < options.precision) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_zero = options.precision - s21_strlen(dest);
    int i = 0;

    for (; i < count_of_zero; i++) {
      dest[i] = '0';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    int n = 0;
    for (; i < options.precision; i++) {
      dest[i] = dest_copy[n];
      n++;
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  if ((options.flag[1] == '+' || options.flag[2] == ' ') &&
      options.type != 'u') {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));

    if ((int)arg >= 0) {
      if (options.flag[1] == '+')
        dest[0] = '+';
      else
        dest[0] = ' ';

      for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
        dest[i + 1] = dest_copy[i];
      }
    }


    free(dest_copy);
  }

  // for flag # and type x/X

  if (options.flag[3] == '#' && (options.type == 'X' || options.type == 'x') &&
      arg != 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    dest[0] = '0';
    if (options.type == 'x')
      dest[1] = 'x';
    else if (options.type == 'X')
      dest[1] = 'X';

    for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
      dest[i + 2] = dest_copy[i];
    }
    free(dest_copy);
  }

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;

    //*p_output_string_pointer++;
  }

  free(dest);

  return output_string_pointer;
}


char *s21_type_d_i_for_long_int(unsigned long int arg, struct variables options,
                                char *output_string_pointer) {
  int hight = LOW_CASE;
  if (options.type == 'X') hight = HIGHT_CASE;
  int base = 10;

  if (options.type == 'o')
    base = 8;
  else if (options.type == 'X' || options.type == 'x')
    base = 16;
  else if (options.type == 'u')
    base = 0;

  char *dest = calloc(MAX_STRING_LEN, sizeof(char));

  dest = s21_long_to_string(dest, arg, base, hight);

  // for flag # and type o

  if (options.flag[3] == '#' && options.type == 'o' && arg != 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    dest[0] = '0';
    for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
      dest[i + 1] = dest_copy[i];
    }
    free(dest_copy);
  }

  //            precision
  if (options.precision == 0 && arg == 0) {
    dest[0] = '\0';
  } else if ((int)s21_strlen(dest) < options.precision) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_zero = options.precision - s21_strlen(dest);
    int i = 0;

    for (; i < count_of_zero; i++) {
      dest[i] = '0';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    int n = 0;
    for (; i < options.precision; i++) {
      dest[i] = dest_copy[n];
      n++;
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  if ((options.flag[1] == '+' || options.flag[2] == ' ') &&
      options.type != 'u') {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    if ((long int)arg >= 0) {
      if (options.flag[1] == '+')
        dest[0] = '+';
      else
        dest[0] = ' ';

      for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
        dest[i + 1] = dest_copy[i];
      }
    }

    free(dest_copy);
  }

  // for flag # and type x/X

  if (options.flag[3] == '#' && (options.type == 'X' || options.type == 'x') &&
      arg != 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    dest[0] = '0';
    if (options.type == 'x')
      dest[1] = 'x';
    else if (options.type == 'X')
      dest[1] = 'X';

    for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
      dest[i + 2] = dest_copy[i];
    }
    free(dest_copy);
  }

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;
  }

  free(dest);

  return output_string_pointer;
}

char *s21_for_double(double arg, struct variables options,
                     char *output_string_pointer) {
  int flag_free = 1;
  if (options.precision == -2) options.precision = 6;
  int is_sharp = 0;
  if (options.flag[3] == '#') is_sharp = 1;
  char *dest = calloc(MAX_STRING_LEN, sizeof(char));
  char *dest_1 = calloc(MAX_STRING_LEN, sizeof(char));
  if (arg == INFINITY || arg == -INFINITY) {
    dest[0] = 'i';
    dest[1] = 'n';
    dest[2] = 'f';
  } else if (isnan(arg)) {
    dest[0] = 'n';
    dest[1] = 'a';
    dest[2] = 'n';
  } else {
    if (options.type == 'f') {
      s21_doubleToString(arg, dest, options.precision, is_sharp);
    } else if (options.type == 'e') {
      dest = s21_double_to_notation(dest, arg, options.precision, LOW_CASE);
    } else if (options.type == 'E') {
      dest = s21_double_to_notation(dest, arg, options.precision, HIGHT_CASE);
    } else if (options.type == 'g') {
      dest =
          s21_flag_g_double(dest, arg, options.precision, is_sharp, LOW_CASE);
    } else if (options.type == 'G') {
      dest =
          s21_flag_g_double(dest, arg, options.precision, is_sharp, HIGHT_CASE);
    }
    // something for G and g
    if (dest == s21_NULL) {
      dest = dest_1;
      flag_free = 0;
    }

    if (arg < 0) {
      for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
        dest[i] = dest[i + 1];
      }
    }
  }

  //            precision

  if ((options.flag[1] == '+' || options.flag[2] == ' ') && arg >= 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    if (arg >= 0) {
      if (options.flag[1] == '+')
        dest[0] = '+';
      else
        dest[0] = ' ';

      for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
        dest[i + 1] = dest_copy[i];
      }
    }


    free(dest_copy);
  } else if (arg < 0) {
    dest[s21_strlen(dest)] = '\0';
    for (int i = s21_strlen(dest); i > 0; i--) {
      dest[i] = dest[i - 1];
    }
    dest[0] = '-';
  }

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }


  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;
  }
  if (flag_free == 1) {
    free(dest);
  }
  free(dest_1);

  return output_string_pointer;
}

char *s21_for_long_double(long double arg, struct variables options,
                          char *output_string_pointer) {
  int flag_free = 1;
  if (options.precision == -2) options.precision = 6;
  int is_sharp = 0;
  if (options.flag[3] == '#') is_sharp = 1;

  char *dest = calloc(MAX_STRING_LEN, sizeof(char));
  char *dest_1 = calloc(MAX_STRING_LEN, sizeof(char));

  if (arg == INFINITY || arg == -INFINITY) {
    dest[0] = 'i';
    dest[1] = 'n';
    dest[2] = 'f';
  } else if (isnan(arg)) {
    dest[0] = 'n';
    dest[1] = 'a';
    dest[2] = 'n';
  } else {
    if (options.type == 'f') {
      s21_long_doubleToString(arg, dest, options.precision, is_sharp);
    } else if (options.type == 'e') {
      dest = s21_double_to_notation(dest, arg, options.precision, LOW_CASE);
    } else if (options.type == 'E') {
      dest = s21_double_to_notation(dest, arg, options.precision, HIGHT_CASE);
    } else if (options.type == 'g') {
      dest = s21_flag_g_long_double(dest, arg, options.precision, is_sharp,
                                    LOW_CASE);
    } else if (options.type == 'G') {
      dest = s21_flag_g_long_double(dest, arg, options.precision, is_sharp,
                                    HIGHT_CASE);
    }

    if (dest == s21_NULL) {
      dest = dest_1;
      flag_free = 0;
    }

    if (arg < 0) {
      for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
        dest[i] = dest[i + 1];
      }
    }
  }

  //            precision

  if ((options.flag[1] == '+' || options.flag[2] == ' ') && arg >= 0) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    if (arg >= 0) {
      if (options.flag[1] == '+')
        dest[0] = '+';
      else
        dest[0] = ' ';

      for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
        dest[i + 1] = dest_copy[i];
      }
    }

    free(dest_copy);
  } else if (arg < 0) {
    dest[s21_strlen(dest)] = '\0';
    for (int i = s21_strlen(dest); i > 0; i--) {
      dest[i] = dest[i - 1];
    }
    dest[0] = '-';
  }

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }


  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;
  }

  if (flag_free == 1) {
    free(dest);
  }
  free(dest_1);

  return output_string_pointer;
}

char *s21_type_s_for_char(char *arg, struct variables options,
                          char *output_string_pointer) {
  char *dest = calloc(MAX_STRING_LEN, sizeof(char));

  for (int i = 0; (s21_size_t int)i < s21_strlen(arg); i++) {
    dest[i] = arg[i];
  }

  if (options.precision >= 0 && (int)s21_strlen(dest) > options.precision) {
    int len = s21_strlen(dest);
    for (int i = options.precision; i < len; i++) dest[i] = '\0';
  }

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }
    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;
  }

  free(dest);

  return output_string_pointer;
}

char *s21_type_c_for_int(char arg, struct variables options,
                         char *output_string_pointer) {
  char *dest = calloc(MAX_STRING_LEN, sizeof(char));
  dest[0] = arg;

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;
  }

  free(dest);

  return output_string_pointer;
}

char *s21_type_p_for_void(void *arg, struct variables options,
                          char *output_string_pointer) {
  uintptr_t address = (uintptr_t)arg;

  char *dest = calloc(MAX_STRING_LEN, sizeof(char));

  dest = s21_long_to_string(dest, address, 16, LOW_CASE);

  //            precision
  if (options.precision == 0 && arg == 0) {
    dest[0] = '\0';
  } else if ((int)s21_strlen(dest) < options.precision) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_zero = options.precision - s21_strlen(dest);
    int i = 0;

    for (; i < count_of_zero; i++) {
      dest[i] = '0';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    int n = 0;
    for (; i < options.precision; i++) {
      dest[i] = dest_copy[n];
      n++;
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }


  // for flag # and type x/X

  char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
  s21_memcpy(dest_copy, dest, s21_strlen(dest));
  dest[0] = '0';
  dest[1] = 'x';

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest_copy); i++) {
    dest[i + 2] = dest_copy[i];
  }
  free(dest_copy);

  // width

  if (s21_strlen(dest) < (s21_size_t int)options.width) {
    char *dest_copy = calloc(MAX_STRING_LEN, sizeof(char));
    s21_memcpy(dest_copy, dest, s21_strlen(dest));
    int count_of_space = options.width - s21_strlen(dest);
    int i = 0;
    int step = 0;
    if (options.flag[0] == '-') step = s21_strlen(dest);

    for (; i < count_of_space; i++) {
      if (options.flag[4] == '0')
        dest[i + step] = '0';
      else
        dest[i + step] = ' ';
    }

    // s21_insert(dest, dest_copy, i)    start    here
    if (options.flag[0] != '-') {
      int n = 0;
      for (; i < options.width; i++) {
        dest[i] = dest_copy[n];
        n++;
      }
    }
    // s21_insert(dest, dest_copy, i)     finish    here
    free(dest_copy);
  }

  // printf("final dest:%s()\n", dest);

  for (int i = 0; (s21_size_t int)i < s21_strlen(dest); i++) {
    *output_string_pointer = dest[i];
    output_string_pointer++;
  }

  free(dest);

  return output_string_pointer;
}

void s21_doubleToString(double number, char *rezult, int accuracy,
                        int is_sharp) {
  int modifire = 0, is_negative = 0;

  ////////////
  // if (number > 0)printf("OOOOOO number = %.30Lf\n", (long double)number);
  /////////////
  if (number < 0) {
    number *= -1.0;  // get positiv number
    is_negative = 1;
  }

  int intPart = (int)number;
  double decimalPart = fabs(number - intPart);

  if (accuracy == 0) {
    number = round(number);
    int int_number = (int)number;
    int intDigits = (int)log10(fabs((float)int_number)) + 1;
    int i = intDigits - 1;
    while (int_number > 0) {
      rezult[i] = (int_number % 10) + '0';
      int_number /= 10;
      i--;
    }

    if (number == 0) {
      rezult[0] = '0';
      rezult[1] = '\0';
    }

    if (is_sharp == 1) {
      rezult[s21_strlen(rezult)] = '.';
      rezult[s21_strlen(rezult)] = '\0';
    }

  }

  else if (number == (double)(int)number) {
    int int_number = (int)number;
    int intDigits = (int)log10(fabs((float)intPart)) + 1;
    int i = intDigits - 1;
  
    while (int_number > 0) {
      rezult[i] = (int_number % 10) + '0';
      int_number /= 10;
      i--;
    }

    if (number == 0) {
      rezult[0] = '0';
      intDigits = 1;
    }

    rezult[intDigits] = '\0';
    int len = s21_strlen(rezult);
    rezult[len] = '.';
    for (int i = 0; i < accuracy; i++) {
      rezult[len + 1 + i] = '0';
    }

  }

  else {
    char *str = calloc(1024, sizeof(char));

    // Calculate the number of digits in the integer part
    int intDigits = (int)log10(fabs((float)intPart)) + 1;
    // Calculate the number of decimal places required
    int decimalPlaces =
        (decimalPart != 0.0) ? (int)log10(1.0 / decimalPart) + 1 : 0;

    // Convert the integer part to string
    int i = intDigits - 1;

    if (intPart == 0) {
      str[0] = '0';
      intDigits = 1;
    } else {
      while (intPart > 0) {
        str[i] = (intPart % 10) + '0';
        intPart /= 10;
        i--;
      }
    }

    // Add the decimal point if necessary
    int index_after_point = i;

    if (decimalPlaces > 0) {
      str[intDigits] = '.';
      i = intDigits + 1 /*+ decimalPlaces*/;
      index_after_point = i;

      // Convert the decimal part to string

      while (decimalPart > 0) {
        decimalPart *= 10;
        int digit = (int)decimalPart;
        str[i] = digit + '0';
        decimalPart -= digit;
        decimalPlaces--;
        i++;
      }
    }


    for (int j = 0; j < index_after_point; j++) {
      rezult[j] = str[j];
    }
    int last_digit_index = index_after_point + accuracy - 1;
    if (index_after_point >= 0) {
      for (int j = index_after_point; j < last_digit_index; j++) {
        rezult[j] = str[j];
      }
    }
    ///////////////
    else {
      s21_doubleToString(0, rezult, accuracy, is_sharp);
      index_after_point = 0;
      last_digit_index = 0;
    }
    ///////////////
    //////////////

    char next_simbol = str[last_digit_index + 1];
    if (next_simbol <= '4') {
      rezult[last_digit_index] = str[last_digit_index];
    } else if (next_simbol >= '6') {
      int copy = last_digit_index;
      if (str[copy] == '9') {
        while (str[copy] == '9') {
          // while ( last_digit_index - back_to_norm_digit == '9' ) {
          rezult[copy] = '0';
          // back_to_norm_digit ++;
          // }
          copy--;
        }
        if (str[copy] == '.') {
          rezult[copy] = '.';
          copy--;
        }
        if (str[copy] == '9') {
          modifire = 1;
        } else {
          rezult[copy] = str[copy] + 1;
        }
      } else {
        rezult[last_digit_index] = str[last_digit_index] + 1;
      }
    } else if (next_simbol == '5') {
      int flag_trash = 0;

      for (int m = last_digit_index + 2; (s21_size_t int)m < s21_strlen(str);
           m++) {
        if (str[m] != '0') {
          flag_trash = 1;
          break;
        }
      }

      if (flag_trash == 1) {
        int copy = last_digit_index;
        if (str[copy] == '9') {
          while (str[copy] == '9') {
            // while ( last_digit_index - back_to_norm_digit == '9' ) {
            rezult[copy] = '0';
            copy--;
          }
          if (str[copy] == '.') {
            rezult[copy] = '.';
            copy--;
            if (rezult[copy] == '9') {
              modifire = 1;
            } else {
              rezult[copy] = rezult[copy] + 1;
            }
          } else {
            rezult[copy] = rezult[copy] + 1;
          }
        } else {
          rezult[last_digit_index] = str[last_digit_index] + 1;
        }
      } else {
        rezult[last_digit_index] = str[last_digit_index];
      }
    }


    if (s21_strlen(rezult) - intDigits - 1 < (s21_size_t int)accuracy) {
      for (int m = s21_strlen(rezult); m < accuracy + intDigits + 1; m++) {
        rezult[m] = '0';
      }
    }

    if (modifire == 1) {
      for (int y = 0; (s21_size_t int)y < s21_strlen(rezult); y++) {
        rezult[y] = '\0';
      }
      s21_doubleToString((double)((int)number + 1), rezult, accuracy, is_sharp);
    }

    int point_is_here = 0;
    for (int y = 0; (s21_size_t int)y < s21_strlen(rezult); y++) {
      if (rezult[y] == '.' && point_is_here == 1) {
        rezult[y] = '\0';
        rezult[y + 1] = '\0';
        break;
      }
      if (rezult[y] == '.') {
        point_is_here = 1;
      }
    }

    free(str);
  }

  if (is_negative == 1) {
    rezult[s21_strlen(rezult) + 1] = '\0';
    for (int i = s21_strlen(rezult); i > 0; i--) {
      rezult[i] = rezult[i - 1];
    }
    rezult[0] = '-';
  }
}

void s21_long_doubleToString(long double number, char *rezult, int accuracy,
                             int is_sharp) {
  int modifire = 0, is_negative = 0;

  if (number < 0) {
    number *= -1.0;  // get positiv number
    is_negative = 1;
  }

  long int intPart = (long int)number;
  long double decimalPart = (long double)fabs((double)number - (double)intPart);


  if (accuracy == 0) {
    number = round(number);
    int int_number = (int)number;
    int intDigits = (int)log10(fabs((float)int_number)) + 1;
    int i = intDigits - 1;
    while (int_number > 0) {
      rezult[i] = (int_number % 10) + '0';
      int_number /= 10;
      i--;
    }

    if (number == 0) {
      rezult[0] = '0';
      rezult[1] = '\0';
    }

    if (is_sharp == 1) {
      rezult[s21_strlen(rezult)] = '.';
      rezult[s21_strlen(rezult)] = '\0';
    }

  }

  else if (number == (long double)(int)number) {
    int int_number = (int)number;
    int intDigits = (int)log10(fabs((float)intPart)) + 1;

    int i = intDigits - 1;
    while (int_number > 0) {
      rezult[i] = (int_number % 10) + '0';
      int_number /= 10;
      i--;
    }

    if (number == 0) {
      rezult[0] = '0';
      intDigits = 1;
    }

    rezult[intDigits] = '\0';
    int len = s21_strlen(rezult);
    rezult[len] = '.';

    for (int i = 0; i < accuracy; i++) {
      rezult[len + 1 + i] = '0';
    }

  }

  else {
    char *str = calloc(1024, sizeof(char));

    // Calculate the number of digits in the integer part
    int intDigits = (int)log10(fabs((float)intPart)) + 1;
    // Calculate the number of decimal places required
    int decimalPlaces =
        (decimalPart != 0.0) ? (int)log10(1.0 / decimalPart) + 1 : 0;

    // Convert the integer part to string
    int i = intDigits - 1;

    if (intPart == 0) {
      str[0] = '0';
      intDigits = 1;
    } else {
      while (intPart > 0) {
        str[i] = (intPart % 10) + '0';
        intPart /= 10;
        i--;
      }
    }

    // Add the decimal point if necessary
    int index_after_point = i;

    if (decimalPlaces > 0) {
      str[intDigits] = '.';
      i = intDigits + 1 /*+ decimalPlaces*/;

      index_after_point = i;

      // Convert the decimal part to string

      while (decimalPart > 0) {
        decimalPart *= 10;
        int digit = (int)decimalPart;
        str[i] = digit + '0';
        decimalPart -= digit;
        decimalPlaces--;
        i++;
      }
    }

    for (int j = 0; j < index_after_point; j++) {
      rezult[j] = str[j];
    }

    int last_digit_index = index_after_point + accuracy - 1;
    for (int j = index_after_point; j < last_digit_index; j++) {
      rezult[j] = str[j];
    }

    char next_simbol = str[last_digit_index + 1];

    if (next_simbol <= '4') {
      rezult[last_digit_index] = str[last_digit_index];
    } else if (next_simbol >= '6') {
      int copy = last_digit_index;
      if (str[copy] == '9') {
        while (str[copy] == '9') {
          rezult[copy] = '0';
          copy--;
        }
        if (str[copy] == '.') {
          rezult[copy] = '.';
          copy--;
        }
        if (str[copy] == '9') {
          modifire = 1;
        } else {
          rezult[copy] = str[copy] + 1;
        }
      } else {
        rezult[last_digit_index] = str[last_digit_index] + 1;
      }
    } else if (next_simbol == '5') {
      int flag_trash = 0;

      for (int m = last_digit_index + 2; (s21_size_t int)m < s21_strlen(str);
           m++) {
        if (str[m] != '0') {
          flag_trash = 1;
          break;
        }
      }

      if (flag_trash == 1) {
        int copy = last_digit_index;
        if (str[copy] == '9') {
          while (str[copy] == '9') {
            rezult[copy] = '0';
            copy--;
          }
          if (str[copy] == '.') {
            rezult[copy] = '.';
            copy--;
            if (rezult[copy] == '9') {
              modifire = 1;
            } else {
              rezult[copy] = rezult[copy] + 1;
            }
          } else {
            rezult[copy] = rezult[copy] + 1;
          }
        } else {
          rezult[last_digit_index] = str[last_digit_index] + 1;
        }
      } else {
        rezult[last_digit_index] = str[last_digit_index];
      }
    }

    if (s21_strlen(rezult) - intDigits - 1 < (s21_size_t int)accuracy) {
      for (int m = s21_strlen(rezult); m < accuracy + intDigits + 1; m++) {
        rezult[m] = '0';
      }
    }

    if (modifire == 1) {
      for (int y = 0; (s21_size_t int)y < s21_strlen(rezult); y++) {
        rezult[y] = '\0';
      }
      s21_long_doubleToString((long double)((int)number + 1), rezult, accuracy,
                              is_sharp);
    }

    int point_is_here = 0;
    for (int y = 0; (s21_size_t int)y < s21_strlen(rezult); y++) {
      if (rezult[y] == '.' && point_is_here == 1) {
        rezult[y] = '\0';
        rezult[y + 1] = '\0';
        break;
      }
      if (rezult[y] == '.') {
        point_is_here = 1;
      }
    }

    free(str);
  }

  if (is_negative == 1) {
    rezult[s21_strlen(rezult) + 1] = '\0';
    for (int i = s21_strlen(rezult); i > 0; i--) {
      rezult[i] = rezult[i - 1];
    }
    rezult[0] = '-';
  }
}
