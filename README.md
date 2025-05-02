## Tests used to run CFI 
command to run with CFI: 
`riscv-unknowen-elf-gcc -Wall -g -O2 -march=rv64gc_zicfilp_zicfiss -fcf-protection=full -mabi=lp64d -static`
Note: you need both `-fcf-protection=full` and `-static` to run CFI.
