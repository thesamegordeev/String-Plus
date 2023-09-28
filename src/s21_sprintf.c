#include "s21_sprintf.h"

#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list va;
  va_start(va, format);
  char *copy_str = str;
  while (*format) {
    if (*format != '%') {
      *str++ = *format++;
      continue;
    } else {
      format++;
      flag flags = {0};
      char buff[4096] = {'\0'};
      get_opt(&format, &flags);
      process(buff, flags, &va);
      for (s21_size_t i = 0; i < s21_strlen(buff); i++) {
        *str++ = buff[i];
      }
    }
  }
  *str = '\0';
  int a = str - copy_str;
  str = copy_str;
  va_end(va);
  return a;
}

void get_opt(const char **format, flag *flags) {
  *format = get_flags(*format, flags);   // checked
  *format = get_width(*format, flags);   // checked
  *format = get_prec(*format, flags);    // checked
  *format = get_length(*format, flags);  // checked
  *format = get_type(*format, flags);    // checked
}

char *get_flags(const char *format, flag *flags) {
  char *ptr = (char *)format;
  while (*ptr == '+' || *ptr == '-' || *ptr == ' ') {
    switch (*ptr) {
      case '+':
        flags->plus = 1;
        flags->space = 0;
        break;
      case '-':
        flags->minus = 1;
        break;
      case ' ':
        if (!flags->plus) {
          flags->space = 1;
        }
    }
    ptr++;
  }
  return ptr;
}

char *get_width(const char *format, flag *flags) {
  char *ptr = (char *)format;
  while (*ptr >= '0' && *ptr <= '9') {
    flags->width *= 10;
    flags->width += (*ptr - '0');
    ptr++;
  }
  return ptr;
}

char *get_prec(const char *format, flag *flags) {
  char *ptr = (char *)format;
  if (*ptr == '.') {
    flags->dot = 1;
    ptr++;
    while (*ptr >= '0' && *ptr <= '9') {
      flags->prec *= 10;
      flags->prec += (*ptr - '0');
      ptr++;
    }
  }
  return ptr;
}

char *get_length(const char *format, flag *flags) {
  char *ptr = (char *)format;
  if (*ptr == 'h') {
    flags->h = 1;
  } else if (*ptr == 'l') {
    flags->l = 1;
  }

  if (flags->l || flags->h) {
    ptr++;
  }

  return ptr;
}

char *get_type(const char *format, flag *flags) {
  char *ptr = (char *)format;
  flags->type = *ptr;
  ptr++;
  return ptr;
}

void process(char *buff, flag flags, va_list *va) {
  switch (flags.type) {
    case 'd':
      process_di(buff, flags, va);
      break;
    case 'i':
      process_di(buff, flags, va);
      break;
    case 'c':
      process_c(buff, flags, va);
      break;
    case 's':
      process_s(buff, flags, va);
      break;
    case 'u':
      process_di(buff, flags, va);
      break;
    case 'f':
      process_f(buff, flags, va);
      break;
    default:
      break;
  }
}

void process_di(char *buff, flag flags, va_list *va) {
  long long int num = va_arg(*va, long long int);
  if (flags.h) {
    if (flags.type == 'u') {
      num = (unsigned short int)num;
    } else {
      num = (short int)num;
    }
  } else if (!flags.l) {
    if (flags.type == 'u') {
      num = (unsigned int)num;
    } else {
      num = (int)num;
    }
  }
  int len = num_len(num) > flags.prec ? num_len(num) : flags.prec + (num < 0);
  char *num_string = malloc((len + 5) * sizeof(char));
  s21_memset(num_string, '\0', len + 1);

  int_to_string(num_string, num, len);
  if (flags.prec > num_len(num)) {
    s21_memmove(num_string + flags.prec, num_string, num_len(num));
    s21_memset(num_string, '0', flags.prec - num_len(num));
  }
  apply_flags(buff, num_string, len, num, flags);
  free(num_string);
}

int num_len(long long int num) {
  int len = 0;
  len = (num == 0) ? 1 : len;
  len = (num < 0) ? len + 1 : len;
  while (num != 0) {
    num /= 10;
    len++;
  }
  return len;
}

void int_to_string(char *num_string, long long int num, int len) {
  if (num < 0) {
    num *= -1;
    num_string[0] = '-';
  }

  if (num == 0) num_string[0] = '0';

  for (int i = len - 1; num != 0; i--) {
    num_string[i] = (num % 10) + '0';
    num /= 10;
  }
}

void apply_flags(char *buff, char *num_string, int len, long long int num,
                 flag flags) {
  if (flags.plus && num >= 0 && flags.type != 'u') {
    applyPlus(num_string, &len);
  }

  if (((flags.space && num >= 0 && flags.width - len < 1) ||
       (flags.space && flags.minus && num >= 0)) &&
      flags.type != 'u') {
    applySpace(num_string, &len);
  }

  if (flags.minus) {
    applyMinus(buff, num_string, len, flags.width);
  } else {
    applyWidth(buff, num_string, len, flags.width);
  }
}

void applyMinus(char *buff, char *num_string, int len, int width) {
  int spaceCount = (width < len) ? 0 : (width - len);
  s21_strcat(buff, num_string);
  for (int i = 0; i < spaceCount; i++) {
    buff[len + i] = ' ';
  }
}

void applyWidth(char *buff, char *num_string, int len, int width) {
  int spaceCount = (width < len) ? 0 : (width - len);
  s21_memset(buff, ' ', spaceCount);
  s21_strcat(buff, num_string);
}

char *applyPlus(char *num_string, int *len) {
  *len = *len + 1;
  char *new = malloc(*len * sizeof(char) + 1);
  s21_memset(new, '\0', *len + 1);
  new[0] = '+';
  s21_strcat(new, num_string);
  s21_strcpy(num_string, new);
  free(new);
  return num_string;
}

char *applySpace(char *num_string, int *len) {
  *len = *len + 1;
  char *new = malloc(*len * sizeof(char) + 1);
  s21_memset(new, '\0', *len + 1);
  new[0] = ' ';
  s21_strcat(new, num_string);
  s21_strcpy(num_string, new);
  free(new);
  return num_string;
}

void process_c(char *buff, flag flags, va_list *va) {
  char c = va_arg(*va, int);
  if (flags.width > 1) {
    int spaceCount = flags.width - 1;
    if (flags.minus) {
      buff[0] = c;
      for (int i = 1; i < spaceCount + 1; i++) {
        buff[i] = ' ';
      }
    } else {
      for (int i = 0; i < spaceCount; i++) {
        buff[i] = ' ';
      }
      buff[spaceCount] = c;
    }
  } else {
    buff[0] = c;
  }
}

void process_s(char *buff, flag flags, va_list *va) {
  char *data = va_arg(*va, char *);
  int len = flags.dot ? flags.prec : (int)s21_strlen(data);
  char *new = calloc((len + 1), sizeof(char));
  if (flags.dot) {
    s21_strncpy(new, data, len);

  } else {
    s21_strcpy(new, data);
  }
  if (flags.minus) {
    applyMinus(buff, new, s21_strlen(new), flags.width);
  } else {
    applyWidth(buff, new, s21_strlen(new), flags.width);
  }
  free(new);
}

double apply_prec(int prec, double num) {
  double shifted = num * pow(10, prec);
  shifted = roundl(shifted);
  return shifted / pow(10, prec);
}

void process_f(char *buff, flag flags, va_list *va) {
  if (!flags.dot) {
    flags.prec = 6;
  }
  double a = va_arg(*va, double);
  double num = a > 0 ? a : -a;
  num = apply_prec(flags.prec, num);
  double integralPart;
  double fractionalPart = round(modf(num, &integralPart) * pow(10, flags.prec));
  int integralPart2 = (int)integralPart;
  integralPart2 *= a < 0 ? -1 : 1;
  char *iP_to_string = malloc((num_len(integralPart2) + 2) * sizeof(char));
  s21_memset(iP_to_string, '\0', num_len(integralPart2) + 1);
  int_to_string(iP_to_string, integralPart2, num_len(integralPart2));
  s21_strcat(iP_to_string, ".");
  char *fP_to_string = malloc((num_len(fractionalPart) + 2) * sizeof(char));
  s21_memset(fP_to_string, '\0', num_len(fractionalPart) + 1);
  int_to_string(fP_to_string, fractionalPart, num_len(fractionalPart));

  char *res_string = malloc(
      (num_len(integralPart2) + num_len(fractionalPart) + 4) * sizeof(char));
  s21_memset(res_string, '\0',
             num_len(integralPart2) + num_len(fractionalPart) + 2);

  s21_strcat(res_string, iP_to_string);
  if (flags.prec != 0) {
    if (fractionalPart == 0) {
      for (int i = 0; i < flags.prec; i++) {
        s21_strcat(res_string, "0");
      }
    } else {
      s21_strcat(res_string, fP_to_string);
    }
  } else {
    res_string[num_len(integralPart2)] = '\0';
  }

  apply_flags(buff, res_string, s21_strlen(res_string), a, flags);
  free(res_string);
  free(fP_to_string);
  free(iP_to_string);
}
