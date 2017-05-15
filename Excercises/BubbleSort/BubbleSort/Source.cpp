#include <iostream>

using namespace std;

void main()
{
	system("Pause");
}

void bubbleSorting()
{
	int myArray[50] = { 1,2,3,4,5,6,7,8,9 };
	int count = 10;
	int temp;

    for(int i = 0; i < count; ++i)
    {
        for(int j=0;j<(count-i);++j)
            if(myArray[j] > myArray[j+1])
            {
                temp=myArray[j];
                myArray[j]=myArray[j+1];
                myArray[j+1]=temp;
            }
    }
    
    cout<<"Array after bubble sort:" << count <<endl;
    for(int i=0;i<count;++i)
        cout<<" "<<myArray[i];
}