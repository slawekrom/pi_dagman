g++ pi_calc.cpp -o pi_calc.o
g++ pi_calc_collect.cpp -o pi_calc_collect.o
python3 create_dags.py $1 $2 $3
condor_submit_dag -f pi_calc.dag