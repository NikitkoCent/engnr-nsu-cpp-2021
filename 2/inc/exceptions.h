#include <stdexcept>
#include <string>
#include <sstream>
#include <string.h>

class CalcExcept : public std::exception
{
protected:
    const char* m_message;
    std::string m_errLine;
    int m_errLineNum;

    std::string m_what;
    CalcExcept(const char* _message,std::string _errline, int _errlinenum) noexcept:m_message(_message), 
                                                                                    m_errLine(_errline), 
                                                                                    m_errLineNum(_errlinenum) { }; 
    virtual ~CalcExcept() = default;
};

class CalcRuntimeExc : public CalcExcept
{
public:
    CalcRuntimeExc(const char* _mes, std::string _errline, int _errlinenum) noexcept : CalcExcept(_mes, _errline, _errlinenum) 
    { 
        std::ostringstream sstream;
        sstream << "Runtime Error was occured in line " << m_errLineNum << "\n"
                << "Error line : " << m_errLine << "\n"
                << m_message << "\n";
        m_what = sstream.str();
    };

    const char* what() const throw() override
    {
        return m_what.c_str();       
    }
};

class CalcInputExc : public CalcExcept
{
public:
    CalcInputExc(const char* _mes, std::string _errline, int _errlinenum) noexcept : CalcExcept(_mes, _errline, _errlinenum) 
    { 
        std::ostringstream sstream;
        sstream << "Input error was occured in line " << m_errLineNum << "\n"
                << "Error line : " << m_errLine << "\n"
                << m_message << "\n";
        m_what = sstream.str();
    };

    const char* what() const throw() override
    {
        return m_what.c_str();                    
    }
};
