import subprocess
from subprocess import run
import time
import os, sys

def run_sort(filename, filepath, appname):
    # subprocess.call(['g++', filename])
    os.system("g++ " + filename + " -o " + filepath)
    subprocess.call(filepath)
    print("Waiting 3 seconds to run next sort...")
    time.sleep(3)

run_sort('./countSortRadixSort/countSort/countSort.cpp', 
         './countSortRadixSort/countSort/countSort',
         'countSort')
# run_sort('./countSortRadixSort/radixSort/radixSort')

