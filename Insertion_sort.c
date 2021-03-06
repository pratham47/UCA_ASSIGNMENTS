#include <stdio.h>
#include <stdlib.h>
#include<sys/time.h>


void generate_input(int arr[], int n, int choice)
{
    switch(choice)
    {
        case 1:
               {
                    for(int i = 0; i < n; i++)
                    {
                        arr[i] = rand() % n + 1;
                    }
                    break;
               }

        case 2:
                {
                    for(int i = 0 ; i<n ; i++)
                    {
                       arr[i] = i;
                    }
                    break;
                }

        case 3:
                {

                   for(int i = 0; i < n; i++)
                   {
                       arr[i] = n-i-1;
                   }
                   break;
                }
    }
}


void insertion_sort(int arr[], int n)
{
     for(int i = 1; i < n; i++)
     {
        int current_element = arr[i];

        int current_element_index = i;

        int j = current_element_index-1;

        while(j >= 0 && arr[j] > current_element)
        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = current_element;
     }
}


void time_calculator(int initial_size, int increment, int choice)
{
    struct timeval te;

    for(int i = 0; i < 8; i++)
    {
        int size = initial_size + increment * i;

        int arr[size];

        generate_input(arr,size,choice);

        gettimeofday(&te,NULL);

        long long int start_time = te.tv_sec * 1000LL + te.tv_usec / 1000;

        insertion_sort(arr,size);

        gettimeofday(&te,NULL);

        long long int end_time = te.tv_sec * 1000LL + te.tv_usec / 1000;

        printf("\t %lld", end_time - start_time);
    }
}

int main()
{
    int initial_size = 8000;
    int increment = 4000;

    int ch;

    do
    {
     printf("Enter 1 to find out time taken by Random Numbers\n");

     printf("Enter 2 to find out time  taken by sorted numbers\n");

     printf("Enter 3 to find out time taken reverse sorted numbers\n");

     printf("Enter 4 to exit\n");

     printf("Enter your choice\n");

     scanf("%d",&ch);

     switch(ch)
     {
         case 1:
                {

                    printf("Time taken by Random Numbers");

                    time_calculator(initial_size,increment,ch);

                    printf("\n");

                    break;
                 }

         case 2:
                 {
                    printf("Time taken by sorted numbers");

                    time_calculator(initial_size,increment,ch);

                    printf("\n");

                    break;
                 }

         case 3:
                 {
                     printf("Time taken by reverse sorted numbers");

                     time_calculator(initial_size,increment,ch);

                     printf("\n");

                     break;
                 }

         case 4:
                 {
                    exit(0);
                 }

    }
 }while(ch >= 1 && ch <= 4);
}
