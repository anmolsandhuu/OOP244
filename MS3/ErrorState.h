#include<iostream>
#ifndef AMA_DATE_H 
#define AMA_DATE_H

#define NO_ERROR 0
#define CIN_FAILED 1
#define YEAR_ERROR 2
#define MON_ERROR 3 
#define DAY_ERROR 4


namespace AMA{
    
    class ErrorState
	{
    private:
    
    char * error_message=NO_ERROR ;
    public:
    ErrorState();
    explicit ErrorState(const char* errorMessage);
    ErrorState(const ErrorState& em) = delete;
    ErrorState& operator=(const ErrorState& em) = delete;
    virtual ~ErrorState();
    void clear();
    bool isClear() const;
    void message(const char* str);
    const char* message()const;
    
    
    };
    std::ostream& operator << ( std::ostream& ostr,  ErrorState&error);

    
    
    
    
    
    
}
#endif