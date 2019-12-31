SOURCE= \
	src/md2.c \
	src/md2_parser.c
TEST_SOURCE= \
	src/test.c \
	src/md2_parser_test.c
LIBRARIES=-L../cutil/bin -lcutil
INCLUDES=-I../