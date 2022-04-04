#include<bits/stdc++.h>//    
using namespace std;

struct HighPrecision{
	int len;
	int num[100000];
 }a,b,addresult,subresult; 
 
 void print(HighPrecision c){
	for(int i=c.len;i>0;i--)
		cout<<c.num[i];
}

 void subprint(HighPrecision c){
 	
	for(int i=c.len;i>0;i--)
		cout<<c.num[i];
	cout<<endl;
}

 void addprint(HighPrecision c){
 	cout<<"="; 
	for(int i=c.len;i>0;i--)
		cout<<c.num[i];
	cout<<endl;
}
 
 void add(HighPrecision a,HighPrecision b,HighPrecision &c){
 	
 	int len=b.len;
 	if(a.len>b.len)		len=a.len;
 	for(int i=1;i<=len;i++)	
 		c.num[i]=a.num[i]+b.num[i];
	 for(int k=1;k<len;k++)
	if(c.num[k]>=10){
 			//len+=1;
 			c.num[k+1]+=1;
 			c.num[k]-=10;
		 }
	 if(c.num[len+1]>0)
	 	len++;
	 	c.len=len;
 }
 
 void addwork(){
		add(a,b,addresult);
		print(a);
		cout<<"+";
		print(b);
		addprint(addresult);
	}
	
 int comp(HighPrecision a,HighPrecision b){
 	if(a.len>b.len)	return -1;
 	if(b.len>a.len)	return 1;
 	for(int i=a.len;i>0;i++){
 		if(a.num[i]>b.num[i])	return -1;
 		if(a.num[i]<b.num[i])	return 1;
 		if(a.num[i]==b.num[i])	return 0;
	 }
	
 }
 
 void sub(HighPrecision a,HighPrecision b,HighPrecision &c){
 	int len=b.len;
 	if(a.len>b.len)	len=a.len;
 //	memset(c.num,0,sizeof(c.num));
 	for(int i=1;i<=len;i++)	
 		c.num[i]=a.num[i]-b.num[i];
	 for(int k=1;k<len;k++)
	if(c.num[k]<0){
 			//len+=1;
 			c.num[k+1]-=1;
 			c.num[k]+=10;
		}
		 while(c.num[len]==0&&len>1)
		 	len-=1;
		 	c.len=len;
}
 
 
 void subwork(){
 	if(comp(a,b)>0)
 	{
 		
 		print(a);
	 	cout<<"-";
	 	print(b);
	 	cout<<"=";
		  cout<<"-";	 		
 		sub(b,a,subresult);
	 }
	 else 
	 {
	 	print(a);
	 	cout<<"-";
	 	print(b);
	 	cout<<"=";
	 	sub(a,b,subresult);
	 }
	 subprint(subresult);
 }
 
 void strtoHigh(string s,HighPrecision &c){
 	reverse(s.begin(),s.end());
 	for(int i=0;i<s.size();i++)
 		c.num[i+1]=int(s[i]-'0');
 	c.len=s.size();
 }
 void init(){
 	string strOne,strTwo;
 	cout<<"输入第一个数：\t";
 	cin>>strOne;
 	cout<<"输入第二个数：\t";
 	cin>>strTwo;
 //	cin>>strOne>>strTwo;
 	strtoHigh(strOne,a);
 	strtoHigh(strTwo,b);
 	
 //	add(a,b,result);
 //	print(a);
 //	print(b);
 	//subwork();
 //	addprint(addresult);
 }
 
int main(){	
	int flag=0;
	int contr=0;
	
	while(contr==0)
{
	cout<<"\t"<<"            "<<"\t"<<"高精度加减，支持十万位数字"<<"\t"<<endl;
 	cout<<"1，加法"<<"\t"<<"\t"<<"2，减法"<<endl;
 	
 	cin>>flag;
 	if(flag==1)	{
	 	init(); 
	 	 addwork();
		 } 
 	else 
	 if(flag==2){
	 	init(); 
	 	subwork();
		 } 
	 else{
	 	cout<<"目前仅支持加减法！\n退出"<<endl;
	 	exit(0);
		 }
	 cout<<endl<<"继续请输入0,按任意键(除0)退出"<<"\t"<<endl;
	 cin>>contr; 
	 	system("cls");
}
	 cout<<"退出"<<endl;
 //	system("cls");
 	//fclose(stdin);
//	 fclose(stdout);
 	return 0;
}
