#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]){

    ifstream file(argv[1]); //opens file stored in argv for reading
    string init_line = "";
    string line = "";
    string new_line = "";
    int leng = 0;
    int new_leng = 0;
    int num_nucs = 0; //number of nuceleotides
    int num_lines = 0; //number of lines
    int a_count = 0, t_count = 0, g_count = 0, c_count = 0;
    int aa_count = 0, at_count = 0, ag_count = 0, ac_count = 0;
    int tt_count = 0, ta_count = 0, tg_count = 0, tc_count = 0;
    int gg_count = 0, ga_count = 0, gt_count = 0, gc_count = 0;
    int cc_count = 0, ca_count = 0, ct_count = 0, cg_count = 0;
    int even_odd; // 1 = odd, 0 = even
    float sum = 0.0, mean = 0.0, var = 0.0, sd = 0.0;


    while(getline(file, init_line)){ //iterates through each line of the file

        leng = init_line.length();
        line = "";

        for(int i = 0; i < leng; i++){ //for loop to iterate through string and lowercase

            init_line[i] = tolower(init_line[i]);

            if(init_line[i] == 'a' || init_line[i] == 't' || init_line[i] == 'g' || init_line[i] == 'c'){ //adds only nucleotide letters to new string

                line += init_line[i];

            }
        }

        new_leng = line.length();

        sum += new_leng; //add the sum of the length of each line
        num_lines++; //increase number of lines count per interation

        for(int i = 0; i < new_leng; i++){ //for loop to iterate through string and read letters

            even_odd == i % 2;
            if(even_odd == 0){ //index is even
                cout<<line[i]<<endl;

                if(line[i] == 'a'){ //first
                    a_count++;
                    num_nucs++;
                    cout<<"in a counter"<<endl;

                    //when when an even number the dimer is checked and added to the count
                    if(line[i + 1] == 'a'){
                        aa_count++;

                    }

                    else if(line[i + 1] == 't'){
                        at_count++;
                    }

                    else if(line[i + 1] == 'g'){
                        ag_count++;

                    }

                    else if(line[i + 1] == 'c'){
                        ac_count++;

                    }
                }

                else if(line[i] == 't'){ //first
                    t_count++;
                    num_nucs++;

                    if(line[i + 1] == 'a'){
                        ta_count++;

                    }

                    else if(line[i + 1] == 't'){
                        tt_count++;
                    }

                    else if(line[i + 1] == 'g'){
                        tg_count++;

                    }

                    else if(line[i + 1] == 'c'){
                        tc_count++;

                    }
                }

                else if(line[i] == 'g'){ //first
                    g_count++;
                    num_nucs++;

                    if(line[i + 1] == 'a'){
                        ga_count++;

                    }

                    else if(line[i + 1] == 't'){
                        gt_count++;
                    }

                    else if(line[i + 1] == 'g'){
                        gg_count++;

                    }

                    else if(line[i + 1] == 'c'){
                        gc_count++;

                    }
                }

                else if(line[i] == 'c'){ //first
                    c_count++;
                    num_nucs++;

                    if(line[i + 1] == 'a'){
                        ca_count++;

                    }

                    else if(line[i + 1] == 't'){
                        ct_count++;
                    }

                    else if(line[i + 1] == 'g'){
                        cg_count++;

                    }

                    else if(line[i + 1] == 'c'){
                        cc_count++;

                    }
                }
            }

            else{
                cout<<line[i]<<endl;
                if(line[i] == 'a'){ //first
                    a_count++;
                    num_nucs++;
                }

                else if(line[i] == 't'){ //first
                    t_count++;
                    num_nucs++;
                }

                else if(line[i] == 'g'){ //first
                    g_count++;
                    num_nucs++;
                }

                else if(line[i] == 'c'){ //first
                    c_count++;
                    num_nucs++;
                }
            }
        }
    }

            //mean num of nucleotides/num of lines lines
            mean = num_nucs/num_lines;

            file.close();//close

            ifstream file1(argv[1]);//then reopen to calculate sd and var

            float sd_num = 0;

            while(getline(file1, init_line)){ //iterates through each line of the file

                leng = init_line.length();

                for(int i = 0; i < leng; i++){ //for loop to iterate through string and lowercase

                    init_line[i] = tolower(init_line[i]);

                    if(init_line[i] == 'a' || init_line[i] == 't' || init_line[i] == 'g' || init_line[i] == 'c'){
                        line += init_line[i];
                    }
                }

            }
                new_leng = new_line.length();
                sd_num += ((new_leng-mean)*(new_leng-mean));

    file1.close(); //close file when done

    //Calculations
    //sum = num_nucs

    //var
    var = (sd_num/(num_lines-1));

    //sd
    sd = sqrt(var);

    //probabilities
    int a_prob = a_count/num_nucs;
    cout<<a_prob<<endl;
    int t_prob = t_count/num_nucs;
    int g_prob = g_count/num_nucs;
    int c_prob = c_count/num_nucs;
    int aa_prob = aa_count/(num_nucs/2);
    int at_prob = at_count/(num_nucs/2);
    int ag_prob = ag_count/(num_nucs/2);
    int ac_prob = ac_count/(num_nucs/2);
    int tt_prob = tt_count/(num_nucs/2);
    int ta_prob = ta_count/(num_nucs/2);
    int tc_prob = tc_count/(num_nucs/2);
    int tg_prob = tg_count/(num_nucs/2);
    int cc_prob = cc_count/(num_nucs/2);
    int ca_prob = ca_count/(num_nucs/2);
    int ct_prob = ct_count/(num_nucs/2);
    int cg_prob = cg_count/(num_nucs/2);
    int gg_prob = gg_count/(num_nucs/2);
    int ga_prob = ga_count/(num_nucs/2);
    int gt_prob = gt_count/(num_nucs/2);
    int gc_prob = gc_count/(num_nucs/2);

    ofstream outfile("jacobbaker.out"); //creates new file yourname.out

    outfile << "Jacob Baker" << endl;
    outfile << "22279125" << endl;
    outfile << "baker210@mail.chapman.edu" << endl;
    outfile << "CPSC-350-02\n" << endl;

    outfile << "Sum of nucleotides: " << num_nucs << endl;
    outfile << "Mean: " << mean << endl;
    outfile << "Variance: " << var << endl;
    outfile << "Standard Deviation: " << sd << endl;
    outfile << "Probability of A: " << a_prob << endl; //prints Probability of A to text file
    outfile << "Probability of T: " << t_prob << endl;
    outfile << "Probability of C: " << c_prob << endl;
    outfile << "Probability of G: " << g_prob << endl;
    outfile << "Probability of AA: " << aa_prob << endl;
    outfile << "Probability of AT: " << at_prob << endl;
    outfile << "Probability of AC: " << ac_prob << endl;
    outfile << "Probability of AG: " << ag_prob << endl;
    outfile << "Probability of TT: " << tt_prob << endl;
    outfile << "Probability of TA: " << ta_prob << endl;
    outfile << "Probability of TC: " << tc_prob << endl;
    outfile << "Probability of TG: " << tg_prob << endl;
    outfile << "Probability of CC: " << cc_prob << endl;
    outfile << "Probability of CA: " << ca_prob << endl;
    outfile << "Probability of CT: " << ct_prob << endl;
    outfile << "Probability of CG: " << cg_prob << endl;
    outfile << "Probability of GG: " << gg_prob << endl;
    outfile << "Probability of GA: " << ga_prob << endl;
    outfile << "Probability of GT: " << gt_prob << endl;
    outfile << "Probability of GC: " << gc_prob << endl;

    return 0;

}
