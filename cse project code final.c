//HEADER FILES
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include<time.h>
//VARIABLE DECLARATION
int residence,plot,address,choice1;
char door[20],street[100],landmark[100],village[100],city[100],appartment[100],pincode[7];
int lv;
char M1[10],P1[10],otp[4],otp1[4];
int choice;
char fname[20],lname[10],email[100],password[20],password1[20],sample_chr;
long long int mobile,mobile1;
int no_lines,i;
int n,j,k,no_lines;
long long int phone,phone1;
char pw1[20],pw2[20],ch;
char str[3];
int payment,month,i,c;
int l;//l is used for storing length of year
int l1;//l1 is used for storing length of cvv
int l2;//l2 is used for storing length of month
long long int mno, number;
char user[50], PW[50], credit[12],debit[12],year[2],cvv[3];
char m1[3];
char s1[5]="none";
char s2[5]="None";
float roc;
char sug_com[200];
long long int M[50];
float R[50];
int num;
time_t t1;
int select,press,A,item,B,C,D,E,F,G,H,I,J,bill;
//FUNCTIONS
void countdata()
{
    FILE *fp;
    fp=fopen("usernames.txt", "a+");
    /*if (fp==NULL)
        printf("error!!!");
    else
        printf("opened!!!");*/
    //get character from file and store in sample_chr
    sample_chr = getc(fp);
    while (sample_chr != EOF) {
        //Count whenever sample_chr is blank (new line) is encountered
        if (sample_chr == '\n')
        {
            //increment variable 'no_lines' by 1
            no_lines=no_lines+1;
        }
        //take next character from file.
        sample_chr = getc(fp);
    }
    fclose(fp);
}
void pwcheck()
{
    FILE *pw;
    pw=fopen("passwords.txt","a+");
    if ((strcmp(password,password1))==0)
    {
        fprintf(pw,"%s\n",password);
        printf("\nYour account is successfully created!! and you are logged-in now!!\n\n");
        printf("Your login credentials for signing-in in the future use are as follows:\n");
        printf("mobile number:%lld\n",mobile);
        printf("password:%s\n",password);
        fclose(pw);
    }
    else
    {
        printf("Passwords do not match!!!\n");
        printf("Please re-enter your password :");
        scanf("%s",&password1);
        pwcheck();
    }
}
void mnocheck()
{

    FILE *user;
    user=fopen("usernames.txt","a+");
    /*if (user==NULL)
        printf("error!!!");
    else
        printf("user opened!\n");*/
    for (i=1;i<=no_lines;i++)
    {
        //printf("entered loop!!!\n");
        fscanf(user,"%lld",&mobile1);
        //printf("%lld\n",mobile1);
        if (mobile==mobile1)
        {
            printf("an account is already registered with this number!!!\n");
            printf("re-enter mobile number:");
            scanf("%lld",&mobile);
            mnocheck();
            break;
        }
        else
        {
            if (i==no_lines)
            {
                fprintf(user,"%lld\n",mobile);
                fclose(user);
                printf("create your password :");
                scanf("%s",&password);
                printf("Re-enter your password :");
                scanf("%s",&password1);
                pwcheck();
            }
            else
            {
                continue;
            }
        }
    }
}
void countdata1()
{
    FILE *fp1;
    fp1=fopen("usernames.txt", "a+");
    //get character from file and store in ch
    ch = getc(fp1);
    while (ch != EOF) {
        //Count whenever ch is blank (new line) is encountered
        if (ch == '\n')
        {
            //increment variable 'no_lines' by 1
            no_lines=no_lines+1;
        }
        //take next character from file.
        ch = getc(fp1);
    }
    fclose(fp1);
}
void pwinputandcheck()
{
    printf("enter your password:");
    scanf("%s",&pw1);
    if ((strcmp(pw1,pw2))==0)
    {
        printf("you logged in successfully!!!\n");
    }
    else
    {
        printf("incorrect password!!!\n");
        printf("re-enter again below:\n");
        pwinputandcheck();
    }
}
void cvvfunc()
{
        printf ("Enter CVV : ");
        scanf ("%s", &cvv);
        l1=strlen(cvv);
        if (l1==3)
        {
            i=0;
            while (i<=2)
            {
                if (i==0)
                {
                    if ((48 <= cvv[i]) && (cvv[i] <= 57))
                    {
                        i=i+1;
                        continue;
                    }
                    else
                    {
                        printf("invalid input of cvv!!!\n");
                        cvvfunc();
                    }
                }
                if (i==1)
                {
                    if ((48 <= cvv[i]) && (cvv[i] <= 57))
                    {
                        i=i+1;
                        continue;
                    }
                    else
                    {
                        printf("invalid input of cvv!!!\n");
                        cvvfunc();
                    }
                }
                if (i==2)
                {
                    if ((48 <= cvv[i]) && (cvv[i] <= 57))
                    {

                        break;
                    }
                    else
                    {
                        printf("invalid input of cvv!!!\n");
                        cvvfunc();
                    }
                }
            }
        }
        else
        {
            printf("invalid input of cvv!!!\n");
            cvvfunc();
        }
}
void expiryyear()
{
        printf ("Enter the year(in YY format) : ");
        scanf ("%s", &year);
        l=strlen(year);
        if (l==2)
        {
            i=0;
            while (i<=1)
            {
                if (i==0)
                {
                    if ((48 <= year[i]) && (year[i] <= 57))
                    {
                        i=i+1;
                        continue;
                    }
                    else
                    {
                        printf("invalid input of year!!!\n");
                        expiryyear();
                    }
                }
                if (i==1)
                {
                    if ((48 <= year[i]) && (year[i] <= 57))
                    {
                        cvvfunc();

                    }
                    else
                    {
                        printf("invalid input of year!!!\n");
                        expiryyear();
                    }
                }
            }

        }
        else
        {
            printf("invalid input of year!!!\n");
            expiryyear();

        }

}
void expirydate()
{
                printf ("Enter the expiry date\n");
                printf ("Enter the month(in MM format) : ");
                scanf ("%s", &m1);
                strcpy(str,m1);
                month=atoi(str);
                l2=strlen(m1);
                if ((1<=month) && (month<=12) && (l2==2) )
                {

                    expiryyear();

                }
                else
                {
                    printf("invalid input of month!!!\n");
                    expirydate();

                }
}
//item selectoin
void restaurants()
{
    printf("1.Sweet Magic\n2.Cross Roads\n3.Little Village\n4.Our Place\n5.Southern Spice\n6.Andhra spice\n");
    printf("7.Barkaas\n8.woods\n9.Minerva Grand\n10.Rusted Spoon\n");
    printf("\n  \n");
}
void items()
{
    switch(select)
    {
        case 1: printf("Sweet Magic\n");
                printf("1.Idly -- Rs.40\n2.Upma -- Rs.45\n3.Pongali -- Rs.65\n4.Poori -- Rs.65\n5.Vada -- Rs.65\n");
                printf("6.Veg Manchurian -- Rs.180\n7.Gobi Manchurian -- Rs.170\n8.Veg Spring Rolls -- Rs.170\n");
                printf("9.Alu-65 -- Rs.170\n10.Chilli baby corn -- Rs.200\n11.Andhra Meals -- Rs.250\n12.Veg Biryani -- Rs.230\n");
                printf("\n \n");
                break;
        case 2: printf("Cross Roads\n");
                printf("1.Dosa -- Rs.60\n2.Onion Dosa -- Rs.75\n3.Raagi Dosa -- Rs.75\n4.Pullattu -- Rs.90\n5.Pesarattu -- Rs.70\n");
                printf("6.Upma Dosa -- Rs.85\n7.Chicken Keema Dosa -- Rs.160\n8.Veg corn soup -- Rs.100\n9.Veg noodle soup -- Rs.120\n");
                printf("10.Chicken corn soup -- Rs.130\n11.Paneer Biryani -- Rs.250\n12.Mushroom Biryani -- Rs.270\n");
                printf("13.Kashmiri pulav -- Rs.250\n");
                printf("\n \n");
                break;
        case 3: printf("Little Village\n");
                printf("1.Chicken Machow soup -- Rs.130\n2.Chicken Bone soup -- Rs.140\n3.Chicken spring rolls -- Rs.250\n");
                printf("4.Chilli Chicken -- Rs.250\n5.Chicken-65 -- Rs.260\n6.Ginger Chicken -- Rs.280\n7.Chicken Wings -- Rs.280\n");
                printf("8.Pepper Chicken -- Rs.250\n9.Chicken Dum Biryani -- Rs.300\n10.Chicken fry Biryani -- Rs.300\n");
                printf("11.Joint Biryani -- Rs.290\n12.Natukodi Biryani -- Rs.300\n13.Spl.Chicken Biryani -- Rs.290\n14.Tandoori Chicken Biryani -- Rs.300\n");
                printf("\n \n");
                break;
        case 4: printf("Our Place\n");
                printf("1.Pulka -- Rs.25\n2.Butter Naan -- Rs.40\n3.Roti -- Rs.40\n4.Plain Palak -- Rs.190\n5.Methi Chaman -- Rs.180\n");
                printf("6.Malai Kofta -- Rs.230\n7.Stuffed Capsicum -- Rs.220\n8.Veg Schezwan -- Rs.160\n9.Butter Chicken -- Rs.280\n");
                printf("10.Spl Chicken curry -- Rs.280\n11.Mutton Dum Biryani -- Rs.350\n12.Mutton Fry Biryani -- Rs.320\n");
                printf("13.Prawn Biryani -- Rs.320\n14.Spl Prawn Biryani -- Rs.320\n");
                printf("\n \n");
                break;
        case 5: printf("Southern Spice\n");
                printf("1.Chicken Tikka Biryani -- Rs.320\n2.Veg Fried Rice -- Rs.200\n3.Shezwan Fried Rice -- Rs.220\n");
                printf("4.Spl Veg Fried Rice -- Rs.240\n5.Egg Fried Rice -- Rs.210\n6.Chicken Fried Rice -- Rs.250\n");
                printf("7.Mixed Fried Rice -- Rs.280\n8.Spl.Chicken Fried Rice -- Rs.270\n9.Prawns Fried Rice -- Rs.290\n");
                printf("10.Spl.Prawns Fried Rice -- Rs.310\n");
                printf("\n \n");
                break;
        case 6: printf("Andhra spice\n");
                printf("1.Mutton Fried Rice -- Rs.320\n2.Baby corn Fried Rice -- Rs.220\n3.Mushroom Fried Rice -- Rs.220\n");
                printf("4.Ginger Chicken Fried Rice -- Rs.280\n5.Zeera Rice -- Rs.210\n6.Veg Noodles -- Rs.200\n7.Egg Noodles -- Rs.210\n");
                printf("8.Chicken Noodles -- Rs.240\n9.Malai paneer Veg Biryani -- Rs.270\n10.Avakai Biryani -- Rs.250\n");
                printf("\n \n");
                break;
        case 7: printf("Barkaas\n");
                printf("1.Fries & Veg Mandi -- Rs.690\n2.Spl Veg Mandi -- Rs.670\n3.Egg Mandi -- Rs.670\n4.Chicken BBQ Mandi -- Rs.830\n");
                printf("5.Chicken Wings Mandi -- Rs.850\n6.Chicken Fahm Mandi -- Rs.830\n7.Chicken Steak Mandi -- Rs.840\n8.Classic Chicken Mandi -- Rs.900\n");
                printf("9.Prawn Mandi -- Rs.940\n10.Arabian Fish Mandi -- Rs.940\n");
                printf("\n \n");
                break;
        case 8: printf("woods\n");
                printf("1.Chicken 555 -- Rs.270\n2.Chocolate Shake -- Rs.140\n3.Vanilla Shake -- Rs.140\n4.ButterScotch Shake -- Rs.140\n");
                printf("5.Cold Coffee Chocolate -- Rs.140\n6.Virgin Mojito -- Rs.90\n7.Mint Lemonade -- Rs.90\n8.Blue Ocean -- Rs.110\n");
                printf("9.Chicken Dum Biryani  -- Rs.250\n10.Mutton Keema Biryani -- Rs.350\n");
                printf("\n \n");
                break;
        case 9: printf("Minerva Grand\n");
                printf("1.Chicken Pizza -- Rs.350\n2.Paneer Pizza -- Rs.250\n3.Chicken Burger -- Rs.250\n4.Sambar Idly -- Rs.150\n");
                printf("5.Sambar Vada -- Rs.150\n6.Sandwich -- Rs.190\n7.MLA Dosa -- Rs.260\n8.Pizza -- Rs.170\n9.Burger -- Rs.150\n10.Paneer Burger -- Rs.220\n");
                printf("\n \n");
                break;
        case 10: printf("Rusted Spoon\n");
                printf("1.Mutton Maharani -- Rs.330\n2.Mutton Keema curry -- Rs.330\n3.Mutton Roghan Josh -- Rs.350\n");
                printf("4.Mutton Sagawala -- Rs.320\n5.Mutton Mughalai -- Rs.350\n6.Mutton manpasand -- Rs.330\n");
                printf("7.Butter prawns -- Rs.300\n8.Kadai Prawns -- Rs.310\n9.Prawn Masala -- Rs.310\n10.Fish Fry -- Rs.300\n");
                printf("\n \n");
                break;
        default:while(select<=0||select>10)
                {
                    printf("select only the given below restaurants\n");
                    restaurants();
                    printf("Select a restaurant :");
                    scanf("%d",&select);
                    switch(select)
                    {
                        case 1: printf("Sweet Magic\n");
                                printf("1.Idly -- Rs.40\n2.Upma -- Rs.45\n3.Pongali -- Rs.65\n4.Poori -- Rs.65\n5.Vada -- Rs.65\n");
                                printf("6.Veg Manchurian -- Rs.180\n7.Gobi Manchurian -- Rs.170\n8.Veg Spring Rolls -- Rs.170\n");
                                printf("9.Alu-65 -- Rs.170\n10.Chilli baby corn -- Rs.200\n11.Andhra Meals -- Rs.250\n12.Veg Biryani -- Rs.230\n");
                                printf("\n \n");
                                break;
                        case 2: printf("Cross Roads\n");
                                printf("1.Dosa -- Rs.60\n2.Onion Dosa -- Rs.75\n3.Raagi Dosa -- Rs.75\n4.Pullattu -- Rs.90\n5.Pesarattu -- Rs.70\n");
                                printf("6.Upma Dosa -- Rs.85\n7.Chicken Keema Dosa -- Rs.160\n8.Veg corn soup -- Rs.100\n9.Veg noodle soup -- Rs.120\n");
                                printf("10.Chicken corn soup -- Rs.130\n11.Paneer Biryani -- Rs.250\n12.Mushroom Biryani -- Rs.270\n");
                                printf("13.Kashmiri pulav -- Rs.250\n");
                                printf("\n \n");
                                break;
                        case 3: printf("Little Village\n");
                                printf("1.Chicken Machow soup -- Rs.130\n2.Chicken Bone soup -- Rs.140\n3.Chicken spring rolls -- Rs.250\n");
                                printf("4.Chilli Chicken -- Rs.250\n5.Chicken-65 -- Rs.260\n6.Ginger Chicken -- Rs.280\n7.Chicken Wings -- Rs.280\n");
                                printf("8.Pepper Chicken -- Rs.250\n9.Chicken Dum Biryani -- Rs.300\n10.Chicken fry Biryani -- Rs.300\n");
                                printf("11.Joint Biryani -- Rs.290\n12.Natukodi Biryani -- Rs.300\n13.Spl.Chicken Biryani -- Rs.290\n14.Tandoori Chicken Biryani -- Rs.300\n");
                                printf("\n \n");
                                break;
                        case 4: printf("Our Place\n");
                                printf("1.Pulka -- Rs.25\n2.Butter Naan -- Rs.40\n3.Roti -- Rs.40\n4.Plain Palak -- Rs.190\n5.Methi Chaman -- Rs.180\n");
                                printf("6.Malai Kofta -- Rs.230\n7.Stuffed Capsicum -- Rs.220\n8.Veg Schezwan -- Rs.160\n9.Butter Chicken -- Rs.280\n");
                                printf("10.Spl Chicken curry -- Rs.280\n11.Mutton Dum Biryani -- Rs.350\n12.Mutton Fry Biryani -- Rs.320\n");
                                printf("13.Prawn Biryani -- Rs.320\n14.Spl Prawn Biryani -- Rs.320\n");
                                printf("\n \n");
                                break;
                        case 5: printf("Southern Spice\n");
                                printf("1.Chicken Tikka Biryani -- Rs.320\n2.Veg Fried Rice -- Rs.200\n3.Shezwan Fried Rice -- Rs.220\n");
                                printf("4.Spl Veg Fried Rice -- Rs.240\n5.Egg Fried Rice -- Rs.210\n6.Chicken Fried Rice -- Rs.250\n");
                                printf("7.Mixed Fried Rice -- Rs.280\n8.Spl.Chicken Fried Rice -- Rs.270\n9.Prawns Fried Rice -- Rs.290\n");
                                printf("10.Spl.Prawns Fried Rice -- Rs.310\n");
                                printf("\n \n");
                                break;
                        case 6: printf("Andhra spice\n");
                                printf("1.Mutton Fried Rice -- Rs.320\n2.Baby corn Fried Rice -- Rs.220\n3.Mushroom Fried Rice -- Rs.220\n");
                                printf("4.Ginger Chicken Fried Rice -- Rs.280\n5.Zeera Rice -- Rs.210\n6.Veg Noodles -- Rs.200\n7.Egg Noodles -- Rs.210\n");
                                printf("8.Chicken Noodles -- Rs.240\n9.Malai paneer Veg Biryani -- Rs.270\n10.Avakai Biryani -- Rs.250\n");
                                printf("\n \n");
                                break;
                        case 7: printf("Barkaas\n");
                                printf("1.Fries & Veg Mandi -- Rs.690\n2.Spl Veg Mandi -- Rs.670\n3.Egg Mandi -- Rs.670\n4.Chicken BBQ Mandi -- Rs.830\n");
                                printf("5.Chicken Wings Mandi -- Rs.850\n6.Chicken Fahm Mandi -- Rs.830\n7.Chicken Steak Mandi -- Rs.840\n8.Classic Chicken Mandi -- Rs.900\n");
                                printf("9.Prawn Mandi -- Rs.940\n10.Arabian Fish Mandi -- Rs.940\n");
                                printf("\n \n");
                                break;
                        case 8: printf("woods\n");
                                printf("1.Chicken 555 -- Rs.270\n2.Chocolate Shake -- Rs.140\n3.Vanilla Shake -- Rs.140\n4.ButterScotch Shake -- Rs.140\n");
                                printf("5.Cold Coffee Chocolate -- Rs.140\n6.Virgin Mojito -- Rs.90\n7.Mint Lemonade -- Rs.90\n8.Blue Ocean -- Rs.110\n");
                                printf("9.Chicken Dum Biryani  -- Rs.250\n10.Mutton Keema Biryani -- Rs.350\n");
                                printf("\n \n");
                                break;
                        case 9: printf("Minerva Grand\n");
                                printf("1.Chicken Pizza -- Rs.350\n2.Paneer Pizza -- Rs.250\n3.Chicken Burger -- Rs.250\n4.Sambar Idly -- Rs.150\n");
                                printf("5.Sambar Vada -- Rs.150\n6.Sandwich -- Rs.190\n7.MLA Dosa -- Rs.260\n8.Pizza -- Rs.170\n9.Burger -- Rs.150\n10.Paneer Burger -- Rs.220\n");
                                printf("\n \n");
                                break;
                        case 10: printf("Rusted Spoon\n");
                                 printf("1.Mutton Maharani -- Rs.330\n2.Mutton Keema curry -- Rs.330\n3.Mutton Roghan Josh -- Rs.350\n");
                                 printf("4.Mutton Sagawala -- Rs.320\n5.Mutton Mughalai -- Rs.350\n6.Mutton manpasand -- Rs.330\n");
                                 printf("7.Butter prawns -- Rs.300\n8.Kadai Prawns -- Rs.310\n9.Prawn Masala -- Rs.310\n10.Fish Fry -- Rs.300\n");
                                 printf("\n \n");
                                 break;
                    }
                }
    }
}
void sweetmagic()
{

                    printf("1.Idly -- Rs.40\n2.Upma -- Rs.45\n3.Pongali -- Rs.65\n4.Poori -- Rs.65\n5.Vada -- Rs.65\n");
                    printf("6.Veg Manchurian -- Rs.180\n7.Gobi Manchurian -- Rs.170\n8.Veg Spring Rolls -- Rs.170\n");
                    printf("9.Alu-65 -- Rs.170\n10.Chilli baby corn -- Rs.200\n11.Andhra Meals -- Rs.250\n12.Veg Biryani -- Rs.230\n");
                    printf("\n");
}
void sweetmagicitems()
{
      switch(A)
      {
            case 1: printf("Idly -- Rs.40");
                    bill = bill + 40;
                    break;
            case 2: printf("Upma -- Rs.45");
                    bill = bill + 45;
                    break;
            case 3: printf("Pongali -- Rs.65");
                    bill = bill + 65;
                    break;
            case 4: printf("Poori -- Rs.65");
                    bill = bill + 65;
                    break;
           case 5:  printf("Vada -- Rs.65");
                    bill = bill + 65;
                    break;
            case 6: printf("Veg Manchurian -- Rs.180");
                    bill = bill + 180;
                    break;
            case 7: printf("Gobi Manchurian -- Rs.170");
                    bill = bill + 170;
                    break;
            case 8: printf("Veg Spring Rolls -- Rs.170");
                    bill = bill + 170;
                    break;
            case 9: printf("Alu-65 -- Rs.170");
                    bill = bill + 170;
                    break;
            case 10: printf("Chilli baby corn -- Rs.200");
                     bill = bill + 200;
                    break;
            case 11: printf("Andhra Meals -- Rs.250");
                    bill = bill + 250;
                    break;
            case 12: printf("Veg Biryani -- Rs.230");
                    bill = bill + 230;
                    break;
                    }
}
void crossroads()
{
                    printf("1.Dosa -- Rs.60\n2.Onion Dosa -- Rs.75\n3.Raagi Dosa -- Rs.75\n4.Pullattu -- Rs.90\n5.Pesarattu -- Rs.70\n");
                    printf("6.Upma Dosa -- Rs.85\n7.Chicken Keema Dosa -- Rs.160\n8.Veg corn soup -- Rs.100\n9.Veg noodle soup -- Rs.120\n");
                    printf("10.Chicken corn soup -- Rs.130\n11.Paneer Biryani -- Rs.250\n12.Mushroom Biryani -- Rs.270\n");
                    printf("13.Kashmiri pulav -- Rs.250\n");
                    printf("\n");
}
void crossroadsitems()
{
                        switch(B)
                    {
                        case 1: printf("Dosa -- Rs.60");
                                bill = bill + 60;
                                break;
                        case 2: printf("Onion Dosa -- Rs.75");
                                bill = bill + 75;
                                break;
                        case 3: printf("Raagi Dosa -- Rs.75");
                                bill = bill + 75;
                                break;
                        case 4: printf("Pullattu -- Rs.90");
                                bill = bill + 90;
                                break;
                        case 5: printf("Pesarattu -- Rs.70");
                                bill = bill + 70;
                                break;
                        case 6: printf("Upma Dosa -- Rs.85");
                                bill = bill + 85;
                                break;
                        case 7: printf("Chicken Keema Dosa -- Rs.160");
                                bill = bill + 160;
                                break;
                        case 8: printf("Veg corn soup -- Rs.100");
                                bill = bill + 100;
                                break;
                        case 9: printf("Veg noodle soup -- Rs.120");
                                bill = bill + 120;
                                break;
                        case 10: printf("Chicken corn soup -- Rs.130");
                                bill = bill + 130;
                                break;
                        case 11: printf("Paneer Biryani -- Rs.250");
                                 bill = bill + 250;
                                 break;
                        case 12: printf("Mushroom Biryani -- Rs.270");
                                bill = bill + 270;
                                break;
                        case 13: printf("Kashmiri pulav -- Rs.250");
                                bill = bill + 250;
                                break;
                    }
}
void littlevillage()
{
    printf("1.Chicken Machow soup -- Rs.130\n2.Chicken Bone soup -- Rs.140\n3.Chicken spring rolls -- Rs.250\n");
    printf("4.Chilli Chicken -- Rs.250\n5.Chicken-65 -- Rs.260\n6.Ginger Chicken -- Rs.280\n7.Ginger Chicken -- Rs.280\n");
    printf("8.Pepper Chicken -- Rs.250\n9.Chicken Dum Biryani -- Rs.300\n10.Chicken fry Biryani -- Rs.300\n");
    printf("11.Joint Biryani -- Rs.290\n12.Natukodi Biryani -- Rs.300\n13.Spl.Chicken Biryani -- Rs.290\n14.Tandoori Chicken Biryani -- Rs.300\n");
    printf("\n");
}
void littlevillageitems()
{
    switch(C)
    {
            case 1: printf("Chicken Machow soup -- Rs.130");
                    bill = bill + 130;
                    break;
            case 2: printf("Chicken Bone soup -- Rs.140");
                    bill = bill + 140;
                    break;
            case 3: printf("Chicken spring rolls -- Rs.250");
                    bill = bill + 250;
                    break;
            case 4: printf("Chilli Chicken -- Rs.250");
                    bill = bill + 250;
                    break;
            case 5: printf("Chicken-65 -- Rs.260");
                    bill = bill + 260;
                     break;
            case 6: printf("Ginger Chicken -- Rs.280");
                    bill = bill + 280;
                    break;
            case 7: printf("Ginger Chicken -- Rs.280");
                    bill = bill + 280;
                    break;
            case 8: printf("Pepper Chicken -- Rs.250");
                    bill = bill + 250;
                    break;
            case 9: printf("Chicken Dum Biryani -- Rs.300");
                    bill = bill + 300;
                    break;
            case 10: printf("Chicken fry Biryani -- Rs.300");
                     bill = bill + 300;
                     break;
            case 11: printf("Joint Biryani -- Rs.290");
                     bill = bill + 290;
                     break;
            case 12: printf("Mushroom Biryani -- Rs.270");
                     bill = bill + 270;
                     break;
            case 13: printf("Natukodi Biryani -- Rs.300");
                     bill = bill + 300;
                     break;
            case 14: printf("Tandoori Chicken Biryani -- Rs.300");
                     bill = bill + 300;
                     break;
    }
}
void ourplace()
{
                    printf("1.Pulka -- Rs.25\n2.Butter Naan -- Rs.40\n3.Roti -- Rs.40\n4.Plain Palak -- Rs.190\n5.Methi Chaman -- Rs.180\n");
                    printf("6.Malai Kofta -- Rs.230\n7.Stuffed Capsicum -- Rs.220\n8.Veg Schezwan -- Rs.160\n9.Butter Chicken -- Rs.280\n");
                    printf("10.Spl Chicken curry -- Rs.280\n11.Mutton Dum Biryani -- Rs.350\n12.Mutton Fry Biryani -- Rs.320\n");
                    printf("13.Prawn Biryani -- Rs.320\n14.Spl Prawn Biryani -- Rs.350\n");
                    printf("\n");
}
void ourplaceitems()
{
                        switch(D)
                    {
                                case 1: printf("Pulka -- Rs.25");
                                        bill = bill + 25;
                                        break;
                                case 2: printf("Butter Naan -- Rs.40");
                                        bill = bill + 40;
                                        break;
                                case 3: printf("Roti -- Rs.40");
                                        bill = bill + 40;
                                        break;
                                case 4: printf("Plain Palak -- Rs.190");
                                        bill = bill + 190;
                                        break;
                                case 5: printf("Methi Chaman -- Rs.180");
                                        bill = bill + 180;
                                        break;
                                case 6: printf("Malai Kofta -- Rs.230");
                                        bill = bill + 230;
                                        break;
                                case 7: printf("Stuffed Capsicum -- Rs.220");
                                        bill = bill + 220;
                                        break;
                                case 8: printf("Veg Schezwan -- Rs.160");
                                        bill = bill + 160;
                                        break;
                                case 9: printf("Butter Chicken -- Rs.280");
                                        bill = bill + 280;
                                        break;
                                case 10: printf("Spl Chicken curry -- Rs.280");
                                         bill = bill + 280;
                                         break;
                                case 11: printf("Mutton Dum Biryani -- Rs.350");
                                         bill = bill + 350;
                                         break;
                                case 12: printf("Mutton Fry Biryani -- Rs.320");
                                         bill = bill + 320;
                                         break;
                                case 13: printf("Prawn Biryani -- Rs.320");
                                         bill = bill + 320;
                                         break;
                                case 14: printf("Spl Prawn Biryani -- Rs.350");
                                         bill = bill + 350;
                                         break;
                          }
}
void southernspice()
{
                   printf("1.Chicken Tikka Biryani -- Rs.320\n2.Veg Fried Rice -- Rs.200\n3.Shezwan Fried Rice -- Rs.220\n");
                    printf("4.Spl Veg Fried Rice -- Rs.240\n5.Egg Fried Rice -- Rs.210\n6.Chicken Fried Rice -- Rs.250\n");
                    printf("7.Mixed Fried Rice -- Rs.280\n8.Spl.Chicken Fried Rice -- Rs.270\n9.Prawns Fried Rice -- Rs.290\n");
                    printf("10.Spl.Prawns Fried Rice -- Rs.310\n");
                    printf("\n");
}
void southernspiceitems()
{
  switch(E)
 {
     case 1: printf("Chicken Tikka Biryani -- Rs.320");
             bill = bill + 320;
             break;
     case 2: printf("Veg Fried Rice -- Rs.200");
             bill = bill + 200;
             break;
     case 3: printf("Shezwan Fried Rice -- Rs.220");
             bill = bill + 220;
             break;
     case 4: printf("Spl Veg Fried Rice -- Rs.240");
             bill = bill + 240;
             break;
     case 5: printf("Egg Fried Rice -- Rs.210");
             bill = bill + 210;
             break;
     case 6: printf("Chicken Fried Rice -- Rs.250");
             bill = bill + 250;
             break;
     case 7: printf("Mixed Fried Rice -- Rs.280");
             bill = bill + 280;
             break;
     case 8: printf("Spl.Chicken Fried Rice -- Rs.270");
             bill = bill + 270;
             break;
     case 9: printf("Prawns Fried Rice -- Rs.290");
             bill = bill + 290;
             break;
     case 10: printf("Spl.Prawns Fried Rice -- Rs.310");
              bill = bill + 310;
              break;
    }
}
void andhraspice()
{
       printf("1.Mutton Fried Rice -- Rs.320\n2.Baby corn Fried Rice -- Rs.220\n3.Mushroom Fried Rice -- Rs.220\n");
       printf("4.Ginger Chicken Fried Rice -- Rs.280\n5.Zeera Rice -- Rs.210\n6.Veg Noodles -- Rs.200\n7.Egg Noodles -- Rs.210\n");
       printf("8.Chicken Noodles -- Rs.240\n9.Malai paneer Veg Biryani -- Rs.270\n10.Avakai Biryani -- Rs.250\n");
       printf("\n");
}
void andhraspiceitems()
{
   switch(F)
   {
        case 1: printf("Mutton Fried Rice -- Rs.320");
                bill = bill + 320;
                break;
        case 2: printf(".Baby corn Fried Rice -- Rs.220");
                bill = bill + 220;
                break;
        case 3: printf("Mushroom Fried Rice -- Rs.220");
                bill = bill + 220;
                break;
        case 4: printf("Ginger Chicken Fried Rice -- Rs.280");
                bill = bill + 280;
                break;
        case 5: printf("Zeera Rice -- Rs.210");
                bill = bill + 210;
                break;
        case 6: printf("Veg Noodles -- Rs.200");
                bill = bill + 200;
                break;
        case 7: printf("Egg Noodles -- Rs.210");
                bill = bill + 210;
                break;
        case 8: printf("Chicken Noodles -- Rs.240");
                bill = bill + 240;
                break;
        case 9: printf("Malai paneer Veg Biryani -- Rs.270");
                bill = bill + 270;
                break;
        case 10: printf("Avakai Biryani -- Rs.250");
                 bill = bill + 250;
                 break;
    }
}
void barkaas()
{
        printf("1.Fries & Veg Mandi -- Rs.690\n2.Spl Veg Mandi -- Rs.670\n3.Egg Mandi -- Rs.670\n4.Chicken BBQ Mandi -- Rs.830\n");
        printf("5.Chicken Wings Mandi -- Rs.850\n6.Chicken Fahm Mandi -- Rs.830\n7.Chicken Steak Mandi -- Rs.840\n8.Classic Chicken Mandi -- Rs.900\n");
        printf("9.Prawn Mandi -- Rs.940\n10.Arabian Fish Mandi -- Rs.940\n");
        printf("\n");
}
void barkaasitems()
{
 switch(G)
{
    case 1: printf("Fries & Veg Mandi -- Rs.690");
            bill = bill + 690;
            break;
    case 2: printf("Spl Veg Mandi -- Rs.670");
            bill = bill + 670;
            break;
    case 3: printf("Egg Mandi -- Rs.670");
            bill = bill + 670;
            break;
    case 4: printf("Chicken BBQ Mandi -- Rs.830");
            bill = bill + 830;
            break;
    case 5: printf("Chicken Wings Mandi -- Rs.850");
            bill = bill + 850;
            break;
    case 6: printf("Chicken Fahm Mandi -- Rs.830");
            bill = bill + 830;
            break;
    case 7: printf("Chicken Steak Mandi -- Rs.840");
            bill = bill + 840;
            break;
   case 8:  printf("Classic Chicken Mandi -- Rs.900");
            bill = bill + 900;
            break;
    case 9: printf("Prawn Mandi -- Rs.940");
            bill = bill + 940;
            break;
    case 10: printf("Arabian Fish Mandi -- Rs.940");
            bill = bill + 940;
            break;
    }
}
void woods()
{
    printf("1.Chicken 555 -- Rs.270\n2.Chocolate Shake -- Rs.140\n3.Vanilla Shake -- Rs.140\n4.ButterScotch Shake -- Rs.140\n");
    printf("5.Cold Coffee Chocolate -- Rs.140\n6.Virgin Mojito -- Rs.90\n7.Mint Lemonade -- Rs.90\n8.Blue Ocean -- Rs.110\n");
    printf("9.Chicken Dum Biryani  -- Rs.250\n10.Mutton Keema Biryani -- Rs.350\n");
    printf("\n");
}
void woodsitems()
{
    switch(H)
   {
        case 1: printf("Chicken 555 -- Rs.270");
                bill = bill + 270;
                break;
         case 2: printf("Chocolate Shake -- Rs.140");
                 bill = bill + 140;
                 break;
         case 3: printf("Vanilla Shake -- Rs.140");
                 bill = bill + 140;
                 break;
         case 4: printf("ButterScotch Shake -- Rs.140");
                 bill = bill + 140;
                 break;
         case 5: printf("Cold Coffee Chocolate -- Rs.140");
                 bill = bill + 140;
                 break;
         case 6: printf("Virgin Mojito -- Rs.90");
                 bill = bill + 90;
                 break;
         case 7: printf("Mint Lemonade -- Rs.90");
                 bill = bill + 90;
                 break;
         case 8: printf("Blue Ocean -- Rs.110");
                 bill = bill + 110;
                 break;
         case 9: printf("Chicken Dum Biryani  -- Rs.250");
                 bill = bill + 250;
                 break;
         case 10: printf("Mutton Keema Biryani -- Rs.350");
                  bill = bill + 350;
                  break;
    }
}
void minervagrand()
{
    printf("1.Chicken Pizza -- Rs.350\n2.Paneer Pizza -- Rs.250\n3.Chicken Burger -- Rs.250\n4.Sambar Idly -- Rs.150\n");
    printf("5.Sambar Vada -- Rs.150\n6.Sandwich -- Rs.190\n7.MLA Dosa -- Rs.260\n8.Pizza -- Rs.170\n9.Burger -- Rs.150\n10.Paneer Burger -- Rs.220\n");
    printf("\n");
}
void minervagranditems()
{
    switch(I)
    {
        case 1: printf("Chicken Pizza -- Rs.350");
                bill = bill + 350;
                break;
        case 2: printf("Paneer Pizza -- Rs.250");
                bill = bill + 250;
                break;
        case 3: printf("Chicken Burger -- Rs.250");
                bill = bill + 250;
                break;
        case 4: printf("Sambar Idly -- Rs.150");
                bill = bill + 150;
                break;
        case 5: printf("Sambar Vada -- Rs.150");
                bill = bill + 150;
                break;
        case 6: printf("Sandwich -- Rs.190");
                bill = bill + 190;
                break;
        case 7: printf("MLA Dosa -- Rs.260");
                bill = bill + 260;
                break;
        case 8: printf("Pizza -- Rs.170");
                bill = bill + 170;
                break;
        case 9: printf("Burger -- Rs.150");
                bill = bill + 150;
                break;
        case 10: printf("Paneer Burger -- Rs.220");
                 bill = bill + 220;
                 break;
    }
}
void rustedspoon()
{
    printf("1.Mutton Maharani -- Rs.330\n2.Mutton Keema curry -- Rs.330\n3.Mutton Roghan Josh -- Rs.350\n");
    printf("4.Mutton Sagawala -- Rs.320\n5.Mutton Mughalai -- Rs.350\n6.Mutton manpasand -- Rs.330\n");
    printf("7.Butter prawns -- Rs.300\n8.Kadai Prawns -- Rs.310\n9.Prawn Masala -- Rs.310\n10.Fish Fry -- Rs.300\n");
    printf("\n");
}
void rustedspoonitems()
{
    switch(J)
    {
         case 1: printf("Mutton Maharani -- Rs.330");
                 bill = bill + 330;
                 break;
         case 2: printf("Mutton Keema curry -- Rs.330");
                 bill = bill + 330;
                 break;
         case 3: printf("Mutton Roghan Josh -- Rs.350");
                 bill = bill + 350;
                 break;
         case 4: printf("Mutton Sagawala -- Rs.320");
                 bill = bill + 320;
                 break;
         case 5: printf("Mutton Mughalai -- Rs.350");
                 bill = bill + 350;
                 break;
         case 6: printf("Mutton manpasand -- Rs.330");
                 bill = bill + 330;
                 break;
         case 7: printf("Butter prawns -- Rs.300");
                 bill = bill + 300;
                 break;
         case 8: printf("Kadai Prawns -- Rs.310");
                 bill = bill + 310;
                 break;
         case 9: printf("Prawn Masala -- Rs.310");
                 bill = bill + 310;
                 break;
         case 10: printf("Fish Fry -- Rs.300");
                  bill = bill + 300;
                  break;
    }
}

//ANY FUNCTIONS IF NEED TO BE ADDED

//MAIN CODE
int main()
{
    //*******************************START OF THE ORDER*******************************************
    //ask sign-in/sign-up
    printf("****************WELCOME TO ABC FOOD ORDERING SYSTEM******************\n");
    printf("Do you want to sign up or sign in\n");
    printf("Enter '1' for sign up\n");
    printf("Enter '2' for sign in\n");
    printf("Enter your choice :");
    scanf("%c",&choice);
    switch(choice)
    {
        case '1'://SIGN-UP
        printf("---------------------SIGN UP-----------------------\n");
        countdata();
        printf("signup is required to start\n");
        printf("enter your first-name :");
        scanf("%s",&fname);
        printf("enter your last-name :");
        scanf("%s",&lname);
        printf("Enter your city :");
        scanf("%s",&city);
        printf("Enter your E-mail id :");
        scanf("%s",&email);



        printf("enter your mobile number(note that this number is to be given for sign-in in future use) :");
        scanf("%lld",&mobile);


        FILE *user;
        user=fopen("usernames.txt", "a+");

        mnocheck();
        break;

        case '2'://SIGN-IN
        printf("---------------------SIGN IN-----------------------\n");
        countdata1();
        FILE *user1;
        user1=fopen("usernames.txt","a+");
        FILE *pw123;
        pw123=fopen("passwords.txt","a+");
        printf("enter your mobile number:");
        scanf("%lld",&phone);
        for (j=1;j<=no_lines;j++)
        {
            fscanf(user1,"%lld",&phone1);
            if (phone==phone1)
            {
                n=j;

                for (k=1;k<=n;k++)
                {
                   fscanf(pw123,"%s",&pw2);
                }
                pwinputandcheck(pw2);
                break;
            }
            else
            {
                if (j==no_lines)
                {
                    printf("no account is registered with the entered mobile number!!!\n");
                    exit(0);
                }

                else
                    {
                        continue;
                    }


            }
        }
        break;

        default:printf("you entered an invalid number");
        exit(0);
    }

    //LIST OF RESTAURANTS AND MENU
    //ITEMS SELECTION
    printf("\n----------------------LIST OF RESTAURANTS AND ITEM SELECTION------------------------\n");
    restaurants();
    printf("Select a restaurant :");
    scanf("%d",&select);
    printf("\n");
    items();
    printf("Press '1' to continue with this restaurant\nPress '2' to go with another restaurant\n");

    scanf("%d",&press);
    printf("\n");
    if(press == 1)
    {
        printf("Finally you have selected ");
        printf("%d",select);
        switch(select)
        {
            case 1: printf("Sweet Magic\n");
                    sweetmagic();
                    printf("select the items :");
                    scanf("%d",&A);
                    sweetmagicitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                             sweetmagic();
                             printf("select the items :");
                             scanf("%d",&A);
                             sweetmagicitems();
                             printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                printf("The total bill to be paid is Rs.%d",bill);
                            }

                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 2: printf("Cross Roads\n");
                    crossroads();
                    printf("select the items :");
                    scanf("%d",&B);
                    crossroadsitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            crossroads();
                            printf("select the items :");
                            scanf("%d",&B);
                            crossroadsitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                           {
                               printf("The total bill to be paid is Rs.%d",bill);
                            }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 3: printf("Little Village\n");
                    littlevillage();
                    printf("select the items :");
                    scanf("%d",&C);
                    littlevillageitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            littlevillage();
                            printf("select the items :");
                            scanf("%d",&C);
                            littlevillageitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                  printf("The total bill to be paid is Rs.%d",bill);
                            }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 4: printf("Our Place\n");
                    ourplace();
                    printf("select the items :");
                    scanf("%d",&D);
                    ourplaceitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            ourplace();
                            printf("select the items :");
                            scanf("%d",&D);
                            ourplaceitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                 printf("The total bill to be paid is Rs.%d",bill);
                            }
                         }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 5: printf("Southern Spice\n");
                    southernspice();
                    printf("select the items :");
                    scanf("%d",&E);
                    southernspiceitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            southernspice();
                            printf("select the items :");
                            scanf("%d",&E);
                            southernspiceitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                 printf("The total bill to be paid is Rs.%d",bill);
                            }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 6: printf("Andhra spice\n");
                    andhraspice();
                    printf("select the items :");
                    scanf("%d",&F);
                    andhraspiceitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            andhraspice();
                            printf("select the items :");
                            scanf("%d",&F);
                            andhraspiceitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                           if(item!=1)
                          {
                              printf("The total bill to be paid is Rs.%d",bill);
                          }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 7: printf("Barkaas\n");
                    barkaas();
                    printf("select the items :");
                    scanf("%d",&G);
                    barkaasitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                           barkaas();
                            printf("select the items :");
                            scanf("%d",&F);
                            barkaasitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                           {
                                printf("The total bill to be paid is Rs.%d",bill);
                           }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 8: printf("woods\n");
                    woods();
                    printf("select the items :");
                    scanf("%d",&H);
                    woodsitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            woods();
                            printf("select the items :");
                            scanf("%d",&H);
                            woodsitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                           {
                               printf("The total bill to be paid is Rs.%d",bill);
                           }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 9: printf("Minerva Grand\n");
                    minervagrand();
                    printf("select the items :");
                    scanf("%d",&I);
                    minervagranditems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            minervagrand();
                            printf("select the items :");
                            scanf("%d",&I);
                            minervagranditems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                           scanf("%d",&item);
                           if(item!=1)
                          {
                             printf("The total bill to be paid is Rs.%d",bill);
                          }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 10: printf("Rusted Spoon\n");
                     rustedspoon();
                     printf("select the items :");
                     scanf("%d",&J);
                     rustedspoonitems();
                     printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            rustedspoon();
                            printf("select the items :");
                            scanf("%d",&J);
                            rustedspoonitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                printf("The total bill to be paid is Rs.%d",bill);
                            }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;

        }


    }
    else if(press == 2)
    {
        while(press == 2)
        {
            restaurants();
            printf("Select a restaurant :");
            scanf("%d",&select);
            items();
            printf("Press '1' to continue with this restaurant\nPress '2' to go with another restaurant\n");
            scanf("%d",&press);
            printf("\n");
            if(press == 1)
           {
               printf("Finally you have selected ");
               printf("%d",select);
           switch(select)
           {
            case 1: printf("Sweet Magic\n");
                    sweetmagic();
                    printf("select the items :");
                    scanf("%d",&A);
                    sweetmagicitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                             sweetmagic();
                             printf("select the items :");
                             scanf("%d",&A);
                             sweetmagicitems();
                             printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                printf("The total bill to be paid is Rs.%d",bill);
                            }

                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 2: printf("Cross Roads\n");
                    crossroads();
                    printf("select the items :");
                    scanf("%d",&B);
                    crossroadsitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            crossroads();
                            printf("select the items :");
                            scanf("%d",&B);
                            crossroadsitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                           {
                               printf("The total bill to be paid is Rs.%d",bill);
                            }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 3: printf("Little Village\n");
                    littlevillage();
                    printf("select the items :");
                    scanf("%d",&C);
                    littlevillageitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            littlevillage();
                            printf("select the items :");
                            scanf("%d",&C);
                            littlevillageitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                  printf("The total bill to be paid is Rs.%d",bill);
                            }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 4: printf("Our Place\n");
                    ourplace();
                    printf("select the items :");
                    scanf("%d",&D);
                    ourplaceitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            ourplace();
                            printf("select the items :");
                            scanf("%d",&D);
                            ourplaceitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                 printf("The total bill to be paid is Rs.%d",bill);
                            }
                         }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 5: printf("Southern Spice\n");
                    southernspice();
                    printf("select the items :");
                    scanf("%d",&E);
                    southernspiceitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            southernspice();
                            printf("select the items :");
                            scanf("%d",&E);
                            southernspiceitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                            {
                                 printf("The total bill to be paid is Rs.%d",bill);
                            }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 6: printf("Andhra spice\n");
                    andhraspice();
                    printf("select the items :");
                    scanf("%d",&F);
                    andhraspiceitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            andhraspice();
                            printf("select the items :");
                            scanf("%d",&F);
                            andhraspiceitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                           if(item!=1)
                          {
                              printf("The total bill to be paid is Rs.%d",bill);
                          }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 7: printf("Barkaas\n");
                    barkaas();
                    printf("select the items :");
                    scanf("%d",&G);
                    barkaasitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                           barkaas();
                            printf("select the items :");
                            scanf("%d",&F);
                            barkaasitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                           {
                                printf("The total bill to be paid is Rs.%d",bill);
                           }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 8: printf("woods\n");
                    woods();
                    printf("select the items :");
                    scanf("%d",&H);
                    woodsitems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            woods();
                            printf("select the items :");
                            scanf("%d",&H);
                            woodsitems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                            scanf("%d",&item);
                            if(item!=1)
                           {
                               printf("The total bill to be paid is Rs.%d",bill);
                           }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 9: printf("Minerva Grand\n");
                    minervagrand();
                    printf("select the items :");
                    scanf("%d",&I);
                    minervagranditems();
                    printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            minervagrand();
                            printf("select the items :");
                            scanf("%d",&I);
                            minervagranditems();
                            printf("\n");
                            printf("\nPress '1' to select any other items\n");
                            printf("press any number to go for address selection\n");
                           scanf("%d",&item);
                           if(item!=1)
                          {
                             printf("The total bill to be paid is Rs.%d",bill);
                          }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;
            case 10: printf("Rusted Spoon\n");
                     rustedspoon();
                     printf("select the items :");
                     scanf("%d",&J);
                     rustedspoonitems();
                     printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item==1)
                    {
                        while(item==1)
                        {
                            rustedspoon();
                            printf("select the items :");
                            scanf("%d",&J);
                            rustedspoonitems();
                            printf("\n");
                    printf("\nPress '1' to select any other items\n");
                    printf("press any number to go for address selection\n");
                    scanf("%d",&item);
                    if(item!=1)
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                        }
                    }
                    else
                    {
                        printf("The total bill to be paid is Rs.%d",bill);
                    }
                    break;

        }

    }
        }
    }
        //ADDRESS SELECTION
    printf("\n1.Individual House\n2.Apartment\nselect your residence : ");
    scanf("%d",&residence);
    printf("\n");
    if(residence==1)
    {
        printf("Enter your Door No :");
        scanf("%s",&door);
        getchar();
    }
    else if(residence==2)
    {
        printf("Enter your Apartment Name :");
        scanf("%s",&appartment);
        getchar();
        printf("Enter your Plot No :");
        scanf("%d",&plot);
        getchar();
    }

        printf("Enter your landmark :");
        fgets(landmark,100,stdin);
        printf("Enter your Street name :");
        fgets(street,100,stdin);
        printf("Enter your Village name :");
        fgets(village,100,stdin);
        printf("Enter your city :");
        scanf("%s",&city);
        getchar();
        printf("Enter your Pincode :");
        fgets(pincode,100,stdin);
        if(residence==1)
        {
            printf("\nDoor number :%s\n\n",door);
        }
        else
        {
            printf("Apartment name :%s\n",appartment);
            printf("plot number :%d\n",plot);
        }

        printf("Land mark :%s\n",landmark);
        printf("street name :%s\n",street);
        printf("village name :%s\n",village);
        printf("city name :%s\n",city);
        printf("pin code :%s\n",pincode);
        printf("Press '1' to confirm the address (or) Press any number to enter the address again :");
        scanf("%d",&address);
        if(address==1)
        {
            printf("Your address is confirmed :)\n");
        }
        else
        {
            printf("Re-enter the address\n");
            while(address!=1)
            {
                    printf("1.Individual House\n2.Apartment\nselect your residence : ");
                    scanf("%d",&residence);

                    if(residence==1)
                    {
                        printf("Enter your Door No :");
                        scanf("%s",&door);
                    }
                    else if(residence==2)
                    {
                         printf("Enter your Apartment Name :");
                         scanf("%s",&appartment);
                         printf("Enter your Plot No :");
                         scanf("%d",&plot);
                    }
                    printf("Enter your landmark :");
                    scanf("%s",&landmark);
                    printf("Enter your Street name :");
                    scanf("%s",&street);
                    printf("Enter your Village name :");
                    scanf("%s",&village);
                    printf("Enter your city :");
                    scanf("%s",&city);
                    printf("Enter your Pincode :");
                    scanf("%s",&pincode);
                    if(residence==1)
                    {
                         printf("Door number :%s\n",door);
                    }
                    else
                    {
                         printf("Apartment name :%s\n",appartment);
                         printf("plot number :%d\n",plot);
                    }
                    printf("Land mark :%s\n",landmark);
                    printf("street name :%s\n",street);
                    printf("village name :%s\n",village);
                    printf("city name :%s\n",city);
                    printf("pin code :%s\n",pincode);
                    printf("Press '1' to confirm the address (or) Press any number to enter the address again :");
                    scanf("%d",&address);
                    if(address==1)
                    {
                        printf("Your address is confirmed :)\n");

                    }
            }
        }
    //PAYMENT AND ORDER CONFIRMATION

    printf("------------------------PAYMENT AND ORDER CONFIRMATION------------------------------\n");
    printf ("Enter your mobile number :");
    scanf ("%llu", &mno);
    printf ("1.COD\n2.CREDIT CARD\n3.DEBIT CARD\n4.NET BANKING\n");
    printf ("Select the payment option : ");
    scanf ("%d", &payment);
    if (payment == 1)
    {
        printf ("You selected the COD option\n");
        printf ("You order is confirmed\n");
        printf ("You need to pay the money at your doorstep!!Amount to be paid:RS.%d\n",bill);
    }
    else if (payment == 2)
    {
        printf ("You selected the CREDIT CARD option\n");
        printf ("Enter your card number:");
        scanf ("%s", &credit);
	        i = 0;
	        while (i <= 11)
	        {
	            if ((48 <= credit[i]) && (credit[i] <= 57) && (strlen (credit) == 12))
		        {
		            i = i + 1;
		            continue;
		        }
	            else
	            {
	                printf("Please ensure that you follow the below conditions while you are entering the credit card number\n");
	                printf("1.Make sure your credit card number has 12 digits only\n");
                    printf ("2.Make sure you do not enter any character other than digits!!\n");
                    strcpy(credit,s1);
                    break;
	            }
	        }
            while ((strcmp(credit,s1)==0))
            {
                printf ("Re-enter your credit card number :");
                scanf ("%s", &credit);
                while (i <= 11)
                {
                    if ((48 <= credit[i]) && (credit[i] <= 57) && (strlen (credit) == 12))
                    {
                        i = i + 1;
                        continue;
                    }
                    else
                    {
                        printf("Please ensure that you follow the below conditions while you are entering the credit card number\n");
                        printf("1.Make sure your credit card number has 12 digits only\n");
                        printf ("2.Make sure you do not enter any character other than digits!!\n");
                        strcpy(credit,s1);
                        break;
                    }

                }
            }
            expirydate();
    }
    else if (payment == 3)
    {
        printf ("You selected the DEBIT CARD option\n");
        printf ("Enter your card number : ");
        scanf ("%s", &debit);
            c = 0;
	        while (c <= 11)
	        {
	            if ((48 <= debit[c]) && (debit[c] <= 57) && (strlen (debit) == 12))
		        {
		            c = c + 1;
		            continue;
		        }
	            else
	            {
	                printf("Please ensure that you follow the below conditions while you are entering the debit card number\n");
	                printf("1.Make sure your debit card number has 12 digits only\n");
                    printf ("2.Make sure you do not enter any character other than digits!!\n");
                    strcpy(debit,s2);
                    break;
	            }
	        }
            while ((strcmp(debit,s2)==0))
            {
                printf ("Re-enter your debit card number :");
                scanf ("%s", &debit);
                while (c <= 11)
                {
                    if ((48 <= debit[c]) && (debit[c] <= 57) && (strlen (debit) == 12))
                    {
                        c = c + 1;
                        continue;
                    }
                    else
                    {
                        printf("Please ensure that you follow the below conditions while you are entering the debit card number\n");
                        printf("1.Make sure your debit card number has 12 digits only\n");
                        printf ("2.Make sure you do not enter any character other than digits!!\n");
                        strcpy(debit,s2);
                        break;
                    }

                }
            }
        expirydate();
    }
    else if (payment == 4)
    {
        printf ("You selected the NET BANKING option\n");
        printf ("Enter your user id : ");
        scanf ("%s", &user);
        printf ("Enter the password : ");
        scanf ("%s", &PW);
    }
    else
    {
        printf ("There is no payment option you have required\n");

    }
    printf ("Enter the OTP as your mobile number :");
    scanf ("%llu", &number);
    if (mno == number)
    {
        printf ("your order is confirmed\n");
    }
    while (mno != number)
    {
        printf ("Incorrect OTP!!!!\nRe-enter your OTP :");
        scanf ("%llu", &number);
        if (number == mno)
	    {
	        printf ("your order is confirmed\n");
	        break;
	    }

    }

    //DELIVERY DETAILS
    printf("------------------------DELIVERY DETAILS------------------------------\n");
    srand((unsigned)time(&t1));
    num=rand()%6;
    char N[50][30]={"Suresh","Ramesh","Shekhar","Vikram","Anoop","Pavan"};
    long long int M[50]={9900812435,9807654123,9492716452,9780612543,9887600987,7854120036};
    float R[50]={3.2,2.5,5.0,4.5,3.9,4.3};
    printf("Estimated delivery time:45 minutes(time may vary based on traffic and weather constraints)\n");
    printf("Delivery Boy Details are as below:\n");
    printf("Name:%s\n",N[num]);
    printf("Mobile number:%llu \n",M[num]);
    printf("Rating:%f star\n",R[num]);

    printf("Dear customer,\n");
    printf("Thank you for choosing our system for placing your order\n");
    printf("\nPlease provide a rating(out of 5) for your experience:");
    scanf("%f",&roc);
    printf("Enter any suggestions or comments if you would like to(or just type nil):");
    scanf("%s",&sug_com);
    printf("\n**********************THANK YOU FOR THE FEEDBACK**********************\n");
    //*******************************END OF THE ORDER*******************************************

}
