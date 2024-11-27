# Read from the file file.txt and output all valid phone numbers to stdout.
grep -P "(^[1-9][0-9]{2}-[0-9]{3}-[0-9]{4}$)|(^\([0-9][0-9]{2}\)\s[0-9]{3}-[0-9]{4}$)" file.txt
