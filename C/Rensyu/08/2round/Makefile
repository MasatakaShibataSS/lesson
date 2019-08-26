CC := gcc
CFLAGS := -Wall -Wextra -fpic
LIBS := -lm
PROGRAMS := 8_1 \
	8_2 \
	8_3 \
	8_4 \
	8_5 \

all: $(PROGRAMS)

8_5: 8_5.o $(LIBS)

clean:
	$(RM) $(PROGRAMS) *.o
