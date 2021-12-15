#include <stdexcept>
#include <string>
#include <sstream>

class CalcExcept : public std::exception
{
protected:
    const char* m_message;
    std::string m_errLine;
    int m_errLineNum;
    CalcExcept(const char* _message,std::string _errline, int _errlinenum) :m_message(_message), 
                                                                            m_errLine(_errline), 
                                                                            m_errLineNum(_errlinenum) { }; 
    virtual ~CalcExcept() throw() { };

public:
    virtual const char * what () const throw () = 0;
};

class CalcRuntimeExc : virtual public CalcExcept
{
public:
    CalcRuntimeExc(const char* _mes, std::string _errline, int _errlinenum) : CalcExcept(_mes, _errline, _errlinenum) { };
    const char* what() const throw() override
    {
        std::ostringstream sstream;
        sstream << "Runtime Error was occured in line " << m_errLineNum << "\n"
                << "Error line : " << m_errLine << "\n"
                << m_message << "\n";
        return sstream.str().c_str();                        
    }
};

class CalcInputExc : virtual public CalcExcept
{
public:
    CalcInputExc(const char* _mes, std::string _errline, int _errlinenum) : CalcExcept(_mes, _errline, _errlinenum) { };
    const char* what() const throw() override
    {
        std::ostringstream sstream;
        sstream << "Input error was occured in line " << m_errLineNum << "\n"
                << "Error line : " << m_errLine << "\n"
                << m_message << "\n";
        return sstream.str().c_str();                        
    }
};
