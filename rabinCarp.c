#include<stdio.h>
#include<string.h>
#define d 256
void search(char* str,char* pat,int q);

void main(void){
char str[]="AABBAB";
char pat[]="AB";
int q=101;
search(str,pat,q);
	
}

void search(char str[],char pat[],int q){
	int m=strlen(pat);
	int n=strlen(str);
	int s=0;
	int p=0;
	int h=1;
	int i,j;
	
	for(i=0;i<m-1;i++){
		h=(h*d)%q;
	}
	
	for(i=0;i<m;i++){
		p=(d*p+pat[i])%q;
		s=(d*s+str[i])%q;
	}

	for(i=0;i<=n-m;i++){

		if(p==s){
			for(j=0;j<m;j++){
				if(str[i+j]!=pat[j])
					break;
			}
			if(j==m)
				printf("pattern mached in index %d \n",i);
		}
		if(i<n-m){
		s=(d*(s-str[i]*h)+str[i+m])%q;
		if(s<0){
			s=s+q;
		}
	}
	}
	
	
}
