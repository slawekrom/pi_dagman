g++ pi_estimation.cpp -o pi_estimation.o
g++ pi_estimation_aggregation.cpp -o pi_estimation_aggregation.o
python3 generate_dag.py $1 $2 $3
condor_submit_dag -f pi_estimation.dag