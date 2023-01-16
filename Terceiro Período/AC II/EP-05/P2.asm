#Programa 02
#x = 1
#y = 5*x + 15

#Associações 
# x-> $s0, y-> $s1
.text
.globl main
main:

addi $s0, $zero,1 #x=1
addi $t0, $zero,15 #t0=15
add $t1, $zero, $s0 #t1=x


add $s0,$s0,$s0 #x=x+x (x=1+1 --> 2)
add $s0,$s0,$s0 #x=x+x (x=2+2 --> 4)
add $s0,$s0,$t1 #x=x+t1  (x=4+1 -->5)

add $s1, $s0, $t0 #y = 5*x + 15





.data 