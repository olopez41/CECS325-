#include <iostream>
#include <random>
#include <iomanip>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    char choice;
    std::random_device rd {};
    unsigned int seed = rd();
    std::default_random_engine engine {seed};
    std::uniform_int_distribution<int> ZeroToOne{0,1};
    std::uniform_int_distribution<int> onetoThree {1,3};
    int random_player_input;

    int fixed_winning_number=onetoThree(engine);
    int player_choice_changing;
    int iterations;

    std::cout<<"Enter the number of iterations:"<<std::endl;
    std::cin>>iterations;

    // x will be a uniform random integer from 1 to 10.
    //std::cout<<"The winning number is:"<< fixed_winning_number <<std::endl;
    float switch_correct_counter=0;
    float switch_incorrect_counter=0;
    float not_switch_correct_counter=0;
    float not_switch_incorrect_counter=0; //how many times they didnt switch and still lost
    for (int i=1; i<iterations; i++ ) {
        while (true) {
            player_choice_changing=onetoThree(engine);
            random_player_input= ZeroToOne(engine);
            if (random_player_input == 0 ) {
                if (player_choice_changing==fixed_winning_number) {
                    switch_correct_counter++;

//1,3,6,3


                }
                else if (player_choice_changing!=fixed_winning_number) {
                    not_switch_incorrect_counter++;




                    break;
                }
            }
            else if (random_player_input == 1) {
                if (player_choice_changing==fixed_winning_number) {
                    not_switch_correct_counter++;
                    break;

                }
                else if (player_choice_changing!=fixed_winning_number) {
                    switch_incorrect_counter++;

                }
            }

        }

    }


    float wins_not_switch =not_switch_correct_counter/iterations;
    float losses_not_switch= not_switch_incorrect_counter/iterations;
    float wins_switchting= switch_correct_counter/iterations;
    float losses_switching= switch_incorrect_counter/iterations;



std::cout<<"not switching correct counter: "<<not_switch_correct_counter<<std::endl;
    std::cout<<"not switching incorrect counter: "<<not_switch_incorrect_counter<<std::endl;
    std::cout<<"switching correct counter: "<<switch_correct_counter<<std::endl;
    std::cout<<"switching incorrect counter: "<<switch_incorrect_counter<<std::endl;

    std::cout<<""<<std::setprecision(2)<<wins_not_switch<< " " << losses_not_switch<<wins_switchting<<losses_switching<<std::endl;//sets the percisions
    std::cout<<""<<"wins not switching: "<< std::setprecision(2)<<" " << wins_not_switch<<std::endl;
    std::cout<<""<<"losses not switching: "<< std::setprecision(2)<<" " << losses_not_switch<<std::endl;
    std:: cout<<""<<"wins with switching:"<< std::setprecision(2)<< " " <<wins_switchting<<std::endl;
    std::cout<<""<<"losses with switching:"<<std::setprecision(2)<<" "  <<losses_switching<<std::endl;


return 0;
}



// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.