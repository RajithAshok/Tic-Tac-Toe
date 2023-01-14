#include<iostream>
using namespace std;

class tictac
{
    int count1=0, count2=0;
    int* arr;
    char name1[30], name2[30];
    
    public:
        
        void read()
        {
            cout<<"\n\n\n\t\t\tTIC TAC TOE\n";
            cout<<"\t\t\n";
            cout<<"\t\t";
            cout<<"Enter Player 1 name: ";
            cin>>name1;
            cout<<"\t\t";
            cout<<"Enter player 2 name: ";
            cin>>name2;
            cout<<"\n\n";
        }
        
        void game()
        {
            int i, t, flag=0, win=0;
            
            arr = (int*)malloc(9*sizeof(int));
            
            for(i=0;i<99;i++) {
                arr[i] = 3;
            }
            
            cout<<"\t\t";
            for(i=0;i<9;i++) {
            
                arr[i]=0;
                cout<<" "<<i+1<<" ";
                  
                if((i+1)%3==0) {
                    cout<<endl;
                    cout<<"\t\t";
                }
            }
            
            while(true)
            {
                label:
                if(flag==0) {
                    cout<<" "<<name1<<"'s turn,enter position: ";
                }
                
                else {
                    cout<<" "<<name2<<"'s turn,enter position: ";
                }
                
                cin>>t;
                cout<<"\n";
                
                if(arr[t-1]!=0) {
                    cout<<"\t\t Invalid position!!!\n"<<endl;
                    cout<<"\t\t";
                    goto label;
                }
                
                else {
                    
                    if(flag==0) {
                        arr[t-1]=1;
                    }
                    
                    else {
                        arr[t-1]=2;
                    }
                }
                
                cout<<"\t\t";
                for(i=0;i<9;i++) {
                    
                    if(arr[i]==0) {
                        cout<<" "<<i+1<<" ";
                    }
                    
                    else if(arr[i]==1) {
                        cout<<" O ";
                    }
                    
                    else {
                        cout<<" X ";
                    }
                    
                    if((i+1)%3==0) { 
                        cout<<endl;
                        cout<<"\t\t";
                    }
                } 
        
                if(arr[0]!=0 && arr[1]!=0 && arr[2]!=0) {
                    
                    if(arr[0]==arr[1] && arr[0]==arr[2]) {
                        win = arr[0];
                    }
                }
                
                if(arr[3]!=0 && arr[4]!=0 && arr[5]!=0) {
                    
                    if(arr[3]==arr[4] && arr[3]==arr[5]) {
                        win = arr[3];
                    }
                }
                
                if(arr[6]!=0 && arr[7]!=0 && arr[8]!=0) {
                
                    if(arr[6]==arr[7] && arr[6]==arr[8]) {
                        win = arr[6];
                    }
                }
                
                if(arr[0]!=0 && arr[3]!=0 && arr[6]!=0) {
                
                    if(arr[0]==arr[3] && arr[0]==arr[6]) {
                        win = arr[0];
                    }
                }
                
                if(arr[1]!=0 && arr[4]!=0 && arr[7]!=0) {
                    
                    if(arr[1]==arr[4] && arr[1]==arr[7]) {
                        win = arr[1];
                    }
                }
                
                if(arr[2]!=0 && arr[5]!=0 && arr[8]!=0) {
                    
                    if(arr[2]==arr[5] && arr[2]==arr[8]) {
                        win = arr[2];
                    }
                }
                
                if(arr[0]!=0 && arr[4]!=0 && arr[8]!=0) {
                    
                    if(arr[0]==arr[4] && arr[0]==arr[8]) {
                        win = arr[0];
                    }
                }
                
                if(arr[2]!=0 && arr[4]!=0 && arr[6]!=0) {
                    
                    if(arr[2]==arr[4] && arr[2]==arr[6]) {
                        win = arr[2];
                    }
                }
                
                if(arr[0]!=0 && arr[1]!=0 && arr[2]!=0 && arr[3]!=0 && arr[4]!=0 && arr[5]!=0 && arr[6]!=0 && arr[7]!=0 && arr[8]!=0) {
                    cout<<"\n";
                    cout<<"The match is draw";
                    cout<<"\n";
                    break;
                }
                
                if(win!=0) {
                    
                    if(win==1) {
                        cout<<"\n";
                        cout<<"Player "<<name1<<" wins!!!"<<endl;
                        count1++;
                        break;
                    }
                    
                    else {
                        cout<<"\n";
                        cout<<"Player "<<name2<<" wins!!!"<<endl;
                        count2++;
                        break;
                    }
                }
                
                if(flag==0) {
                    flag=1;
                }
                
                else {
                    flag=0;
                }
                cout<<endl;
                cout<<"\t\t";
            }
            free(arr);
        }
        
        void result()
        {
            cout<<"The score is "<<name1<<" "<<count1<<" and "<<name2<<" "<<count2<<endl;
        }
        
        void winner()
        {
            if(count1>count2) {
                cout<<"The winner is "<<name1<<endl;
            }
            
            else if(count2>count1) {
                cout<<"The winner is "<<name2<<endl;    
            }
            
            else {
                cout<<"It is a draw"<<endl;
            }
        }
};

int main()
{
    char a;
    int count=0;
    tictac obj;
    
    obj.read();
    
    do {
        obj.game();
        obj.result();
        count++;
        cout<<"Do you want to play again:Y/N"<<endl;
        cin>>a;
    }while(a=='Y' || a=='y');
    
    cout<<"\n"<<endl;
    cout<<"After "<<count<<" round(s)"<<endl;
    obj.winner();
    cout<<"\t\t\t\tThank you for playing"<<endl;
}