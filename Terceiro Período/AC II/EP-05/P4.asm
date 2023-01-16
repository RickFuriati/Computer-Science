#Programa 02
#x = 3
#y = 4 
#z = ( 15*x + 67*y)*4

.text
.globl main
main:
#Associações 
# x-> $s0, y-> $s1, z-> $s2
addi $s0, $zero,3 #x=1
addi $s1, $zero,4 #y=1

add $t0, $zero,$s0
add $t1, $zero,$s1

sll $s0,$s0,4 #x=x.2^4 (x.16)
sub $s0,$s0,$t0 #x=x-t0 (x=(x.16)-x)

sll $s1,$s1,6 #x=x.2^6 (x.64)
add $s1,$s1,$t1
add $s1,$s1,$t1
add $s1,$s1,$t1



add $s2, $s0, $s1 #y =x+y (15*x + 67*y)

add $s2, $s2, $s2 #z=z+z (dobro de z)
add $s2, $s2, $s2 #z=z+z (quadruplo de z)




.data 