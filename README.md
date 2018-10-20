# Secure
Build :<br> ./build_champsim.sh bimodal no no lru 1
<br>

run: <br>
Using script file:<br>
./run_champsim.sh bimodal-no-no-lru-1core 1 10 trace-3
<br>
Directly running the binary<br>
./bin/bimodal-no-no-lru-1core -warmup_instructions 100000 -simulation_instructions 1000000 -traces ./champsim.trace.gz
<br>
