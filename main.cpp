#include<iostream>
#include<string>
using namespace std;

bool isBinary(string str){
    for(int i = 0; i< str.length(); i++){
        if(str[i] == '1' || str[i] == '0'){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

bool Equals(string bin1, string bin2){
    if( !isBinary(bin1) || !isBinary(bin2)) return false;
    int l1 = bin1.length();
    int l2 = bin2.length();


    int min = l1;
   
    int dif = l2 - l1;

    if(l2 < l1){
      min = l2;
      dif = l1 - l2;
    }
    
  if(l1 > l2){
    for(int i = 0; i < dif; i++){
      if(bin1[i] == '1') return false;
    }
  }

  if(l2 > l1){
    for(int i = 0; i < dif; i++){
      if(bin2[i] == '1') return false;
    }
  }


for(int i = min -1; i>=0; i--){
  if(l1 > l2){
    if(bin1[i+dif] != bin2[i]) return false;
  }

  if(l2 > l1){
    if(bin1[i] != bin2[i+dif]) return false;
  }
}

    return 1;
}


bool NotEqual(string bin1, string bin2){
  return !Equals(bin1, bin2);
}


int main(){


    cout<< Equals("010000000000001", "00000001");
    cout<< NotEqual("0001", "00101");
    return 0;
}