import sys

file = open("pi_calc.dag", "w")
file.write(sys.argv)
count = int(sys.argv[1])
seed = int(sys.argv[3])

for i in range(0, count):
    file.write("JOB job" + str(i) + " pi_calc.sub\n")
    file.write(
        "VARS job"
        + str(i)
        + ' id="'
        + str(i)
        + '" iterations="'
        + sys.argv[2]
        + '" seed="'
        + str(i + seed)
        + '"\n'
    )

file.write("JOB final pi_calc_collect.sub\n")
file.write('VARS final count="' + sys.argv[1] + '"\n')

file.write("PARENT ")
for i in range(0, count):
    file.write("job" + str(i) + " ")
file.write("CHILD final")

file.close()