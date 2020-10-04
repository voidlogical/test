/*Program Transport Transport Shanghai*/
/*Team 13 White Wolf*/
/*Team member:
Liutianyi   201710234009
Liwenda     201710234061
Sunzhe      201710234043
Chendongkun 201710234065
Taojianxun  201710234021*/
/*Date 2019-4-24*/


#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 100 

/*Functions*/
int calculate_bottlers(float sprite);
int calculate_bottlerb(float beer);
int calculate_bottlerc(float cola);
int calculate_box(int bottlerb);
int calculate_cratec(int bottlerc);
int calculate_crates(int bottlers);
int calculate_bcarb(int *box);
int calculate_bcarc(int *cratec);
int calculate_bcars(int *crates);
void calculate_bcarmix(int *box,int *cratec,int *crates,int s[]);
int calculate_carmix(int *box,int *cratec,int *crates);
void select(int a, int b, int c ,int d,int e,int f);
void loading_plan(int box,int cratec,int crates);
void Cc(int bcarb ,int bcarc,int bcars ,int x,int s[]);
void precentage(int box,int cratec,int crates);
void create(float *,float *,float *);
void orderlist(char cname[],float *,float *,float *);


/* define the structure data type */
struct customer
{	
	char name[20];						
	float beer;
	float cola;
	float sprite;
};

int main()
{
	float beer,cola,sprite;
	int i,op1;
	int bottleb,bottlec,bottles;
	int box,cratec,crates;
	
	
	char namec[20];
	
	struct customer data[N];
	do
	{
		printf("\n\n**********************Drinks Transport Shanghai***********************\n\n");
		printf("                                Welcome!                              \n");
		printf("\n*****************************Primary Menu*****************************\n");
		printf("<Create a new order>-----------------------------------------------<1>\n");
		printf("<    Order list    >-----------------------------------------------<2>\n");
		printf("<      Quit        >-----------------------------------------------<0>\n");
		printf("\nPLease input your choice: ");
		
		scanf("%d",&op1);
		getchar();
		switch(op1)
		{
			case 1:
			create(&beer,&cola,&sprite);

			
			
			bottles=calculate_bottlers(sprite);
			bottleb=calculate_bottlerb(beer);
			bottlec=calculate_bottlerc(cola);/*calculate*/
			box=calculate_box(bottleb);
			cratec=calculate_cratec(bottlec);
			crates=calculate_crates(bottles);
			select(bottleb,bottlec,bottles,box,cratec,crates);
			
			
			break;
			case 2:
			printf("\n-------------------------------Customer-------------------------------\n");
            printf("***Please input the name of the customer: ");
            gets(namec);
            
            orderlist(namec,&beer,&cola,&sprite);
		    /*orderlist();*/

		    
		    /*calculate*/;
			/*Switch wyw*/;
			break;
			case 0:

			break;
			default:
			printf("\n                          Please try again!                           \n");   	
		}
		
		
	 }while(op1!=0);
	printf("\nQuit\n");
	printf("\n**************************Program Close*******************************");
	
	
	
	
	return 0;	
}
void create(float *be,float *co,float *sp)
{
	int na,i,count;
	char nam[20];
	FILE *fp;
	int number;
	struct customer data[N];
	
	if( (fp = fopen("Customer order","rb")) == 0)		/* open the file */
	{
	    printf("File cannot be opened!\n");
	}
	else
	{
			fread(&data,sizeof(struct customer),100,fp);
			for(i=100;i>0;i--)
			{
				if(strlen(data[i].name)==0)
				count=i;
			}
				fclose(fp);
	}
	
	
	printf("PLease input the customer's name: ");
	gets(data[count].name);

	printf("Enter the amount for beer:");
	scanf("%f",&data[count].beer);
    getchar();
	printf("Enter the amount of cola: ");
    scanf("%f",&data[count].cola);
    getchar();
	printf("Enter the amount of sprite:");
    scanf("%f",&data[count].sprite);
	getchar();
	*be=data[count].beer;
	*co=data[count].cola;
	*sp=data[count].sprite;

   	if( (fp = fopen("Customer order","ab")) == 0)		/* open the file */
	{
	    printf("File cannot be opened!\n");
	}
	else
	{
		number = fwrite(&data[count],sizeof(struct customer),1,fp);
		if (number == 1)
		{
			printf("File has been created and data is stored.\n");	
		}
		else
		{
			printf("Order could not be saved to file!\n");
		}
		fclose(fp);
	}
	return;
}
void orderlist(char cname[],float *bee,float *col,float *spr)
{
	int i,count,op2,op3;
	FILE *fp;
	int bottleb,bottlec,bottles;
	int box,cratec,crates;
	struct customer data[N];
	
		if( (fp = fopen("Customer order","rb")) == 0)		/* open the file */
		{
		    printf("File cannot be opened!\n");
		}
		else
		{
				fread(&data,sizeof(struct customer),100,fp);
				for(i=100;i>0;i--)
				{
					if(strcmp(cname,data[i].name)==0)
					{
						printf("\n$$$ Order[%d] from %s: TSINGDAO BEER %.1fL Cola %.1fL Sprite %.1fL\n",i,data[i].name,data[i].beer,data[i].cola,data[i].sprite);
			        } 	
				}
						printf("\n\n\n***You can enter 1 to select an order, then compute and check it again.\n***Enter 2 to quit.");
						printf("\n\n***Your choice: ");
						scanf("%d",&op2);
						getchar();
						switch(op2)
								{
									case 1:
									printf("\n***Please input the Order number: ");
									scanf("%d",&op3);
									getchar();
									printf("\n***Your choice is:");
									printf("Order[%d] from %s: TSINGDAO BEER %.1fL Cola %.1fL Sprite %.1fL\n",op3,data[op3].name,data[op3].beer,data[op3].cola,data[op3].sprite);
								    *bee=data[op3].beer;
	                                *col=data[op3].cola;
	                                *spr=data[op3].sprite;
	                                bottles=calculate_bottlers(data[op3].sprite);
			                        bottleb=calculate_bottlerb(data[op3].beer);
			                        bottlec=calculate_bottlerc(data[op3].cola);
			                        box=calculate_box(bottleb);
			                        cratec=calculate_cratec(bottlec);
			                        crates=calculate_crates(bottles);
			                        
			                        select(bottleb,bottlec,bottles,box,cratec,crates);
									break;
									
									case 2:
								    
									break;  
									default:
									printf("That is a wrong option,please try again.\n");	
								}
				
				fclose(fp);
		}	
    return;	
}
void select(int a, int b, int c ,int d,int e,int f)
{
	int x,m,y=0;
	int s[7];
	int bcars,bcarb,bcarc;
	int box1,cratec1,crates1;
	
	while(y<1)
	{
		printf("\n\n1 Show the number of bottles for each product.\n");
		printf("2 for show the number of boxes and crates. \n");
		printf("3 for Show me the most efficient way of transportation. \n");
		printf("4 for show me the loading percentage of the last truck.\n");
		printf("5 for show me the loading plan with all details for every truck on the screen. \n");
		printf("6 for quit.\n");
		printf("Please enter your choice:");
		scanf("%d",&x);
		getchar(); 
	
		switch(x)
		{		
		  	case 1: printf("%d bottles Beer\n%d bottles Cola\n%dbottle Sprite\n",a,b,c);
  			break;
   			case 2: printf("%d boxs of Beer\n%d crates of Cola \n%d crates of sprite ",d,e,f);
   			break;
   			case 3: 
			        box1=d;
			        crates1=e;
			        cratec1=f;
					bcarb=calculate_bcarb(&box1);
				 	bcarc=calculate_bcarc(&cratec1);
				 	bcars=calculate_bcars(&crates1);
				 	calculate_bcarmix(&box1,&cratec1,&crates1,s);
				 	m=calculate_carmix(&box1,&cratec1,&crates1);
			        Cc( bcarb , bcarc, bcars ,m,s);
			        
   			break;
   			case 4: 
			   precentage(d,e,f);
   			break;
   			case 5: 
			   loading_plan(d,e,f);
  			break;
   			case 6:y=y+1;
   			break;
   			
		}
		
	}
	getchar();
	return;
}
void loading_plan(int box,int cratec,int crates)
{
 	int bcarb,bcarc,bcars,x,a,i,j,k,number,t,y,u,cut,pallet;
 	int cut1,cut2,cut3;
 	int s[7];
 	int box1,cratec1,crates1;
 	box1=box;
 	cratec1=cratec;
 	crates1=crates;
	i=j=k=0;
 	number=1;
 	bcarb=calculate_bcarb(&box);
 	bcarc=calculate_bcarc(&cratec);
 	bcars=calculate_bcars(&crates);
 	calculate_bcarmix(&box,&cratec,&crates,s);
 	x=calculate_carmix(&box,&cratec,&crates);
 	for(t=0;t<bcarb;t++)
 	{
 		printf("***************************\n");
 		printf("*   big truck No.%3d      *\n",number);
 		printf("*   3200 box of beer      *\n");
 		printf("*      0 crate of cola    *\n");
 		printf("*      0 crate of sprite  *\n");
 		printf("*     50 pallet           *\n");
 		printf("***************************\n");
 		printf("\n");
 		number++;
	}
 	/*printf("%dcola",&bcarc);*/
 	for(y=0;y<bcarc;y++)
 	{
 		printf("***************************\n");
 		printf("*   big truck No.%3d      *\n",number);
 		printf("*      0 box of beer      *\n");
 		printf("*    800 crate of cola    *\n");
 		printf("*      0 crate of sprite  *\n");
 		printf("*     50 pallet           *\n");
 		printf("***************************\n");
 		printf("\n");
 		number++;
 	}
 	/*printf("%dsprite",&bcars);*/
 	for(u=0;u<bcars;u++)
 	{
 		printf("***************************\n");
 		printf("*   big truck No.%3d      *\n",number);
 		printf("*      0 box of beer      *\n");
 		printf("*      0 crate of cola    *\n");
 		printf("*    800 crate of sprite  *\n");
 		printf("*     50 pallet           *\n");
 		printf("***************************\n");
 		printf("\n");
 		number++;
 	}
 	if(s[0]==2)
 	{
 		/*printf("first bcar is %dbeer %dcola %dsprite",s[1],s[2],s[3]);*/
 		printf("***************************\n");
 		printf("*   big mix truck No.%3d  *\n",number);
 		printf("*   %4d box of beer      *\n",s[1]);
 		printf("*   %4d crate of cola    *\n",s[2]);
 		printf("*   %4d crate of sprite  *\n",s[3]);
 		printf("*     50 pallet           *\n");
 		printf("***************************\n");
 		printf("\n");
 		number++;
 		/*printf("second bcar is %dbeer %dcola %dsprite",s[4],s[5],s[6]);*/
 		printf("***************************\n");
 		printf("*   big mix truck No.%3d  *\n",number);
 		printf("*   %4d box of beer      *\n",s[4]);
 		printf("*   %4d crate of cola    *\n",s[5]);
 		printf("*   %4d crate of sprite  *\n",s[6]);
 		printf("*     50 pallet           *\n");
 		printf("***************************\n");
 		printf("\n");
 		number++;
	}
	if(s[0]==1)
	{
		printf("***************************\n");
 		printf("*   big mix truck No.%3d  *\n",number);
 		printf("*   %4d box of beer      *\n",s[1]);
 		printf("*   %4d crate of cola    *\n",s[2]);
 		printf("*   %4d crate of sprite  *\n",s[3]);
 		printf("*     50 pallet           *\n");
 		printf("***************************\n");
 		printf("\n");
 		number++;
	}
 	if(x==3)
 	{
 		/*printf("last big truck have %dbeer %dcola %dsprite",box,cratec,crates);*/
 			pallet=box/48+(crates+cratec)/12;
 			if(box%48)
 			{
 				pallet++;
			}
			if((crates+cratec)%12)
 			{
 				pallet++;
			}
 			printf("***************************\n");
	 		printf("*   big last truck No.%3d *\n",number);
	 		printf("*   %4d box of beer      *\n",box);
	 		printf("*   %4d crate of cola    *\n",cratec);
	 		printf("*   %4d crate of sprite  *\n",crates);
	 		printf("*    %3d pallet           *\n",pallet);
	 		printf("***************************\n");
	 		printf("\n");
	 		number++;
	}		
	if(x==2)
	{
		if(box<384)
		{
			if(box==0)
			{
				if(cratec==0)
				{
					/*printf("C  c");*/
					pallet=(crates-96)/12;
					if((crates-96)%12)
		 			{
		 				pallet++;
					}
					printf("***************************\n");
			 		printf("*    small truck No.%3d   *\n",number);
			 		printf("*      0 box of beer      *\n");
			 		printf("*      0 crate of cola    *\n");
			 		printf("*     96 crate of sprite  *\n");
			 		printf("*      8 pallet           *\n");
			 		printf("***************************\n");
			 		printf("\n");
			 		number++;
			 		printf("***************************\n");
			 		printf("*  small last truck No.%3d*\n",number);
			 		printf("*      0 box of beer      *\n");
			 		printf("*      0 crate of cola    *\n");
			 		printf("*   %4d crate of sprite  *\n",crates-96);
			 		printf("*    %3d pallet           *\n",pallet);
			 		printf("***************************\n");
			 		printf("\n");
			 		number++;
				}
				else
				{
					if(cratec==96)
					{
						/*printf("B       c");*/
						pallet=(crates)/12;
						if((crates)%12)
			 			{
			 				pallet++;
						}
					printf("***************************\n");
			 		printf("*    small truck No.%3d   *\n",number);
			 		printf("*      0 box of beer      *\n");
			 		printf("*     96 crate of cola    *\n");
			 		printf("*      0 crate of sprite  *\n");
			 		printf("*      8 pallet           *\n");
			 		printf("***************************\n");
			 		printf("\n");
			 		number++;	
			 		printf("***************************\n");
			 		printf("*  small last truck No.%3d*\n",number);
			 		printf("*      0 box of beer      *\n");
			 		printf("*      0 crate of cola    *\n");
			 		printf("*   %4d crate of sprite  *\n",crates);
			 		printf("*    %3d pallet           *\n",pallet);
			 		printf("***************************\n");
			 		printf("\n");
			 		number++;
					}
					else
					{
						if(cratec>96)
						{
							/*printf("B         b+c");*/
							pallet=(crates+(cratec-96))/12;
							if((crates+cratec)%12)
				 			{
				 				pallet++;
							}
							printf("***************************\n");
					 		printf("*    small truck No.%3d   *\n",number);
					 		printf("*      0 box of beer      *\n");
					 		printf("*     96 crate of cola    *\n");
					 		printf("*      0 crate of sprite  *\n");
					 		printf("*      8 pallet           *\n");
					 		printf("***************************\n");
					 		printf("\n");
					 		number++;
					 		printf("***************************\n");
					 		printf("*  small last truck No.%3d*\n",number);
					 		printf("*      0 box of beer      *\n");
					 		printf("*   %4d crate of cola    *\n",cratec-96);
					 		printf("*   %4d crate of sprite  *\n",crates);
					 		printf("*    %3d pallet           *\n",pallet);
					 		printf("***************************\n");
					 		printf("\n");
					 		number++;
						}
						else
						{
							/*printf("BC         Cb+c");*/
							pallet=cut+(crates-(96-cratec))/12;
							if((cut+(crates-(96-cratec)))%12)
				 			{
				 				pallet++;
							}
							cut=cratec%12;
							printf("***************************\n");
					 		printf("*    small truck No.%3d   *\n",number);
					 		printf("*      0 box of beer      *\n");
					 		printf("*   %4d crate of cola    *\n",cratec-cut);
					 		printf("*   %4d crate of sprite  *\n",96-cratec);
					 		printf("*      8 pallet           *\n");
					 		printf("***************************\n");
					 		printf("\n");
					 		number++;
					 		printf("***************************\n");
					 		printf("*  small last truck No.%3d*\n",number);
					 		printf("*      0 box of beer      *\n");
					 		printf("*   %4d crate of cola    *\n",cut);
					 		printf("*   %4d crate of sprite  *\n",crates-(96-cratec));
					 		printf("*     50 pallet           *\n");
					 		printf("***************************\n");
					 		printf("\n");
					 		number++;
						}
					}
				}
			}
			else
			{
				while(box1>=48)
				{
					i++;
					box1=box1-48;
				}
				while(cratec1>=12)
				{
					j++;
					cratec1=cratec1-12;
				}
				while(crates1>=12)
				{
					k++;
					crates1=crates1-12;
				}
				if(i+j+k<8)
				{
					if(i+j+k==7)
					{
						if(cratec1+crates1<=12)
						{
							if(box*0.4*0.3*0.3<(cratec1+crates1)*0.4*0.6*0.6)
							{
								/*printf("ABC b+c  ca");*/
								cut=box%48;	
								pallet=cut/48+(crates-(96-cratec))/12;
					 			if(box%48)
					 			{
					 				pallet++;
								}
								if((crates-(96-cratec))%12);
					 			{
					 				pallet++;
								}
								printf("***************************\n");
						 		printf("*    small truck No.%3d   *\n",number);
						 		printf("*   %4d box of beer      *\n",box-cut);
						 		printf("*   %4d crate of cola    *\n",cratec);
						 		printf("*   %4d crate of sprite  *\n",(2400-box+cut)/4-cratec);
						 		printf("*      8 pallet           *\n");
						 		printf("***************************\n");
						 		printf("\n");
						 		number++;
						 		printf("***************************\n");
						 		printf("*  small last truck No.%3d*\n",number);
						 		printf("*   %4d box of beer      *\n",cut);
						 		printf("*      0 crate of cola    *\n");
						 		printf("*   %4d crate of sprite  *\n",crates-(96-cratec));
						 		printf("*    %3d pallet          *\n",pallet);
						 		printf("***************************\n");
						 		printf("\n");
						 		number++;
							}
							else
							{
								/*printf("ABC a  b+c");*/
								cut=cratec%12;
								pallet=(cut+(crates-((50-(box%48)-1)*12+cut-cratec)))/12;
								if((crates+(crates-((50-(box%48)-1)*12+cut-cratec)))%12)
					 			{
					 				pallet++;
								}
								printf("***************************\n");
						 		printf("*    small truck No.%3d   *\n",number);
						 		printf("*   %4d box of beer      *\n",box);
						 		printf("*   %4d crate of cola    *\n",cratec-cut);
						 		printf("*   %4d crate of sprite  *\n",(50-(box%48)-1)*12+cut-cratec);
						 		printf("*      8 pallet           *\n");
						 		printf("***************************\n");
						 		printf("\n");
						 		number++;
						 		printf("***************************\n");
						 		printf("*  small last truck No.%3d*\n",number);
						 		printf("*      0 box of beer      *\n");
						 		printf("*   %4d crate of cola    *\n",cut);
						 		printf("*   %4d crate of sprite  *\n",crates-((50-(box%48)-1)*12+cut-cratec));
						 		printf("*    %3d pallet           *\n",pallet);
						 		printf("***************************\n");
						 		printf("\n");
						 		number++;
							}
						}
						else
						{
							/*printf("ABC bc  c+a");*/
							cut=box%48;
							pallet=cut/48+(crates-((50-((box-cut)%48)-1)*12-cratec))/12;
					 			if(cut%48)
					 			{
					 				pallet++;
								}
								if((crates-((50-((box-cut)%48)-1)*12-cratec))%12)
					 			{
					 				pallet++;
								}
							printf("***************************\n");
						 	printf("*    small truck No.%3d   *\n",number);
						 	printf("*   %4d box of beer      *\n",box-cut);
						 	printf("*   %4d crate of cola    *\n",cratec);
						 	printf("*   %4d crate of sprite  *\n",(50-((box-cut)%48)-1)*12-cratec);
						 	printf("*      8 pallet           *\n");
						 	printf("***************************\n");
						 	printf("\n");
						 	number++;
						 	printf("***************************\n");
						 	printf("*  small last truck No.%3d*\n",number);
						 	printf("*   %4d box of beer      *\n",cut);
						 	printf("*      0 crate of cola    *\n");
							printf("*   %4d crate of sprite  *\n",crates-((50-((box-cut)%48)-1)*12-cratec));
						 	printf("*    %3d pallet           *\n",pallet);
							printf("***************************\n");
							printf("\n");
							number++;
						}
					}
					else
					{
						/*printf("ABC a b+c   c");*/
								pallet=(crates-((50-((box)%48)-1)*12-cratec))/12;
					 			if(box%48)
					 			{
					 				pallet++;
								}
								if((crates-((50-((box)%48)-1)*12-cratec))%12)
					 			{
					 				pallet++;
								}
							printf("***************************\n");
						 	printf("*    small truck No.%3d   *\n",number);
						 	printf("*   %4d box of beer      *\n",box);
						 	printf("*   %4d crate of cola    *\n",cratec);
						 	printf("*   %4d crate of sprite  *\n",(50-((box)%48)-1)*12-cratec);
						 	printf("*      8 pallet            *\n");
						 	printf("***************************\n");
						 	printf("\n");
						 	number++;
						 	printf("***************************\n");
						 	printf("*  small last truck No.%3d*\n",number);
						 	printf("*      0 box of beer      *\n");
						 	printf("*      0 crate of cola    *\n");
							printf("*   %4d crate of sprite  *\n",crates-((50-((box)%48)-1)*12-cratec));
						 	printf("*    %3d pallet          *\n",pallet);
							printf("***************************\n");
							printf("\n");
							number++;
					}
				}
				else
				{
					if(i+j+k==8)
					{
							cut1=box%48;
							cut2=cratec%12;
							cut3=crates%12;
							pallet=(cut2+cut3)/12;
				 			if(cut1)
				 			{
				 				pallet++;
							}
							if((cut3+cut2)%12)
				 			{
				 				pallet++;
							}
							printf("***************************\n");
						 	printf("*    small truck No.%3d   *\n",number);
						 	printf("*   %4d box of beer      *\n",box-cut1);
						 	printf("*   %4d crate of cola    *\n",cratec-cut2);
						 	printf("*   %4d crate of sprite  *\n",crates-cut3);
						 	printf("*      8 pallet            *\n");
						 	printf("***************************\n");
						 	printf("\n");
						 	number++;
						 	printf("***************************\n");
						 	printf("*  small last truck No.%3d*\n",number);
						 	printf("*   %4d box of beer      *\n",cut1);
						 	printf("*   %4d crate of cola    *\n",cut2);
							printf("*   %4d crate of sprite  *\n",cut3);
						 	printf("*    %3d pallet           *\n",pallet);
							printf("***************************\n");
							printf("\n");
							number++;
					}
					else
					{
						if((box/48)+(cratec/12)<8)
						{
							cut1=box%48;
							cut2=cratec%12;
							cut3=crates%12;
							pallet=(cut2/12+(crates-((8-(box/48)-(cratec/12))*12))/12);
				 			if(cut1)
				 			{
				 				pallet++;
							}
							if(((crates-((8-(box/48)-(cratec/12))*12))+cut2)%12)
				 			{
				 				pallet++;
							}
							printf("***************************\n");
						 	printf("*    small truck No.%3d   *\n",number);
						 	printf("*   %4d box of beer      *\n",box-cut1);
						 	printf("*   %4d crate of cola    *\n",cratec-cut2);
						 	printf("*   %4d crate of sprite  *\n",(8-(box/48)-(cratec/12))*12);
						 	printf("*      8 pallet            *\n");
						 	printf("***************************\n");
						 	printf("\n");
						 	number++;
						 	printf("***************************\n");
						 	printf("*  small last truck No.%3d*\n",number);
						 	printf("*   %4d box of beer      *\n",cut1);
						 	printf("*   %4d crate of cola    *\n",cut2);
							printf("*   %4d crate of sprite  *\n",crates-((8-(box/48)-(cratec/12))*12));
						 	printf("*    %3d pallet           *\n",pallet);
							printf("***************************\n");
							printf("\n");
							number++;
						}
						else
						{
							if((box/48)+(cratec/12)==8)
							{
								cut1=box%48;
								cut2=cratec%12;
								cut3=crates%12;
								pallet=(cut2+crates)/12;
					 			if(cut1)
					 			{
					 				pallet++;
								}
								if((crates+cut2)%12)
					 			{
					 				pallet++;
								}
								printf("***************************\n");
							 	printf("*    small truck No.%3d   *\n",number);
							 	printf("*   %4d box of beer      *\n",box-cut1);
							 	printf("*   %4d crate of cola    *\n",cratec-cut2);
							 	printf("*      0 crate of sprite  *\n");
							 	printf("*      8 pallet           *\n");
							 	printf("***************************\n");
							 	printf("\n");
							 	number++;
							 	printf("***************************\n");
							 	printf("*  small last truck No.%3d*\n",number);
							 	printf("*   %4d box of beer      *\n",cut1);
							 	printf("*   %4d crate of cola    *\n",cut2);
								printf("*   %4d crate of sprite  *\n",crates);
							 	printf("*    %3d pallet           *\n",pallet);
								printf("***************************\n");
								printf("\n");
								number++;
							}
							else
							{
								cut1=box%48;
								cut2=cratec%12;
								cut3=crates%12;
								pallet=((cratec-(12*(8-box/48))+crates)/12);
					 			if(cut1)
					 			{
					 				pallet++;
								}
								if((crates+(cratec-(12*(8-box/48))))%12)
					 			{
					 				pallet++;
								}
								printf("***************************\n");
							 	printf("*    small truck No.%3d   *\n",number);
							 	printf("*   %4d box of beer      *\n",box-cut1);
							 	printf("*   %4d crate of cola    *\n",12*(8-box/48));
							 	printf("*      0 crate of sprite  *\n");
							 	printf("*      8 pallet           *\n");
							 	printf("***************************\n");
							 	printf("\n");
							 	number++;
							 	printf("***************************\n");
							 	printf("*  small last truck No.%3d*\n",number);
							 	printf("*   %4d box of beer      *\n",cut1);
							 	printf("*   %4d crate of cola    *\n",cratec-(12*(8-box/48)));
								printf("*   %4d crate of sprite  *\n",crates);
							 	printf("*    %3d pallet           *\n",pallet);
								printf("***************************\n");
								printf("\n");
								number++;
							}
						}
					}
				}
				
			}
		}
		else
		{
			if(box==384)
			{
				/*printf("A");
				printf("BC b+c ");*/
				pallet=(crates+cratec)/12;
				if((crates+cratec)%12)
				{
					pallet++;
				}
				printf("***************************\n");
				printf("*    small truck No.%3d   *\n",number);
			 	printf("*    384 box of beer      *\n");
			 	printf("*      0 crate of cola    *\n");
			 	printf("*      0 crate of sprite  *\n");
			 	printf("*     50 pallet           *\n");
			 	printf("***************************\n");
			 	printf("\n");
			 	number++;
			 	printf("***************************\n");
			 	printf("*  small last truck No.%3d*\n",number);
			 	printf("*      0 box of beer      *\n");
			 	printf("*   %4d crate of cola    *\n",cratec);
				printf("*   %4d crate of sprite  *\n",crates);
			 	printf("*    %3d pallet           *\n",pallet);
				printf("***************************\n");
				printf("\n");
				number++;
			}
			else
			{
				/*printf("A");
				printf("ABC a b+c or b+c c");*/
				pallet=(box-384)/48+(crates+cratec)/12;
				if((box-384)%48)
				{
					pallet++;
				}
				if((crates+cratec)%12)
				{
					pallet++;
				}
				printf("***************************\n");
				printf("*    small truck No.%3d   *\n",number);
			 	printf("*    384 box of beer      *\n");
			 	printf("*      0 crate of cola    *\n");
			 	printf("*      0 crate of sprite  *\n");
			 	printf("*     50 pallet           *\n");
			 	printf("***************************\n");
			 	printf("\n");
			 	number++;
			 	printf("***************************\n");
			 	printf("*  small last truck No.%3d*\n",number);
			 	printf("*   %4d box of beer      *\n",box-384);
			 	printf("*   %4d crate of cola    *\n",cratec);
				printf("*   %4d crate of sprite  *\n",crates);
			 	printf("*     50 pallet           *\n");
				printf("***************************\n");
				printf("\n");
				number++;
			}
		}
	}
	if(x==1)
	{
		/*printf("ABC a b+c or b+c c");*/
		pallet=box/48+(crates+cratec)/12;
		if(box%48)
		{
			pallet++;
		}
		if((crates+cratec)%12)
		{
			pallet++;
		}
		printf("***************************\n");
	 	printf("* small last truck No.%3d *\n",number);
	 	printf("*   %4d box of beer      *\n",box);
	 	printf("*   %4d crate of cola    *\n",cratec);
		printf("*   %4d crate of sprite  *\n",crates);
	 	printf("*    %3d pallet           *\n",pallet);
		printf("***************************\n");
		printf("\n");
		number++;
	}
	if(x==4)
	{
			cut1=cratec%16;
			cut2=crates%16;
			pallet=+(cut1+cut2)/12;
			if((crates+cratec)%12)
			{
				pallet++;
			}
			printf("***************************\n");
			printf("*    big truck No.%3d     *\n",number);
		 	printf("*   %4d box of beer      *\n",box);
		 	printf("*   %4d crate of cola    *\n",cratec-cut1);
		 	printf("*   %4d crate of sprite  *\n",crates-cut2);
		 	printf("*     50 pallet           *\n");
		 	printf("***************************\n");
		 	printf("\n");
		 	number++;
		 	printf("***************************\n");
		 	printf("*  small last truck No.%3d*\n",number);
		 	printf("*      0 box of beer      *\n");
		 	printf("*   %4d crate of cola    *\n",cut1);
			printf("*   %4d crate of sprite  *\n",cut2);
		 	printf("*    %3d pallet           *\n",pallet);
			printf("***************************\n");
			printf("\n");
			number++;
	}
}
int calculate_bottlers(float sprite)
{
	int bottler;
	bottler=(int)(sprite/2);
	if(bottler<(sprite/2))
	{
		bottler++;
	}
	return bottler;	
}
int calculate_bottlerb(float beer)
{
	int bottler;
	bottler=(int)(beer/0.5);
	if(bottler<(beer/0.5))
	{
		bottler++;
	}
	return bottler;
}
int calculate_bottlerc(float cola)
{
	int bottler;
	bottler=(int)(cola/2);
	if(bottler<(cola/2))
	{
		bottler++;
	}
	return bottler;
}
int calculate_box(int bottlerb)
{
	int box;
	box=bottlerb/12;
	if(bottlerb%12)
	{
		box++;
	}
	return box;
}
int calculate_cratec(int bottlerc)
{
	int cratec;
	cratec=bottlerc/6;
	if(bottlerc%6)
	{
		cratec++;
	}
	return cratec;
}
int calculate_crates(int bottlers)
{
	int crates;
	crates=bottlers/6;
	if(bottlers%6)
	{
		crates++;
	}
	return crates;
}
int calculate_bcarb(int *box)
{
	int bcarb=0;
	while(*box>=3200)
	{
		bcarb++;
		*box=*box-3200;
	}
	return bcarb;
}
int calculate_bcarc(int *cratec)
{
	int bcarc=0;
	while(*cratec>=800)
	{
		bcarc++;
		*cratec=*cratec-800;
	}
	return bcarc;
}
int calculate_bcars(int *crates)
{
	int bcars=0;
	while(*crates>=800)
	{
		bcars++;
		*crates=*crates-800;
	}
	return bcars;
}
void calculate_bcarmix(int *box,int *cratec,int *crates,int s[])
{
	int i,j,k,m,rem,flag,rem2;
	flag=0;
	s[0]=0;
	i=0;
	j=0;
	k=0;
	while(*box>=64)
	{
		i++;
		*box=*box-64;
	}
	while(*cratec>=16)
	{
		j++;
		*cratec=*cratec-16;
	}
	while(*crates>=16)
	{
		k++;
		*crates=*crates-16;
	}
	m=0;
	if(*cratec+*crates>=16)
	{
		m=1;
		rem=*cratec;
	}
	if((i+j+k)/50==2)
	{
		s[0]=2;
		s[1]=i*64;
		s[2]=(50-i)*16;
		s[3]=0;
		s[4]=0;
		s[5]=(j-(50-i))*16;
		s[6]=(50-(j-(50-i)))*16;
		*crates=*crates+((k-(50-(j-(50-i))))*16);
	}
	else
	{
		if(i+k+j+m==100)
		{
			flag=1;
			s[0]=2;
			s[1]=i*64;
			s[2]=(50-i)*16;
			s[3]=0;
			s[4]=0;
			s[5]=(50-(i+j))*16+rem;
			s[6]=k*16+(16-rem);
		}
		else
		{
		if((i+k+j)/50==1)
		{
			s[0]=1;
			s[1]=i;
			if(i+j>=50)
			{
				s[2]=(50-i)*16;
				s[3]=0;
				s[4]=0;
				s[5]=0;
				s[6]=0;
				*crates=*crates+(k*16);
				*cratec=*cratec+((j-(50-i))*16);
			}
			else
			{
				s[2]=j;
				s[3]=50-i-j;
				s[4]=0;
				s[5]=0;
				s[6]=0;
				*crates=*crates+((k-(50-i-j))*16);
			}
		}
		else
		{
			if(i+j+k+m==50)
			{
				flag=1;
				s[0]=1;
				s[1]=i*64;
				s[2]=j*16+rem;
				s[3]=k*16+(16-rem);
				s[4]=0;
				s[5]=0;
				s[6]=0;
			}
			else
			{
				*box+=i*64;
				*cratec+=j*16;
				*crates+=k*16;
			}
		}
		}
		if(flag==1)
		{
		*cratec-=rem;
		*crates-=(16-rem);
		}
	}
}
int calculate_carmix(int *box,int *cratec,int *crates)
{
	int i,j,k,sum,box1,box2,i2,j2,sum2;
	i=0;
	j=0;
	i2=0;
	j2=0;
	box1=*box;
	box2=*box;
	while(box1>=48)
	{
		i++;
		box1=box1-48;
	}
	if(box1)
	{
		i++;
	}
	while(box2>=64)
	{
		i2++;
		box2=box2-64;
	}
	if(box2)
	{
		i2++;
	}
	sum=*cratec+*crates;
	sum2=*cratec+*crates;
	while(sum>=12)
	{
		j++;
		sum=sum-12;
	}
	if(sum)
	{
		j++;
	}
	while(sum2>=16)
	{
		j2++;
		sum2=sum2-16;
	}
	if(sum2)
	{
		j2++;
	}
	if((i2+j2)>50)
	{
		k=4;
	}
	else
	{
		if(i+j>16)
		{
			k=3;
		}
		else
		{
			if(i+j>8)
			{
				k=2;
			}
			else
			{
				k=1;
				if(i+j==0)
				{
					k=0;
				}
			}
		}
	}
	return k;
}
void Cc(int bcarb ,int bcarc,int bcars ,int x,int s[])
{   
	int sumbcar;
	sumbcar=bcarb+bcarc+bcars+s[0];
 switch(x)
 {
 	case 0:printf("There shoud be %d big trucks and no small truck.",sumbcar);
 	break;
	case 1:printf("There shoud be %d big trucks and one small truck.",sumbcar);
	break;
	case 2:printf("There shoud be %d big trucks and two small truck.",sumbcar);
	break;
	case 3:printf("There shoud be %d big trucks and no small truck.",sumbcar+1);
	break;  
	case 4:printf("There shoud be %d big trucks and one small truck.",sumbcar+1);
	break; 
 } 
 return;
}
void precentage(int box,int cratec,int crates)
{
 	int bcarb,bcarc,bcars,x,a,i,j,k,t,y,u,cut,pallet;
 	int cut1,cut2,cut3;
 	int s[7];
 	int box1,cratec1,crates1;
 	float p;
 	box1=box;
 	cratec1=cratec;
 	crates1=crates;
	i=j=k=0;
 	bcarb=calculate_bcarb(&box);
 	bcarc=calculate_bcarc(&cratec);
 	bcars=calculate_bcars(&crates);
 	calculate_bcarmix(&box,&cratec,&crates,s);
 	x=calculate_carmix(&box,&cratec,&crates);
 	if(x==3)
 	{
	 		p=((box*0.4*0.3*0.3)+(cratec*0.4*0.6*0.6)+(crates*0.4*0.6*0.6))/(12*4*2.6)*100;
	 		printf("The last truck is big truck,the precentage is %f",p);
	}	
	if(x==2)
	{
		if(box<384)
		{
			if(box==0)
			{
				if(cratec==0)
				{
					/*printf("C  c");*/
			 		p=((0*0.4*0.3*0.3)+(0*0.4*0.6*0.6)+((crates-96)*0.4*0.6*0.6))/(4.8*2*2)*100;
					printf("The last truck is small truck,the precentage is %f",p);
				}
				if(cratec==96)
				{
					/*printf("B       c");*/
		 		p=((0*0.4*0.3*0.3)+(0*0.4*0.6*0.6)+(crates*0.4*0.6*0.6))/(4.8*2*2)*100;
				printf("The last truck is small truck,the precentage is %f",p);
				}
				else
				{
					if(cratec>96)
					{
						/*printf("B         b+c");*/
					 	p=((0*0.4*0.3*0.3)+((cratec-96)*0.4*0.6*0.6)+(crates*0.4*0.6*0.6))/(4.8*2*2)*100;
						printf("The last truck is small truck,the precentage is %f",p);	
					}
					else
					{
						/*printf("BC         Cb+c");*/
						cut=cratec%12;
				 		p=((0*0.4*0.3*0.3)+(cut*0.4*0.6*0.6)+((crates-(96-cratec))*0.4*0.6*0.6))/(4.8*2*2)*100;
						printf("The last truck is small truck,the precentage is %f",p);
					}
				}
			}
			else
			{
				while(box1>=48)
				{
					i++;
					box1=box1-48;
				}
				while(cratec1>=12)
				{
					j++;
					cratec1=cratec1-12;
				}
				while(crates1>=12)
				{
					k++;
					crates1=crates1-12;
				}
				if(i+j+k<8)
				{
					if(i+j+k==7)
					{
						if(cratec+crates<=12)
						{
							if(box*0.4*0.3*0.3<(cratec+crates)*0.4*0.6*0.6)
							{
								/*printf("ABC b+c  ca");*/
								cut=box%48;	
						 		p=((cut*0.4*0.3*0.3)+(0*0.4*0.6*0.6)+((crates-(96-cratec))*0.4*0.6*0.6))/(4.8*2*2)*100;
								printf("The last truck is small truck,the precentage is %f",p);
							}
							else
							{
								/*printf("ABC a  b+c");*/
								cut=cratec%12;
						 		p=((0*0.4*0.3*0.3)+((cut)*0.4*0.6*0.6)+((crates-((50-(box%48)-1)*12+cut-cratec))*0.4*0.6*0.6))/(4.8*2*2)*100;
								printf("The last truck is small truck,the precentage is %f",p);
							}
						}
						else
						{
							/*printf("ABC bc  c+a");*/
							cut=box%48;
							p=((cut*0.4*0.3*0.3)+(0*0.4*0.6*0.6)+((crates-((50-((box-cut)%48)-1)*12-cratec))*0.4*0.6*0.6))/(4.8*2*2)*100;
							printf("The last truck is small truck,the precentage is %f",p);
						}
					}
					else
					{
						/*printf("ABC a b+c   c");*/
							p=((0*0.4*0.3*0.3)+(0*0.4*0.6*0.6)+((crates-((50-((box)%48)-1)*12-cratec))*0.4*0.6*0.6))/(4.8*2*2)*100;
							printf("The last truck is small truck,the precentage is %f",p);
					}
				}
				else
				{
					if(i+j+k==8)
					{
							cut1=box%48;
							cut2=cratec%12;
							cut3=crates%12;
							p=((cut1*0.4*0.3*0.3)+(cut2*0.4*0.6*0.6)+(cut3*0.4*0.6*0.6))/(4.8*2*2)*100;
							printf("The last truck is small truck,the precentage is %f",p);
					}
					else
					{
						if((box/48)+(cratec/12)<8)
						{
							cut1=box%48;
							cut2=cratec%12;
							cut3=crates%12;
							p=((cut1*0.4*0.3*0.3)+(cut2*0.4*0.6*0.6)+((crates-((8-(box/48)-(cratec/12))*12))*0.4*0.6*0.6))/(4.8*2*2)*100;
							printf("The last truck is small truck,the precentage is %f",p);
						}
						else
						{
							if((box/48)+(cratec/12)==8)
							{
								cut1=box%48;
								cut2=cratec%12;
								cut3=crates%12;
								p=((cut1*0.4*0.3*0.3)+(cut2*0.4*0.6*0.6)+(crates*0.4*0.6*0.6))/(4.8*2*2)*100;
								printf("The last truck is small truck,the precentage is %f",p);
							}
							else
							{
								cut1=box%48;
								cut2=cratec%12;
								cut3=crates%12;
								p=((cut1*0.4*0.3*0.3)+((cratec-(12*(8-box/48)))*0.4*0.6*0.6)+(crates*0.4*0.6*0.6))/(4.8*2*2)*100;
								printf("The last truck is small truck,the precentage is %f",p);
							}
						}
					}
				}
				
			}
		}
		else
		{
			if(box==384)
			{
				/*printf("A");
				printf("BC b+c ");*/
				p=((0*0.4*0.3*0.3)+(cratec*0.4*0.6*0.6)+(crates*0.4*0.6*0.6))/(4.8*2*2)*100;
				printf("The last truck is small truck,the precentage is %f",p);
			}
			else
			{
				/*printf("A");
				printf("ABC a b+c or b+c c");*/
				p=(((box-384)*0.4*0.3*0.3)+(cratec*0.4*0.6*0.6)+(crates*0.4*0.6*0.6))/(4.8*2*2)*100;
		printf("The last truck is small truck,the precentage is %f",p);
			}
		}
	}
	if(x==1)
	{
		/*printf("ABC a b+c or b+c c");*/
		p=((box*0.4*0.3*0.3)+(cratec*0.4*0.6*0.6)+(crates*0.4*0.6*0.6))/(4.8*2*2)*100;
		printf("The last truck is small truck,the precentage is %f",p);
	}
	if(x==4)
	{
			cut1=cratec%16;
			cut2=crates%16;
			p=((cut1*0.4*0.6*0.6)+(cut2*0.4*0.6*0.6))/(4.8*2*2)*100;
			printf("The last truck is small truck,the precentage is %f",p);
	}
}














