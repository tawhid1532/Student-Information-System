#include <stdio.h>
#include<windows.h>
#include<string.h>

struct student
{
    char name[100];
    char roll[100];
    char batch[100];
    char dept[100];
    char board[100];
    float marks[4];
    int pyear;
    float tmarks;
};

void main_menu();
void add_student();
void modify();
void search();
int num;
float sum=0.0;
struct student s;


int main()
{

    main_menu();

    return 0;

}
void main_menu()
{
    system("cls");
    int ch;
    printf("\n\n\n\t\tStudent Information System");
    printf("\n\n\t\t Please Enter a following options:\n\n");
    printf("\t\t1.Add Student\n");
    printf("\t\t2.Add more Student\n");
    printf("\t\t3.Search Student\n\n");
    printf("\t\tEnter a following choice (1/2/3):\t");
    scanf("%d", &ch);

    switch(ch)
    {
    case 1:
        add_student();
        break;
    case 2:
        modify();
        break;
    case 3:
        search();
        break;
    default:
        exit(0);
    }
}
void add_student()
{
    FILE *fp;

    system("cls");
    getchar();
    int i,j,e;
    printf("enter the num of entry of students: ");
    scanf("%d",&e);

    for(i=0; i<e; i++)
    {
        fp = fopen("data.txt", "a");
        printf("\n\nSTUDENT %d:\n", i+1);
        printf("Enter the roll of student:");
        scanf("%s", &s.roll);
        printf("Enter the name of student:");
        scanf("%s", &s.name);

        printf("Enter the board of student:");
        scanf("%s",s.board);
        printf("Enter the passing year of student:");
        scanf("%d",&s.pyear);
        printf("Enter the name of dept:");
        scanf("%s",&s.dept);
        printf("Enter the batch:");
        scanf("%s",&s.batch);
        printf("Enter the marks of student :\n");

        for(j=0; j<4; j++)
        {
            printf("Enter the marks of subject number %d:",j+1);
            scanf("%f",&s.marks[j]);
            sum=sum+s.marks[j];
        }

        s.tmarks=sum;
        printf("Total number %f\n",s.tmarks);

        fprintf(fp,"%s %s %s %d %s %s", s.roll, s.name, s.board, s.pyear, s.dept, s.batch);

        for(j=0; j<4; j++)
            fprintf(fp," %f", s.marks[j]);
        fprintf(fp," %f\n", s.tmarks);

        fclose(fp);
    }
    main_menu();
}

void modify()
{
    system("cls");
    getchar();
    FILE *fp;
    char k;
    int i,j,e;
    printf("Add more student data? Press Y or N:");
    scanf("%c",&k);

    if(k=='Y'||'y')
    {
        printf("Enter the number of students you want to add:");
        scanf("%d",&e);

        for(i=0; i<e; i++)
        {
            fp = fopen("data.txt", "a");
            printf("\n\nSTUDENT %d:\n", i+1);
            printf("Enter the roll of student:");
            scanf("%s", &s.roll);
            printf("Enter the name of student:");
            scanf("%s", &s.name);

            printf("Enter the board of student:");
            scanf("%s",s.board);
            printf("Enter the passing year of student:");
            scanf("%d",&s.pyear);
            printf("Enter the name of dept:");
            scanf("%s",&s.dept);
            printf("Enter the batch:");
            scanf("%s",&s.batch);
            printf("Enter the marks of student :\n");

            for(j=0; j<4; j++)
            {
                printf("Enter the marks of subject number %d:",j+1);
                scanf("%f",&s.marks[j]);
                sum=sum+s.marks[j];
            }

            s.tmarks=sum;
            printf("Total number %f\n",s.tmarks);

            fprintf(fp,"%s %s %s %d %s %s", s.roll, s.name, s.board, s.pyear, s.dept, s.batch);

            for(j=0; j<4; j++)
                fprintf(fp," %f", s.marks[j]);
            fprintf(fp," %f\n", s.tmarks);

            fclose(fp);
        }

    }

    else if(k=='N'||'n')
    {
        main_menu();
    }

    main_menu();
}
void search()
{
    system("cls");
    FILE *fp;
    int i,j;
    while(1)
    {

        printf("\nTo search by Batch press 1.\nTo search by dept press 2.\nTo search by roll press 3\nTo exit press 4\n");
        int h;
        scanf("%d",&h);
        getchar();
        if(h==1)
        {

            char batch[100];
            printf("Enter the batch:");
            scanf("%s",batch);
            fp = fopen("data.txt", "r");
            while(fscanf(fp,"%s %s %s %d %s %s", &s.roll, &s.name, &s.board, &s.pyear, &s.dept, &s.batch) != EOF)
            {
                for(j=0; j<4; j++)
                    fscanf(fp," %f", &s.marks[j]);
                fscanf(fp,"%f", &s.tmarks);

                if(strcmp(s.batch,batch) == 0)
                {

                    printf("Roll:%s\nName:%s\nPassing year:%d\nDept:%s\n",s.roll,s.name,s.pyear,s.dept);
                    for(j=0; j<4; j++)
                    {
                        printf("Marks of subject %d: %.2f\n",j+1,s.marks[j]);
                    }

                    printf("Total Marks: %.2f\n\n", s.tmarks);
                }
            }
            fclose(fp);
        }
        else if(h==2)
        {
            char dept[100];
            printf("Enter the name of the dept:");
            scanf("%s",dept);
            fp = fopen("data.txt", "r");
            while(fscanf(fp,"%s %s %s %d %s %s", &s.roll, &s.name, &s.board, &s.pyear, &s.dept, &s.batch) != EOF)
            {
                for(j=0; j<4; j++)
                    fscanf(fp," %f", &s.marks[j]);
                fscanf(fp,"%f", &s.tmarks);

                if(strcmp((s.dept),dept)==0)
                {
                    printf("Roll:%s\nName:%s\nBoard:%s\nBatch:%s\n",s.roll,s.name,s.board,s.batch);
                    for(j=0; j<4; j++)
                    {
                        printf("Marks of subjects %d: %.2f\n",j+1,s.marks[j]);
                    }
                    printf("Total Marks: %.2f\n\n", s.tmarks);
                }
            }
            fclose(fp);
        }
        else if(h==3)
        {
            char roll[100];
            printf("Enter the roll:");
            scanf("%s",roll);
            fp = fopen("data.txt", "r");
            while(fscanf(fp,"%s %s %s %d %s %s", &s.roll, &s.name, &s.board, &s.pyear, &s.dept, &s.batch) != EOF)
            {
                for(j=0; j<4; j++)
                    fscanf(fp," %f", &s.marks[j]);
                fscanf(fp,"%f", &s.tmarks);

                if(strcmp(s.roll,roll) == 0)
                {
                    printf("Name:%s\nBoard:%s\nPassing year:%d\nBatch:%s\nDept:%s\n",s.name,s.board,s.pyear,s.batch,s.dept);
                    for(j=0; j<4; j++)
                    {
                        printf("Marks of subject %d: %.2f\n",j+1,s.marks[j]);
                    }
                    printf("Total Marks: %.2f\n\n", s.tmarks);
                }
            }
            fclose(fp);
        }

        else if(h==4)
            main_menu();

        printf("Press any key to continue.");
        getch();
        system("cls");
    }
}

