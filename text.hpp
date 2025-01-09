#include <iostream>
#include <string>
#include <filesystem>
#include <fstream>
#include <map>
#include <cctype>
#include <sstream>

namespace mf{

    class TextHandler {
        private:
            std::string m_file_name;
            std::ifstream m_file;
        public:
            TextHandler(){
                m_file_name = "unknown";
            }
            TextHandler(const std::string f) : m_file_name(f){
                m_file.open(m_file_name);
            }

            bool is_opened(){
                return m_file.is_open();
            }

            void read_text(){
                std::string line;
                while (std::getline(m_file, line)){
                    std::cout << line << std::endl;
                }
                m_file.clear();
                m_file.seekg(0);
            }

            void count_lines(){
                std::string line;
                int n{};
                while (std::getline(m_file, line)){
                        n++;
                }
                std::cout << "The number of lines: " << n << std::endl;
                m_file.clear();
                m_file.seekg(0);
            }

            void count_words(){
                std::string line;
                int n{};
                bool word;
                while (std::getline(m_file, line)){
                    if(line[0]==' '){
                        word = 0;
                    }
                    else{
                        word = 1;
                    }
                    for(int k=0;k<line.size();k++){
                        if(line[k]==' ' && word==1){
                            n++;
                            word = 0;
                        }
                        else if(line[k]!=' ' && word==0){
                            word = 1;
                        }
                    }
                    if(line.empty()==0 && line.find(' ')==std::string::npos){
                        n++;
                    }
                    if(line.find(' ')!=std::string::npos && line[line.size()-1]!=' '){
                        n++;
                    }
                }
                std::cout << "The number of words: " << n << std::endl;
                m_file.clear();
                m_file.seekg(0);
            }

            void count_characters(){
                std::string line;
                int n{};
                while (std::getline(m_file, line)){
                    n+=line.size();
                }
                std::cout << "The number of characters: " << n << std::endl;
                m_file.clear();
                m_file.seekg(0);
            }

            void count_letters(){
                std::string line;
                int n{};
                while (std::getline(m_file, line)){
                    for(int k=0;k<line.size();k++){
                        if((line[k]>='a' && line[k]<='z')||(line[k]>='A' && line[k]<='Z')){
                            n++;
                        }
                    }
                }
                std::cout << "The number of letters: " << n << std::endl;
                m_file.clear();
                m_file.seekg(0);
            }

            void freq_of_words(){
                std::map<std::string, int> list;
                std::string line;
                bool word;
                std::string present_word;
                while (std::getline(m_file, line)){
                    for(int n=0;n<line.size();n++){
                        line[n] = std::tolower(line[n]);
                    }
                    for(int n=0;n<line.size();n++){
                        if(line[n]>='a' && line[n]<='z'){
                            word = 1;
                        }
                        else{
                            word = 0;
                        }
                        if(word){
                            present_word+=line[n];
                        }
                        if(!present_word.empty() && !word){
                            list[present_word]++;
                            present_word.clear();
                        }
                    }
                    if(!present_word.empty()){
                            list[present_word]++;
                            present_word.clear();
                        }
                }
                std::cout << "Frequency of words(shows only words that repeat):" << std::endl;
                for(auto pair : list){
                    if(pair.second>1){
                        std::cout << pair.first << " - " << pair.second << std::endl;
                    }
                }
                m_file.clear();
                m_file.seekg(0);
            }

            void space_repair(){
                std::string line;
                std::ostringstream buffer;
                while (std::getline(m_file, line)){
                    while (!line.empty() && line.front() == ' '){
                        line.erase(0, 1);
                    }
                    while (!line.empty() && line.back() == ' '){
                        line.erase(line.size() - 1, 1);
                    }
                    for(int n=0;n<line.size();){
                        if(line[n]==' ' && line[n-1]==' '){
                            line.erase(n,1);
                        }
                        else{
                            n++;
                        }
                    }
                    buffer << line << std::endl;
                }
                if (m_file.is_open()) {
                    m_file.close();
                }
                std::ofstream output_file(m_file_name, std::ios::trunc);
                output_file << buffer.str();
                output_file.close();
                this->m_file.open(m_file_name);
                m_file.clear();
                m_file.seekg(0);
            }

            TextHandler& operator += (const std::string& y){
                if (m_file.is_open()) {
                    m_file.close();
                }
                std::ofstream output_file(m_file_name, std::ios::app);
                output_file << std::endl;
                output_file << y;
                output_file.close();
                this->m_file.open(m_file_name);
                m_file.clear();
                m_file.seekg(0);
                return *this;
            }

            void setFile(std::string f){
                if (m_file.is_open()) {
                    m_file.close();
                }   
                m_file_name = f;
                m_file.open(m_file_name);
                if(!m_file.is_open()){
                    throw std::runtime_error("Can't open file"); 
                }
            }

            std::string getFile(){
                return m_file_name;
            }

            ~TextHandler() {
                if (m_file.is_open()) {
                    m_file.close();
                }
            }
    };
}
