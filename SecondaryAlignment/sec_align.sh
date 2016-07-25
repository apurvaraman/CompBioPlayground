echo -e "\ns\nt\na\nr\nt\n"

./ig-sw test_data/SRR1383326_collapse-unique_atleast-2.fastq test_data/useless.sam -p test_data/ -m 1 -u 1 -o 7 -e 1 -d 0
./toletter >> truncated_seqs.fa
exonerate --model affine:local --exhaustive yes -s 25 --showcigar true ighd.fa truncated_seqs.fa >> 25_threshold.txt
echo 25_threshold.txt | ./parseoutput >> final_25.txt
