#include <bits/stdc++.h>
using namespace std;

void lrao(int arr[],int size)
{
    int temp = arr[0];
    for(int i =1;i<size;++i)
    {
        arr[i-1] = arr[i];
    }
    arr[size-1] = temp;
}
void move_zeros2end(int arr[],int size)
{
    int nonzerocount = 0;
    for(int i=0;i<size;++i)
    {
        if(arr[i]!=0) swap(arr[i],arr[nonzerocount++]);
    }
}

void reverse_array(int arr[],int size)
{
    int i = 0; 
    int j = size-1;
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    }
}
int second_largest(int arr[],int size)
{
    int pos = 0;
    for(int i=1;i<size;++i)
    {
        if(arr[i]>arr[pos])
        pos = i;
    }
    int fl_pos = pos;
    pos = -1;
    for(int i=0;i<size;++i)
    {
        if(arr[i]!=arr[fl_pos])
        {
            if(pos==-1)
            pos = i;
            else if(arr[i]>arr[pos])
            pos = i;
        }
    }
    return pos; 
}

int esecondlargest(int arr[],int size)
{
    int firstpos =  0,secondpos = -1;
    for(int i=1;i<size;++i)
    {
        if(arr[i]>arr[firstpos])
        {
            secondpos = firstpos;
            firstpos = i;
        }
        else if(arr[i]<arr[firstpos])
        {
            if(secondpos==-1||arr[i]>arr[firstpos]) 
                secondpos = i;
        }
    }
    return secondpos;
}

int delete_arr(int arr[],int size,int x)
{
    for(int i=0;i<size;++i)
    {
        if(arr[i]==x) 
        {
            for(int j = i+1;j<size;j++)
            {
                arr[j-1] = arr[j];
            }
            return size-1;
        }
    }
    return size;
}

void disp(int arr[],int size)
{
    for(int i=0;i<size;++i)
    cout<<arr[i]<<" ";

    cout<<"\n";
}

int main()
{
    int arr[] = {1,2,4,5,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    disp(arr,size);
    lrao(arr,size);
    disp(arr,size);
    // int pos = second_largest(arr,size);
    // if(pos>=0)
    // cout<<arr[pos]<<"\n";
    // else
    // cout<<"No second largest\n";
    // pos = esecondlargest(arr,size);
    // if(pos>=0)
    // cout<<arr[pos]<<"\n";
    // else
    // cout<<"No second largest\n";
    return 0;
}