#ifndef __SVSNPRINTF_H__
#define __SVSNPRINTF_H__

/*
 * snprintf() replacement.
 * Place a formatted string in str buffer with maximum size of size.
 * Supported conversion specifications:
 *  flags:
 *    0, -, +
 *  length modifier:
 *    hh, h, l, ll
 *  conversion specifier:
 *    d, i, o, u, x, X, b(binary form), f, c, s, p
 *
 * return:
 *  -1 - str is NULL, but size not
 *  -2 - wrong conversion specifier
 *  >=0 - the length of resulting string (wihout \0)
 */
int ssnprintf(char *str, size_t size, const char *fmt, ...);

int svsnprintf(char *str, size_t size, const char *fmt, va_list ap);

#endif  /* __SVSNPRINTF_H__ */
