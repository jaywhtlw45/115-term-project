import- random

f = open("C:\\users\\jay\\code\\115\\115-term-project\\heapSortBubbleSort\\number_files\\bubble_sort\\onehundredthousand.txt", "w")

number = 100000

# write numbers in ascending order
f.write('1')
for i in range(2, number+1):
    f.write(" ")
    f.write(str(i))
f.write("\n")

# write numbers in descending order
f.write(str(number))
for i in range(number-1, 0, -1):
    f.write(" ")
    f.write(str(i))
f.write("\n")

# write random numbers
random_numbers = random.sample(range(1, number+1), number)
f.write(str(random_numbers[0]))
for i in range(1, number):
    f.write(" ")
    f.write(str(random_numbers[i]))

f.close()
