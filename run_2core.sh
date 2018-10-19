TRACE_DIR=../Traces
binary=${1}
n_warm=${2}
n_sim=${3}
trace1=${4}
trace2=${5}
option=${6}



mkdir -p results_2core

(./bin/${binary} -warmup_instructions ${n_warm}000000 -simulation_instructions ${n_sim}000000 ${option} -traces ${TRACE_DIR}/${trace1}.trace.gz ${TRACE_DIR}/${trace2}.trace.gz) &> results_2core/${trace1}-${trace2}-${binary}${option}.txt
