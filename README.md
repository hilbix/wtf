[![wtf Status](https://api.cirrus-ci.com/github/hilbix/wtf.svg?branch=master)](https://cirrus-ci.com/github/hilbix/wtf/master)

# WTF

Things I do just do not understand.

## Usage

	git clone https://github.com/hilbix/wtf.git
	cd wtf
	make

## FAQ

WTF why?

- Excactly!

Structure?

- Each file `NAME.h` defines a function `void NAME(void)` which is the actual test.
- File `test.c` is the wrapper which includes `NAME.h` to be compiled into `NAME`
- This then is executed by the `Makefile` automatically
