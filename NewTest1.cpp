#include "parse.cpp"
#include <map>
#include <fstream>
#include <vector>
#include <string>
 
int main()
{ 
	printf("Welcome to the TonySal test task. \n");
	printf("If you need help just put down command 'help'\n");
    printf("Enter command: ");
	string cmd, name;
	int id;
	
	//array to add node
	map< int, string > book;
	
	//init Parse object
	Parse parse;
	
	//filename to save current node state
	string filename = "stream.txt";
	
	while( cin >> cmd ) {
    	if ( cmd == "add"  ) {
			//add node to array
			cin >> id >> name;
            book[ id ] = name;
            cout << "Created" << endl;
            printf("\nEnter command: "); 
        } else if (cmd == "open") {
			// get content node from file
			
            char* buff=NULL;
            int length;
            ifstream is;
            is.open ("stream.txt", ios::in );

            // get length of file:
            is.seekg (0, ios::end);
            length = is.tellg();
            is.seekg (0, ios::beg);
            
            buff = new char [length];
            // read data as a block:
            is.read (buff,length);
            is.close();
            
            cout.write (buff,length);
            delete[] buff;
            buff = NULL; 
            
            
			/* string contentSource = parse.open(filename);
			cout << contentSource;*/
			printf("\n \nEnter command: ");
        } else if ( cmd == "save" ) {
			//build node state
			//save current node state to file
			
            string buildStringRelation("");
            map< int, string >::const_iterator i;
            
            for( i = book.begin(); i != book.end() ; ++i ) {
	          buildStringRelation.append("(");
              buildStringRelation.append(parse.IntToStr(i->first));
              buildStringRelation.append(")");
              buildStringRelation.append(i->second);
              buildStringRelation.append("  ");
              //buildStringRelation.append("\n");
            }
                     
            bool isSave = parse.save(filename, buildStringRelation);
            if(isSave) {
            	cout << "Save was success!\n";
            	printf("\nEnter command: ");
            } else {
        		cout << "Save was not success!\n";
        		printf("\nEnter command: ");
            }               
            
        } else if ( cmd == "delete" ){
			//delete element from array
            cin >> id;
            book.erase( id );
            cout << "Deleted" << endl;
            printf("\nEnter command: ");
    	} else if ( cmd == "show" ) {
			//show tree of elements
            map< int, string >::const_iterator i;
            for( i = book.begin(); i != book.end() ; ++i )
              cout << i->first << " " << i->second << endl;
              printf("\nEnter command: ");
        } else if ( cmd == "help") {
          printf("  add - create new node.\n");
          printf("  show - show all created node.\n");
          printf("  delete - delete node.\n");
          printf("  save - saved book to the stream.txt .\n");
          printf("  open - show all saved node on a console.\n");
          printf("  quit - exit console.\n");
          printf("\nEnter command: ");
        } else if ( cmd == "quit") {
			//exit
          	return 0;
        } else {
          	cerr << "Bad command '" << cmd << "'" << endl;
          	printf("\nEnter command: ");
        }   
    } // while( cin >> cmd )
 
    return 0;
} 
