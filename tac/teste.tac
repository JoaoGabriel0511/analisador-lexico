.table
float i_main_VARIABLE
.code
jump main
main:
inttofl $7, 1
mov i_main_VARIABLE, $7
println i_main_VARIABLE
