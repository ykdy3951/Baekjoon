file=$1
extension=`echo $file | cut -d '.' -f2`

# cpp file
if [ $extension = "cpp" ] || [ $extension = "cc" ]; then
    g++ $file -o Main -O2 -Wall -lm -static -std=gnu++17 -DONLINE_JUDGE -DBOJ && ./Main && Main
# c file
elif [ $extension = "c" ]; then
    gcc $file -o Main -O2 -Wall -lm -static -std=gnu11 -DONLINE_JUDGE -DBOJ && ./Main && rm Main
# python file
elif [ $extension = "py" ]; then
    python -W ignore -c "import py_compile; pycompile.compile(r'$file')" && python3 -W ignore $file
# sv file
elif [ $extension = "sv" ]; then
    iverilog -g2012 -o Main $file && vvp Main && rm Main
fi
