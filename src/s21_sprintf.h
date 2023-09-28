#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 4096
typedef struct flags {
  char plus;
  char minus;
  char space;
  int width;
  int dot;
  int prec;
  char h;
  char l;
  char type;
} flag;

void get_opt(const char **format, flag *flags);
char *get_flags(const char *format, flag *flags);
char *get_width(const char *format, flag *flags);
int s21_atoi(char *str);
char *get_prec(const char *format, flag *flags);
char *get_length(const char *format, flag *flags);
char *get_type(const char *format, flag *flags);
void process(char *buff, flag flags, va_list *va);
void int_to_string(char *buff, long long int num, int len);
void process_di(char *buff, flag flags, va_list *va);
void apply_flags(char *buff, char *num_string, int len, long long int num,
                 flag flags);
int num_len(long long int num);
void applyMinus(char *buff, char *num_string, int len, int width);
void applyWidth(char *buff, char *num_string, int len, int width);
char *applyPlus(char *num_string, int *len);
char *applySpace(char *num_string, int *len);
int getLenFracPart(double a, int prec);
double apply_prec(int prec, double num);
void process_c(char *buff, flag flags, va_list *va);
void process_s(char *buff, flag flags, va_list *va);
void process_f(char *buff, flag flags, va_list *va);
void process_s(char *buff, flag flags, va_list *va);
