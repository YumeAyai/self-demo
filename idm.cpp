#include <iostream>
using namespace std;

int main()
{
    int size;
    char c;
    double t;
    cout << "How long is your array?\n";
    scanf_s("%d", &size);
    cout << "Input your Delta x :\n";
    scanf_s("%lf", &t);
    //此处应用一个动态数组
    float* s=new float [size]();//建立一个动态数组，以应对数组大小变化

check:
    //此处为goto的检查点，便于更正输入错误
    cout << "Now input your numbers:\n";
    int i = 0;
    // size次循环输入
    for (i = 0; i < size; i++)
    {
        scanf_s("%lf", &s[i]);
    }
    // size次循环打印
    printf("Input numbers are:\n");
    for (i = 0; i < size; i++)
    {
        printf_s("%lf ", s[i]);
    }
    printf("\n");
    system ("pause");
    cout << "if number is correct,input y,else input n\n";
    cin >> c; 
    if(c!='y')
    {goto check;}


    //对Δ进行计算
    float sum1=0, sum2=0;
    float result=-1.0;
    int halfsize=size/2;
    if (size % 2 == 1)
    {
        for (i = 0; i < halfsize; i++)
        {
            sum1 += s[i];
        }
        for (i = 0; i < halfsize; i++)
        {
            sum2 += s[i+halfsize+1];
        }
        result = (sum2-sum1)/(halfsize*halfsize*t*t);
    }
    else
    {
        for (i = 0; i < halfsize; i++)
        {
            sum1 += s[i];
        }
        for (i = 0; i < halfsize; i++)
        {
            sum2 += s[i + halfsize];
        }
        result = (sum2 - sum1) / (halfsize * halfsize*t*t);
    }
    printf("Δ=%lf", result);           
    delete[] s;//记得释放内存
    system("pause");
    return 0;
}
