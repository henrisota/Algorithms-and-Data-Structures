/*
	CH-231-A
	hw2_p6.cpp
	Henri Sota
	h.sota@jacobs-university.de
*/
#include <set>
class Access {
    public:
        // Method to activate a code if not already active
        void activate(unsigned int code);
        // Method to deactivate a code if already active
        void deactivate(unsigned int code);
        // Method to check if code is active
        bool isactive(unsigned int code) const;
    private:
        std::set<unsigned int> codes;
};