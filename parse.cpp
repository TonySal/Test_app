#include "parse.h"

class Parse
{
public:

	std::string open_with_parse(const std::string filename)
	{
       return filename; 
  	}
	
	//std::string open(const std::string filename)
	//{
		/*
			open file and get content
		*/
		
	/*	ifstream s_file;
		s_file.open(filename.c_str());
		char content[sizeof(s_file)];
		if(s_file.is_open()) {
			while(!s_file.eof()) {
				s_file >> content;
			}
		}
		s_file.close();
		return string(content);   
	} */
    
    bool save(const std::string filename, const std::string content)
    {
		/*
			save content to txt file
		*/
		ofstream file;
		if(file) {
		   file.open(filename.c_str());  
		   file << content;
		   file.close();
		   return true;
		} else {
		   return false;
		}
    }
    
    std::string parse(const std::string content)
    {
    }
    std::string IntToStr(int x)
    {
        stringstream r;
        r << x;
        return r.str();
    }
};
