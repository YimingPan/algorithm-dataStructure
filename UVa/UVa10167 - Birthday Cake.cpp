//ֱ��ö���߶β���A��B����
#include <cstdio>

struct Point
{
    int x,y;
}p[105];
int n;

bool check(int a,int b)
{
    int cnt_above=0;
    for(int i=0;i<2*n;i++)
    {
        if(cnt_above>n) return 0;
        if(a*p[i].x+b*p[i].y>0)
            cnt_above++;
        else if(a*p[i].x+b*p[i].y==0) return 0;//һ�����ڹ������ǲ������
    }
    if(cnt_above == n) return 1;
    return 0;
}

int main()
{
    int A,B;
    while(scanf("%d",&n),n)
    {
        for(int i=0;i<2*n;i++) scanf("%d%d",&p[i].x,&p[i].y);
        bool found = 0;
        for(A=-500;A<=500;A++)//������ѭ���ܿ�ͻ��˳�
        {
            for(B=-500;B<=500;B++)
            {
                if(check(A,B))
                {
                    found = 1;
                    break;
                }
            }
            if(found) break;
        }
        printf("%d %d\n",A,B);
    }
    return 0;
}
