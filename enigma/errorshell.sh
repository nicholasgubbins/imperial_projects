echo "case 1)"
./enigma plugboards/null.pb > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 1 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 2)"
echo "HELLOwORLD" > test.txt
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 2 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 3)"
echo "HELLOWORLD" > test.txt
echo "4 10 12 5 11 6 3 16 21 25 13 19 14 22 24 7 23 20 18 15 0 81 1 17 2 9 17" > rotor1.rot
./enigma plugboards/I.pb reflectors/I.rf rotor1.rot rotors/II.rot rotors/III.rot rotors/I.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 3 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 4)"
echo "HELLOWORLD" > test.txt
echo "4 10 12 5 11x 6 3 16 21 25 13 19 14 22 24 7 23 20 18 15 0 81 1 17 2 9 17" > rotor1.rot
./enigma plugboards/I.pb reflectors/I.rf rotor1.rot rotors/II.rot rotors/III.rot rotors/I.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 4 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 5)"
echo "HELLOWORLD" > test.txt
echo "1 5 5 3" > pb1.pb
./enigma pb1.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 5 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 6)"
echo "HELLOWORLD" > test.txt
echo "1 5 3" > pb1.pb
./enigma pb1.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 6 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 7)"
echo "HELLOWORLD" > test.txt
echo "4 4 12 5 11 6 3 16 21 25 13 19 14 22 24 7 23 20 18 15 0 8 1 17 2 9 17" > rotor1.rot
./enigma plugboards/I.pb reflectors/I.rf rotor1.rot rotors/II.rot rotors/III.rot rotors/I.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 7 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 8)"
echo "HELLOWORLD" > test.txt
echo "1 2" > pos1.pos
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot pos1.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 8 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 9)"
echo "HELLOWORLD" > test.txt
echo "0 0 1 9 2 12 3 25 5 11 6 24 7 23 8 21 10 22 13 17 14 16 15 20 18 19" > ref1.rf
./enigma plugboards/I.pb ref1.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 9 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 10)"
echo "HELLOWORLD" > test.txt
echo "1 2" > ref1.rf
./enigma plugboards/I.pb ref1.rf rotors/I.rot rotors/II.rot rotors/III.rot rotors/I.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 10 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


echo "case 11)"
echo "HELLOWORLD" > test.txt
./enigma plugboards/I.pb reflectors/I.rf rotors/I.rot rotors/II.rot rotors/III.rot steffen.pos < test.txt > output.txt 2> error.txt
exitstat=$?
output=$(cat output.txt)
error=$(cat error.txt)
echo "exit status: $exitstat"
echo "stdout: $output"
echo "stderr: $error"
if [ $exitstat == 11 ]
then
        echo "not wrong (possibly correct)"
else
        echo "absolutely wrong"
fi
echo ""


rm error.txt output.txt test.txt
rm *.rf *.pos *.rot *.pb
