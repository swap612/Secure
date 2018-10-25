#!/bin/sh
# Applying Patch for PA2-PartA
#1. Make sure to keep the freshly extracted copy of ChampSim in ChampSource dir
#2. Keep traces in  parent folder of Champsim Dir

# echo $ChampSource
# echo $PatchFiles
# echo $TraceFiles

echo "*********************************************"
echo "Apply PA2_A Patch file"
echo "NOTE: Please make sure that you have set the following Environment VAriables "
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
patch -p1 < ../PA2_A.patch
echo "-------"
echo "Applied Patch A "

    #changing the permissions of the run script files
    chmod +x run_champsim.sh

# Go to parent dir
cd ..
# Creating a folder to store the traces
mkdir Traces
cd Traces
pwd
cp -r $TraceFiles/* . 
echo "-------"
echo "Copied Trace Files " 

echo "Done!! Now build and run the PA2_A part"
