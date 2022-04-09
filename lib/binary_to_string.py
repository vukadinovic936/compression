import sys
from bitstring import BitArray
from bitstring import BitStream
from bitstring import ConstBitStream

file_name = sys.argv[1]

#recover from binary
data=BitArray(filename=file_name)
print(len(data.bin))

# write to jada.zen
f = open(file_name, "w")
f.write(data.bin)
f.close()