#include"Headerfile.h"

int main()
{
    char mypara;
    system("cls");
    ifstream in_file ("first.txt",ios::in);
    ofstream out_file ("Second.txt",ios::out);

    if(!in_file  &&  !out_file)
    {
        cout<<"Files could not opened!!!\n\tProgram Error!!"<<endl;
        system("exit");
    }
    else
    {
        while (in_file)
        {
            in_file.get(mypara); 
            out_file<<mypara;
            
        }
        
    }
    in_file.close();
    out_file.close();
    
    return 0;
}