# Read from the file file.txt and print its transposed content to stdout.
awk '{
    for(i=1; i<=NF; i++){
        if(NR==1){
            result[i]=$i
        }else{
            result[i]=result[i] " " $i
        }
    }
}
END{
    for (i=1; i<=NF; i++){
        print result[i]
    }
}' file.txt

# seq 1 $(head -1 file.txt | wc -w) | xargs -I '{}' bash -c "cut -d '"' '"' -f {} file.txt| xargs"
