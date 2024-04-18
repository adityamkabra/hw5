#ifndef RECCHECK
// For debugging
#include <iostream>
// For std::remove
#include <algorithm> 
#include <map>
#include <set>
#include <vector>
#endif

#include "wordle.h"
#include "dict-eng.h"
using namespace std;


// Add prototypes of helper functions here


// Definition of primary wordle function
std::set<std::string> wordle(
    const std::string& in,
    const std::string& floating,
    const std::set<std::string>& dict)
{
   
    // Add your code here
    std::set<std::string> s;
     if(in.size()==0)
    {
      return s;
    }
    vector<int> ind;
    std::string w = in;
    for(int i =0; i<in.size(); i++)
    {
        if(in[i]=='-')
        {
          ind.push_back(i);
        }

    }
  
    int over = 0;
    
    word(w,dict,0,ind,s,floating,0);
    cout<<s.size()<<endl;
    return s;
}
void word(const std::string& inp,  const std::set<std::string>& dict, int ctr, vector<int> ind, std::set<std::string>& s, const std::string& floating,int over)
{
    std::string in = inp;
    if(ind.size()==ctr)
    {
      
      if(dict.find(in)!=dict.end())
      {
        s.insert(in);
        return;
      }
      return;
    }
    if(over!=floating.size())
    {
      for(int i =0; i<ind.size(); i++)
      {
       
                in[ind[i]]=floating[over];
              
                vector<int> v;
                
                for(int j = 0; j<ind.size(); j++)
                {
                  if(j==i)
                  {
                    continue;
                  }
                  else
                  {
                    v.push_back(ind[j]);
                    
                  }
                  
                }
                word(in, dict, ctr,v,s, floating, over+1);
                in[ind[i]]='-';
      }
    }
      
    else if(over==floating.size())
    {
       
      for(int i =0 ; i<26; i++)
      {
          char ch = static_cast<char>(i+97);
          in[ind[ctr]]=ch;
          word(in, dict, ctr+1,ind,s, floating,over);
          in[ind[ctr]]='-';
      }
    }
      
    return;
}
