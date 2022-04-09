import sys
from bitstring import BitArray

file_name = sys.argv[1]
# read file
text_file = open(file_name, "r") 
data = text_file.read() 
text_file.close()

# write to binary
binary_file = open(file_name,'wb')
b = BitArray(bin=data)
b.tofile(binary_file)
binary_file.close()