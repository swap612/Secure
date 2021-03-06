#!/bin/sh
# Applying Patch for PA2-PartC
#1. Make sure to keep the freshly extracted copy of ChampSim in ChampSource dir

echo "*********************************************"
echo "Apply PA2_C Patch file"
echo "NOTE: Make sure to keep the freshly extracted copy of ChampSim and delete the other files generated by previous patch"
echo "Please make sure that you have set the following Environment VAriables "
echo "1. Set ChampSource to champsim folder"
echo "2. Set PatchFiles to PatchFiles folder"
echo "3. Set TraceFiles to TraceFiles folder"
echo "*********************************************"

echo "If All the above variables are set. Press any key"
read opt
echo $opt

cd $ChampSource
echo "Printing Champsim Dir"
pwd

#copy Trace Files to Prent Dir of
cd ..
cp -r $PatchFiles/* .
echo "-------"
echo "Copied Patch Files "

cd $ChampSource
#applying patch
patch -p1 < ../PA2_C.patch
echo "-------"
echo "Applied Patch C "

#changing the permissions of the run script files
chmod +x run_champsim.sh
chmod +x run_2core.sh
chmod +x run_4core.sh

# Go to parent dir
cd ..
# Creating a folder to store the traces
mkdir Traces
cd Traces
pwd
cp -r $TraceFiles/* .
echo "-------"
echo "Copied Trace Files "
echo "-------"
echo "Done!! Now build and run the PA2_C part"
