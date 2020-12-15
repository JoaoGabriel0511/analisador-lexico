.table
int a_sum_VARIABLE
int b_sum_VARIABLE
int c_sum_VARIABLE
int a_main_VARIABLE
.code
jump main
sum:
pop c_sum_VARIABLE
pop b_sum_VARIABLE
pop a_sum_VARIABLE
add $0, b_sum_VARIABLE, a_sum_VARIABLE
add $0, $0, c_sum_VARIABLE
return $0
main:
param 1
param 2
param 3
call sum
pop a_main_VARIABLE
println a_main_VARIABLE
