#include<iostream>
#include<string>
#include<climits>
using namespace std;

class Store{
    private:
    string item_name;
    int item_id;
    int item_price;
    public:
    Store()
    {

    }
    Store(string item_name,int item_id,int item_price)
    {
        this->item_name=item_name;
        this->item_id=item_id;
        this->item_price=item_price;
    }
    void display()
    {
        cout << "Name of item is : "<<item_name<<endl;
        cout << "Id of item is : "<<item_id<<endl;
        cout << "Price of item is : "<<item_price<<endl; 
    }
    int get_id()
    {
        return item_id;
    }
    int get_price()
    {
        return item_price;
    }
};
int max_item=10;
Store Array[10];
int counter =0;
void add_item()
{
    if(counter>=max_item)
    {   
        cout << "Inventory is full "<<endl;
        return;
    }
    string name;
    int item_id;
    int item_price;
    cout << "Add item in Inventory\n";
     cin.ignore();
    cout << "Enter item name :";
    getline(cin,name);
    cout << "Enter item id : ";
    cin >>item_id;
    cout << "Enter item price : ";
    cin >> item_price;
    Array[counter]=Store(name,item_id,item_price);
    counter++;
    cout << "Your item is Successfully added in inventory\n";
}
// remove recent element 
void remove_recent_item(){
    if(counter==0)
    {
        cout << "Inventory is empty\n";
        return;
    }
    counter--;
    cout << "Your recent item successfully removed from inventory\n";
}
// remove oldest element 
 void remove_oldest_item()
 {
    if(counter==0)
    {
        cout << "Inventory is empty\n";
        return;
    }
    for(int i=0;i<counter-1;i++)
    {
        Array[i]=Array[i+1];
    }
    counter--;
    cout << "Oldest item in your inventory is successfully removed \n";
 }
 // VIEW ALL ITEMS PRESENT IN INVENTORY
 void View_all_items()
 {
    if(counter==0)
    {
        cout << "Inventory is empty\n";
        return;
    }
    cout << "All items present in your Inventory \n";
    for(int i=0;i<counter;i++ )
    {
        Array[i].display();
    }
 }
void search_item()
{
    if(counter==0)
    {
        cout << "Inventory is empty\n";
        return;
    }
    cout << "Enter id no of item :";
    int id_no;
    cin>>id_no;
    bool item_found=false;
    for(int i=0;i<counter;i++)
    {
        if(Array[i].get_id()==id_no)
        {
            cout << "Item found\n";
            Array[i].display();
            item_found=true;
            break;
        }
        
    }
    if(!item_found)
    {
        cout << "Item is not found in the Inventory\n";
    }

}
void get_inventory_stats()
{
    int total_value=0;
    int max_price=INT_MIN;
    int min_price=INT_MAX;
    if(counter==0)
    {
        cout << "Inventory is empty\n";
        return;
    }
    for(int i=0;i<counter;i++)
    {
        int price=Array[i].get_price();
        total_value+=price;
        if(price>max_price)
        {
            max_price=price;
        }
        if(price<min_price)
        {
            min_price=price;
        }
    }
    double Average=total_value/counter;
    cout << "========Inventory stats======== \n";
    cout << "Maximum price of an item in inventary :"<<max_price<<endl;
    cout << "Minimum price of item in Inventory :" <<min_price<<endl;
    cout << "Total Value of Inventory is :"<<total_value<<endl;
    cout << "Average prices : "<<Average<<endl;
    cout << "Total items present in Inventory :"<<counter<<endl;
}
void displayMenu() {
    cout << "\n======================================" << endl;
    cout << "      INVENTORY MANAGEMENT SYSTEM     " << endl;
    cout << "======================================" << endl;
    cout << "1. Add New Item" << endl;
    cout << "2. Remove Recent Item" << endl;
    cout << "3. Remove Oldest Item" << endl;
    cout << "4. View All Inventory" << endl;
    cout << "5. Search for an Item" << endl;
    cout << "6. Get Inventory Statistics" << endl;
    cout << "7. Exit" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Select an option (1-7): ";
}
int main()
{
    int choice;
    do{
        displayMenu();
        cin >>choice;
        switch(choice)
        {
            case 1:
               add_item();
            break;
            case 2:
                remove_recent_item();
            break;
            case 3:
                remove_oldest_item();
            break;
            case 4:
                View_all_items();
            break;
            case 5:
                search_item();
            break;
            case 6:
                get_inventory_stats();
            break;
            case 7:
            cout << "Exiting\n";
            break;
            default:
            cout << "Invalid Choice \n";
            break;

        }
    }while(choice!=7);

    return 0;


}