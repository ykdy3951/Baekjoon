file=$1
boj_number=`echo $file | cut -d '.' -f1`
extension=`echo $file | cut -d '.' -f2`

if [ $extension = "cc" ] || [ $extension = "cpp" ]; then
    ./mkfile_cpp.sh $boj_number
elif [ $extension = "py" ]; then
    ./mkfile_py.sh $boj_number
elif [ $extension = "sv" ]; then
    ./mkfile_sv.sh $boj_number
else
    touch $file
fi