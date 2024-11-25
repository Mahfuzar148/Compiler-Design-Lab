/*
Write a program that read the following string:
“Munmun is the student of Computer Science & Engineering”.
a) Count how many vowels and Consonants are there?
b) Find out which vowels and consonants are existed in the above string?
c) Divide the given string into two separate strings, where one string only contains
 the words started with vowel, and another contains the words started with consonant.
*/

#include<bits/stdc++.h>
using namespace std;
bool is_vowel(char c){
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
    {
        return true;
    }
    return false;
}
int main()
{
    freopen("input2.txt","r",stdin);
    string line;
    getline(cin,line);
    cout<<line<<endl;

    string vowels ,consonants,word;
    int vowel = 0, consonant = 0;

    string vowelString,consonantString;



    for( char c : line)
    {
        if(is_vowel(c))
        {
            vowel++;
            vowels+=c;

        }

        else
        {
            if(tolower(c)>='a' and tolower(c)<='z')
            {
                consonant++;
                consonants+=c;
            }
        }

        if(isalpha(c))
        {
            word+=c;

        }
        else
        {
            if(c==' ')
            {
                if(is_vowel(word[0]))
                {
                    vowelString +=word +" ";
                     word = "";
                }
                else
                {
                     consonantString+= word+" ";
                      word = "";
                }
            }
        }

    }

             if(is_vowel(word[0]))
                {
                    vowelString +=word +" ";

                }
                else
                {
                     consonantString+= word+" ";

                }
//    string str;
//    istringstream word(line);
//
//   while(word>>str)
//   {
//      if(is_vowel(str[0]))
//      {
//          vowelString +=str +" ";
//      }
//      else{
//        consonantString+= str+" ";
//      }
//   }

   cout<<"Number of vowels : "<<vowel<<endl;
   cout<<"Number of consonant : "<<consonant<<endl;
   cout<<"The vowels are : "<< vowels<<endl;
   cout<<"The consonants are : "<<consonants<<endl;
   cout<<"The vowel string is : "<<vowelString<<endl;
   cout<<"The cconsonant string is :"<<consonantString<<endl;

}
