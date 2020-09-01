/*
	CH-231-A
	hw2_p8.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <map>
class Access {
    public:
        // Method to activate a code if not already active
        void activate(unsigned int code, unsigned int level);
        // Method to deactivate a code if already active
        void deactivate(unsigned int code);
        // Method to check if code is active
        bool isactive(unsigned int code, unsigned int level) const;
    private:
        std::map<unsigned int, unsigned int> codes;
};