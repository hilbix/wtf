#

DEBIAN=libx11-dev

INCLUDES=$(wildcard *.h)
TESTS=$(INCLUDES:.h=.test)

.PHONY:	love
love:	all

.PHONY:	all
all:	test

.PHONY:	test
test:	$(TESTS)
	-for a in *.test; do "./$$a"; done

.PHONY:	clean
clean:
	$(RM) $(TESTS)

.PHONY:	debian
debian:
	apt install $(DEBIAN)

$(TESTS):	_test.c Makefile

%.test:	%.h
	$(CC) -o '$@' -D_TESTINC='"$<"' -D_TESTFN='$(@:.test=)' _test.c `sed -n 's#^.\*-#-#p' '$<'`

