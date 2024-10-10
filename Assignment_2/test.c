#include<stdio.h>
int main()
{
    int arr[5];
    int a;
    int a;
    {
        int f;
    }
    {
        f = 10;
    }
    for(int i = 0; i < 5; i++) //
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < 5; i++) //
    {
        //for_scope-1
    }
    for(int i = 1; i < 5; i++) //
    {
        //for_scope-1
    }
    //scope-2
    {
        int b;
        int b;
    }

    for(int i = 0; i < 5; i++)
    {
        printf("index: %d - Value: %d\n", i, arr[i]);
    }

    int i = 1;
    while(i < 5)
    {
        
        i++;
    }
    // while(test_case--)
    // {
    //     printf("tes_case - %d\n", test_case); // test_case  = 0 //assigned
    //     int a , b; 
    //     scanf("%d %d", &a, &b);
    //     int sum = a + b;
    //     printf("%d\n", sum);
    // }

    // if(0) printf("Hello\n");
    // else printf("Not true value\n");
    int t = 3;
    do{
        int a , b; 
        scanf("%d %d", &a, &b);
        int sum = a + b;
        printf("%d\n", sum);
        t--;
    }while(t > 0);
    return 0;
}