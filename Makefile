CFLAGS = -Wall -Werror -Wextra -std=c11
SRC = s21_string.c s21_string_test.c 
Q1 = ../build/Quest1
Q2 = ../build/Quest2
Q3 = ../build/Quest3
Q4 = ../build/Quest4
Q5 = ../build/Quest5

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests

strlen_tests: $(SRC)
	gcc $(CFLAGS) -DS21_STRLEN $(SRC) -o $(Q1)

strcmp_tests: $(SRC)
	gcc $(CFLAGS) -DS21_STRCMP $(SRC) -o $(Q2)

strcpy_tests: $(SRC)
	gcc $(CFLAGS) -DS21_SRTCPY $(SRC) -o $(Q3)

strcat_tests: $(SRC)
	gcc $(CFLAGS) -DS21_STRCAT $(SRC) -o $(Q4)

strchr_tests: $(SRC)
	gcc $(CFLAGS) -DS21_STRCHR $(SRC) -o $(Q5)


clean:
	rm -rf $(Q1) $(Q2) $(Q3) $(Q4) $(Q5)


.PHONY: all strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests clean
