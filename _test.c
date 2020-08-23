#include <stdio.h>
#include <string.h>
#include <setjmp.h>
#include <stdarg.h>

#define OOPS(...)       _FAIL(__LINE__, __func__, __VA_ARGS__)
#define FATAL(X)        do { if (X) OOPS("FAIL %s", #X); } while (0)
#define BP              __asm__("int $3")       /* Intel based breakpoint for GDB       */

static jmp_buf	_test_jmp;
static char	_test_buf[BUFSIZ];

static void
_FAIL(int line, const char *fn, const char *s, ...)
{
  va_list	list;

  va_start(list, s);
  vsnprintf(_test_buf, sizeof _test_buf, s, list);
  va_end(list);
  longjmp(_test_jmp, 1);
}

#include _TESTINC

#define	__TESTOUT(FN)	printf("TEST " #FN ": %s\n", _test_buf)
#define	_TESTOUT(FN)	__TESTOUT(FN)

int
main(int argc, char **argv)
{
  int	ret;

  strcpy(_test_buf, "ok");
  if ((ret=setjmp(_test_jmp))==0)
    _TESTFN();
  _TESTOUT(_TESTFN);
  return ret;
}
