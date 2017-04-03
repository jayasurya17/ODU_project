from __future__ import print_function
import sys
file_data = open(sys.argv[1],"r").read() #opens input file for reading which is given as the first argument in command line
output_file = open(sys.argv[2],"w") #opens input file for writing which is given as the first argument in command line
flag = 0 #flag is used to keep track if the word "foo" has been encountered
position = 0 #position is used to keep track of the file pointer position
#The following for loop reads the whole file char by char and any occurance of "foo" is replaced by "bar"
for char in file_data:
    output_file.write(char)
    if char == '"' and flag == 0:
        flag+=1
    elif char == 'f' and flag == 1:
        flag+=1
    elif char == 'o' and flag == 2:
        flag+=1
    elif char == 'o' and flag == 3:
        flag+=1
    elif char == '"' and flag == 4:
        output_file.seek(position-4) #file pointer is moved 4 positions behind to write the word "bar"
        output_file.write("\"bar\"") #"bar" is written onto the file
    else:
        flag = 0
    position+=1
output_file.close()
print(open(sys.argv[2],"r").read(),end="") #output file is opened in read mode and the content is displayed
