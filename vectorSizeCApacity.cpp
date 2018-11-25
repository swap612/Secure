#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


std::vector<int> primeSet ;
//={2,3,5,7,11,13,17,19,23,29,31,37,41,43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,97};


int main(){

    // std::sort();

  // primeSet.resize(40);

    for(int i=0;i<1000000000;i++)
    primeSet.push_back(i);
    cout<<"size::"<<primeSet.capacity()<<endl;
    // for(int i=0;i<primeSet.size();i++){
    //     cout<<primeSet[i]<<" ";
    // }

    std::vector<int>::iterator v_it;
    for(v_it=primeSet.begin();v_it!=primeSet.end();v_it+=16){
        cout<<*v_it;
    }
    cout<<"size::"<<primeSet.size()<<endl;
}
