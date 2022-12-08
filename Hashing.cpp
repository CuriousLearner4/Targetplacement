#include <bits/stdc++.h>
using namespace std;
//Direct address table
// void insert(bool arr[],int key)
// {
//     if(arr[key] == true) cout<<"Key already exists";
//     else arr[key] = true;
// }

// bool search(bool arr[],int key)
// {
//     return arr[key];
// }

// void Delete(bool arr[],int key)
// {
// }
// }
int hashgen(int val,int bucket = 7)
{
    return val%bucket;
}

void insert(vector<vector<int>> &table,int val)
{
    table[hashgen(val)].push_back(val);
}

bool search(vector<vector<int>> table,int val)
{
    for(int i = 0 ;i< table[hashgen(val)].size();++i)
    {
        if(table[hashgen(val)][i]==val) return true;
    }
    return false;
}

void Delete(vector<vector<int>> &table,int val)
{
    for(int i = 0 ;i< table[hashgen(val)].size();++i)
    {
        if(table[hashgen(val)][i]==val) 
        {
            for(int j=i+1;j<table[hashgen(val)].size();++j)
            table[hashgen(val)][j-1] = table[hashgen(val)][j];
            table[hashgen(val)].pop_back();
        }
    }
}

int main()
{
    // bool arr[1000] = {0};
    //  insert(arr,10);
    //  insert(arr,20);
    //  insert(arr,119);
    // cout<<search(arr,10)<<"\n";
    // cout<<search(arr,20)<<"\n";
    //  Delete(arr,119);
    // cout<<search(arr,119)<<"\n";
    // cout<<search(arr,118)<<"\n";
    // cout<<search(arr,1)<<"\n";
    // return 0;
    
    //Chaining
    vector<vector<int>> table(7);
    insert(table,10);
    insert(table,20);
    insert(table,119);
    for(int i=0;i<table.size();++i)
    {
        cout<<i<<": ";
        for(int j=0;j<table[i].size();++j)
        {
            cout<<table[i][j];
        }
        cout<<"\n";
    }
    cout<<search(table,10)<<"\n";
    cout<<search(table,20)<<"\n";
    Delete(table,119);
    cout<<search(table,119)<<"\n";
    cout<<search(table,118)<<"\n";
    cout<<search(table,1)<<"\n";
    return 0;
}