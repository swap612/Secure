---------------------------------------------------
NOTE: Keep the traces in folder Traces in parent direct
How to apply Patch: PA2_A.patch
1. Goto the one directory up of Champsim. for ex: if your Chamsim dir is "/home/swapnil/Secure/ChampSim-master" 
	cd "/home/swapnil/Secure/".
	mkdir Traces //copy the traces in folder "Traces"

2. copy the patch file PA2_A.patch in this folder.

3. goto Chamsim folder
	cd ChampSim-master
	
3. Run patch file. It will displaying patching files. 4 files should be patched. 
	patch -p1 < '../PA2_A.patch'
 
4. If permission denied error shows, give permissions +x to run ./run_champsim.sh
	chmod +x ./run_champsim.sh

Now, build the project using 
	./build_champsim.sh bimodal no no lru 1
To run,
	./run_champsim.sh bimodal-no-no-lru-1core 1 10 trace-3
	
---------------------------------------------------
