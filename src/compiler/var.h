#ifndef VAR_H
#define VAR_H

#define NSYMS 20 /* 允许的符号个数 */
extern int nsym;

struct symtab {
  char *name;
  double value;
};

extern struct symtab symtab[NSYMS];

struct symtab *symlook();

#endif