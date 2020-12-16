.table
int a_sum_VARIABLE
int b_sum_VARIABLE
int i_main_VARIABLE
.code
jump main
sum:
pop b_sum_VARIABLE
pop a_sum_VARIABLE
add $0, b_sum_VARIABLE, a_sum_VARIABLE
return $0
main:
param 2
param 2
call sum
pop $0
param 2
param 2
call sum
pop $1
add $0, $0, $1
mov i_main_VARIABLE, $0
param 2
param 2
call sum
param 2
param 2
call sum
