import sys

file = open('pi_estimation.dag', 'w')
count = int(sys.argv[1])
seed_shift = int(sys.argv[3])

for i in range(0, count):
    file.write('JOB job' + str(i) + ' pi_estimation.sub\n')
    file.write('VARS job' + str(i) + ' id=\"' + str(i) + '\" iterations=\"' + sys.argv[2] + '\" seed=\"' + str(i + seed_shift) + '\"\n')

file.write('JOB final pi_estimation_aggregation.sub\n')
file.write('VARS final count=\"' + sys.argv[1] + '\"\n')

file.write('PARENT ')
for i in range(0, count):
    file.write('job' + str(i) + ' ')
file.write('CHILD final')

file.close()