a) In a Bash shell, run:
make -f Makefile.#
(# corresponds to the part of the project [1,2,3])

b) Test cases are coded into DfaTest.c, NfaTest.c and ConvTest.c
You can change the words being tested by modifying the .c files listed above
Just run the output file from the makefile
That should be dfatest, nfatest, and convtest respectively

c) Timothy Chu & Griffin van de Venne & Vincent Ou

d) We used the sample files from Prof Ferguson

make -f Makefile.1
./dfatest

make -f Makefile.2
./nfatest

make -f Makefile.3
./convtest