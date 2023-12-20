##
## EPITECH PROJECT, 2023
## libmy makefile
## File description:
## Compiles my lib and perform necessary actions
##

CTYPE_FUNCS := ./ctype/my_isneg.c \
			   ./ctype/my_isalpha.c \
			   ./ctype/my_isdigit.c \
			   ./ctype/my_islower.c \
			   ./ctype/my_isprint.c \
			   ./ctype/my_isupper.c \
			   ./ctype/my_tolower.c \
			   ./ctype/my_toupper.c \
			   ./ctype/my_char_to_int.c

MATH_FUNCS := ./math/my_getnbr.c \
			  ./math/my_is_prime.c \
			  ./math/my_find_prime_sup.c \
			  ./math/my_compute_power_rec.c \
			  ./math/my_compute_square_root.c \
			  ./math/my_nbrlen.c \
			  ./math/my_fabs.c \
			  ./math/my_pow10.c \
			  ./math/my_round.c

SORT_FUNCS := ./sort/my_swap.c \
			  ./sort/my_sort_int_array.c

IO_FUNCS := ./io/my_putstr.c \
			./io/my_putnstr.c \
			./io/my_put_nbr.c \
			./io/my_put_nbr_unsigned.c \
			./io/my_putchar.c \
			./io/my_putstr_error.c \
			./io/my_putchar_error.c \
			./io/my_put_float.c \
			./io/my_put_exponent.c \
			./io/my_put_hexadecimal.c \
			./io/my_put_pointer.c \
			./io/my_put_octal.c

IO_FUNCS_PRINTF := 	./io/printf/my_printf.c \
					./io/printf/arguments_tab.c \
					./io/printf/verify_flags.c \
					./io/printf/decimal_conversion.c \
					./io/printf/unsigned_conversion.c \
					./io/printf/get_specifier.c \
					./io/printf/get_flag_char.c \
					./io/printf/field_width.c \
					./io/printf/get_precision.c \
					./io/printf/float_conversion.c \
					./io/printf/exponent_conversion.c \
					./io/printf/hexadecimal_conversion.c \
					./io/printf/octal_conversion.c \
					./io/printf/char_conversion.c \
					./io/printf/string_conversion.c \
					./io/printf/pointer_conversion.c \
					./io/printf/flag_characters/alternate_form.c \
					./io/printf/flag_characters/padding.c \
					./io/printf/flag_characters/put_padding.c

STRINGS_FUNCS := ./strings/my_revstr.c \
				 ./strings/my_strcat.c \
				 ./strings/my_strcmp.c \
				 ./strings/my_str_to_word_array.c \
				 ./strings/my_str_isprintable.c \
				 ./strings/my_show_word_array.c \
				 ./strings/my_strcapitalize.c \
				 ./strings/my_str_isupper.c \
				 ./strings/my_str_islower.c \
				 ./strings/my_str_isalpha.c \
				 ./strings/my_putnbr_base.c \
				 ./strings/my_putnbr_base_unsigned.c \
				 ./strings/my_putnbr_base_int64.c \
				 ./strings/my_strlowcase.c \
				 ./strings/my_strupcase.c \
				 ./strings/my_str_isnum.c \
				 ./strings/my_show_str.c \
				 ./strings/my_strndup.c \
				 ./strings/my_strncpy.c \
				 ./strings/my_strncmp.c \
				 ./strings/my_strncat.c \
				 ./strings/my_showmem.c \
				 ./strings/my_strstr.c \
				 ./strings/my_strlen.c \
				 ./strings/my_strdup.c \
				 ./strings/my_strcpy.c \
				 ./strings/my_memcpy.c \
				 ./strings/my_memset.c

STD_FUNCS = ./std/my_realloc.c \
	./std/my_freearray.c

SRC := $(CTYPE_FUNCS) \
	   $(MATH_FUNCS) \
	   $(SORT_FUNCS) \
	   $(IO_FUNCS) \
	   $(IO_FUNCS_PRINTF) \
	   $(STRINGS_FUNCS) \
	   $(STD_FUNCS)
CFLAGS := -Wall -Wextra -Werror -I .
OBJ := $(SRC:.c=.o)
LIB_DIR := ../../
INCLUDE_DIR := ../../include/
NAME := libmy.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	@mkdir -p $(LIB_DIR)
	@cp $@ $(LIB_DIR)
	@mkdir -p $(INCLUDE_DIR)
	@cp -r ./math/my_math.h $(INCLUDE_DIR)
	@cp -r ./sort/my_sort.h $(INCLUDE_DIR)
	@cp -r ./ctype/my_ctype.h $(INCLUDE_DIR)
	@cp -r ./io/my_io.h $(INCLUDE_DIR)
	@cp -r ./strings/my_strings.h $(INCLUDE_DIR)
	@cp -r ./io/printf/my_printf.h $(INCLUDE_DIR)
	@cp -r ./std/my_std.h $(INCLUDE_DIR)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@rm -f ../../$(NAME)

debug: CFLAGS += -ggdb3
debug: all

re:	fclean
	all
