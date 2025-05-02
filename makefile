cc = $(gdb_bin)/riscv64-unknown-elf-gcc
flags = -Wall -g -O2 -march=rv64gc_zicfilp_zicfiss -fcf-protection=full -mabi=lp64d -static
include := $(wildcard ./include/*.c)

# Tests need to get added here.  Tests are compiled individually and each test asembly is also created.
all: test_function_pointer_attack test_invalid_function_pointer return_address_attack
test_function_pointer_attack: $(include) test_function_pointer_attack.c
	$(cc) $(flags) -S test_function_pointer_attack.c -o test_function_pointer_attack.s
	$(cc) $(flags) $(include) test_function_pointer_attack.c -o test_function_pointer_attack.elf

test_invalid_function_pointer: $(include) test_invalid_function_pointer.c
	$(cc) $(flags) -S test_invalid_function_pointer.c -o test_invalid_function_pointer.s
	$(cc) $(flags) $(include) test_invalid_function_pointer.c -o test_invalid_function_pointer.elf

return_address_attack: $(include) return_address_attack.c
	$(cc) $(flags) -S return_address_attack.c -o return_address_attack.s
	$(cc) $(flags) $(include) return_address_attack.c -o return_address_attack.elf

make clean:
	rm *.s *.elf