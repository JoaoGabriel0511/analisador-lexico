.table
int i_main_VARIABLE[] = {0, 0}
.code
jump main
main:
mov $2, 1
mov $3, 2
mov $4, 3
mov $5, 4
mul $0, $2, $4
mul $1, $3, $5
mov $2, $0
mov $3, $1
mov $4, 12
mov $5, 24
add $0, $2, $4
add $1, $3, $5
mov $2, &i_main_VARIABLE
mov $2[0], $0
mov $2[1], $1
mov $2, &i_main_VARIABLE
mov $2, $2[0]
print '<'
print $2
print ','
mov $2, &i_main_VARIABLE
mov $2, $2[1]
print $2
print '>'
println
