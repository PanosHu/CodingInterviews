/********************************
 *@file:
 *@author: Pan HU
 *@data:
 *@version: 0.1
 *@describe:
 ********************************/
#include <iostream>
#include <cstring>
using namespace std;

void replaceSpace(char *src, int len)
{
    if(src == NULL || len <= 0)
    {
        return;
    }

    int iSpaceNum(0),iSrcLen(0);
    for(int i = 0; src[i] != '\0'; ++i)
    {
        ++iSrcLen;
        if(*(src+i) == ' ')
        {
            ++iSpaceNum;
        }
    }

    int iNewLen = iSrcLen + iSpaceNum*2;
    cout<<iSpaceNum<<" "<<iSrcLen<<" "<<iNewLen<<endl;
    if(iNewLen >= len)
    {
        return;
    }


    for(int i = iSrcLen-1; i >= 0; --i)
    {
        if(src[i] == ' ')
        {
            src[-1+iNewLen--] = '0';
            src[-1+iNewLen--] = '2';
            src[-1+iNewLen--]   = '%';
        }
        else
        {
            src[-1+iNewLen--] = src[i];
        }
    }
    src[iSrcLen + iSpaceNum*2] = '\0';
    cout<<src<<endl;
}

int main1()
{
    char arr[100];
    memset(arr,0,sizeof(char)*100);
    strcpy(arr,"hello world!");
    replaceSpace(arr,100);
    return 0;
}
