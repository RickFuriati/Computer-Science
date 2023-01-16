#Programa 02
#x = 100000
#y = 200000
#z = x+y

.text
.globl main
main:
#Associações 
# x-> $s0, y-> $s1, z-> $s2
addi $s0, $zero,25000 #x=25000

sll $s0,$s0,2 #x=25000.4
sll $s1,$s0,1 #y=x.2

add $s2, $s0, $s1 #y =x+y 

.data 