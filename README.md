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
<pre>
In this assignment, you will implement a LLC replacement policy (as discussed in the class) that
prevents cross-core eviction attacks such as evict+reload and prime+probe.
You have to use a trace based cache simulator called ChampSim:
https://github.com/ChampSim/ChampSim

Read the README carefully and make your hands dirty with the ChampSim.
You have to add your replacement policy inside the replacement folder.

This section will provide the task list which needs to be accomplished by you for this
assignment. The task list for this assignment is as follows:

A. [You must be kidding: 2 points] ChampSim does not implement an inclusive LLC. So,
your first goal is to make the LLC inclusive. Once the LLC is inclusive, demystify the
statement: “the back-invalidation hits at the private caches is small” with LRU
replacement policy. Note that LRU replacement policy is already implemented in
ChampSim
(​ https://github.com/ChampSim/ChampSim/blob/master/replacement/lru.llc_repl​ )

B. [Time for the mitigation: 8 points] ​ Implement the LLC replacement policy that
prevents cross-core evictions that result in back-invalidation hits assuming LLC
implements the LRU policy. You can run a simple 2-core setup and you have to show
that your policy prevents the basis of any cross-core eviction based attacks.

C. [Time to move on: 5 points] ​ In ​ Task B, ​ the replacement policy is restricted to LRU
only. Change your code so that it can be applied to any replacement policy. Check the performance loss with your change.

D. [​ Show me something new: 5 points​ ] Enhance your policy so that performance loss will
be minimal.

</pre>
