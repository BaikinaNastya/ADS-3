#include "tstack.h"
#include <string>

std::string infx2pstfx(std::string inf) {
  TStack<char> stack1;
    char buf[200], * str;
    int num=0;
    
    for ( int i = 0; inf[i] != '\0'; i++ ) {
        switch (inf[i]) {
            
            case '(':
            stack1.push(inf[i]); 
            break;
            
            case ')':
            while(stack1.get()!='(')
            {
                buf[num] = stack1.get();
                stack1.pop();
                num++;
            } 
            stack1.pop();
            break;
            
            case '+': case '-':
            if (stack1.isEmpty()==false) {
                if (stack1.get() == '(') {
                    stack1.push(inf[i]); 
                }
                else {
                    while(stack1.isEmpty()==false)
                    {
                        if (stack1.get() != '(') {
                            buf[num] = stack1.get();
                            stack1.pop();
                            num++;
                        }
                        else break;
                    } 
                    stack1.push(inf[i]);
                }
            }
            else {
                stack1.push(inf[i]);
            }
            break;
            
            case '*': case '/':
            if (stack1.isEmpty()==false) {
                if (stack1.get() != '/' && stack1.get() != '*') {
                    stack1.push(inf[i]); 
                }
                else {
                    while(stack1.isEmpty()==false)
                    {
                        if (stack1.get() == '/' || stack1.get() == '*') {
                            buf[num] = stack1.get();
                            stack1.pop();
                            num++;
                        }
                        else break;
                    } 
                    stack1.push(inf[i]);
                }
            }
            else 
                stack1.push(inf[i]);
            break;
            
            default:
            buf[num]=inf[i];
            num++;
            break;
        }
    }
    
    while(stack1.isEmpty()==false)
    {
        buf[num] = stack1.get();
        stack1.pop();
        num++;
    } 
    
    str = new char[num];
    for (int i=0; i<num; i++) {
        str[i]=buf[i];
    }  
    
    std::string pst(str, num);
    
    return pst;
}

int eval(std::string pst) {
  TStack<int> stack2;
    int num, operand1, operand2;
    
    for ( int i = 0; pst[i] != '\0'; i++ ) {
        switch (pst[i]) {
            
            case '+': 
            operand2 = stack2.get();
            stack2.pop();
            operand1 = stack2.get();
            stack2.pop();
            num = operand1 + operand2;
            stack2.push(num);
            break;
            
            case '-':
            operand2 = stack2.get();
            stack2.pop();
            operand1 = stack2.get();
            stack2.pop();
            num = operand1 - operand2;
            stack2.push(num);
            break;
            
            case '*': 
            operand2 = stack2.get();
            stack2.pop();
            operand1 = stack2.get();
            stack2.pop();
            num = operand1 * operand2;
            stack2.push(num);
            break;
            
            case '/':
            operand2 = stack2.get();
            stack2.pop();
            operand1 = stack2.get();
            stack2.pop();
            num = operand1 / operand2;
            stack2.push(num);
            break;
            
            default:
            if((int)pst[i]>47 && (int)pst[i]<58)
            {
                num = pst[i] - '0';
                stack2.push(num);
            }
            else {
                std::cout<<"Error.";
                return 0;
            }
            break;
        }
    }
    
    return stack2.get();
}
