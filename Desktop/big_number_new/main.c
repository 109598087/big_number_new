#include <stdio.h>
#include <stdlib.h>
#define LEN 100
//void test_oper(char input1[], char input2[], char op)
//{
//    char c[LEN];
//    if(op == '+')
//    {
//        Add(input1, input2, c);
//        re_Print(c);
//    }
//    if(op == '-')
//    {
//        Sub(input1, input2, c);
//        re_Print(c);
//    }
//    if(op == '*')
//    {
//        Mul(input1, input2, c);
//        re_Print(c);
//    }
//}
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
    if(sign_num==0 || sign_num==3) // 同號
    {
        for(i=0; i<LEN; i++)
        {
            result[i] = input1_int[i] + input2_int[i];
        }
        for(i=0; i<LEN-1; i++)
        {
            if(result[i]>10)
            {
                result[i+1] += result[i]/10;
                result[i] = result[i]%10;
            }
        }
        if(sign_num==3) //-- 把result最後面加一個負號
        {
            for(i=LEN-1; i>0; i--)
            {
                if(result[i]!=0) break;
            }
            result[i+1] = 100; //在print的時候看到100->'-'
        }
    }
    else //異號
    {
        //改變input2的符號(加一個負號)

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
    if(sign_num==0 || sign_num==3)//同號
    {

    }
    else //異號
    {
        //改變input2的符號(加一個負號)
//        Add();
    }
}
void Mul(char input1[], char input2[], int result[])
{

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
            sign1_num = 1; //input1有-
            break;
        }
    }
    for(i=0; i<strlen(input2); i++)
    {
        if(input2[i]=='-')
        {
            sign2_num = 1; //input2有-
            break;
        }
    }
    if(sign1_num == 0 && sign2_num == 0)return 0; //++
    if(sign1_num == 0 && sign2_num == 1)return 1; //+-
    if(sign1_num == 1 && sign2_num == 0)return 2; //-+
    if(sign1_num == 1 && sign2_num == 1)return 3; //--
}






int main()
{
    int temp[LEN] = {0};
 //   Add("-9999", "-9876", temp);
    Sub("99999", "-9876", temp);
    re_Print(temp);
    return 0;
}
