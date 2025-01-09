#include <iostream>
#include <string>
#include "text.hpp"

/*
This main show the potencial usage of my library
*/

int main(){
    /**
     * \creating object with parametric contructror 
     * 
     * \we have to put the name of the txt file that we want to work with
     * 
     * \the file that we are going to work with has to be in the same file as the project is
    */
    mf::TextHandler text2("2.txt");         
    text2.read_text();                  //shows text in terminal
    text2.count_lines();                //counts number of lines
    text2.count_words();                //counts number of words (numbers count)
    text2.count_characters();           //counts the number of characters (space counts)
    text2.count_letters();              //counts the number of letter (numbers doesn't count)
    text2.freq_of_words();              //shows words that repeats and number of repetitions
    /**
     * zmniejsza ilosc spacji do jednej pomiedzy slowami oraz usuwa spacje na poczatku i na koncu linijek
     */
    text2.space_repair();
    /**
     * \this operator gives as possibility to add text in a new line
     * 
     * by this operator we can even make a new text file because if we create an object
     * with a file that doesnt't exist and we use this operator program will create file
     * and put the line we wrote in it
     */
    text2+="Now this text looks great!!!";
    text2.read_text();
    return 0;

}