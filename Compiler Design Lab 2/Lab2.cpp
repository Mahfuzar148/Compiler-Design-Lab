#include<bits/stdc++.h>
using namespace std;
bool is_vowel(char chr)
{
    if(chr=='A'||chr=='E'||chr=='I'||chr=='O'||chr=='U'||chr=='a'||chr=='e'||chr=='i'||chr=='o'||chr=='u')
    {
        return true;
    }
    return false;
}

int main()
{
    ifstream inputFile("C:\\Users\\DELL\\Documents\\Compiler Desing Lab\\input2.txt");
    ofstream outputFile("C:\\Users\\DELL\\Documents\\Compiler Desing Lab\\output2.txt");
    if(!inputFile.is_open())
    {
        cerr<<("Failed to open input File");
    }

    if(!outputFile.is_open())
    {
        cerr<<("Failed to open output file");
    }

    string line;
    int vowel = 0,consonant = 0;
    vector<char>vow,con;
    vector<string>wv,wc;
    while(getline(inputFile,line))
    {
        istringstream iss(line);
        string word;
        while(iss>>word)
        {
            if(is_vowel(word[0]))
            {
                wv.push_back(word);
            }
            if(!is_vowel(word[0]) and isalpha(word[0]))
            {
                wc.push_back(word);
            }
        }
       for(int i=0;i<line.size();i++)
       {
           if(is_vowel(line[i]))
           {
               vowel++;
               vow.push_back(line[i]);
           }
           if(!is_vowel(line[i]) and isalpha(line[i]))
           {
               consonant++;
               con.push_back(line[i]);
           }
       }

    }
    outputFile<<"Number of vowel : "<<vowel<<endl;
    outputFile<<"Number of consonant : "<<consonant<<endl;

    outputFile<<"Vowels that exist in the above string : "<<endl;
    for(auto u : vow)
    {
        outputFile<<u<<" ";
    }


    outputFile<<endl<<"Consonants that exist in the above string : "<<endl;
    for(auto u : con)
    {
        outputFile<<u<<" ";
    }

    outputFile<<endl<<"Words that start with vowel : "<<endl;
    for(auto u : wv)
    {
        outputFile<<u<<", ";
    }
    outputFile<<endl<<"Words that start with consonant : "<<endl;
    for(auto u : wc)
    {
        outputFile<<u<<", ";
    }

    inputFile.close();
    outputFile.close();
    cerr<<"Output has been written successfully to output2.txt "<<endl;

    return 0;


}
