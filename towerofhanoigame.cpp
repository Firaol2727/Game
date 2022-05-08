#include <iostream>
#include <math.h>
//#include <windows.h>
#include <stdlib.h>
#include<stdlib.h>
#include<unistd.h>
#include<iomanip>
using namespace std;

//         GROUP NAME                  ID
//      1. KETEMA GIRMA             UGR/1004/12
//      2. Firaol Getachew          UGR/1364/12 
//      3. GETU HAILE               UGR/1589/12
structn node(){
    int value;
    Stack* next;
}
class Stack{
    public:
        int  count_C, disk, disk_move;
        
        
        void pop() {
        int top_val;
        if(*head==NULL)
            return 0;
        else {
        Stack* temp = new Stack();
        temp = *head;
        top_val = temp->value;
        *head=(*head)->next;
        delete temp;
        }
        
}


void displayA() {
    Stack* temp1 = new Stack();
    temp1 = head_a;
    cout <<"  🚪 A 🚪   "<<endl;
    cout <<" 🩹     🥖 "<<endl;
    while (temp1 !=NULL)
    {
        if(temp1->value !=0)
        cout <<"🚪   " << temp1->value <<"   🚪"<<endl;
       
        temp1 = temp1->next;
    }
     cout <<"🚪_______🚪 ";
}

void displayB() {
    Stack* temp2 = new Stack();
    temp2 = head_b;
    cout <<"\t\t\t\t  🚪 B 🚪   "<<endl;
    cout <<"\t\t\t\t 🩹     🥖 "<<endl;
    while (temp2 !=NULL)
    {
        if(temp2->value !=0)
        cout <<"\t\t\t\t🚪   " << temp2->value <<"   🚪"<<endl;
        temp2 = temp2->next;
    }
     cout <<"\t\t\t\t🚪_______🚪 "<<endl;
}

void displayC() { 
    Stack* temp3 = new Stack();
    temp3 = head_c;
    cout <<"\t\t\t\t\t\t\t\t  🚪 C 🚪   "<<endl;
    cout <<"\t\t\t\t\t\t\t\t 🩹     🥖 "<<endl;
    while (temp3 !=NULL)
    {
        if(temp3->value !=0)
        cout <<"\t\t\t\t\t\t\t\t🚪   " << temp3->value <<"   🚪"<<endl;
        temp3 = temp3->next;
    }
     cout <<"\t\t\t\t\t\t\t\t🚪_______🚪 "<<endl;
}

void read_No_Disk () {
   
    cout<< " ENTER NUMBER OF DISK: ";
    cin >>disk;
        a->value = disk;
        a->next = NULL;
    disk_move = pow(2,disk) +3;

    for (int i = disk-1; i > 0; i-- ) {
        push(i,&head_a);
    }
    cout<<endl;
}

void Main_menu() {
    cout<<endl;
    cout<< "\t 1. Move 💿 From A 🗑 to B 🗑"<<"      "<<"|     ";
    cout<< "\t 2. Move 📀 From A 🗑 to C 🗑"<<"      "<<"|     "<<endl;
    cout<< "\t 3. Move 💿 From B 🗑 to A 🗑"<<"      "<<"|     ";
    cout<< "\t 4. Move 📀 From B 🗑 to C 🗑"<<"      "<<"|     "<<endl;
    cout<< "\t 5. Move 💿 From C 🗑 to A 🗑"<<"      "<<"|     ";
    cout<< "\t 6. Move 📀 From C 🗑 to B 🗑"<<"      "<<"|     "<<endl;
    cout<<endl;
    cout<< "\t\t\t\t 7. 😊 RESTART 😊"<< endl;
    cout<<endl;
    cout<< "\t\t\t\t 8. 😥 EXIT 😥"<< endl;
    cout<<endl;
    cout<<endl;
}
void com(Stack *&giv,Stack *&rec){
    int key,key2;
        key = top(&giv);
        key2 = top(&rec);
        if (key2 == 0) {
            push(key, &rec);
            pop(&giv);
            disk_move--;  
            if(rec==head_c){
                count_C++;
            }
            
        }
        else if(key < key2){
            push(key, &rec);
            pop(&giv);
            disk_move--; 
            if(rec==head_c){
                count_C++;
            }
            
        }
        else
            disk_move--; 
}
int main() {
    head_a = a;
    head_b = b;
    head_c = c;
    count = 0;
    count_C  = 0;

    RESTART:
    Main_menu();
        int Move;
        int key2;
        int key;
    read_No_Disk();

    MAIN:
        if (count_C == disk) {
            displayA();  
            displayB();
            displayC();
            cout<<"\t "<< " LIFE💖: "<<disk_move<<endl;
            cout<< "CONGRA YOU WON!!!"<<endl;
             sleep(3);
            head_a=NULL;
            head_b=NULL;
            head_c=NULL;
            count_C=0;
            goto RESTART;
        }
        else if (count < disk_move) {
            displayA();  
            displayB();
            displayC();
            cout<<"\t "<< " LIFE💖: "<<disk_move<<endl;
            Main_menu();
        }
        else {
            cout<< "YOU LOST!!"<<endl;
            sleep(3);
            head_a=NULL;
            head_b=NULL;
            head_c=NULL;
            count=0;
            goto RESTART;
        }
    cout<<" ENTER: ";
    cin>>Move;
//head_a
    switch (Move) {
    case 1:
        com(head_a,head_b);
        goto MAIN;
    case 2:
        com(head_a,head_c);
        goto MAIN;
    case 3:
        com(head_b,head_a);
        goto MAIN;
    case 4:
        com(head_b,head_c);
        goto MAIN;
    case 5:
        com(head_c,head_a);
        goto MAIN;
    case 6:
        com(head_c,head_b);
        goto MAIN;
    case 7:
        head_a=NULL;
        head_b=NULL;
        head_c=NULL;
        count_C=0;
        goto RESTART;
    case 8:
        cout<<" THANK YOU!!";
        exit(0);
    default:
        cout<<" INVALID INPUT TRY AGAIN!!"<<endl;
        goto RESTART;
    }
    return 0;
}