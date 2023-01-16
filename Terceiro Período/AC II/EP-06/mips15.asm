.text	
.globl main

main:
#ass: $s0=i, $s1=j
addi $s0,$zero,0 #i=0
addi $s1,$zero,100 #j=100

ori $t0,$zero,0x1001 
sll $t0,$t0,16 #$t0=mem[0]
do:
sll $t1,$s0,1 #$t1=2i
addi $t1,$t1,1 #$t1=2i+1

add $s2,$s2,$t1 #$2+=vetor[i]
sll $t2,$s0,2 #$t2=4i
add $t2,$t0,$t2 #$t2=end base + 4i

sw  $t1,0($t2) #mem[i]=2i+1 ($t1)

addi $s0,$s0,1 #i=i+1
bne $s0,$s1,do #wile(i!=j)

addi $t2,$t2,4 #$t2=$t2+4
sw  $s2,0($t2) #mem[101]=soma