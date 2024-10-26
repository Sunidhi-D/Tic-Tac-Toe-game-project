#include<iostream>
using namespace std;

char space[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int row,col;
char token='x';
bool tie=false;
string n1="",n2="";
void fun1(){
    
    cout<<"    |    |    "<<endl;
    cout<<" "<<space[0][0]<<"  | "<<space[0][1]<<"  |  "<<space[0][2]<<" "<<endl;
    cout<<"____|____|____"<<endl;
    cout<<"    |    |    "<<endl;
    cout<<" "<<space[1][0]<<"  | "<<space[1][1]<<"  |  "<<space[1][2]<<" "<<endl;
    cout<<"____|____|____"<<endl;
    cout<<"    |    |    "<<endl;
    cout<<" "<<space[2][0]<<"  | "<<space[2][1]<<"  |  "<<space[2][2]<<" "<<endl;
    cout<<"    |    |    "<<endl;
    
}

void fun2(string n1,string n2){
	int dig;
	
	if(token=='x'){
		cout<<n1<<" your chance.";
		cin>>dig;
	}
	
	if(token=='o'){
		cout<<n2<<" your chance.";
		cin>>dig;
	}
	
	if(dig==1){
		row=0,col=0;
	}
	
	if(dig==2){
		row=0,col=1;
	}
	
	if(dig==3){
		row=0,col=2;
	}
	
	if(dig==4){
		row=1,col=0;
	}
	
	if(dig==5){
		row=1,col=1;
	}
	
	if(dig==6){
		row=1,col=2;
	}
	
	if(dig==7){
		row=2,col=0;
	}
	
	if(dig==8){
		row=2,col=1;
	}
	
	if(dig==9){
		row=2,col=2;
	}
	
	else if(dig<1 && dig>9){
		cout<<"Invalid!!"<<endl;
	}
	
	if(token=='x'&& space[row][col]!='x' && space[row][col]!='o'){
		space[row][col]='x';
		token='o';
	}
	
	else if(token=='o'&& space[row][col]!='x' && space[row][col]!='o'){
		space[row][col]='o';
		token='x';
	}
	else{
		cout<<"There is no empty space!!"<<endl;
		fun2(n1,n2);
	}
	
}

bool fun3(){
	for(int i=0;i<3;i++){
		if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
			return true;
		}
	}
	if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[2][2]==space[1][1] && space[2][2]==space[3][0]){
		return true;
	}
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(space[i][j]!='x' && space[i][j]!='o'){
				return false;
			}
		}
	}
	tie=true;
	return false;
}

int main(){
	string n1,n2;
    cout<<"Enter the name of first player: ";
    getline(cin,n1);
    cout<<"Enter the name of second player: ";
    getline(cin,n2);
    cout<<n1<<" will play first.Then "<<n2<<endl;
    
	while(!fun3()){
		fun1();
		fun2(n1,n2);
		fun3();
	}
	
	if(token=='x' && tie==false){
		cout<<n2<<" wins!!";
	}
	else if(token=='o' && tie==false ){
		cout<<n1<<" wins!!";
	}
	else{
		cout<<"It's a draw!!";
	}
}