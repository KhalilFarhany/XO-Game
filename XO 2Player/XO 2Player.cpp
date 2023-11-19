#include <iostream>
#include <string>
#include<windows.h>

using namespace std;

//add spaces to the left such nbChar + lenWord = newLen
string lFormat(string str, int newLen) {
    for (int i = 0; i < newLen;i++) {
        str = ' ' + str;
    }
    return str;
}

//Menu of my game
void menu(char arr[3][3]) {
    string strBegin = "",strEnd="",strMiddle="";
    for (int i = 0; i < 17; i++) {
        strBegin += (i == 5 || i == 11) ? char(194) : char(196);
    }
    
    for (int i = 0; i < 17; i++) {
        strMiddle += (i == 5 || i == 11) ? char(197) : char(196);
    }
    
    for (int i = 0; i < 17; i++) {
        strEnd += (i == 5 || i == 11) ? char(193) : char(196);
    }

    
    strBegin = char(218) + strBegin + char(191);
    strMiddle = char(195) + strMiddle + char(180);
    strEnd = char(192) + strEnd + char(217);
    cout << lFormat(strBegin, 25) << endl;
    for (int i = 0; i < 3; i++) {
        string str2 = "";
        str2 = str2 + char(179);
        cout << lFormat(str2, 25) ;
        for (int j = 0; j < 3; j++) {
            cout << "  "<< arr[i][j] <<"  " << str2;
        }
        cout << endl;
        (i < 2) ? cout << lFormat(strMiddle, 25) << endl : cout << lFormat(strEnd, 25) << endl;
    }
   
}

//read player (x or o) Positiion choice
int readChoice(char c) {
    int choice;
    do {
        cout << "Choice Your Position - Player <" << c << "> : ";
        cin >> choice;
    } while (choice < 1 || choice>9);
    return choice;
}

//veif line (x x x or o o o) win
bool verifLine(char arr[3][3], int i) {
    if (arr[i][0]  == arr[i][1]  && arr[i][1] == arr[i][2])
        return true;
        return false;
}
//verif column
bool verifColumn(char arr[3][3], int j) {
    if (arr[0][j] == arr[1][j] && arr[0][j] == arr[2][j])
        return true;
    return false;
}

//verif diagonal 1
bool verifDiagonal1(char arr[3][3]) {
    return(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]);
}

//verif Diagonal 2
bool  verifDiagonal2(char arr[3][3]) {
    return(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0]);
}

//verif all condition
char verifWin(char arr[3][3]) {
    if (verifDiagonal1(arr) || verifDiagonal2(arr))
        return arr[1][1];
    for (int i = 0; i < 3; i++) {
        if (verifLine(arr, i))
            return arr[i][0];
        if (verifColumn(arr, i))
            return arr[0][i];
    }
    return '0';
}

//enter Choice Position to array
void arrayRound(char arr[3][3], char choice, char xo) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (arr[i][j] == choice)
                arr[i][j] = xo;
        }
    }
}

//verif odd
bool isOdd(int num) {
    return (num % 2 == 0);
}

//calc number of number in matrix
int calcNumberInMatrix(char arr[3][3]) {
    int s = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!(arr[i][j] == 'X' || arr[i][j] == 'O'))
                s++;
        }
    }
    return s;
}

//Play
void play(char arr[3][3]) {
    bool test = false;
    int i = 0;
    int choice;
    while (calcNumberInMatrix(arr)>0) {
        menu(arr);
        cout << endl << endl;
        if (isOdd(i)) {
            choice = readChoice('X');
            cout << endl << endl;
            system("cls");
            arrayRound(arr, char(choice + 48), 'X');
        }
        else {
            choice = readChoice('O');
            cout << endl << endl;
            system("cls");
            arrayRound(arr, char(choice + 48), 'O');
        }
        if (verifWin(arr) != '0') {
            system("cls");
            arrayRound(arr, char(choice + 48), verifWin(arr));
            menu(arr);
            cout << endl << endl;     
            cout << "The Winer Is Player <" << verifWin(arr) << ">  .congratulation !!";
            system("color 2F");
            cout << endl << endl;
            test = true;
            break;
        }
        i++;
    }
    if (!test) {
        menu(arr);
        cout << endl << endl;
        cout << "No Winner !!";
        cout << endl << endl;
        system("color 6F");
    }
}

//read choice (repeat or no)
bool readRepeat() {
    int repeat;
    do {
        cout << "Do you want to repeat ?  "<<endl;
        cout << "1- YES " << endl;
        cout << "0- NO " << endl ;
        cin >> repeat;
    } while (repeat != 0 && repeat != 1);
    if (repeat==0)
    return false;
    return true;
}

//main
int main()
{
    bool repeat = true;
    while (repeat) {
        char arr[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };
        play(arr);
        repeat = readRepeat();
        system("cls");
        system("color 0F");
    }
    return 0;
}

