echo -e "\nstart 10,000\n"

./ig-sw test_data/200_lines.fastq test_data/useless.sam -p test_data/ -m 1 -u 1 -o 7 -e 1 -d 0
./toletter >> truncated_seqs.fa
exonerate --model affine:local --exhaustive yes -s 35 --showcigar true ighd.fa truncated_seqs.fa >> 35_threshold.txt
echo 35_threshold.txt | ./parseoutput >> final_200.txt
