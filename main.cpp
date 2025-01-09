#include <iostream>
#include <string>
#include "text.hpp"

/**
 * \This file is example of terminal apllication
 * 
 * \It shows us the potential of making bigger apllication with my library
 */

int main(){
    
    int option;
    std::string file;
    std::cout << "Type file name:" << std::endl;
    std::cin >> file;

    std::cout << "What do you want to do with your text?" << std::endl;
    std::cout << "Choose option (analyze - 1; repair - 2; write: 'ale super' in new line - 3):" << std::endl;
    std::cin >> option;
    
    mf::TextHandler text(file);

    switch (option){
        case 1:
            if(!text.is_opened()){
                return 1;
            }
            text.read_text();
            text.count_lines();
            text.count_words();
            text.count_characters();
            text.count_letters();
            text.freq_of_words();
            break;
        case 2:
            if(!text.is_opened()){
                return 1;
            }
            text.space_repair();
            std::cout << "Repaired text: " << std::endl;
            text.read_text();
            break;
        case 3:
            if(!text.is_opened()){
                return 1;
            }
            text+="ale super";
            break;
        default:
            std::cout << "Wrong command" << std::endl;
    }    

    return 0;
}