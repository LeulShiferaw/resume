#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main()
{
     ifstream file_reader_0("doc1.txt");
     ifstream file_reader_1("doc2.txt");

     vector<string> words;
     map<string, bool> word_exists;
     map<string, int> d1_freq, d2_freq;

     char c;
     string buffer = "";
     while(file_reader_0 >> c)
     {
         if(c<'a'&&c>'z'&&c<'A'&&c>'Z'&&c<'0'&&c>'9')
         {
             if(word_exists.find(buffer)==string::npos)
             {
                words.push_back(buffer);
                word_exists[buffer] = true;
             }
             if(d1_freq.find(buffer)==string::npos)
             {
                 d1_freq[buffer] = 1;
                 buffer = "";
                 continue;
             }
             d1_freq[buffer]+=1;
             buffer = "";
         }
         buffer+=c;
     }
     buffer = "";
     while(file_reader_1 >> c)
     {
         if(c<'a'&&c>'z'&&c<'A'&&c>'Z'&&c<'0'&&c>'9')
         {
             if(word_exists.find(buffer)==string::npos)
             {
                words.push_back(buffer);
                word_exists[buffer] = true;
             }
             if(d2_freq.find(buffer)==string::npos)
             {
                 d2_freq[buffer] = 1;
                 buffer = "";
                 continue;
             }
             d2_freq[buffer]+=1;
             buffer = "";
         }
         buffer+=c;
     }

     int dot_pro = 0, total_d1
     for (int i = 0; i<words.size(); ++i)
     {
         int f_d1 = 0, f_d2 = 0;
         if(d1_freq.find(words[i])!=string::npos)
         {
             f_d1 = d1_freq[words[i]];
         }
         if(f_d1!=0)
         {
             if(d2_freq.find(words[i])!=string::npos)
             {
                 f_d2 = d2_freq[words[i]];
             }
         }
     }

}
