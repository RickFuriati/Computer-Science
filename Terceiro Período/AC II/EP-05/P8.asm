# programa 08
# $8 = 0x12345678;
# $9 = 0x12;
# $10 = 0x34;
# $11 = 0x56;
# $12 = 0x78;

# Associações: 
#$8 -> $t0, $9 -> $t1, $10 -> $t2, $11 -> $t3 ,$12 -> $t4
.text
.globl main
main:
ori $8, $0, 0x1234 # t0 = 0x0000 1234;
sll $8, $8, 16	# t0 = 0x1234 0000;
ori $8, $8, 0x5678 # t0 = 0x1234 5678;
srl $9, $8, 16	# t1 = 0x0000 1234; 
srl $9, $9, 8	# t1 = 0x0000 0012;
sll $10, $8, 8	# t2 = 0x3456 7800;
srl $10, $10, 16 # t2 = 0x0000 3456;
srl $10, $10, 8	# t2 = 0x0000 0034;
sll $11, $8, 16	# t3 = 0x5678 0000;
srl $11, $11, 16 # t3 = 0x0000 5678;
srl $11, $11, 8	# t3 = 0x0000 0056;
sll $12, $8, 16 # t4 = 0x5678 0000;
sll $12, $12, 8	# t4 = 0x7800 0000;
srl $12, $12, 16 # t4 = 0x0000 7800;
srl $12, $12, 8	# t4 = 0x0000 0078;