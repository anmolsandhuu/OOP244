#include <iostream>
using namespace std;
#include <iomanip>
#include <cstring>
#include "ErrorState.h"

namespace AMA {
    
    ErrorState ::ErrorState(){
        error_message = nullptr;
    }
    
    ErrorState:: ErrorState(const char* errorMessage){

            if(errorMessage != nullptr){
            error_message = new char[strlen(errorMessage) +1];
             strncpy(error_message ,errorMessage, strlen(errorMessage));
            }    
        }
        
   ErrorState::~ErrorState(){
       
       delete [] error_message;
   }
        
        void ErrorState::clear(){
             delete [] error_message;
             error_message = nullptr; 
            
        }
        
        bool ErrorState::isClear() const{
         if( error_message == nullptr){
             return true;
         }
         return false;
        }
        
        void ErrorState::message(const char* str){
            delete [] error_message;
            error_message = new char [strlen(str+1)];
            strncpy(error_message,str, strlen(str));
            
            }
            
            
        const char* ErrorState::message()const{
            
            return error_message;
        }
        
         std::ostream& operator << ( std::ostream& ostr,  ErrorState&err){
             if(!err.isClear())
                ostr << err.message();
             return ostr;
         }
    }
    
    
    
