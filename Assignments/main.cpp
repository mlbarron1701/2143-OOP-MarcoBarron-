 /*
   /$$$$$$   /$$$$$$   /$$$$$$                               
  /$$__  $$ /$$$_  $$ /$$__  $$                              
 | $$  \ $$| $$$$\ $$|__/  \ $$                              
 | $$$$$$$$| $$ $$ $$   /$$$$$/                              
 | $$__  $$| $$\ $$$$  |___  $$                              
 | $$  | $$| $$ \ $$$ /$$  \ $$                              
 | $$  | $$|  $$$$$$/|  $$$$$$/                              
 |__/  |__/ \______/  \______/                               
                                                             
                                                             
                                                             
   /$$$$$$    /$$ /$$   /$$  /$$$$$$                         
  /$$__  $$ /$$$$| $$  | $$ /$$__  $$                        
 |__/  \ $$|_  $$| $$  | $$|__/  \ $$                        
   /$$$$$$/  | $$| $$$$$$$$   /$$$$$/                        
  /$$____/   | $$|_____  $$  |___  $$                        
 | $$        | $$      | $$ /$$  \ $$                        
 | $$$$$$$$ /$$$$$$    | $$|  $$$$$$/                        
 |________/|______/    |__/ \______/                         
                                                             
                                                             
                                                             
  /$$$$$$$                                                   
 | $$__  $$                                                  
 | $$  \ $$  /$$$$$$   /$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$$ 
 | $$$$$$$  |____  $$ /$$__  $$ /$$__  $$ /$$__  $$| $$__  $$
 | $$__  $$  /$$$$$$$| $$  \__/| $$  \__/| $$  \ $$| $$  \ $$
 | $$  \ $$ /$$__  $$| $$      | $$      | $$  | $$| $$  | $$
 | $$$$$$$/|  $$$$$$$| $$      | $$      |  $$$$$$/| $$  | $$
 |_______/  \_______/|__/      |__/       \______/ |__/  |__/
                                                             
*/

/*****************************************************************************
*                    
*  Author:           (Marco Barron )
*  Email:            (Marcoleon1701@gmail.com)
*  Label:            (02-AO3 Assignment 4)
*  Title:            (Basic Project Organization)
*  Course:           (2143-OOP)
*  Semester:         (Fall 2022)
* 
*  Description:
*        This program impliments an array as a circular queue that holds integers. 
*        Integers can be added by the user to the front of the list using the 
*        push function and data can be removed from the list using the pop function.
*  Usage:
*        how to use the program if necessary
* 
*  Files:            (main.cpp)
*****************************************************************************/

include <iostream>

using namespace std;

/**
 * CircularArrayQue
 * 
 * Description:
 *     This class creates a queue that can gain and lose integers based on user input.
 * 
 * Public Methods:
 *          void            Push(int item)
 *           
 *      
 * 
 * Private Methods:
 *          bool            full()
 *          void            init(int size = 0)
 *          int             Pop()
 *           
 *
 *
 *
 *
 *
 *
 * Usage: 
 * 
 *      CircularArrayQue(int size)       initializes the size of the array 
 *      
 *      
 */

class CircularArrayQue {
private:
    int *Container;                                   // Pointer to allocate dynamic array
    int Front;                                        // Int at the front of the queue 
    int Rear;                                         // Int at the rear of the queue 
    int QueSize;                                      // whole queue
    int CurrentSize;                                  // items in the queue    

        /**
     * Private : Init ()
     * 
     * Description:
     *      Inititalizes the queue to 0 
     * 
     * Params:
     *     
     *      int : array size 
     *      
     * Returns:
     *      void so nothing 
     */




    void init(int size = 0) {
        Front = Rear = CurrentSize = 0;
        QueSize = size;
    }

    
 /**
     * Private : Full ()
     * 
     * Description:
     *      Tells if the queue is full or not
     * 
     * Params:
     *      
     *      
     *      int : array size 
     *      
     * 
     * Returns:
     *      An integer if the queue is full 
     */


    bool Full() {                                     // true or false function 
        return CurrentSize == QueSize;                // returns int of full
    }

public:


 /**
     * Public : CircularArrayQue 
     * 
     * Description:
     *      setter for the queue initialiec size to 10
     * 
     * Params:
     *      int     :  array size
     * 
     * Returns:
     */

    CircularArrayQue() {
        Container = new int[10];
        init(10);
    }

    /**
     * Public : CircularArrayQue 
     * 
     * Description:
     *      setter for the queue to be what the user imput
     * 
     * Params:
     *      int     :  array size
     * 
     * Returns:
     */      

    CircularArrayQue(int size) {
        Container = new int[size];
        init(size);
    }

 /**
     * Public : Push ()
     * 
     * Description:
     *     add an integer to the front of the list 
     * 
     * Params:
     *     
     * 
     * Returns:
     *      integer : adds item to the front of the que 
     */

    void Push(int item) {
        if (!Full()) {
            Container[Rear] = item;
            Rear = (Rear + 1) % QueSize;
            CurrentSize++;
        } else {
            cout << "FULL!!!!" << endl;
        }
    }


 /**
     * Public : Pop()
     * 
     * Description:
     *      removes an item from the queues rear 
     * 
     * Params:   
     *   
     * 
     * Returns:
     *      integer : removes item from the back of the que 
     */

    int Pop() {
        int temp = Container[Front];
        Front = (Front + 1) % QueSize;
        CurrentSize--;
        return temp;
    }

    
     //friend operator grants access to the private members of class
    friend ostream &operator<<(ostream &os, const CircularArrayQue &other); 
}; 

ostream &operator<<(ostream &os, const CircularArrayQue &other) {      

    for (int i = other.Front; i < other.CurrentSize; i = (i + 1) % other.QueSize) {
        os << other.Container[i] << " ";
    }
    os << endl;
    return os;
}

/**
 * Main Driver
 * 
 * For this program, the main driver was used to test the CircularArrayQue class
 * 
 */
int main() {
    CircularArrayQue C1(5);                   //declares an array with 5 spaces

    // C1.Push(34);
    // C1.Push(38);
    // C1.Push(44);
    // C1.Push(22);
    // C1.Push(99);
    // C1.Push(100);

    C1.Push(1);                               //pushes 1 to the front 
    C1.Push(2);                               //pushes 2 to the front 
    C1.Push(3);                               //pushes 3 to the front 
    // C1.Push(6);
    // C1.Push(7);
    cout << C1 << endl;                       // returns list 
    // C1.Push(1);
    // C1.Push(2);
    // C1.Push(3);

    cout << C1 << endl;
}