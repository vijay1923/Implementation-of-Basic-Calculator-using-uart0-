// MINI-PROJECT 2
// IMPLEMENT CALCULATOR APPLICATION USING UART PROTOCOL  
#include<lpc21xx.h>
#include"header.h"

int i,j,n1=0,n2=0,result;
unsigned char s[30];		// FOR STORING INPUT INTO A STRING 
int main()
{
uart0_init(9600);
	while(1)
	{
		n1=0;n2=0;result=0;		// INITIALY N1,N2 AND RESULT HAS TO '0' 
		uart0_tx_string("Enter the Expr : ");
		//uart0_tx_string("\r\n");
		uart0_rx_string(s,20); 		// TACKING INPUT FROM USR IN FORM OF STRING 
uart0_tx_string(s);
		uart0_tx_string("\r\n");
	// FOR NUMBER 1
if(s[0]=='-')			// IF 1ST NUMBER IS NEGATIVE 
	i=1;
else 
	i=0;
 for(i;s[i];i++)
 {
	 if(s[i]>='0' && s[i]<='9')
   n1=n1*10+(s[i]-48);				// FOR STRORING NUMBER 1
	 else
		 break; 	 
 }
  if(s[0]=='-')
	n1=-n1;


// FOR NUMBER 2
	for(j=i+1;s[j];j++)
    {
		  if(s[j]>='0' && s[j]<='9')
				n2=n2*10+(s[j]-48); 		//FOR STORING NUMBER 2
			else
				break;
		}
			
uart0_tx_string("Result : ");
		// FOR CALCULATIONS
switch(s[i])
 {
  case '+':result=n1+n2;break;
	case '-':result=n1-n2;break;
	case '*':result=n1*n2;break;
	case '/':result=n1/n2;break;
  default :uart0_tx_string("Invalid Operator\r\n");			// IF USER INTERED WRONG OPERATOR
 }	
uart0_tx_integer(result);		// DISPLAYING RESULT 
uart0_tx_string("\r\n"); 		// FOR NEW LINE 
		
}
}
