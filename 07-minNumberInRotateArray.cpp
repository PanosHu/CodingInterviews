/********************************
 *@file:
 *@author: Pan HU
 *@data: 2015-8-16
 *@version: 0.1
 *@describe:
 ********************************/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>
using namespace std;

int minNumberInRotateArray(vector<int> rotateArray);

int main()
{
	int arr[] = {3,4,5,1,2};
	vector<int> vec/*(arr,arr+sizeof(arr)/sizeof(*arr))*/;
	try{
		cout<<minNumberInRotateArray(vec)<<endl;
	} catch (const runtime_error &e){
		cerr<<e.what()<<endl;
	}
	vec.push_back(2);
	vec.push_back(1);
	cout<<minNumberInRotateArray(vec)<<endl;
	return 0;
}

int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.empty())
	{
		throw runtime_error("array is empty!");
	}
	
	int indexLeft  = 0;
	int indexRight = rotateArray.size()-1;
	int indexMid   = 0;
	
	while(rotateArray[indexLeft] >= rotateArray[indexRight])
	{
		if(indexRight - indexLeft == 1)
		{
			return rotateArray[indexRight];
		}
		
		indexMid = (indexLeft + indexRight)/2;
		if(rotateArray[indexLeft] == rotateArray[indexRight] 
		&& rotateArray[indexLeft] == rotateArray[indexMid])
		{
			int minItem = rotateArray[indexLeft];
			for(int i = indexLeft+1; i <= indexRight; ++i)
			{
				if(rotateArray[i] < minItem)
				{
					minItem = rotateArray[i];
				}
			}
			return minItem;
		}
		
		if(rotateArray[indexMid] >= rotateArray[indexLeft])
		{
			indexLeft = indexMid;
		}
		else if(rotateArray[indexMid] <= rotateArray[indexRight])
		{
			indexRight = indexMid;
		}
	}
	return rotateArray[indexMid];
}