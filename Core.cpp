#include <iostream>
#include <conio>
#include <cstring>
#include <math>
#include <vector>
#include <fstream>

using namespace std;

int string_length(string name)    //Function to calculate string length
{
  int length=0;
  if(name[length]=='\0')
    return length;
  else
    length=length+1;
}

string encryption(string name, int index, int data_length)    //Function that encrypts
{
  
  ifstream file("Randomizer.txt");
    if(file.is_open())
    {
        int randomizer[(index+data_length)];

        for(int i = 0; i < (index+data_length); i++)
        {
            file >> randomizer[i];
        }
    }
  
  for(int i = index; i < data_length; i++)
  {
    name[i]=name[i]+randomizer[i];
  }  
  
  return(name);
}

void main()
{
  string data,key;
  
  getline (cin, data);  //get the data to be encripted
  getline (cin, key);   //get the passkey for encription
  
  int data_length,key_length;
  
  data_length=string_length(data);
  key_length=string_length(key);
  
  for(int i = 0; i < key_length; i++)
  {
    data = encryption(data,(int) key[i],data_length);
  }
  
  cout<<data;
}