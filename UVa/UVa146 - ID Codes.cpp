//����STL������һ�����С���next_permutation��������
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    char str[55];
    int len;
    while(gets(str)!=NULL)
    {
        if(str[0] == '#') break;
        len = strlen(str);
        if(next_permutation(str,str+len)) puts(str);
        else puts("No Successor");
    }
    return 0;
}
