.table
int i_main_VARIABLE[] = {0, 0}
int j_main_VARIABLE[] = {0, 0}
int h_main_VARIABLE[] = {0, 0}
.code
jump main
main:
mov $2, &i_main_VARIABLE
mov $2[0], 12
mov $2[1], 24
mov $2, &j_main_VARIABLE
mov $2[0], 1
mov $2[1], 2
mov $6, &j_main_VARIABLE
mov $2, $6[0]
mov $3, $6[1]
mov $6, &i_main_VARIABLE
mov $4, $6[0]
mov $5, $6[1]
add $0, $2, $4
add $1, $3, $5
mov $2, &h_main_VARIABLE
mov $2[0], $0
mov $2[1], $1
mov $2, &h_main_VARIABLE
mov $2, $2[0]
print '<'
print $2
print ','
mov $2, &h_main_VARIABLE
mov $2, $2[1]
print $2
print '>'
println
