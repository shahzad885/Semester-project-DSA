#include<graphics.h>
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


struct edge {
    char dest;
    edge* link = NULL;
};

struct Queue {
    struct node* vertix = NULL;
    struct Queue* link = NULL;
} * rear = NULL, * front = NULL;

struct node {
    char name;
    int index;
    edge* adj = NULL;
    node* next = NULL;
} * start = NULL;;

void insert_node(char ch, int index);
node* find(char ch);
void insert_edge(char source, char dest);
void delete_node(char ch);
void delete_edge(char source, char dest);
void delnode_edge(char dest);
void display();
void bfs(char v);
void visualize(char arr[], int counter, struct Queue* front);
void push(node* vertix);
node* pop();
void qdisplay();
void displayIntro();
void displayProcedure();
void displayExample();
void displayTC();
void quiz();
void menu();

int main() {
   
    system("color f4");
   	menu();
		
	
}

void menu(){
	
 cout<<"  \t---------------------------------------      WELCOME TO BFS TUTORIAL       ------------------------------------ "<<endl;

    int choice;
    while(true){
    	cout<<endl;
    	cout<<endl;
    	cout<<"\t\t\t\t\t\t -----------------------------"<<endl;
    	cout<<"\t\t\t\t\t\t|  1.INTRODUCTION             |"<<endl;
    	cout <<"\t\t\t\t\t\t|  2.EXAMPLE                  |"<<endl;
        cout << "\t\t\t\t\t\t|  3.PROCEDURE                |"<<endl;
        cout << "\t\t\t\t\t\t|  4.TIME COMPLEXITY          |"<<endl;
        cout << "\t\t\t\t\t\t|  5.VISUALIZATION            | " <<endl;
        cout << "\t\t\t\t\t\t|  6.QUIZ                     |"  <<endl;
    	cout<<"\t\t\t\t\t\t -----------------------------"<<endl;
        cout << "\t\t\t\t\t\t   ENTER YOUR CHOICE: ";
		 
        
        cin >> choice;
        
        
        switch (choice) {
           
            case 1:
            	displayIntro();
           	    break;
		   	case 2:
		   		
		   		displayExample();
		   		break;
		   		
		   	case 3:
		   		displayProcedure();
		   		break;
		   		
		   	case 4:
		   	 displayTC();
		   		break;
		   		
		    case 5:
		    	
			initwindow(1380, 820, "BFS Visualization");
    		settextstyle(10, 0, 1); 
    		
    
            srand(time(0)); 

		    
		    for (int i = 0; i < 10; ++i) {
		        char nodeName = 'A' + i;
		        insert_node(nodeName, i);
		    }
		
		    
		    for (int i = 0; i < 20; ++i) {
		        char source = 'A' + rand() % 10;
		        char dest = 'A' + rand() % 10;
		        insert_edge(source, dest);
		    }
		
		 
		    cout << "BFS: ";
		    bfs('A'); 
		
		    getch();
		    closegraph();
//		    insert_node('A', 0);
//		    insert_node('B', 1);
//		    insert_node('C', 2);
//		    insert_node('D', 3);
//		    insert_node('E', 4);
//		    insert_node('F', 5);
//		    insert_node('G', 6);
//
//		    insert_edge('A', 'B');
//		    insert_edge('B', 'A');
//		    insert_edge('A', 'C');
//		    insert_edge('C', 'A'); 
//		    insert_edge('B', 'D');   
//		    insert_edge('D', 'B'); 
//		    insert_edge('B', 'E');
//		    insert_edge('E', 'B'); 
//		    insert_edge('C', 'F'); 
//		    insert_edge('F', 'C'); 
//		    insert_edge('C', 'G');
//		    insert_edge('G', 'C'); 
//		    cout<<"  \t\t\t\t\t\t   BFS:  ";
//		    bfs('A');
//		    getch();
//		    closegraph();
		    break;
		    
		    case 6:
                quiz();
                break;
           
            default:
            cout << "Invalid choice" << endl;
          
          
		}
		
	}//while
  	
	
}
void push(node* vertix) {
    struct Queue* temp = new Queue();
    temp->vertix = vertix;
    if (front == NULL) {
        front = temp;
    }
    else {
        rear->link = temp;
    }
    rear = temp;
}

node* pop() {
    if (front != NULL) {
        node* data = front->vertix;
        front = front->link;
        return data;
    }
    else {
        cout << "Stack underflow: ";
        rear = NULL;
        front = NULL;
        return NULL;
    }
}

void qdisplay() {
    struct Queue* q = front;
    while (q != NULL) {
        cout << q->vertix->name << endl;
        q = q->link;
    }
}


void insert_node(char ch, int index) {
    node* temp = new node();
    temp->name = ch;
    temp->index = index;
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        
        node* ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}


node* find(char ch) {
    node* ptr = start;
    while (ptr != NULL) {
        if (ptr->name == ch) {
            break;
        }
        else {
            ptr = ptr->next;
        }
    }
    return ptr;
}
void insert_edge(char source, char dest) {
    edge* ptr;
    edge* temp = new edge();
    node* u = find(source);
    node* v = find(dest);
    if (u == NULL || v == NULL) {
        cout << "Source or destination doesn't exist" << endl;
        return;
    }
    temp->dest = dest;
    temp->link = NULL;

    if (u->adj == NULL) {
        u->adj = temp;
    } else {
      
        ptr = u->adj;
        while (ptr->link != NULL) {
            ptr = ptr->link;
        }
        ptr->link = temp;
    }
}

/*void delete_node(char ch) {
    node* q = start;
    node* temp;
    if (q->name == ch) {
        temp = start;
        start = start->next;
        delete (temp);
        return;
    }
    while (q->next->next != NULL) {
        if (q->next->name == ch) {
            temp = q->next;
            q->next = q->next->next;
            delete (temp);
            return;
        }
        q = q->next;
    }
    if (q->next->name == ch) {
        temp = q->next;
        q->next = NULL;
        delete (temp);
        return;
    }
}

void delete_edge(char source, char dest) {
    node* ptr = start;
    edge* temp, * q;
    node* u = find(source);
    if (u == NULL) {
        cout << "Source doesn't exist" << endl;
        return;
    }
    if (u->adj->dest == dest) {
        temp = u->adj;
        u->adj = u->adj->link;
        delete (temp);
        return;
    }
    q = u->adj;
    while (q->link->link != NULL) {
        if (q->link->dest == dest) {
            temp = q->link;
            q->link = q->link->link;
            delete (temp);
            return;
        }
        q = q->link;
    }
    if (q->link->dest == dest) {
        temp = q->link;
        q->link = NULL;
        delete (temp);
        return;
    }
}

void delnode_edge(char dest) {
    node* ptr = start;
    edge* temp, * q;
    while (ptr != NULL) {
        if (ptr->adj->dest == dest) {
            temp = ptr->adj;
            ptr->adj = ptr->adj->link;
            delete (temp);
            continue;
        }
        q = ptr->adj;
        while (q->link->link != NULL) {
            if (q->link->dest == dest) {
                temp = q->link;
                q->link = q->link->link;
                delete (temp);
                continue;
            }
            q = q->link;
        }
        if (q->link->dest == dest) {
            temp = q->link;
            q->link = NULL;
            delete (temp);
        }
        ptr = ptr->next;
    }
}
*/
void display() {
    node* ptr = start;
    edge* q = NULL;
    while (ptr != NULL) {
        q = ptr->adj;
        cout << ptr->name << " : ";
        while (q != NULL) {
            cout << q->dest << " , ";
            q = q->link;
        }
        cout << endl;
        ptr = ptr->next;
    }
}

void bfs(char v) {
	int MAX =20;
    bool visited[MAX];
    char temp_array[MAX];
    int counter = 0;
    for (int i = 0; i < 20; i++) {
        visited[i] = false;
    }
    node* temp = NULL, * temp2 = NULL;
    node* q = find(v);
    cout << q->name << ", ";
    push(q);
    temp_array[counter] = q->name;
    counter++;
    // 1. Clear Screen 2. Iterate on temp_array 3. Iterate on queue
    visualize(temp_array, counter, front);
    getch();
    visited[q->index] = true;
    while (rear != NULL && front != NULL) {
        temp = pop();
        // 1. Clear Screen 2. Iterate on temp_array 3. Iterate on queue
        visualize(temp_array, counter, front);
        getch();
        edge* adj = temp->adj;
        while (adj != NULL) {
            temp2 = find(adj->dest);
            if (visited[temp2->index] == false) {
                cout << temp2->name << ", ";
                visited[temp2->index] = true;
                push(temp2);
                temp_array[counter] = temp2->name;
                counter++;
            }
            adj = adj->link;
        }
        // 1.Clear Screen 2. Iterate on temp_array 3. Iterate on queue
        visualize(temp_array, counter, front);
        getch();
    }
}

void visualize(char arr[], int counter, Queue* front) {
  
    cleardevice();
    string s1, s2;
  
    int output_x = 1050, output_y = 100, radius = 25;
    int rect_x = 50, rect_y = 50, width = 50, height = 50;
   
    outtextxy(rect_x - 5, 20, "Queue ");
    outtextxy(output_x - 32, output_y - 60, "BFS Traversed");
   
    line(rect_x - 5, rect_y - 5, 900, rect_y - 5);
    line(rect_x - 5, rect_y + height + 10, 900, rect_y + height + 10);
   
    for (int i = 0; i < counter; i++) {
        s1 = arr[i];
        circle(output_x, output_y, radius);
        outtextxy(output_x - 15, output_y - 15, &s1[0]);
        output_y = output_y + 80;
    }
    
    Queue* q = front;
    while (q != NULL) {
        rectangle(rect_x, rect_y, rect_x + width, rect_y + height);
        s2 = q->vertix->name;
        outtextxy(rect_x + 15, rect_y + 15, &s2[0]);
        rect_x = rect_x + 60;
        q = q->link;
    }
}

void displayIntro() {
	
    
    initwindow(1280, 800, "BFS INTRO");
    setbkcolor(WHITE);
    cleardevice();

    readimagefile("img/intro.jpg", 200, 100, 900,300);  

    getch();
    closegraph();



}

void displayProcedure(){
	
    initwindow(1280, 650, "PROCEDURE");
    setbkcolor(WHITE);
    cleardevice();


    readimagefile("img/procedure.jpg", 0, 0, 900, 350);  

    
    getch();
    closegraph();
	
}


void displayExample(){
	
	
	 initwindow(1280, 650, "BFS EXAMPLE");
    setbkcolor(WHITE);
    cleardevice();

    
    readimagefile("img/example.jpg", 0, 0, 900, 600);  

    getch();
    closegraph();
}


void displayTC(){
	
initwindow(1380, 650, "TIME COMPLEXITY");
    setbkcolor(WHITE);
    cleardevice();

    
    readimagefile("img/TC.jpg", 0, 0, 1080, 600);  

    
    getch();
    closegraph();
}




void showresult(int correct,int incorrect) {
	
    system("CLS");
    cout << "Quiz Results:" << endl;
    cout << "Correct Answers: " << correct << endl;
    cout << "Incorrect Answers: " << incorrect << endl;
}

void quiz() {
	int incorrect = 0;
    int correct = 0;
    int i = 0;
    char choice[50];

    // Question 1
system("CLS");
cout << "1. What does BFS stand for in the context of graph traversal?" << endl;
cout << "   a. Best-First Search" << endl;
cout << "   b. Breadth-First Search" << endl;
cout << "   c. Binary-First Search" << endl;
cout << "   d. Balanced-First Search" << endl;

cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}

// Question 2
system("CLS");
cout << "2. Which data structure is typically used to implement the BFS algorithm?" << endl;
cout << "   a. Stack" << endl;
cout << "   b. Queue" << endl;
cout << "   c. Array" << endl;
cout << "   d. Linked List" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}

// Question 3
system("CLS");
cout << "3. In BFS, which vertex is processed first?" << endl;
cout << "   a. The vertex with the lowest index" << endl;
cout << "   b. The vertex with the highest index" << endl;
cout << "   c. Any random vertex" << endl;
cout << "   d. The vertex at the front of the queue" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'd') {
    correct++;
}
else
{
	incorrect++;
}

// Question 4
system("CLS");
cout << "4. What is the main advantage of BFS over DFS (Depth-First Search)?" << endl;
cout << "   a. Simplicity" << endl;
cout << "   b. Memory Efficiency" << endl;
cout << "   c. Time Efficiency" << endl;
cout << "   d. All of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'd') {
    correct++;
}
else
{
	incorrect++;
}

// Question 5
system("CLS");
cout << "5. In a graph, what does an edge represent in BFS?" << endl;
cout << "   a. A connection between two vertices" << endl;
cout << "   b. A loop in the graph" << endl;
cout << "   c. A directed path" << endl;
cout << "   d. A disconnected node" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}
else
{
	incorrect++;
}

// Question 6
system("CLS");
cout << "6. How is BFS implemented in C++ for graph traversal?" << endl;
cout << "   a. Recursion" << endl;
cout << "   b. Iteration" << endl;
cout << "   c. Both a and b" << endl;
cout << "   d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}


// Question 7
system("CLS");
cout << "7. What is the purpose of the visited array in BFS?" << endl;
cout << "   a. To store the vertices" << endl;
cout << "   b. To mark visited vertices" << endl;
cout << "   c. To keep track of the queue" << endl;
cout << "   d. To store the graph structure" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}


// Question 8
system("CLS");
cout << "8. Which of the following is a standard library used in C++ for queues?" << endl;
cout << "   a. stack" << endl;
cout << "   b. list" << endl;
cout << "   c. queue" << endl;
cout << "   d. set" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}
else
{
	incorrect++;
}


// Question 9
system("CLS");
cout << "9. In BFS, what is the time complexity for visiting all vertices in a graph with V vertices and E edges?" << endl;
cout << "   a. O(V)" << endl;
cout << "   b. O(E)" << endl;
cout << "   c. O(V + E)" << endl;
cout << "   d. O(log V)" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}
else
{
	incorrect++;
}


// Question 10
system("CLS");
cout << "10. What happens if a graph contains a cycle in BFS traversal?" << endl;
cout << "    a. The algorithm terminates successfully" << endl;
cout << "    b. It leads to an infinite loop" << endl;
cout << "    c. The cycle is ignored" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}


// Question 11
system("CLS");
cout << "11. Which operation is performed on the nodes during BFS?" << endl;
cout << "    a. Insertion" << endl;
cout << "    b. Deletion" << endl;
cout << "    c. Both a and b" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}
else
{
	incorrect++;
}


// Question 12
system("CLS");
cout << "12. What is the space complexity of BFS?" << endl;
cout << "    a. O(V)" << endl;
cout << "    b. O(E)" << endl;
cout << "    c. O(V + E)" << endl;
cout << "    d. O(1)" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}
else
{
	incorrect++;
}


// Question 13
system("CLS");
cout << "13. In BFS, which vertex is explored first in a graph with multiple connected components?" << endl;
cout << "    a. Any random vertex" << endl;
cout << "    b. The vertex with the lowest index" << endl;
cout << "    c. The vertex with the highest index" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}

else
{
	incorrect++;
}


// Question 14
system("CLS");
cout << "14. What is the role of the queue in BFS?" << endl;
cout << "    a. To store vertices in a random order" << endl;
cout << "    b. To store vertices in a sorted order" << endl;
cout << "    c. To maintain the order of traversal" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}
else
{
	incorrect++;
}


// Question 15
system("CLS");
cout << "15. Which of the following is a real-world application of BFS?" << endl;
cout << "    a. Web Crawling" << endl;
cout << "    b. Sorting Arrays" << endl;
cout << "    c. Binary Search" << endl;
cout << "    d. QuickSort" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}
else
{
	incorrect++;
}

// Question 16
system("CLS");
cout << "16. What is the output of BFS on an unweighted graph with multiple connected components?" << endl;
cout << "    a. Single tree" << endl;
cout << "    b. Multiple trees" << endl;
cout << "    c. Single path" << endl;
cout << "    d. Single node" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}

// Question 17
system("CLS");
cout << "17. How does BFS guarantee that the shortest path is found in an unweighted graph?" << endl;
cout << "    a. It considers the vertices in ascending order" << endl;
cout << "    b. It considers the vertices in descending order" << endl;
cout << "    c. It considers all vertices at once" << endl;
cout << "    d. It doesn't guarantee the shortest path" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'c') {
    correct++;
}
else
{
	incorrect++;
}


// Question 18
system("CLS");
cout << "18. In BFS, what is the role of the adjacency list?" << endl;
cout << "    a. To store the vertices" << endl;
cout << "    b. To store the edges" << endl;
cout << "    c. To store the graph structure" << endl;
cout << "    d. To store the visited vertices" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}

// Question 19
system("CLS");
cout << "19. What is the purpose of the queue in BFS?" << endl;
cout << "    a. To store the graph vertices" << endl;
cout << "    b. To maintain the order of traversal" << endl;
cout << "    c. To store the visited vertices" << endl;
cout << "    d. To store the edges" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}


// Question 20
system("CLS");
cout << "20. In BFS, what happens if a vertex is encountered but is already marked as visited?" << endl;
cout << "    a. It is ignored" << endl;
cout << "    b. It is added to the queue" << endl;
cout << "    c. It leads to an error" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}
else
{
	incorrect++;
}


// Question 21
system("CLS");
cout << "21. How is the initial vertex added to the queue in BFS?" << endl;
cout << "    a. Push operation" << endl;
cout << "    b. Pop operation" << endl;
cout << "    c. Front operation" << endl;
cout << "    d. Rear operation" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}
else
{
	incorrect++;
}


// Question 22
system("CLS");
cout << "22. In BFS, which operation is performed on the rear of the queue?" << endl;
cout << "    a. Enqueue" << endl;
cout << "    b. Dequeue" << endl;
cout << "    c. Push" << endl;
cout << "    d. Pop**" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}
else
{
	incorrect++;
}


// Question 23
system("CLS");
cout << "23. In BFS, what does the 'front' pointer of the queue represent?" << endl;
cout << "    a. The first element of the queue" << endl;
cout << "    b. The last element of the queue" << endl;
cout << "    c. The middle element of the queue" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}
else
{
	incorrect++;
}


// Question 24
system("CLS");
cout << "24. What is the output of BFS on a disconnected graph?" << endl;
cout << "    a. Single tree" << endl;
cout << "    b. Multiple trees" << endl;
cout << "    c. Single path" << endl;
cout << "    d. Single node" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else
{
	incorrect++;
}


// Question 25
	system("CLS");
    cout << "25. What is the primary application of BFS in real-world scenarios?*" << endl;
    cout << "    a. Sorting" << endl;
    cout << "    b. Path finding" << endl;
    cout << "    c. Database Management" << endl;
    cout << "    d. Image Processing" << endl;
    cout << "Enter Your Answer" << endl;
    cin >> choice[i++];
    if (choice[i - 1] == 'b') {
        correct++;
    } else {
        incorrect++;
    }
 
     // Question 26
   
system("CLS");
cout << "26. In BFS, what is the role of the 'next' field in the node structure?*" << endl;
cout << "    a. To store the next node in the list" << endl;
cout << "    b. To store the previous node in the list" << endl;
cout << "    c. To store the adjacent edges" << endl;
cout << "    d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'a') {
    correct++;
}
else
{
    incorrect++;
}


    // Question 27
    system("CLS");
    cout << "27. In BFS, what does the 'rear' pointer of the queue represent?*" << endl;
    cout << "   a. The first element of the queue" << endl;
    cout << "   b. The last element of the queue" << endl;
    cout << "   c. The middle element of the queue" << endl;
    cout << "   d. None of the above" << endl;
    cout << "Enter Your Answer" << endl;
    cin >> choice[i++];
    if (choice[i - 1] == 'b') {
        correct++;
    } else {
        incorrect++;
    }

    // Question 28
	 system("CLS");
cout << "28. What is the primary drawback of BFS in terms of memory usage?*" << endl;
cout << "   a. It consumes less memory" << endl;
cout << "   b. It consumes more memory" << endl;
cout << "   c. It doesn't use memory" << endl;
cout << "   d. None of the above" << endl;
cout << "Enter Your Answer" << endl;
cin >> choice[i++];
if (choice[i - 1] == 'b') {
    correct++;
}
else {
    incorrect++;
}

    // Question 29
    system("CLS");
    
    cout << "29. In BFS, which condition is used to terminate the algorithm?*" << endl;
    cout << "   a. The queue is empty" << endl;
    cout << "   b. The queue is full" << endl;
    cout << "   c. The visited array is full" << endl;
    cout << "   d. The graph is disconnected" << endl;
    cout << "Enter Your Answer" << endl;
    cin >> choice[i++];
    if (choice[i - 1] == 'a') {
        correct++;
    } else {
        incorrect++;
    }

    // Question 30
    system("CLS");
    cout << "30. What is the main purpose of BFS in computer science?*" << endl;
    cout << "   a. Sorting" << endl;
    cout << "   b. Searching" << endl;
    cout << "   c. Graph Traversal" << endl;
    cout << "   d. Data Compression" << endl;
    cout << "Enter Your Answer" << endl;
    cin >> choice[i++];
    if (choice[i - 1] == 'c') {
        correct++;
    } else {
        incorrect++;
    }

    showresult(correct,incorrect);
    
    
}

