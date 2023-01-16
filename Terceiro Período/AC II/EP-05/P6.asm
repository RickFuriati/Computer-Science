#Programa 06
#x = maior inteiro
#y = 400000
#z = x-4y

.text
.globl main
main:
#Associações 
# x-> $s0, y-> $s1, z-> $s2

addi $s1, $zero,25000 #x=25000
sll $s1,$s1,2 #x=100000
add $t0,$s1,$zero #t0=100000
add $s1,$s1, $t0 #x=200000
add $s1,$s1, $t0 #x=300000


addi $s0, $zero,0x7FFF 
sll $s0,$s0,16 
ori $s0,$s0,0xFFFF

sll $s1,$s1,2 #y=4y

sub $s2, $s0, $s1 #y =x-4y 

.data 