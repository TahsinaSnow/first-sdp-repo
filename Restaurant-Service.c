#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void return_menu();

struct info
{
    char name[50];
    char code[50];
    float price;
};
struct info f;


int Add()
{
    FILE *fp;
    fp=fopen("food.dat","a");

        printf("\n\t\t enter food name:: ");
        scanf("%s",f.name);
        printf("\n\t\t enter food code:: ");
        scanf("%s",f.code);
        printf("\n\t\t enter food price:: ");
        scanf("%f",&f.price);
        fwrite(&f,sizeof(f),1,fp);
        printf("Record insert successful");
    fclose(fp);

}
int search()
{
    system("cls");

    char r[10];
    gets(r);

	FILE *fp;

	fp = fopen("food.dat","r");
	char code[10];
	char ch;
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else


	fp=fopen("food.dat","r");
            {
                while(fread(&f,sizeof(f),1,fp)==1)
                    {
                        printf("\n\t\t***************************************\n");
                        printf("\n\t\t\tfood name:: ");
                        printf("%s",f.name);
                        printf("\n\t\t\tfood code:: ");
                        printf("%s",f.code);
                        printf("\n\t\t\tfood price:: ");
                        printf("%.2f",f.price);
                        printf("\n\n\t\t***************************************\n");

                    }
            }
        fclose(fp);

        printf("\n\n\t\tEnter food code: ");
	    gets(code);

	  fp=fopen("food.dat","r");
            {
                while(fread(&f,sizeof(f),1,fp)==1)
                    if(strcmp(f.code,code)==0)
                    {
                        printf("\n\t\t***************************************\n");
                        printf("\n\t\t\t\tRECORD FOUND\n");
                        printf("\n\t\t***************************************\n");
                        printf("\n\t\t***************************************\n");
                        printf("\n\t\t\tfood name:: ");
                        printf("%s",f.name);
                        printf("\n\t\t\tfood code:: ");
                        printf("%s",f.code);
                        printf("\n\t\t\tfood price:: ");
                        printf("%.2f",f.price);
                        printf("\n\n\t\t***************************************\n");


                    }

            }
        fclose(fp);



}
int view()
{
    system("cls");

    char r[10];
    gets(r);

	FILE *fp;

	fp = fopen("food.dat","r");
	char number[100];
	char ch;
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else


	fp=fopen("food.dat","r");
            {
                while(fread(&f,sizeof(f),1,fp)==1)
                    {
                        printf("\n\t\t***************************************\n");
                        printf("\n\t\t\tfood name:: ");
                        printf("%s",f.name);
                        printf("\n\t\t\tfood code:: ");
                        printf("%s",f.code);
                        printf("\n\t\t\tfood price:: ");
                        printf("%.2f",f.price);
                        printf("\n\n\t\t***************************************\n");

                    }
            }
        fclose(fp);

}
int order()
{
    system("cls");

    char r[10];
    gets(r);

	FILE *fp;

	fp = fopen("food.dat","r");
	char code[10],ordarry[10][50];
	char ch;
	if(fp == NULL)
	{
		printf("file does not found !");
		exit(1);

	}
	else


	fp=fopen("food.dat","r");
            {
                while(fread(&f,sizeof(f),1,fp)==1)
                    {
                        printf("\n\t\t***************************************\n");
                        printf("\n\t\t\tfood name:: ");
                        printf("%s",f.name);
                        printf("\n\t\t\tfood code:: ");
                        printf("%s",f.code);
                        printf("\n\t\t\tfood price:: ");
                        printf("%.2f",f.price);
                        printf("\n\n\t\t***************************************\n");

                    }
            }
        fclose(fp);


        char ord;
        float total_price = 0;
        int j = 0;
        int total_seat,seatarry[10];
        do{
            fp=fopen("food.dat","r");

        printf("\n\n\t\tEnter food code: ");
	    scanf("%s",&code);

	    printf("\n\t\tTotal number of food :");
        scanf("%d",&total_seat);

        seatarry[j] = total_seat;


            {
                while(fread(&f,sizeof(f),1,fp)==1)
                    if(strcmp(f.code,code)==0)
                    {
                        strcpy(ordarry[j],f.code);
                        printf("\n\t\t\tOrder Placed\n");

                        printf("\n\t\t\tfood name:: ");
                        printf("%s X %d",f.name,total_seat);
                        printf("\n\t\t\tfood price:: ");
                        printf("%.2f X %d",f.price,total_seat);

                        total_price = total_price + f.price*total_seat;

                        j++;
                    }

            }

            printf("\n\n\t\tDo you want to order another one? Y/N");
            ord = getch();

            fclose(fp);

       }while(ord == 'y' || ord  == 'Y');


       system("cls");
       printf("\n\n\t\t***************************************\n");
       printf("\n\n\t\tYour Orders: \n\n");

    int i;
       for(i = 0; i < j; i++)
        {
            fp=fopen("food.dat","r");

             while(fread(&f,sizeof(f),1,fp)==1)
                    if(strcmp(f.code,ordarry[i])==0)
                    {
                        printf("\n\t\t%d. %s (%d Pieces) :\t%.2f X %d",i+1,f.name,seatarry[i],f.price,seatarry[i]);
                    }
            fclose(fp);
       }

        printf("\n\n\t\t-----------------------------\n");
        printf("\t\tTotal price :\t\t%.2f\n\n",total_price);


    char Date[20];
    char name[20];
    char mobile[20];


	printf("\n\t\tPress any key to submit order.");
	getch();

    printf("\n\t\tDate:");
    scanf("%s",Date);
	printf("\n\t\tyour name :");
	scanf("%s",name);
	printf("\n\t\tmobile number :");
	scanf("%s",mobile);

	printf("\n\t\tOrder submitted, ENJOY!!!");
}


void main_menu(){
    printf("\n\t\t  =======================================\n");
    printf("\n\t\t\t MAIN MENU");
    printf("\n\t\t  =======================================\n");
    printf("\n\t\t1.Add Food name");
    printf("\n\t\t2.search details");
    printf("\n\t\t3.view details");
    printf("\n\t\t4.order");
    printf("\n\t\t5.exit");
    int choice;
    printf("\n\n\t\t ENTER YOUR CHOICE : ");
    scanf("%d",&choice);
    printf("\n\n\n");



    switch(choice)
    {

    case 1:
        Add();
        return_menu();
        break;

    case 2:
        search();
        return_menu();
        break;

    case 3:
        view();
        return_menu();
        break;

    case 4:
        order();
        return_menu();
        break;

    case 5:
        exit(0);
        return_menu();
        break;

    default:
        printf("Wrong choice !");
        break;
    }
    }


    void return_menu(){
        printf("Press any key to continue.");
        getchar();
        system("cls");
        main_menu();
    }

    void main()
{
    system("color 3f");

    printf("\n\t\t  =======================================");
    printf("\n\t\t        RESTAURANT SERVICE ");
    printf("\n\t\t  =======================================\n");

     main_menu();
}
