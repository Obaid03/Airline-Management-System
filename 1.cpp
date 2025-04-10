#include <iostream>
#include <vector>
using namespace std;

int main() {
    bool flag = false;
    vector<int> nums = {1,2,3,4,5};
    int temp;
    do
    {
        cout << "Enter num" << endl;
        cin >> temp;
        for (int i : nums)
        {
            if (temp == i)
            {   
                cout << "if\n";
                flag = true;
                break;
            }
            else
            {   
                cout << "else\n";
                flag = false;
            }
        }
        cout << "out of for\n";
    }while(flag==false);
    cout << "out of do while\n";
}