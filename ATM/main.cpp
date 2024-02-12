#include<bits/stdc++.h>
using namespace std;

class ATM{
    private:
        int balance;
        vector<pair<string,int> >history;
    public:
        ATM(int balance=0){
            this->balance=balance;
        }
        
        void deposit(int amount){
            balance+=amount;
            history.push_back(make_pair("Deposit",amount));
            cout<<"Deposit secessfully"<<endl;
        }

        int getBalance(){
            return balance;
        }

        bool widthdraw(int amount){
            if(balance<amount){
                return false;
            }else{
                balance-=amount;
                history.push_back(make_pair("Withdraw",amount));
                return true;
            }
        }

        void showHistory(){
            for(int i=0;i<history.size();i++){
                cout<<history[i].first<<" : "<<history[i].second<<endl;
            }
            cout<<"Current balance : "<<getBalance()<<endl;
        }
};

int main(){
    ATM a;
    int choice;
    cout<<"---------- Welcome to ATM ----------"<<endl;
    cout<<"--------------- Menu --------------- "<<endl;
    do{
        cout<<"------------------------------------ "<<endl;
        cout<<"1. Show Balance"<<endl;
        cout<<"2. Withdraw Amount"<<endl;
        cout<<"3. Deposit Amount"<<endl;
        cout<<"4. Transaction History"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"------------------------------------ "<<endl;
        cout<<"choose a option"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout<<"Available Balance : "<<a.getBalance()<<endl;
            break;
        case 2:
            int Wamount;
            cout<<"Enter Amount : ";
            cin>>Wamount;
            if(a.widthdraw(Wamount)){
                cout<<"Please Collect Your Cash"<<endl;
            }else{
                cout<<"Insuficcient Balance"<<endl;
            }
            break;
        case 3:
            int Damount;
            cout<<"Enter Amount : ";
            cin>>Damount;
            a.deposit(Damount);
            break;
        case 4:
            a.showHistory();
            break;
        case 5:
            cout<<"Thank You !! Do Visit Again :)"<<endl;
            break;
        default:
            cout<<"Invalid Input"<<endl;
            break;
        }
    }while(choice!=5);
    return 0;
}