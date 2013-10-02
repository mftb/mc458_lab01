#!/bin/bash
echo "====== Inconsistências encontradas pelo lint.sh======"

FILES="$*"

# Use correct " 
egrep -n -i '"' $FILES

# Use desempenho instead of performance
egrep -n -i 'performance' $FILES

# Use projeto instead of design
egrep -n -i 'design' $FILES

# Use add this number 
egrep -n -i 'NEEDNUM' $FILES

# No double dash
egrep -n -i ' -- ' $FILES

# Use disable
egrep -n -i 'decomission' $FILES

# Use writeback
egrep -n -i 'write-back' $FILES

# Use data-race 
egrep -n -i 'datarace' $FILES
egrep -n -i 'data race' $FILES
egrep -n -i 'data\nrace' $FILES

# Use multi-variable
egrep -n -i 'multivari' $FILES

# Use malloc-coloring
egrep -n -i 'malloc\s*col' $FILES

# Use nondetermin(ism,istic)
egrep -n -i 'non-det' $FILES

# Use multithread(ed,ing)
egrep -n -i 'multi-thr' $FILES

# Use shared-memory
egrep -n -i 'shared\s*memory' $FILES

# Use false-sharing
egrep -n -i 'false\s*shar' $FILES

# Use data-flow
egrep -n -i 'data\s*flow' $FILES

# Use (may,must)-alias
egrep -n -i '(may|must)\s*alias' $FILES

# Use runtime
egrep -n -i '\brun-time\b' $FILES | egrep -v 'sec:runtime'

# Use Section~\ref
# Use Figure~\ref
egrep -n '\bsection~\\ref' $FILES
egrep -n '\bfigure~\\ref' $FILES

# Use \st
egrep -n '\bMOT\b' $FILES | egrep -v '(^[0-9]+:\s*%|newcommand)'

# Use \nodice
egrep -n -i '(^|[^\])\bnodice\b' $FILES | egrep -v '(^[0-9]+:\s*%|newcommand)'

# Use $T_i$
egrep -n "\$t(\b|'|_)" $FILES
egrep -n "\$T'" $FILES

echo "========================================================================"

exit 0
