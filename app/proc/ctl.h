#include <string>
#include <iostream>
#include <sstream>



// Class
class Controller {
    private:
        // Variables
        std::string _pgO;
        std::string _type;
        std::string _momo;
        std::string _exec;
        std::string _stdd;
        std::string _pgOc;
        std::string _status;
        std::string _digit;
        std::string _info;
        int _part;
        const int _MAXCOUNT = 9;

    public:
        // Constructors
        Controller();
        Controller(const std::string& str01, const std::string& str02, const std::string& str03, const std::string& str04, 
            const std::string& str05, const std::string& str06, const std::string& str07);
        Controller(const std::string& str01, const std::string& str02, const std::string& str03, const std::string& str04, 
            const std::string& str05, const std::string& str06, const std::string& str07, const std::string& str08, const std::string str09);
        
    public:
        // Destructor
        ~Controller();

    public:
        // Split string method
        bool __splitString(std::string& _input);
        // Command - CLi
        void __CommandCLI();

    public:
        // Getters
        std::string __getPgO()      const { return _pgO;    }
        std::string __getType()     const { return _type;   }
        std::string __getMomo()     const { return _momo;   }
        std::string __getExec()     const { return _exec;   }
        std::string __getStdd()     const { return _stdd;   }
        std::string __getPgOc()     const { return _pgOc;   }
        std::string __getStatus()   const { return _status; }
        std::string __getDigit()    const { return _digit;  }
        std::string __getInfo()     const { return _info;   }
        
    public:
        // Setters
        void __setPgO(   const std::string& val) { _pgO    = val; }
        void __setType(  const std::string& val) { _type   = val; }
        void __setMomo(  const std::string& val) { _momo   = val; }
        void __setExec(  const std::string& val) { _exec   = val; }
        void __setStdd(  const std::string& val) { _stdd   = val; }
        void __setPgOc(  const std::string& val) { _pgOc   = val; }
        void __setStatus(const std::string& val) { _status = val; } 
        void __setDigit( const std::string& val) { _digit  = val; }
        void __setInfo(  const std::string& val) { _info   = val; }

    public:
        // Display method
        void __displayParts() const;
        std::string __command() const;
};