echo -e "\ns\nt\na\nr\nt\n"

./ig-sw test_data/SRR1383448_collapse-unique_atleast-2.fastq test_data/useless.sam -p test_data/ -m 1 -u 1 -o 7 -e 1 -d 0
./toletter >> truncated_seqs.fa
exonerate --model affine:local --exhaustive yes -s 50 --showcigar true truncated_seqs.fa ighd.fa >> 50_threshold.txt
echo 50_threshold.txt | ./parseoutput >> final_file3_switched.txt
