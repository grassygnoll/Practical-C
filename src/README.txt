# Use the following command to build a given source file
# This builds the output file "outputfile" from source "file.c"
# 
# This specific build command builds with debug symbols, no optimization, all warnings
# DEBUG

gcc -g -O0 -Wall file.c -o ./debug/outputfile

# This specific build command builds for release, no debug, reasonable optimization, all warnings
# RELEASE

gcc -O2 -Wall file.c -o ./release/outputfile


