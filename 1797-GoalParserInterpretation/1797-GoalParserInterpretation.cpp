// Last updated: 30/07/2026, 10:22:16
class Solution {
public:
    string interpret(string command) {
        std::string result="";
        for(int i=0;i<command.length();i++){
            if(command[i]=='G'){
                result+='G';
            }else if(command[i]=='('){
                if(command[i+1]==')'){
                    result+='o';
                    i++;
                }else{
                    result+="al";
                    i+=3;
                }
            }
        }return result;
    }
};