input1="HELLOWORLD"
input2="LOREMIPSUMDOLORSITAMET"
input3="IWANDEREDLONELYASACLOUD"
input4="ALLTHEWORLDSASTAGE"
input5="CALLMEISHMAELSOMEYEARSAGONEVERMINDHOWLONGPRECISELYHAVINGLITTLEORNOMONEYINMYPURSEANDNOTHINGPARTICULARTOINTERESTMEONSHOREITHOUGHTIWOULDSAILABOUTALITTLEANDSEETHEWATERYPARTOFTHEWORLDITISAWAYIHAVEOFDRIVINGOFFTHESPLEENANDREGULATINGTHECIRCULATIONWHENEVERIFINDMYSELFGROWINGGRIMABOUTTHEMOUTHWHENEVERITISADAMPDRIZZLYNOVEMBERINMYSOULWHENEVERIFINDMYSELFINVOLUNTARILYPAUSINGBEFORECOFFINWAREHOUSESANDBRINGINGUPTHEREAROFEVERYFUNERALIMEETANDESPECIALLYWHENEVERMYHYPOSGETSUCHANUPPERHANDOFMETHATITREQUIRESASTRONGMORALPRINCIPLETOPREVENTMEFROMDELIBERATELYSTEPPINGINTOTHESTREETANDMETHODICALLYKNOCKINGPEOPLESHATSOFFTHENIACCOUNTITHIGHTIMETOGETTOSEAASSOONASICANTHISISMYSUBSTITUTEFORPISTOLANDBALLWITHAPHILOSOPHICALFLOURISHCATOTHROWSHIMSELFUPONHISSWORDIQUIETLYTAKETOTHESHIPTHEREISNOTHINGSURPRISINGINTHISIFTHEYBUTKNEWITALMOSTALLMENINTHEIRDEGREESOMETIMEOROTHERCHERISHVERYNEARLYTHESAMEFEELINGSTOWARDSTHEOCEANWITHME"

output1="XAFFQKQNFZ"
output2="NHERJWDYVJPHNHEYWBQJRB"
output3="HNOVXKPGTUUPDPPCECRSHJL"
output4="FOOIRDZLNXTFDFNQYX"
output5="MDRJFRGEMSZBNPNLZJJYXDVBNQUBMUVYDOSICYTFHIOQZJJVMJTEDEVDPCEZZFCWAPSQKWIBQHWQJBYHIMROINOOHEOLCRYAINQQRPVKBDGLCRFCBKWNKXKQYFEYDCIQXNOCYIGPIYENZEUFBPHVZPQKFCLAMGCCWNAPHEUDXNDPQLKOHJVJCEWFDHPEVYPAZGKKOOQVMALHVVNGABVENZFFOSRZLFTMLUOARFGWCWLRGSYESUJGXQJZBPDFSCOLKXUKJUOWLQBBDRYLEHNCWJWAGLLJDSQGSSDWHJZURVMIKNGQBGTJKGRYMJPFXWDNCURDPYCCALQMGRJEQHLZHHCCKMXDPDMUZDRYVGFKZSVGELYDVVTVXVSNOZPWTOFKIPLWPUHPKFHIJCCQYDNTTZCTSIDOMPLWDWJHKAWLFQVRCQWPASXKQKRQQUADSORSFCIYQHROVDECQXMGZHKOJPLXENQPXCPHKXZWBTFTGMCWMNTCBBQEOKTFGIVQPVFOIIZWQNEHYEOYAAWBXOIQWVVLIQYQFRPJIXBNVZGFWSSFKJTAIINOJDVEIPNKFNFDXLNLAFSTTJKMAIBKGGFLCXEIIHJNKRJBERPGCKIKYKOODWMFIPNQMGWIVQRVRYOHWXAGGAIJEJFCOGRKTMZMXYJQQKMHYYSRXCSXSSGGHEKAFXORYKMFJBGSXLCPGCOPLFNFPOGEXCTPFCDHRVCTSMAZJFJHLPURMOHLXNINQIVSHIBDWCUEKVABWBEIZTXFTCTHQYYPTVOZDLHHJGFJTSPIVYHMXMNKLDKXJRXJEXCNBCRAMKBBCEOBRXIMNOYBKPXYTFSQIFYBZXVUOOXTSIFGPHPMHFUGAYWUHHOKWLOQIVEBOSET"

echo $input1 > input1.txt
echo $input2 > input2.txt
echo $input3 > input3.txt
echo $input4 > input4.txt
echo $input5 > input5.txt

echo "18 10" > startpos3.pos
echo "11 25" > startpos4.pos
echo "5 25 24" > startpos5.pos


echo "case 1)"
output=$(./enigma plugboards/null.pb reflectors/I.rf < input1.txt)
echo "your output is: $output"
if [ $output == $output1 ]
then
        echo "your output is correct!"
else
        echo "your output is incorrect!"
fi
echo ""

echo "case 2)"
output=$(./enigma plugboards/null.pb reflectors/II.rf rotors/shift_up.rot rotors/I.pos < input2.txt)
echo "your output is: $output"
if [ $output == $output2 ]
then
        echo "your output is correct!"
else
        echo "your output is incorrect!"
fi
echo ""

echo "case 3)"
output=$(./enigma plugboards/I.pb reflectors/III.rf rotors/II.rot rotors/I.rot startpos3.pos < input3.txt)
echo "your output is: $output"
if [ $output == $output3 ]
then
        echo "your output is correct!"
else
        echo "your output is incorrect!"
fi
echo ""

echo "case 4)"
output=$(./enigma plugboards/II.pb reflectors/IV.rf rotors/IV.rot rotors/VI.rot startpos4.pos < input4.txt)
echo "your output is: $output"
if [ $output == $output4 ]
then
        echo "your output is correct!"
else
        echo "your output is incorrect!"
fi
echo ""

echo "case 5)"
output=$(./enigma plugboards/III.pb reflectors/V.rf rotors/VI.rot rotors/VII.rot rotors/VIII.rot startpos5.pos < input5.txt)
echo "your output is: $output"
if [ $output == $output5 ]
then
        echo "your output is correct!"
else
        echo "your output is incorrect!"
fi
echo ""

rm input1.txt
rm input2.txt
rm input3.txt
rm input4.txt
rm input5.txt
rm startpos3.pos
rm startpos4.pos
rm startpos5.pos
