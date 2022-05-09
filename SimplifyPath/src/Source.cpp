#include <vector>
#include <assert.h>
#include <string>
#include <iostream>
#include <algorithm>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        //Single period dot '.' refers to the current directoy
        //Double period dot '..' refers to the parent directory (i.e. up on directory)
        //Paths must always begin with a forward slash '/'
        //Directory names must never be separated by more or less than a single slash, i.e. parent/child/grandchild NOT parent//child.
        //The trailing directory must not end with a '/'
        //Root directory is referred to by a single forward slash '/' with no directory name.

        //Directory string format should be '/DIRECTORY'
        //Directory strings should be pushed to the back of their parent, iteratively....

       /* std::vector<std::string> dir; //A vector containing the directories
        int dir_index = 0;
        for (int i = 0; i < path.size(); ++i)        // This loop extracts the strings from between forward slashes and discards single 
        {                                           // period dots from path and places them into dir.
            if (path[i] == '.' & path[i + 1] != '.')
                ++dir_index;
            else if (path[i] == '/')
                ++dir_index;
            else
                dir.(static_cast<std::string>(path[i]));
        }
        */

        std::vector<std::string> dir; //A vector containing the directories
        std::string delim{ "/" };
        size_t pos = 0;
        std::string token;
        while ((pos = path.find(delim)) != std::string::npos)
        {
            token = path.substr(0, pos);
            if (token != "." & token != "")
            {
                dir.push_back(token);
                std::cout << token;
            }
            path.erase(0, pos + delim.length());
        }

        if(path != "." & path != "")
            dir.push_back(path);

        //Example
        /*
            INPUT: "/home//foo/"
            dir = {"home", "foo"}

            INPUT: "/a/b/./../../c/""
            dir = {"a", "b", "..", "..", "c"}
        */


        //Account for up relative path characters
        std::vector<std::string> simple_path;
        int simple_path_index = 0;

        
        for (int i = 0; i < dir.size(); ++i)
        {
            if (dir[i] != "..")
            {              
                if (simple_path.empty())
                {
                    std::cout << std::endl << "DEBUG: simple_path is empty - pushing back: " << dir[i];
                    simple_path.push_back(dir[i]);
                }
                else
                {
                    if (simple_path.size() > simple_path_index)
                    {
                        std::cout << std::endl << "DEBUG: overiting " << simple_path[simple_path_index]
                            << " with " << dir[i];

                        simple_path[simple_path_index] = dir[i];
                    }
                    else
                    {
                        std::cout << std::endl << "DEBUG: simple_path_index > simple_path.size() - pushing back: " << dir[i];
                        simple_path.push_back(dir[i]);
                    }
                }     
              
                ++simple_path_index; //Move index to the next directory.
              
            }
            else
            {
                //If the index is greater than one, then the path must go up.
                if (simple_path_index > 0)
                    --simple_path_index;
            }
        }



        std::string imploded;

        for (int i = 1; i < simple_path.size(); ++i)
        {
            if (imploded.size() == 0)
            {
                imploded = '/';
                imploded += simple_path[i].c_str();
            }
            else
            {
                imploded += '/';
                imploded += simple_path[i].c_str();
            }
        }

        return imploded;
    }
};

// DO NOT TOUCH THE STUFF BELOW! IT IS FOR THE EVALUATION
/*
std::string stringToString(std::string input) 
{
    assert(input.length() >= 2);
    std::string result;
    for (int i = 1; i < input.length() - 1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i + 1];
            switch (nextChar) {
            case '\"': result.push_back('\"'); break;
            case '/': result.push_back('/'); break;
            case '\\': result.push_back('\\'); break;
            case 'b': result.push_back('\b'); break;
            case 'f': result.push_back('\f'); break;
            case 'r': result.push_back('\r'); break;
            case 'n': result.push_back('\n'); break;
            case 't': result.push_back('\t'); break;
            default: break;
            }
            i++;
        }
        else {
            result.push_back(currentChar);
        }
    }
    return result;
}
*/
int main() {

    std::string ret = Solution().simplifyPath("/a/b/c/../d/../e/./");
    std::cout << std::endl << ret;
    return 0;
}