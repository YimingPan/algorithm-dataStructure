#include <cstdio>
int main()
{
    int D, I;   //FBT�����ȣ���Iֻ��
    int nCase;
    while(scanf("%d",&nCase), nCase != -1)
    {
        while(nCase --)
        {
            int k = 1;  //���һ��С�����ξ����Ľڵ���
            scanf("%d%d",&D,&I);
            for(int i=0;i<D-1;i++)
            {
                //����ż�����������
                k = k*2-I%2+1;
                I = (I+I%2)/2;
            }
            printf("%d\n",k);
        }
    }
    return 0;
}
