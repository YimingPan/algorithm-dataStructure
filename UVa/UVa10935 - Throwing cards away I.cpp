#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int n;  //n��ʾ�ܿ�Ƭ��
    while(scanf("%d",&n), n)
    {
        queue<int> q;   //��ʼʱ���б���Ϊ�գ���ÿ���ؽ�һ��
        for(int i=1;i<=n;i++) q.push(i);
        printf("Discarded cards:");
        for(int k=0;k<n-1;k++)  //k��ʾ����������
        {
            if(k == n-2) printf(" %d",q.front());   //�����ʽУ��
            else printf(" %d,",q.front());
            q.pop();    //������һ���ƣ��ڶ����Ƴ�Ϊ����Ԫ��
            q.push(q.front());  //�ڶ��������
            q.pop();
        }
        printf("\nRemaining card: %d\n",q.front());
    }
    return 0;
}
