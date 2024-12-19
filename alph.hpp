/*
 * Copyright (c) ghgltggamer 2024
 * Written by ghgltggamer
 * SCxx Alph - Simple Cxx Alphabet Datatype
 * An easy to use std::string alternative for C++
 * Licensed under the MIT License
 * Checkout the docs for more information
*/

#ifndef ALPH
#define ALPH 132823 // SCxx Unique integers for differentiation

const unsigned long long alph_unidef = -1;
typedef unsigned long long size_p;

class alph {
    private:
        char *gvalue; // the value of alph will be stored here
        int glen; // Global length for alph
    public:
        alph(char str[]) {
            int len = 0;
            for (int &i = len;str[i] != '\0';i++);
            glen = len;
            gvalue = new char[len];
            for (int i = 0;i != len;i++){
                gvalue[i] = str[i];
            }
            gvalue[len] = '\0';
        }
        int length(){
            return glen;
        }

        const char *value(char alpha[] = "\0"){
            if (alpha[0] != '\0'){
                int len = 0;
                for (int &i = len;alpha[i] != '\0';i++){
                    // std::cout<<"len: "<<len<<"\n";
                }
                delete[] gvalue;
                glen = len;
                gvalue = new char[len];
                for (int i = 0;i != len;i++){
                    gvalue[i] = alpha[i];
                }
                gvalue[len] = '\0';
            }
            return gvalue;
        }
        int find(char str[], size_p position = 0){
            size_p rval = alph_unidef;
            int len = 0;
            for (int &i = len;str[i] != '\0';i++);
            int status = 1;
            size_p pos = 0;
            for (size_p i = position;i < length();i++){
                // char current_str[len] = "";
                int index = 0;
                for (size_p x = i;index != len;x++){
                    if (str[index] == gvalue[x]){
                        status = 1;
                        pos = i;
                    }
                    else {
                        status = 0;
                    }
                    index++;
                }
                if (status == 1){
                    pos = i; // confirming that the pos is set to i
                    rval = pos; // set the return value to pos
                    break;
                }
                // current_str[len+1] = '\0';
            }
            return rval;
        }
        size_p substr(size_p pos, size_p length){
            // Will be implemented later on 
        }
        void clear(){
            delete[] gvalue;
            gvalue = nullptr;
            gvalue = new char[1];
            gvalue[0] = '\0'; // default character
            glen = 0;
        }

        ~alph(){
            delete[] gvalue;
            gvalue = nullptr;
        }
};

#endif