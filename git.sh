file=$1
boj_number=`echo $file | cut -d '.' -f1`
extension=`echo $file | cut -d '.' -f2`

git add $file
git commit -m "boj $boj_number using $extension"
git push -u origin main