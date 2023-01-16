# programa 07
# $8 = 0xFFFFFFFF;

# Associações: 
# $8 -> $t0

.text
.globl main
main:
ori $8, $0, 0x01 #t0=0x0000 0001;
sll $8, $8, 16 	#t0=0x0001 0000;
ori $8, $8, 0xFFFF #t0=0x0001 FFFF;
sll $8, $8, 16 	#t0=0xFFFF 0000;
ori $8, $8, 0xFFFF #t0=0xFFFF FFFF;
