rm *.o
rm *.class
rm *.pyc
find . -type f -print0 | xargs -0 file -N0 -- | perl -nlwe '/(.*\0).*ELF.*executable/ and printf $1' | xargs -0 rm --
