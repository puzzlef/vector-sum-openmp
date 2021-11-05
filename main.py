# https://www.kaggle.com/wolfram77/puzzlef-multiply-openmp-adjust-schedule
import os
from IPython.display import FileLink
src="multiply-openmp-adjust-schedule"
out="{}.txt".format(src)
!printf "" > "$out"
display(FileLink(out))
!echo ""

# Download program
!rm -rf $src
!git clone https://github.com/puzzlef/$src
!echo ""

# Run
!g++ -O3 $src/main.cxx
!ulimit -s unlimited && stdbuf --output=L ./a.out 2>&1 | tee -a "$out"
