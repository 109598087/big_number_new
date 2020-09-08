#include <stdio.h>
#include <stdlib.h>
#define LEN 100


void Add(char input1[], char input2[], int result[])
{
    int sign_num = sign(input1, input2);
    int i, input1_int[LEN]= {0}, input2_int[LEN]= {0}; // save no - int[]
    int len1=strlen(input1), len2=strlen(input2);
    for(i=0; i<len1; i++)
    {
        if(input1[len1-i-1]=='-') continue;
        input1_int[i] = input1[len1-i-1]-'0';
    }
    for(i=0; i<len2; i++)
    {
        if(input2[len2-i-1]=='-') continue;
        input2_int[i] = input2[len2-i-1]-'0';
    }
    if(sign_num==0 || sign_num==3) // �P��
    {
        for(i=0; i<LEN; i++)
        {
            result[i] = input1_int[i] + input2_int[i];
        }
        for(i=0; i<LEN-1; i++)
        {
            if(result[i]>=10)
            {
                result[i+1] += result[i]/10;
                result[i] = result[i]%10;
            }
        }
        if(sign_num==3) //-- ��result�̫᭱�[�@�ӭt��
        {
            for(i=LEN-1; i>0; i--)
            {
                if(result[i]!=0) break;
            }
            result[i+1] = 100; //�bprint���ɭԬݨ�100->'-'
        }
    }
    else //����
    {
        if(len1>len2)
        {
            for(i=0; i<LEN; i++)
            {
                result[i] = input1_int[i] - input2_int[i];
            }
            for(i=0; i<LEN-1; i++)
            {
                if(result[i] < 0)
                {
                    result[i+1] -= 1;
                    result[i] = 10+result[i];
                }
            }
            if(sign_num==2)
            {
                for(i=LEN-1; i>0; i--)
                {
                    if(result[i]!=0) break;
                }
                result[i+1] = 100; //�bprint���ɭԬݨ�100->'-'
            }
        }
        else //len2>len1
        {
            for(i=0; i<LEN; i++)
            {
                result[i] = input2_int[i] - input1_int[i];
            }
            for(i=0; i<LEN-1; i++)
            {
                if(result[i] < 0)
                {
                    result[i+1] -= 1;
                    result[i] = 10+result[i];
                }
            }
            if(sign_num==1)
            {
                for(i=LEN-1; i>0; i--)
                {
                    if(result[i]!=0) break;
                }
                result[i+1] = 100; //�bprint���ɭԬݨ�100->'-'
            }
        }

    }

}
void Sub(char input1[], char input2[], int result[])
{
    int sign_num = sign(input1, input2);
    int i, input1_int[LEN]= {0}, input2_int[LEN]= {0}; // save no - int[]
    int len1=strlen(input1), len2=strlen(input2);
    for(i=0; i<len1; i++)
    {
        if(input1[len1-i-1]=='-') continue;
        input1_int[i] = input1[len1-i-1]-'0';
    }
    for(i=0; i<len2; i++)
    {
        if(input2[len2-i-1]=='-') continue;
        input2_int[i] = input2[len2-i-1]-'0';
    }

    if(sign_num==0 || sign_num==3)//�P��
    {
        //�p��Ʀr
        if(len1>len2) //if�����k��j
        {
            for(i=0; i<LEN; i++)
            {
                result[i] = input1_int[i] - input2_int[i];
            }
            for(i=0; i<LEN-1; i++)
            {
                if(result[i] < 0)
                {
                    result[i+1] -= 1;
                    result[i] = 10+result[i];
                }
            }
            if(sign_num==3)
            {
                for(i=LEN-1; i>0; i--)
                {
                    if(result[i]!=0) break;
                }
                result[i+1] = 100; //�bprint���ɭԬݨ�100->'-'
            }
        }
        else // len2>len1
        {
            for(i=0; i<LEN; i++)
            {
                result[i] = input2_int[i] - input1_int[i];
            }
            for(i=0; i<LEN-1; i++)
            {
                if(result[i] < 0)
                {
                    result[i+1] -= 1;
                    result[i] = 10+result[i];
                }
            }
            if(sign_num==0)
            {
                for(i=LEN-1; i>0; i--)
                {
                    if(result[i]!=0) break;
                }
                result[i+1] = 100; //�bprint���ɭԬݨ�100->'-'
            }
        }
    }
    else //����
    {
        for(i=0; i<LEN; i++)
        {
            result[i] = input1_int[i] + input2_int[i];
        }
        for(i=0; i<LEN-1; i++)
        {
            if(result[i]>=10)
            {
                result[i+1] += result[i]/10;
                result[i] = result[i]%10;
            }
        }
        if(sign_num==2)
        {
            for(i=LEN-1; i>0; i--)
            {
                if(result[i]!=0) break;
            }
            result[i+1] = 100; //�bprint���ɭԬݨ�100->'-'
        }
    }
}
void Mul(char input1[], char input2[], int result[])
{
    int sign_num = sign(input1, input2);
    int i,j, input1_int[LEN]= {0}, input2_int[LEN]= {0}; // save no - int[]
    int len1=strlen(input1), len2=strlen(input2);
    for(i=0; i<len1; i++)
    {
        if(input1[len1-i-1]=='-') continue;
        input1_int[i] = input1[len1-i-1]-'0';
    }
    for(i=0; i<len2; i++)
    {
        if(input2[len2-i-1]=='-') continue;
        input2_int[i] = input2[len2-i-1]-'0';
    }
    for(i=0; i<LEN; i++)
    {
        for(j=0; j<LEN; j++)
        {
            result[i+j]+=input1_int[j]*input2_int[i];
            if(result[i+j]>=10)
            {
                result[i+j+1]+=result[i+j]/10;
                result[i+j]=result[i+j]%10;
            }
        }
    }
    if(sign_num==1 || sign_num==2)
    {
        for(i=LEN-1; i>0; i--)
        {
            if(result[i]!=0) break;
        }
        result[i+1] = 100; //�bprint���ɭԬݨ�100->'-'
    }



}
void re_Print(int result[]) // ok
{
    int i;
    char print_result[LEN];
    for(i=0; i<LEN; i++)
    {
        if(result[i] == 100)
        {
            print_result[i] = '-';
            continue;
        }
        print_result[i] = result[i] + '0';
    }
    for(i=LEN-1; i>0; i--)
        if(print_result[i]!='0') break;
    for(; i>=0; i--)
    {
        printf("%c", print_result[i]);
    }
    printf("\n");
}
int sign(char input1[], char input2[]) //0:++,1:+-, 2:-+, 3:--
{
    int i, sign1_num=0, sign2_num=0;
    for(i=0; i<strlen(input1); i++)
    {
        if(input1[i]=='-')
        {
            sign1_num = 1; //input1��-
            break;
        }
    }
    for(i=0; i<strlen(input2); i++)
    {
        if(input2[i]=='-')
        {
            sign2_num = 1; //input2��-
            break;
        }
    }
    if(sign1_num == 0 && sign2_num == 0)return 0; //++
    if(sign1_num == 0 && sign2_num == 1)return 1; //+-
    if(sign1_num == 1 && sign2_num == 0)return 2; //-+
    if(sign1_num == 1 && sign2_num == 1)return 3; //--
}
void test_oper(char input1[], char input2[], char op)
{
    int c[LEN*2] = {0};
    switch(op)
    {
    case '+':
        Add(input1, input2, c);
        re_Print(c);
        break;
    case '-':
        Sub(input1, input2, c);
        re_Print(c);
        break;
    case '*':
        Mul(input1, input2, c);
        re_Print(c);
        break;
    }
}

int main()
{
    test_oper("11111", "999", '+');
    test_oper("11111", "-999", '+');
    test_oper("-11111", "999", '+');
    test_oper("-11111", "-999", '+');
    test_oper("999", "11111", '+');
    test_oper("999", "-11111", '+');
    test_oper("-999", "11111", '+');
    test_oper("-999", "-11111", '+');

    test_oper("11111", "999", '-');
    test_oper("11111", "-999", '-');
    test_oper("-11111", "999", '-');
    test_oper("-11111", "-999", '-');
    test_oper("999", "11111", '-');
    test_oper("999", "-11111", '-');
    test_oper("-999", "11111", '-');
    test_oper("-999", "-11111", '-');

    test_oper("11111", "999", '*');
    test_oper("11111", "-999", '*');
    test_oper("-11111", "999", '*');
    test_oper("-11111", "-999", '*');
    test_oper("999", "11111", '*');
    test_oper("999", "-11111", '*');
    test_oper("-999", "11111", '*');
    test_oper("-999", "-11111", '*');


    return 0;
}
