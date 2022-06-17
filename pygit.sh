AGR2=${2:-py}

git add $1.$AGR2
git commit -m "boj $1"
git push origin master