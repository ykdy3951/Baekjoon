AGR2=${2:-sv}

git add $1.$AGR2
git commit -m "boj $1 by systemverilog"
git push -u origin main