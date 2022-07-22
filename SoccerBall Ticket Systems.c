#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


struct qty{

// These below save values of counter for various functions, since they will be probably looped more than once
// One loop = One person
////////////////////////////////////////////////////////////////////////////////////
	int m;            // Q[0].m used in void RESULT // Q[1].m  used in void Ayman///
	int M;              //Q[0].m used in void Ayman                              ///
	int V;             // Q[0].V used in  void TSTFILE                           ///
	int E;                //Q[0].E used                                          ///
	int J;             //Q[0].J used                                             ///
}Q[2];                                                                           ///
////////////////////////////////////////////////////////////////////////////////////

struct chosen{
	
	int chosen_seat1;
	int chosen_seat2;
	int chosen_seat3;
}seat[6];



// Functions are called in orderly manner
void Ayu(int same,char tchoice,int member); //FROM AYU (SEMI MODIFIED BY AYMAN AND AMIR)
void Thaqif(int same,int member); //FROM THAQIF
void TST_FILE(int member,int same);// BY AYMAN
void Ayman(int tournament,int same,int member); //FROM AYMAN
void AYU2(int member,int same,char tchoice);  //FROM AYU (SEMI MODIFIED BY AYMAN) //return type is void... for now.
void RESULT(int member,int same,char tchoice); //BY AYMAN
void Ayman2(int member,int same,char tchoice); //BY AYMAN
void DEL_FILE(int member);













void main(){
	int member=0;
	int same =1;
	char tchoice;
	int i,k;	
	FILE *ptr;	
	FILE *B;
	
		 	 	 	 	 
  	
	// AMIR PART
	printf("\nEnter amount of person : ");
	scanf("%d",&member);
	if(member <= 0){
		printf("\n Range cannot be zero and under!");
		sleep(3);
		exit(1);
	}
	
	printf("\nWould you like to see a different(D) or the same(S) tournament? [D/S] : ");
	scanf(" %c", &tchoice);
	
		
	
	if(tchoice == 'S' || tchoice == 's'){
		same = member; //later fix this
	}
	// END AMIR PART
	
	
	

if(tchoice == 'S' || tchoice == 's'){

B = fopen("BEVERAGE.txt","w");
	 fprintf(B,"%s\n","--------------------------------------------------------");
	 fprintf(B,"%s\n","                       BEVERAGE                         ");
	 fprintf(B,"%s\n","--------------------------------------------------------");
	 fprintf(B,"%s\n","   NAME                  			PRICE ");
	 fclose(B);
}

 //Thqif part 
	 ptr = fopen("lol.txt","w");
	 fclose(ptr);

	// End Thaqif Part


	
	//AYU PART
	Ayu(same,tchoice,member);
    // END AYU PART



	
DEL_FILE(member);



}



//AYU PART (SOME OF THEM HAVE AMIR)
void Ayu(int same,char tchoice,int member)
{
	char tour [3][2][30]={{"Manchester United Vs Chelsea", "[17.00-20.00]"},
	                      {"Liverpool Vs Arsenal"," [20.00-23.00]"},
						  {"Real Madrid Vs Barcelona","[20.30-24.00]"}};

	int choice, x=0, i,k,s,l,op=0;
	char code,pin,addon;
	char *dest;
	char wchoice[50];

	
						  
	printf("\n \t\t\t----------------------------------------------------------");
	printf("\n \t\t\t  CHOOSE YOUR TOURNAMENT              Time                ");
	printf("\n \t\t\t  1.Manchester United Vs Chelsea   [17.00-20.00]          ");
	printf("\n \t\t\t  2.Liverpool Vs Arsenal           [20.00-23.00]          ");
	printf("\n \t\t\t  3.Real Madrid Vs Barcelona       [20.30-24.00]          ");
	printf("\n \t\t\t----------------------------------------------------------");
	
	
	
	// AMIR PART
	switch(tchoice)
	{
		case 'S':
		case 's':													
					Thaqif(same,member);					
					TST_FILE(member,same);
				do	{
					x=0;
					choice = 0;
					printf("\nChoose your tournament:");
					scanf(" %c",&wchoice);
				    choice = strtol(wchoice,&dest,10); //MODIFIED BY AYMAN					
					
					
					
					
					
					
					switch(choice)
					{
						case 1: 
						    printf("%s %s",tour[0][0],tour[0][1]);
						break;
						
						case 2:
							printf("%s %s",tour[1][0],tour[1][1]);
						break;
						
						case 3:
							printf("%s %s",tour[2][0],tour[2][1]);
							break;
						default:
							printf("\nInvalid Tournament");
							x=1;		
					}	
					
					} while (x==1);
					
					printf("\n");
					
					//FUNCTION CALL
					Ayman(choice,same,member);
				    printf("\n");
				    AYU2(member,same,tchoice);
				    RESULT(member,same,tchoice);
			
				    break;	
///////////////////////////////////////////////////////////////////////////////////			
		case 'D':
		case 'd':	
			
			for(s=0;s<member;s++)
			{
				Thaqif(same,member);
				TST_FILE(member,same);
				do
					{
					x=0;	
					printf("\nChoose your tournament:"); 
					scanf(" %c",&wchoice);
					choice = strtol(wchoice,&dest,10);
				
					
					switch(choice)
					{
						case 1: 
						    printf("%s %s",tour[0][0],tour[0][1]);
						break;
						
						case 2:
							printf("%s %s",tour[1][0],tour[1][1]);
						break;
						
						case 3:
							printf("%s %s",tour[2][0],tour[2][1]);
							break;
						default:
							printf("\nInvalid Tournament");
							x=1;		
					}	
					
					} while (x==1);
						printf("\n");
						
						//FUNCTION CALL	
						Ayman(choice,same,member);
				    	printf("\n");
				    	AYU2(member,same,tchoice); 
				    	RESULT(member,same,tchoice);
					
			}
			        break;
			 /// case D
	}
	
	
	
	
	
	
	
}








// THAQIF PART
void Thaqif(int same,int member){
	char name[member][50];
	char lol[member][50];
	char users[member][50];
	int i;
	FILE *ptr;
	
	
	(getchar());
	for(i=0;i<same;i++)
	{
		printf("\n Insert name : ");
		
		fgets(name[i],50,stdin);
	}
	
	ptr = fopen("lol.txt","a");
	for(i=0;i<same;i++)
	{
		fprintf(ptr,"%s",name[i]);
	}
 
	fclose(ptr);

}




//MADE BY AYMAN
void TST_FILE(int member,int same){
	char name[member][50];
	char input[member][50];
	char result[member][50];
	int i,N,E,J;
	FILE *p;
	FILE *ptr;
	
	
	ptr = fopen("lol.txt","r");
	
	
	for(i=0;i<member;i++){
		
 	fgets(input[i],50,ptr);
 	input[i] [strcspn(input[i],"\r\n")]=0;
 	
 	sprintf(name[i],"%s.txt",input[i]);               //YG NI OK
 }  
   
	fclose(ptr);
	                                       //THIS PROGRAM MIGHT BE LOOPED MORE THAN ONCE, EACH LOOP IS A DIFFERENT PERSON
	                                        //ESPECIALLY WHEN GROUP CHOOSE D, IF THEY CHOOSE S, WE CAN JUST SIMPLY LOOP IT
											// BUT OPTION D IS DIFFERENT, D IS FOR SINGLE, DIFFERENT INDIVIDUALS,
											//MEANING THE FUNCTION CALL WILL BE CALLED MORE THAN ONCE.
											//TO ACCOMODATE FOR BOTH, WE STORE THE COUNTER GLOBALLY 
	for(i=0;i<same;i++){                    //N GETS VALUE FROM Q[0].V , INITIALLY ZERO
	N = Q[0].V;	                              
		p=fopen(name[N],"w");                // TASK // EACH LOOP N VALUE IS CHANGED,N=0 AND N= 1 ARE DIFFERENT PERSON
		
	N++;                                   //N INCREMENTS BY 1 AFTER THE TASK IS DONE
	Q[0].V = N;                            //Q[0].V IS UPDATED
	fclose(p);
	}

	
	for(i=0;i<same;i++){
	
		J = Q[0].J;
		p=fopen(name[J],"a");
		fprintf(p,"%s",input[J]);  
		J++;
		Q[0].J = J;
	fclose(p);
	}
	
	
	//test
		for(i=0;i<same;i++){
	E = Q[0].E;		
	
		printf(" HI %s!\n",input[E]);
	E ++;
	Q[0].E = E;	
			fclose(p);
	}

	
	

	
}













//AYMAN PART
void Ayman(int tournament,int same,int member){
	int i,k,j,h,n,y,z;
	int choice;
	int x=0;
	char opt[member][50];
	char users[member][50];
	char filename[member][50];
	char seat_type[50];
	float price;
	//FILE *output;
	FILE *T;
	FILE *input;
	
	                          //0                1           2
	char menu[3][3][20]={   {"| NORMAL |","| NORMAL |","| NORMAL |"}, //0
	                        {"----------","----------","----------"},//1
	                        {"|  VIP   |","|  VIP   |","|  VIP   |"}//2
											
	};
	

	
	
	int compare[6];                //= {11,11,11,11,11,11};
	
	switch(tournament){
		case 1:
			   for(h=0;h<6;h++){
			   	compare[h]= seat[h].chosen_seat1;
			   	if(compare[h] == 1 || compare[h] == 2 || compare[h]== 3){
			   		strcpy(menu[0][compare[h] -1],"| PICKED |");
				   } else if(compare[h] == 4 || compare[h] == 5 || compare[h]== 6){
				   	strcpy(menu[2][compare[h] - 4],"| PICKED |");
				   }
			   	
			   }
			   for(h=0;h<same;h++){
			   z = Q[1].m; // z = 0
			   strcpy(opt[z],"TOURNAMENT 1");
			   z++;
			   Q[1].m = z;
		                          }
			  
			   break;
		case 2:
		       for(h=0;h<6;h++){
			   	compare[h]= seat[h].chosen_seat2;
			   		if(compare[h] == 1 || compare[h] == 2 || compare[h]== 3){
			   		strcpy(menu[0][compare[h] -1],"| PICKED |");
				   } else if(compare[h] == 4 || compare[h] == 5 || compare[h]== 6){
				   	strcpy(menu[2][compare[h] - 4],"| PICKED |");
				   }
			   	
			   	
			                   }
			   for(h=0;h<same;h++){
			   z = Q[1].m;
			   strcpy(opt[z],"TOURNAMENT 2");
			   z++;
			   Q[1].m = z;
		                          }
			 
			   break;
		case 3:
		       for(h=0;h<6;h++){
			   	compare[h]= seat[h].chosen_seat3;
			   		if(compare[h] == 1 || compare[h] == 2 || compare[h]== 3){
			   		strcpy(menu[0][compare[h] -1],"| PICKED |");
				   } else if(compare[h] == 4 || compare[h] == 5 || compare[h]== 6){
				   	strcpy(menu[2][compare[h] - 4],"| PICKED |");
				   }
			   	
			   	
			                   }
			   for(h=0;h<same;h++){
			   z = Q[1].m;
			   strcpy(opt[z],"TOURNAMENT 3");
			   z++;
			   Q[1].m = z;
			 
	               	              }
			  
			   break;	   	   
	                    }
	

	input = fopen("lol.txt","r");
	for(i=0;i<member;i++){
 	fgets(users[i],50,input);
 	users[i] [strcspn(users[i],"\r\n")]=0; //since its not from stdin not needed?
 	sprintf(filename[i],"%s.txt",users[i]);
 	//printf("\n%s",filename[i]);
 }  

fclose(input);




	//if(z ==1 || same == 1){
	
	printf("\t\t\t\t\t%s%s%s\n"
	       "\t\t\t\t\t------------------------------\n"
		   "\t\t\t\t\t%s%s%s\n",menu[0][0],menu[0][1],menu[0][2],menu[2][0],menu[2][1],menu[2][2]);
//	}

	printf("Normal seat\t: RM 100\n");
	printf("VIP seat\t: RM 200\n");	

//START LOOP here
   for(j=0;j<same;j++)	{
 






	
do{
	
	
 printf("\nEnter your seat : ");
 scanf("%d",&choice);

 x=0;
//lets say they enter the same seat number
 for(i=0;i<6;i++){


 if(choice== compare[i] ){
	x=1;
	printf("\n REDO");
                         }
                         
                 }







switch(choice){
	case 1:
    case 2:
    case 3:
    	   strcpy(menu[0][choice-1],"| PICKED |");
    	   compare[choice-1]= choice;
    	   
		   if(tournament == 1){
		   //put here the data want to put in output.txt
		   seat[choice -1].chosen_seat1= choice;
		   
	                          }else if(tournament == 2){
	                          	
		                               seat[choice -1].chosen_seat2= choice;
		                               
	                          }else if(tournament == 3){
	                          	
		                               seat[choice -1].chosen_seat3= choice;
	}
    	   break;
    	   
    case 4:
    	   strcpy(menu[2][0],"| PICKED |");
		   	compare[3]= choice;
		   	
		   	if(tournament == 1){
		   		
		   		seat[3].chosen_seat1= choice;
		   		
			   }else if(tournament == 2){
			   	
			   	seat[3].chosen_seat2= choice;
			   	
			   }else if(tournament == 3){
			   	
			   	seat[3].chosen_seat3= choice;
			   	
			   }
			   
    	   break;
	case 5:
		  strcpy(menu[2][1],"| PICKED |");
		  	compare[4]= choice;
		  	if(tournament == 1){
		  		
		  		seat[4].chosen_seat1= choice;
		  		
			  }else if(tournament == 2){
			  	
			  	seat[4].chosen_seat2= choice;
			  	
			  }else if(tournament == 3){
			  	
			  	seat[4].chosen_seat3= choice;
			  	
			  }
			  
			  
		  break;
	case 6:
		   strcpy(menu[2][2],"| PICKED |");	
		   compare[5]= choice;
		   
		   if(tournament == 1){
		   	
		   	seat[5].chosen_seat1= choice;
		   	
		   }else if(tournament == 2){
		   	
		   	seat[5].chosen_seat2= choice;
		   	
		   }else if(tournament == 3){
		   	
		   	seat[5].chosen_seat3= choice;
		   	
		   }
		   
	         
		   break; 
}


	for(i=0;i<3;i++){
		
		printf("\n");
		
		for(k=0;k<3;k++){
			
			printf("%s",menu[i][k]);
			
		                }
		                
	                }	
}while(x==1);

	                         //



switch(choice){
	case 1:
	case 2:
	case 3:
		   strcpy(seat_type,"Normal Seat");
		   price = 100;
		   break;
	case 4:
	case 5:
	case 6:
		   strcpy(seat_type,"  VIP  Seat");
		   price = 200;
		   break;
}

//OUTPUT KUMPUL  //jenis tournament, seat choice 
 y = Q[0].M;
 T = fopen(filename[y],"a");  //Hold on
 opt[y][strcspn(opt[y],"\r\n")]=0;
 fprintf(T,"\t%-s  Seat %d (%s : RM %.2f)\n",opt[y],choice,seat_type,price);
 //fprintf(T,"\t%-s  Seat %d\n",opt[y],choice);
 y++;
 Q[0].M = y;
 
fclose(T);


}//end OF LOOP



}



void AYU2(int member,int same,char tchoice){

	int H;
	FILE *BEV;
	FILE *IN;
	FILE *B;
	char username[member][50];
	char XD[member][50];
	char chosen[50];
	char price[50];
	char temp[50];
	
//copy pasted from ayu	
	char menu [5][2][100]={
	                      {"a) COLA COLA\t\t\t\t","RM 1.50"},
	                      {"b) HEAVEN AND EARTH\t\t\t","RM 1.80"},
	                      {"c) MINERAL WATER\t\t\t","RM 1.00"},
						  {"d) CORN DOG MOZARELLA\t\t\t","RM 15.00"},
						  {"e) KUACI\t\t\t\t", "RM 5.00"}
						  };
	int choice, x=0,i,k,s,l;
	char code,pin,addon;	
////////////////////////////////////////////	

	
	H = Q[1].E;
	

	
	IN = fopen("lol.txt","r");
    for(i=0;i<member;i++){
    	
	
	fgets(XD[i],50,IN);
    XD[i] [strcspn(XD[i],"\n")]=0;
}
	fclose(IN);
	
	
		if(tchoice == 'D' || tchoice == 'd'){
	
	sprintf(username[H],"%s.txt",XD[H]);
	
}
	

	printf("\nWould u like to addon bevg  [Y/N] : ");
	scanf(" %c",&code);
	

	switch(code)
	{
		case 'Y':
		case 'y':
	    		BEV = fopen(username[H],"a");
	 
	 			fprintf(BEV,"%s\n","--------------------------------------------------------");
	 			fprintf(BEV,"%s\n","                       BEVERAGE                         ");
	 			fprintf(BEV,"%s\n","--------------------------------------------------------");
	 			fprintf(BEV,"%s\n","   NAME                  			PRICE ");
				fclose(BEV);
			
				printf("\n CHOOSE YOUR BEVRAGES                  Price               ");
	          
	            printf("\n");
	         
			
			for(i=0;i<5;i++)
			{
				printf("\n");
			for(k=0;k<2;k++)
			{
			
				printf("%s",menu[i][k]);
			}	
			   
			}
		
			
			
			
			
			
	
	
	
			
			
		
	
	//start do
	do{
	     do{
			printf("\n"); 
			printf("\n Enter code beverages:");
            scanf(" %c",&pin);
	
	//lepas pin
		switch(pin)
    {
    	case 'a':
    			printf("%s %s",menu[0][0],menu[0][1]);
    			strcpy(chosen,menu[0][0]);
    			strcpy(price,menu[0][1]);
    
        x=0;
    	break;
    	
    	case 'b':
    			printf("%s %s",menu[1][0],menu[1][1]);
    			strcpy(chosen,menu[1][0]);
    			strcpy(price,menu[1][1]);
    			x=0;
    
    	break;
    	
    	case 'c':
    			printf("%s %s",menu[2][0],menu[2][1]);
    			strcpy(chosen,menu[2][0]);
    			strcpy(price,menu[2][1]);
    			x=0;
    
    	break;
    	
    	case 'd':
    			printf("%s %s",menu[3][0],menu[3][1]);
    			strcpy(chosen,menu[3][0]);
    			strcpy(price,menu[3][1]);
    			x=0;
    
    	break;
    	
    	case 'e':
    			printf("%s %s",menu[4][0],menu[4][1]);
    			strcpy(chosen,menu[4][0]);
    			strcpy(price,menu[4][1]);
    			x=0;
    
    	break;
    	
    	default:
				printf("\nInvalid Beverages");
				printf("\nReenter with valid options please!");
				x=1;
		break;
   	}
   	
   	
       }while(x==1);
       
       
       
	//tanya
	printf("\nDo you want add anymore beverages [Y/N]? ");
   	scanf(" %c",&addon);
   	
   	
   	
   	if(tchoice == 'D' || tchoice == 'd'){
	
	
	BEV = fopen(username[H],"a");
	fprintf(BEV,"%s\t%s\n",chosen,price); //Testing testing
	strcpy(chosen,"\0");
	strcpy(price,"\0");
	
	fclose(BEV);
     }
     else if(tchoice == 'S' || tchoice == 's'){
     B = fopen("BEVERAGE.txt","a");
     fprintf(B,"%s\t%s\n",chosen,price); //Testing testing
	 strcpy(chosen,"\0");
	 strcpy(price,"\0");
     fclose(B);	
                            }
}while(addon=='Y');
                 break;

       case 'N':
       case 'n':
	             printf("\n No beverage(s) is ordered");
				 printf("\n");	
				 if(tchoice == 'S' || tchoice == 's'){
			
					B = fopen("BEVERAGE.txt","w");
					      fprintf(B,"%s","\0");
						  fclose(B);	  				 	
				 }
				 break;
}
	
	
	
	H++;
	Q[1].E = H;	

}
















 


void RESULT(int member,int same,char tchoice){
int i,k,H;
FILE *ptr;

	FILE *output;
	


char xd[member][50];
char lol[member][50];
char opt[member][1000];


	ptr = fopen("lol.txt","r");
	for(i=0;i<member;i++){
 	fgets(lol[i],50,ptr);
 	lol[i] [strcspn(lol[i],"\r\n")]=0;
 	sprintf(xd[i],"%s.txt",lol[i]);
 }  
   
	fclose(ptr);
	
	printf("\n");
	
    for(i=0;i<same;i++){
		
	H = Q[0].m;	
		
	if(tchoice == 'S' || tchoice == 's'){
	
		output = fopen(xd[H],"r");



	fgets(opt[H],1000,output);
	opt[H] [strcspn(opt[H],"\r\n")]=0;
	printf("%s\n",opt[H]); //\T
	
	fclose(output);
}else if(tchoice == 'D' || tchoice == 'd'){

	Ayman2(member,same,tchoice);
}
	H++;
	Q[0].m = H;
//	fgets(lol[i],50,ptr);
	

}
if(tchoice == 'S' || tchoice == 's'){
	
printf("\n");

Ayman2(member,same,tchoice);

printf("\n");


}
sleep(1);

	







}











void Ayman2(int member,int same,char tchoice){
	FILE *A;
	FILE *B;
	FILE *C;
	char BEV[50];
	char name[member][50];
	char input[member][50];
	char output[1000];
	int i;
	int L;
	
	if(tchoice == 'S' || tchoice == 's'){
	A= fopen ("BEVERAGE.txt","r");
	while(fgets(BEV,50,A)){
	printf("%s",BEV);
		
		
                          }
    fclose(A);                      
		
	} //IF s
	else if(tchoice == 'D' || tchoice == 'd'){
		B = fopen("lol.txt","r");
		
		for(i=0;i<member;i++){
		
 			fgets(input[i],50,B);
 			input[i] [strcspn(input[i],"\r\n")]=0;
 	
 	
 	
                             }
	


		L = Q[1].J;
		sprintf(name[L],"%s.txt",input[L]);               //YG NI OK
		C = fopen(name[L],"r");
			
		while(fgets(output,1000,C)){
			
				printf("%s",output);
			}
		fclose(C);	
		L++;
 	    Q[1].J = L;
 
      fclose(B);
	}
	
}






void DEL_FILE(int member){
	FILE *B;
	//FILE *C;
	char list[member][50];
	char username[member][50];
	int i;
	int check;
	B = fopen("lol.txt","r");
	    for(i=0;i<member;i++){
	    	fgets(list[i],50,B);
	    	list[i] [strcspn(list[i],"\n")]=0;
	    //	printf("%s\n",list[i]);
	    	sprintf(username[i],"%s.txt",list[i]);
	    //	printf("%s\n",username[i]);
		}
	fclose(B);
	
	remove("BEVERAGE.txt");
	
	for(i=0;i<member;i++){
	
	//check = unlink(username[i]);
          check = remove(username[i]);    
		          }
    
	
	if(check == 0){
    	printf("\n");
    	printf("\n");
    	printf("Cleaning up files...\n");
    	printf("Please wait ...\n");
    	sleep(10);
    	printf("Success!\n");
    }
    else{
    	printf("\n check again pls");
	}
}
